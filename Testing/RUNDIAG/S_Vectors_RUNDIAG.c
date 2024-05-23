

/* system headers */
#include "Std_Types.h"
#include "_assert_.h"
/* used headers */
/**TestInfo**/
#include "TestInfo.h"
#include "TestInfo_def.h"
/**MAP010_RUNDIAG**/
#include "MAP010_RUNDIAG_cfg.h"
#include "MAP010_RUNDIAG_def.h"
#include "MAP010_RUNDIAG.h"
/**MMW039_DATACOMP**/
#include "MMW039_DATACOMP_def.h"
#include "MMW039_DATACOMP.h"
/**MSF026_BRKFLAGS**/
#include "MSF026_BRKFLAGS.h"
#include "MSF026_BRKFLAGS_def.h"
/**MSGQUEUE**/
#include "MSGQUEUE_def.h"
#include "MSGQUEUE.h"
/**MMD023_DIAGENC**/
#include "MMD023_DIAGENC_cfg.h"
/**ANALOG**/
#include "ANALOG_def.h"
/**ANALOG_ISR**/
#include "ANALOG_ISR_def.h"
#include "ANALOG_ISR_cfg.h"
/**GPIO**/
#include "GPIO__def.h"
#include "GPIO_.h"
/**MMD022_DIOMUX**/
#include "MMD022_DIOMUX.h"
/**MMD034_DIAGSWITCH**/
#include "MMD034_DIAGSWITCH_cfg.h"
/**MMD021_DOORSENS**/
#include "MMD021_DOORSENS_cfg.h"
/**GPIO__**/
#include "GPIO__cfg.h"
/**ANALOGCFG**/
#include "ANALOGCFG_def.h"
#include "ANALOGCFG_cfg.h"

/* own headers */
#include "SITS_Vectors_MAP010_RUNDIAG_CHV-Ch-P.h"

/*[EXPORTED]****************************************************************************/
/* public_variables */

/*[INTERNAL]****************************************************************************/
/* internal__pre-processor macros */
/**
 * @def  RUNDIAG_TEST_s_nDIRECT_SIGNALS
 * @brief Constate que representa el valor del grupo de se�ales conectadas directamente al m�dulo ADC1.
 * @note
 */
#define RUNDIAG_TEST_s_nDIRECT_SIGNALS	(8U)


/**
 * @def  RUNDIAG_TEST_s_nP10Flag
 * @brief Constante que define la activaci�n del freno de emergencia por medio de la funci�n de seguridad P10
 * @note
 */
#define RUNDIAG_TEST_s_nP10Flag	(4096U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_5000
 * @brief Constante que define la captura cruda de 5000, para obtener el valor equivalente de las se�ales de los sensores inductivos.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_5000    (5000U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_6000
 * @brief Constante que define la captura cruda de 6000, para obtener el valor equivalente de las se�ales de los sensores inductivos.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_6000    (6000U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_2000
 * @brief Constante que define la captura cruda de 2000, para obtener el valor equivalente de las se�ales de los sensores inductivos.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_2000   (2000U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_400
 * @brief Constante que define la captura cruda de 400, para obtener el valor equivalente de las se�ales de los sensores inductivos.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_400   (400U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_1900
 * @brief Constante que define la captura cruda de 1900, para obtener el valor equivalente de las se�ales de los sensores inductivos.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_1900  (1900U)

/**
 * @def  RUNDIAG_TEST_s_nRAWVAL_2300
 * @brief Constante que define la captura cruda de 2300, para obtener el valor equivalente de las se�ales de los sensores limit switch.
 * @note
 */
#define RUNDIAG_TEST_s_nRAWVAL_2300  (2300U)


/**
 * @def  RUNDIAG_s_check_id(u8TestId)
 * @brief Macro que define el n�mero o id de la prueba que se va a ejecutar.
 * @note
 */
#define RUNDIAG_s_check_id(u8TestId)	\
	if ((u8TestId) == RUNDIAG_TEST_s_u8TestCount)	\
	{		\
		/* Nothing to do */		\
	}		\
	else	\
	{		\
		return;	\
	}

/* internal__types */
/*Enumeraci�n que se utiliza para identificar las pruebas.*/
typedef enum
{
	RUNDIAG_enECP_IAP032_03_SET = 0,
	RUNDIAG_enECP_IAP032_03_CTRL,
	RUNDIAG_enECP_IAP032_04_SET,
	RUNDIAG_enECP_IAP032_04_CTRL,
	RUNDIAG_enECP_IAP032_05_SET,
	RUNDIAG_enECP_IAP032_05_CTRL,
	RUNDIAG_enECP_IAP032_06_SET,
	RUNDIAG_enECP_IAP032_06_CTRL,
	RUNDIAG_enECP_IAP032_07_SET,
	RUNDIAG_enECP_IAP032_07_CTRL,
	RUNDIAG_enTotalMRBTestId
}RUNDIAG_TEST_s_tenMBRTestId;

/*Enumeraci�n que se utiliza para identificar las se�ales de diagn�stico de los sensores.*/
typedef enum{
	RUNDIAG_TEST_enRlyDiag = 0,					/**< Identificador del estado de diagnostico del rel� de reseteo remoto */
	RUNDIAG_TEST_enWheelFrontLeft,			/**< Identificador del diagn�stico del sensor de la rueda frontal izquierda */
	RUNDIAG_TEST_enWheelFrontRight,			/**< Identificador del diagn�stico del sensor de la rueda frontal derecha  */
	RUNDIAG_TEST_enWheelRearLeft,			/**< Identificador del diagn�stico del sensor de la rueda trasera izquierda */
	RUNDIAG_TEST_enWheelRearRight,			/**< Identificador del diagn�stico del sensor de la rueda trasera derecha */
	RUNDIAG_TEST_enSwitchFrL,			/**< Identificador del estado del sensor inductivo S-FrL-1*/
	RUNDIAG_TEST_enSwitchFrR,			/**< Identificador del estado del sensor inductivo S-FrR-1 */
	RUNDIAG_TEST_enSwitchRrL,			/**< Identificador del estado del sensor inductivo S-RrL-1 */
	RUNDIAG_TEST_enSwitchRrR,			/**< Identificador del estado del sensor inductivo S-RrR-1 */
	RUNDIAG_TEST_enCouplingF,			/**< Identificador del estado del sensor de acoplamiento z1-Fr*/
	RUNDIAG_TEST_enCouplingR,			/**< Identificador del estado del sensor de acoplamiento z1-Rr*/
	RUNDIAG_TEST_enFrontRightSwitch,	/**< Identificador de sensor limit switch frontal derecho */
	RUNDIAG_TEST_enFrontLeftSwitch,			/**< Identificador de sensor limit switch frontal izquierdo */
	RUNDIAG_TEST_enRearRightSwitch,			/**< Identificador de sensor limit switch trasero derecho */
	RUNDIAG_TEST_enRearLeftSwitch,			/**< Identificador de sensor limit switch trasero izquierdo */
	RUNDIAG_TEST_enenRightNamurSensor,			/**< Identificador del sensor de la puerta derecha*/
	RUNDIAG_TEST_enLeftNamurSensor,			/**< Identificador del sensor de la puerta izquierda */
	RUNDIAG_TEST_enFrontRightWheel,			/**< Identificador de rueda frontal derecha */
	RUNDIAG_TEST_enFrontLeftWheel,			/**< Identificador de rueda frontal izquierda */
	RUNDIAG_TEST_enRearRightWheel,			/**< Identificador de rueda trasera derecha */
	RUNDIAG_TEST_enRearLeftWheel,			/**< Identificador de rueda trasera izquierda */
	RUNDIAG_TEST_enTotalSignals  			/**< N�mero total de se�ales de diagn�stico de sensores */
}RUNDIAG_TEST_Signals;

/*Estructura que se utiliza para almacenar la velocidad registrada en cada rueda.*/
typedef struct
{
	uint32 u32MsgId;
	uint32 u32TotalSignalsStates;
	uint32 u32SignalsStateSize;
	uint32 au32MsgBuff[RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg];
}RUNDIAG_TEST_s_tstProcessMsg;

/* private__variables */
static uint8 RUNDIAG_TEST_s_u8TestCount = (uint8)0U;
static uint8 *RUNDIAG_TEST_s_pau8FailureCount = NULL;
static uint8 *RUNDIAG_TEST_s_pau8FailureCount_Mirror = NULL;
static void **RUNDIAG_TEST_s_pvProcessMsgAddress = NULL;
static void **RUNDIAG_TEST_s_pvProcessMsgAddress_Mirror = NULL;
static uint32* RUNDIAG_TEST_s_pau32DiagWheel= NULL;
static uint32* RUNDIAG_TEST_s_pau32DiagWheel_Mirror = NULL;
static sint32* RUNDIAG_TEST_s_ps32RlyDiagStatus = NULL;
static sint32* RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = NULL;
static DIGIFILTER_tstFilterProperties* RUANDIAG_TEST_s_pastProperties = NULL;
static DIGIFILTER_tstFilterProperties* RUANDIAG_TEST_s_pastPropCompl = NULL;
static ANALOGCFG_tstSignalConversion* RUNDIAG_TEST_s_pastConverId = NULL;
static ANALOGCFG_tstSignalConversion* RUNDIAG_TEST_s_pastConverIdCmpl = NULL;
static ANALOGCFG_tstSignalLocation* RUNDIAG_TEST_s_pastLocationId = NULL;
static ANALOGCFG_tstSignalLocation* RUNDIAG_TEST_s_pastLocationIdCmpl = NULL;
static ANALOG_tstAnalogTable* RUNDIAG_TEST_s_pastTable = NULL;
static ANALOG_tstAnalogTable* RUNDIAG_TEST_s_pastTableComp = NULL;
static ANALOG_tstADC1Signals* RUNDIAG_TEST_s_stADC1Capture = NULL;
static ANALOG_tstADC1Signals*RUNDIAG_TEST_s_stADC1Comp = NULL;
static uint32* RUNDIAG_TEST_s_pau32BreakFlags = NULL;
static uint32* RUNDIAG_TEST_s_pau32BreakFlags_Mirror = NULL;

/* private__functions */
/**
 * @def  RUNDIAG_TEST_s_vGetAddress
 * @brief Se encarga de obtener las direcciones de memoria de variables est�ticas relevantes para los ensayos.
 * @note
 */
static void RUNDIAG_TEST_s_vGetAddress(void)
{
	RUNDIAG_TEST_s_pau8FailureCount = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pau8FailureCount_Mirror = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pvProcessMsgAddress = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pvProcessMsgAddress_Mirror = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pau32DiagWheel = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pau32DiagWheel_Mirror = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_ps32RlyDiagStatus = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = TESTINFO_pvGetAddress();
	RUANDIAG_TEST_s_pastProperties = TESTINFO_pvGetAddress();
	RUANDIAG_TEST_s_pastPropCompl = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastConverId = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastConverIdCmpl = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastLocationId = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastLocationIdCmpl = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastTable = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pastTableComp = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_stADC1Capture = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_stADC1Comp = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pau32BreakFlags = TESTINFO_pvGetAddress();
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror = TESTINFO_pvGetAddress();
}

/**
 * @def  RUNDIAG_TEST_vSetState
 * @brief Se encarga de asignar un estado a un pin correspondiente al puerto asignado.
 * @note
 */
void RUNDIAG_TEST_vSetState(uint16 u16Port, uint8 u8PinNbr, uint8 u8State)
{
	GPIO_tstGioPort* pstPort;
	uint8 u8NewState = 0U;

	u8NewState = (uint8)_bool_(u8State);
	pstPort = (GPIO_tstGioPort*)GPIO_nGIOPORTNHET1_ADDR_cfg;

	if(u8NewState == (uint8)STD_LOW)
	{
		pstPort ->DIN &= (uint32)~((uint32)1U << u8PinNbr);
	}
	else
	{
		pstPort ->DIN |= (uint32)((uint32)u8State << u8PinNbr);
	}
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_01                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS10127
* @Description:
*      			Se comprueba que la interfaz termina la ejecuci�n del programa con c�digo de error
*      			E_CORRUPT_DATA, si se detecta corrupci�n de datos en la memoria est�tica del componente.
*
*				RUNDIAG_TEST_s_pau8FailureCount = (uint8)TESTINFO_nZERO;
*				RUNDIAG_TEST_s_pau8FailureCount_Mirror = (uint8)RUNDIAG_TEST_s_pau8FailureCount
*
* @Pre: 
* @Notes:
*         NA
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
static void SINT_MAP010_BBT_ECP_IAP032_01_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);;

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_02                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS10127
* @Description:
*      			Se comprueba que la interfaz termina la ejecuci�n del programa con c�digo de error
*      			E_CORRUPT_DATA, si se detecta corrupci�n de datos en la memoria est�tica del componente.
*
*				RUNDIAG_TEST_s_pvProcessMsgAddress = (uint8)TESTINFO_nZERO;
*				RUNDIAG_TEST_s_pvProcessMsgAddress_Mirror = (uint8)RUNDIAG_TEST_s_pau8FailureCount
*
* @Pre:
* @Notes:
*         NA
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
static void SINT_MAP010_BBT_ECP_IAP032_02_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_return_if_deactivated(u8RunTest);

	uint16 u16i = 0U;

	*RUNDIAG_TEST_s_pvProcessMsgAddress = (void *)&u16i;
	*RUNDIAG_TEST_s_pvProcessMsgAddress_Mirror = *RUNDIAG_TEST_s_pvProcessMsgAddress;

}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_03                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605, SS9606, SS9607, SS9867, SS10828.b, SS10128.c, SS10196, SS10466.
* @Description:
*      			Se comprueba que la interfaz:
*      				- Obtiene "E_OK", en el estado de diagn�stico del rel� de reseteo remoto.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera derecha.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal izquierdo.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero derecho.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo de acoplamiento frontal.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo de acoplamiento trasero.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero izquierdo.
*       			- Obtiene "STD_LOW, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha.
*      				- Obtiene "STD_HIGH, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
*      				- Establece en cero el contador de fallas en la se�al de diagn�stico.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico.
*      			Cuando:
*      				- No existen fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- No existen fallas en las se�ales de diagn�sticos.
*
*
* @Pre:
* @Notes:
*         		1. Configurar las tablas RUNDIAG_POINT_TO_0PINTRFZ_cfg y RUNDIAG_POINT_TO_1PINTRFZ_cfg, respecto
*         		   a la descripci�n que menciona para cada tabla en el archivo MAP010_RUNDIAG_cfg.h, para obtener
*         		   los diagn�sticos de los sensores.
*
*         		2. Se�ales de diagn�stico que activan el freno de emergencia, cuando se tienen 2 o m�s fallas:
*         		- Se�al de diagn�stico del rel� de reseteo remoto.
*         		- Se�ales de diagn�stico del sensor NAMUR de las puertas derechas/izquierdas.
*         		- Se�ales de diagn�stico del sensor de factor de calibraci�n de las llantas.
*
*
*
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
static void SINT_MAP010_BBT_ECP_IAP032_03_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_03_SET);
	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Se inicializa en cero las banderas del freno de emergencia del CHV*/
	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	*RUNDIAG_TEST_s_ps32RlyDiagStatus = E_OK;
	*RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = (sint32)~(*RUNDIAG_TEST_s_ps32RlyDiagStatus);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel];


	/*Se establece el estado de diagn�stico de la rueda trasera izquierda*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)0, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda rueda trasera derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nANALOG_HIGH_MIN_CURRENT_cfg, DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel];

	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)28, (uint8)STD_HIGH);

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)24, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)20, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_1900;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)16, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)29, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)14, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)27, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de las se�ales de diagn�stico de los sensores de calibraci�n delas ruedas frontales y traseras*/
	uint8 u8Wheel = (uint16)0U;

	for(u8Wheel = 0U; u8Wheel < (uint16)CALIBDIAM_enTotalWheels; u8Wheel++)
	{
		RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel] = (uint32)E_OK;
		RUNDIAG_TEST_s_pau32DiagWheel_Mirror[u8Wheel] = ~(uint32)RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel];
	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_03_CTRL;
}

static void SINT_MAP010_BBT_ECP_IAP032_03(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_03_CTRL(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_03_CTRL);
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32TestResult = (uint32)TRUE;

	MSGQUEUE_tstMsgSelectBoth stMsgSelectBoth = {(uint32)RUNDIAG_PROT_PID_cfg, RUNDIAG_PROCESS_MSG_ID_cfg, 0U};

	void* pvAuxiliarProMsg = (void*)NULL;

	pvAuxiliarProMsg = MSGQUEUE_pvRxMsg((uint32)MSGQUEUE_nNO_TMO,(void**)&stMsgSelectBoth ,(uint32)MSGQUEUE_nMSGRX_BOTH);

	RUNDIAG_TEST_s_tstProcessMsg* pstProcessMsg = (RUNDIAG_TEST_s_tstProcessMsg*)pvAuxiliarProMsg;

	pstProcessMsg->u32SignalsStateSize = sizeof(uint32);
	pstProcessMsg->u32TotalSignalsStates = (uint32)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg;

	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRlyDiag] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrL] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrL] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrR] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingF] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enenRightNamurSensor] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;

	uint16 u16SignalIndex = 0U;

	for(u16SignalIndex = 0U; u16SignalIndex < (uint16)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u16SignalIndex++)
	{
		u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[u16SignalIndex]  == (uint8)TESTINFO_nZERO) ? u32TestResult : (uint8)FALSE;
		u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount_Mirror[u16SignalIndex]  == (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u16SignalIndex]) ? u32TestResult : (uint8)FALSE;
	}

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	MSGQUEUE_vTxMsg((void**)&pvAuxiliarProMsg, (uint32)RUNDIAG_PROT_PID_cfg);

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_05_SET;

}


void SINT_MAP010_BBT_ECP_IAP032_01_DUMMY(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_02_DUMMY(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_03_DUMMY(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_04_DUMMY(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_04                             	  *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605, SS9606, SS9607, SS9867, SS10128.a, SS10196, SS10465.
* @Description:
*      			Se comprueba que la interfaz:
*      				- Obtiene "E_NOT_OK", en el estado de diagn�stico del rel� de reseteo remoto.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico de la rueda frontal izquierda.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico de la rueda frontal derecha.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico de la rueda trasera izquierda.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico de la rueda trasera derecha.
*       			- Obtiene "E_OPEN_LOAD", en el estado del sensor inductivo frontal izquierdo.
*       			- Obtiene "E_OPEN_LOAD", en el estado del sensor inductivo frontal derecho.
*       			- Obtiene "E_OPEN_LOAD", en el estado del sensor inductivo trasero izquierdo.
*       			- Obtiene "E_OPEN_LOAD", en el estado del sensor inductivo trasero derecho.
*       			- Obtiene "E_NOT_OK", en el estado del sensor inductivo de acoplamiento frontal.
*       			- Obtiene "E_NOT_OK", en el estado del sensor inductivo de acoplamiento trasero.
*       			- Obtiene "E_NOT_OK", en el estado del sensor limit switch frontal derecho.
*       			- Obtiene "E_NOT_OK", en el estado del sensor limit switch frontal izquierdo.
*       			- Obtiene "E_NOT_OK", en el estado del sensor limit switch trasero derecho.
*       			- Obtiene "E_NOT_OK", en el estado del sensor limit switch trasero izquierdo.
*       			- Obtiene "E_NOT_OK, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha.
*      				- Obtiene "E_NOT_OK, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Obtiene "E_OUT_OF_RANGE", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_OUT_OF_RANGE", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_OUT_OF_RANGE", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_OUT_OF_RANGE", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
*      				- Aumenta el contador de fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico.
*      				- Activa la bandera de frenado de emergencia correspondiente a la funci�n de seguridad P10.

*      			Cuando:
*      				- Existen m�s de dos fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- Existen fallas en las se�ales de diagn�sticos.
* @Pre:
* @Notes:
*
* 				1. Configurar las tablas RUNDIAG_POINT_TO_0PINTRFZ_cfg y RUNDIAG_POINT_TO_1PINTRFZ_cfg, respecto
*         		   a la descripci�n que menciona para cada tabla en el archivo MAP010_RUNDIAG_cfg.h, para obtener
*         		   los diagn�sticos de los sensores.
*
*         		2. Se�ales de diagn�stico que activan el freno de emergencia, cuando se tienen 2 o m�s fallas:
*         		- Se�al de diagn�stico del rel� de reseteo remoto.
*         		- Se�ales de diagn�stico del sensor NAMUR de las puertas derechas/izquierdas.
*         		- Se�ales de diagn�stico del sensor de factor de calibraci�n de las llantas.
*
*         NA
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
static void SINT_MAP010_BBT_ECP_IAP032_04_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_04_SET);
	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Se inicializa en cero las banderas del freno de emergencia del CHV*/
	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	*RUNDIAG_TEST_s_ps32RlyDiagStatus = E_NOT_OK;
	*RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = (sint32)~(*RUNDIAG_TEST_s_ps32RlyDiagStatus);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda trasera izquierda*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)0, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda rueda trasera derecha*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)28, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nANALOG_HIGH_MIN_CURRENT_cfg, DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel];

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel];


	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)24, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)TESTINFO_nZERO;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)20, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)TESTINFO_nZERO;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)TESTINFO_nZERO;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)29, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero derecho*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)27, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_HIGH_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_HIGH_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de las se�ales de diagn�stico de los sensores de calibraci�n delas ruedas frontales y traseras*/
	uint8 u8Wheel = (uint16)0U;

	for(u8Wheel = 0U; u8Wheel < (uint16)CALIBDIAM_enTotalWheels; u8Wheel++)
	{
		RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel] = (uint32)E_OUT_OF_RANGE;
		RUNDIAG_TEST_s_pau32DiagWheel_Mirror[u8Wheel] = ~(uint32)RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel];
	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_04_CTRL;
}

static void SINT_MAP010_BBT_ECP_IAP032_04(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_04_CTRL(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_04_CTRL);
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32TestResult = (uint32)TRUE;

	uint32 u32BrkFlags = (uint32)TESTINFO_nZERO;

	MSGQUEUE_tstMsgSelectBoth stMsgSelectBoth = {(uint32)RUNDIAG_PROT_PID_cfg, RUNDIAG_PROCESS_MSG_ID_cfg, 0U};

	void* pvAuxiliarProMsg = (void*)NULL;

	pvAuxiliarProMsg = MSGQUEUE_pvRxMsg((uint32)MSGQUEUE_nNO_TMO,(void**)&stMsgSelectBoth ,(uint32)MSGQUEUE_nMSGRX_BOTH);

	RUNDIAG_TEST_s_tstProcessMsg* pstProcessMsg = (RUNDIAG_TEST_s_tstProcessMsg*)pvAuxiliarProMsg;

	pstProcessMsg->u32SignalsStateSize = sizeof(uint32);
	pstProcessMsg->u32TotalSignalsStates = (uint32)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg;

	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRlyDiag] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontLeft] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontRight] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearLeft] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearRight] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrL] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrR] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrL] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrR] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingF] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingR] == (uint32)E_OPEN_LOAD) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightSwitch] == (uint8)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftSwitch] == (uint8)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightSwitch] == (uint8)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftSwitch] == (uint8)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enenRightNamurSensor] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightWheel] == (uint32)E_OUT_OF_RANGE) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftWheel] == (uint32)E_OUT_OF_RANGE) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightWheel] == (uint32)E_OUT_OF_RANGE) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftWheel] == (uint32)E_OUT_OF_RANGE) ? u32TestResult : (uint8)FALSE;

	u32BrkFlags = BRKFLAGS_u32GetFlags(BRKFLAGS_enCHV);
	u32TestResult = (u32BrkFlags == (uint32)RUNDIAG_TEST_s_nP10Flag) ? u32TestResult : (uint8)FALSE;

	u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enRlyDiag] == (uint32)TESTINFO_nZERO_RIGHT) ? u32TestResult : (uint8)FALSE;

	uint8 u8SignalIndex = (uint8)0U;
	for(u8SignalIndex = (uint8)RUNDIAG_TEST_enenRightNamurSensor; u8SignalIndex < RUNDIAG_TEST_enTotalSignals; u8SignalIndex++)
	{
		u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[u8SignalIndex] == (uint32)TESTINFO_nZERO_RIGHT) ? u32TestResult : (uint8)FALSE;
	}

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_07_SET;
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_05                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605,SS9606, SS9607, SS9867, SS10128, SS10196, SS10465, SS10466.
* @Description:
*      			Se comprueba que la interfaz:
*      				- Obtiene "E_NOT_OK", en el estado de diagn�stico del rel� de reseteo remoto.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera derecha.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal izquierdo.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero derecho.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo de acoplamiento frontal.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo de acoplamiento trasero.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
*      				- Establece en cero el contador de fallas en la se�al de diagn�stico que activan el freno de emergencia y no presentan fallas.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico que no presentan fallas.
*      				- Aumenta el contador de fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico.
*      				- Activa la bandera de frenado de emergencia correspondiente a la funci�n de seguridad P10.
*      			Cuando:
*      				- Existen dos fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- Existen fallas en las se�ales de diagn�sticos.
*
*
* @Pre:
* @Notes:
*         		1. Configurar las tablas RUNDIAG_POINT_TO_0PINTRFZ_cfg y RUNDIAG_POINT_TO_1PINTRFZ_cfg, respecto
*         		   a la descripci�n que menciona para cada tabla en el archivo MAP010_RUNDIAG_cfg.h, para revisar
*         		   que los diagn�sticos de los sensores arrojan un estado de buen funcionamiento.
*
*         		2. Se�ales de diagn�stico que activan el freno de emergencia, cuando se tienen 2 o m�s fallas:
*         		- Se�al de diagn�stico del rel� de reseteo remoto.
*         		- Se�ales de diagn�stico del sensor NAMUR de las puertas derechas/izquierdas.
*         		- Se�ales de diagn�stico del sensor de factor de calibraci�n de las llantas.
*
*
*
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static void SINT_MAP010_BBT_ECP_IAP032_05_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{

	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_05_SET);
	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Se inicializa en cero las banderas del freno de emergencia del CHV*/
	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	*RUNDIAG_TEST_s_ps32RlyDiagStatus = E_NOT_OK;
	*RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = (sint32)~(*RUNDIAG_TEST_s_ps32RlyDiagStatus);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel];


	/*Se establece el estado de diagn�stico de la rueda trasera izquierda*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)0, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda rueda trasera derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nANALOG_HIGH_MIN_CURRENT_cfg, DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel];

	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)28, (uint8)STD_HIGH);

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)24, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)20, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_1900;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)16, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)29, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)14, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)27, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_HIGH_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de las se�ales de diagn�stico de los sensores de calibraci�n delas ruedas frontales y traseras*/
	uint8 u8Wheel = (uint16)0U;

	for(u8Wheel = 0U; u8Wheel < (uint16)CALIBDIAM_enTotalWheels; u8Wheel++)
	{
		RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel] = (uint32)E_OK;
		RUNDIAG_TEST_s_pau32DiagWheel_Mirror[u8Wheel] = ~(uint32)RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel];
	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_05_CTRL;
}

static void SINT_MAP010_BBT_ECP_IAP032_05(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_05_CTRL(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_05_CTRL);
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32TestResult = (uint32)TRUE;

	MSGQUEUE_tstMsgSelectBoth stMsgSelectBoth = {(uint32)RUNDIAG_PROT_PID_cfg, RUNDIAG_PROCESS_MSG_ID_cfg, 0U};

	void* pvAuxiliarProMsg = (void*)NULL;

	pvAuxiliarProMsg = MSGQUEUE_pvRxMsg((uint32)MSGQUEUE_nNO_TMO,(void**)&stMsgSelectBoth ,(uint32)MSGQUEUE_nMSGRX_BOTH);

	RUNDIAG_TEST_s_tstProcessMsg* pstProcessMsg = (RUNDIAG_TEST_s_tstProcessMsg*)pvAuxiliarProMsg;

	pstProcessMsg->u32SignalsStateSize = sizeof(uint32);
	pstProcessMsg->u32TotalSignalsStates = (uint32)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg;

	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRlyDiag] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrL] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrL] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrR] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingF] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enenRightNamurSensor] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;

	uint32 u32BrkFlags = (uint32)TESTINFO_nZERO;

	u32BrkFlags = BRKFLAGS_u32GetFlags(BRKFLAGS_enCHV);
	u32TestResult = (u32BrkFlags == (uint32)RUNDIAG_TEST_s_nP10Flag) ? u32TestResult : (uint8)FALSE;

	u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enRlyDiag] == (uint32)TESTINFO_nZERO_RIGHT) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)TESTINFO_nZERO_RIGHT) ? u32TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	MSGQUEUE_vTxMsg((void**)&pvAuxiliarProMsg, (uint32)RUNDIAG_PROT_PID_cfg);

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_06_SET;
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_06                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605, SS9606, SS9607, SS9867, SS10128, SS10196, SS10466.
* @Description:
*      			Se comprueba que la interfaz:
*      				- Obtiene "E_OK", en el estado de diagn�stico del rel� de reseteo remoto.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda trasera derecha.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal izquierdo.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero derecho.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo de acoplamiento frontal.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo de acoplamiento trasero.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
*      				- Establece en cero el contador de fallas en la se�al de diagn�stico.
*      				- Aumenta el contador de fallas en la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico.
*					- No activa la bandera de frenado de emergencia correspondiente a la funci�n de seguridad P10.
*      			Cuando:
*      				- Existe una falla en las se�ales de diagn�stico que activan el freno de emergencia..
*      				- No existen fallas en las se�ales de diagn�stico que no activan el freno de emergencia.
*
*
* @Pre:
* @Notes:
*         		1. Configurar las tablas RUNDIAG_POINT_TO_0PINTRFZ_cfg y RUNDIAG_POINT_TO_1PINTRFZ_cfg, respecto
*         		   a la descripci�n que menciona para cada tabla en el archivo MAP010_RUNDIAG_cfg.h, para revisar
*         		   que los diagn�sticos de los sensores arrojan un estado de buen funcionamiento.
*
*         		2. Se�ales de diagn�stico que activan el freno de emergencia, cuando se tienen 2 o m�s fallas:
*         		- Se�al de diagn�stico del rel� de reseteo remoto.
*         		- Se�ales de diagn�stico del sensor NAMUR de las puertas derechas/izquierdas.
*         		- Se�ales de diagn�stico del sensor de factor de calibraci�n de las llantas.
*
*
*
*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static void SINT_MAP010_BBT_ECP_IAP032_06_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_06_SET);
	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Se inicializa en cero las banderas del freno de emergencia del CHV*/
	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	*RUNDIAG_TEST_s_ps32RlyDiagStatus = E_OK;
	*RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = (sint32)~(*RUNDIAG_TEST_s_ps32RlyDiagStatus);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda trasera izquierda*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)0, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda rueda trasera derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nANALOG_HIGH_MIN_CURRENT_cfg, DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel];

	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)28, (uint8)STD_HIGH);

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)24, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)20, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_1900;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)16, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)29, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)14, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)27, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_HIGH_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de las se�ales de diagn�stico de los sensores de calibraci�n delas ruedas frontales y traseras*/
	uint8 u8Wheel = (uint16)0U;

	for(u8Wheel = 0U; u8Wheel < (uint16)CALIBDIAM_enTotalWheels; u8Wheel++)
	{
		RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel] = (uint32)E_OK;
		RUNDIAG_TEST_s_pau32DiagWheel_Mirror[u8Wheel] = ~(uint32)RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel];
	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_06_CTRL;
}

static void SINT_MAP010_BBT_ECP_IAP032_06(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_06_CTRL(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_06_CTRL);
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32TestResult = (uint32)TRUE;

	MSGQUEUE_tstMsgSelectBoth stMsgSelectBoth = {(uint32)RUNDIAG_PROT_PID_cfg, RUNDIAG_PROCESS_MSG_ID_cfg, 0U};

	void* pvAuxiliarProMsg = (void*)NULL;

	pvAuxiliarProMsg = MSGQUEUE_pvRxMsg((uint32)MSGQUEUE_nNO_TMO,(void**)&stMsgSelectBoth ,(uint32)MSGQUEUE_nMSGRX_BOTH);

	RUNDIAG_TEST_s_tstProcessMsg* pstProcessMsg = (RUNDIAG_TEST_s_tstProcessMsg*)pvAuxiliarProMsg;

	pstProcessMsg->u32SignalsStateSize = sizeof(uint32);
	pstProcessMsg->u32TotalSignalsStates = (uint32)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg;

	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRlyDiag] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelRearRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrL] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrL] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrR] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingF] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enenRightNamurSensor] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)E_NOT_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;

	uint32 u32BrkFlags = (uint32)TESTINFO_nZERO;

	u32BrkFlags = BRKFLAGS_u32GetFlags(BRKFLAGS_enCHV);
	u32TestResult = (u32BrkFlags == (uint32)STD_INACTIVE) ? u32TestResult : (uint8)FALSE;

	u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)TESTINFO_nZERO_RIGHT) ? u32TestResult : (uint8)FALSE;

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	MSGQUEUE_vTxMsg((void**)&pvAuxiliarProMsg, (uint32)RUNDIAG_PROT_PID_cfg);

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}
	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_04_SET;
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_07                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605, SS9606, SS9607, SS9616, SS9867, SS10828.b, SS10128.c, SS10196, SS10466.
* @Description:
*      			Se comprueba que la interfaz:
*      				- Obtiene "E_OK", en el estado de diagn�stico del rel� de reseteo remoto.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico de la rueda frontal derecha.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal izquierdo.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo trasero derecho.
*       			- Obtiene "STD_HIGH", en el estado del sensor inductivo de acoplamiento frontal.
*       			- Obtiene "STD_LOW", en el estado del sensor inductivo de acoplamiento trasero.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch frontal izquierdo.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero derecho.
*       			- Obtiene "STD_LOW", en el estado del sensor limit switch trasero izquierdo.
*       			- Obtiene "STD_LOW, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha.
*      				- Obtiene "STD_HIGH, en el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
*      				- Establece en cero el contador de fallas en la se�al de diagn�stico.
*      				- Actualiza el mirror de contador de fallas de las se�ales de diagn�stico.
*      				- Recupera la propiedad del mensaje de diagn�stico.
*      			Cuando:
*      				- No existen fallas en las se�ales de diagn�stico que activan el freno de emergencia.
*      				- No existen fallas en las se�ales de diagn�sticos.
*      				- El proceso de control no haya devuelto la propiedad del mensaje de diagnostico.
*
*
* @Pre:
* @Notes:
*         		1. Configurar las tablas RUNDIAG_POINT_TO_0PINTRFZ_cfg y RUNDIAG_POINT_TO_1PINTRFZ_cfg, respecto
*         		   a la descripci�n que menciona para cada tabla en el archivo MAP010_RUNDIAG_cfg.h, para obtener
*         		   los diagn�sticos de los sensores.
*
*         		2. Se�ales de diagn�stico que activan el freno de emergencia, cuando se tienen 2 o m�s fallas:
*         		- Se�al de diagn�stico del rel� de reseteo remoto.
*         		- Se�ales de diagn�stico del sensor NAMUR de las puertas derechas/izquierdas.
*         		- Se�ales de diagn�stico del sensor de factor de calibraci�n de las llantas.
*
*         		3. Para comprobar que se recupera la propiedad del mensaje de diagnostico, usando la interfaz "MsgAcquire"
*         		   del componente MSGQUEUE, en el proceso de control, correspondiente al ensayo SINT_MAP010_BBT_ECP_IAP032_04_CTRL,
*         		   no se regres� la propiedad del mensaje de diagnostico.
*
*

*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
 *                   Input Vector                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/
static void SINT_MAP010_BBT_ECP_IAP032_07_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_07_SET);
	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Se inicializa en cero las banderas del freno de emergencia del CHV*/
	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	*RUNDIAG_TEST_s_ps32RlyDiagStatus = E_OK;
	*RUNDIAG_TEST_s_ps32RlyDiagStatus_Mirror = (sint32)~(*RUNDIAG_TEST_s_ps32RlyDiagStatus);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FL_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FL_SENS_PWR_VS].u8Channel];

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_A_cfg].u32PrevState;

	RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)TESTINFO_middle_value_of_range(DIAGENC_nCONDITIONING_OK_LOWER_LIMIT_cfg, DIAGENC_nCONDITIONING_OK_UPPER_LIMIT_cfg);
	RUANDIAG_TEST_s_pastPropCompl[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState = (uint32)~RUANDIAG_TEST_s_pastProperties[DIAGENC_FR_SIGNALCOND_B_cfg].u32PrevState;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_LOW_LOWER_FRONT_VOLT_cfg, DIAGENC_nHSD_LOW_UPPER_FRONT_VOLT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_FR_SENS_PWR_VS].u8Channel];

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)30, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)4, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)24, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)20, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)RUNDIAG_TEST_s_nRAWVAL_1900;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)16, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)29, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero derecho*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)14, (uint8)STD_LOW);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	RUNDIAG_TEST_vSetState((uint16)GPIO_enPORTNHET1, (uint8)27, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_2300;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel];

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	RUNDIAG_TEST_s_pastTableComp[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)~RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel];

	/*Se establece el estado de las se�ales de diagn�stico de los sensores de calibraci�n delas ruedas frontales y traseras*/
	uint8 u8Wheel = (uint16)0U;

	for(u8Wheel = 0U; u8Wheel < (uint16)CALIBDIAM_enTotalWheels; u8Wheel++)
	{
		RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel] = (uint32)E_OK;
		RUNDIAG_TEST_s_pau32DiagWheel_Mirror[u8Wheel] = ~(uint32)RUNDIAG_TEST_s_pau32DiagWheel[u8Wheel];
	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enECP_IAP032_07_CTRL;
}

static void SINT_MAP010_BBT_ECP_IAP032_07(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

}

void SINT_MAP010_BBT_ECP_IAP032_07_CTRL(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	RUNDIAG_s_check_id(RUNDIAG_enECP_IAP032_07_CTRL);
	TESTINFO_check_if_test_is_enabled(u16Component,u8RunTest,u16TestType);

	uint32 u32TestResult = (uint32)TRUE;

	MSGQUEUE_tstMsgSelectBoth stMsgSelectBoth = {(uint32)RUNDIAG_PROT_PID_cfg, RUNDIAG_PROCESS_MSG_ID_cfg, 0U};

	void* pvAuxiliarProMsg = (void*)NULL;

	pvAuxiliarProMsg = MSGQUEUE_pvRxMsg((uint32)MSGQUEUE_nNO_TMO,(void**)&stMsgSelectBoth ,(uint32)MSGQUEUE_nMSGRX_BOTH);

	RUNDIAG_TEST_s_tstProcessMsg* pstProcessMsg = (RUNDIAG_TEST_s_tstProcessMsg*)pvAuxiliarProMsg;

	pstProcessMsg->u32SignalsStateSize = sizeof(uint32);
	pstProcessMsg->u32TotalSignalsStates = (uint32)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg;

	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRlyDiag] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontLeft] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enWheelFrontRight] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrL] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchFrR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrL] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enSwitchRrR] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingF] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enCouplingR] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightSwitch] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftSwitch] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enenRightNamurSensor] == (uint32)STD_LOW) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enLeftNamurSensor] == (uint32)STD_HIGH) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enFrontLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearRightWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;
	u32TestResult = (pstProcessMsg->au32MsgBuff[RUNDIAG_TEST_enRearLeftWheel] == (uint32)E_OK) ? u32TestResult : (uint8)FALSE;

	uint16 u16SignalIndex = 0U;

	for(u16SignalIndex = 0U; u16SignalIndex < (uint16)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u16SignalIndex++)
	{
		u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount[u16SignalIndex]  == (uint8)TESTINFO_nZERO) ? u32TestResult : (uint8)FALSE;
		u32TestResult = (RUNDIAG_TEST_s_pau8FailureCount_Mirror[u16SignalIndex]  == (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u16SignalIndex]) ? u32TestResult : (uint8)FALSE;
	}

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	MSGQUEUE_vTxMsg((void**)&pvAuxiliarProMsg, (uint32)RUNDIAG_PROT_PID_cfg);

	uint8 u8i = 0U;

	for(u8i = 0U; u8i < (uint8)RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCount_Mirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];

	}

	/*The following code is used to synchronize the test call sequence. It is only used in the TestDriver.*/
	RUNDIAG_TEST_s_u8TestCount = (uint8)RUNDIAG_enTotalMRBTestId;

}

/* public_functions */
void SINT_MAP010(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);
}

void SINT_MAP010_SET(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	RUNDIAG_TEST_s_vGetAddress();

	/*ASSERT HARD ERROR*/
	SINT_MAP010_BBT_ECP_IAP032_01_SET(u16Component, (uint8)STD_DISABLE, (uint16)TESTINFO_enManual); /*Se espera llamada a Hard Error E_CORRUPT_DATA*/
	SINT_MAP010_BBT_ECP_IAP032_02_SET(u16Component, (uint8)STD_DISABLE, (uint16)TESTINFO_enManual); /*Se espera llamada a Hard Error E_CORRUPT_DATA*/
	SINT_MAP010_BBT_ECP_IAP032_03_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_04_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_05_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_06_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_07_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
}

void SINT_MAP010_CHK(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	SINT_MAP010_BBT_ECP_IAP032_03(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_04(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_05(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_06(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_07(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);

}

void SINT_MAP010_CTRL(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);
	RUNDIAG_TEST_s_vGetAddress();

	SINT_MAP010_BBT_ECP_IAP032_01_DUMMY(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_02_DUMMY(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_03_DUMMY(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_04_DUMMY(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);

	SINT_MAP010_BBT_ECP_IAP032_03_CTRL(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_04_CTRL(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_05_CTRL(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_06_CTRL(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	SINT_MAP010_BBT_ECP_IAP032_07_CTRL(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);

}

/* EOF */
