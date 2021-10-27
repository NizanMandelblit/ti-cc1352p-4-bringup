/*
 * ti_printf.h
 *
 *  Created on: 26 ????? 2021
 *      Author: cellium
 */

#ifndef TI_PRINTF_H_
#define TI_PRINTF_H_


//#include <stdint.h>
//#include <stdbool.h>
//
//#include <stddef.h>
//#include <string.h>

/* Driver Header files */
//#include <ti/drivers/GPIO.h>
//#include <ti/drivers/UART.h>
//#include <ti/drivers/NVS.h>
//#include <ti/drivers/nvs/NVSRAM.h>
///* Driver configuration */
//#include "ti_drivers_config.h"
//#include <ti/sysbios/knl/Clock.h>
//#include <ti/sysbios/knl/Task.h>
#include <uartecho.h>


int bm_printf(const char *fmt, ...);


#endif /* TI_PRINTF_H_ */
