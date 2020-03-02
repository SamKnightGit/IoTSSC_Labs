#include "mbed.h"
#include "platform/mbed_thread.h"
#include "MMA8652.h"
#include "MiCS6814_GasSensor.h"

// Loop wait rate
#define SLEEP_RATE_MS						5

Serial pc(USBTX, USBRX);

// Initialize i2c pins for communicating with sensors
MMA8652 mma8652(D14, D15);
MiCS6814_GasSensor mics6814(D14, D15);

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
	    printf("NH3: %.2f ppm, CO: %.2f ppm, NO2: %.2f ppm, C3H8: %.2f ppm \r\n", mics6814.getGas(NH3), mics6814.getGas(CO), mics6814.getGas(NO2), mics6814.getGas(C3H8));
            printf("C4H10: %.2f ppm, CH4: %.2f ppm, H2: %.2f ppm, C2H5OH: %.2f ppm \r\n", mics6814.getGas(C4H10), mics6814.getGas(CH4), mics6814.getGas(H2), mics6814.getGas(C2H5OH));
	    
	    printf("\r\n");
	    thread_sleep_for(SLEEP_RATE_MS);
	}
}


