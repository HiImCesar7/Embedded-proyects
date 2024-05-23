
/* system headers */

#include "Std_Types.h"

/* used headers */

/* own headers */

#include "FLASH_reg.h"
#include "FLASH_API.h"
#include "FLASH.h"
#include "FLASH_config.h"

/*[EXPORTED]*****************************************************************************/

/* public_variables */

/*[INTERNAL]*****************************************************************************/

/* internal__pre-processor macros */

/* FLASH__nRWAIT = Wait cycles to read/write program/data Flash memory */
/* FLASH__nEWAIT = Wait cycles to read/write data (EEPROM) Flash memory */

#if   ((FLASH__nHCLK_FREQUENCY_cfg > 0  ) && (FLASH__nHCLK_FREQUENCY_cfg <= 45 ))
    #define FLASH__nRWAIT (0) 
    #define FLASH__nEWAIT (0) 
#elif ((FLASH__nHCLK_FREQUENCY_cfg > 45 ) && (FLASH__nHCLK_FREQUENCY_cfg <= 90 ))
    #define FLASH__nRWAIT (1) 
    #define FLASH__nEWAIT (1) 
#elif ((FLASH__nHCLK_FREQUENCY_cfg > 90 ) && (FLASH__nHCLK_FREQUENCY_cfg <= 135))
    #define FLASH__nRWAIT (2) 
    #define FLASH__nEWAIT (2) 
#else
    #define FLASH__nRWAIT (3) 
    #define FLASH__nEWAIT (3) 
#endif

#define FLASH__MEMORY_SECTORS_TABLE                                   \
{  /* Sector Low Address  Sector Size (Bytes)     Sector Name      */ \
     {0x00000000,         0x00007FFF}, /*  32KB - Bank 0 Sector  0 */ \
     {0x00008000,         0x00007FFF}, /*  32KB - Bank 0 Sector  1 */ \
     {0x00010000,         0x00007FFF}, /*  32KB - Bank 0 Sector  2 */ \
     {0x00018000,         0x00007FFF}, /*  32KB - Bank 0 Sector  3 */ \
     {0x00020000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  4 */ \
     {0x00040000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  5 */ \
     {0x00060000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  6 */ \
     {0x00080000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  7 */ \
     {0x000A0000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  8 */ \
     {0x000C0000,         0x0001FFFF}, /* 128KB - Bank 0 Sector  9 */ \
     {0x000E0000,         0x0001FFFF}, /* 128KB - Bank 0 Sector 10 */ \
     {0x00100000,         0x0001FFFF}, /* 128KB - Bank 0 Sector 11 */ \
     {0x00120000,         0x0001FFFF}, /* 128KB - Bank 0 Sector 12 */ \
     {0x00140000,         0x0001FFFF}, /* 128KB - Bank 0 Sector 13 */ \
     {0x00160000,         0x0001FFFF}, /* 128KB - Bank 0 Sector 14 */ \
     {0x00180000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  0 */ \
     {0x001A0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  1 */ \
     {0x001C0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  2 */ \
     {0x001E0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  3 */ \
     {0x00200000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  4 */ \
     {0x00220000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  5 */ \
     {0x00240000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  6 */ \
     {0x00260000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  7 */ \
     {0x00280000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  8 */ \
     {0x002A0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector  9 */ \
     {0x002C0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector 10 */ \
     {0x002E0000,         0x0001FFFF}, /* 128KB - Bank 1 Sector 11 */ \
     {0xF0200000,         0x00003FFF}, /*  16KB - Bank 7 Sector  0 */ \
     {0xF0204000,         0x00003FFF}, /*  16KB - Bank 7 Sector  1 */ \
     {0xF0208000,         0x00003FFF}, /*  16KB - Bank 7 Sector  2 */ \
     {0xF020C000,         0x00003FFF}  /*  16KB - Bank 7 Sector  3 */ \
}

/* This constant defines the number of sectors of the EEPROM memory */
#define FLASH__nTOTAL_SECTORS_NBR (31) 

#define FLASH__nEEPROM_SECTOR_SIZE_IN_BYTES (16384) 

/* This constant defines the maximum number of bytes to read or write at once */
#define FLASH__nBANK_WIDTH_IN_BYTES (16)

#define FLASH__BANK0_PROGRAM (FLASH__API_BANK0)
#define FLASH__BANK1_PROGRAM (FLASH__API_BANK1)
#define FLASH__BANK7_EEPROM (FLASH__API_BANK7)

/* Bank�s memory ranges */
#define FLASH__BANK0_START_ADDRESS (FLASH__astMemorySectors[0].u32StartAddress)
#define FLASH__BANK0_END_ADDRESS   (FLASH__astMemorySectors[14].u32StartAddress + \
                                    FLASH__astMemorySectors[14].u32SizeInBytes)

#define FLASH__BANK1_START_ADDRESS (FLASH__astMemorySectors[15].u32StartAddress)
#define FLASH__BANK1_END_ADDRESS   (FLASH__astMemorySectors[26].u32StartAddress + \
                                    FLASH__astMemorySectors[26].u32SizeInBytes)

#define FLASH__BANK7_START_ADDRESS (FLASH__astMemorySectors[27].u32StartAddress)
#define FLASH__BANK7_END_ADDRESS   (FLASH__astMemorySectors[30].u32StartAddress + \
                                    FLASH__astMemorySectors[30].u32SizeInBytes)
                                      
/* Backup sector: EEPROM sector 3 */ 
#define FLASH__BACKUP_SECTOR_START_ADDRESS (FLASH__astMemorySectors[30].u32StartAddress) 

/* Read Flash address range */
#define FLASH__READ_START_ADDRESS (FLASH__astMemorySectors[0].u32StartAddress)
#define FLASH__READ_END_ADDRESS   (FLASH__astMemorySectors[30].u32StartAddress + \
                                   FLASH__astMemorySectors[30].u32SizeInBytes)

/* Write Flash address range: EEPROM from sector 0 to sector 2 
  (no backup sector is used for write on it) */
#define FLASH__WRITE_START_ADDRESS (FLASH__astMemorySectors[27].u32StartAddress)
#define FLASH__WRITE_END_ADDRESS   (FLASH__astMemorySectors[29].u32StartAddress + \
                                    FLASH__astMemorySectors[29].u32SizeInBytes)

#define FLASH__unlock_registers() pstFLASHReg->FSM_WR_ENA = FLASH__FSM_WR_ENA_WR_ENA(5);
#define FLASH__lock_registers()   pstFLASHReg->FSM_WR_ENA = FLASH__FSM_WR_ENA_WR_ENA(2);
#define FLASH__set_rwait(x)       pstFLASHReg->FRDCNTL = FLASH__FRDCNTL_RWAIT(x)       | \
                                                         FLASH__FRDCNTL_ASWSTEN_MASK   | \
                                                         FLASH__FRDCNTL_ENPIPE_MASK
#define FLASH__set_ewait(x) pstFLASHReg->EEPROM_CONFIG = FLASH__EEPROM_CONFIG_EWAIT(x) | \
                                                         FLASH__EEPROM_CONFIG_AUTOSTART_GRACE(2)                                                                
/* internal__types */

typedef struct
{
    uint32 u32StartAddress;
    uint32 u32SizeInBytes;
}FLASH__tstMemorySector;
                          
/* static function prototypes */

static uint8  FLASH__u8GetDriverStatus(uint16 u16APIStatus);
static uint32 FLASH__u32GetSectorStartAddress(uint32 u32Address);
static uint8  FLASH__u8GetBank(uint32 u32Address);
static void   FLASH__vWait(void);
static void   FLASH__vEraseSector(uint32 u32Address);
static void   FLASH__vDoSectorBackup(uint32 u32Address);
static void   FLASH__vCopyNewBuffer(uint8* pu8Buffer, uint8 u8Length);
static void   FLASH__vWriteNewBuffer(uint32 u32Address, uint8 u8Length);
static void   FLASH__vDoSectorRecovery(uint32 u32Address, uint8 u8Length);
static uint8  FLASH__u8ValidateAddress(uint32 u32Address, uint8 u8Length, bool bWriteFlag);
static uint8  FLASH__u8ValidatePointer(uint8* pu8Buffer);
static uint8  FLASH__u8ValidateLength(uint8 u8Length);
static uint8  FLASH__u8ValidateCmd(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length, bool bWriteFlag);
                                                                                                                                                  
/* private__variables */

static FLASH__tstMemorySector FLASH__astMemorySectors[FLASH__nTOTAL_SECTORS_NBR] = 
                              FLASH__MEMORY_SECTORS_TABLE;

/* This buffer stores data to be writen */                                                                 
static uint8 FLASH__au8RAMBuffer[FLASH__nMAX_RW_BYTES_cfg]; 

/* private__functions */

/** 
 * @fn     FLASH__u8GetDriverStatus(uint16 u16APIStatus)
 * @brief  Get API (Flash Library F021 v1.5) funtions status
 * @param  u16APIStatus - Satatus returned by API function
 * @return FLASH_E_OK
 * @return FLASH_E_BUSY
 * @return FLASH_E_READY
 * @return FLASH_E_ERROR
 */
static uint8 FLASH__u8GetDriverStatus(uint16 u16APIStatus)
{
   uint8 u8DriverStatus;
   
   switch (u16APIStatus)
   {
      case FLASH__API_OK:
         u8DriverStatus = FLASH_E_OK;
         break;
      case FLASH__API_BUSY:
         u8DriverStatus = FLASH_E_BUSY;
         break;
      case FLASH__API_READY:
         u8DriverStatus = FLASH_E_READY;
         break;
      default:
         u8DriverStatus = FLASH_E_ERROR;
         break;
   }
   
   return u8DriverStatus;
}

/** 
 * @fn     FLASH__u32GetSectorStartAddress(uint32 u32Address)
 * @brief  Get starting address of affected sector depending on memory address
 * @param  u32Address - Memory address where FLASH starts reading or writing
 * @return Any sector low address
 */
static uint32 FLASH__u32GetSectorStartAddress(uint32 u32Address)
{
   uint8 u8Index;
   uint32 u32SectorStartAddress;
   
   for (u8Index = 0; 
        u8Index < FLASH__nTOTAL_SECTORS_NBR; 
        u8Index++)
   {       
      if ((u32Address >= FLASH__astMemorySectors[u8Index].u32StartAddress)&&
          (u32Address <= FLASH__astMemorySectors[u8Index].u32StartAddress + 
                         FLASH__astMemorySectors[u8Index].u32SizeInBytes))
      {
         u32SectorStartAddress = FLASH__astMemorySectors[u8Index].u32StartAddress;
         break;
      }
      else
      {
         /* Nothing to do */
      }
   } 
                                                                                                
   return u32SectorStartAddress;
}

/** 
 * @fn     FLASH__u8GetBank(uint32 u32Address)
 * @brief  Get banck name depending on address memory
 * @param  u32Address - Memory address where FLASH starts reading or writing
 * @return FLASH__API_BANK0
 * @return FLASH__API_BANK1
 * @return FLASH__API_BANK2
 */
static uint8 FLASH__u8GetBank(uint32 u32Address)
{
   uint8 u8APIBank;
   
   if ((u32Address >= FLASH__BANK0_START_ADDRESS) && 
       (u32Address <= FLASH__BANK0_END_ADDRESS  ))
   {
      /* Memory for Program and/or data */
      u8APIBank = FLASH__BANK0_PROGRAM;
   }
   else if ((u32Address >= FLASH__BANK1_START_ADDRESS) && 
            (u32Address <= FLASH__BANK1_END_ADDRESS  ))
   {
      /* Memory for Program and/or data */
      u8APIBank = FLASH__BANK1_PROGRAM;
   }
   else if ((u32Address >= FLASH__BANK7_START_ADDRESS) && 
            (u32Address <= FLASH__BANK7_END_ADDRESS  ))
   {
      /* Memory for data only (EEPROM) */
      u8APIBank = FLASH__BANK7_EEPROM;
   }
   else
   {
      /* Nothing to do */
   }
   
   return u8APIBank;
}

/** 
 * @fn     FLASH__vWait(void)
 * @brief  This function is used to wait if Flash memory 
 * @brief  controller is busy reading or writing
 * @param  None
 * @return None
 */
static void FLASH__vWait(void)
{
   uint8 u8DriverStatus;
   uint16 u16APIStatus;
   
   do
   {
      u16APIStatus = FLASH__u16APICheckFsmForReady();
      u8DriverStatus = FLASH__u8GetDriverStatus(u16APIStatus);
   }
   while(u8DriverStatus == FLASH_E_BUSY);
}

/** 
 * @fn     FLASH__vEraseSector(uint32 u32Address)
 * @brief  This function erase all contents of the sector 
 * @brief  where is a specific memory address 
 * @param  u32Address - Any sector�s memory address
 * @return None
 */
static void FLASH__vEraseSector(uint32 u32Address)
{ 
   FLASH__vAPIEraseSector(u32Address);
   FLASH__vWait();
}

/** 
 * @fn     FLASH__vDoSectorBackup(uint32 u32Address)
 * @brief  This function copies data from affected sector 
 * @brief  and data is stored in backup sector
 * @param  u32Address - Affected sector�s memory address
 * @return None
 */
static void FLASH__vDoSectorBackup(uint32 u32Address)
{
   uint16 u16Bytes;         /* Number of bytes backed up */  
   uint32 u32OffsetAddress; /* Current memory address    */
   uint32 u32BackupOffsetAddress = FLASH__BACKUP_SECTOR_START_ADDRESS;
   
   FLASH__vEraseSector(FLASH__BACKUP_SECTOR_START_ADDRESS);
   
   u32OffsetAddress = FLASH__u32GetSectorStartAddress(u32Address);
   
   for (u16Bytes = 0; 
        u16Bytes < FLASH__nEEPROM_SECTOR_SIZE_IN_BYTES; 
        u16Bytes += FLASH__nBANK_WIDTH_IN_BYTES)
   {       
      FLASH__vAPIWriteCommand(u32BackupOffsetAddress, u32OffsetAddress, FLASH__nBANK_WIDTH_IN_BYTES);
      FLASH__vWait();
      u32OffsetAddress += FLASH__nBANK_WIDTH_IN_BYTES;
      u32BackupOffsetAddress += FLASH__nBANK_WIDTH_IN_BYTES;
   }  
}

/** 
 * @fn     FLASH__vCopyNewBuffer(uint8 *pu8Buffer, uint8 u8Length)
 * @brief  This function stores new buffer in RAM array
 * @param  pu8Buffer  - Pointer to address where new data is stored
 * @param  u8Length - Number of bytes to be stored
 * @return None
 */
static void FLASH__vCopyNewBuffer(uint8* pu8Buffer, uint8 u8Length)
{
   uint8 u8Bytes;   

   for (u8Bytes = 0; u8Bytes < u8Length; u8Bytes++)
   {
     FLASH__au8RAMBuffer[u8Bytes] = pu8Buffer[u8Bytes]; 
   }
}

/** 
 * @fn     FLASH__vWriteNewBuffer(uint32 u32Address, uint8 u8Length)
 * @brief  This function write new buffer in affected sector byte by byte
 * @param  u32Address - Memory address where FLASH starts writing
 * @param  u8Length   - Number of bytes to be written
 * @return None
 */
static void FLASH__vWriteNewBuffer(uint32 u32Address, uint8 u8Length)
{
   uint8 u8Bytes;
   uint32 u32OffsetAddress = u32Address;
   
   FLASH__vEraseSector(u32Address);
   
   /* In this case, data is written byte by byte */
   for (u8Bytes = 0; u8Bytes < u8Length; u8Bytes++)
   {       
      FLASH__vAPIWriteCommand(u32OffsetAddress, &FLASH__au8RAMBuffer[u8Bytes], 1);
      FLASH__vWait();
      u32OffsetAddress++;
   }  
}

/** 
 * @fn     FLASH__vDoSectorRecovery(uint32 u32Address, uint8 u8Length)
 * @brief  This function writes last data in affected sector
 * @param  u32Address - Memory address where data were wirtten
 * @param  u8Length   - Number of bytes written
 * @return None
 */
static void FLASH__vDoSectorRecovery(uint32 u32Address, uint8 u8Length)
{
   uint16 u16Bytes = 0; /* Variable that stores number of bytes that have been written */
   uint32 u32OffsetAddress;
   uint32 u32BackupOffsetAddress = FLASH__BACKUP_SECTOR_START_ADDRESS;
   
   u32OffsetAddress = FLASH__u32GetSectorStartAddress(u32Address);
   
   /**@todo: RodDa -- Esta secci�n de c�digo puede ser optimizada al evitar realizar  
                      el primer "if" dentro del bucle do{}while(); ya que por el momento
                      se evalua esta condici�n para saber si la direcci�n destino se 
                      encuentra dentro del margen de una fila de la memoria EEPROM, si es 
                      as�, los bytes respaldados (ubicados en el sector 3) se almacenan 
                      byte por byte desde el inicio de la fila hasta la direcci�n indicada. 
                      Posteriormente las direcciones de memoria que incluyen los bytes que 
                      fueron actualizados son salteadas, pues ya contiene la nueva 
                      informaci�n, luego se completa la fila afectada escribiendo byte por
                      byte. Por �ltimo todas las filas restantes del sector son 
                      actualizadas de 16 en a6 bytes para ejecutar m�s rapidamente 
                      la escritura. */
   do
   {  
      /* if destination memory address is between bank row boundaries */
      if ((u32Address >= u32OffsetAddress)&& 
          (u32Address < (u32OffsetAddress + FLASH__nBANK_WIDTH_IN_BYTES))) 
      {  
         while(u32OffsetAddress < u32Address)
         {
            FLASH__vAPIWriteCommand(u32OffsetAddress, u32BackupOffsetAddress, 1);
            FLASH__vWait();
            u16Bytes++;
            u32OffsetAddress++;
            u32BackupOffsetAddress++;
         }
         
         u16Bytes += u8Length;
         u32OffsetAddress += u8Length;
         u32BackupOffsetAddress += u8Length;
         
         /* Resulting module = (bytes written/16) in order to know where the row end */
         /* Bank width = 16 */

         while((u16Bytes % FLASH__nBANK_WIDTH_IN_BYTES) != 0)              
         {
            FLASH__vAPIWriteCommand(u32OffsetAddress, u32BackupOffsetAddress, 1);
            FLASH__vWait();
            u16Bytes++;
            u32OffsetAddress++;
            u32BackupOffsetAddress++;
         }
      }
      else /* Wirte data 16 bytes at once */
      {
         FLASH__vAPIWriteCommand(u32OffsetAddress, u32BackupOffsetAddress, FLASH__nBANK_WIDTH_IN_BYTES);
         FLASH__vWait();
         u16Bytes += FLASH__nBANK_WIDTH_IN_BYTES;
         u32OffsetAddress += FLASH__nBANK_WIDTH_IN_BYTES;
         u32BackupOffsetAddress += FLASH__nBANK_WIDTH_IN_BYTES;
      }
   }
   while(u16Bytes < FLASH__nEEPROM_SECTOR_SIZE_IN_BYTES);
}

/** 
 * @fn     FLASH__u8ValidateAddress(uint32 u32Address, uint8 u8Length, bool bWriteFlag)
 * @brief  This function evaluates memory address parameter
 * @param  u32Address - Memory address where FLASH starts reading or writing
 * @return FLASH_E_OK
 * @return FLASH_E_ERROR_ADDRESS
 */
static uint8 FLASH__u8ValidateAddress(uint32 u32Address, uint8 u8Length, bool bWriteFlag)
{
   uint8 u8AddressStatus;

   uint32 u32LastAddress = u32Address + (u8Length - 1);

   uint32 u32StartAddress1;
   uint32 u32StartAddress2;

   uint32 u32StartAddress;
   uint32 u32EndAddress;

   if (bWriteFlag == TRUE)
   {
      u32StartAddress = FLASH__WRITE_START_ADDRESS;
      u32EndAddress = FLASH__WRITE_END_ADDRESS;
   }
   else
   {
      u32StartAddress = FLASH__READ_START_ADDRESS;
      u32EndAddress = FLASH__READ_END_ADDRESS;
   }
  
   /* If destination memory as */
   if (((u32Address >= u32StartAddress     ) && (u32Address <= u32EndAddress     )) && 
       ((u32LastAddress >= u32StartAddress) && (u32LastAddress <= u32EndAddress)))
   {
      u32StartAddress1 = FLASH__u32GetSectorStartAddress(u32Address);
      u32StartAddress2 = FLASH__u32GetSectorStartAddress(u32LastAddress);
      
      /* Check if start address and end address are in the same sector */
      if (u32StartAddress1 == u32StartAddress2) 
                                               
      {
         u8AddressStatus = FLASH_E_OK;
      }
      else
      {
         u8AddressStatus = FLASH_E_ERROR_ADDRESS;
      }
   }
   else
   {
      u8AddressStatus = FLASH_E_ERROR_ADDRESS;
   }
   
   return u8AddressStatus;
}

/** 
 * @fn     FLASH__u8ValidatePointer(uint8* pu8Buffer)
 * @brief  This function evaluates data buffer pointer
 * @param  pu8Buffer - Pointer to data buffer
 * @return FLASH_E_OK
 * @return FLASH_E_ERROR_POINTER
 */
static uint8 FLASH__u8ValidatePointer(uint8* pu8Buffer)
{
   uint8 u8PointerStatus;
   
   if (pu8Buffer != NULL)
   {
      u8PointerStatus = FLASH_E_OK;
   }
   else
   {
      u8PointerStatus = FLASH_E_ERROR_POINTER;
   }
   
   return u8PointerStatus;
}

/** 
 * @fn     FLASH__u8ValidateLength(uint8 u8Length)
 * @brief  This function evaluates number of bytes parameter
 * @param  u8Length - Number of bytes to read or write
 * @return FLASH_E_OK
 * @return FLASH_E_ERROR_LENGTH
 */
static uint8 FLASH__u8ValidateLength(uint8 u8Length)
{
   uint8 u8LengthStatus;
   
   if (u8Length <= FLASH__nMAX_RW_BYTES_cfg)
   {
      u8LengthStatus = FLASH_E_OK;
   }
   else
   {
      u8LengthStatus = FLASH_E_ERROR_LENGTH;
   }
   
   return u8LengthStatus;
}

/** 
 * @fn     FLASH__u8ValidateCmd(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length, bool bWriteFlag)
 * @brief  This function evaluates input parameters before to 
 * @brief  perform a read or write operation
 * @param  u32Address - Memory address where FLASH starts reading or writing
 * @param  u8Length   - Number of bytes to read or write
 * @return FLASH_E_OK
 * @return FLASH_E_ERROR_ADDRESS
 * @return FLASH_E_ERROR_LENGTH
 * @return FLASH_E_ERROR_POINTER
 */
static uint8 FLASH__u8ValidateCmd(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length, bool bWriteFlag)
{
   uint8 u8CmdStatus;
   uint8 u8AddressStatus;
   uint8 u8PointerStatus;
   uint8 u8LengthStatus;
   
   u8AddressStatus = FLASH__u8ValidateAddress(u32Address, u8Length, bWriteFlag);
   u8PointerStatus = FLASH__u8ValidatePointer(pu8Buffer);
   u8LengthStatus = FLASH__u8ValidateLength(u8Length);

   /* If an exception has occurred */
   if ((u8AddressStatus != FLASH_E_OK) || /* Wrong address       */
       (u8PointerStatus != FLASH_E_OK) || /* Null data pointer   */
       (u8LengthStatus  != FLASH_E_OK))   /* Wrong buffer length */
   {
      if (u8AddressStatus != FLASH_E_OK)
      {
         u8CmdStatus = u8AddressStatus;
      }
      else if (u8PointerStatus != FLASH_E_OK)
      {
         u8CmdStatus = u8PointerStatus;
      }
      else
      {
         u8CmdStatus = u8LengthStatus;
      }
   }
   else
   {
      u8CmdStatus = FLASH_E_OK;                     
   }
   
   return u8CmdStatus;
}

/* public_functions */

/** 
 * @fn     FLASH_vInit(void)
 * @brief  This function configures Flash memory controller registers to initialize 
 * @brief  Flash module.
 * @return None
 */
void FLASH_vInit(void)
{
   FLASH__tstMemMap* pstFLASHReg = NULL; /* Create pointer to access Flash
                                            memory controller registers */
   pstFLASHReg = (void*)FLASH__ADDR_PTR;
   
   FLASH__unlock_registers();
   FLASH__set_rwait(FLASH__nRWAIT);
   FLASH__set_ewait(FLASH__nEWAIT); 
   FLASH__lock_registers();
   
   FLASH__vAPIInit(FLASH__API_CPU_ADDRESS, FLASH__nHCLK_FREQUENCY_cfg);
   FLASH__vAPISetActiveNonEEPROMSectors();
   FLASH__vAPISetActiveEEPROMSectors();

   /* Restart Flash memory controller registers */
   FLASH__vAPIFlushFMCBuffers(); 
}

/** 
 * @fn     FLASH_u8ReadBuffer(uint32 u32Address, uint8 *pu8Buffer, uint8 u8Length)
 * @brief  This function reads n bytes from Flash memory
 * @param  u32Address - Memory address where FLASH starts reading
 * @param  pu8Buffer  - Pointer to a variable in RAM that stores data read
 * @param  u8Length   - Number of bytes to read
 * @return FLASH_E_OK
 * @return FLASH_E_BUSY
 * @return FLASH_E_ERROR_ADDRESS
 * @return FLASH_E_ERROR_LENGTH
 * @retunr FLASH_E_ERROR_POINTER
 */
uint8 FLASH_u8ReadBuffer(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length)
{
   uint8 u8DriverStatus;
   uint16 u16APIStatus;
   uint8 u8Bank;  

   u8DriverStatus = FLASH__u8ValidateCmd(u32Address, pu8Buffer, u8Length, FALSE);
   
   if (u8DriverStatus == FLASH_E_OK)
   {
      /* Check if driver is busy with another operation on memory */
      u16APIStatus = FLASH__u16APICheckFsmForReady(); 
                                   
      /* u16APIStatus is traduced to u8DriverStatus */
      u8DriverStatus = FLASH__u8GetDriverStatus(u16APIStatus); 
                                                                  
      if (u8DriverStatus == FLASH_E_READY)
      {  
         /* Activate respective bank */ 
         u8Bank = FLASH__u8GetBank(u32Address);
         FLASH__vAPISetActiveBank(u8Bank);

         /* Restart Flash memory controller registers */
         FLASH__vAPIFlushFMCBuffers(); 

         FLASH__vAPIReadCommand(u32Address, pu8Buffer, u8Length);
         
         u8DriverStatus = FLASH_E_OK;
      }
      else
      {
         /* Nothing to do */
      }        
   }
   else
   {
      /* Nothing to do */
   }
   
   return u8DriverStatus;
}

/** 
 * @fn     FLASH_u8WriteBuffer(uint32 u32Address, uint8 *pu8Buffer, uint8 u8Length)
 * @brief  This function writes "n" bytes in Flash memory (EEPROM)
 * @param  u32Address - Memory address where FLASH starts writing
 * @param  pu8Buffer  - Pointer to a variable in RAM that stores new data
 * @param  u8Length   - Number of bytes to write
 * @return FLASH_E_OK
 * @return FLASH_E_BUSY
 * @return FLASH_E_ERROR_ADDRESS
 * @return FLASH_E_ERROR_LENGTH
 * @return FLASH_E_ERROR_POINTER
 */
uint8 FLASH_u8WriteBuffer(uint32 u32Address, uint8* pu8Buffer, uint8 u8Length)
{
   uint8 u8DriverStatus;
   uint16 u16APIStatus;
   
   u8DriverStatus = FLASH__u8ValidateCmd(u32Address, pu8Buffer, u8Length, TRUE);
   
   if (u8DriverStatus == FLASH_E_OK)
   {
      /* Check if driver is busy with another operation on memory */
      u16APIStatus = FLASH__u16APICheckFsmForReady(); 
                               
      /* u16APIStatus (form "F021 library") is traduced to u8DriverStatus */
      u8DriverStatus = FLASH__u8GetDriverStatus(u16APIStatus);
                                                                  
      if (u8DriverStatus == FLASH_E_READY)
      {  
         /* Restart Flash memory controller registers */
         FLASH__vAPIFlushFMCBuffers(); 

         /* Activate EEPROM bank */ 
         FLASH__vAPISetActiveBank(FLASH__BANK7_EEPROM);

         /* Backup all sector�s data into backup sector */
         FLASH__vDoSectorBackup(u32Address); 
         
         /* Store new data buffer in RAM array */
         FLASH__vCopyNewBuffer(pu8Buffer, u8Length); 

         /* Erase affected sector and write new RAM data buffer */
         FLASH__vWriteNewBuffer(u32Address, u8Length);  
          
         /* Backed up data is written into affected sector again */
         FLASH__vDoSectorRecovery(u32Address, u8Length); 
                                                            
         u8DriverStatus = FLASH_E_OK; 
      }
      else
      {
         /* Nothing to do */
      }         
   }
   else
   {
      /* Nothing to do */
   }
     
   return u8DriverStatus;
}

/* EOF */