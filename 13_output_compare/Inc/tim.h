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
void tim2_output_compare(void);

#define SR_UIF (1U<<0)
#endif /* TIM_C_ */
