/*
 * uart.h
 *
 *  Created on: Dec 29, 2021
 *      Author: michael
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "stm32f1xx.h"

void uart2_rxtx_init(void);
void uart2_tx_init(void);
char uart2_read(void);
void uart2_write(int ch);
void uart2_rx_interrupt_init(void);
void uart2_tx_interrupt_init(void);

#define SR_RXNE			(1U<<5)
#define SR_TXE			(1U<<7)

#endif /* UART_H_ */
