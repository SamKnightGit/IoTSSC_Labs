#include "mbed.h"

#define MAIN_SLEEP_MS                       1000

RawSerial pc(USBTX, USBRX, 9600);
// Instantiate connection for bluetooth communication


int main()
{
    while(1) {
        ThisThread::sleep_for(MAIN_SLEEP_MS);
        // Send data to bluetooth module
		// Receive data from bluetooth module
    }
}
