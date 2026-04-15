#include "STD_TYPES.h"
#include "KEYPAD.h"
#include "7_SEGMANT.h"

void main(void)
{
    u8 key;

    KEYPAD_VoidInit();
    SEVEN_SEG_VoidInit();

    while(1)
    {
        key = KEYPAD_U8GetPressedKey();

        if(key <= 9)   
        {
            SEVEN_SEG_VoidDisplay(key);
        }
        else           
        {
            SEVEN_SEG_VoidOff();
        }
    }
}