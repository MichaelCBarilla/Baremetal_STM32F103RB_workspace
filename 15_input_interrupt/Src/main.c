#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

#define GPIOAEN			(1U<<2)

#define PIN5			(1U<<5)
#define LED_PIN			(PIN5)

static void exti_callback(void);

int main(void)
{
	RCC->APB2ENR |= GPIOAEN;

	GPIOA->CRL &= ~(1U<<23);
	GPIOA->CRL &= ~(1U<<22);
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL &= ~(1U<<20);

	uart2_tx_init();

	pc13_exti_init();

	while(1)
	{


	}
}

static void exti_callback(void)
{
	printf("BTN Pressed...\n\r");
	GPIOA->ODR ^= LED_PIN;
}


void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & LINE13) {
		/* Clear the PR flag */
		EXTI->PR |= LINE13;

		/* Do Something */
		exti_callback();
	}
}


