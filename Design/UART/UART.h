

#ifndef UART_H_
#define UART_H_

/* system headers */
#include "Std_Types.h"
/* used headers */

/* own headers */


/*****************************************************************************/

/* exported configuration macros */

/* exported types */
typedef enum
{
	UART_enBaud110 = 110,
	UART_enBaud2400 = 2400,
	UART_enBaud9600 = 9600,
	UART_enBaud19200 = 19200,
	UART_enBaud38400 = 38400,
	UART_enBaud57600 = 57600,
	UART_enBaud115200 = 115200,
	UART_enBaud230400 = 230400,
	UART_enBaud_MAX = UART_enBaud230400
}UART_tenBaudRates;


typedef enum
{
	UART_enDevice0,
	UART_enDevice1,
        UART_enTotalDevices
}UART_tenDevices;

typedef void (*UART_tpvfRxCallBack)(uint8);
typedef void (*UART_tpvfTxCallBack)(void);

/* exported variables */

/* exported functions */
extern void UART_vInit(UART_tenDevices enDevice, UART_tenBaudRates enBaudRate);
extern void UART_vInstallRxCallBack(UART_tenDevices enDevice, UART_tpvfRxCallBack pvfCallback);
extern void UART_vInstallTxCallBack(UART_tenDevices enDevice, UART_tpvfTxCallBack pvfCallback);
extern void UART_vSendBuffer(UART_tenDevices enDevice, uint8 *pu8Data, uint16 u16Length);



#endif /* UART_H_ */
