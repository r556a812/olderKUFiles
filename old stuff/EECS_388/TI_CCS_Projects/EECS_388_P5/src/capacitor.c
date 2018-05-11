/*
 * capacitor.c
 *
 *  Created on: Apr 21, 2016
 *      Author: raviles
 */


#include "capacitor.h"
#include "buttons.h"
#include "driverlib/adc.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

QueueHandle_t queue1;
int UART_trigger;

void CAPACITORTask(void* pvParameter)
{
	unsigned long val1=0;
	int x=0;
	queue1 = xQueueCreate(100,sizeof(unsigned long));

	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_1);
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_OD);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x02);

	ADCSequenceConfigure(ADC_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_IE|ADC_CTL_END|ADC_CTL_CH1);
	ADCSequenceEnable(ADC0_BASE, 1);

	ADCIntClear(ADC0_BASE, 1);

	while(true)
	{

		if(cap_trigger==1)
		{

			x=0;
			cap_trigger = 0;
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x00);//Setting the Pin 0 to "high"
			vTaskDelay(ONE_MS*0.5);
			GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x02);//Setting the Pin 0 to "high"


			while(x<100)
			{
				ADCProcessorTrigger(ADC0_BASE, 1);
				while(!ADCIntStatus(ADC0_BASE, 1, false))
				{
				}
				ADCSequenceDataGet(ADC0_BASE, 1, &val1);//Enable ADC sequence 0
				ADCIntClear(ADC0_BASE, 1);
				xQueueSend(queue1, &val1, 0);
				x++;
				vTaskDelay(ONE_MS*1.0)
;			}
			UART_trigger = 1;

		}
		vTaskDelay(ONE_MS*10);
	}

}
