/*
 * buttons.c
 *
 *  Created on: Apr 21, 2016
 *      Author: raviles
 */


#include "buttons.h"
#include "system.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"

#define select GPIO_PIN_7
#define buttons select

static unsigned long debounce = 100;
static unsigned long delay=ONE_MS;

unsigned long buttons1=buttons;
unsigned long buttons2=buttons;
unsigned long trigger2;


static unsigned long period1 = 500*ONE_MS;
static unsigned long period2 = 1000*ONE_MS;


unsigned long trigger2;

int cap_trigger=0;

void BUTTONSTask(void *pvParameters)
{


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

    GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, buttons);
    GPIOPadConfigSet(GPIO_PORTG_BASE, buttons, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    vTaskDelay(ONE_MS*1000);///maybe a mistake

	while(true)
	{

		delay = ONE_MS;


		trigger2 = GPIOPinRead(GPIO_PORTG_BASE, buttons);

		if (trigger2 != buttons) {
			if(trigger2 != buttons1)
			{
				delay += debounce;
			}

		}
		else
		{
			if((trigger2 != buttons2) && (buttons1 != buttons2))
			{
				cap_trigger = 1;
				delay += period2;
			}
		}

		buttons2 = buttons1;
		buttons1 = trigger2;
		vTaskDelay(delay);//substitute for target+=period
	}
}
