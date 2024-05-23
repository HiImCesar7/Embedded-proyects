

/* system headers */
#include "Std_Types.h"
#include "_assert_.h"
/* used headers */

/*TestInfo*/
#include "TestInfo.h"
#include "TestInfo_def.h"
/*MAP010_RUNDIAG*/
#include "MAP010_RUNDIAG_cfg.h"
#include "MAP010_RUNDIAG_def.h"
#include "MAP010_RUNDIAG.h"
/*MMW039_RUNDIAG*/
#include "MMW039_DATACOMP_def.h"
#include "MMW039_DATACOMP.h"
/*MSF026_BRKFLAGS*/
#include "MSF026_BRKFLAGS.h"
#include "MSF026_BRKFLAGS_def.h"
/*MSGQUEUE*/
#include "MSGQUEUE_def.h"
#include "MSGQUEUE.h"
/*MBS006_CANDICT*/
#include "MBS006_CANDICT_def.h"
/*MTL003_SMCTRL*/
#include "MTL003_SMCTRL_def.h"
#include "MTL003_SMCTRL.h"
/*SHMEM*/
#include "SHMEM_def.h"
#include "SHMEM.h"
/*MSF069_RESETODO*/
#include "MSF069_RESETODO_def.h"
/*MMD023_DIAGENC*/
#include "MMD023_DIAGENC_cfg.h"
/*ANALOG*/
#include "ANALOG_def.h"
/*ANALOG_ISR*/
#include "ANALOG_ISR_def.h"
#include "ANALOG_ISR_cfg.h"
/*MMD034_DIAGSWITCH*/
#include "MMD034_DIAGSWITCH_cfg.h"
/*MMD021_DOORSENS*/
#include "MMD021_DOORSENS_cfg.h"
/*ANALOGCF*/
#include "ANALOGCFG.h"
#include "ANALOGCFG_def.h"
#include "ANALOGCFG_cfg.h"
/*ANALOG*/
#include "ANALOG.h"
/*CRC_LUT*/
#include "CRC_LUT.h"
/*DIGIFILTER*/
#include "DIGIFILTER.h"
/*MMD022_DIOMUX*/
#include "MMD022_DIOMUX.h"
/*ADC_*/
#include "ADC__def.h"
/*MSF069_RESETODO*/
#include "MSF069_RESETODO_cfg.h"
#include "MSF069_RESETODO_def.h"
#include "MSF069_RESETODO.h"

/* own headers */
#include "HSITS_Vectors_MAP010_RUNDIAG_CHV-Ch-P.h"
/*[EXPORTED]****************************************************************************/
/* public_variables */
/*[INTERNAL]****************************************************************************/
/* internal__pre-processor macros */

/**
 * @def  RUNDIAG_TEST_nCAN_MSG_ID_cfg
 * @brief Constante utilizada para definir el ID del mensaje de CAN.
 * @note
 */
#define RUNDIAG_TEST_nCAN_MSG_ID_cfg (0xEE1103)

/**
 * @def MSGDICT_nCAN_ROLLCNTR_MAX
 * @brief  Valor m�ximo para el rolling counter de mensajes de CAN
 **/
#define MSGDICT_nCAN_ROLLCNTR_MAX	(15U)

/**
 * @def  SERVMAP_nBRANCH_MIN_LEN
 * @brief Constante con el valor de la longitud m�nima de una rama en cm.
 * @note
 */
#define SERVMAP_nBRANCH_MIN_LEN (20)

/**
 * @def  SERVMAP_nBRANCH_MAX_LEN
 * @brief Constante con el valor de la longitud m�xima de una rama en cm.
 * @note
 */
#define SERVMAP_nBRANCH_MAX_LEN (102400)


/**
 * @def  SERVMAP_nLEFT_BRANCH_MIN_VAL
 * @brief Constante con el valor m�nimo para el ID de una rama izquierda.
 * @note
 */
#define SERVMAP_nLEFT_BRANCH_MIN_VAL (0x1000)

/**
 * @def  SERVMAP_nLEFT_BRANCH_MAX_VAL
 * @brief Constante con el valor m�ximo para el ID de una rama izquierda.
 * @note
 */
#define SERVMAP_nLEFT_BRANCH_MAX_VAL (0x1FFF)

/**
 * @def  RUNDIAG_TEST_s_nMASK_LSB
 * @brief Constante utilizada como m�scara para obtener los 2 bytes menos significativos del valor de la longitud de rama en riel izquierdo y derecho.
 * @note
 */
#define RUNDIAG_TEST_s_nMASK_LSB (0x0000FFFF)


/**
 * @def  RUNDIAG_TEST_s_nMASK_MSB
 * @brief Constante utilizada como m�scara para obtener los 2 bits m�s significativos del valor de la longitud de rama en riel izquierdo y derecho.
 * @note
 */
#define RUNDIAG_TEST_s_nMASK_MSB (0x00030000)

/**
 * @def  RUNDIAG_TEST_s_nMASK_4BITS
 * @brief Constante utilizada como m�scara para obtener los 4 bits menos significativos del valor del rolling counter.
 * @note
 */
#define RUNDIAG_TEST_s_nMASK_4BITS (0x0F)

/**
 * @def  RUNDIAG_TEST_s_nSHIFT_16BITS
 * @brief Constante utilizada para realizar un corrimiento de 16 bits.
 * @note
 */
#define RUNDIAG_TEST_s_nSHIFT_16BITS (16U)

/**
 * @def  RUNDIAG_TEST_s_nPT_RTMC_IAP032_01
 * @brief Tiempo m�ximo de ejecuci�n de la interfaz RUNDIAG_vMonitor.
 * @note  Las unidades est�n us.
 */
#define RUNDIAG_TEST_s_nPT_RTMC_IAP032_01	(780U)

/**
 * @def  RUNDIAG_TEST_s_nPT_RTMC_IAP033_01
 * @brief Tiempo m�ximo de ejecuci�n de la interfaz RUNDIAG_vInit.
 * @note  Las unidades est�n us.
 */
#define RUNDIAG_TEST_s_nPT_RTMC_IAP033_01	(80U)

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
 * @def     RUNDIAG_TEST_nMAX_DISPLACEMENT
 * @brief   El máximo valor válido de desplazamiento en centimetros con dos decimales en formato de punto fijo
 *          (valor positivo máximo), es equivalente a (2^31-1)cm - 10Km .
 */
#define RUNDIAG_TEST_nMAX_DISPLACEMENT  (2146483647)


/**
 * @def  RUNDIAG_TEST_s_nP10Flag
 * @brief Constante que define la activaci�n del freno de emergencia por medio de la funci�n de seguridad P10
 * @note
 */
#define RUNDIAG_TEST_s_nP10Flag	(4096U)


/* internal__types */

/*Estructura que almacena el identificador del mensaje de CAN y el mensaje de CAN.*/
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

/*Estructura que almacena el identificador del mensaje de CAN y el mensaje de CAN.*/
typedef struct
{
	uint32 u32MsgId;
	uint32 u32TotalSignalsStates;
	uint32 u32SignalsStateSize;
	uint32 au32MsgBuff[RUNDIAG_nTOTAL_DIAG_SIGNALS_cfg];
}RUNDIAG_TEST_s_tstProcessMsg;

/*Estructura que almacena el identificador del mensaje de CAN y el mensaje de CAN.*/
typedef struct
{   CANDICT_tstCanId stIdCAN;
	CANDICT_tstCanResetDisplacement stMsgCAN;
}RUNDIAG_TEST_s_tstCanRUNDIAGMsg;

/* private__variables */
static uint8 RUNDIAG_TEST_s_u8State = (uint8)TESTINFO_nZERO;
static uint8 RUNDIAG_TEST_s_u8FlagSet = (uint8)STD_OFF;
static uint8 RUNDIAG_TEST_s_u8FlagChk = (uint8)STD_OFF;

static uint8* RUNDIAG_TEST_s_pau8FailureCount;
static uint8* RUNDIAG_TEST_s_pau8FailureCountMirror;
static DIGIFILTER_tstFilterProperties* RUANDIAG_TEST_s_pastProperties;
static DIGIFILTER_tstFilterProperties* RUANDIAG_TEST_s_pastPropCompl;
static ANALOGCFG_tstSignalConversion* RUNDIAG_TEST_s_pastConverId = NULL;
static ANALOGCFG_tstSignalConversion* RUNDIAG_TEST_s_pastConverIdCmpl = NULL;
static ANALOGCFG_tstSignalLocation* RUNDIAG_TEST_s_pastLocationId = NULL;
static ANALOGCFG_tstSignalLocation* RUNDIAG_TEST_s_pastLocationIdCmpl = NULL;
static ANALOG_tstAnalogTable* RUNDIAG_TEST_s_pastTable = NULL;
static ANALOG_tstAnalogTable* RUNDIAG_TEST_s_pastTableComp = NULL;
static ANALOG_tstADC1Signals* RUNDIAG_TEST_s_stADC1Capture = NULL;
static ANALOG_tstADC1Signals* RUNDIAG_TEST_s_stADC1Comp = NULL;
static RESETODO_tstWheelDisplacement* RUNDIAG_TEST_s_stWheelDis = NULL;
static RESETODO_tstWheelDisplacement* RUNDIAG_TEST_s_stWheelDisComp = NULL;
static uint32* RUNDIAG_TEST_s_pau32BreakFlags = NULL;
static uint32* RUNDIAG_TEST_s_pau32BreakFlags_Mirror = NULL;

/* private__functions */

/**
 * @def  RUNDIAG_TEST_s_vSetResetCanMsg
 * @brief Se encarga de definir la informaci�n del mensaje de CAN y establecerlo en el contexto de CTRL. Establece el mensaje de CAN para simular
 *        la recepci�n de un mensaje desde el CTV con la informaci�n del identificador, longitud de riel izquierdo y derecho de la rama a la que ingres� el veh�culo.
 *        Este mensaje se requiere para el c� culo de los factores de calibraci�n.
 * @note
 */
static void RUNDIAG_TEST_s_vSetResetCanMsg()
{
	RUNDIAG_TEST_s_tstCanRUNDIAGMsg stCANResetMsg = {0};
	uint32 u32BranchLeftLength = 0U;
	uint32 u32BranchRightLength = 0U;

	static uint8 u8MsgRC = 0U;
	uint8 u8MsgCRC = 0U;

	/*Se aumenta en 1 el rolling counter de mensajes de CAN si a�n no se ha alcanzado el valor m�ximo.*/
	if( u8MsgRC >= (uint8)MSGDICT_nCAN_ROLLCNTR_MAX)
	{
		u8MsgRC = TESTINFO_nZERO;
	}
	else
	{
		u8MsgRC++;
	}

	/*Se utiliza el mismo ID del mensaje de CAN que se recibir� en el componente RESETODO.*/
	stCANResetMsg.stIdCAN.u32CanMsgId = (uint32)RUNDIAG_TEST_nCAN_MSG_ID_cfg;

	/*Se establece el valor medio de la clase v�lida para la longitud de los rieles en la rama.*/
	u32BranchLeftLength = TESTINFO_middle_value_of_range(SERVMAP_nBRANCH_MIN_LEN, SERVMAP_nBRANCH_MAX_LEN);
	u32BranchRightLength = TESTINFO_middle_value_of_range(SERVMAP_nBRANCH_MIN_LEN, SERVMAP_nBRANCH_MAX_LEN);

	/*Se establece el valor medio de la clase v�lida para el ID de una rama izquierda.*/
	stCANResetMsg.stMsgCAN.u16BranchId = (uint16)TESTINFO_middle_value_of_range(SERVMAP_nLEFT_BRANCH_MIN_VAL, SERVMAP_nLEFT_BRANCH_MAX_VAL);

	/*Se realizan las operaciones en bits necesarias con las m�scaras determinadas para dividir la
	 * longitud de los rieles de la rama en los elementos del mensaje de CAN.
	 */
	stCANResetMsg.stMsgCAN.u16BranchLeftLengthLSB = (uint32)(u32BranchLeftLength & RUNDIAG_TEST_s_nMASK_LSB);
	stCANResetMsg.stMsgCAN.u16BranchRightLengthLSB = (uint32)(u32BranchRightLength & RUNDIAG_TEST_s_nMASK_LSB);
	stCANResetMsg.stMsgCAN.u2BranchLeftLengthMSB = (uint32)((u32BranchLeftLength & RUNDIAG_TEST_s_nMASK_MSB)>>RUNDIAG_TEST_s_nSHIFT_16BITS);
	stCANResetMsg.stMsgCAN.u2BranchRightLengthMSB = (uint32)((u32BranchLeftLength & RUNDIAG_TEST_s_nMASK_MSB)>>RUNDIAG_TEST_s_nSHIFT_16BITS);

	/*Se asigna el valor del rolling counter con la m�scara determinada para solo tomar los 4 bits requeridos en el mensaje de CAN.*/
	stCANResetMsg.stMsgCAN.u4RollingCounter = u8MsgRC & (uint8)RUNDIAG_TEST_s_nMASK_4BITS;
	stCANResetMsg.stMsgCAN.u8ConsistencyChecker = (uint8)TESTINFO_nZERO;

	/*Se llama a la interfaz CRC_LUT_vGetCRC8 para calcular el CRC del mensaje de CAN.*/
	CRC_LUT_vGetCRC8((uint8*)&stCANResetMsg, (uint16)sizeof(stCANResetMsg),(uint8*)&u8MsgCRC);
	stCANResetMsg.stMsgCAN.u8ConsistencyChecker = u8MsgCRC;

	/*Se establece el mensaje de CAN con el identificador correspondiente en el contexto de ctrl . */
	SHMEM_vSetVar((uint16)SHMEM_enCtrlResetDisplMsg, (uint8*) &stCANResetMsg.stMsgCAN, (uint16)sizeof(stCANResetMsg.stMsgCAN), (uint32*)NULL);
}

/**
 *
 * @def  RUNDIAG_TEST_s_vSetFlags
 * @brief Establece en alto la bandera definida para ejecutar la primera prueba del bloque SET, despu�s de haberse activado la interrupci�n de la se�al
 * 		  SPD_MARK_DET_IN en RESETODO.
 * @note
 */
void RUNDIAG_TEST_s_vSetFlags(void)
{
		RUNDIAG_TEST_s_u8FlagSet = (uint8)STD_ON;
}

/**
 * @def  RUNDIAG_TEST_s_vUpdateComp
 * @brief Se encarga de definir la informaci�n del mensaje de CAN y establecerlo en el contexto de CTRL. Establece el mensaje de CAN para simular
 *        la recepci�n de un mensaje desde el CTV con la informaci�n del identificador, longitud de riel izquierdo y derecho de la rama a la que ingres� el veh�culo.
 *        Este mensaje se requiere para el c� culo de los factores de calibraci�n.
 * @note
 */
static void RUNDIAG_TEST_s_vUpdateComp(const uint32 *pu32Table, uint32 *pu32Comp,uint16 u16Len)
{
	uint16 u16i;
	uint16 u16Words;

	u16Words = u16Len/(uint16)4U;

	for(u16i = 0U; u16i < u16Words; u16i++)
	{
		pu32Comp[u16i] = ~pu32Table[u16i];
	}
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: SINT_MAP010_BBT_ECP_IAP032_01                            *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9605, SS9867, SS10128, SS10196, SS9606, SS9607, SS10465, SS10466.
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
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal derecha.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda frontal izquierda.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera derecha.
*      				- Obtiene "E_NOT_OK", en el estado de la se�al de diagn�stico del sensor de calibraci�n de la rueda trasera izquierda.
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
static void HSINT_MAP010_BBT_ECP_IAP032_01_SET(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	/* Dentro de las interfaces de RESETODO ejecutadas cuando se genera la interrupci�n, se instal� entre guardas de integraci�n de HW
	 * una llamada a la funci�n auxiliar RUNDIAG_TEST_s_vSetFlags. Esta funci�n establece en alto la bandera necesaria para ejecutar la
	 * prueba.
	 */
	if (RUNDIAG_TEST_s_u8FlagSet == (uint8)STD_ON)
	{

	TESTINFO_check_if_split_test_is_enabled(u16Component,u8RunTest,u16TestType);

	/*Previamente se declararon entre guardas de integraci�n los prototipos de las siguientes funciones, que se utilizar�n
	 * para obtener la direcci�n de las variables est�ticas requeridas para esta prueba.
	 * */
	RUNDIAG_TEST_s_pau8FailureCount = (uint8*)RUNDIAG_TEST_pau8FailureCount();
	RUNDIAG_TEST_s_pau8FailureCountMirror = (uint8*)RUNDIAG_TEST_pau8FailureCountMirror();
	RUANDIAG_TEST_s_pastProperties = (DIGIFILTER_tstFilterProperties*)DIGIFILTER_TEST_pvGetProperties();
	RUANDIAG_TEST_s_pastPropCompl = (DIGIFILTER_tstFilterProperties*) DIGIFILTER_TEST_pvGetPropertiesCompl();
	RUNDIAG_TEST_s_pastConverId = (ANALOGCFG_tstSignalConversion*)ANALOGCFG_TEST_pvGetConverId();
	RUNDIAG_TEST_s_pastConverIdCmpl = (ANALOGCFG_tstSignalConversion*)ANALOGCFG_TEST_pvGetConverIdComp();
	RUNDIAG_TEST_s_pastLocationId = (ANALOGCFG_tstSignalLocation*)ANALOGCFG_TEST_pvGetLocationId();
	RUNDIAG_TEST_s_pastLocationIdCmpl = (ANALOGCFG_tstSignalLocation*)ANALOGCFG_TEST_pvGetLocationIdCmpl();
	RUNDIAG_TEST_s_pastTable = (ANALOG_tstAnalogTable*)ANALOG_TEST_pvGetTable();
	RUNDIAG_TEST_s_pastTableComp = (ANALOG_tstAnalogTable*)ANALOG_TEST_pvGetTableComp();
	RUNDIAG_TEST_s_stADC1Capture = (ANALOG_tstADC1Signals*)ANALOG_TEST_pvGetADC1Capture();
	RUNDIAG_TEST_s_stADC1Comp = (ANALOG_tstADC1Signals*)ANALOG_TEST_pvGetADC1Comp();
	RUNDIAG_TEST_s_stWheelDis = (RESETODO_tstWheelDisplacement*)RESETODO_TEST_pstGetWheelDis();
	RUNDIAG_TEST_s_stWheelDisComp = (RESETODO_tstWheelDisplacement*)RESETODO_TEST_pstGetWheelDisComp();
	RUNDIAG_TEST_s_pau32BreakFlags = (uint32*)BRKFLAGS_TEST_pvGetBrkFlags();
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror = (uint32*)BRKFLAGS_TEST_pvGetBrkFlagsMirror();

	RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV] = (uint32)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau32BreakFlags_Mirror[BRKFLAGS_enCHV] = (uint32)~RUNDIAG_TEST_s_pau32BreakFlags[BRKFLAGS_enCHV];

	/*Se establece el estado de diagn�stico del rel� de reseteo remoto*/
	POWEROFF_TEST_vSetDiagStatus(E_OK);

	/*Se establece el estado de diagn�stico de la rueda frontal izquierda*/
	DIOMUX_vSetState((uint16)DIOCFG_enSPD_FL_SENS_PWR, (uint8)STD_OFF);

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

	/*Se establece el estado de diagn�stico de la rueda frontal derecha*/
	DIOMUX_vSetState((uint16)DIOCFG_enSPD_FR_SENS_PWR, (uint8)STD_OFF);

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

	/*Se establece el estado de diagn�stico de la rueda trasera izquierda*/
	DIOMUX_vSetState((uint16)DIOCFG_enSPD_RL_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RL_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	/*Se establece el estado de diagn�stico de la rueda trasera derecha*/
	DIOMUX_vSetState((uint16)DIOCFG_enSPD_RR_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_SENS_PWR_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nANALOG_HIGH_MIN_CURRENT_cfg, DIAGENC_nANALOG_HIGH_MAX_CURRENT_cfg);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enSPD_RR_FREQ_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGENC_nHSD_HIGH_LOWER_REAR_VOLT_cfg, DIAGENC_nHSD_HIGH_UPPER_REAR_VOLT_cfg);

	/*Se establece el estado del sensor inductivo frontal izquierdo*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_L_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo frontal derecho*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_R_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)2000;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero izquierdo*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_L_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrLftPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo trasero derecho*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_R_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_SENS_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RrRgtPos_Sw_AD1].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento frontal*/
	DIOMUX_vSetState((uint16)DIOCFG_enCPL_F_ENGAGED_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_F_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_6000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_FrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)400;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_FrCoupEng].u8Channel];

	/*Se establece el estado del sensor inductivo de acoplamiento trasero*/
	DIOMUX_vSetState((uint16)DIOCFG_enCPL_R_ENGAGED_SENS_PWR, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_R_ENGAGED_PWR_VS].u8Channel] =
	(uint16)RUNDIAG_TEST_s_nRAWVAL_5000;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enCPL_RrCoupEng].s16FactorDenom;

	RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)1900;
	RUNDIAG_TEST_s_stADC1Comp->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel] = (uint16)~RUNDIAG_TEST_s_stADC1Capture->au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enCPL_RrCoupEng].u8Channel];

	/*Se establece el estado del sensor limit switch frontal derecho*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	/*Se establece el estado del sensor limit switch frontal izquierdo*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_FrntLftLmt_Sw_DIG, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_FL_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	/*Se establece el estado del sensor limit switch trasero derecho*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_RearRgtLmt_Sw_DIG, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RR_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	/*Se establece el estado del sensor limit switch trasero izquierdo*/
	DIOMUX_vSetState((uint16)DIOCFG_enDSW_RearLftLmt_Sw_DIG, (uint8)STD_HIGH);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDSW_RL_LIMIT_IN_VS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DIAGSWITCH_nSTD_LOW_MIN_VOLTAGE_cfg, DIAGSWITCH_nSTD_LOW_MAX_VOLTAGE_cfg);

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta derecha*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_LOW_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_LOW_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_R_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	/*Se establece el estado de la se�al de diagn�stico del sensor NAMUR de la puerta izquierda*/
	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_CLOSE_IN_CS].u8Channel] =
	(uint16)TESTINFO_middle_value_of_range(DOORSENS_NAMUR_CURR_STD_HIGH_LOW_LIMIT_cfg, DOORSENS_NAMUR_CURR_STD_HIGH_HIGH_LIMIT_cfg);

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorNum;

	RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)TESTINFO_nZERO_RIGHT;
	RUNDIAG_TEST_s_pastConverIdCmpl[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom = (sint16)~RUNDIAG_TEST_s_pastConverId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].s16FactorDenom;

	RUNDIAG_TEST_s_pastTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ADCDev].ANALOG_ISR_astSignalTable[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8ExtMux].au16RawVal[RUNDIAG_TEST_s_pastLocationId[ANALOGCFG_enDOOR_L_SENS_CLOSE_PWR_VS].u8Channel] =
	(uint16)DOORSENS_NAMUR_VOLT_STD_HIGH_LOW_LIMIT_cfg;

	/*Se establece el desplazamiento por llanta en centimetros (frontal Izquierda, frontal derecha, trasera izquierda y trasera derecha)*/
	RUNDIAG_TEST_s_stWheelDis->s32DisplacementFrL = (sint32)TESTINFO_right_int_limit(RUNDIAG_TEST_nMAX_DISPLACEMENT);
	RUNDIAG_TEST_s_stWheelDis->s32DisplacementFrR =  (sint32)TESTINFO_right_int_limit(RUNDIAG_TEST_nMAX_DISPLACEMENT);
	RUNDIAG_TEST_s_stWheelDis->s32DisplacementRrL =  (sint32)TESTINFO_right_int_limit(RUNDIAG_TEST_nMAX_DISPLACEMENT);
	RUNDIAG_TEST_s_stWheelDis->s32DisplacementRrR =  (sint32)TESTINFO_right_int_limit(RUNDIAG_TEST_nMAX_DISPLACEMENT);

	/*Se actualiza el Mirror de las variables anteriores para evitar corrupci�n de datos.*/
	RUNDIAG_TEST_s_stWheelDisComp->s32DisplacementFrL = (sint32)~RUNDIAG_TEST_s_stWheelDis->s32DisplacementFrL;
	RUNDIAG_TEST_s_stWheelDisComp->s32DisplacementFrR = (sint32)~RUNDIAG_TEST_s_stWheelDis->s32DisplacementFrR;
	RUNDIAG_TEST_s_stWheelDisComp->s32DisplacementRrL = (sint32)~RUNDIAG_TEST_s_stWheelDis->s32DisplacementRrL;
	RUNDIAG_TEST_s_stWheelDisComp->s32DisplacementRrR = (sint32)~RUNDIAG_TEST_s_stWheelDis->s32DisplacementRrR;

	/*Se actualiza el Mirror de las variables anteriores para evitar corrupci�n de datos.*/
	RUNDIAG_TEST_s_vUpdateComp((uint32*)&RUNDIAG_TEST_s_stADC1Capture,(uint32*)&RUNDIAG_TEST_s_stADC1Comp,(uint16)sizeof(ANALOG_tstADC1Signals));
	RUNDIAG_TEST_s_vUpdateComp((uint32*)&RUNDIAG_TEST_s_pastTable[ADC_enModule1],(uint32*)&RUNDIAG_TEST_s_pastTableComp[ADC_enModule1],(uint16)sizeof(ANALOG_tstAnalogTable));
	RUNDIAG_TEST_s_vUpdateComp((uint32*)&RUNDIAG_TEST_s_pastTable[ADC_enModule2],(uint32*)&RUNDIAG_TEST_s_pastTableComp[ADC_enModule2],(uint16)sizeof(ANALOG_tstAnalogTable));

	/*Se establece en alto la bandera definida para ejecutar la primera prueba del bloque CHK*/
	RUNDIAG_TEST_s_u8FlagChk = (uint8)STD_ON;

	}
	else
	{
		/*Nothing To do*/
	}
}

static void HSINT_MAP010_BBT_ECP_IAP032_01(uint16 u16Component, uint8 u8RunTest, uint16 u16TestType)
{
	/*Para que se ejecute la prueba en el bloque CHK, es necesario que previamente se haya ejecutado la correspondiente en el bloque
	 * SET; la bandera definida para asegurar esta acci�n es establecida en alto en la prueba del bloque SET.
	 */
	if (RUNDIAG_TEST_s_u8FlagChk == (uint8)STD_ON)
	{
	TESTINFO_check_if_split_test_chk_is_enabled(u16Component,u8RunTest,u16TestType);

	uint8 u32TestResult = (uint8)TRUE;

	uint32 u32BrkFlags = (uint32)TESTINFO_nZERO;

	uint8 u8i = 0U;

	RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enRlyDiag] = (uint8)TESTINFO_nZERO;
	RUNDIAG_TEST_s_pau8FailureCountMirror[RUNDIAG_TEST_enRlyDiag] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[RUNDIAG_TEST_enRlyDiag];

	for(u8i = (uint8)RUNDIAG_TEST_enenRightNamurSensor; u8i < (uint8)RUNDIAG_TEST_enFrontRightWheel; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO;
		RUNDIAG_TEST_s_pau8FailureCountMirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];
	}

	for(u8i = (uint8)RUNDIAG_TEST_enFrontRightWheel; u8i < (uint8)RUNDIAG_TEST_enTotalSignals; u8i++ )
	{
		RUNDIAG_TEST_s_pau8FailureCount[u8i] = (uint8)TESTINFO_nZERO_RIGHT;
		RUNDIAG_TEST_s_pau8FailureCountMirror[u8i] = (uint8)~RUNDIAG_TEST_s_pau8FailureCount[u8i];
	}


	u32BrkFlags = BRKFLAGS_u32GetFlags(BRKFLAGS_enCHV);
	u32TestResult = (u32BrkFlags == (uint32)RUNDIAG_TEST_s_nP10Flag) ? u32TestResult : (uint8)FALSE;

	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++*
	 *                   Expected Results                  *
	 *+++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	TESTINFO_vPrintStatus(__func__, u32TestResult);

	}
	else
	{
		/*Nothing to do*/
	}
}



/* public_functions */
void HSINT_MAP010(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

}

void HSINT_MAP010_SET(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	/*Las pruebas se ejecutan si la bandera que indica que el mensaje de CAN fue establecido se encuentra en alto.*/
	if (RUNDIAG_TEST_s_u8State == (uint8)STD_OFF)
	{
		/*Nothing to do*/
	}

	else
	{
		HSINT_MAP010_BBT_ECP_IAP032_01_SET(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	}
}

void HSINT_MAP010_CHK(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);


	/*Las pruebas se ejecutan si la bandera que indica que el mensaje de CAN fue establecido se encuentra en alto.*/
	if (RUNDIAG_TEST_s_u8State == (uint8)STD_OFF)
	{
		/*Nothing to do*/
	}
	else
	{

		HSINT_MAP010_BBT_ECP_IAP032_01(u16Component, u8RunBlock, (uint16)TESTINFO_enAuto);
	}

}

void HSINT_MAP010_CTRL(uint16 u16Component, uint8 u8RunBlock)
{
	TESTINFO_check_if_block_is_enabled(u16Component, u8RunBlock);

	static uint8 u8CyclesCount = 0U;

	/*Se hace una llamada a la interfaz auxiliar que establece el mensaje de CAN en el contexto de control
	 * cuando el programa del CHV llegue a estado autom�tico.
	 */
	if(SMCTRL_u16GetState() == (uint16)SMCTRL_enStateAuto)
	{
		RUNDIAG_TEST_s_vSetResetCanMsg();

		/*Se requieren 2 ciclos adicionales para que el mensaje de CAN pueda recibirse en el contexto de protecci�n.*/

		if(u8CyclesCount > (uint8)TESTINFO_nZERO_RIGHT)
		{
			/*Se establece en alto la bandera para ejecutar las pruebas del bloque SET y CHK.*/
			RUNDIAG_TEST_s_u8State = (uint8)STD_ON;
		}
		else
		{
			u8CyclesCount++;
		}
	}
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: HSINT_MAP010_PT_RTMC_IAP033_01                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vInit
* @Requirements: SS9621.
* @Description:
* 		Se comprueba que la interfaz Monitor se ejecute en un tiempo menor a los 80 us.
* @Pre:
* @Notes:
*         NA.
*/
void HSINT_MAP010_PT_RTMC_IAP033_01(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__,(uint32)RUNDIAG_TEST_s_nPT_RTMC_IAP033_01);
}

/*
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
*@TestId: HSINT_MAP010_PT_RTMC_IAP032_01                             *
*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
* @Interface: RUNDIAG_vMonitor
* @Requirements: SS9615.
* @Description:
* 		Se comprueba que la interfaz Monitor se ejecute en un tiempo menor a los 780 us.
* @Pre:
* @Notes:
*         NA.
*/
void HSINT_MAP010_PT_RTMC_IAP032_01(uint16 u16Component, uint16 u16TestType)
{
	TESTINFO_nh_time_measurement(u16Component,u16TestType,__func__,(uint32)RUNDIAG_TEST_s_nPT_RTMC_IAP032_01);
}



/* EOF */
