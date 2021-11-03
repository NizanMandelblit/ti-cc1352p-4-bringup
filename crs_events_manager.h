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

typedef struct crs_events {
   uint32_t  EventId;
   uint8_t  EventType;
   uint32_t  EventTime;//---NEED TO CHECK HOW MUCH BITS ARE NEDDED!   uint32_t time= Timestamp_get32();
   uint32_t  ManagedObjectClass;
   uint16_t  ManagedObjectInstance;
   uint8_t  perceivedSeverity;
   uint32_t  AdditionalInformation[3];
} crs_Events;


void *eventsThread(void *arg0);
#define MAX_CRS_EVENTS_SLOTS 200

#endif /* CRS_EVENTS_MANAGER_H_ */
