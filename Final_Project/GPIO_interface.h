#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_STD_TYPES.h"

#define GPIO_PORTB 0
#define GPIO_PORTC 1
#define GPIO_PORTD 2

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1

void GPIO_SetPIN_Direction(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);
void GPIO_SetPIN_Value(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);
void GPIO_SetPORT_Direction(u8 copy_u8Port, u8 copy_u8Direction);
void GPIO_SetPORT_Value(u8 copy_u8Port, u8 copy_u8Value);
u8 GPIO_GetPIN_Value(u8 copy_u8Port, u8 copy_u8Pin);

#endif
