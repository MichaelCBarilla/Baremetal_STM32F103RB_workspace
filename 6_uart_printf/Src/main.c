#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"

/* LQFP64 Package */

#define GPIOAEN			(1U<<2)
#define UART2EN			(1U<<17)

#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)

#define SYS_FREQ		(8000000)
#define APB1_CLK		(SYS_FREQ)
#define UART_BAUDRATE	(115200)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_tx_init(void);
void uart2_write(int ch);


int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

int main(void)
{

	uart2_tx_init();

	while(1)
	{

		printf("Hello from STM32F1.......\n\r");
		for (int i = 0; i < 500000; i++) {}
	}
}

void uart2_tx_init(void)
{
	/************ Configure uart gpio pin *********/
	/* Enable clock access to GPIOA */
	RCC->APB2ENR |= GPIOAEN;

	/* Set PA2 mode to alternate function mode */
	GPIOA->CRL |= (1U<<11);
	GPIOA->CRL &= ~(1U<<10);
	GPIOA->CRL |= (1U<<9);
	GPIOA->CRL &= ~(1U<<8);

	/*
	 * Set PA2 alternate function type to UART_TX,
	 * Since this is default for F103RB, no remapping required
	 */


	/************ Configure uart module ***********/
	/* Enable clock access to uart2 */
	RCC->APB1ENR |= UART2EN;

	/* Configure baudrate */
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/* Configure the transfer direction */
	USART2->CR1 = CR1_TE;

	/* Enable uart module */
	USART2->CR1 |= CR1_UE;
}

void uart2_write(int ch)
{
	/* Make sure the transmit data register is empty */
	while (!(USART2->SR & SR_TXE)) {}

	/* Write to transmit data register */
	USART2->DR = (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate / 2U)) / BaudRate);
}
