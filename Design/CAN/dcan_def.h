
#ifndef DCAN_DEF_H_
#define DCAN_DEF_H_

/* system headers */

/* used headers */

/* own headers */

/*****************************************************************************/

/* exported pre-procesor macros */





/* exported types */

typedef enum
{
	DCAN_enOperationMode_RxMailbox = 1,
	DCAN_enMarksSensor_RxMailbox,
	
	DCAN_enACK_TxMailbox,
	DCAN_enMarksSensor_TxMailbox
}DCAN_tenMailboxDef;

typedef enum
{
	CAN_enCHV_C_SA	= 0,
	CAN_enCHV_P_SA	= 1,
	CAN_enCTV_C_SA	= 2,
	CAN_enCTV_P_SA	= 3,
	CAN_enSIV_C_SA	= 4,
	CAN_enSIV_P_SA	= 5,
	CAN_enCIU_M_SA	= 6,
	CAN_enCIU_S_SA	= 7,
	CAN_enDDP_SA	= 8,
	CAN_enIND_SA = 0xFF
}CAN_SourceAddr;

/* exported variables */

/* exported functions */


#endif /* DCAN_DEF_H_ */
