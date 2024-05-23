

/* system headers */
#include "Std_Types.h"
/* used headers */
#include "TestInfo_def.h"
#include "TestInfo.h"

#include "MMD012_INDSENS_def.h"
#include "MMD012_INDSENS_cfg.h"
#include "MMD012_INDSENS.h"

#include "MMW039_DATACOMP_def.h"
#include "MMW039_DATACOMP.h"
#include "MMD022_DIOMUX.h"
#include "ANALOG.h"


/* own headers */
#include "SITR_TestDriver_MMD012_INDSENS_CHV-Ch-P.h"

/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define INDSENS_TEST_s_nPT_RTMC_IMD015_1    	(16000U)   /*16us*/
#define INDSENS_TEST_s_nPT_RTMC_IMD006_1    	(70000U)   /*70us*/


/* internal__types */

/* private__variables */
static uint32* INDSENS_TEST_s_pau32PrevIndSens = (uint32*)NULL;
static uint32* INDSENS_TEST_s_pau32PrevIndSens_Mirror = (uint32*)NULL;
static uint8 INDSENS_TEST_s_u8State = 0U;


/* private__functions */
void INDSENS_TEST_s_vGetVarAddr(void)
{
	INDSENS_TEST_s_pau32PrevIndSens = (uint32*)TESTINFO_pvGetAddress();
	INDSENS_TEST_s_pau32PrevIndSens_Mirror = (uint32*)TESTINFO_pvGetAddress();
}

static void SINT_MMD012_DAT_SBT_IMD0015_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	uint16 u16j;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	INDSENS_vInit();

	for(u16j = 0; u16j < (uint16)INDSENS_enTotalSensors; u16j++)
	{
		u8TestResult = (INDSENS_TEST_s_pau32PrevIndSens[u16j] == ((uint32)E_NOT_OK) ? TRUE : FALSE);
		u8TestResult &= (INDSENS_TEST_s_pau32PrevIndSens_Mirror[u16j] == (uint32)~INDSENS_TEST_s_pau32PrevIndSens[u16j] ? TRUE : FALSE);
	}

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void SINT_MMD012_BBT_ECP_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_middle_value_of_range(INDSENS_enTotalSensors,TESTINFO_nMAXU16);
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_INVALID_SIGNAL) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_BBT_ECP_IMD006_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_middle_value_of_range(TESTINFO_nZERO,INDSENS_enTotalSensors);

	INDSENS_TEST_s_pau32PrevIndSens[INDSENS_enSwitchRrR] = (uint32)INDSENS_nPREV_STATE;

	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_CORRUPT_DATA) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_BBT_BVA_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)INDSENS_enTotalSensors;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_INVALID_SIGNAL) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_BBT_BVA_IMD006_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_right_int_limit(INDSENS_enTotalSensors);
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_INVALID_SIGNAL) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_BBT_BVA_IMD006_3(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_left_int_limit(TESTINFO_nMAXU16);
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_INVALID_SIGNAL) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_BBT_BVA_IMD006_4(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_nMAXU16;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_INVALID_SIGNAL) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void SINT_MMD012_PT_RTMC_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);
	uint16 u16SensorId = (uint16)TESTINFO_middle_value_of_range(TESTINFO_nZERO,INDSENS_enTotalSensors);
	TESTINFO_vGetStartTime();
	INDSENS_u32GetState(u16SensorId);
	TESTINFO_vEvaluateTime(__func__, INDSENS_TEST_s_nPT_RTMC_IMD006_1);
}

/* public_functions */
void SINT_MMD012(uint16 u16Component, uint8 u8RunBlock)
{
    TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

    INDSENS_TEST_s_vGetVarAddr();

    SINT_MMD012_DAT_SBT_IMD0015_1(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
    SINT_MMD012_BBT_ECP_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
    SINT_MMD012_BBT_ECP_IMD006_2(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);

    SINT_MMD012_BBT_BVA_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
    SINT_MMD012_BBT_BVA_IMD006_2(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
    SINT_MMD012_BBT_BVA_IMD006_3(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
    SINT_MMD012_BBT_BVA_IMD006_4(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);

    SINT_MMD012_PT_RTMC_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
}
void SINT_MMD012_PT_RTMC_IMD015_1(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__,(uint32)INDSENS_TEST_s_nPT_RTMC_IMD015_1);

	if (INDSENS_TEST_s_u8State == (uint8)TESTINFO_nZERO_RIGHT)
	{
		INDSENS_TEST_s_vGetVarAddr();
		SINT_MMD012_DAT_SBT_IMD0015_1(u16Component, (uint8)STD_ENABLE, (uint16)TESTINFO_enAuto);
	}
	else
	{
		INDSENS_TEST_s_u8State++;
	}
}


/* EOF */
