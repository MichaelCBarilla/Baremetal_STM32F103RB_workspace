#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)


int main(void)
{

	RCC->APB2ENR |= GPIOAEN;

	GPIOA->CRL &= ~(1U<<23);
	GPIOA->CRL &= ~(1U<<22);
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL &= ~(1U<<20);

	uart2_tx_init();


	while(1)
	{
		systickDelayMS(1000);
		GPIOA->ODR ^= LED_PIN;
		printf("a second just passed \n\r");
	}
}



