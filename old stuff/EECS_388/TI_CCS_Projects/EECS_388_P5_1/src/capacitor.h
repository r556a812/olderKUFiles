/*
 * capacitor.h
 *
 *  Created on: Apr 21, 2016
 *      Author: raviles
 */

#ifndef SRC_CAPACITOR_H_
#define SRC_CAPACITOR_H_

#include "system.h"
#include "queue.h"

extern int UART_trigger;
extern QueueHandle_t queue1;
extern void CAPACITORTask(void*);

#endif /* SRC_CAPACITOR_H_ */
