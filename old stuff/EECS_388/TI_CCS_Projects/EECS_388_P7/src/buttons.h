/*
 * buttons.h
 *
 *  Created on: Mar 2, 2016
 *      Author: raviles
 */


#ifndef SRC_BUTTONS_H_
#define SRC_BUTTONS_H_

extern void BUTTONSTask(void*);

#define UP GPIO_PIN_3
#define DOWN GPIO_PIN_4
#define LEFT GPIO_PIN_5
#define RIGHT GPIO_PIN_6
#define SELECT GPIO_PIN_7
#define BUTTONS (UP | DOWN | LEFT | RIGHT | SELECT)



#endif /* SRC_BUTTONS_H_ */
