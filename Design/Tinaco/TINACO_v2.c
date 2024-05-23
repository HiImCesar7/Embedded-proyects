
/* system headers */
#include "Std_Types.h"

/* used headers */
#include "TINACO_v2.h"
#include "TINACO_v2_def.h"
/* own headers */


/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */

/* internal__types */

/* private__variables */
static uint8 au8Port[GPIO_enTotalPin];
static uint8 u8Counter = STD_OFF;
/* private__functions */

/* public_functions */
void TINACO_vReset_Counter(void)
{
	u8Counter = STD_OFF;
}

void TINACO_vMonitor(void)
{

	if(au8Port[GPIO_enPin1] == STD_HIGH && au8Port[GPIO_enPin2] == STD_HIGH)
	{
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enPump, (uint8)STD_HIGH);
		u8Counter ++;
	}
	else if((u8Counter < STD_10S && au8Port[GPIO_enPump] == (uint8)STD_HIGH) && (au8Port[GPIO_enPin1] == (uint8)STD_LOW) && (au8Port[GPIO_enPin2] == (uint8)STD_LOW))
	{
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enPump, (uint8)STD_LOW);
		u8Counter = STD_OFF;
	}
	else if(au8Port[GPIO_enPump] == STD_HIGH && u8Counter < STD_10S && au8Port[GPIO_enPin1] == STD_LOW && au8Port[GPIO_enPin2] == STD_HIGH)
	{
		u8Counter ++;
	}
	else if((u8Counter >= STD_10S && au8Port[GPIO_enPump] == (uint8)STD_HIGH) && (au8Port[GPIO_enPin1] == (uint8)STD_LOW) && (au8Port[GPIO_enPin2] == (uint8)STD_HIGH))
	{
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enPump, (uint8)STD_OFF);
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enIndicator, (uint8)STD_HIGH);
		u8Counter = STD_OFF;
	}
	else if ((u8Counter < STD_10S && au8Port[GPIO_enPump] == (uint8)STD_HIGH) && (au8Port[GPIO_enPin1] == (uint8)STD_HIGH) && (au8Port[GPIO_enPin2] == (uint8)STD_LOW))
	{
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enPump, (uint8)STD_OFF);
		GPIO_u8Set((uint8)GPIO_enPortA, (uint8)GPIO_enInvalidState, (uint8)STD_HIGH);
	}
	else
	{
		/*nothing to do*/
	}
}



uint8 GPIO_u8GetState(uint8 u8Port, uint8 u8Pin)
{
	uint8 u8Result;
	u8Result = au8Port[u8Pin];

	return u8Result;
}


uint8 GPIO_u8Set(uint8 u8Port, uint8 u8Pin, uint8 u8State)
{
	uint8 u8Result = (uint8)STD_LOW;
	if(u8Port < (uint8)GPIO_enTotalPorts)
	{
		if(u8Pin < (uint8)GPIO_enTotalPin)
		{
			if(_bool_(u8State)== STD_HIGH)
			{
				au8Port[u8Pin] = STD_HIGH;
				u8Result = STD_HIGH;
			}
			else
			{
				au8Port[u8Pin] =STD_LOW;
				u8Result = STD_LOW;
			}
		}
		else
		{
			/*Nothing to do*/
		}
	}
	else
	{
		/*Nothing to do*/
	}
return u8Result;
}


/* EOF */
