

#ifndef FLASH_H_
#define FLASH_H_

/* system headers */

#include "Std_Types.h"

/* used headers */

/* own headers */

/****************************************************************************************/

/* exported configuration macros */

#define FLASH_E_OK	          (0)
#define FLASH_E_ERROR         (1)
#define FLASH_E_BUSY          (2)
#define FLASH_E_READY         (3) 
#define FLASH_E_ERROR_ADDRESS (4)
#define FLASH_E_ERROR_LENGTH  (5)
#define FLASH_E_ERROR_POINTER (6)

/* exported types */

/* exported variables */

/* exported functions */

extern void FLASH_vInit(void);
extern uint8 FLASH_u8ReadBuffer(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length);
extern uint8 FLASH_u8WriteBuffer(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length);

#endif /* FLASH_H_ */
