/*
 * systick.c
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#include "systick.h"

#define SYSTICK_LOAD_VAL	(8000) /* amount of cycles in a ms, based on default clock */
#define CTRL_ENABLE			(1U<<0)
#define CTRL_CLKSRC			(1U<<2)
#define CTRL_COUNTFLAG		(1U<<16)
#define CTRL_TICKINT		(1U<<1)

#define ONE_SEC_LOAD		(8000000)


void systickDelayMS(int delay)
{
	/* Reload with number of clocks per millisecond */
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/* Clear systick current value register */
	SysTick->VAL = 0;

	/* Enable systick and select internal clk src */
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for (int i=0; i<delay; i++) {
		/* Wait until the COUNTFLAG is set */
		while ((SysTick->CTRL & CTRL_COUNTFLAG) == 0) {}
	}

	SysTick->CTRL = 0;
}

void systick_1hz_interrupt(void)
{
	/* Reload with number of clocks per second */
	SysTick->LOAD = ONE_SEC_LOAD - 1;

	/* Clear systick current value register */
	SysTick->VAL = 0;

	/* Enable systick,select internal clk src, and tick interrupt */
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC | CTRL_TICKINT;

}
