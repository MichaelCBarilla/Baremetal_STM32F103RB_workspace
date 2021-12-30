#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

static void uart_callback(void);

char message[5] = "he\n\r\0";
int main(void)
{


	uart2_tx_interrupt_init();
	uart2_write(*message);
	while(1)
	{

	}
}

static void uart_callback(void)
{
	for (int i = 0; i < 4; i++) {
		uart2_write(message[i]);
	}
}

void USART2_IRQHandler(void)
{
	/* Check if RXNE is set */
	if (USART2->SR & SR_TXE) {

		/* Do something */
		uart_callback();

	}

}
