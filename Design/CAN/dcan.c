

/*** system headers ***/
#include <sciopta.h>  /* API */
#include <string.h>

/* used headers */
#include <tms570/vim.h>
#include <tms570/vim_chn_ls31.h>
#include "_can_.h"
#include "CANAPI_def.h"
#include "CANAPI.h"
#include "CANMB_def.h"
#include "DIOCFG_def.h"
#include "DIO.h"

/* own headers */
#include "dcan.h"
#include "dcan_reg.h"


/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define DCAN__nINT_CAN1_HIGH	(0x00)
#define DCAN__nINT_CAN1_LOW		(0x01)
#define DCAN__nINT_CAN1_IF3		(0x02)
#define DCAN__nINT_CAN2_HIGH	(0x10)
#define DCAN__nINT_CAN2_LOW		(0x11)
#define DCAN__nINT_CAN2_IF3		(0x12)
#define DCAN__nINT_CAN3_HIGH	(0x20)
#define DCAN__nINT_CAN3_LOW		(0x21)
#define DCAN__nINT_CAN3_IF3		(0x22)

/* internal__types */


/* private__variables */

static CANMB_tstMbData DCAN_s_astMbData[CANMB_nTOTAL_RX_MB] = {0};
static uint16 DCAN_s_au16MbStatus[CANMB_nTOTAL_RX_MB] = {0};

static DCAN_tpvfFunction DCAN__apvfCallBack[DCAN_enTotalDevices] = DCAN__CALLBACKS_TABLE_cfg;

__tstCANStandbySignal __astCANStandbySignals[DCAN_enTotalDevices] = DCAN_STANDBY_GPIO_cfg;

static uint32 u32CANTimestampISR = 0;
static uint32 u32Buffer = 0;
static uint32 u32CANCheck = 0;
static uint8 __u8DLC;

/* private__functions */
static void DCAN__vStandbyGPIO( DCAN_tenDevices enDevice, uint8 u8Level )
{
	uint16 u16Peripheral;
	uint8 u8GPIOLevel = STD_OFF;
	enDevice--;
	if( enDevice < DCAN_enTotalDevices )
	{
		if( __astCANStandbySignals[enDevice].stEN.u16Signal != NULL )
		{
			u16Peripheral = __astCANStandbySignals[enDevice].stEN.u16Signal;
			u8GPIOLevel = ~(__astCANStandbySignals[enDevice].stEN.u8Level ^ u8Level) & 0x01;
			DIO_u32SetState(u16Peripheral, u8GPIOLevel);
		}
		else
		{
			/* nothing to do */
		}

		if( __astCANStandbySignals[enDevice].stSTB.u16Signal != NULL )
		{
			u16Peripheral = __astCANStandbySignals[enDevice].stSTB.u16Signal;
			u8GPIOLevel = ~(__astCANStandbySignals[enDevice].stSTB.u8Level ^ u8Level) & 0x01;
			DIO_u32SetState(u16Peripheral, u8GPIOLevel);
		}
		else
		{
			/* nothing to do */
		}

		if( __astCANStandbySignals[enDevice].stWake.u16Signal != NULL )
		{
			u16Peripheral = __astCANStandbySignals[enDevice].stWake.u16Signal;
			DIO_u32SetState(u16Peripheral, STD_OFF);
		}
		else
		{
			/* nothing to do */
		}
	}
	else
	{
		/* nothing to do */
	}
}

static DCAN__tstBitRateRegisterDefinition DCAN__pstDeviceBaudrate(DCAN_tenDevices enDevice)
{
	DCAN__tstBitRateRegisterDefinition stBitRateRegisterDefinition[] = DCAN_DEVICE_BAUDRATE_cfg;
	if( enDevice < DCAN_enTotalDevices )
	{
		/* nothing to do */
	}
	else
	{
		enDevice = DCAN_enTotalDevices;
	}

	return( stBitRateRegisterDefinition[enDevice] );
}

static DCAN__tstMemMap* DCAN__pstSelectDevice(DCAN_tenDevices enDevice)
{
	DCAN__tstMemMap *pstAddr = NULL;
	
	switch (enDevice)
	{
		case DCAN_enCANA:
			pstAddr = (void*)DCAN__1_ADDR_PTR;
			break;
		case DCAN_enCANC:
			pstAddr = (void*)DCAN__2_ADDR_PTR;
			break;
		case DCAN_enCAND:
			pstAddr = (void*)DCAN__3_ADDR_PTR;
			break;
		default:
			break;
	}
	return pstAddr;
}

#if (_HWSW_INTEGRATION_ == 1) && (_middleware_ == 1)
uint32 DCAN_Test_u32MsgCnt = 0; /*Variable expotada para contabilizar los mensajes de CAN recibidos*/
#endif

static void DCAN__vTxRxMessageISR(DCAN_tenDevices enDevice)
{
	DCAN__tstMemMap *pstCANReg = NULL;
	uint32 u32Mailbox;
	uint8 u8Buffer[8];
	uint8 u8DLC;
	uint8 i = 0;
	uint8 u8RegIndex;
	uint32 u32BitIndex;
	
	pstCANReg = DCAN__pstSelectDevice(enDevice);

#if (_HWSW_INTEGRATION_ == 1) && (_middleware_ == 1)
	DCAN_Test_u32MsgCnt++; /*Contabilizar los mensajes de CAN recibidos*/
#endif

	u32Mailbox = pstCANReg->INT;	
	
	if (u32Mailbox == 0x8000U)
	{
		return;
	}
	
	if(u32Mailbox <= CANAPI_u16GetRxMbPerDev((uint16)enDevice))
	{

		if(u32Mailbox == 1)
		{
			u32CANTimestampISR = RTC_u32GetKernelClock();
		}

		pstCANReg->IF1CMD = DCAN__IFxCMD_CLRINTPND_MASK;
		pstCANReg->IF1NO  = u32Mailbox;

		while (pstCANReg->IF1STAT & DCAN__IFxSTAT_BUSY_MASK);
		
		pstCANReg->IF1CMD = (DCAN__IFxCMD_WRRD_MASK | DCAN__IFxCMD_TXRQNEWDATA_MASK | 
							DCAN__IFxCMD_DATAA_MASK | DCAN__IFxCMD_DATAB_MASK);
		
		u8RegIndex = (u32Mailbox - 1) >> 5;
		u32BitIndex = 1 << ((u32Mailbox - 1) & 0x1F);

		if ((pstCANReg->NWDATx[u8RegIndex] & u32BitIndex))
		{
			/** - Wait until IF2 is ready for use */
			while (pstCANReg->IF2STAT & DCAN__IFxSTAT_BUSY_MASK);

			/** - Copy data into IF2 */
			pstCANReg->IF2NO = u32Mailbox;

			/** - Wait until data are copied into IF2 */
			while (pstCANReg->IF2STAT & DCAN__IFxSTAT_BUSY_MASK);

			/** - Get number of received bytes */
			u8DLC = pstCANReg->IF2MCTL & DCAN__IFxMCTL_DLC_MASK;

			/** - Copy RX data into destination buffer */
			i = 0;
			while(i < u8DLC)
			{
		#ifdef __little_endian__
				u8Buffer[i] = pstCANReg->IF2DATx[i];
		#else
				u8Buffer[i] = pstCANReg->IF2DATx[3 - (i&0x3) + (i&0x4)];
		#endif
				i++;
			}
			
			
			if(DCAN__apvfCallBack != NULL)
			{
				DCAN__apvfCallBack[enDevice](enDevice, u32Mailbox, u8DLC, u8Buffer);
				u32Buffer = u8Buffer[2];
			}
			
		}
	}
	else
	{
		pstCANReg->IF1CMD |= 0 << 23; 
		pstCANReg->IF1CMD |= DCAN__IFxCMD_CLRINTPND_MASK;
		pstCANReg->IF1NO  = u32Mailbox;
		while (pstCANReg->IF1STAT & DCAN__IFxSTAT_BUSY_MASK);
	}
}

static uint8 DCAN__u8InitMailbox(volatile DCAN__tstMemMap *pstCANReg, uint8 u8MailboxNbr, uint8 u8Direction, uint32 u32ID, uint8 u8FrameType, uint8 u8DLC)
{
	/* Wait until IFx is ready for use */
	uint32 u32FrameTypeMask;
	uint8 u8TxIE = 0;
	uint8 u8RxIE = 0;
	uint8 u8Status = DCAN_E_OK;

	if(u8FrameType == DCAN_NORMAL_FRAME)
	{
		u32FrameTypeMask = DCAN__NORMAL_FRAME_MASK;
		if( u8Direction == DCAN__DIRECTION_RX )
		{
			u32ID = u32ID << DCAN__NORMAL_FRAME_ID_SHIFT; /* IFxARB [28:18] */
		}
		else
		{
			u32ID = u32ID << DCAN__NORMAL_FRAME_ID_SHIFT; /* IFxARB [28:18] */
		}
	}
	else
	{
		u32FrameTypeMask = DCAN__EXTENDED_FRAME_MASK;
		u32ID = u32ID << DCAN__EXTENDED_FRAME_ID_SHIFT;  /* IFxARB [28:18] */
	}

	if(u8Direction == DCAN__DIRECTION_RX)
	{
		u8RxIE = 1;
	}
	else
	{
		//u8TxIE = 1;
	}
	
	if((u8MailboxNbr % 2) == 0)
	{
		while ( (pstCANReg->IF2STAT & DCAN__IFxSTAT_BUSY_MASK) );
		pstCANReg->IF2MSK  = DCAN__IFxMSK_MXTD_MASK | DCAN__IFxMSK_MDIR_MASK | DCAN__IFxMSK_MSK(u32FrameTypeMask);
	    pstCANReg->IF2ARB  = DCAN__IFxARB_MSGVAL_MASK | DCAN__IFxARB_XDT(u8FrameType) | DCAN__IFxARB_DIR(u8Direction) | DCAN__IFxARB_ID(u32ID);
	    pstCANReg->IF2MCTL = DCAN__IFxMCTL_UMASK_MASK | DCAN__IFxMCTL_RXIE(u8RxIE) | DCAN__IFxMCTL_TXIE(u8TxIE)|
							 DCAN__IFxMCTL_EOB_MASK |DCAN__IFxMCTL_DLC(u8DLC);
	    pstCANReg->IF2CMD  = DCAN__IFxCMD_WRRD_MASK | DCAN__IFxCMD_MASK_MASK | DCAN__IFxCMD_ARB_MASK |
				 	 	 	 DCAN__IFxCMD_CONTROL_MASK| DCAN__IFxCMD_CLRINTPND_MASK;
	    pstCANReg->IF2NO   = u8MailboxNbr;
	}
	else
	{
		while ( (pstCANReg->IF1STAT & DCAN__IFxSTAT_BUSY_MASK) );
		pstCANReg->IF1MSK  = DCAN__IFxMSK_MXTD_MASK | DCAN__IFxMSK_MDIR_MASK | DCAN__IFxMSK_MSK(u32FrameTypeMask);
	    pstCANReg->IF1ARB  = DCAN__IFxARB_MSGVAL_MASK | DCAN__IFxARB_XDT(u8FrameType) | DCAN__IFxARB_DIR(u8Direction) | DCAN__IFxARB_ID(u32ID);
	    pstCANReg->IF1MCTL = DCAN__IFxMCTL_UMASK_MASK | DCAN__IFxMCTL_RXIE(u8RxIE) | DCAN__IFxMCTL_TXIE(u8TxIE)|
							 DCAN__IFxMCTL_EOB_MASK |DCAN__IFxMCTL_DLC(u8DLC);
	    pstCANReg->IF1CMD  = DCAN__IFxCMD_WRRD_MASK | DCAN__IFxCMD_MASK_MASK | DCAN__IFxCMD_ARB_MASK |
	    					 DCAN__IFxCMD_CONTROL_MASK| DCAN__IFxCMD_CLRINTPND_MASK;
	    pstCANReg->IF1NO   = u8MailboxNbr;
	}
	
	return u8Status;
}

static void DCAN__vSetupBitTimming(volatile DCAN__tstMemMap *pstCANReg, DCAN__tstBitRateRegisterDefinition stBitRate)
{
	pstCANReg->BTR =
			DCAN__BTR_BRPE(stBitRate.u8BRPE) |
			DCAN__BTR_TSEG2(stBitRate.u8Phase_Seg2 - 1)	|
			DCAN__BTR_TSEG1(stBitRate.u8Phase_Seg1 + stBitRate.u8Prop_Seg - 1)	|
			DCAN__BTR_SJW(stBitRate.u8SJW - 1)	|
			DCAN__BTR_BRP( stBitRate.u8BRP);
}

static void DCAN__vActivateInterrupt(DCAN_tenDevices enDevice, DCAN_tenInterruptTypes enInterruptType)
{
	    /*
    ** enable compare0 interrupt,
    ** assumes 1:1 channel mapping !
    */
	uint8 u8InterruptSelect;
	VIM__tstMap *pstVIMMap = VIM_;
	
	u8InterruptSelect = ((enDevice) << 4) + enInterruptType;
	
	switch (u8InterruptSelect)
	{
		case DCAN__nINT_CAN1_HIGH:
			u8InterruptSelect = VIM_DCAN1_Level_0;
			break;
		case DCAN__nINT_CAN1_LOW:
			u8InterruptSelect = VIM_DCAN1_Level_1;
			break;
		case DCAN__nINT_CAN1_IF3:
			u8InterruptSelect = VIM_DCAN1_IF3;
			break;
		case DCAN__nINT_CAN2_HIGH:
			u8InterruptSelect = VIM_DCAN2_Level_0;
			break;
		case DCAN__nINT_CAN2_LOW:
			u8InterruptSelect = VIM_DCAN2_Level_1;
			break;
		case DCAN__nINT_CAN2_IF3:
			u8InterruptSelect = VIM_DCAN2_IF3;
			break;			
		case DCAN__nINT_CAN3_HIGH:
			u8InterruptSelect = VIM_DCAN3_Level_0;
			break;
		case DCAN__nINT_CAN3_LOW:
			u8InterruptSelect = VIM_DCAN3_Level_1;
			break;
		case DCAN__nINT_CAN3_IF3:
			u8InterruptSelect = VIM_DCAN3_IF3;
			break;			
		default:
			break;
	}
	
	if(u8InterruptSelect < 32)
	{
#ifdef _INTEGRATION_
		pstVIMMap->REQMASKSET0 |= (1 << u8InterruptSelect);
#else
		pstVIMMap->REQMASKSET0 = (1 << u8InterruptSelect);
#endif
	}
	else
	{
#ifdef _INTEGRATION_
		pstVIMMap->REQMASKSET1 |= (1 << (u8InterruptSelect - 32));
#else
		pstVIMMap->REQMASKSET1 = (1 << (u8InterruptSelect - 32));
#endif
	}
}

static void DCAN__vMailboxesConfig(DCAN_tenDevices enDevice, volatile DCAN__tstMemMap *pstCANReg)
{
	uint16 u16i = 0;
	for (u16i = 0 ; u16i < CANMB_nTOTAL_MAILBOX ; u16i++)
	{
		if (CANAPI_u16GetCANDevice(u16i) == (uint16)enDevice)
		{
			DCAN__u8InitMailbox(pstCANReg,
								(uint8)CANAPI_u16GetMbDriver(u16i),
								CANAPI_u8GetMbDirection(u16i),
								CANAPI_u32GetMsgId(u16i),
								CANAPI_u8GetFrameType(u16i),
								CANAPI_u8GetMbSize(u16i));
		}
		else
		{
			/* Nothing to do */
		}
	}
}

static uint8 DCAN__u8StandBy(DCAN_tenDevices enDevice)
{
	uint8 u8ErrCode = E_NOT_OK;
	if( enDevice < DCAN_enTotalDevices )
	{
		DCAN__vStandbyGPIO( enDevice, STD_IDLE);
		u8ErrCode = E_OK;
	}
	else
	{
		u8ErrCode = E_NOT_OK;
	}
	return u8ErrCode;
}

/* public__functions */

void DCAN_vReceivedMessagesISR(uint8 u8Device, uint8 u8Mailbox, uint8 u8DLC, uint8 *pu8Data)
{
	uint8 i = 0;
//	u8Mailbox -= 1;

	while(  CANAPI_u16GetCANDevice(i) != u8Device ||
			CANAPI_u16GetMbDriver(i) != u8Mailbox )
	{
		i++;
	}
	u8Mailbox = i;
	if(CANAPI_u8GetMbDirection(u8Mailbox) == DCAN__DIRECTION_RX)
	{
		__u8DLC = u8DLC;
		if(u8DLC == CANAPI_u8GetMbSize(u8Mailbox))
		{
			/*SYS_enter_critical();*/ /** @todo ##SevEd 13/03/2012: Hacer el mecanismo de seguridad de memoria critica*/
			memcpy(DCAN_s_astMbData[u8Mailbox].unMsgData.au8Byte, pu8Data, u8DLC);
			DCAN_s_au16MbStatus[u8Mailbox] = CANAPI_enNewMsg;
			u32CANCheck ++;
			/*SYS_exit_critical();*/
		}
		else
		{
			/*dbg_printf("\nCAN Controller, Error: DLC mismatched \n",0);*/
			/** @todo SevEd## 13/10/11 -- Make an Error???? */
			DCAN_s_au16MbStatus[u8Mailbox] = CANAPI_enMsgError;
			u32CANCheck = 0xFFFFFFFF;
		}
	}
}

void DCAN_vGetAllRxMbData(void* pvData)
{
	memcpy(pvData, (void*)DCAN_s_astMbData, (CANMB_nTOTAL_RX_MB * sizeof(CANMB_tstMbData)));
}

void DCAN_vGetMbStatus(void* pvData)
{
	uint16 u16i = 0;
	memcpy(pvData, (void*)DCAN_s_au16MbStatus, (CANMB_nTOTAL_RX_MB * sizeof(uint16)));
	for (u16i = 0 ; u16i < CANMB_nTOTAL_RX_MB ; u16i++)
	{
		DCAN_s_au16MbStatus[u16i] = CANAPI_enMsgNotArrived;
	}
}

void DCAN_vInit(DCAN_tenDevices enDevice)
{
	volatile DCAN__tstMemMap *pstCANReg = NULL;
	pstCANReg = DCAN__pstSelectDevice(enDevice);

	if(pstCANReg != NULL)
	{
		DCAN__u8StandBy( enDevice );

		pstCANReg->CTL = DCAN__CTL_IE1_MASK | DCAN__CTL_PMD(0x05) | DCAN__CTL_CCE_MASK |
						DCAN__CTL_IE0_MASK | 0/*DCAN__CTL_ABO_MASK*/;
		pstCANReg->CTL |= DCAN__CTL_INIT_MASK;



		/** - Clear all pending error flags and reset current status */
		pstCANReg->ES = DCAN__ES_PER_MASK | DCAN__ES_WAKEUP_PND_MASK |
						DCAN__ES_RXOK_MASK | DCAN__ES_TXOK_MASK | DCAN__ES_LEC(7);


		pstCANReg->TEST = 0;
		/** - Assign interrupt level for messages */
		pstCANReg->INTMUXx[0] = 0x0;
		pstCANReg->INTMUXx[1] = 0x0;
			
		/** - Setup auto bus on timer pewriod */
		pstCANReg->ABOTR = 0;


		DCAN__vMailboxesConfig((DCAN_tenDevices)enDevice, pstCANReg);

		DCAN__vActivateInterrupt((DCAN_tenDevices)enDevice, DCAN_enInterruptHigh);

	    /** - Setup IF1 for data transmission
	    *     - Wait until IF1 is ready for use
	    *     - Set IF1 control byte
	    */
	    while ( (pstCANReg->IF1STAT & DCAN__IFxSTAT_BUSY_MASK) );

	    pstCANReg->IF1CMD  = DCAN__IFxCMD_WRRD_MASK | DCAN__IFxCMD_TXRQNEWDATA_MASK |
	    					 DCAN__IFxCMD_DATAA_MASK | DCAN__IFxCMD_DATAB_MASK;

	    /** - Setup IF2 for reading data
	    *     - Wait until IF1 is ready for use
	    *     - Set IF1 control byte
	    */
	    while ( (pstCANReg->IF2STAT & DCAN__IFxSTAT_BUSY_MASK) );

	    pstCANReg->IF2CMD = DCAN__IFxCMD_CONTROL_MASK | DCAN__IFxCMD_TXRQNEWDATA_MASK |
				 	 	   DCAN__IFxCMD_DATAA_MASK | DCAN__IFxCMD_DATAB_MASK;


	    DCAN__vSetupBitTimming(pstCANReg, DCAN__pstDeviceBaudrate(enDevice));


	     /** - DCAN1 Port output values */
	    pstCANReg->TIOC = DCAN__TIOC_FUNC_MASK | DCAN__TIOC_DIR_MASK | DCAN__TIOC_PD_MASK;
	    pstCANReg->RIOC = DCAN__RIOC_FUNC_MASK | DCAN__RIOC_PD_MASK;



	    /** - Leave configuration and initialization mode  */
	    pstCANReg->CTL &= ~(DCAN__CTL_CCE_MASK | DCAN__CTL_INIT_MASK);

	}
	else
	{
		/* nothing to do */
	}
}

/** @fn uint32_t dcanTransmit(dcanBASE_t *node, uint32_t messageBox, const uint8_t *data)
*   @brief Transmits a DCAN message
*   @param[in] node Pointer to DCAN node:
*              - pstCANReg: DCAN1 node pointer
*              - dcanREG2: DCAN2 node pointer
*              - dcanREG3: DCAN3 node pointer
*   @param[in] messageBox Message box number of DCAN node:
*              - dcanMESSAGE_BOX1: DCAN message box 1
*              - dcanMESSAGE_BOXn: DCAN message box n [n: 1-64]
*              - dcanMESSAGE_BOX64: DCAN message box 64
*   @param[in] data Pointer to DCAN TX data
*   @return The function will return:
*           - 0: When the setup of the TX message box wasn't successful   
*           - 1: When the setup of the TX message box was successful   
*
*   This function writes a DCAN message into a DCAN message box.
*
*/

/* USER CODE BEGIN (6) */
/* USER CODE END */

uint8 DCAN_u8TransmitMailbox(uint8 u8Device, uint8 u8MailboxNbr, uint8 u8DLC, uint8 *pu8Data)
{
	volatile DCAN__tstMemMap *pstCANReg = NULL;
	uint8 u8RegIndex;
	uint8 u8Status = DCAN_E_OK;
	uint32 u32BitIndex;
	uint8 i;

	uint32 u32Bandera = 0;

	pstCANReg = DCAN__pstSelectDevice((DCAN_tenDevices)u8Device);

	if(pstCANReg != NULL)
	{
		u8RegIndex = (u8MailboxNbr - 1) >> 5;
		u32BitIndex = 1 << ((u8MailboxNbr - 1) & 0x1F);

		u32Bandera = pstCANReg->TXRQx[u8RegIndex];
		u32Bandera &= u32BitIndex;
		if ((u32Bandera) == 0)
		{
			    /** - Wait until IF1 is ready for use */
    		while (pstCANReg->IF1STAT & DCAN__IFxSTAT_BUSY_MASK);

			/** - Copy TX data into IF1 */
    		i = 0;
			while(i < u8DLC)
			{
		#ifdef __little_endian__
				pstCANReg->IF1DATx[i] = pu8Data[i];
		#else
				pstCANReg->IF1DATx[3 - (i&0x3) + (i&0x4)] = pu8Data[i];
		#endif
				i++;
			}
			
			/** - Copy TX data into mesasge box */
			pstCANReg->IF1NO = u8MailboxNbr;
		}
		else
		{
			u8Status = DCAN_E_NOT_OK;
		}
	}
	else
	{
		u8Status = DCAN_E_ERROR_ADDR;
	}
	return u8Status;
}

uint8 DCAN_u8WakeUp(DCAN_tenDevices enDevice)
{
	uint8 u8ErrCode = E_NOT_OK;
	if( enDevice < DCAN_enTotalDevices )
	{
		DCAN__vStandbyGPIO( enDevice, STD_ACTIVE);
		u8ErrCode = E_OK;
	}
	else
	{
		u8ErrCode = E_NOT_OK;
	}
	return u8ErrCode;
}

uint32 DCAN_u32GetTimestampISR(void)
{
	return u32CANTimestampISR;
}

uint32 DCAN_u32GetBufferISR(void)
{
	return u32Buffer;
}

uint32 DCAN_u32GetCanCheck(void)
{
	return u32CANCheck;
}

uint8 DCAN_u8GetDLC(void)
{
	return __u8DLC;
}


SC_INT_PROCESS(DCAN_sysISR1, src)
{
	if (src == 0)/* Generated by hardware */
	{
	/* Code for hardware interrupt handling */
		DCAN__vTxRxMessageISR(DCAN_enCANA);
	}
	else
	{
		/* nothing to do */
	}
}

SC_INT_PROCESS(DCAN_sysISR2, src)
{
	if (src == 0)/* Generated by hardware */
	{
	/* Code for hardware interrupt handling */
		DCAN__vTxRxMessageISR(DCAN_enCANC);
	}	
	else
	{
		/* nothing to do */
	}
}

SC_INT_PROCESS(DCAN_sysISR3, src)
{
	if (src == 0)/* Generated by hardware */
	{
	/* Code for hardware interrupt handling */
		DCAN__vTxRxMessageISR(DCAN_enCAND);
	}
	else
	{
		/* nothing to do */
	}
}
