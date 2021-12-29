#include "stm32f1xx.h"

#define GPIOAEN			(1U<<2)
#define GPIOCEN			(1U<<4)

#define PIN5			(1U<<5)
#define PIN13			(1U<<13)

#define LED_PIN			(PIN5)
#define BTN_PIN			(PIN13)

int main(void)
{
	/* Enable clock access to GPIOA and GPIOC */
	RCC->APB2ENR |= GPIOAEN;
	RCC->APB2ENR |= GPIOCEN;

	/* Set PA5 as output pin */
	GPIOA->CRL &= ~(1U<<20);
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL &= ~(1U<<22);
	GPIOA->CRL &= ~(1U<<23);

	/* Set PC13 as input pin */
	GPIOC->CRH &= ~(1U<<20);
	GPIOC->CRH &= ~(1U<<21);
	GPIOC->CRH &= ~(1U<<22);
	GPIOC->CRH |= (1U<<23);

	while(1)
	{
		/* Check if BTN is pressed */
		if (GPIOC->IDR & BTN_PIN) {
			/* Turn on led */
			GPIOA->BSRR = LED_PIN;
		} else {
			/* Turn off led */
			GPIOA->BSRR = (1U<<21);
		}
	}
}
