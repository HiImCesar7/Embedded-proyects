#ifndef EVALP6A_H_
#define EVALP6A_H_

/* system headers */
#include "Std_Types.h"

/* own headers */

/*****************************************************************************/
/* helper macros */

/* exported variables */

/* exported functions */
/**
 * @fn          void EVALP6A_vMonitor(void)
 * @version     ISF193 -- 8+kXq
 * @brief       Determina los estados lógicos de las ramas en el SIV actual y las de entrada al siguiente SIV, 
 *              además de encender o apagar los LEDs del SIV actual para indicar los estados de las ramas ya 
 *              mencionados
 * @pre         Ninguna
 * @post        Ninguna
 * @return      void
*/
extern          void EVALP6A_vMonitor(void);

/**
 * @fn          uint8 EVALP6A_u8Get(uint16 u16SelectBranch)
 * @version     ISF194 -- BfdZx
 * @brief       Indica el estado actual de las ramas (sección actual o primeras ramas de la siguiente sección)
 * @pre         Ninguna
 * @post        Ninguna
 * @param[in]   u16SelectBranch
 *                  - Rango del tipo A = { {x | (x ∈ ℕ) ∩ (x ∈ [0, 2^16-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[0, #EVALP6A_enTotalBranches) }
 *                  - Clases inválidas C = { 
 *                        - A-B }
 * @return      uint8
 *                  - Rango del tipo A = { {x | (x ∈ ℕ) ∩ (x ∈ [0, 2^8-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[#EVALP6A_nOPEN_BRANCH, #EVALP6A_nCLOSED_BRANCH] }
 *                  - Clases inválidas C = { 
 *                        - A - B }
*/
extern          uint8 EVALP6A_u8Get(uint16 u16SelectBranch);

/**
 * @fn          void EVALP6A_vCloseBranch(uint16 u16SelectBranch,uint8 u8BranchState)
 * @version     ISF195 -- LLlIe
 * @brief       Permite cambiar el estado de las ramas monitoreadas por la sección actual, 
 *              ya sea abrir o cerrar rama
 * @pre         Ninguna
 * @post        Ninguna
 * @param[in]   u16SelectBranch
 *                  - Rango del tipo A = { {x | (x ∈ ℕ) ∩ (x ∈ [0, 2^16-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[0, #EVALP6A_enTotalBranches) }
 *                  - Clases inválidas C = { 
 *                        - A-B }
 * @param[in]   u8BranchState
 *                  - Rango del tipo A = { {x | (x ∈ ℕ) ∩ (x ∈ [0, 2^8-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[#EVALP6A_nOPEN_BRANCH, #EVALP6A_nCLOSED_BRANCH] }
 *                  - Clases inválidas C = { 
 *                        - A - B }
 * @return      void
*/
extern          void EVALP6A_vCloseBranch(uint16 u16SelectBranch,uint8 u8BranchState);

/**
 * @fn          void EVALP6A_vInit(void)
 * @version     ISF222 -- ZvPvq
 * @brief       Realiza la inicialización del componente
 * @pre         Ninguna
 * @post        Ninguna
 * @return      void
*/
extern          void EVALP6A_vInit(void);

/**
 * @fn          sint32 EVALP6A_s32Diag(uint16 u16SelectDiag)
 * @version     ISF227 -- SLsqI
 * @brief       Entrega el estado del diagnostico de la llave y del boton de confirmación
 * @pre         Ninguna
 * @post        Ninguna
 * @param[in]   u16SelectDiag
 *                  - Rango del tipo A = { {x | (x ∈ ℕ) ∩ (x ∈ [0, 2^16-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[0, #EVALP6A_enTotalDiag) }
 *                  - Clases inválidas C = { 
 *                        - A-B }
 * @return      sint32
 *                  - Rango del tipo A = { {x | (x ∈ ℤ) ∩ (x ∈ [-2^31, 2^31-1])} }
 *                  - Clases válidas (B ∈ A) | B = { 
 *                        - B=[#E_OK, #E_NOT_OK, #STD_UNDEFINED_STATE] }
 *                  - Clases inválidas C = { 
 *                        - A - B }
*/
extern          sint32 EVALP6A_s32Diag(uint16 u16SelectDiag, sint32* s32StatusDiag);

extern uint8 prueba(void);

extern 			sint32 EVALP6A_s32LedStatus(void);

#endif /* EVALP6A_H_ */
