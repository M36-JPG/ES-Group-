#ifndef INTERFACING_H
#define INTERFACING_H
#include "STD_TYPES.h"
#define GPIO_OUTPUT  1
#define GPIO_INPUT   0
#define HIGH         1
#define LOW          0
#define PORTB        0
#define PORTC        1
#define PORTD        2
#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7
#define GPIO_OUTPUT_ALL  0xFF
#define GPIO_INPUT_ALL   0x00
void GPIO_SetPIN_Direction(u8 PORT, u8 PIN, u8 DIR);
void GPIO_SetPIN_Value(u8 PORT, u8 PIN, u8 VAL);
u8   GPIO_GETPIN_Value(u8 PORT, u8 PIN);
void GPIO_SetPORT_Direction(u8 PORT, u8 DIR);
void GPIO_SetPORT_Value(u8 PORT, u8 VAL);
#endif
