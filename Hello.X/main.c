#include "LCD.h"


#define F_CPU 1000000UL  // 1 MHz clock
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    LCD_Init();
    LCD_SendString("Hello");
    LCD_SetCursor(1,0);
    LCD_SendString("ATmega328P");
    
    while (1)
    {
        
    }
}