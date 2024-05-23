/* system headers */

/* used headers */

/* own headers */
#include "Std_Types.h"
#include "_error_.h"
#include "_assert_.h"
#include "ANTIGLITCH_cfg.h"
#include "ANTIGLITCH_def.h"
#include "ANTIGLITCH.h"
#include "DIGIFILTER.h"
#include "DIGIFILTER_def.h"
#include "DIOCFG_def.h"
#include "MMD029_DIOMUX_cfg.h"
#include "MMD029_DIOMUX_def.h"
#include "MMD029_DIOMUX.h"
#include "sciopta.h"
#include "MSF088_EVALP6A_v2.h"
#include "MSF088_EVALP6A_v2_cfg.h"
#include "MSF088_EVALP6A_v2_def.h"
#include "SIS_MAP032_CONFIGSIV_cfg.h"
#include "SIS_MAP032_CONFIGSIV_def.h"
#include "SIS_MAP032_CONFIGSIV.h"
#include "SHMEM.H"
#include "SHMEM_cfg.H"
#include "SHMEM_def.H"
/*[EXPORTED]****************************************************************************/

/* public_variables */

/*[INTERNAL]****************************************************************************/

/* internal__pre-processor macros */

/* internal__types */

/* private__variables */
static sint32 EVALP6A_s_s32DiagStatus[EVALP6A_enTotalDiag];
static sint32 EVALP6A_s_s32BranchStateID[EVALP6A_enTotalState];
static uint8 EVALP6A_s_u8Branches[EVALP6A_enTotalBranches];
static uint8 EVALP6A_s_u8TypeSection;
static sint32 EVALP6A_s_s32DiagStatusBranch;
static sint32 EVALP6A_s_s32DiagStatusButton;
static sint32 EVALP6A_s_s32MemoryDiagButton;
static sint32 EVALP6A_s_s32MemoryDiagKey;
static sint32 EVALP6A_s_s32StatusLEDS;



/* private__functions */

/* public_functions */
sint32 EVALP6A_s32Diag(uint16 u16SelectDiag,sint32* s32StatusDiag)
{
	sint32 s32ReturnStatus=0;

	if(u16SelectDiag < (uint16)EVALP6A_enTotalDiag)
	{
		switch(u16SelectDiag)
		{
			case EVALP6A_enKeyDiag:
				if(EVALP6A_s_s32BranchStateID[EVALP6A_enKeyState] < (sint32)EVALP6a_enTOTAL_StatesKey )
				{
					EVALP6A_s_s32DiagStatus[EVALP6A_enKeyDiag] = E_OK;
					s32ReturnStatus = E_OK;
					*s32StatusDiag = EVALP6A_s_s32BranchStateID[EVALP6A_enKeyState];
				}
				else
				{
					EVALP6A_s_s32DiagStatus[EVALP6A_enKeyDiag] = E_NOT_OK;
					s32ReturnStatus = E_NOT_OK;
				}

			break;
			case EVALP6A_enButtonDiag:
				if(EVALP6A_s_s32BranchStateID[EVALP6A_enButtonDiag] < (sint32)EVALP6a_enTOTAL_BUTTON)
				{
					switch(EVALP6A_s_s32BranchStateID[EVALP6A_enButtonDiag])
					{
						case EVALP6a_enBUTTON_ON:
							EVALP6A_s_s32DiagStatus[EVALP6A_enButtonDiag] = E_OK;
							s32ReturnStatus = E_OK;
							*s32StatusDiag = EVALP6A_s_s32BranchStateID[EVALP6A_enButtonState];
						break;
						case EVALP6a_enBUTTON_ERROR:
							EVALP6A_s_s32DiagStatus[EVALP6A_enButtonDiag] = E_NOT_OK;
							s32ReturnStatus = E_NOT_OK;
						break;
						case EVALP6a_enBUTTON_STDBY:
							EVALP6A_s_s32DiagStatus[EVALP6A_enButtonDiag] = STD_UNDEFINED_STATE;
							s32ReturnStatus = STD_UNDEFINED_STATE;
						break;
						default:
							ASSERT_HARD_ERROR((EVALP6A_s_s32BranchStateID[EVALP6A_enButtonDiag] < (sint32)EVALP6a_enTOTAL_BUTTON),E_INVALID_STATE);
						break;
					}
				}
				else
				{
					ASSERT_HARD_ERROR(u16SelectDiag < (uint16)EVALP6A_enTotalDiag,E_INVALID_STATE);
				}
			break;
			default:
				ASSERT_HARD_ERROR(u16SelectDiag < (uint16)EVALP6A_enTotalDiag,E_INVALID_STATE);
			break;
		}
	}
	else
	{
		ASSERT_HARD_ERROR(u16SelectDiag < (uint16)EVALP6A_enTotalDiag,E_INVALID_STATE);
	}

	return s32ReturnStatus;
}
void EVALP6A_vInit(void)
{

	EVALP6A_s_s32DiagStatus[EVALP6A_enKeyDiag] = STD_UNDEFINED_STATE;
	EVALP6A_s_s32DiagStatus[EVALP6A_enButtonDiag] = STD_UNDEFINED_STATE;

	EVALP6A_s_s32BranchStateID[EVALP6A_enKeyState] = STD_UNDEFINED_STATE;
	EVALP6A_s_s32BranchStateID[EVALP6A_enButtonState] = STD_UNDEFINED_STATE;

	CONFIGSIV_vGetTypeSection(&EVALP6A_s_u8TypeSection);

	ANTIGLITCH_vSetSignalState((uint16)EVALP6A_enKeyState,STD_UNDEFINED_STATE,0,0);
	ANTIGLITCH_vSetSignalState((uint16)EVALP6A_enButtonState,STD_UNDEFINED_STATE,0,0);

	EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrLeftBranch,EVALP6A_nCLOSED_BRANCH);
	EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrRightBranch,EVALP6A_nCLOSED_BRANCH);
	EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrCommonBranch,EVALP6A_nCLOSED_BRANCH);
	EVALP6A_vCloseBranch((uint16)EVALP6A_enNxtLeftBranch,EVALP6A_nOPEN_BRANCH);
	EVALP6A_vCloseBranch((uint16)EVALP6A_enNxtRightBranch,EVALP6A_nOPEN_BRANCH);
	EVALP6A_vCloseBranch((uint16)EVALP6A_enNxtCommonBranch,EVALP6A_nOPEN_BRANCH);

	DIOMUX_vSetState((uint16)EVALP6a_enLfBrRedLED,ON);
	DIOMUX_vSetState((uint16)EVALP6a_enRtBrRedLED,ON);
	DIOMUX_vSetState((uint16)EVALP6a_enCmBrRedLED,ON);

	EVALP6A_s_s32StatusLEDS = EVALP6A_s32LedStatus();
	SHMEM_vSetVar((uint16)EVALP6A_nBRANCH_SHARED_STATE_ID_cfg,&EVALP6A_s_s32StatusLEDS,sizeof(EVALP6A_s_s32StatusLEDS),(uint32*)NULL);

}
void EVALP6A_vCloseBranch(uint16 u16SelectBranch,uint8 u8BranchState)
{

		if(u16SelectBranch < EVALP6A_LIMIT_ACTUAL)
		{
			if((u8BranchState == EVALP6A_nOPEN_BRANCH) || (u8BranchState == EVALP6A_nCLOSED_BRANCH))
			{
				EVALP6A_s_u8Branches[u16SelectBranch] = u8BranchState;

			}
			else
			{
				ASSERT_HARD_ERROR((u8BranchState == EVALP6A_nOPEN_BRANCH) || (u8BranchState == EVALP6A_nCLOSED_BRANCH),E_INVALID_STATE);
			}
		}
		else
		{
			ASSERT_HARD_ERROR(u16SelectBranch < EVALP6A_LIMIT_ACTUAL,E_INVALID_STATE);
		}
		if((u16SelectBranch < EVALP6A_LIMIT_NXT) && (u16SelectBranch >= EVALP6A_LIMIT_ACTUAL))
		{
			switch(EVALP6A_s_u8TypeSection)
				{
				case CONFIGSIV_enBi:
					 if((u16SelectBranch == (uint16)EVALP6A_enNxtLeftBranch) || (u16SelectBranch == (uint16)EVALP6A_enNxtRightBranch))
					 {
						 EVALP6A_s_u8Branches[u16SelectBranch] = u8BranchState;
					 }
					 else
					 {
						 ASSERT_HARD_ERROR(((u16SelectBranch == (uint16)EVALP6A_enNxtLeftBranch) || (u16SelectBranch == (uint16)EVALP6A_enNxtRightBranch)),E_INVALID_STATE);
					 }
				break;
				case CONFIGSIV_enEn:
					if(u16SelectBranch == (uint16)EVALP6A_enNxtCommonBranch)
					{
						EVALP6A_s_u8Branches[u16SelectBranch] = u8BranchState;
					}
					else
					{
						ASSERT_HARD_ERROR((u16SelectBranch == (uint16)EVALP6A_enNxtCommonBranch),E_INVALID_STATE);
					}
				break;

				default:
					ASSERT_HARD_ERROR(EVALP6A_s_u8TypeSection < (uint8)CONFIGSIV_enTOTAL_TYPE_SECTION,E_INVALID_STATE);

				break;
				}
		}
		else
		{
			ASSERT_HARD_ERROR((u16SelectBranch < EVALP6A_LIMIT_NXT) && (u16SelectBranch >= EVALP6A_LIMIT_ACTUAL),E_INVALID_STATE);
		}



}
uint8 EVALP6A_u8Get(uint16 u16SelectBranch)
{
	uint8 u8ReturnStatus=0;

	if(u16SelectBranch < (uint16)EVALP6A_enTotalBranches)
	{
		u8ReturnStatus = EVALP6A_s_u8Branches[u16SelectBranch];
	}
	else
	{
		ASSERT_HARD_ERROR(u16SelectBranch < (uint16)EVALP6A_enTotalBranches,E_INVALID_STATE	);
	}

	return u8ReturnStatus;

}
void EVALP6A_vMonitor(void)
{
	(void)ANTIGLITCH_s32GetSignalState((uint16)EVALP6A_enButtonState,&EVALP6A_s_s32BranchStateID[EVALP6A_enButtonState]);

	(void)ANTIGLITCH_s32GetSignalState((uint16)EVALP6A_enKeyState,&EVALP6A_s_s32BranchStateID[EVALP6A_enKeyState]);

	EVALP6A_s_s32DiagStatusBranch = EVALP6A_s32Diag((uint16)EVALP6A_enKeyDiag,&EVALP6A_s_s32MemoryDiagKey);
	EVALP6A_s_s32DiagStatusButton = EVALP6A_s32Diag((uint16)EVALP6A_enButtonDiag,&EVALP6A_s_s32MemoryDiagButton);


	if(EVALP6A_s_s32DiagStatusButton != STD_UNDEFINED_STATE)
	{

		if((EVALP6A_s_s32DiagStatusButton == E_NOT_OK) || (EVALP6A_s_s32DiagStatusBranch == E_NOT_OK))
		{
			EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrLeftBranch,EVALP6A_nCLOSED_BRANCH);
			EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrRightBranch,EVALP6A_nCLOSED_BRANCH);
			EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrCommonBranch,EVALP6A_nCLOSED_BRANCH);

			DIOMUX_vSetState((uint16)EVALP6a_enLfBrRedLED,ON);
			DIOMUX_vSetState((uint16)EVALP6a_enRtBrRedLED,ON);
			DIOMUX_vSetState((uint16)EVALP6a_enCmBrRedLED,ON);

			EVALP6A_s_s32StatusLEDS = EVALP6A_s32LedStatus();
			SHMEM_vSetVar((uint16)EVALP6A_nBRANCH_SHARED_STATE_ID_cfg,&EVALP6A_s_s32StatusLEDS,sizeof(EVALP6A_s_s32StatusLEDS),(uint32*)NULL);

		}
		else
		{
			/*Nothing to do*/
		}

		if((EVALP6A_s_s32DiagStatusButton == E_OK) && (EVALP6A_s_s32DiagStatusBranch == E_OK))
		{
			switch(EVALP6A_s_s32MemoryDiagKey)
			{
				case EVALP6a_enBRANCH_CLOSED:

					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrLeftBranch,EVALP6A_nCLOSED_BRANCH);
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrRightBranch,EVALP6A_nCLOSED_BRANCH);
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrCommonBranch,EVALP6A_nCLOSED_BRANCH);

					DIOMUX_vSetState((uint16)EVALP6a_enLfBrRedLED,ON);
					DIOMUX_vSetState((uint16)EVALP6a_enRtBrRedLED,ON);
					DIOMUX_vSetState((uint16)EVALP6a_enCmBrRedLED,ON);
				break;
				case EVALP6a_enBRANCH_LEFT:
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrLeftBranch,EVALP6A_nCLOSED_BRANCH);
					DIOMUX_vSetState((uint16)EVALP6a_enLfBrRedLED,ON);
				break;

				case EVALP6a_enBRANCH_RIGHT:
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrRightBranch,EVALP6A_nCLOSED_BRANCH);
					DIOMUX_vSetState((uint16)EVALP6a_enRtBrRedLED,ON);
				break;

				case EVALP6a_enBRANCH_COMMON:
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrCommonBranch,EVALP6A_nCLOSED_BRANCH);
					DIOMUX_vSetState((uint16)EVALP6a_enCmBrRedLED,ON);
				break;

				case EVALP6a_enBRANCH_OPEN:
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrLeftBranch,EVALP6A_nOPEN_BRANCH);
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrRightBranch,EVALP6A_nOPEN_BRANCH);
					EVALP6A_vCloseBranch((uint16)EVALP6A_enCurrCommonBranch,EVALP6A_nOPEN_BRANCH);

					DIOMUX_vSetState((uint16)EVALP6a_enLfBrRedLED,OFF);
					DIOMUX_vSetState((uint16)EVALP6a_enRtBrRedLED,OFF);
					DIOMUX_vSetState((uint16)EVALP6a_enCmBrRedLED,OFF);
				break;

				default:
				/*nothing to do*/
				break;
			}

		}
		else
		{
			/*Nothing to do*/
		}

		switch(EVALP6A_s_u8TypeSection)
		{
		case CONFIGSIV_enBi:
			 (void)EVALP6A_u8Get((uint16)EVALP6A_enNxtLeftBranch);
			 (void)EVALP6A_u8Get((uint16)EVALP6A_enNxtRightBranch);
		break;

		case CONFIGSIV_enEn:
			 (void)EVALP6A_u8Get((uint16)EVALP6A_enNxtCommonBranch);

		break;

		default:
			/*Nothing to do*/

		break;
		}


	}
	else
	{
		/*Nothing to do*/
	}
	EVALP6A_s_s32StatusLEDS = EVALP6A_s32LedStatus();
	SHMEM_vSetVar((uint16)EVALP6A_nBRANCH_SHARED_STATE_ID_cfg,&EVALP6A_s_s32StatusLEDS,sizeof(EVALP6A_s_s32StatusLEDS),(uint32*)NULL);

}

sint32 EVALP6A_s32LedStatus(void) /*Orden de los leds RT,CM,LF*/
{
	sint32 s32Result=0;
	sint32 s32Status=0;

	s32Result = DIOMUX_s32GetState((uint16)EVALP6a_enLfBrRedLED);

	s32Status |= (s32Result<<2);
	s32Result = 0;

	s32Result = DIOMUX_s32GetState((uint16)EVALP6a_enCmBrRedLED);

	s32Status |= (s32Result<<1);
	s32Result = 0;

	s32Result = DIOMUX_s32GetState((uint16)EVALP6a_enRtBrRedLED);

	s32Status |= (s32Result<<0);

	return s32Status;


}

/* EOF */
