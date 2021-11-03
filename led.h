/*
 * led.h
 *
 *  Created on: 26 ????? 2021
 *      Author: cellium
 */

#ifndef LED_H_
#define LED_H_


#include <ti/sysbios/knl/Semaphore.h>

void init_led(Semaphore_Handle* handle);

#endif /* LED_H_ */
