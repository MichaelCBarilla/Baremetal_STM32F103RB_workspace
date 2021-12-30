/*
 * adc.h
 *
 *  Created on: Dec 29, 2021
 *      Author: michael
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f1xx.h"

void pa1_adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);


#endif /* ADC_H_ */
