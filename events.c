/*
 * events.c
 *
 *  Created on: 27 ????? 2021
 *      Author: cellium
 */



#include <stdint.h>
#include <stddef.h>
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
#include <ti_printf.h>




typedef struct events {
   List_Elem elem;
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


Events ev;
Events ev2;

void *eventsThread(void *arg0){

List_List listEvents;


strcpy(ev.EventId,"test1");
strcpy(ev2.EventId,"test2");
Events *evPtr;
Events *evPtr2;

List_clearList(&listEvents); //Function to initialize the contents of a List_List.
List_put(&listEvents, (List_Elem *)&ev); //Function to atomically put an elem onto the end of a linked list.
List_put(&listEvents, (List_Elem *)&ev2);
evPtr = (Events *)List_get(&listEvents); //Function to atomically get the first elem in a linked list.
evPtr2=(Events*) evPtr->elem.next;

Task_sleep(50 * (1000 / Clock_tickPeriod));


}




