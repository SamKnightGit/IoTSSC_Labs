#include "mbed.h"

#define MAIN_SLEEP_MS                       1000
#define BUFF_LENGTH                         20
RawSerial pc(USBTX, USBRX, 9600);
RawSerial bluetooth_module(D1, D0, 9600);
event_callback_t bluetooth_callback;

uint8_t bluetooth_text[BUFF_LENGTH + 1];

void bluetooth_read(int events)
{
    pc.printf("Read from bluetooth: \r\n");
    pc.printf("%s\r\n", bluetooth_text);
}

int main()
{
    bluetooth_callback = bluetooth_read;
    pc.printf("Starting Up!\r\n");
    while(1) {
        ThisThread::sleep_for(MAIN_SLEEP_MS);
        //bluetooth_module.printf("Howdy\r\n");
        bluetooth_module.read(bluetooth_text, BUFF_LENGTH, bluetooth_callback);
    }
}
