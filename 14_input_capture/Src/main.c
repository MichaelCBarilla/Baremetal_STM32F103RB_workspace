#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)


int main(void)
{
	tim2_pa0_output_compare();


	while(1)
	{


	}
}



