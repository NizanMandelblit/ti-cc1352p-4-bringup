/*
 * events.c
 *
 *  Created on: 27 ????? 2021
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
#include <ti_printf.h>


typedef struct events {
   List_Elem elem;
   uint32_t  EventId;
   uint8_t  EventType;
   uint8_t  EventTime[100];//---NEED TO CHECK HOW MUCH BITS ARE NEDDED!
   uint32_t  ManagedObjectClass;
   uint16_t  ManagedObjectInstance;
   uint8_t  perceivedSeverity;
   uint32_t  AdditionalInformation[3];
} Events;


Events ev;
Events ev2;

void *eventsThread(void *arg0){

List_List listEvents;
memcpy(&ev.EventId,"test1",sizeof("test1"));
memcpy(&ev2.EventId,"test2",sizeof("test2"));



//char buff[7];
//memcpy(buff,&ev.EventId,sizeof("test1")); testing to see if memcpy copied the string correctly


Events *evPtr;
Events *evPtr2;

List_clearList(&listEvents); //Function to initialize the contents of a List_List.
List_put(&listEvents, (List_Elem *)&ev); //Function to atomically put an elem onto the end of a linked list.
List_put(&listEvents, (List_Elem *)&ev2);
evPtr = (Events *)List_get(&listEvents); //Function to atomically get the first elem in a linked list.
evPtr2=(Events*) evPtr->elem.next;

Task_sleep(50 * (1000 / Clock_tickPeriod));


}




