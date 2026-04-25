#ifndef ADC_H
#define ADC_H

#include "GPIO_STD_TYPES.h"

void ADC_Init(void);
void ADC_StartConversion(u8 copy_u8Channel);

#endif
