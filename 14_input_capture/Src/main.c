#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)

int timestamp = 0;

/* Set up : Connect a jumper wire from PA0 to PA6 */

int main(void)
{
	tim2_pa0_output_compare();
	tim3_pa6_input_capture();


	while(1)
	{
		/* Wait until edge is captured */
		while ((TIM3->SR & SR_CC1IF) == 0) {}

		/* Read captured value */
		timestamp = TIM3->CCR1;

	}
}



