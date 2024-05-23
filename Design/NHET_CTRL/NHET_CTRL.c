
/* system headers */
#include "_assert_.h"

/*used headers*/
#include "NHET.h"
#include "NHET_def.h"

/*own headers*/
#include "NHET_CTRL.h"


sint32 NHET_CTRL_s32SetDutyCycle(uint16 u16PWMSignal, uint8 u8DutyCycle)
{
	sint32 s32ReturnValue = E_NOT_OK;

	ASSERT_HARD_ERROR((u16PWMSignal < (uint16)NHET_enTotalPwmSignals),E_INVALID_SIGNAL);

	s32ReturnValue = NHET_s32SetDutyCycle(u16PWMSignal,u8DutyCycle);

	return s32ReturnValue;
}

uint8 NHET_CTRL_u8GetDutyCycle(uint16 u16PWMSignal)
{
	uint8 u8ReturnValue = 0U;

	ASSERT_HARD_ERROR((u16PWMSignal < (uint16)NHET_enTotalPwmSignals),E_INVALID_SIGNAL);

	u8ReturnValue = NHET_u8GetDutyCycle(u16PWMSignal);

	return u8ReturnValue;
}

sint32 NHET_CTRL_s32GetPulseCount(uint16 u16SignalId)
{
	sint32 s32ReturnValue = 0U;

	ASSERT_HARD_ERROR((u16SignalId < (uint16)NHET_enTotalSignals),E_INVALID_SIGNAL);

	s32ReturnValue = NHET_s32GetPulseCount(u16SignalId);

	return s32ReturnValue;
}

uint32 NHET_CTRL_u32GetPulsePeriod( uint16 u16SignalId )
{
	sint32 s32ReturnValue = 0U;

	ASSERT_HARD_ERROR((u16SignalId < (uint16)NHET_enTotalSignals),E_INVALID_SIGNAL);

	s32ReturnValue = NHET_u32GetPulsePeriod(u16SignalId);

	return s32ReturnValue;
}



