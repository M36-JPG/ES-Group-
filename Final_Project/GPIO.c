#include "GPIO_STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include <avr/io.h>

void GPIO_SetPIN_Direction(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction) {
    if (copy_u8Direction == OUTPUT) {
        if (copy_u8Port == GPIO_PORTB) SET_BIT(DDRB, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTC) SET_BIT(DDRC, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTD) SET_BIT(DDRD, copy_u8Pin);
    } else {
        if (copy_u8Port == GPIO_PORTB) CLR_BIT(DDRB, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTC) CLR_BIT(DDRC, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTD) CLR_BIT(DDRD, copy_u8Pin);
    }
}

void GPIO_SetPIN_Value(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value) {
    if (copy_u8Value == HIGH) {
        if (copy_u8Port == GPIO_PORTB) SET_BIT(PORTB, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTC) SET_BIT(PORTC, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTD) SET_BIT(PORTD, copy_u8Pin);
    } else {
        if (copy_u8Port == GPIO_PORTB) CLR_BIT(PORTB, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTC) CLR_BIT(PORTC, copy_u8Pin);
        else if (copy_u8Port == GPIO_PORTD) CLR_BIT(PORTD, copy_u8Pin);
    }
}

u8 GPIO_GetPIN_Value(u8 copy_u8Port, u8 copy_u8Pin) {
    u8 result = 0;
    if (copy_u8Port == GPIO_PORTB) result = GET_BIT(PINB, copy_u8Pin);
    else if (copy_u8Port == GPIO_PORTC) result = GET_BIT(PINC, copy_u8Pin);
    else if (copy_u8Port == GPIO_PORTD) result = GET_BIT(PIND, copy_u8Pin);
    return result;
}

void GPIO_SetPORT_Direction(u8 copy_u8Port, u8 copy_u8Direction) {
    if (copy_u8Port == GPIO_PORTB) DDRB = copy_u8Direction;
    else if (copy_u8Port == GPIO_PORTC) DDRC = copy_u8Direction;
    else if (copy_u8Port == GPIO_PORTD) DDRD = copy_u8Direction;
}

void GPIO_SetPORT_Value(u8 copy_u8Port, u8 copy_u8Value) {
    if (copy_u8Port == GPIO_PORTB) PORTB = copy_u8Value;
    else if (copy_u8Port == GPIO_PORTC) PORTC = copy_u8Value;
    else if (copy_u8Port == GPIO_PORTD) PORTD = copy_u8Value;
}
