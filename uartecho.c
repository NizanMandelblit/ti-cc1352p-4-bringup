/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
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
 *  ======== uartecho.c ========
 */
#include <stdint.h>
#include <stdbool.h>

#include <stddef.h>
#include <string.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/NVS.h>
#include <ti/drivers/nvs/NVSRAM.h>
/* Driver configuration */
#include "ti_drivers_config.h"
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti_printf.h>


/*
 *  ======== mainThread ========
 */
#define BUFFSIZE 100
#define RAM_WRITE 1024
unsigned int convertStrUint(char *st);
int hex2int(char ch);
char int2hex(unsigned long n,  char *outbuf);


void *cliThread(void *arg0)
{

    bm_printf("%s %d %08x\n","avi fraind",4,0xff);


    char        input;
    uint8_t  inputArray[BUFFSIZE];
    const char  echoPrompt[] = "\r\n Echoing characters:\r\n";
    uint32_t RAM_writeable_sector[RAM_WRITE]={0};
    UART_Handle uart;
    UART_Params uartParams;

    /* Call driver init functions */
    GPIO_init();
    UART_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode =  UART_DATA_TEXT;
    uartParams.readDataMode =  UART_DATA_TEXT;
    uartParams.readReturnMode = UART_RETURN_NEWLINE;
    uartParams.baudRate = 115200;
    uartParams.readEcho=UART_ECHO_ON;


    uart = UART_open(CONFIG_UART_0, &uartParams);

    if (uart == NULL) {
        /* UART_open() failed */
        while (1);
    }


   char buffCmd[BUFFSIZE]={'\0'};
    UART_write(uart, echoPrompt, sizeof(echoPrompt));
    char addr[8]={'\0'};
    char valHex[8]={'\0'};
    int i=0;
    /* Loop forever echoing */
    while (1) {
         UART_read(uart,&input , 1);
         //if the user pressed backspace
         if(input=='\b'){
               i--;
               buffCmd[i%BUFFSIZE]=input;
               UART_write(uart,  &input, 1);
               UART_write(uart," ", 1);
               UART_write(uart,  &input, 1);

               continue;
         }
         buffCmd[i%BUFFSIZE]=input;
         //if the user pressed enter
         if(input=='\r'){
             buffCmd[i]='\0';
             const char enter[2]="\r\n";
             const char  cliPrompt[] = ">";
             UART_write(uart,  enter, sizeof(enter));
             UART_write(uart,  cliPrompt, sizeof(cliPrompt));
             if (strcmp(buffCmd,"help")==0){
                 UART_write(uart,"help menu\r\n", sizeof("help menu\r\n"));
                 UART_write(uart,"w [address] [value]\r\n", sizeof("w [address] [value]\r\n"));
                 UART_write(uart,"r [address] \r\n", sizeof("r [address] \r\n"));
                 UART_write(uart,"don't prefix with 0x\r\n", sizeof("don't prefix with 0x\r\n"));

                 uint32_t addr_start= ((uint32_t) (&RAM_writeable_sector)-0x20000000);
                char RAM_write_string[5]={'\0'};
               UART_write(uart,"RAM write addr space: 0x",sizeof("RAM write addr space: 0x"));
               int2hex(addr_start,RAM_write_string);
               UART_write(uart,RAM_write_string,sizeof(RAM_write_string));
               UART_write(uart," -0x", sizeof(" -0x"));
               int2hex((addr_start+RAM_WRITE),RAM_write_string);
               UART_write(uart,RAM_write_string,sizeof(RAM_write_string));
             }
             if (buffCmd[0]=='w'){
                 if(strlen(buffCmd)<2){
                     buffCmd[0]='\0';
                       UART_write(uart,"invalid cmd\r\n", sizeof("invalid cmd\r\n"));
                        continue;
                   }
                         UART_write(uart,"write menu\r\n", sizeof("write menu\r\n"));
                         const char delimiter[2] = " ";//space delimiter
                         char *token;
                          /* get the first token */
                           token = strtok(buffCmd, delimiter);
                           /* walk through other tokens */
                           token = strtok(NULL, delimiter);//skip the 'w'
                           strcpy(addr,token);
                           token = strtok(NULL, delimiter);//skip the addr string
                           memset(valHex,'\0',sizeof(valHex));
                           strcpy(valHex,token);//token is now the value

                           uint32_t addrInt=((uint32_t)(convertStrUint(addr))+0x20000000);
                           uint32_t valInt=(convertStrUint(valHex));
                           *((uint32_t *)addrInt)= valInt;
                           memset(addr,'\0',sizeof(addr));
                           memset(buffCmd,'\0',sizeof(buffCmd));


                     }
             if (buffCmd[0]=='r'){
                 if(strlen(buffCmd)<2){
                     buffCmd[0]='\0';
                       UART_write(uart,"invalid cmd\r\n", sizeof("invalid cmd\r\n"));
                        continue;
                   }
                           UART_write(uart,"read menu\r\n", sizeof("read menu\r\n"));
                           strcpy(addr,(buffCmd+2));
                           uint32_t addrHex=(convertStrUint(addr));
                           addrHex+=0x20000000;
                           uint32_t x= *(uint32_t *)(addrHex);
                          UART_write(uart,"0x", sizeof("0x"));
                          UART_write(uart,addr, sizeof(addr));
                          UART_write(uart," = ", sizeof(" = "));
                          UART_write(uart,"0x", sizeof("0x"));
                          int2hex(x,valHex);
                          UART_write(uart,valHex,sizeof(valHex));
                          memset(addr,'\0',sizeof(addr));
                          memset(buffCmd,'\0',sizeof(buffCmd));
                          memset(valHex,'\0',sizeof(valHex));
                          continue;

                       }
             i=0;
             continue;
         }else{
             UART_write(uart,  &input, 1);
         }
i++;
         Task_sleep(50 * (1000 / Clock_tickPeriod));

    }
}


unsigned int convertStrUint(char *st) {
  char *x;

  int i=0;
  int len = strlen(st)-1;
  int base;
  (len) ? (base=16) : (base=1);
  for (i=1;i<len;i++){
      base*=16;
  }
  unsigned int result=0;
  for (x = st ; *x ; x++) {
      result+=base*hex2int(*x);
      base/=16;
  }
return result;
}



int hex2int(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    return -1;
}



char int2hex(unsigned long num,  char *outbuf)
{
      int i = 12;
      int j = 0;

      do{
          outbuf[i] = "0123456789ABCDEF"[num % 16];
          i--;
          num = num/16;
      }while( num > 0);

      while( ++i < 13){
         outbuf[j++] = outbuf[i];
      }

      outbuf[j] = 0;

}




