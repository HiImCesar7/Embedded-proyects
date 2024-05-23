

/* system headers */
#include "Std_Types.h"

/* used headers */
#include "TestInfo.h"
#include "TestInfo_def.h"
#include "MAP028_DIAGSPD.h"
#include "MAP028_DIAGSPD_cfg.h"
#include "MAP028_DIAGSPD_def.h"
#include "MMD022_DIOMUX.h"
#include "RTC.h"
#include "DIOCFG_def.h"
#include "NHET_def.h"
#include "MMD024_DIAGHSD_def.h"
#include "MMD024_DIAGHSD.h"
#include "MMD014_PORTEXP_def.h"

/* own headers */
#include "HSITR_TestDriver_MAP028_DIAGSPD_CHV-Ch-P.h"


/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define DIAGSPD_TEST_s_nFRONTSENS			(2U)
#define DIAGSPD_TEST_s_nREARSENS			(2U)
#define DIAGSPD_TEST_s_nINIT_FREQ		(uint8)(0)

#define DIAGSPD_TEST_s_nPT_RTMC_IAP034_1 	(32U)	/* Max execution time for Init interface */
#define DIAGSPD_TEST_s_nPT_RTMC_IAP035_1 	(275U)	/* Max execution time for Monitor interface */
#define DIAGSPD_TEST_s_nPT_RTMC_IAP036_1 	(10U)	/* Max execution time for IsDiagRunning interface */

/* internal__types */
typedef struct
{
	uint16 u16PwrSig;
	uint16 u16PwrDiag;
	uint16 u16NhetSigA;
	uint16 u16NhetSigB;
}DIAGSPD_TEST_s_tstFrontSignals;

typedef struct
{
	uint16 u16PwrSig;
	uint16 u16PwrDiag;
	uint16 u16NhetSig;
	uint16 u16Padding;
}DIAGSPD_TEST_s_tstRearSignals;

typedef enum
{
	DIAGSPD_TEST_s_enStandBy = 0,
	DIAGSPD_TEST_s_enGenFreq,
	DIAGSPD_TEST_s_enDiagnostic,
	DIAGSPD_TEST_s_enTotalStates
}DIAGSPD_TEST_s_tenStates;

typedef enum
{
	DIAGSPD_TEST_s_enFreq50Hz = DIAGSPD_TEST_s_nINIT_FREQ,
	DIAGSPD_TEST_s_enTotalFreqs
}DIAGSPD_s_tenFreqStates;

/* private__variables */
static uint16 *DIAGSPD_TEST_s_pu16State;
static uint16 *DIAGSPD_TEST_s_pu16State_Mirror;
static uint16 *DIAGSPD_TEST_s_pu16FreqState;
static uint16 *DIAGSPD_TEST_s_pu16FreqState_Mirror;
static uint32 *DIAGSPD_TEST_s_pu32LastTime;
static uint32 *DIAGSPD_TEST_s_pu32LastTime_Mirror;
static uint8 *DIAGSPD_TEST_s_pu8LastHalfPeriodNumber;
static uint8 *DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror;
static uint32 *DIAGSPD_TEST_s_pu32PulseInitTime;
static uint32 *DIAGSPD_TEST_s_pu32PulseInitTime_Mirror;
static uint32 DIAGSPD_TEST_s_u32ActualTimeValue;

static uint8 DIAGSPD_TEST_s_u8InitTest = (uint8)STD_INACTIVE;

static DIAGSPD_TEST_s_tstFrontSignals DIAGSPD_TEST_s_astFrontSig[DIAGSPD_TEST_s_nFRONTSENS] = DIAGSPD_TABLE_FRONTSIG_cfg;
static DIAGSPD_TEST_s_tstRearSignals DIAGSPD_TEST_s_astRearSig[DIAGSPD_TEST_s_nREARSENS] = DIAGSPD_TABLE_REARSIG_cfg;
/* private__functions */
/************************************ Tests for Init interface ************************************/
static void HSINT_MAP028_DAT_SBT_IAP034_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	uint8 u8TestResult = (uint8)TRUE;

	u8TestResult = (*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enStandBy)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16State_Mirror == (uint16)~(*DIAGSPD_TEST_s_pu16State))? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16FreqState == (uint16)DIAGSPD_TEST_s_nINIT_FREQ)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16FreqState_Mirror == (uint16)~(*DIAGSPD_TEST_s_pu16FreqState))? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu32LastTime != (uint32)TESTINFO_nZERO)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu32LastTime_Mirror == (uint32)~(*DIAGSPD_TEST_s_pu32LastTime))? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror == (uint8)~(*DIAGSPD_TEST_s_pu8LastHalfPeriodNumber))? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu32PulseInitTime_Mirror == (uint32)~(*DIAGSPD_TEST_s_pu32PulseInitTime))? u8TestResult : (uint8)FALSE;
	u8TestResult = (DIOMUX_s32GetState((uint16)DIAGSPD_FREQ_DIG_ID_cfg) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

/************************************ Tests for Monitor interface ************************************/
static void HSINT_MAP028_DAT_SBT_IAP035_1_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8Len = (uint8)TESTINFO_nZERO;

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	DIAGSPD_TEST_s_u32ActualTimeValue = RTC_u32GetKernelClock();

	*DIAGSPD_TEST_s_pu32LastTime = (uint32)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_u32ActualTimeValue, TESTINFO_nMAXU32);
	*DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32)~(*DIAGSPD_TEST_s_pu32LastTime);

	DIOMUX_vSetState((uint16)DIAGSPD_FREQ_DIG_ID_cfg, (uint8)STD_HIGH);

	for(u8Len = 0U; u8Len < DIAGSPD_TEST_s_nFRONTSENS; u8Len++)
	{
		DIOMUX_vSetState(DIAGSPD_TEST_s_astFrontSig[u8Len].u16PwrSig, (uint8)STD_HIGH);
		DIOMUX_vSetState(DIAGSPD_TEST_s_astRearSig[u8Len].u16PwrSig, (uint8)STD_HIGH);
	}

	DIOMUX_vSetState((uint16)DIAGSPD_PWRTEST_DIG_ID_cfg, (uint8)STD_LOW);

}

static void HSINT_MAP028_DAT_SBT_IAP035_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8TestResult = (uint8)TRUE;
	uint8 u8Len = (uint8)TESTINFO_nZERO;

	u8TestResult = (*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enGenFreq)? u8TestResult : (uint8)FALSE;
	u8TestResult = (DIOMUX_s32GetState((uint16)DIAGSPD_FREQ_DIG_ID_cfg) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;
	for(u8Len = 0U; u8Len < DIAGSPD_TEST_s_nFRONTSENS; u8Len++)
	{
		u8TestResult = (DIOMUX_s32GetState(DIAGSPD_TEST_s_astFrontSig[u8Len].u16PwrSig) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;
		u8TestResult = (DIOMUX_s32GetState(DIAGSPD_TEST_s_astRearSig[u8Len].u16PwrSig) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;
	}

	u8TestResult = (DIOMUX_s32GetState((uint16)DIAGSPD_PWRTEST_DIG_ID_cfg) == (sint32)STD_HIGH)? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void HSINT_MAP028_DAT_SBT_IAP035_2_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	DIAGSPD_TEST_s_u32ActualTimeValue = RTC_u32GetKernelClock();

	*DIAGSPD_TEST_s_pu32LastTime = (uint32)TESTINFO_middle_value_of_range(TESTINFO_nZERO, DIAGSPD_TEST_s_u32ActualTimeValue);
	*DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32)~(*DIAGSPD_TEST_s_pu32LastTime);
}

static void HSINT_MAP028_DAT_SBT_IAP035_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8TestResult = (uint8)TRUE;

	u8TestResult = (*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enStandBy)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu32LastTime == (uint32)TESTINFO_middle_value_of_range(TESTINFO_nZERO, DIAGSPD_TEST_s_u32ActualTimeValue))? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void HSINT_MAP028_DAT_SBT_IAP035_3_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	*DIAGSPD_TEST_s_pu16FreqState = (uint16)DIAGSPD_TEST_s_enFreq50Hz;
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void HSINT_MAP028_DAT_SBT_IAP035_3(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8TestResult = (uint8)TRUE;

	u8TestResult = (*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enDiagnostic)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16State_Mirror == (uint16)~DIAGSPD_TEST_s_enDiagnostic)? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void HSINT_MAP028_DAT_SBT_IAP035_5_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	*DIAGSPD_TEST_s_pu16FreqState = (uint16)DIAGSPD_TEST_s_enFreq50Hz;
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void HSINT_MAP028_DAT_SBT_IAP035_5(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8TestResult = (uint8)TRUE;

	u8TestResult = (*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enStandBy)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16State_Mirror == (uint16)~DIAGSPD_TEST_s_enStandBy)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16FreqState == (uint16)DIAGSPD_TEST_s_nINIT_FREQ)? u8TestResult : (uint8)FALSE;
	u8TestResult = (*DIAGSPD_TEST_s_pu16FreqState_Mirror == (uint16)~DIAGSPD_TEST_s_nINIT_FREQ)? u8TestResult : (uint8)FALSE;
	u8TestResult = (DIOMUX_s32GetState((uint16)DIAGSPD_FREQ_DIG_ID_cfg) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;
	u8TestResult = (DIOMUX_s32GetState((uint16)DIAGSPD_PWRTEST_DIG_ID_cfg) == (sint32)STD_LOW)? u8TestResult : (uint8)FALSE;

	for(uint8 u8Len = 0U; u8Len < DIAGSPD_TEST_s_nFRONTSENS; u8Len++)
	{
		u8TestResult = (DIOMUX_s32GetState(DIAGSPD_TEST_s_astFrontSig[u8Len].u16PwrSig) == (sint32)STD_HIGH)? u8TestResult : (uint8)FALSE;
		u8TestResult = (DIOMUX_s32GetState(DIAGSPD_TEST_s_astRearSig[u8Len].u16PwrSig) == (sint32)STD_HIGH)? u8TestResult : (uint8)FALSE;
	}

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void HSINT_MAP028_DAT_SBT_IAP035_11_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8Len = (uint8)TESTINFO_nZERO;

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	DIAGSPD_TEST_s_u32ActualTimeValue = RTC_u32GetKernelClock();

	*DIAGSPD_TEST_s_pu32LastTime = (uint32)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_u32ActualTimeValue, TESTINFO_nMAXU32);
	*DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32)~(*DIAGSPD_TEST_s_pu32LastTime);
}

static void HSINT_MAP028_DAT_SBT_IAP035_12_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_is_enabled(u16Component, u8RunTest, u16TestType);

	uint8 u8Len = (uint8)TESTINFO_nZERO;

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	DIAGSPD_TEST_s_u32ActualTimeValue = RTC_u32GetKernelClock();

	*DIAGSPD_TEST_s_pu32LastTime = (uint32)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_u32ActualTimeValue, TESTINFO_nMAXU32);
	*DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32)~(*DIAGSPD_TEST_s_pu32LastTime);
}


static void HSINT_MAP028_PT_RTMC_IAP036_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component, u8RunTest, u16TestType);

	TESTINFO_vGetStartTime();
	(void)DIAGSPD_u8IsDiagRunning();
	TESTINFO_vEvaluateTime(__func__, DIAGSPD_TEST_s_nPT_RTMC_IAP036_1);
}

/* public_functions */
void HSINT_MAP028_SET(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	DIAGSPD_TEST_vGetStaticAddr(&DIAGSPD_TEST_s_pu16State, &DIAGSPD_TEST_s_pu16State_Mirror, &DIAGSPD_TEST_s_pu16FreqState,
			                    &DIAGSPD_TEST_s_pu16FreqState_Mirror, &DIAGSPD_TEST_s_pu32LastTime, &DIAGSPD_TEST_s_pu32LastTime_Mirror,
								&DIAGSPD_TEST_s_pu8LastHalfPeriodNumber, &DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror,
								&DIAGSPD_TEST_s_pu32PulseInitTime, &DIAGSPD_TEST_s_pu32PulseInitTime_Mirror);

	DIOMUX_vSetState(DIOCFG_enEBRK_KL15_PWR, (uint8)STD_OFF);

	HSINT_MAP028_DAT_SBT_IAP035_1_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	HSINT_MAP028_DAT_SBT_IAP035_2_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	HSINT_MAP028_DAT_SBT_IAP035_3_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	HSINT_MAP028_DAT_SBT_IAP035_11_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enManual);  //ASSERT_HARD_ERROR Sensores frontales
	HSINT_MAP028_DAT_SBT_IAP035_12_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enManual);  //ASSERT_HARD_ERROR Sensores traseros

	if(*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enStandBy)
	{
		HSINT_MAP028_DAT_SBT_IAP035_5_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	}
	else
	{

	}
}

void HSINT_MAP028_CHK(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	DIAGSPD_TEST_vGetStaticAddr(&DIAGSPD_TEST_s_pu16State, &DIAGSPD_TEST_s_pu16State_Mirror, &DIAGSPD_TEST_s_pu16FreqState,
					                    &DIAGSPD_TEST_s_pu16FreqState_Mirror, &DIAGSPD_TEST_s_pu32LastTime, &DIAGSPD_TEST_s_pu32LastTime_Mirror,
										&DIAGSPD_TEST_s_pu8LastHalfPeriodNumber, &DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror,
										&DIAGSPD_TEST_s_pu32PulseInitTime, &DIAGSPD_TEST_s_pu32PulseInitTime_Mirror);

	HSINT_MAP028_DAT_SBT_IAP035_1(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	HSINT_MAP028_DAT_SBT_IAP035_2(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);

	if(*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enDiagnostic)
	{
		HSINT_MAP028_DAT_SBT_IAP035_3(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);

		*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
		*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	}
	else if(*DIAGSPD_TEST_s_pu16State == (uint16)DIAGSPD_TEST_s_enStandBy)
	{
		HSINT_MAP028_DAT_SBT_IAP035_5(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	}
	else
	{

	}

	HSINT_MAP028_PT_RTMC_IAP036_1(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);



}

void HSINT_MAP028(uint16 u16Component, uint8 u8RunBlock)
{
	/*EMPTY BLOCK*/
}


void HSINT_MAP028_PT_RTMC_IAP034_1(uint16 u16Component, uint16 u16TestType)
{

		TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__, (uint32)DIAGSPD_TEST_s_nPT_RTMC_IAP034_1);

		if(DIAGSPD_TEST_s_u8InitTest == (uint8)STD_ACTIVE)
		{
			DIAGSPD_TEST_vGetStaticAddr(&DIAGSPD_TEST_s_pu16State, &DIAGSPD_TEST_s_pu16State_Mirror, &DIAGSPD_TEST_s_pu16FreqState,
												&DIAGSPD_TEST_s_pu16FreqState_Mirror, &DIAGSPD_TEST_s_pu32LastTime, &DIAGSPD_TEST_s_pu32LastTime_Mirror,
												&DIAGSPD_TEST_s_pu8LastHalfPeriodNumber, &DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror,
												&DIAGSPD_TEST_s_pu32PulseInitTime, &DIAGSPD_TEST_s_pu32PulseInitTime_Mirror);

			HSINT_MAP028_DAT_SBT_IAP034_1(u16Component, (uint8)STD_ENABLE, (uint16)TESTINFO_enAuto);

			DIAGSPD_TEST_s_u8InitTest = (uint8)STD_INACTIVE;
		}
		else
		{
			DIAGSPD_TEST_vGetStaticAddr(&DIAGSPD_TEST_s_pu16State, &DIAGSPD_TEST_s_pu16State_Mirror, &DIAGSPD_TEST_s_pu16FreqState,
															&DIAGSPD_TEST_s_pu16FreqState_Mirror, &DIAGSPD_TEST_s_pu32LastTime, &DIAGSPD_TEST_s_pu32LastTime_Mirror,
															&DIAGSPD_TEST_s_pu8LastHalfPeriodNumber, &DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror,
															&DIAGSPD_TEST_s_pu32PulseInitTime, &DIAGSPD_TEST_s_pu32PulseInitTime_Mirror);

			*DIAGSPD_TEST_s_pu16State = (uint16)~DIAGSPD_TEST_s_enStandBy;
			*DIAGSPD_TEST_s_pu16State_Mirror = *DIAGSPD_TEST_s_pu16State;
			*DIAGSPD_TEST_s_pu16FreqState = (uint16)~DIAGSPD_TEST_s_enFreq50Hz;
			*DIAGSPD_TEST_s_pu16FreqState_Mirror = *DIAGSPD_TEST_s_pu16FreqState;
			*DIAGSPD_TEST_s_pu32LastTime = (uint32)TESTINFO_nZERO;
			*DIAGSPD_TEST_s_pu32LastTime_Mirror = *DIAGSPD_TEST_s_pu32LastTime;
			*DIAGSPD_TEST_s_pu8LastHalfPeriodNumber = (uint8)TESTINFO_nZERO;
			*DIAGSPD_TEST_s_pu8LastHalfPeriodNumber_Mirror = *DIAGSPD_TEST_s_pu8LastHalfPeriodNumber;
			*DIAGSPD_TEST_s_pu32PulseInitTime = (uint32)TESTINFO_nZERO;
			*DIAGSPD_TEST_s_pu32PulseInitTime_Mirror = *DIAGSPD_TEST_s_pu32PulseInitTime;

			DIAGSPD_TEST_s_u8InitTest = (uint8)STD_ACTIVE;
		}
}

void HSINT_MAP028_PT_RTMC_IAP035_1(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__, (uint32)DIAGSPD_TEST_s_nPT_RTMC_IAP035_1);
}

/* EOF */
