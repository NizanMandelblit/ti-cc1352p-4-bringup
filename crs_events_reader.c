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

extern List_List listEvents;

typedef struct crs_events_reader {
    crs_Events *start;
    crs_Events *end;
    crs_Events *curr;
    uint8_t handler_id;
} crs_Events_Reader;

unsigned int handler_counter=0;

void *events_readerThread(){
    char* buff;
    handler_counter++;
    bm_printf("handler id ");
    int2hex(handler_counter,buff);
    bm_printf(buff);



//    evPtr = (crs_Events *)List_get(&listEvents); //Function to atomically get the first elem in a linked list.


}
