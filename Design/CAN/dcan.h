

#ifndef DCAN_H_
#define DCAN_H_

/* system headers */
#include "Std_Types.h"

/* used headers */

/* own headers */
#include "dcan_def.h"
#include "dcan_config.h"
/*****************************************************************************/

/* exported pre-procesor macros */
#define DCAN_E_OK 				(0)
#define DCAN_E_NOT_OK			(1)
#define DCAN_E_ERROR_ADDR		(2)
#define DCAN_E_ERROR_DATA_LOST	(3)


#define DCAN__LEVEL_ACTIVE	(0x00)	/* When RX- and TX error counters are below 96 */
#define DCAN__LEVEL_WARNING	(0x40)	/* When RX- or TX error counter are between 96 and 127 */
#define DCAN__LEVEL_PASSIVE	(0x20)	/* When RX- or TX error counter are between 128 and 255 */
#define DCAN__LEVEL_BUS_OFF	(0x80)	/* When RX- or TX error counter are above 255 */

#define DCAN__DIRECTION_TX	(1)
#define DCAN__DIRECTION_RX	(0)

#define DCAN_NORMAL_FRAME			(0x00)
#define DCAN_EXTENDED_FRAME			(0x01)
#define DCAN__NORMAL_FRAME_MASK		(0x1FFC0000UL)
#define DCAN__EXTENDED_FRAME_MASK	(0x1FFFFFFFUL)

#define DCAN__EXTENDED_FRAME_ID_SHIFT	( 0U )	/* IFxARB.ID Bits 28:0  */
#define DCAN__NORMAL_FRAME_ID_SHIFT		( 18U ) /* IFARB.ID  Bits 28:18 */


/* GPIO EXPOSED */
#define DCAN_GPIO_RX	(0)
#define DCAN_GPIO_TX	(1)

#define DCAN_GPIO_INPUT		(0)
#define DCAN_GPIO_OUTPUT	(1)

/* exported types */
typedef enum
{
	DCAN_enCANA = 0,
	DCAN_enCANC,
	DCAN_enCAND,
	DCAN_enTotalDevices
}DCAN_tenDevices;

typedef enum
{
	DCAN_enInterruptHigh = 0,
	DCAN_enInterruptLow,
	DCAN_enInterruptIF3
}DCAN_tenInterruptTypes;

typedef void (*DCAN_tpvfFunction)(uint8,uint8,uint8,uint8*);



/* exported variables */

/* exported functions */

extern void  DCAN_vInit(DCAN_tenDevices u8Device);
extern uint8 DCAN_u8TransmitMailbox(uint8 u8Device, uint8 u8Mailbox, uint8 u8DLC, uint8 *pu8Data);
extern uint8 DCAN_u8WakeUp(DCAN_tenDevices enDevice);
extern void DCAN_vReceivedMessagesISR(uint8 u8Device, uint8 u8Mailbox, uint8 u8DLC, uint8 *pu8Data);
extern void DCAN_vGetAllRxMbData(void* pvData);
extern void DCAN_vGetMbStatus(void* pvData);
extern uint32 DCAN_u32GetTimestampISR(void);
extern uint32 DCAN_u32GetBufferISR(void);
extern uint32 DCAN_u32GetCanCheck(void);
extern uint8 DCAN_u8GetDLC(void);


typedef struct
{
#if _little_endian__
  uint8  reserved0[3];
  uint8  IRQIVEC;
  uint8  reserved1[3];
  uint8  FIQIVEC;
#else
  uint8  IRQIVEC;
  uint8  reserved0[3];
  uint8  FIQIVEC;
  uint8  reserved1[3];
#endif
  uint32 reserved2[2];
  uint32 FIRQPR0;          /* 0x0010        */
  uint32 FIRQPR1;          /* 0x0014        */
  uint32 FIRQPR2;          /* 0x0018        */
  uint32 FIRQPR3;          /* 0x001C        */
  uint32 INTREQ0;          /* 0x0020        */
  uint32 INTREQ1;          /* 0x0024        */
  uint32 INTREQ2;          /* 0x0028        */
  uint32 INTREQ3;          /* 0x002C        */
  uint32 REQMASKSET0;      /* 0x0030        */
  uint32 REQMASKSET1;      /* 0x0034        */
  uint32 REQMASKSET2;      /* 0x0038        */
  uint32 REQMASKSET3;      /* 0x003C        */
  uint32 REQMASKCLR0;      /* 0x0040        */
  uint32 REQMASKCLR1;      /* 0x0044        */
  uint32 REQMASKCLR2;      /* 0x0048        */
  uint32 REQMASKCLR3;      /* 0x004C        */
  uint32 WAKEMASKSET0;     /* 0x0050        */
  uint32 WAKEMASKSET1;     /* 0x0054        */
  uint32 WAKEMASKSET2;     /* 0x0058        */
  uint32 WAKEMASKSET3;     /* 0x005C        */
  uint32 WAKEMASKCLR0;     /* 0x0060        */
  uint32 WAKEMASKCLR1;     /* 0x0064        */
  uint32 WAKEMASKCLR2;     /* 0x0068        */
  uint32 WAKEMASKCLR3;     /* 0x006C        */
  uint32 IRQVECREG;        /* 0x0070        */
  uint32 FIQVECREQ;        /* 0x0074        */
  uint16 CAPEVTSRC1;
  uint16 CAPEVTSRC0;
  uint32 reserved5;        /* 0x007C        */
  uint8  CHANMAP[64U];     /* 0x0080-0x017C */
}VIM__tstMap;

#define VIM_ ((VIM__tstMap*)0xFFFFFE00U)



#endif /* DCAN_H_ */
