#include "GPIO_STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer.h"
#include <avr/io.h>

void Timer0_Init(void) {
    TCCR0A = 0x02; 
    OCR0A = 250;   
}

void Timer0_DelayMS(u16 ms) {
    TCCR0B = 0x03; 
    for(u16 i=0; i<ms*4; i++) {
        while(GET_BIT(TIFR0, 1) == 0);
        SET_BIT(TIFR0, 1);
    }
    TCCR0B = 0;
}
