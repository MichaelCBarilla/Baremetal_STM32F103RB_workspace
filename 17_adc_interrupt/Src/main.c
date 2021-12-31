#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"
#include "adc.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)

void ADC_IRQHandler(void);
static void adc_callback(void);

uint32_t sensor_value;
int main(void)
{


	uart2_tx_init();
	pa1_adc_interrupt_init();
	start_conversion();

	while(1)
	{


	}
}

static void adc_callback(void)
{
	sensor_value = ADC1->DR;
	printf("Sensor value : %d \n\r", (int)sensor_value);
}

void ADC1_IRQHandler(void)
{
	/* Check for EOC in SR */
	if ((ADC1->SR & SR_EOC) != 0) {
		/* Clear EOC  */
		ADC1->SR &= ~(SR_EOC);

		/* Do something */
		adc_callback();
	}
}
