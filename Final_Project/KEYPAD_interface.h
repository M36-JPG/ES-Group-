#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H


#include "GPIO_interface.h"

void KEYPAD_Init(void);
u8 KEYPAD_GetKey(void);

#endif
