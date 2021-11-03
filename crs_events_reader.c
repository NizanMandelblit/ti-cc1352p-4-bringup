/*
 * crs_events_reader.c
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
#include <ti_printf.h>
#include <ti_utils.h>

extern crs_Events listEvents[MAX_CRS_EVENTS_SLOTS];
#define MAX_READER_SLOTS 30
typedef struct crs_events_reader
{
    crs_Events start;
    crs_Events end;
    crs_Events curr;
    uint8_t handler_id;
    char is_open;
    uint8_t cntr;
    uint16_t short_addr;
} crs_Events_Reader;

unsigned int handler_counter = MAX_READER_SLOTS;
crs_Events_Reader reader[MAX_READER_SLOTS];
void* events_readerThread(uint16_t short_addr)
{
while(handler_counter){
    if (!(reader[handler_counter].is_open)){
        reader[handler_counter].handler_id = handler_counter;
        reader[handler_counter].start = *listEvents;
        reader[handler_counter].end = listEvents[MAX_CRS_EVENTS_SLOTS - 1];
        reader[handler_counter].curr = *(listEvents);
        reader[handler_counter].is_open = 1;
        reader[handler_counter].cntr = 0;
        reader[handler_counter].short_addr = short_addr;

        bm_printf("%d\r\n", handler_counter);
        handler_counter --;
        return;
    }else {
        handler_counter--;
    }
}

if(!handler_counter){
    bm_printf("Error:0x2\n");
    handler_counter=MAX_READER_SLOTS;
}

//    bm_printf("0x00000001 0x07 0x00001234 0xABCD0123 0x11 measured_voltage:2.9,voltage_treshold:3.3  perceivedSeverity(4 bits)\r");

}

void* evnext_cmd(unsigned int handler_id)
{
if(handler_id<0 && handler_id>MAX_READER_SLOTS){
bm_printf("Error:0x3\n");
return;
}
//    bm_printf("%d", handler_id);
    if (reader[handler_id].is_open)
    {
        bm_printf("0x%08x 0x%02x 0x%08x 0x%08x 0x%02x %d,%d,%d 0x%01x\r",
                  reader[handler_id].curr.EventId,
                  reader[handler_id].curr.EventType,
                  reader[handler_id].curr.EventTime,
                  reader[handler_id].curr.ManagedObjectClass,
                  reader[handler_id].short_addr,
                  reader[handler_id].curr.AdditionalInformation[0],
                  reader[handler_id].curr.AdditionalInformation[1],
                  reader[handler_id].curr.AdditionalInformation[2],
                  reader[handler_id].curr.perceivedSeverity);
        reader[handler_counter].cntr = ((reader[handler_counter].cntr + 1)
                % MAX_CRS_EVENTS_SLOTS);
        reader[handler_id].curr = (listEvents[reader[handler_counter].cntr]);
    }
    else
    {
        bm_printf("Error:0x1\n",
                  handler_id);

    }
//Need to reutrn in this format: 0x00000001 0x07 0x00001234 0xABCD0123 0x11 2.9,3.3\r
//    reader[handler_id];

}

void* evclose_cmd(unsigned int handler_id)
{
    reader[handler_id].is_open = 0;
    handler_counter=MAX_READER_SLOTS;
}
