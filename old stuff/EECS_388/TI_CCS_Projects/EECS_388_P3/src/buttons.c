/*
 * buttons.c
 *
 *  Created on: Mar 2, 2016
 *      Author: raviles
 */


#include "buttons.h"

#include "system.h"

#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"

#include "FreeRTOS.h"
#include "task.h"

#include "speaker.h"

static unsigned long timeToExec = 0;
static const unsigned long delay = 10;
static unsigned debounce = 100;
static unsigned long period1 = 200;
static unsigned long period2 = 500;
unsigned long buttons2;
unsigned long a = BUTTONS;
unsigned long b = BUTTONS;


void BUTTONSTask(void *pvParameters) {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

    GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7));

    GPIOPadConfigSet(GPIO_PORTG_BASE, (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7), GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);






	while(true) {
	if(sysTickCount >= timeToExec) {

		frequency = 0;
        buttons2 = GPIOPinRead(GPIO_PORTG_BASE, BUTTONS);

        if (buttons2 != BUTTONS)
        {
        	if (buttons2 != a)
        	{
        		timeToExec += debounce;
        	}

        	else
        	{
        		if (buttons2!=b)
        		{
        			if (!(buttons2 & UP))
        			{
        				frequency = 100;
        			}
        			else if (!(buttons2 & DOWN))
        			{
        				frequency = 200;
        			}
        			else if (!(buttons2 & LEFT))
        			{
        				frequency = 300;
        			}
        			else if (!(buttons2 & RIGHT))
        			{
        				frequency = 400;
        			}
        			else if (!(buttons2 & SELECT))
        			{
        				frequency = 500;
        			}

        			timeToExec += period1;
        		}
        	}
        }
        else
        {
        	if (buttons2 != b && a != b)
        	{
        		if (!(b & UP))
        		{
        			frequency = 100;
        		}
        		else if (!(b & DOWN))
        		{
        			frequency = 200;
        		}
        		else if (!(b & LEFT))
        		{
        			frequency = 300;
        		}
        		else if (!(b & RIGHT))
        		{
        			frequency = 400;
        		}
        		else if (!(b & SELECT))
        		{
        			frequency = 500;
        		}

        		timeToExec += period2;

        	}
        }

        b = a;
        a = buttons2;
        timeToExec += delay;

	}
}
}
