/*
 * speaker.c
 *
 *  Created on: Feb 3, 2016
 *      Author: raviles
 */


#include "speaker.h"

#include "system.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

static unsigned long timeToExec = 0;
static const unsigned long delay = SYSTICK_FREQUENCY / (2 * 440);

void SPEAKERInit() {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, (GPIO_PIN_0 | GPIO_PIN_1));

    GPIOPinWrite(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0), 0b1);
    timeToExec = sysTickCount + delay;
}

void SPEAKERExec() {
	if(sysTickCount >= timeToExec) {
        GPIOPinWrite(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0), GPIOPinRead(GPIO_PORTH_BASE, (GPIO_PIN_1 | GPIO_PIN_0)) ^ 0b11 );
        timeToExec += delay;
	}
}
