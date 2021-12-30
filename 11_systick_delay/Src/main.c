#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "adc.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)



uint32_t sensor_value;
int main(void)
{


	uart2_rxtx_init();
	pa1_adc_init();
	start_conversion();

	while(1)
	{

		sensor_value = adc_read();
		printf("Sensor value : %d \n\r", (int)sensor_value);
	}
}



