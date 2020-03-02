/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    1000
#define BLINK_DURATION_MS						    200

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut ledRed(LED1, 1);
    DigitalOut ledGreen(LED2, 1);
    DigitalOut ledBlue(LED3, 1);
    int counter = 0;
    while (true) {
	if (counter == 0) {
	    ledRed = 0;
	    thread_sleep_for(BLINK_DURATION_MS);
	    ledRed = 1;

	    counter += 1;
	}
	else if (counter == 1) {
	    ledGreen = 0;
	    thread_sleep_for(BLINK_DURATION_MS);
	    ledGreen = 1;

	    counter += 1;
	}
	else {
	    ledBlue = 0;
	    thread_sleep_for(BLINK_DURATION_MS);
	    ledBlue = 1;

	    counter = 0;
	}
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
