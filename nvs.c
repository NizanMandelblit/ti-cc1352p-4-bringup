/*
 * nvs.c
 *
 *  Created on: 21 10 2021
 *      Author: nizan
 */



#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/NVS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti_printf.h>

/* Driver configuration */
#include "ti_drivers_config.h"

typedef struct Event {
    int     id;
    char    val;
} EventObj;


void *nvsThread(void *arg0)
{



//
//        bm_printf("nvs thread!\n");
//
//
//          NVS_Handle nvsRegion;
//          NVS_Attrs regionAttrs;
//          uint_fast16_t status;
//          char buf[32];
//          // initialize the NVS driver
//          NVS_init();
//          //
//          // Open the NVS region specified by the 0th element in the NVS_config[]
//          // array defined in ti_drivers_config.c.
//          //
//          // Use default NVS_Params to open this memory region, hence 'NULL'
//          //
//          nvsRegion = NVS_open(CONFIG_NVS_RAM, NULL);
//          // Confirm that the NVS region opened properly
//          if (nvsRegion == NULL) {
//              // Error handling code
//          }
//          // Fetch the generic NVS region attributes for nvsRegion
//          NVS_getAttrs(nvsRegion, &regionAttrs);
//          // Erase the first sector of nvsRegion
//  //        status = NVS_erase(nvsRegion, 0, regionAttrs.sectorSize);
////          if (status != NVS_STATUS_SUCCESS) {
////              // Error handling code
////          }
////          // Write "Hello" to the base address of nvsRegion, verify after write
////  //        status = NVS_write(nvsRegion, 0, "Hello", strlen("Hello")+1, NVS_WRITE_POST_VERIFY);
////          if (status != NVS_STATUS_SUCCESS) {
////              // Error handling code
////          }
//          // Copy "Hello" from nvsRegion into local 'buf'
//          status = NVS_read(nvsRegion, 0, buf, strlen("Hello")+1);
//          if (status != NVS_STATUS_SUCCESS) {
//              // Error handling code
//          }
//          // Print the string from fetched NVS storage
//          bm_printf("%s\n",buf);
//          //
//          // Print the string using direct flash address reference if valid
//          //
//          // When the NVS driver is managing SPI flash non volatile
//          // storage, the regionBase attribute will be `NVS_REGION_NOT_ADDRESSABLE`
//          //
//          if (regionAttrs.regionBase != NVS_REGION_NOT_ADDRESSABLE) {
//             bm_printf("%s\n", regionAttrs.regionBase);
//          }
//          // close the region
//          NVS_close(nvsRegion);
//          Task_sleep(500 * (1000 / Clock_tickPeriod));
//


}
