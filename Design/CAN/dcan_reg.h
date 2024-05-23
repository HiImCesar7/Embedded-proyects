
#ifndef DCAN_REG_H_
#define DCAN_REG_H_

/* system headers */
#include "Std_Types.h"
/* used headers */

/* own headers */

/*****************************************************************************/

/* exported pre-procesor macros */

#define DCAN__1_ADDR_PTR	((DCAN__tstMemMap *)0xFFF7DC00U)
#define DCAN__2_ADDR_PTR	((DCAN__tstMemMap *)0xFFF7DE00U)
#define DCAN__3_ADDR_PTR	((DCAN__tstMemMap *)0xFFF7E000U)

/************************************************************************************
 * REGISTER MASKS
 ************************************************************************************/
/** CAN Control Register (DCAN CTL) */
#define DCAN__CTL_WABA_MASK		(0x2000000UL)
#define DCAN__CTL_WABA_SHIFT	(25)
#define DCAN__CTL_PDR_MASK		(0x1000000UL)
#define DCAN__CTL_PDR_SHIFT		(24)
#define DCAN__CTL_DE3_MASK		(0x0100000UL)
#define DCAN__CTL_DE3_SHIFT		(20)
#define DCAN__CTL_DE2_MASK		(0x0080000UL)
#define DCAN__CTL_DE2_SHIFT		(19)
#define DCAN__CTL_DE1_MASK		(0x0040000UL)
#define DCAN__CTL_DE1_SHIFT		(18)
#define DCAN__CTL_IE1_MASK		(0x0020000UL)
#define DCAN__CTL_IE1_SHIFT		(17)
#define DCAN__CTL_INIT_DBG_MASK	(0x0010000UL)
#define DCAN__CTL_INIT_DBG_SHIFT	(16)
#define DCAN__CTL_SWR_MASK		(0x0008000UL)
#define DCAN__CTL_SWR_SHIFT		(15)
#define DCAN__CTL_PMD_MASK		(0x0003C00UL)
#define DCAN__CTL_PMD_SHIFT		(10)
#define DCAN__CTL_PMD(x)		(((uint32)(((uint32)(x)) << DCAN__CTL_PMD_SHIFT)) & DCAN__CTL_PMD_MASK)
#define DCAN__CTL_ABO_MASK		(0x0000200UL)
#define DCAN__CTL_ABO_SHIFT		(9)
#define DCAN__CTL_IDS_MASK		(0x0000100UL)
#define DCAN__CTL_IDS_SHIFT		(8)
#define DCAN__CTL_TEST_MASK		(0x0000080UL)
#define DCAN__CTL_TEST_SHIFT	(7)
#define DCAN__CTL_CCE_MASK		(0x0000040UL)
#define DCAN__CTL_CCE_SHIFT		(6)
#define DCAN__CTL_DAR_MASK		(0x0000020UL)
#define DCAN__CTL_DAR_SHIFT		(5)
#define DCAN__CTL_EIE_MASK		(0x0000008UL)
#define DCAN__CTL_EIE_SHIFT		(3)
#define DCAN__CTL_SIE_MASK		(0x0000004UL)
#define DCAN__CTL_SIE_SHIFT		(2)
#define DCAN__CTL_IE0_MASK		(0x0000002UL)
#define DCAN__CTL_IE0_SHIFT		(1)
#define DCAN__CTL_INIT_MASK		(0x0000001UL)
#define DCAN__CTL_INIT_SHIFT	(0)


/** Error and Status Register (DCAN ES) */
#define DCAN__ES_PDA_MASK			(0x0000400UL)
#define DCAN__ES_PDA_SHIFT			10
#define DCAN__ES_WAKEUP_PND_MASK	(0x0000200UL)
#define DCAN__ES_WAKEUP_PND_SHIFT	9
#define DCAN__ES_PER_MASK			(0x0000100UL)
#define DCAN__ES_PER_SHIFT			8
#define DCAN__ES_BOFF_MASK			(0x0000080UL)
#define DCAN__ES_BOFF_SHIFT			7
#define DCAN__ES_EWARN_MASK			(0x0000040UL)
#define DCAN__ES_EWARN_SHIFT		6
#define DCAN__ES_EPASS_MASK			(0x0000020UL)
#define DCAN__ES_EPASS_SHIFT		5
#define DCAN__ES_RXOK_MASK			(0x0000010UL)
#define DCAN__ES_RXOK_SHIFT			4
#define DCAN__ES_TXOK_MASK			(0x0000008UL)
#define DCAN__ES_TXOK_SHIFT			3
#define DCAN__ES_LEC_MASK			(0x0000007UL)
#define DCAN__ES_LEC_SHIFT			0
#define DCAN__ES_LEC(x)				(((uint32)(((uint32)(x)) << DCAN__ES_LEC_SHIFT)) & DCAN__ES_LEC_MASK)


/** IF1/IF2 Command Registers (DCAN IF1CMD, DCAN IF2CMD) */
#define DCAN__IFxCMD_WRRD_MASK			(0x80)
#define DCAN__IFxCMD_MASK_MASK			(0x40)
#define DCAN__IFxCMD_ARB_MASK			(0x20)
#define DCAN__IFxCMD_CONTROL_MASK		(0x10)
#define DCAN__IFxCMD_CLRINTPND_MASK		(0x08)
#define DCAN__IFxCMD_TXRQNEWDATA_MASK	(0x04)
#define DCAN__IFxCMD_TXRQNEWDATA_SHIFT	2
#define DCAN__IFxCMD_DATAA_MASK			(0x02)
#define DCAN__IFxCMD_DATAB_MASK			(0x01)

#define DCAN__IFxSTAT_BUSY_MASK			(0x80)
#define DCAN__IFxSTAT_DMAACTIVE_MASK	(0x40)


/** IF1/IF2 Message Control Registers (DCAN IF1MCTL, DCAN IF2MCTL) */
#define DCAN__IFxMCTL_NEWDAT_MASK	(0x00008000UL)
#define DCAN__IFxMCTL_NEWDAT_SHIFT	15
#define DCAN__IFxMCTL_MSGLST_MASK	(0x00004000UL)
#define DCAN__IFxMCTL_MSGLST_SHIFT	14
#define DCAN__IFxMCTL_INTPND_MASK	(0x00002000UL)
#define DCAN__IFxMCTL_INTPND_SHIFT	13
#define DCAN__IFxMCTL_UMASK_MASK	(0x00001000UL)
#define DCAN__IFxMCTL_UMASK_SHIFT	12
#define DCAN__IFxMCTL_TXIE_MASK		(0x00000800UL)
#define DCAN__IFxMCTL_TXIE_SHIFT	11
#define DCAN__IFxMCTL_TXIE(x)		(((uint32)(((uint32)(x)) << DCAN__IFxMCTL_TXIE_SHIFT)) & DCAN__IFxMCTL_TXIE_MASK)
#define DCAN__IFxMCTL_RXIE_MASK		(0x00000400UL)
#define DCAN__IFxMCTL_RXIE_SHIFT	10
#define DCAN__IFxMCTL_RXIE(x)		(((uint32)(((uint32)(x)) << DCAN__IFxMCTL_RXIE_SHIFT)) & DCAN__IFxMCTL_RXIE_MASK)
#define DCAN__IFxMCTL_RMTEN_MASK	(0x00000200UL)
#define DCAN__IFxMCTL_RMTEN_SHIFT	9
#define DCAN__IFxMCTL_TXRQST_MASK	(0x00000100UL)
#define DCAN__IFxMCTL_TXRQST_SHIFT	8
#define DCAN__IFxMCTL_EOB_MASK		(0x00000080UL)
#define DCAN__IFxMCTL_EOB_SHIFT		7
#define DCAN__IFxMCTL_DLC_MASK		(0x0000000FUL)
#define DCAN__IFxMCTL_DLC_SHIFT		0
#define DCAN__IFxMCTL_DLC(x)		(((uint32)(((uint32)(x)) << DCAN__IFxMCTL_DLC_SHIFT)) & DCAN__IFxMCTL_DLC_MASK)


/** IF1/IF2 Arbitration Registers (DCAN IF1ARB, DCAN IF2ARB) */
#define DCAN__IFxARB_MSGVAL_MASK	(0x80000000UL)
#define DCAN__IFxARB_MSGVAL_SHIFT	31
#define DCAN__IFxARB_XDT_MASK		(0x40000000UL)
#define DCAN__IFxARB_XDT_SHIFT		30
#define DCAN__IFxARB_XDT(x)			(((uint32)(((uint32)(x)) << DCAN__IFxARB_XDT_SHIFT)) & DCAN__IFxARB_XDT_MASK)
#define DCAN__IFxARB_DIR_MASK		(0x20000000UL)
#define DCAN__IFxARB_DIR_SHIFT		29
#define DCAN__IFxARB_DIR(x)			(((uint32)(((uint32)(x)) << DCAN__IFxARB_DIR_SHIFT)) & DCAN__IFxARB_DIR_MASK)
#define DCAN__IFxARB_ID_MASK		(0x1FFFFFFFUL)
#define DCAN__IFxARB_ID_SHIFT		0
#define DCAN__IFxARB_ID(x)			(((uint32)(((uint32)(x)) << DCAN__IFxARB_ID_SHIFT)) & DCAN__IFxARB_ID_MASK)


/** IF1/IF2 Mask Registers (DCAN IF1MSK, DCAN IF2MSK) */
#define DCAN__IFxMSK_MXTD_MASK		(0x80000000UL)
#define DCAN__IFxMSK_MXTD_SHIFT		31
#define DCAN__IFxMSK_MDIR_MASK		(0x40000000UL)
#define DCAN__IFxMSK_MDIR_SHIFT		30
#define DCAN__IFxMSK_MSK_MASK		(0x1FFFFFFFUL)
#define DCAN__IFxMSK_MSK_SHIFT		0
#define DCAN__IFxMSK_MSK(x)			(((uint32)(((uint32)(x)) << DCAN__IFxMSK_MSK_SHIFT)) & DCAN__IFxMSK_MSK_MASK)



/** Bit Timing Register (DCAN BTR) */
#define DCAN__BTR_BRPE_MASK		(0x000F0000UL)
#define DCAN__BTR_BRPE_SHIFT	16
#define DCAN__BTR_BRPE(x)		(((uint32)(((uint32)(x)) << DCAN__BTR_BRPE_SHIFT)) & DCAN__BTR_BRPE_MASK)
#define DCAN__BTR_TSEG2_MASK	(0x00007000UL)
#define DCAN__BTR_TSEG2_SHIFT	12
#define DCAN__BTR_TSEG2(x)		(((uint32)(((uint32)(x)) << DCAN__BTR_TSEG2_SHIFT)) & DCAN__BTR_TSEG2_MASK)
#define DCAN__BTR_TSEG1_MASK	(0x00000F00UL)
#define DCAN__BTR_TSEG1_SHIFT	8
#define DCAN__BTR_TSEG1(x)		(((uint32)(((uint32)(x)) << DCAN__BTR_TSEG1_SHIFT)) & DCAN__BTR_TSEG1_MASK)
#define DCAN__BTR_SJW_MASK		(0x00000060UL)
#define DCAN__BTR_SJW_SHIFT		6
#define DCAN__BTR_SJW(x)		(((uint32)(((uint32)(x)) << DCAN__BTR_SJW_SHIFT)) & DCAN__BTR_SJW_MASK)
#define DCAN__BTR_BRP_MASK		(0x0000001FUL)
#define DCAN__BTR_BRP_SHIFT		0
#define DCAN__BTR_BRP(x)		(((uint32)(((uint32)(x)) << DCAN__BTR_BRP_SHIFT)) & DCAN__BTR_BRP_MASK)


/** CAN TX IO Control Register (DCAN TIOC) */
#define DCAN__TIOC_PU_MASK		(0x00040000UL)
#define DCAN__TIOC_PU_SHIFT		18
#define DCAN__TIOC_PD_MASK		(0x00020000UL)
#define DCAN__TIOC_PD_SHIFT		17
#define DCAN__TIOC_OD_MASK		(0x00010000UL)
#define DCAN__TIOC_OD_SHIFT		16
#define DCAN__TIOC_FUNC_MASK	(0x00000008UL)
#define DCAN__TIOC_FUNC_SHIFT	3
#define DCAN__TIOC_DIR_MASK		(0x00000004UL)
#define DCAN__TIOC_DIR_SHIFT	2
#define DCAN__TIOC_OUT_MASK		(0x00000002UL)
#define DCAN__TIOC_OUT_SHIFT	1
#define DCAN__TIOC_OUT(x)		(((uint32)(((uint32)(x)) << DCAN__TIOC_OUT_SHIFT)) & DCAN__TIOC_OUT_MASK)
#define DCAN__TIOC_IN_MASK		(0x00000001UL)
#define DCAN__TIOC_IN_SHIFT		0


/** CAN RX IO Control Register (DCAN RIOC) */
#define DCAN__RIOC_PU_MASK		(0x00040000UL)
#define DCAN__RIOC_PU_SHIFT		18
#define DCAN__RIOC_PD_MASK		(0x00020000UL)
#define DCAN__RIOC_PD_SHIFT		17
#define DCAN__RIOC_OD_MASK		(0x00010000UL)
#define DCAN__RIOC_OD_SHIFT		16
#define DCAN__RIOC_FUNC_MASK	(0x00000008UL)
#define DCAN__RIOC_FUNC_SHIFT	3
#define DCAN__RIOC_DIR_MASK		(0x00000004UL)
#define DCAN__RIOC_DIR_SHIFT	2
#define DCAN__RIOC_OUT_MASK		(0x00000002UL)
#define DCAN__RIOC_OUT_SHIFT	1
#define DCAN__RIOC_OUT(x)		(((uint32)(((uint32)(x)) << DCAN__RIOC_OUT_SHIFT)) & DCAN__RIOC_OUT_MASK)
#define DCAN__RIOC_IN_MASK		(0x00000001UL)
#define DCAN__RIOC_IN_SHIFT		0

/* exported types */

/**
 * CAN Register Frame Definition.
 * This type is used to access the CAN Registers.
*/
typedef struct
{
  uint32 CTL;          /**< 0x0000: Control Register                  */
  uint32 ES;           /**< 0x0004: Error and Status Register         */
  uint32 EERC;         /**< 0x0008: Error Counter Register            */
  uint32 BTR;          /**< 0x000C: Bit Timing Register               */
  uint32 INT;          /**< 0x0010: Interrupt Register                */
  uint32 TEST;         /**< 0x0014: Test Register                     */
  uint32 res1;         /**< 0x0018: Reserved                          */
  uint32 PERR;         /**< 0x001C: Parity/SECDED Error Code Register */
  uint32 REL;          /**< 0x0020: Core Release Register             */
  uint32 ECCDIAG;      /**< 0x0024: ECC Diagnostic Register           */
  uint32 ECCDIADSTAT;  /**< 0x0028: ECC Diagnostic Status Register    */
  uint32 res2[21];
  uint32 ABOTR;        /**< 0x0080: Auto Bus On Time Register         */
  uint32 TXRQX;        /**< 0x0084: Transmission Request X Register   */
  uint32 TXRQx[4U];    /**< 0x0088-0x0094: Transmission Request Registers  */
  uint32 NWDATX;       /**< 0x0098: New Data X Register               */
  uint32 NWDATx[4U];   /**< 0x009C-0x00A8: New Data Registers         */
  uint32 INTPNDX;      /**< 0x00AC: Interrupt Pending X Register      */
  uint32 INTPNDx[4U];  /**< 0x00B0-0x00BC: Interrupt Pending Registers*/
  uint32 MSGVALX;      /**< 0x00C0: Message Valid X Register          */
  uint32 MSGVALx[4U];  /**< 0x00C4-0x00D0: Message Valid Registers    */
  uint32 res3;         /**< 0x00D4: Reserved                          */
  uint32 INTMUXx[4U];  /**< 0x00D8-0x00E4: Interrupt Multiplexer Registers */
  uint32 res4[6];
#if _little_endian__ /*__BYTE_ORDER == __LITTLE_ENDIAN*/
  uint8 IF1NO;        /**< 0x0100: IF1 Command Register, Msg Number  */
  uint8 IF1STAT;      /**< 0x0100: IF1 Command Register, Status      */
  uint8 IF1CMD;       /**< 0x0100: IF1 Command Register, Command     */
  uint8   res5;       /**< 0x0100: IF1 Command Register, Reserved    */
#else
  uint8 res5;         /**< 0x0100: IF1 Command Register, Reserved    */
  uint8 IF1CMD;       /**< 0x0100: IF1 Command Register, Command     */
  uint8 IF1STAT;      /**< 0x0100: IF1 Command Register, Status      */
  uint8 IF1NO;        /**< 0x0100: IF1 Command Register, Msg Number  */
#endif
  uint32 IF1MSK;      /**< 0x0104: IF1 Mask Register                 */
  uint32 IF1ARB;      /**< 0x0108: IF1 Arbitration Register          */
  uint32 IF1MCTL;     /**< 0x010C: IF1 Message Control Register      */
  uint8 IF1DATx[8U];  /**< 0x0110-0x0114: IF1 Data A and B Registers */
  uint32 res6[2];     /**< 0x0118: Reserved                          */
#if _little_endian__ /*__BYTE_ORDER == __LITTLE_ENDIAN*/
  uint8 IF2NO;        /**< 0x0100: IF2 Command Register, Msg No      */
  uint8 IF2STAT;      /**< 0x0100: IF2 Command Register, Status      */
  uint8 IF2CMD;       /**< 0x0100: IF2 Command Register, Command     */
  uint8 res7;         /**< 0x0100: IF2 Command Register, Reserved    */
#else
  uint8 res7;         /**< 0x0100: IF2 Command Register, Reserved    */
  uint8 IF2CMD;       /**< 0x0100: IF2 Command Register, Command     */
  uint8 IF2STAT;      /**< 0x0100: IF2 Command Register, Status      */
  uint8 IF2NO;        /**< 0x0100: IF2 Command Register, Msg Number  */ 
#endif
  uint32 IF2MSK;      /**< 0x0124: IF2 Mask Register                 */
  uint32 IF2ARB;      /**< 0x0128: IF2 Arbitration Register          */
  uint32 IF2MCTL;     /**< 0x012C: IF2 Message Control Register      */
  uint8 IF2DATx[8U];  /**< 0x0130-0x0134: IF2 Data A and B Registers */
  uint32 res8[2];     /**< 0x0138: Reserved                          */
  uint32 IF3OBS;      /**< 0x0140: IF3 Observation Register          */
  uint32 IF3MSK;      /**< 0x0144: IF3 Mask Register                 */
  uint32 IF3ARB;      /**< 0x0148: IF3 Arbitration Register          */
  uint32 IF3MCTL;     /**< 0x014C: IF3 Message Control Register      */
  uint8 IF3DATx[8U];  /**< 0x0150-0x0154: IF3 Data A and B Registers */
  uint32 res9[2];     /**< 0x0158: Reserved                          */
  uint32 IF3UEy[4U];  /**< 0x0160-0x016C: IF3 Update Enable Registers*/
  uint32 res10[28];
  uint32 TIOC;        /**< 0x01E0: TX IO Control Register            */
  uint32 RIOC;        /**< 0x01E4: RX IO Control Register            */
}DCAN__tstMemMap;
/* exported variables */

/* exported functions */


#endif /* DCAN_REG_H_ */
