
#ifndef TINACO_v2_def_H_
#define TINACO_v2_def_H_

/* system headers */
#include "Std_Types.h"

/*****************************************************************************/
/* exported macros */
#define STD_10S  (10)

/* exported types */
typedef enum
{
	GPIO_enPortA=0,
	GPIO_enTotalPorts,
}GPIO_tenPorts;
typedef enum
{
	GPIO_enPin1=0,
	GPIO_enPin2,
	GPIO_enPump,
	GPIO_enIndicator,
	GPIO_enInvalidState,
	GPIO_enTotalPin,
}GPIO_tenPortsPin;


#endif /* TINACO_v2_def_H_ */

