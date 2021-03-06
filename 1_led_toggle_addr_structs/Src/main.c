/* Where is the led connected? */
/* Port: A */
/* Pin:	 5 */

#include <stdint.h>

#define PERIPH_BASE			(0x40000000UL)

#define APB2PERIPH_OFFSET  	(0x00010000UL)
#define APB2PERIPH_BASE		(PERIPH_BASE + APB2PERIPH_OFFSET)
#define GPIOA_OFFSET		(0x00000800UL)
#define GPIOA_BASE			(APB2PERIPH_BASE + GPIOA_OFFSET)

#define AHBPERIPH_OFFSET 	(0x00018000UL)
#define AHBPERIPH_BASE		(PERIPH_BASE + AHBPERIPH_OFFSET)
#define RCC_OFFSET			(0x00009000UL)
#define RCC_BASE			(AHBPERIPH_BASE + RCC_OFFSET)

#define IOPAEN				(1U<<2)	//0b 0000 0000 0000 0000 0000 0000 0000 0100

#define PIN5				(1U<<5)
#define LED_PIN				(PIN5)

//#define __IO volatile

//typedef struct
//{
//  __IO uint32_t CR;            /*!< RCC clock control register,                 Address offset: 0x00   */
//  __IO uint32_t CFGR;          /*!< RCC clock configuration register,           Address offset: 0x04   */
//  __IO uint32_t CIR;           /*!< RCC clock interrupt register,               Address offset: 0x08   */
//  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,         Address offset: 0x0C   */
//  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,         Address offset: 0x10   */
//  __IO uint32_t AHBENR;        /*!< RCC AHB peripheral clock enable register,   Address offset: 0x14   */
//  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x18   */
//  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,  Address offset: 0x1C   */
//  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,         Address offset: 0x20   */
//  __IO uint32_t CSR;           /*!< RCC clock control & status register,        Address offset: 0x24   */
//} RCC_TypeDef;

typedef struct
{
  volatile uint32_t DUMMY[6];    /*!< RCC AHB peripheral clock enable register,   Address offset: 0x14   */
  volatile uint32_t APB2ENR;     /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x18   */
} RCC_TypeDef;

//typedef struct
//{
//	  __IO uint32_t CRL;      /*!< GPIO port low mode and config register,  Address offset: 0x00      */
//	  __IO uint32_t CRH;      /*!< GPIO port high mode and config register, Address offset: 0x04      */
//	  __IO uint32_t IDR;      /*!< GPIO port input data register,           Address offset: 0x08      */
//	  __IO uint32_t ODR;      /*!< GPIO port output data register,          Address offset: 0x0C      */
//	  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,        Address offset: 0x10      */
//	  __IO uint32_t BRR;      /*!< GPIO port bit reset register,            Address offset: 0x14      */
//	  __IO uint32_t LCKR;     /*!< GPIO port config lock register,          Address offset: 0x18      */
//} GPIO_TypeDef;

typedef struct
{
	volatile uint32_t CRL;      /*!< GPIO port low mode and config register,  Address offset: 0x00      */
	volatile uint32_t DUMMY[2];
	volatile uint32_t ODR;      /*!< GPIO port output data register,          Address offset: 0x0C      */
} GPIO_TypeDef;

#define RCC 	((RCC_TypeDef*)RCC_BASE)
#define GPIOA	((GPIO_TypeDef*)GPIOA_BASE)

int main()
{
	/* Enable clock access to gpioa */
	RCC->APB2ENR |= IOPAEN;

	/* set PA5 as output pin */
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL &=~(1U<<20);
	GPIOA->CRL &=~(1U<<22);
	GPIOA->CRL &=~(1U<<23);

	while(1) {
		GPIOA->ODR ^= LED_PIN;
		for (int i = 0; i < 100000; i++) {

		}
	}

}
