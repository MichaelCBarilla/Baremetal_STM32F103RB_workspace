/*
 * exti.h
 *
 *  Created on: Dec 30, 2021
 *      Author: michael
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f1xx.h"

void pc13_exti_init(void);

#define LINE13			(1U<<13)

#endif /* EXTI_H_ */
