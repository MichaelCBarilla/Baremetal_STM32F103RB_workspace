/*
 * tim.c
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#ifndef TIM_C_
#define TIM_C_

#include "stm32f1xx.h"

void tim2_1hz_init(void);
void tim2_pa0_output_compare(void);
void tim3_pa6_input_capture(void);

#define SR_UIF 		(1U<<0)
#define SR_CC1IF	(1U<<1)
#endif /* TIM_C_ */
