/*
 * crs_events_writer.c
 *
 *  Created on: 28 ????? 2021
 *      Author: cellium
 */


#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include <string.h>

#include <led.h>
/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/apps/LED.h>
#include <ti/drivers/utils/List.h>

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
#include <crs_events_manager.h>



void *events_writerThread(void *arg0){


}
