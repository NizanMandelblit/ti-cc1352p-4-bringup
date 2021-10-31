/*
 * crs_events_manager.c
 *
 *  Created on: 27 ????? 2021
 *      Author: cellium
 */


#include <crs_events_manager.h>
//#include <ti/drivers/Timer.h>
#include <xdc/runtime/Timestamp.h>




crs_Events ev;
crs_Events ev2;
crs_Events ev3;

List_List listEvents;
int max_record_number=100;

//this thread simply create the data structure that will hold the linked list of the crs_events struct, and will make event-call to write an crs_event object into the list, and event-call to make a read operation.
void *eventsThread(void *arg0){

memcpy(&ev.EventId,"test1",sizeof("test1"));
memcpy(&ev2.EventId,"test2",sizeof("test2"));
memcpy(&ev3.EventId,"test3",sizeof("test3"));



//char buff[7];
//memcpy(buff,&ev.EventId,sizeof("test1")); testing to see if memcpy copied the string correctly


crs_Events *evPtr;
crs_Events *evPtr2;
crs_Events *evPtr3;


List_clearList(&listEvents); //Function to initialize the contents of a List_List.
List_put(&listEvents, (List_Elem *)&ev); //Function to atomically put an elem onto the end of a linked list.
List_put(&listEvents, (List_Elem *)&ev2);
List_put(&listEvents, (List_Elem *)&ev3);

evPtr = (crs_Events *)List_get(&listEvents); //Function to atomically get the first elem in a linked list.
evPtr2=(crs_Events*) evPtr->elem.next;
evPtr3=(crs_Events*) evPtr2->elem.next;

while(1){

    Task_sleep(50 * (1000 / Clock_tickPeriod));
}


}




