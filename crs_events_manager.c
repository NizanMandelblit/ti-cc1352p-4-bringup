/*
 * crs_events_manager.c
 *
 *  Created on: 27 ????? 2021
 *      Author: cellium
 */


#include <crs_events_manager.h>
//#include <ti/drivers/Timer.h>
#include <xdc/runtime/Timestamp.h>


//   uint32_t  EventId;
//   uint8_t  EventType;
//   uint32_t  EventTime;//---NEED TO CHECK HOW MUCH BITS ARE NEDDED!   uint32_t time= Timestamp_get32();
//   uint32_t  ManagedObjectClass;
//   uint16_t  ManagedObjectInstance;
//   uint8_t  perceivedSeverity;
//   uint32_t  AdditionalInformation[3];


crs_Events listEvents[MAX_CRS_EVENTS_SLOTS];

//this thread simply create the data structure that will hold the linked list of the crs_events struct, and will make event-call to write an crs_event object into the list, and event-call to make a read operation.
void *eventsThread(void *arg0){
int i=0;
    for(i=0;i<MAX_CRS_EVENTS_SLOTS;i++){
        listEvents[i].EventId=i;
        listEvents[i].EventType=rand();
        listEvents[i].EventTime=Timestamp_get32();
        listEvents[i].ManagedObjectClass=rand();
        listEvents[i].perceivedSeverity=(rand()%0xf);
        listEvents[i].AdditionalInformation[0]=3;
        listEvents[i].AdditionalInformation[1]=2;
        listEvents[i].AdditionalInformation[2]=1;
    }

while(1){

    Task_sleep(50 * (1000 / Clock_tickPeriod));
}


}




