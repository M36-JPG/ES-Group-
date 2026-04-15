#include "7_SEGMANT.h"
#include "GPIO_INTERFACE.h"

u8 SevenSegArr[10] = {
    0x3F, 
    0x06, 
    0x5B, 
    0x4F, 
    0x66, 
    0x6D, 
    0x7D, 
    0x07, 
    0x7F, 
    0x6F  
};

void SEVEN_SEG_VoidInit(void)
{
    GPIO_VidSetPortDirection(GPIO_PORTC, 0xFF);
}

void SEVEN_SEG_VoidDisplay(u8 Copy_u8Num)
{
    GPIO_VidSetPortValue(GPIO_PORTC, SevenSegArr[Copy_u8Num]);
}

void SEVEN_SEG_VoidOff(void)
{
    GPIO_VidSetPortValue(GPIO_PORTC, 0x00);
}