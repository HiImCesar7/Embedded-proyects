

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
#include "DIOCFG_def.h"

/* own headers */
#include "HSITR_TestDriver_MMD012_INDSENS_CHV-CH-P.h"

/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */
#define INDSENS_TEST_s_nPT_RTMC_IMD015_1    	(16U)   /*16us*/
#define INDSENS_TEST_s_nPT_RTMC_IMD006_1    	(70U)   /*70us*/

/* internal__types */

/* private__variables */

/* private__functions */
static void HSINT_MMD012_DAT_ECP_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)INDSENS_enSwitchRrL;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_OPEN_LOAD) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void HSINT_MMD012_DAT_ECP_IMD006_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)INDSENS_enSwitchRrL;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)STD_HIGH) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void HSINT_MMD012_DAT_ECP_IMD006_3(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)INDSENS_enSwitchRrL;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)STD_LOW) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void HSINT_MMD012_BBT_BVA_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_nZERO;
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_OPEN_LOAD) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void HSINT_MMD012_BBT_BVA_IMD006_2(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_right_int_limit(TESTINFO_nZERO);
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_OPEN_LOAD) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}
static void HSINT_MMD012_BBT_BVA_IMD006_3(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32Return = (uint32)TESTINFO_nZERO;
	uint8 u8TestResult = (uint8)TESTINFO_nZERO;

	uint16 u16SensorId = (uint16)TESTINFO_left_int_limit(INDSENS_enTotalSensors);
	u32Return = INDSENS_u32GetState(u16SensorId);
	u8TestResult = (uint8)(u32Return == ((uint32)E_OPEN_LOAD) ? TRUE : FALSE);

	TESTINFO_vPrintStatus(__func__, u8TestResult);
}

static void HSINT_MMD012_PT_RTMC_IMD006_1(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint16 u16SensorId = (uint16)INDSENS_enSwitchRrR;
	TESTINFO_vGetStartTime();
	INDSENS_u32GetState(u16SensorId);
	TESTINFO_vEvaluateTime(__func__, INDSENS_TEST_s_nPT_RTMC_IMD006_1);
}

/* public_functions */
void HSINT_MMD012(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	HSINT_MMD012_DAT_ECP_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);
	HSINT_MMD012_DAT_ECP_IMD006_2(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);
	HSINT_MMD012_DAT_ECP_IMD006_3(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);

	HSINT_MMD012_BBT_BVA_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);
	HSINT_MMD012_BBT_BVA_IMD006_2(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);
	HSINT_MMD012_BBT_BVA_IMD006_3(u16Component,u8RunBlock,(uint16)TESTINFO_enManual);

	HSINT_MMD012_PT_RTMC_IMD006_1(u16Component,u8RunBlock,(uint16)TESTINFO_enAuto);
}

void HSINT_MMD012_PT_RTMC_IMD015_1(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__,(uint32)INDSENS_TEST_s_nPT_RTMC_IMD015_1);
}
/* EOF */
