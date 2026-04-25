#include "GPIO_STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile u16 ADC_Values[3] = {0}; 
static u8 current_ch = 0;

void ADC_Init(void) {
    ADMUX = (1 << REFS0); 
    ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1); 
    SREG |= (1 << 7); 
}

void ADC_StartConversion(u8 copy_u8Channel) {
    current_ch = copy_u8Channel;
    ADMUX &= 0xF0;
    ADMUX |= (copy_u8Channel & 0x0F);
    ADCSRA |= (1 << ADSC);
}

ISR(ADC_vect) {
    ADC_Values[current_ch] = ADC;
}
