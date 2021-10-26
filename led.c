/*
 * led.c
 *
 *  Created on: 21 ????? 2021
 *      Author: cellium
 */


#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/apps/LED.h>

/* Driver configuration */
#include "ti_drivers_config.h"

#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>
#include <ti/display/AnsiColor.h>
#define MAXPRINTLEN 128
/* XDC module Headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti_printf.h>

void *ledThread(void *arg0){
while(1){
//    bm_printf("led thread!\r\n");

    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_LED_OFF);
//    myDelay(12000000); /* Pretend to do something useful but time-consuming */
    Task_sleep(1000 * (1000 / Clock_tickPeriod));
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_LED_ON);
    Task_sleep(50 * (1000 / Clock_tickPeriod));

}


}
