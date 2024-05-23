

#ifndef HSITRMAP028_H_
#define HSITRMAP028_H_

/* system headers */

/* own headers */

/*****************************************************************************/
/* helper macros */

/* exported variables */

/* exported functions */
extern void HSINT_MAP028_SET(uint16 u16Component, uint8 u8RunBlock);
extern void HSINT_MAP028_CHK(uint16 u16Component, uint8 u8RunBlock);
extern void HSINT_MAP028(uint16 u16Component, uint8 u8RunBlock);
extern void HSINT_MAP028_PT_RTMC_IAP034_1(uint16 u16Component, uint16 u16TestType);
extern void HSINT_MAP028_PT_RTMC_IAP035_1(uint16 u16Component, uint16 u16TestType);

#endif /* HSITRMAP028_H_ */
