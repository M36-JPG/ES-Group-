#ifndef KEYPAD_H
#define KEYPAD_H
#include "STD_TYPES.h"
#include "GPIO_INTERFACE.h"
#define KEYPAD_PortDirection 0xF0
#define KEYPAD_Port GPIO_PORTD 

#define KEYPAD_Arr{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}

#define KEYPAD_ROW1 GPIO_PIN0
#define KEYPAD_ROW2 GPIO_PIN1
#define KEYPAD_ROW3 GPIO_PIN2
#define KEYPAD_ROW4 GPIO_PIN3

#define KEYPAD_COL1 GPIO_PIN4
#define KEYPAD_COL2 GPIO_PIN5
#define KEYPAD_COL3 GPIO_PIN6
#define KEYPAD_COL4 GPIO_PIN7

#define KEYPAD_ROWNUM 4
#define KEYPAD_COLNUM 4


void KEYPAD_VoidInit(void);

u8 KEYPAD_U8GetPressedKey(void);


#endif
