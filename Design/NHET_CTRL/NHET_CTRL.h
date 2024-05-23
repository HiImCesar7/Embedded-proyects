

#ifndef NHET_CTRL_H_
#define NHET_CTRL_H_


#include "Std_Types.h"


extern sint32 NHET_CTRL_s32SetDutyCycle(uint16 u16PWMSignal, uint8 u8DutyCycle);
extern uint8 NHET_CTRL_u8GetDutyCycle(uint16 u16PWMSignal);
extern sint32 NHET_CTRL_s32GetPulseCount(uint16 u16SignalId);
extern uint32 NHET_CTRL_u32GetPulsePeriod(uint16 u16SignalId);

#endif /* NHET_CTRL_H_ */
