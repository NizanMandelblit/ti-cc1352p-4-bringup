/*
 * events.c
 *
 *  Created on: 27 ????? 2021
 *      Author: cellium
 */



#include <stdint.h>
#include <stddef.h>
#include <led.h>
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


struct events {
   char  EventId[50];
   char  EventType[50];
   char  EventTime[100];
   int   probableCause;
   char  perceivedSeverity[100];
   char  ManagedObjectInstance[100];
   char  serviceDesruptive[100];
   char  notificationIdentifier [100];
   char  AdditionalText[100];
   char  AdditionalInformation[100];
   char  ProposedRepairActions[100];
} Events;


void *eventsThread(void *arg0){



}




