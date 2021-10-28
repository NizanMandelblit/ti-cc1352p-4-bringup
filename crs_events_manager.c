/*
 * crs_events_manager.c
 *
 *  Created on: 27 ????? 2021
 *      Author: cellium
 */


#include <crs_events_manager.h>


typedef struct crs_events {
   List_Elem elem;
   uint32_t  EventId;
   uint8_t  EventType;
   uint8_t  EventTime[100];//---NEED TO CHECK HOW MUCH BITS ARE NEDDED!
   uint32_t  ManagedObjectClass;
   uint16_t  ManagedObjectInstance;
   uint8_t  perceivedSeverity;
   uint32_t  AdditionalInformation[3];
} crs_Events;


crs_Events ev;
crs_Events ev2;
//this thread simply create the data structure that will hold the linked list of the crs_events struct, and will make event-call to write an crs_event object into the list, and event-call to make a read operation.
void *eventsThread(void *arg0){

List_List listEvents;
memcpy(&ev.EventId,"test1",sizeof("test1"));
memcpy(&ev2.EventId,"test2",sizeof("test2"));



//char buff[7];
//memcpy(buff,&ev.EventId,sizeof("test1")); testing to see if memcpy copied the string correctly


crs_Events *evPtr;
crs_Events *evPtr2;

List_clearList(&listEvents); //Function to initialize the contents of a List_List.
List_put(&listEvents, (List_Elem *)&ev); //Function to atomically put an elem onto the end of a linked list.
List_put(&listEvents, (List_Elem *)&ev2);
evPtr = (crs_Events *)List_get(&listEvents); //Function to atomically get the first elem in a linked list.
evPtr2=(crs_Events*) evPtr->elem.next;
while(1){

    Task_sleep(50 * (1000 / Clock_tickPeriod));
}


}




