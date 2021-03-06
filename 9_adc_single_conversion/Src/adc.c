/*
 * adc.c
 *
 *  Created on: Dec 29, 2021
 *      Author: michael
 */

#include "adc.h"

#define GPIOAEN			(1U<<2)
#define ADC1EN			(1U<<9)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	(0x00)
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART		(1U<<22)
#define SR_EOC			(1U<<1)

 /*
  * adc configured with 3 channels example
  * =======================================
  *
  * ch2, ch3, ch5
  * first = ch5
  * second = ch2
  * third channel = ch3
  *
  * first, put binary value 5 in SQ1 in ADC_SQR3 register
  * then, put binary value 2 in SQ2 in ADC_SQR3 register
  * then, put binary value 3 in SQ3 in ADC_SQR3 register
  */

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
	RCC->APB2ENR |= ADC1EN;

	/* Conversion sequence start */
	ADC1->SQR3 = ADC_CH1;

	/* Conversion sequence length */
	ADC1->SQR1 = ADC_SEQ_LEN_1;

	/* Enable the ADC module */
	ADC1->CR2 = CR2_ADON;
}

void start_conversion(void)
{
	/********* Start adc conversion *************/
	/* when CR2's ADON bit is set to 1, write 1 bit to start a conversion */
	ADC1->CR2 |= CR2_ADON;

}

uint32_t adc_read(void)
{
	/* Wait for conversion to be complete */
	while (!(ADC1->SR & SR_EOC)) {}

	/* Read conversion result */
	return (ADC1->DR);
}
