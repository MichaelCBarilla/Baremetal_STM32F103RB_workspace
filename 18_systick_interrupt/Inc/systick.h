/*
 * systick.h
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f1xx.h"

void systickDelayMS(int delay);
void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
