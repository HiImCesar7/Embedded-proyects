
#ifndef EVALP6A_def_H_
#define EVALP6A_def_H_

/* system headers */
#include "Std_Types.h"

/* exported macros */

/* exported types */

#define EVALP6A_nOPEN_BRANCH					(0U)
#define EVALP6A_nCLOSED_BRANCH					(1U)
#define STD_UNDEFINED_STATE 					(-38)
#define EVALP6A_LIMIT_ACTUAL					(3U)
#define EVALP6A_LIMIT_NXT						(6U)
#define ON 										(1U)
#define OFF 									(0U)

/**
 * @enum EVALP6A_tenBrIdents
 * @brief Indice para indicar la rama de la cual se desea conocer o modificar
 * su estado logico (abierta o cerrada)
 */
typedef enum
{
	EVALP6A_enCurrLeftBranch = 0,
	EVALP6A_enCurrRightBranch,
	EVALP6A_enCurrCommonBranch,
	EVALP6A_enNxtLeftBranch,
	EVALP6A_enNxtRightBranch,
	EVALP6A_enNxtCommonBranch,
	EVALP6A_enTotalBranches
} EVALP6A_tenBrIdents;

/**
 * @enum EVALP6A_tenBrIdents
 * @brief Indice para indicar la rama de la cual se desea conocer o modificar
 * su estado logico (abierta o cerrada)
 */
typedef enum
{
    EVALP6A_enKeyDiag = 0,
    EVALP6A_enButtonDiag,
    EVALP6A_enTotalDiag
} EVALP6A_tenDiagId;

typedef enum
{
    EVALP6A_enKeyState = 0,
    EVALP6A_enButtonState,
    EVALP6A_enTotalState
} EVALP6A_tenStateId;

typedef enum
{
	EVALP6a_enBRANCH_CLOSED = 0,
	EVALP6a_enBRANCH_LEFT,
	EVALP6a_enBRANCH_RIGHT,
	EVALP6a_enBRANCH_COMMON,
	EVALP6a_enBRANCH_OPEN,
	EVALP6a_enTOTAL_StatesKey
}EVALP6_tenKeyStates;

typedef enum
{
	EVALP6a_enLfBrRedLED = 0,
	EVALP6a_enRtBrRedLED,
	EVALP6a_enCmBrRedLED,
	EVALP6a_enTOTAL_LEDS
}EVALP6_tenLEDStates;

typedef enum
{
	EVALP6a_enBUTTON_ON = 0,
	EVALP6a_enBUTTON_ERROR,
	EVALP6a_enBUTTON_STDBY,
	EVALP6a_enTOTAL_BUTTON
}EVALP6_tenButtonStates;





#endif /* EVALP6A_def_H_ */
