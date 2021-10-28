/*
 * crs_events_manager.h
 *
 *  Created on: 28 ????? 2021
 *      Author: cellium
 */

#ifndef CRS_EVENTS_MANAGER_H_
#define CRS_EVENTS_MANAGER_H_


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



void *eventsThread(void *arg0);

#endif /* CRS_EVENTS_MANAGER_H_ */
