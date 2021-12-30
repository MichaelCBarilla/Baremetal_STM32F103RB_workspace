/*
 * exti.c
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#include "exti.h"

#define GPIOCEN			(1U<<4)
#define AFIOEN			(1U<<0)
#define IMR_13			(1U<<13)
#define FTSR_13			(1U<<13)


void pc13_exti_init(void)
{
	/* Disable global interrupts */
	__disable_irq();

	/* Enable clock access for GPIOC */
	RCC->APB2ENR |= GPIOCEN;

	/* Enable clock access to AFIO */
	RCC->APB2ENR |= AFIOEN;

	/* Set PC13 as input */
	GPIOC->CRH  |= (1U<<23);
	GPIOC->CRH  &= ~(1U<<22);
	GPIOC->CRH  &= ~(1U<<21);
	GPIOC->CRH  &= ~(1U<<20);

	/* Select PORTC for EXTI13 */
	AFIO->EXTICR[3] &= ~(1U<<7);
	AFIO->EXTICR[3] &= ~(1U<<6);
	AFIO->EXTICR[3] |= (1U<<5);
	AFIO->EXTICR[3] &= ~(1U<<4);

	/* Unmask EXTI13 */
	EXTI->IMR |= IMR_13;

	/* Select falling edge trigger */
	EXTI->FTSR |= FTSR_13;

	/* Enable EXTI13 line in NVIC */
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	/* Enable global interrupts */
	__enable_irq();

}
