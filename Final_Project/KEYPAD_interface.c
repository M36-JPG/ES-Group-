#include "GPIO_STD_TYPES.h"
#include "GPIO_interface.h"
#include "KEYPAD_interface.h"


u8 Keys[4][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

u8 Rows[4] = {PIN0, PIN1, PIN2, PIN3}; 
u8 Cols[3] = {PIN4, PIN5, PIN6};       

void KEYPAD_Init(void) {
   
    for(u8 i=0; i<4; i++) {
        GPIO_SetPIN_Direction(GPIO_PORTB, Rows[i], OUTPUT);
        GPIO_SetPIN_Value(GPIO_PORTB, Rows[i], HIGH);
    }
  
    for(u8 i=0; i<3; i++) {
        GPIO_SetPIN_Direction(GPIO_PORTB, Cols[i], INPUT);
        GPIO_SetPIN_Value(GPIO_PORTB, Cols[i], HIGH); 
    }
}

u8 KEYPAD_GetKey(void) {
    for(u8 r=0; r<4; r++) {
        GPIO_SetPIN_Value(GPIO_PORTB, Rows[r], LOW); 
        for(u8 c=0; c<3; c++) {
            if(GPIO_GetPIN_Value(GPIO_PORTB, Cols[c]) == LOW) {
                while(GPIO_GetPIN_Value(GPIO_PORTB, Cols[c]) == LOW); 
                GPIO_SetPIN_Value(GPIO_PORTB, Rows[r], HIGH);
                return Keys[r][c];
            }
        }
        GPIO_SetPIN_Value(GPIO_PORTB, Rows[r], HIGH); 
    }
    return 0;
}
