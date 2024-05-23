

#ifndef FLASH_API_H_
#define FLASH_API_H_

/* system headers */

#include "Std_Types.h"

/* used headers */

#include "F021.h"
#include "F021_FMC_BE.h"

/* own headers */

/****************************************************************************************/

/* exported configuration macros */

#define FLASH__API_CPU_ADDRESS F021_CPU0_BASE_ADDRESS /* Library registers base address */

#define FLASH__API_BANK0 (uint8)Fapi_FlashBank0 /* Bank for program and/or data storage */
#define FLASH__API_BANK1 (uint8)Fapi_FlashBank1 /* Bank for program and/or data storage */ 
#define FLASH__API_BANK7 (uint8)Fapi_FlashBank7 /* Bank for Flash EEPROM Emulation*/

#define FLASH__API_OK            (uint16)Fapi_Status_Success
#define FLASH__API_ERROR         (uint16)Fapi_Error_Fail
#define FLASH__API_BUSY          (uint16)Fapi_Status_FsmBusy
#define FLASH__API_READY         (uint16)Fapi_Status_FsmReady                                              
#define FLASH__API_ERROR_ADDRESS (uint16)Fapi_Error_InvalidAddress
#define FLASH__API_ERROR_LENGTH  (uint16)Fapi_Error_AsyncIncorrectDataBufferLength

#define FLASH__vAPIInit(x,y)                   Fapi_initializeAPI(x,y)
#define FLASH__vAPISetActiveBank(x)            Fapi_setActiveFlashBank((Fapi_FlashBankType) x)
#define FLASH__vAPISetActiveNonEEPROMSectors() Fapi_setupBankSectorEnable()
#define FLASH__vAPISetActiveEEPROMSectors()    Fapi_setupEepromSectorEnable()
#define FLASH__vAPIFlushFMCBuffers()           Fapi_flushPipeline()
#define FLASH__vAPIEraseSector(x)              Fapi_issueAsyncCommandWithAddress(Fapi_EraseSector, (uint32 *) x);

#define FLASH__vAPIWriteCommand(x,y,z) Fapi_issueProgrammingCommand((uint32 *) x, (uint8 *) y, z, 0, 0, Fapi_DataOnly)
#define FLASH__vAPIReadCommand(x,y,z)  Fapi_doMarginReadByByte((uint8 *) x, y, z, Fapi_NormalRead)

#define FLASH__u16APICheckFsmForReady() (uint16)Fapi_checkFsmForReady()

/* exported types */

/* exported variables */

/* exported functions */

#endif /* FLASH_API_H_ */
