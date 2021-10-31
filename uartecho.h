/*
 * uartecho.h
 *
 *  Created on: 26 ????? 2021
 *      Author: cellium
 */

#ifndef UARTECHO_H_
#define UARTECHO_H_

#include <stdint.h>
#include <stdbool.h>

#include <stddef.h>
#include <string.h>

/* Driver Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/NVS.h>
#include <ti/drivers/nvs/NVSRAM.h>
/* Driver configuration */
#include "ti_drivers_config.h"
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti_printf.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti_utils.h>


void uart_write_string(const char *buff, size_t size);
void uart_write_string2(const char * buff,size_t size);
void uart_read_string( char * buff,size_t size);
void init_echo(Semaphore_Handle* handle);

unsigned int convertStrUint(char *st);
int hex2int(char ch);
char int2hex(unsigned long num, char *outbuf);

#endif /* UARTECHO_H_ */
