#ifndef KEYPAD_H
#define KEYPAD_H

#include "STD_TYPES.h"

#define KEYPAD_PORT    PORTD

#define R0 PIN0
#define R1 PIN1
#define R2 PIN2
#define R3 PIN3
#define C0 PIN4
#define C1 PIN5
#define C2 PIN6
#define C3 PIN7

void KEYPAD_Init(void);
u8 KEYPAD_GetPressedKey(void);

#endif





