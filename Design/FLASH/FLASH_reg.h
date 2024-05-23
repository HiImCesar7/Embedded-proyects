

#ifndef FLASH_REG_H_
#define FLASH_REG_H_

/* system headers */

#include "Std_Types.h"

/* used headers */

/* own headers */

/****************************************************************************************/

/* exported configuration macros */

#define FLASH__ADDR_PTR ((FLASH__tstMemMap *)0xFFF87000U) 

/*****************************************************************************************
 **** REGISTER MASKS & SHIFTS                                                         ****
 ****************************************************************************************/

/**** Flash Option Control Register (FLASH FRDCNTL) [Offset = FFF8 7000 h] **************/

#define FLASH__FRDCNTL_RWAIT_MASK    (0x00000F00UL)
#define FLASH__FRDCNTL_RWAIT_SHIFT   (8)
#define FLASH__FRDCNTL_RWAIT(x)      (((uint32)(((uint32)(x)) << FLASH__FRDCNTL_RWAIT_SHIFT)) & FLASH__FRDCNTL_RWAIT_MASK)
#define FLASH__FRDCNTL_ASWSTEN_MASK  (0x00000010UL)
#define FLASH__FRDCNTL_ASWSTEN_SHIFT (4)
#define FLASH__FRDCNTL_ENPIPE_MASK   (0x00000001UL)
#define FLASH__FRDCNTL_ENPIPE_SHIFT  (0)

/**** Flash Error Detection and Correction Control Register 1 (FLASH FEDACCTRL1) [Offset = FFF8 7008 h] *****/ 

#define FLASH__FEDACCTRL1_SUSP_IGNR_MASK  (0x01000000UL)
#define FLASH__FEDACCTRL1_SUSP_IGNR_SHIFT (24)
#define FLASH__FEDACCTRL1_EDACMODE_MASK   (0x000F0000UL)
#define FLASH__FEDACCTRL1_EDACMODE_SHIFT  (16)
#define FLASH__FEDACCTRL1_EDACMODE(x)     (((uint32)(((uint32)(x)) << FLASH__FEDACCTRL1_EDACMODE_SHIFT)) & FLASH__FEDACCTRL1_EDACMODE_MASK)
#define FLASH__FEDACCTRL1_EZFEN_MASK      (0x00000200UL)
#define FLASH__FEDACCTRL1_EZFEN_SHIFT     (9)
#define FLASH__FEDACCTRL1_EPEN_MASK       (0x00000100UL)
#define FLASH__FEDACCTRL1_EPEN_SHIFT      (8)
#define FLASH__FEDACCTRL1_EOCV_MASK       (0x00000020UL)
#define FLASH__FEDACCTRL1_EOCV_SHIFT      (5)
#define FLASH__FEDACCTRL1_EZCV_MASK       (0x00000010UL)
#define FLASH__FEDACCTRL1_EZCV_SHIFT      (4)
#define FLASH__FEDACCTRL1_EDACEN_MASK     (0x0000000FUL)
#define FLASH__FEDACCTRL1_EDACEN_SHIFT    (0)
#define FLASH__FEDACCTRL1_EDACEN(x)       (((uint32)(((uint32)(x)) << FLASH__FEDACCTRL1_EDACEN_SHIFT)) & FLASH__FEDACCTRL1_EDACEN_MASK)

/**** Flash Error Detection and Correction Control Register 2 (FLASH FEDACCTRL2) [Offset = FFF8 700C h] ****/

#define FLASH__FEDACCTRL2_SEC_THRESHOLD_MASK  (0x0000FFFFUL)
#define FLASH__FEDACCTRL2_SEC_THRESHOLD_SHIFT (0)
#define FLASH__FEDACCTRL2_SEC_THRESHOLD(x)    (((uint32)(((uint32)(x)) << FLASH__FEDACCTRL2_SEC_THRESHOLD_SHIFT)) & FLASH__FEDACCTRL2_SEC_THRESHOLD_MASK)

/**** Flash Un-correctable Error Address (FLASH FUNC_ERR_ADD) [Offset = FFF8 7020 h] ****/

#define FLASH__FUNC_ERR_ADD_UNC_ERR_ADD_MASK  (0xFFFFFFF8UL)
#define FLASH__FUNC_ERR_ADD_UNC_ERR_ADD_SHIFT (3)
#define FLASH__FUNC_ERR_ADD_UNC_ERR_ADD(x)    (((uint32)(((uint32)(x)) << FLASH__FUNC_ERR_ADD_UNC_ERR_ADD_SHIFT)) & FLASH__FUNC_ERR_ADD_UNC_ERR_ADD_MASK)
#define FLASH__FUNC_ERR_ADD_WORD_OFFSET_MASK  (0x00000007UL)
#define FLASH__FUNC_ERR_ADD_WORD_OFFSET_SHIFT (0)
#define FLASH__FUNC_ERR_ADD_WORD_OFFSET(x)    (((uint32)(((uint32)(x)) << FLASH__FUNC_ERR_ADD_WORD_OFFSET_SHIFT)) & FLASH__FUNC_ERR_ADD_WORD_OFFSET_MASK) 

/**** Flash Bank Protection Register (FLASH FBPROT) [Offset = FFF8 7030 h] **************/

#define FLASH__FBPROT_PROTL1DIS_MASK  (0x00000001UL)
#define FLASH__FBPROT_PROTL1DIS_SHIFT (0)

/**** Flash Bank Sector Enable Register (FLASH FBSE) [Offset = FFF8 7034 h] *************/

#define FLASH__FBSE_BSE_MASK  (0x0000FFFFUL)
#define FLASH__FBSE_BSE_SHIFT (0)
#define FLASH__FBSE_BSE(x)    (((uint32)(((uint32)(x)) << FLASH__FBSE_BSE_SHIFT)) & FLASH__FBSE_BSE_MASK)

/**** Flash Bank Access Control Register (FLASH FBAC) [Offset = FFF8 703C h] ************/

#define FLASH__FBAC_OTPPROTDIS_MASK  (0x00FF0000UL)
#define FLASH__FBAC_OTPPROTDIS_SHIFT (16)
#define FLASH__FBAC_OTPPROTDIS(x)    (((uint32)(((uint32)(x)) << FLASH__FBAC_OTPPROTDIS_SHIFT)) & FLASH__FBAC_OTPPROTDIS_MASK)
#define FLASH__FBAC_BAGP_MASK        (0x0000FF00UL)
#define FLASH__FBAC_BAGP_SHIFT       (8)
#define FLASH__FBAC_BAGP(x)          (((uint32)(((uint32)(x)) << FLASH__FBAC_BAGP_SHIFT)) & FLASH__FBAC_BAGP_MASK)
#define FLASH__FBAC_VREADST_MASK     (0x000000FFUL)
#define FLASH__FBAC_VREADST_SHIFT    (0)
#define FLASH__FBAC_VREADST(x)       (((uint32)(((uint32)(x)) << FLASH__FBAC_VREADST_SHIFT)) & FLASH__FBAC_VREADST_MASK)

/**** Flash Bank Fallback Power Register (FLASH FBFALLBACK) [Offset = FFF8 7040 h] ******/

#define FLASH__FBFALLBACK_BANKPWR3_MASK  (0x000000C0UL)
#define FLASH__FBFALLBACK_BANKPWR3_SHIFT (6)
#define FLASH__FBFALLBACK_BANKPWR3(x)    (((uint32)(((uint32)(x)) << FLASH__FBFALLBACK_BANKPWR3_SHIFT)) & FLASH__FBFALLBACK_BANKPWR3_MASK)
#define FLASH__FBFALLBACK_BANKPWR2_MASK  (0x00000030UL)
#define FLASH__FBFALLBACK_BANKPWR2_SHIFT (4)
#define FLASH__FBFALLBACK_BANKPWR2(x)    (((uint32)(((uint32)(x)) << FLASH__FBFALLBACK_BANKPWR2_SHIFT)) & FLASH__FBFALLBACK_BANKPWR2_MASK)
#define FLASH__FBFALLBACK_BANKPWR1_MASK  (0x0000000CUL)
#define FLASH__FBFALLBACK_BANKPWR1_SHIFT (2)
#define FLASH__FBFALLBACK_BANKPWR1(x)    (((uint32)(((uint32)(x)) << FLASH__FBFALLBACK_BANKPWR1_SHIFT)) & FLASH__FBFALLBACK_BANKPWR1_MASK)
#define FLASH__FBFALLBACK_BANKPWR0_MASK  (0x00000003UL)
#define FLASH__FBFALLBACK_BANKPWR0_SHIFT (0)
#define FLASH__FBFALLBACK_BANKPWR0(x)    (((uint32)(((uint32)(x)) << FLASH__FBFALLBACK_BANKPWR0_SHIFT)) & FLASH__FBFALLBACK_BANKPWR0_MASK)

/**** Flash Pump Access Control Register 1 (FLASH FPAC1) [Offset = FFF8 7048 h] *********/

#define FLASH__FPAC1_PSLEEP_MASK   (0x07FF0000UL)
#define FLASH__FPAC1_PSLEEP_SHIFT  (16)
#define FLASH__FPAC1_PSLEEP(x)     (((uint32)(((uint32)(x)) << FLASH__FPAC1_PSLEEP_SHIFT)) & FLASH__FPAC1_PSLEEP_MASK)
#define FLASH__FPAC1_PUMPPWR_MASK  (0x00000001UL)
#define FLASH__FPAC1_PUMPPWR_SHIFT (0)

/**** Flash Pump Access Control Register 2 (FLASH FPAC2) [Offset = FFF8 704C h] *********/

#define FLASH__FPAC2_PAGP_MASK  (0x0000FFFFUL)
#define FLASH__FPAC2_PAGP_SHIFT (0)
#define FLASH__FPAC2_PAGP(x)    (((uint32)(((uint32)(x)) << FLASH__FPAC2_PAGP_SHIFT)) & FLASH__FPAC2_PAGP_MASK)

/**** Flash Module Access Control Register (FLASH FMAC) [Offset = FFF8 7050 h] **********/

#define FLASH__FMAC_BANK_MASK  (0x00000007UL)
#define FLASH__FMAC_BANK_SHIFT (0)
#define FLASH__FMAC_BANK(x)    (((uint32)(((uint32)(x)) << FLASH__FMAC_BANK_SHIFT)) & FLASH__FMAC_BANK_MASK)

/**** Flash Module Status Register (FLASH FMSTAT) [Offset = FFF8 7054 h] ****************/

#define FLASH__FMSTAT_RVSUSP_MASK    (0x00020000UL)
#define FLASH__FMSTAT_RVSUSP_SHIFT   (17)
#define FLASH__FMSTAT_RDVER_MASK     (0x00010000UL)
#define FLASH__FMSTAT_RDVER_SHIFT    (16)
#define FLASH__FMSTAT_RVF_MASK       (0x00008000UL)
#define FLASH__FMSTAT_RVF_SHIFT      (15)
#define FLASH__FMSTAT_ILA_MASK       (0x00004000UL)
#define FLASH__FMSTAT_ILA_SHIFT      (14)
#define FLASH__FMSTAT_DBT_MASK       (0x00002000UL)
#define FLASH__FMSTAT_DBT_SHIFT      (13)
#define FLASH__FMSTAT_PGV_MASK       (0x00001000UL)
#define FLASH__FMSTAT_PGV_SHIFT      (12)
#define FLASH__FMSTAT_PCV_MASK       (0x00000800UL)
#define FLASH__FMSTAT_PCV_SHIFT      (11)
#define FLASH__FMSTAT_EV_MASK        (0x00000400UL)
#define FLASH__FMSTAT_EV_SHIFT       (10)
#define FLASH__FMSTAT_CV_MASK        (0x00000200UL)
#define FLASH__FMSTAT_CV_SHIFT       (9)
#define FLASH__FMSTAT_BUSY_MASK      (0x00000100UL)
#define FLASH__FMSTAT_BUSY_SHIFT     (8)
#define FLASH__FMSTAT_ERS_MKASK      (0x00000080UL)
#define FLASH__FMSTAT_ERS_SHIFT      (7)
#define FLASH__FMSTAT_PGM_MASK       (0x00000040UL)
#define FLASH__FMSTAT_PGM_SHIFY      (6)
#define FLASH__FMSTAT_INV_DAT_MASK   (0x00000020UL)
#define FLASH__FMSTAT_INV_DAT_SHIFT  (5)
#define FLASH__FMSTAT_CSTAT_MASK     (0x00000010UL)
#define FLASH__FMSTAT_CSTAT_SHIFT    (4)
#define FLASH__FMSTAT_VOLTSTAT_MASK  (0x00000008UL)
#define FLASH__FMSTAT_VOLTSTAT_SHIFT (3)
#define FLASH__FMSTAT_ESUSP_MASK     (0x00000004UL)
#define FLASH__FMSTAT_ESUSP_SHIFT    (2)
#define FLASH__FMSTAT_PSUSP_MASK     (0x00000002UL)
#define FLASH__FMSTAT_PSUSP_SHIFT    (1)
#define FLASH__FMSTAT_SLOCK_MASK     (0x00000001UL)
#define FLASH__FMSTAT_SLOCK_SHIFT    (0)

/**** FSM Register Write Enable (FLASH FSM_WR_ENA) [Offset = FFF8 7288 h] ***************/

#define FLASH__FSM_WR_ENA_WR_ENA_MASK  (0x00000007UL)
#define FLASH__FSM_WR_ENA_WR_ENA_SHIFT (0)
#define FLASH__FSM_WR_ENA_WR_ENA(x)    (((uint32)(((uint32)(x)) << FLASH__FSM_WR_ENA_WR_ENA_SHIFT)) & FLASH__FSM_WR_ENA_WR_ENA_MASK)

/**** EEPROM Emulation Configuration Register (FLASH EEPROM_CONFIG) [Offset = FFF8 72B8 h] ****/

#define FLASH__EEPROM_CONFIG_EWAIT_MASK            (0x000F0000UL)
#define FLASH__EEPROM_CONFIG_EWAIT_SHIFT           (16)
#define FLASH__EEPROM_CONFIG_EWAIT(x)              (((uint32)(((uint32)(x)) << FLASH__EEPROM_CONFIG_EWAIT_SHIFT)) & FLASH__EEPROM_CONFIG_EWAIT_MASK)
#define FLASH__EEPROM_CONFIG_AUTOSUSP_EN_MASK      (0x00000100UL)
#define FLASH__EEPROM_CONFIG_AUTOSUSP_EN_SHIFT     (8)
#define FLASH__EEPROM_CONFIG_AUTOSTART_GRACE_MASK  (0x000000FFUL)
#define FLASH__EEPROM_CONFIG_AUTOSTART_GRACE_SHIFT (0)
#define FLASH__EEPROM_CONFIG_AUTOSTART_GRACE(x)    (((uint32)(((uint32)(x)) << FLASH__EEPROM_CONFIG_AUTOSTART_GRACE_SHIFT)) & FLASH__EEPROM_CONFIG_AUTOSTART_GRACE_MASK)

/* exported types */

/*****************************************************************************************
 * 
 * FLASH Register Frame Definition.
 * This type is used to access the FLASH Registers.
 * 
*****************************************************************************************/

typedef struct
{
   uint32 FRDCNTL;        /* FFF8 7000h : Flash Option Control Register                 */    
   uint32 reserved1;      /* FFF8 7004h : Reserved                                      */
   uint32 FEDACTRL1;      /* FFF8 7008h : Error Detection and Correction Control Reg. 1 */
   uint32 FEDACTRL2;      /* FFF8 700Ch : Error Detection and Correction Control Reg. 2 */
   uint32 reserved2[4];   /* FFF8 7010h : Reserved                                      */
   uint32 FUNC_ERR_ADD;   /* FFF8 7020h : Flash Un-correctable Error Address            */
   uint32 reserved3[3];   /* FFF8 7024h : Reserved                                      */
   uint32 FBPROT;         /* FFF8 7030h : Flash Bank Protection Register                */
   uint32 FBSE;           /* FFF8 7034h : Flash Bank Sector Enable Register             */
   uint32 reserved4;      /* FFF8 7038h : Reserved                                      */
   uint32 FBAC;           /* FFF8 703Ch : Flash Bank Access Control Register            */
   uint32 FBFALLBACK;     /* FFF8 7040h : Flash Bank Fallback Power Register            */
   uint32 reserved5;      /* FFF8 7044h : Reserved                                      */
   uint32 FPAC1;          /* FFF8 7048h : Flash Pump Access Control Register 1          */
   uint32 FPAC2;          /* FFF8 704Ch : Flash Pump Access Control Register 2          */
   uint32 FMAC;           /* FFF8 7050h : Flash Module Access Control Register          */
   uint32 FMSTAT;         /* FFF8 7054h : Flash Module Status Register                  */   
   uint32 reserved6[140]; /* FFF8 7058h : Reserved                                      */
   uint32 FSM_WR_ENA;     /* FFF8 7288h : FSM Register Write Enable                     */
   uint32 reserved7[11];  /* FFF8 728Ch : Reserved                                      */
   uint32 EEPROM_CONFIG;  /* FFF8 72B8h : EEPROM Emulation Configuration Register       */
}FLASH__tstMemMap;

/* exported variables */

/* exported functions */

#endif /* FLASH_REG_H_ */
