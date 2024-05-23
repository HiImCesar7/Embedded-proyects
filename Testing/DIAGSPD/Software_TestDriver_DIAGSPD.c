

/* system headers */
#include "Std_Types.h"

/* used headers */
#include "TestInfo.h"
#include "TestInfo_def.h"
#include "MAP028_DIAGSPD.h"
#include "MAP028_DIAGSPD_cfg.h"
#include "MAP028_DIAGSPD_def.h"

/* own headers */
#include "SITR_TestDriver_MAP028_DIAGSPD_CHV-Ch-P.h"

/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define DIAGSPD_TEST_s_nPT_RTMC_IAP034_1 (20000U)	/* Max execution time for Init interface: 20 us */
#define DIAGSPD_TEST_s_nPT_RTMC_IAP035_1 (220000U)	/* Max execution time for Monitor interface: 210 us */
#define DIAGSPD_TEST_s_nPT_RTMC_IAP036_1 (10000U)	/* Max execution time for IsDiagRunning interface: 10 us */

/* internal__types */
typedef enum
{
	DIAGSPD_TEST_s_enStandBy = 0,
	DIAGSPD_TEST_s_enGenFreq,
	DIAGSPD_TEST_s_enDiagnostic,
	DIAGSPD_TEST_s_enTotalStates
}DIAGSPD_TEST_s_tenStates;

typedef enum
{
	DIAGSPD_TEST_s_enFreq100Hz = 0,
	DIAGSPD_TEST_s_enFreq125Hz,
	DIAGSPD_TEST_s_enFreq250Hz,
	DIAGSPD_TEST_s_enFreq500Hz,
	DIAGSPD_TEST_s_enTotalFreqs
}DIAGSPD_TEST_s_tenFreqStates;

/* private__variables */
static uint16* DIAGSPD_TEST_s_pu16State = (uint16*)NULL;
static uint16* DIAGSPD_TEST_s_pu16State_Mirror = (uint16*)NULL;
static uint16* DIAGSPD_TEST_s_pu16FreqState = (uint16*)NULL;
static uint16* DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16*)NULL;
static uint32* DIAGSPD_TEST_s_pu32LastTime = (uint32*)NULL;
static uint32* DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32*)NULL;

/* private__functions */
static void DIAGSPD_TEST_s_vGetStaticAddr(void)
{
	DIAGSPD_TEST_s_pu16State = (uint16*)TESTINFO_pvGetAddress();
	DIAGSPD_TEST_s_pu16State_Mirror = (uint16*)TESTINFO_pvGetAddress();
	DIAGSPD_TEST_s_pu16FreqState = (uint16*)TESTINFO_pvGetAddress();
	DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16*)TESTINFO_pvGetAddress();
	DIAGSPD_TEST_s_pu32LastTime = (uint32*)TESTINFO_pvGetAddress();
	DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint32*)TESTINFO_pvGetAddress();
}

/*********************************************** DIAGSPD_vMonitor Tests ***********************************************/

static void SINT_MAP028_BBT_BVA_IAP035_11_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)DIAGSPD_TEST_s_enTotalFreqs;
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_12_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_right_int_limit(DIAGSPD_TEST_s_enTotalFreqs);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_13_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_left_int_limit(TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_14_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_nMAXU16;
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_18_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_right_int_limit(DIAGSPD_TEST_s_enFreq500Hz);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_19_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_left_int_limit(TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_BBT_BVA_IAP035_20_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_nMAXU16;
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_DAT_SBT_IAP035_11_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_enTotalFreqs, TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_DAT_SBT_IAP035_12_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_enTotalFreqs, TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16FreqState);
}

static void SINT_MAP028_DAT_SBT_IAP035_15_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16FreqState = (uint16)TESTINFO_middle_value_of_range(TESTINFO_nZERO, TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu16FreqState_Mirror = (uint16)*DIAGSPD_TEST_s_pu16FreqState;
}

static void SINT_MAP028_DAT_SBT_IAP035_16_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu32LastTime = (uint16)TESTINFO_middle_value_of_range(TESTINFO_nZERO, TESTINFO_nMAXU16);
	*DIAGSPD_TEST_s_pu32LastTime_Mirror = (uint16)*DIAGSPD_TEST_s_pu32LastTime;
}

static void SINT_MAP028_DAT_SBT_IAP035_17_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)TESTINFO_middle_value_of_range(DIAGSPD_TEST_s_enFreq100Hz, DIAGSPD_TEST_s_enTotalFreqs);
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)*DIAGSPD_TEST_s_pu16State;
}

/*********************************************** DIAGSPD_u8IsDiagRunning Tests ***********************************************/

static void SINT_MAP028_BBT_ECP_IAP036_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint8 u8TestResult = (uint8)TRUE;
	uint8 u8StateRet = (uint8)TRUE;

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	u8StateRet = DIAGSPD_u8IsDiagRunning();

	u8TestResult = (u8StateRet == (uint8)FALSE)? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void SINT_MAP028_BBT_ECP_IAP036_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint8 u8TestResult = (uint8)TRUE;
	uint8 u8StateRet = (uint8)FALSE;

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	u8StateRet = DIAGSPD_u8IsDiagRunning();

	u8TestResult = (u8StateRet == (uint8)TRUE)? u8TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u8TestResult);

	/* returns initial state to DIAGSPD_s_u16State */
	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enStandBy;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);
}

static void SINT_MAP028_DAT_SBT_IAP036_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enDiagnostic;
	*DIAGSPD_TEST_s_pu16State_Mirror = *DIAGSPD_TEST_s_pu16State;

	(void)DIAGSPD_u8IsDiagRunning();
}

static void SINT_MAP028_PT_RTMC_IAP036_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	*DIAGSPD_TEST_s_pu16State = (uint16)DIAGSPD_TEST_s_enGenFreq;
	*DIAGSPD_TEST_s_pu16State_Mirror = (uint16)~(*DIAGSPD_TEST_s_pu16State);

	TESTINFO_vGetStartTime();
	(void)DIAGSPD_u8IsDiagRunning();
	TESTINFO_vEvaluateTime(__func__, DIAGSPD_TEST_s_nPT_RTMC_IAP036_1);
}

/* public_functions */
void SINT_MAP028_SET(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	DIAGSPD_TEST_s_vGetStaticAddr();

	SINT_MAP028_BBT_BVA_IAP035_11_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_12_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_13_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_14_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_18_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_19_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_BBT_BVA_IAP035_20_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_DAT_SBT_IAP035_11_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_DAT_SBT_IAP035_12_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_INVALID_ID */
	SINT_MAP028_DAT_SBT_IAP035_15_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_CORRUPT_DATA */
	SINT_MAP028_DAT_SBT_IAP035_16_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_CORRUPT_DATA */
	SINT_MAP028_DAT_SBT_IAP035_17_SET(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_CORRUPT_DATA */
}

void SINT_MAP028_CHK(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);
}

void SINT_MAP028(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	DIAGSPD_TEST_s_vGetStaticAddr();

	SINT_MAP028_BBT_ECP_IAP036_1(u16Component, u8RunBlock, (uint8)TESTINFO_enAuto);
	SINT_MAP028_BBT_ECP_IAP036_2(u16Component, u8RunBlock, (uint8)TESTINFO_enAuto);
	SINT_MAP028_PT_RTMC_IAP036_1(u16Component, u8RunBlock, (uint8)TESTINFO_enAuto);

	SINT_MAP028_DAT_SBT_IAP036_1(u16Component, (uint8)STD_DISABLE, (uint8)TESTINFO_enManual);	/* E_CORRUPT_DATA */
}

void SINT_MAP028_PT_RTMC_IAP034_1(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component, u16TestType, __func__, DIAGSPD_TEST_s_nPT_RTMC_IAP034_1);
}

void SINT_MAP028_PT_RTMC_IAP035_1(uint16 u16Component, uint16 u16TestType)
{
	/*it's necessary set the right conditions manually through a debug session in order to measure the longest path*/
	TESTINFO_nh_time_measurement(u16Component, u16TestType, __func__, DIAGSPD_TEST_s_nPT_RTMC_IAP035_1);
}

/* EOF */
