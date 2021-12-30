/*
 * tim.c
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#include "tim.h"

#define GPIOAEN		(1U<<2)

#define TIM2EN		(1U<<0)
#define TIM3EN		(1U<<1)

#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	(1U<<4) | (1U<<5)
#define CCER_CC1E	(1U<<0)
#define CCER_CC1S	(1U<<0)

void tim2_1hz_init(void)
{
	/* Enable clock access to tim2 */
	RCC->APB1ENR |= TIM2EN;

	/* Set prescaler value */
	TIM2->PSC = 800 - 1; 			// 8 000 000 / 800 = 10 000

	/* Set auto-reload value */
	TIM2->ARR = 10000 - 1;			// 10 000 / 10 000 = 1

	/* Clear counter */
	TIM2->CNT = 0;

	/* Enable timer */
	TIM2->CR1 = CR1_CEN;

}

void tim2_pa0_output_compare(void)
{
	/* Enable clock access to GPIOA */
	RCC->APB2ENR |= GPIOAEN;

	/* Set PA0 mode to alternate function */
	GPIOA->CRL |= (1U<<3);
	GPIOA->CRL &= ~(1U<<2);
	GPIOA->CRL |= (1U<<1);
	GPIOA->CRL &= ~(1U<<0);

	/* Enable clock access to tim2 */
	RCC->APB1ENR |= TIM2EN;

	/* Set prescaler value */
	TIM2->PSC = 800 - 1; 			// 8 000 000 / 800 = 10 000

	/* Set auto-reload value */
	TIM2->ARR = 10000 - 1;			// 10 000 / 10 000 = 1

	/* Set output compare toggle mode */
	TIM2->CCMR1 = OC_TOGGLE
			;
	/* Enable tim2 ch1 to compare mode */
	TIM2->CCER |= CCER_CC1E;

	/* Clear counter */
	TIM2->CNT = 0;

	/* Enable tim2 */
	TIM2->CR1 = CR1_CEN;

}

void tim3_pa6_input_capture(void)
{
	/* Enable clock access to GPIOA */
	RCC->APB2ENR |= GPIOAEN;

	/* Set PA6 mode to alternate function */
	GPIOA->CRL |= (1U<<27);
	GPIOA->CRL &= ~(1U<<26);
	GPIOA->CRL |= (1U<<25);
	GPIOA->CRL &= ~(1U<<24);

	/* Enable clock access to tim3 */
	RCC->APB1ENR |= TIM3EN;

	/* Set prescaler value */
	TIM3->PSC = 8000 - 1; 			// 8 000 000 / 8000 = 1 000

	/* Set CH1 to input mode */
	TIM3->CCMR1 = CCER_CC1S;

	/* Set CH1 to capture at rising edge */
	TIM3->CCER |= CCER_CC1E;

	/* Enable tim3 */
	TIM3->CR1 = CR1_CEN;
}

