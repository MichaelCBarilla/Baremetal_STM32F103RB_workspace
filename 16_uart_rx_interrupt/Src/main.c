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

static void uart_callback(void);

char key;
int main(void)
{
	/* Enable clock access to GPIOA */
	RCC->APB2ENR |= GPIOAEN;

	/* Set PA5 as output pin */
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL &= ~(1U<<20);
	GPIOA->CRL &= ~(1U<<22);
	GPIOA->CRL &= ~(1U<<23);

	uart2_rx_interrupt_init();

	while(1)
	{

	}
}

static void uart_callback(void)
{
	key = USART2->DR;

	key = uart2_read();
	if (key == '1')
		GPIOA->ODR |= LED_PIN;
	else
		GPIOA->ODR &= ~LED_PIN;
}

void USART2_IRQHandler(void)
{
	/* Check if RXNE is set */
	if (USART2->SR & SR_RXNE) {

		/* Do something */
		uart_callback();
	}
}
