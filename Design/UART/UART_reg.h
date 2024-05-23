

#ifndef UART_REG_H_
#define UART_REG_H_

/* system headers */

/* used headers */

/* own headers */

/*****************************************************************************/

/* exported configuration macros */

#define UART__DEVICE0_ADDR_PTR	((UART__tstMemMap *)0xFFF7E400U)
#define UART__DEVICE1_ADDR_PTR	((UART__tstMemMap *)0xFFF7E500U)    /* LIN-SCI */


/************************************************************************************
 * REGISTER MASKS
 ************************************************************************************/
/** SCI Global Control Register 0 (SCIGCR0) */
#define SCI__GCR0_RESET_MASK			(0x00000001UL)
#define SCI__GCR0_RESET_SHIFT	        (0)


/** SCI Global Control Register 1 (SCIGCR1) */
#define SCI__GCR1_TXENA_MASK		(0x02000000UL)
#define SCI__GCR1_TXENA_SHIFT	        (25)
#define SCI__GCR1_RXENA_MASK			(0x01000000UL)
#define SCI__GCR1_RXENA_SHIFT	        (24)
#define SCI__GCR1_CONT_MASK			(0x00020000UL)
#define SCI__GCR1_CONT_SHIFT	        (17)
#define SCI__GCR1_LOOP_BACK_MASK		(0x00010000UL)
#define SCI__GCR1_LOOP_BACK_SHIFT       (16)
#define SCI__GCR1_MBUF_MODE_MASK		(0x00000400UL)
#define SCI__GCR1_MBUF_MODE_SHIFT		(10)
#define SCI__GCR1_POWERDOWN_MASK		(0x00000200UL)
#define SCI__GCR1_POWERDOWN_SHIFT       (9)
#define SCI__GCR1_SLEEP_MASK            (0x00000100UL)
#define SCI__GCR1_SLEEP_SHIFT           (8)
#define SCI__GCR1_SWnRST_MASK           (0x00000080UL)
#define SCI__GCR1_SWnRST_SHIFT          (7)
#define SCI__GCR1_CLOCK_MASK            (0x00000020UL)
#define SCI__GCR1_CLOCK_SHIFT           (5)
#define SCI__GCR1_STOP_MASK	       		(0x00000010UL)
#define SCI__GCR1_STOP_SHIFT            (4)
#define SCI__GCR1_PARITY_MASK           (0x00000008UL)
#define SCI__GCR1_PARITY_SHIFT          (3)
#define SCI__GCR1_PARITY_ENA_MASK		(0x00000004UL)
#define SCI__GCR1_PARITY_ENA_SHIFT      (2)
#define SCI__GCR1_TIMMING_MODE_MASK		(0x00000002UL)
#define SCI__GCR1_TIMMING_MODE_SHIFT    (1)
#define SCI__GCR1_COMM_MODE_MASK		(0x00000001UL)
#define SCI__GCR1_COMM_MODE_SHIFT       (0)


/** SCI Format Control Register (SCIFORMAT) */

#define SCI__FORMAT_CHAR_MASK			(0x00000007UL)
#define SCI__FORMAT_CHAR_SHIFT			(0)
#define SCI__FORMAT_CHAR(x)				(((uint32)(((uint32)(x)) << SCI__FORMAT_CHAR_SHIFT)) & SCI__FORMAT_CHAR_MASK)


/** SCI Pin I/O Control Register 0 (SCIPIO0) */
#define SCI__PIO0_TX_FUNC_MASK	        (0x00000004UL)
#define SCI__PIO0_TX_FUNC_SHIFT         (2)
#define SCI__PIO0_RX_FUNC_MASK          (0x00000002UL)
#define SCI__PIO0_RX_FUNC_SHIFT         (1)

/** SCI Pin I/O Control Register 1 (SCIPIO1) */
#define SCI__PIO1_TX_DIR_MASK           (0x00000004UL)
#define SCI__PIO1_TX_DIR_SHIFT          (2)
#define SCI__PIO1_RX_DIR_MASK           (0x00000002UL)
#define SCI__PIO1_RX_DIR_SHIFT			(1)

/** SCI Pin I/O Control Register 2 (SCIPIO2) */
#define SCI__PIO2_TX_IN_MASK			(0x00000004UL)
#define SCI__PIO2_TX_IN_SHIFT			(2)
#define SCI__PIO2_RX_IN_MASK			(0x00000002UL)
#define SCI__PIO2_RX_IN_SHIFT			(1)

/** SCI Pin I/O Control Register 3 (SCIPIO3) */
#define SCI__PIO3_TX_OUT_MASK           (0x00000004UL)
#define SCI__PIO3_TX_OUT_SHIFT          (2)
#define SCI__PIO3_RX_OUT_MASK           (0x00000002UL)
#define SCI__PIO3_RX_OUT_SHIFT          (1)



/** SCI Pin I/O Control Register 6 (SCIPIO6) */
#define SCI__PIO6_TX_PDR_MASK           (0x00000004UL)
#define SCI__PIO6_TX_PDR_SHIFT          (2)
#define SCI__PIO6_RX_PDR_MASK           (0x00000002UL)
#define SCI__PIO6_RX_PDR_SHIFT          (1)

/** SCI Pin I/O Control Register 8 (SCIPIO8) */
#define SCI__PIO8_TX_PSL_MASK           (0x00000004UL)
#define SCI__PIO8_TX_PSL_SHIFT          (2)
#define SCI__PIO8_RX_PSL_MASK           (0x00000002UL)
#define SCI__PIO8_RX_PSL_SHIFT          (1)


/** SCI Set Interrupt Level Register (SCISETINTLVL) */
#define SCI__SETINTLVL_SET_FE_MASK			(0x04000000UL)
#define SCI__SETINTLVL_SET_FE_SHIFT			(26)
#define SCI__SETINTLVL_SET_CE_MASK			(0x02000000UL)
#define SCI__SETINTLVL_SET_CE_SHIFT			(25)
#define SCI__SETINTLVL_SET_PE_MASK			(0x01000000UL)
#define SCI__SETINTLVL_SET_PE_SHIFT			(24)
#define SCI__SETINTLVL_SET_RX_DMA_MASK		(0x00040000UL)
#define SCI__SETINTLVL_SET_RX_DMA_SHIFT		(18)
#define SCI__SETINTLVL_SET_RX_MASK			(0x00000200UL)
#define SCI__SETINTLVL_SET_RX_SHIFT			(9)
#define SCI__SETINTLVL_SET_TX_MASK			(0x00000100UL)
#define SCI__SETINTLVL_SET_TX_SHIFT			(8)
#define SCI__SETINTLVL_SET_WAKEUP_MASK		(0x00000002UL)
#define SCI__SETINTLVL_SET_WAKEUP_SHIFT		(1)
#define SCI__SETINTLVL_SET_BRKDT_MASK		(0x00000001UL)
#define SCI__SETINTLVL_SET_BRKDT_SHIFT		(0)


/** SCI Flags Register (SCIFLR) */
#define SCI__FLR_FE_MASK				(0x04000000UL)
#define SCI__FLR_FE_SHIFT				(26)
#define SCI__FLR_OE_MASK				(0x02000000UL)
#define SCI__FLR_OE_SHIFT				(25)
#define SCI__FLR_PE_MASK				(0x01000000UL)
#define SCI__FLR_PE_SHIFT				(24)
#define SCI__FLR_RXWAKE_MASK			(0x00001000UL)
#define SCI__FLR_RXWAKE_SHIFT			(12)
#define SCI__FLR_TX_EMPTY_MASK			(0x00000800UL)
#define SCI__FLR_TX_EMPTY_SHIFT			(11)
#define SCI__FLR_TXWAKE_MASK			(0x00000400UL)
#define SCI__FLR_TXWAKE_SHIFT			(10)
#define SCI__FLR_RXRDY_MASK				(0x00000200UL)
#define SCI__FLR_RXRDY_SHIFT			(9)
#define SCI__FLR_TXRDY_MASK				(0x00000100UL)
#define SCI__FLR_TXRDY_SHIFT			(8)
#define SCI__FLR_BUSY_MASK				(0x00000008UL)
#define SCI__FLR_BUSY_SHIFT				(3)
#define SCI__FLR_IDLE_MASK				(0x00000004UL)
#define SCI__FLR_IDLE_SHIFT				(2)
#define SCI__FLR_WAKEUP_MASK			(0x00000002UL)
#define SCI__FLR_WAKEUP_SHIFT			(1)
#define SCI__FLR_BRKDT_MASK				(0x00000001UL)
#define SCI__FLR_BRKDT_SHIFT			(0)
#define SCI__FLR_CLEAR_ALL_MASK			(0xFFFFFFFFUL)


/** SCI Set Interrupt Register (SCISETINT) */
#define SCI__SETINT_SET_FE_MASK		    	(0x04000000UL)
#define SCI__SETINT_SET_FE_SHIFT			(26)
#define SCI__SETINT_SET_CE_MASK				(0x02000000UL)
#define SCI__SETINT_SET_CE_SHIFT			(25)
#define SCI__SETINT_SET_PE_MASK				(0x01000000UL)
#define SCI__SETINT_SET_PE_SHIFT	    	(24)
#define SCI__SETINT_SET_RX_DMA_ALL_MASK	    (0x00040000UL)
#define SCI__SETINT_SET_RX_DMA_ALL_SHIFT    (18)
#define SCI__SETINT_SET_RX_DMA_MASK	    	(0x00020000UL)
#define SCI__SETINT_SET_RX_DMA_SHIFT	    (17)
#define SCI__SETINT_SET_TX_DMA_MASK			(0x00010000UL)
#define SCI__SETINT_SET_TX_DMA_SHIFT	    (16)
#define SCI__SETINT_SET_RX_MASK				(0x00000200UL)
#define SCI__SETINT_SET_RX_SHIFT	    	(9)
#define SCI__SETINT_SET_TX_MASK		    	(0x00000100UL)
#define SCI__SETINT_SET_TX_SHIFT	    	(8)
#define SCI__SETINT_SET_WAKEUP_MASK	    	(0x00000002UL)
#define SCI__SETINT_SET_WAKEUP_SHIFT	    (1)
#define SCI__SETINT_SET_BRKDT_MASK	    	(0x00000001UL)
#define SCI__SETINT_SET_BRKDT_SHIFT	    	(0)

/** SCI Clear Interrupt Register (SCICLEARINT) */
#define SCI__CLEARINT_CLR_FE_MASK		    (0x04000000UL)
#define SCI__CLEARINT_CLR_FE_SHIFT			(26)
#define SCI__CLEARINT_CLR_CE_MASK			(0x02000000UL)
#define SCI__CLEARINT_CLR_CE_SHIFT			(25)
#define SCI__CLEARINT_CLR_PE_MASK			(0x01000000UL)
#define SCI__CLEARINT_CLR_PE_SHIFT	    	(24)
#define SCI__CLEARINT_CLR_RX_DMA_ALL_MASK	(0x00040000UL)
#define SCI__CLEARINT_CLR_RX_DMA_ALL_SHIFT	(18)
#define SCI__CLEARINT_CLR_RX_DMA_MASK		(0x00020000UL)
#define SCI__CLEARINT_CLR_RX_DMA_SHIFT	    (17)
#define SCI__CLEARINT_CLR_TX_DMA_MASK		(0x00010000UL)
#define SCI__CLEARINT_CLR_TX_DMA_SHIFT	    (16)
#define SCI__CLEARINT_CLR_RX_MASK			(0x00000200UL)
#define SCI__CLEARINT_CLR_RX_SHIFT	    	(9)
#define SCI__CLEARINT_CLR_TX_MASK		   	(0x00000100UL)
#define SCI__CLEARINT_CLR_TX_SHIFT	    	(8)
#define SCI__CLEARINT_CLR_WAKEUP_MASK	   	(0x00000002UL)
#define SCI__CLEARINT_CLR_WAKEUP_SHIFT	    (1)
#define SCI__CLEARINT_CLR_BRKDT_MASK	   	(0x00000001UL)
#define SCI__CLEARINT_CLR_BRKDT_SHIFT	   	(0)



/** SCI Interrupts Table */
#define SCI__INTERRUPT_WAKEUP_FLAG			(1)
#define SCI__INTERRUPT_PARITY_ERROR_FLAG	(3)
#define SCI__INTERRUPT_FRAME_ERROR_FLAG		(6)
#define SCI__INTERRUPT_BRKDT_ERROR_FLAG		(7)
#define SCI__INTERRUPT_OVERRUN_ERROR_FLAG	(9)
#define SCI__INTERRUPT_RECEIVE_FLAG			(11)
#define SCI__INTERRUPT_TRANSMIT_FLAG		(12)


/* exported types */

/** @struct sciBase
 *   @brief SCI Register Definition
 *
 *   This structure is used to access the SCI module egisters.
 */

typedef struct
{
  uint32 GCR0;          /* 0x0000 Global Control Register 0 */
  uint32 GCR1;          /* 0x0004 Global Control Register 1 */
  uint32 GCR2;          /* 0x0008 Global Control Register 2 */
  uint32 SETINT;        /* 0x000C Set Interrupt Enable Register */
  uint32 CLRINT;        /* 0x0010 Clear Interrupt Enable Register */
  uint32 SETINTLVL;     /* 0x0014 Set Interrupt Level Register */
  uint32 CLRINTLVL;     /* 0x0018 Set Interrupt Level Register */
  uint32 FLR;           /* 0x001C Interrupt Flag Register */
  uint32 INTVECT0;      /* 0x0020 Interrupt Vector Offset 0 */
  uint32 INTVECT1;      /* 0x0024 Interrupt Vector Offset 1 */
#if _little_endian__
  uint16 CHAR;
  uint16 LENGTH;        /* 0x0028 Format Control Register */
#else
  uint16 LENGTH;        /* 0x0028 Format Control Register */
  uint16 CHAR;
#endif
  uint32 BRS;           /* 0x002C Baud Rate Selection Register */
  uint8  reserved0[3];
  uint8  ED;            /* 0x0033 Emulation Register */
  uint8  reserved1[3];
  uint8  RD;            /* 0x0037 Receive Data Buffer */
  uint8  reserved2[3];
  uint8  TD;            /* 0x003B Transmit Data Buffer */
  uint32 FUN;           /* 0x003C Pin Function Register */
  uint32 DIR;           /* 0x0040 Pin Direction Register */
  uint32 DIN;           /* 0x0044 Pin Data In Register */
  uint32 DOUT;          /* 0x0040 Pin Data Out Register */
  uint32 SET;           /* 0x004C Pin Data Set Register */
  uint32 CLR;           /* 0x0050 Pin Data Clr Register */
  uint32 ODR;           /* 0x0054: Pin Open Drain Output Enable Register */
  uint32 PD;            /* 0x0058: Pin Pullup/Pulldown Disable Register */
  uint32 PSL;           /* 0x005C: Pin Pullup/Pulldown Selection Register */
  uint32 COMPARE;		/* 0x0060: LIN Compare Registers*/
  uint32 RD0;           /* 0x0064: LIN Receive Buffer 0 Register*/
  uint32 RD1;           /* 0x0068: LIN Receive Buffer 1 Register*/
  uint32 MASK;          /* 0x005C: LIN Mask Register*/
  uint32 ID;            /* 0x0070: LIN Identification Register*/
  uint32 TD0;           /* 0x0074: LIN Transmit Buffer 0*/
  uint32 TD1;           /* 0x0078: LIN Transmit Buffer 1*/
}UART__tstMemMap;

/* exported variables */

/* exported functions */

#endif /* UART_REG_H_ */
