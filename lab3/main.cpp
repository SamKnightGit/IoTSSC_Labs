#include "mbed.h"
#include "platform/mbed_thread.h"
#include "MMA8652.h"

// Loop wait rate
#define SLEEP_RATE_MS						5

Serial pc(USBTX, USBRX);

// Initialize i2c pins for communicating with sensors
MMA8652 mma8652(D14, D15);

float accel_data[3];

int main()
{
	
        mma8652.MMA8652_config();
	printf("Begin reading data from accelerometer and Gas Sensor...\r\n\r\n");
    	thread_sleep_for(500);
	
	while(1) {
            
	    // Reading Acceleration Data
	    printf("Acceleration Data:\r\n");
            mma8652.acquire_MMA8652_data_g(accel_data);
            printf("%4.2f,\t%4.2f,\t%4.2f,\t\r\n\r\n", accel_data[0], accel_data[1], accel_data[2]);
	    
	    // Reading Gas Sensor Data
	    /**insert code here**/

	    printf("\r\n");
	    thread_sleep_for(SLEEP_RATE_MS);
	}
}


