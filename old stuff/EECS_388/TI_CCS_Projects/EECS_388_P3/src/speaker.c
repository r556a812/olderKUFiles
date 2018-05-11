/*
 * speaker.c
 *
 *  Created on: Mar 2, 2016
 *      Author: raviles
 */


#include "speaker.h"
#include "buttons.h"
#include "system.h"

#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"

#include "FreeRTOS.h"
#include "task.h"

static unsigned long timeToExec = 0;
static unsigned long delay = SYSTICK_FREQUENCY / (2 * 440);
unsigned long frequency = 0;

void SPEAKERTask(void *pvParameters) {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, (GPIO_PIN_0 | GPIO_PIN_1));

    GPIOPinWrite(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0), 0b1);



	while(true) {
	if(sysTickCount >= timeToExec) {
		delay = SYSTICK_FREQUENCY / (frequency * 2);
        GPIOPinWrite(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0), GPIOPinRead(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0)) ^ 0b11 );
        timeToExec += delay;
	}
}
}
