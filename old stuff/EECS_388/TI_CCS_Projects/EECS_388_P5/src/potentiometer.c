/*
 * potentiometer.c
 *
 *  Created on: Mar 24, 2016
 *      Author: raviles
 */


#include "potentiometer.h"

#include "driverlib/adc.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

//Redeclare queue
QueueHandle_t queue;

unsigned long ulValue = 0;

void POTENTIOMETERTask(void *pvParameters){
	//Initialize queue with call to xQueueCreate
	queue = xQueueCreate(5, sizeof(long));

	//Enable Port D
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	//Set Port D to output pin
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);

	//Set drive strength to 4ma
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);

	//Set to High
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x01);

	//Enable ADC0 Peripheral
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	//Configure sequence 0 to be triggered by the processor
	ADCSequenceConfigure(ADC0_BASE,0,ADC_TRIGGER_PROCESSOR,1);

	//Configure step 0 of sequence 0 to be the final step
	ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);

	//Enable ADC sequence 0
	ADCSequenceEnable(ADC0_BASE,0);

	//Clear the ADC sequence 0 interrupt flag
	ADCIntClear(ADC0_BASE, 0);

	while(true) {
		//Trigger an ADC sample
		ADCProcessorTrigger(ADC0_BASE, 0);

		//Wait for the ADC interrupt to be thrown
		while(!ADCIntStatus(ADC0_BASE, 0, false)) {
		}

		//Collect data from the ADC sequence
		ADCSequenceDataGet(ADC0_BASE, 0, &ulValue);

		//Reset the ADC interrupt status
		ADCIntClear(ADC0_BASE, 0);

		//Write the sampled data to the queue, if full drop the sample
		xQueueSend(queue,(void*) &ulValue,0);

		//Set delay time to one sec
		vTaskDelay(ONE_MS * 1000.0);
	}
}




