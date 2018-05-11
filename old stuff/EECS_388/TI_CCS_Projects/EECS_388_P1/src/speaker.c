/*
 * speaker.c
 *
 *  Created on: Feb 3, 2016
 *      Author: raviles
 */

//Header file
#include "speaker.h"

// The system.h module will be required in all future task definitions
// This will give the task access to the base libraries as well as the global variables
#include "system.h"

// Stellaris driver libraries required by these local function definitions
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

/*
 *  The SPEAKER task definition requires two local variables to help control the execution frequency.
 *  	"timeToExec" is the number that is compared to sysTickCount.
 *  		It is usually initialized to 0, because it typically requires dynamic initialization
 *  	"delay" is best calculated as a fraction of the SysTick Frequency,
 *  		such that it has the form:  SYSTICK_FREQUENCY * (delay between executions in milliseconds)
 *  		this is done so that the SysTick frequency can be altered without having to change the
 *  		delay values for previously defined tasks.
 */
static unsigned long timeToExec = 0;
static const unsigned long delay = SYSTICK_FREQUENCY / (2 * 440);

/*
 *  The initialization and execution functions for this task
 */
void SPEAKERInit() {

	// Enable GPIO Port H
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);

    // The SPEAKER is attached Port G pin 0 and pin 1. It must be set as output
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
