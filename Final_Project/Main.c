#include "GPIO_interface.h"
#include "LCD.h"
#include "ADC.h"
#include "Timer.h"

extern volatile u16 ADC_Values[3];
u16 alarm_count = 0;
u8 alarm_flag = 0;

int main(void) {
    LCD_Init();
    ADC_Init();
    Timer0_Init();
    
    GPIO_SetPIN_Direction(GPIO_PORTC, PIN4, OUTPUT);
    GPIO_SetPIN_Direction(GPIO_PORTD, PIN7, OUTPUT);

    while(1) {
        ADC_StartConversion(0);
        Timer0_DelayMS(10);
        ADC_StartConversion(1);
        Timer0_DelayMS(10);
        ADC_StartConversion(2);
        Timer0_DelayMS(10);

        u16 temp = (ADC_Values[0] * 500UL) / 1024;
        u16 moisture = ADC_Values[1];
        u16 light = ADC_Values[2];

        if(temp > 35 && alarm_flag == 0) {
            alarm_count++;
            alarm_flag = 1;
            GPIO_SetPIN_Value(GPIO_PORTD, PIN7, HIGH);
        } else if(temp <= 35) {
            alarm_flag = 0;
            GPIO_SetPIN_Value(GPIO_PORTD, PIN7, LOW);
        }

        if(light > 500) { 
            GPIO_SetPIN_Value(GPIO_PORTC, PIN4, LOW);
        } else {
            GPIO_SetPIN_Value(GPIO_PORTC, PIN4, HIGH);
        }

        LCD_Clear();
        LCD_SendString("T:");
        LCD_SendChar((temp/10)+'0'); 
        LCD_SendChar((temp%10)+'0');
        
        LCD_SendString(" M:");
        LCD_SendChar(((moisture/100)%10)+'0');
        LCD_SendChar(((moisture/10)%10)+'0');
        
        LCD_SendCommand(0xC0);
        LCD_SendString("Alarms:");
        LCD_SendChar((alarm_count%10)+'0');
        
        LCD_SendString(" L:");
        LCD_SendChar(((light/100)%10)+'0');
        LCD_SendChar(((light/10)%10)+'0');

        Timer0_DelayMS(100);
    }
}


