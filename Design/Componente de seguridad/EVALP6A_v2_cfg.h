#ifndef EVALP6A_cfg_H_
#define EVALP6A_cfg_H_

/* system headers */
#include "Std_Types.h"
#include "SHMEM_def.h"

/*****************************************************************************/
/* exported configuration macros */
/**
 * @def		EVALP6A_nLEFT_RED_LED_SIGNAL_cfg
 * @brief	Identificador de la señal correspondiente al led rojo de la rama izquierda.
 * @note	Clase válida [0,DIOCFG_enTotalSignals)
 **/
#define EVALP6A_nLEFT_RED_LED_SIGNAL_cfg 		(0)
/**
 * @def		EVALP6A_nRIGHT_RED_LED_SIGNAL_cfg
 * @brief	Identificador de la señal correspondiente al led rojo de la rama derecha.
 * @note	Clase válida [0,DIOCFG_enTotalSignals)
 **/
#define EVALP6A_nRIGHT_RED_LED_SIGNAL_cfg 		(1)
/**
 * @def		EVALP6A_nCOMMON_RED_LED_SIGNAL_cfg
 * @brief	Identificador de la señal correspondiente al led rojo de la rama comun.
 * @note	Clase válida [0,DIOCFG_enTotalSignals)
 **/
#define EVALP6A_nCOMMON_RED_LED_SIGNAL_cfg 		(2)

/**
 * @def     EVALP6A_nKEY_LEFT_BRANCH_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para la rama izquierda.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nKEY_LEFT_BRANCH_SIGNAL_cfg        (3)

/**
 * @def     EVALP6A_nKEY_RIGHT_BRANCH_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para la rama derecha.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nKEY_RIGHT_BRANCH_SIGNAL_cfg        (4)

/**
 * @def     EVALP6A_nKEY_COMMON_BRANCH_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para la rama comun.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nKEY_COMMON_BRANCH_SIGNAL_cfg        (5)

/**
 * @def     EVALP6A_nKEY_CLOSED_BRANCH_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para cerrar todas las ramas.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nKEY_CLOSED_BRANCH_SIGNAL_cfg        (6)

/**
 * @def     EVALP6A_nKEY_OPEN_BRANCH_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para abrir todas las ramas.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nKEY_OPEN_BRANCH_SIGNAL_cfg        (7)

/**
 * @def     EVALP6A_nBRANCH_CONFIRM_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para cerrar todas las ramas.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nBRANCH_CONFIRM_SIGNAL_cfg        (8)

/**
 * @def     EVALP6A_nBRANCH_CONFIRM_NEGATIVE_SIGNAL_cfg
 * @brief   Identificador de la señal correspondiente la llave para abrir todas las ramas.
 * @note    Clase válida [0,DIGIFILTER_enTotalSignals)
 **/
#define EVALP6A_nBRANCH_CONFIRM_NEGATIVE_SIGNAL_cfg        (9)

/**
 * @def     EVALP6A_nBRANCH_SHARED_STATE_ID_cfg
 * @brief   Identificador de la señal correspondiente la llave para abrir todas las ramas.
 * @note    Clase válida [0,SHMEM_enTotalProtVariables)
 **/
#define EVALP6A_nBRANCH_SHARED_STATE_ID_cfg        (SHEM_enCtrlStatusActualBranch )


#endif /* EVALP6A_cfg_H_ */





