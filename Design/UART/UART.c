


/* system headers */
#include <sciopta.h>  /* API */
#include "config.h"

/* used headers */


/* own headers */
#include "UART.h"
#include "UART_config.h"
#include "UART_reg.h"

/*[EXPORTED]****************************************************************************/



/* public_variables */



/*[INTERNAL]****************************************************************************/



/* internal__pre-processor macros */
#define UART_DIVIDE_BY_16(divisor)    (divisor >> 4)

/* internal__types */
typedef struct
{
	uint16 u16Length;
	uint8 *pu8Data;
}UART__tstTransferData;


/* private__variables */
static UART__tstTransferData UART__astTransferData[UART_enTotalDevices];
static UART_tpvfRxCallBack UART__avfRxCallBack[UART_enTotalDevices] = { NULL };
static UART_tpvfTxCallBack UART__avfTxCallBack[UART_enTotalDevices] = { NULL };

/* private__functions */
void *UART__pvSelectDevice(UART_tenDevices enDevice)
{
    void *pvAddr = NULL;
        
    /* Select pointer to registers */
    if( enDevice == UART_enDevice0 )
    {
        pvAddr = UART__DEVICE0_ADDR_PTR;
    }
    else if ( enDevice == UART_enDevice1 )
    {
        pvAddr = UART__DEVICE1_ADDR_PTR;
    }
    else
    {
        sc_miscError(SC_ERR_SYSTEM_FATAL,enDevice);
    }
    
    return pvAddr;   
}



/* public_functions */
void UART_vInit(UART_tenDevices enDevice, UART_tenBaudRates enBaudRate)
{
    UART__tstMemMap *pstUART;
    
    /* Select pointer to registers */
    pstUART = (UART__tstMemMap*)UART__pvSelectDevice(enDevice);

    if(pstUART != NULL)
    {
        /* - bring SCI out of reset */
        do
        {
            pstUART->GCR0 = SCI__GCR0_RESET_MASK;
        }while ( pstUART->GCR0 != SCI__GCR0_RESET_MASK );
        
        
        /* - Disable all interrupts */
        pstUART->CLRINT    = 0xFFFFFFFF;
        pstUART->CLRINTLVL = 0xFFFFFFFF;
        
        /* - global control 1 */
        pstUART->GCR1 = (SCI__GCR1_TXENA_MASK |
                         SCI__GCR1_RXENA_MASK |
                         SCI__GCR1_CLOCK_MASK |
                         SCI__GCR1_CONT_MASK |
                         SCI__GCR1_TIMMING_MODE_MASK);
        
        /* Baudrate */
        /* See page DataSheet 26.2.3 SCI Baud Rate, p. 1673
        VBUSPCLK Frequency / 16 BAUD + 1 */
        
		/** @todo: Edgar Sevilla -- FIX Clock*/
        pstUART->BRS = 42;//27;//UART_DIVIDE_BY_16((CNF_VCLK)/(enBaudRate + 1));  /* baudrate */
    
        /* Character length*/
        pstUART->CHAR = SCI__FORMAT_CHAR(7);    
        
        /* - set SCI pins functional mode */
        pstUART->FUN = (SCI__PIO0_TX_FUNC_MASK |
                        SCI__PIO0_RX_FUNC_MASK);
        
        /* - set SCI pins open drain enable */
        pstUART->ODR = SCI__PIO6_TX_PDR_MASK;  /* tx pin */
        
        /** - set SCI pins pullup/pulldown enable */
        pstUART->PD = 0;
        
        /** - set SCI pins pullup/pulldown select */
        pstUART->PSL = (SCI__PIO8_TX_PSL_MASK | /* tx pin */
                        SCI__PIO8_TX_PSL_MASK);  /* rx pin */
        
        /** - set interrupt level */
        pstUART->SETINTLVL = (UART__ISR_MAPPED_TO_LVL1_cfg);
        
        /** - clear interrupt flags */
        pstUART->FLR = SCI__FLR_CLEAR_ALL_MASK;
        
        /** - set interrupt enable */
        pstUART->SETINT = SCI__SETINT_SET_RX_MASK;
        
        /** - Finaly start SCI2 */
        pstUART->GCR1 |= SCI__GCR1_SWnRST_MASK;
    }
    else
    {
        /* Nothing to do -- Error was marked */
    }
}

void UART_vInstallRxCallBack(UART_tenDevices enDevice, UART_tpvfRxCallBack pvfCallback)
{
    UART__avfRxCallBack[enDevice] = pvfCallback;
}

void UART_vInstallTxCallBack(UART_tenDevices enDevice, UART_tpvfTxCallBack pvfCallback)
{
    UART__avfTxCallBack[enDevice] = pvfCallback;
}

void UART_vSendBuffer(UART_tenDevices enDevice, uint8 *pu8Data, uint16 u16Length)
{
    UART__tstMemMap *pstUART;

    /* Select pointer to registers */
    pstUART = (UART__tstMemMap*)UART__pvSelectDevice(enDevice);

    if(pstUART != NULL)
    {
        UART__astTransferData[enDevice].u16Length = u16Length;
        UART__astTransferData[enDevice].pu8Data   = pu8Data;
        
        /* start transmit by sending first byte */
        pstUART->TD     = *UART__astTransferData[enDevice].pu8Data++;
        pstUART->SETINT = SCI__SETINT_SET_TX_MASK;
    }
}

void UART_vSendBuffer_p(UART_tenDevices enDevice, uint8 *pu8Data, uint16 u16Length)
{
    UART__tstMemMap *pstUART;
    uint8 j;
    /* Select pointer to registers */
    pstUART = (UART__tstMemMap*)UART__pvSelectDevice(enDevice);

    if(pstUART != NULL)
    {
        j = 0;
        while(j<u16Length)
        {

            while ((pstUART->FLR & 0x00000100) == 0);
            pstUART->TD = *pu8Data;
            pu8Data++;
            j++;
        }
    } 
}

SC_INT_PROCESS(UART0_sysISR, src)
{
	
    UART__tstMemMap *pstUART;

    pstUART = UART__DEVICE0_ADDR_PTR;
	
    if(src == -1)   /* ISR Init */
    {
        VIM->REQMASKSET0 = (1 << UART__ISR0_VIM_cfg);
    }
    
    if (src == 0)   /* Generated by hardware */
    {
        uint32 u32VectorSrc = pstUART->INTVECT1;

        switch (u32VectorSrc)
        {
        case SCI__INTERRUPT_WAKEUP_FLAG:
                    
            break;
        case SCI__INTERRUPT_PARITY_ERROR_FLAG:
                    
            break;
        case SCI__INTERRUPT_FRAME_ERROR_FLAG:
                    
            break;
        case SCI__INTERRUPT_BRKDT_ERROR_FLAG:
            
            break;
        case SCI__INTERRUPT_OVERRUN_ERROR_FLAG:
                    
            break;
    
        case SCI__INTERRUPT_RECEIVE_FLAG:
            if(UART__avfRxCallBack[UART_enDevice0] != NULL)
            {
                UART__avfRxCallBack[UART_enDevice0]((uint8)pstUART->RD);
            }
            else
            {
                /* Nothing to do */
            }
            break;
    
        case SCI__INTERRUPT_TRANSMIT_FLAG:
            if (--UART__astTransferData[UART_enDevice0].u16Length > 0)
            {
                pstUART->TD = *UART__astTransferData[UART_enDevice0].pu8Data++;
            }
            else
            {
                pstUART->CLRINT = SCI__CLEARINT_CLR_TX_MASK;
                UART__avfTxCallBack[UART_enDevice0]();
            }
            break;
    
        default:
            /* phantom interrupt, clear flags and return */
            pstUART->FLR = pstUART->SETINTLVL & 0x07000303;
             break;
        }
    }	
}

/* EOF */
