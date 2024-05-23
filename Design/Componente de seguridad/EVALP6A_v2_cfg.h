/**
 * @copyright
 * This document is a part of the source code and related artifacts
 * for Modutram Autotrén transportation system
 *
 * http://www.modutram.com
 *
 * Copyright © 2021 Modutram
 *
 * Any use of this source code - including reproduction, modification, distribution, 
 * republication, transmission, re-transmission, modification, or public showing - without the prior 
 * written permission of Modutram is strictly prohibited. 
 *
 * @file    SIS_MSF088_EVALP6A_cfg.h
 *
 * @brief   MSF088 -- SIL4 -- Configuración: Determina el estado lógico de las ramas (abierta o cerrada) 
 *                            del SIV actual y las ramas de entrada del SIV siguiente, así 
 *                            como de actualizar el estado de los LEDs ademas de 
 *                            diagnosticar el estado de la llave y del boton de 
 *                            confirmación   
 * @note
 *        ______________      ______________      ______________
 *        Horalia Reyes               TBD_V               TBD_P
 *        Diseñador           Verificador         PM 
 *
 * @version SIS  * - Horalia Reyes -- 02/11/2021 -- No oficial
 *   - Primera Versión
 *     
 */

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





