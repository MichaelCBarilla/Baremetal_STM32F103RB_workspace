/* Where is the led connected? */
/* Port: A */
/* Pin:	 5 */

#define PERIPH_BASE			(0x40000000UL)

#define APB2PERIPH_OFFSET  	(0x00010000UL)
#define APB2PERIPH_BASE		(PERIPH_BASE + APB2PERIPH_OFFSET)
#define GPIOA_OFFSET		(0x00000800UL)
#define GPIOA_BASE			(APB2PERIPH_BASE + GPIOA_OFFSET)

#define AHBPERIPH_OFFSET 	(0x00018000UL)
#define AHBPERIPH_BASE		(PERIPH_BASE + AHBPERIPH_OFFSET)
#define RCC_OFFSET			(0x00009000UL)
#define RCC_BASE			(AHBPERIPH_BASE + RCC_OFFSET)

#define RCC_APB2ENR_OFFSET	(0x18UL)
#define RCC_APB2EN_R		(*(volatile unsigned int*)(RCC_BASE + RCC_APB2ENR_OFFSET))

#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int*)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x0CUL)
#define GPIOA_OD_R			(*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

#define IOPAEN				(1U<<2)	//0b 0000 0000 0000 0000 0000 0000 0000 0100

#define PIN5				(1U<<5)
#define LED_PIN				(PIN5)


/*
 * (1U<<21) set bit 21 to 1
 * &=~(1U<<20) set bit 20 to 0
 * &=~(1U<<22) set bit 22 to 0
 * &=~(1U<<23) set bit 23 to 0
 */


int main()
{
	/* Enable clock access to gpioa */
	RCC_APB2EN_R |= IOPAEN;

	/* set PA5 as output pin */
	GPIOA_MODE_R |= (1U<<21);
	GPIOA_MODE_R &=~(1U<<20);
	GPIOA_MODE_R &=~(1U<<22);
	GPIOA_MODE_R &=~(1U<<23);
	while(1) {
		/* inside infinite loop, turn on the led */
//		GPIOA_OD_R |= LED_PIN;

		/* Toggle PA5 */
		GPIOA_OD_R ^= LED_PIN;
		for (int i = 0; i < 1000000; i++) {

		}
	}

}
