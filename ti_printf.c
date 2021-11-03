/*
 * ti_printf.c
 *
 *  Created on: 21 ????? 2021
 *      Author: cellium
 */


#include <ti_printf.h>
#include <ti/drivers/dpl/SystemP.h>

/* PRINTF IMPL    */

int bm_printf(const char *fmt, ...)
{
  char buf[200]={'\0'};
  va_list args;
  va_start(args, fmt);
  SystemP_vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);


  uart_write_string2(buf,strlen(buf));

}
