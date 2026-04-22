#define F_CPU 1000000UL
#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"

int main(void) {
    u8 key;
    s32 n1 = 0, n2 = 0, res = 0;
    u8 op = 0, state = 0;

    LCD_Init();
    KEYPAD_Init();
    LCD_SendString("Calculator:");
    _delay_ms(1000);
    LCD_ClearScreen();

    while(1) {
        key = KEYPAD_GetPressedKey();
        if(key != 0xFF) {
            if(key >= '0' && key <= '9') {
                LCD_SendChar(key);
                if(state == 0) n1 = (n1 * 10) + (key - '0');
                else n2 = (n2 * 10) + (key - '0');
            } 
            else if(key == '+' || key == '-' || key == '*' || key == '/') {
                LCD_SendChar(key);
                op = key;
                state = 1;
            } 
            else if(key == '=') {
                LCD_ClearScreen();
                switch(op) {
                    case '+': res = n1 + n2; break;
                    case '-': res = n1 - n2; break;
                    case '*': res = n1 * n2; break;
                    case '/': 
                        if(n2 != 0) res = n1 / n2; 
                        else { LCD_SendString("Div by 0!"); _delay_ms(1000); key='C'; }
                        break;
                }
                
                if (key != 'C') {
                   
                    if(res < 0) { LCD_SendChar('-'); res = -res; }
                    if(res == 0) LCD_SendChar('0');
                    else {
                        u8 buf[11]; s8 i=0;
                        while(res > 0) { buf[i++] = (res % 10) + '0'; res /= 10; }
                        while(--i >= 0) LCD_SendChar(buf[i]);
                    }
                }
                
                n1 = 0; n2 = 0; state = 0; 
            } 
            else if(key == 'C') {
                LCD_ClearScreen();
                n1 = 0; n2 = 0; state = 0;
            }
        }
    }
}






