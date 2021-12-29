/*
 * adc.c
 *
 *  Created on: Dec 29, 2021
 *      Author: michael
 */

#define GPIOAEN			(1U<<2)
#define ADC1EN		(1U<<9)

void pa1_adc_init(void)
{
	/********* Cpnfigure the ADC GPIO pin *********/

	/* Enable clock access to GPIOA */
	RCC->APB2ENR |= GPIOAEN;

	/* Set the mode of PA1 to analog mode */
	GPIOA->CRL &= ~(1U<<7);
	GPIOA->CRL &= ~(1U<<6);
	GPIOA->CRL &= ~(1U<<5);
	GPIOA->CRL &= ~(1U<<4);

	/********* Configure the ADC module ***********/

	/* Enable clock access to adc */

	/* Configure adc parameters */

}
