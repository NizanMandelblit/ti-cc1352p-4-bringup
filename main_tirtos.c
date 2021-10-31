/*
 * Copyright (c) 2016-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,

 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main_tirtos.c ========
 */
//#include <stdint.h>
/* POSIX Header files */
//#include <pthread.h>

/* RTOS header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/std.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/Board.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <main.h>
#include <led.h>
#include <uartecho.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>


extern void *cliThread(void *arg0);
extern void *nvsThread(void *arg0);
extern void *ledThread(void *arg0);
extern void *eventsThread(void *arg0);


/*
 *  ======== main ========
 */


/* Stack size in bytes */
#define THREADSTACKSIZE 1024
static uint8_t clithreadStack[THREADSTACKSIZE];
static uint8_t nvsthreadStack[THREADSTACKSIZE];
static uint8_t ledthreadStack[THREADSTACKSIZE];
static uint8_t eventsthreadStack[THREADSTACKSIZE];


/* Make sure we have nice 8-byte alignment on the stack to avoid wasting memory */
#pragma DATA_ALIGN(clithreadStack, 8)
#pragma DATA_ALIGN(nvsthreadStack, 8)
#pragma DATA_ALIGN(ledthreadStack, 8)
#pragma DATA_ALIGN(eventsthreadStack, 8)




int main(void)
{

    Board_init();


    Semaphore_Struct my_semStruct;
    Semaphore_Handle my_semHandle;
    Semaphore_Params semParams;


    /* Construct a Semaphore object to be use as a resource lock, inital count 1 */
       Semaphore_Params_init(&semParams);
       semParams.mode = Semaphore_Mode_BINARY;
       my_semHandle = Semaphore_create(1, &semParams, NULL); /* Memory allocated in here */

//       Semaphore_construct(&my_semStruct, 1, &semParams);

       /* Obtain instance handle */





  init_led(&my_semHandle);

  init_echo(&my_semHandle);

    Task_Struct clithread;
    Task_Struct nvsthread;
    Task_Struct ledthread;
    Task_Struct eventsthread;



    Task_Params  clithreadParams;
    Task_Params  nvsthreadParams;
    Task_Params  ledthreadParams;
    Task_Params  eventsthreadParams;


    Task_Params_init(&clithreadParams);
//    Task_Params_init(&nvsthreadParams);
    Task_Params_init(&ledthreadParams);
    Task_Params_init(&eventsthreadParams);  //BUG !!!!4 task params init, MAKE THE CPU STUCK!


    clithreadParams.stackSize = THREADSTACKSIZE;
    clithreadParams.priority = 1;
    clithreadParams.stack = &clithreadStack;

    ledthreadParams.stackSize = THREADSTACKSIZE;
    ledthreadParams.priority = 2;
    ledthreadParams.stack = &ledthreadStack;


    eventsthreadParams.stackSize = THREADSTACKSIZE;
    eventsthreadParams.priority = 2;
    eventsthreadParams.stack = &eventsthreadStack;

    Task_construct(&clithread, (Task_FuncPtr)cliThread, &clithreadParams, NULL); //uart thread 50 ms
    Task_construct(&ledthread, (Task_FuncPtr)ledThread, &ledthreadParams, NULL); //led thread  50 ms
    Task_construct(&eventsthread, (Task_FuncPtr)eventsThread, &eventsthreadParams, NULL); //events thread 50 ms


//    Task_construct(&nvsthread, (Task_FuncPtr)nvsThread, &nvsthreadParams, NULL); //nvs thread

    BIOS_start();

    return (0);




 //POSIX way:
//    pthread_t           clithread;
//    pthread_t           nvsthread;
//    pthread_t           ledthread;
//    pthread_attr_t      attrs;
//    struct sched_param  priParam;
//    int                 retc;
//
//    Board_init();
//
//    /* Initialize the attributes structure with default values */
//    pthread_attr_init(&attrs);
//
//    /* Set priority, detach state, and stack size attributes */
//    priParam.sched_priority = 1;
//    retc = pthread_attr_setschedparam(&attrs, &priParam);
//    retc |= pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_DETACHED);
//    retc |= pthread_attr_setstacksize(&attrs, THREADSTACKSIZE);
//    if (retc != 0) {
//        /* failed to set attributes */
//        while (1) {}
//    }
//
//    retc = pthread_create(&clithread, &attrs, cliThread, NULL);
//    if (retc != 0) {
//        /* pthread_create() failed */
//        while (1) {}
//    }
//    retc = pthread_create(&ledthread, &attrs, ledThread, NULL);
//     if (retc != 0) {
//         /* pthread_create() failed */
//         while (1) {}
//     }
//    BIOS_start();
//
//    return (0);


}
