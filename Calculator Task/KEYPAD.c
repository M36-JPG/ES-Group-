#define F_CPU 1000000UL
#include <util/delay.h>
#include "INTERFACING.h"
#include "KEYPAD.h"

void KEYPAD_Init(void) {

    GPIO_SetPORT_Direction(KEYPAD_PORT, 0xF0); 
    GPIO_SetPORT_Value(KEYPAD_PORT, 0xFF); 
}

u8 KEYPAD_GetPressedKey(void) 
{
    u8 cols[] = {C0, C1, C2, C3};
    u8 rows[] = {R0, R1, R2, R3};
  
    u8 keys[4][4] = 
    {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'C', '0', '=', '+'}
    };

    for(u8 c=0; c<4; c++)
    {
        GPIO_SetPIN_Value(KEYPAD_PORT, cols[c], LOW);
            for(u8 r=0; r<4; r++) 
            {
                if(GPIO_GETPIN_Value(KEYPAD_PORT, rows[r]) == LOW)
                {
                    _delay_ms(20); 
                    while(GPIO_GETPIN_Value(KEYPAD_PORT, rows[r]) == LOW);
                    _delay_ms(20);
                    GPIO_SetPIN_Value(KEYPAD_PORT, cols[c], HIGH);
                    return keys[r][c];
                }
            }
            GPIO_SetPIN_Value(KEYPAD_PORT, cols[c], HIGH);
    }
    return 0xFF;
}




