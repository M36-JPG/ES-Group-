#include "KEYPAD.h"


void KEYPAD_VoidInit(void){
    
    GPIO_VidSetPortDirection(KEYPAD_Port,KEYPAD_PortDirection);
    GPIO_VidSetPortValue(KEYPAD_Port,GPIO_HIGH);

}


u8 KEYPAD_U8GetPressedKey(void)
{
   u8 Loc_U8PinVal;
   u8 Loc_U8PressedKey = 0xFF;
   u8 Loc_U8KEYPADCOLArr[KEYPAD_COLNUM] = {KEYPAD_COL1, KEYPAD_COL2, KEYPAD_COL3, KEYPAD_COL4};
   u8 Loc_U8KEYPADROWArr[KEYPAD_ROWNUM] = {KEYPAD_ROW1, KEYPAD_ROW2, KEYPAD_ROW3,KEYPAD_ROW4 };

   u8 Loc_U8KEYPADArr [KEYPAD_ROWNUM] [KEYPAD_COLNUM] = KEYPAD_Arr;

   for(int i=0;i<KEYPAD_COLNUM;i++)
   {

     GPIO_VidSetPinValue(KEYPAD_Port,Loc_U8KEYPADCOLArr[i],GPIO_LOW);

     for(int j=0;j< KEYPAD_ROWNUM;j++)
     {

         Loc_U8PinVal= GPIO_U8GetPinValue(KEYPAD_Port,Loc_U8KEYPADROWArr[j]);

          if(Loc_U8PinVal == GPIO_LOW)
          {
       
              Loc_U8PressedKey = Loc_U8KEYPADArr[j][i];
              while (Loc_U8PinVal == GPIO_LOW)
              {
               
                Loc_U8PinVal= GPIO_U8GetPinValue(KEYPAD_Port,Loc_U8KEYPADROWArr[j]);
              }
              _delay_ms(10);

     
          }

      }

       GPIO_VidSetPinValue(KEYPAD_Port,Loc_U8KEYPADCOLArr[i],GPIO_HIGH);
    }

   return Loc_U8PressedKey;

}




