/********************************************************************************************
 *
 * 		Author: 		Brad Torrence
 *		Purpose:		Example program that demonstrates:
 *							(1) setting up the system clock and the FreeRTOS system
 * 							(2) initializing peripherals (LED and OLED display)
 *							(3) toggling an LED by reading/writing from/to GPIO pins
 *							(4) creating and displaying a simple image on the OLED
 *							(5) formatting and displaying a string on the OLED
 *
 ********************************************************************************************/

// Project libraries
#include "src/system.h"
#include "src/oled.h"
#include "src/led.h"
#include "src/potentiometer.h"
#include "src/buttons.h"
#include "src/uartSend.h"
#include "src/capacitor.h"


//*************************************************************************************************
//	Main program to initialize hardware and execute Tasks.
//*************************************************************************************************
void main()  {
	// Create the tasks, the definitions are passed to the scheduler
	xTaskCreate(LEDTask, "LEDTask", 32, NULL, 0, NULL);
	xTaskCreate(OLEDTask, "OLEDTask", 256, NULL, 1, NULL); // Note the higher priority for the display
	xTaskCreate(POTENTIOMETERTask, "POTENTIOMETERTask", 64, NULL, 3, NULL);
	xTaskCreate(UARTTask, "UARTTask", 64, NULL, 1, NULL);
	xTaskCreate(CAPACITORTask, "CAPACITORTask", 64, NULL, 2, NULL);
	xTaskCreate(BUTTONSTask, "BUTTONSTask", 64, NULL, 1, NULL);
	//  Initialize system
	systemInit();

	// Display the initial image
	startScreen();

	// Start the FreeRTOS Scheduler
	vTaskStartScheduler();

	// The infinite loop is necessary for the FreeRTOS Scheduler
    while(true);
}

