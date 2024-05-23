

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* system headers */

/* used headers */
#include <tms570/vim.h>
#include <tms570/vim_chn_ls31.h>

/* own headers */

/*****************************************************************************/

/* exported configuration macros */
#define UART__ISR_MAPPED_TO_LVL1_cfg (  SCI__SETINTLVL_SET_TX_MASK | \
                                        SCI__SETINTLVL_SET_RX_MASK)

#define UART__ISR0_VIM_cfg  (VIM_LIN_Level_1)
#define UART__ISR1_VIM_cfg  (VIM_LIN_Level_1)

#define SCI_MULTIBUFFER_LENGHT_cfg			(7)

#define SCI_FIRST_BYTE_MASK					(0xFF)
#define SCI_SECOND_BYTE_MASK				(0xFF00)
#define SCI_THIRD_BYTE_MASK					(0xFF0000)
#define SCI_FOURTH_BYTE_MASK				(0xFF000000)
/* exported types */

/* exported variables */

/* exported functions */

#endif /* UART_CONFIG_H_ */
