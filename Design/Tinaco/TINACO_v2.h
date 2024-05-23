#ifndef TINACO_v2_H_
#define TINACO_v2_H_

/* system headers */
#include "Std_Types.h"

/* own headers */

/*****************************************************************************/
/* helper macros */

/* exported variables */

/* exported functions */
extern void TINACO_vMonitor(void);
extern uint8 GPIO_u8GetState(uint8 u8Port, uint8 u8Pin);
extern uint8 GPIO_u8Set(uint8 u8Port, uint8 u8Pin, uint8 u8State);
extern void TINACO_vReset_Counter(void);

#endif /* TINACO_v2_H_ */
