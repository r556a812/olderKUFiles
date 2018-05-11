/*
 * buttons.c
 *
 *  Created on: Feb 10, 2016
 *      Author: raviles
 */


#include "system.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#include "speaker.h"

void BUTTONSInit() {
    // Enable GPIO Port G and configure it to drive the Status LED
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
    // The Status LED is attached to G<2> (Port G pin 2) it must be set as output
    GPIOPinTypeGPIOOutput(GPIO_PORTG_BASE, GPIO_PIN_2);
    /*
     * Start G<2> signal HIGH so the LED is lit at the start
     * The GPIOPinWrite function requires the Port and pins as the first arguments
     * 		the third argument has to be a bit-packed byte that represents the
     * 		desired state of the given pins.
     * 		The least-significant-bit of this byte (bit 0) represents pin 0 on the specified port,
     * 		the next LSB (bit 1) represents pin 1 and so on...
     * 	To write pin G<2> HIGH we have to pass the value 0x04 (or the constant representing the pin),
     * 	For example, if we wanted pin G<1> HIGH =>
     * 			GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_1, GPIO_PIN_1)
     * 		and if we wanted pin G<7> LOW =>
     * 			GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_7, 0x00)
     * 	The function can be used to write multiple pins as well,
     * 		if we wanted pins G<1> and G<2> HIGH =>
     * 			GPIOPinWrite(GPIO_PORTG_BASE, (GPIO_PIN_1 | GPIO_PIN_2), (GPIO_PIN_1 | GPIO_PIN_2))
     * 			or G<1> HIGH and G<2> LOW =>
     * 			GPIOPinWrite(GPIO_PORTG_BASE, (GPIO_PIN_1 | GPIO_PIN_2), GPIO_PIN_1)
     * 		the pin arguments are combined with a bit-wise OR operation
     * 		and the desired signal value given is a bit-wise OR'ing of the individual pin values.
     */
    // This sets G<2> to LOW
    GPIOPinWrite(GPIO_PORTG_BASE, GPIO_PIN_2, 0x00);
    /*
     * NOTICE the way numerical values are written here,
     * 		for instance 0x00 = 0, the prefix 0x tells the compiler that the
     * 		number is written in hexadecimal notation.
     * 			So, 0x02 = 2, 0x0F = 15, and 0x10 = 16
     *
     * 		Likewise binary values can be given with the prefix 0b
     * 			So, 0b0 = 0, 0b10 = 2, and 0b111 = 7
     *
     * 		These notations can make the code easier to understand in some cases
     */

    // Initialize the first execution time for the task by adding to the current SysTickCount
    timeToExec = sysTickCount + delay;
}
