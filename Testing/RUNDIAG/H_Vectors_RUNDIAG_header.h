
#ifndef SITRMAP010_H_
#define SITRMAP010_H_

/* system headers */

/* own headers */

/*****************************************************************************/
/* helper macros */

/* exported variables */

/* exported functions */
void HSINT_MAP010(uint16 u16Component, uint8 u8RunBlock);

void HSINT_MAP010_CTRL(uint16 u16Component, uint8 u8RunBlock);

void HSINT_MAP010_SET(uint16 u16Component, uint8 u8RunBlock);

void HSINT_MAP010_CHK(uint16 u16Component, uint8 u8RunBlock);

extern void HSINT_MAP010_PT_RTMC_IAP033_01(uint16 u16Component, uint16 u16TestType);

extern void HSINT_MAP010_PT_RTMC_IAP032_01(uint16 u16Component, uint16 u16TestType);

#endif /* FILENAME_H_ */
