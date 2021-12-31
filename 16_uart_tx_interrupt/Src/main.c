#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

static void uart_callback(void);

uint8_t message[5] = "TEST\0";
int main(void)
{


	uart2_tx_interrupt_init();
	USART2->DR = ((*message) & 0xFF);
	while(1)
	{

	}
}

static void uart_callback(void)
{
	for (uint8_t i = 1; i < 5; i++) {
		USART2->DR = (message[i] & 0xFF);
	}
}

void USART2_IRQHandler(void)
{
	/* Check if TXE is set */
	if (USART2->SR & SR_TXE) {

		/* Do something */
		uart_callback();

	}

}
