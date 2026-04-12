#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"

void Task_1(void) {
    GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);

    while (1) {

    }
}

void Task_2(void) {
    GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
     _delay_ms(1000);
    GPIO_VidTogglePinValue(GPIO_PORTA, GPIO_PIN0);
     _delay_ms(1000);


}

void Task_3(void) {
   GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);

    while (1) {
        _delay_ms(1000);
        GPIO_VidTogglePinValue(GPIO_PORTA, GPIO_PIN0);
    }
}

void Task_4(void) {
    GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
     GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
      GPIO_VidSetPinDirection(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);

    while(1){
      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
       _delay_ms(1000);
      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
       _delay_ms(1000);
      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
       _delay_ms(1000);

      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
      GPIO_VidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
       _delay_ms(1000);

    }
    
}

void Task_5(void) {
   GPIO_VidsetPortDirection(GPIO_PORTD, 0xFF);
   int array[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    while (1) {
        for (int i = 0; i < 10; i++) {
            GPIO_VidSetPortValue(GPIO_PORTD, array[i]);
             _delay_ms(1000);
        }
    }
}

void Task_6(void) {
    u8 Local_u8SwitchValue = 0;

    GPIO_VidSetPortDirection(GPIO_PORTA, GPIO_INPUT);
     GPIO_VidSetPortValue(GPIO_PORTA, 0xFF);
      GPIO_VidSetPortDirection(GPIO_PORTC, 0xFF); 

    while(1)
    {
        Local_u8SwitchValue = GPIO_U8GetPortValue(GPIO_PORTA);
        GPIO_VidSetPortValue(GPIO_PORTC, ~Local_u8SwitchValue);
        _delay_ms(500);
        
        GPIO_VidSetPortValue(GPIO_PORTC, 0x00);
        _delay_ms(500);

    }
}




int main() {
        //Task_1();
        //Task_2();
        //Task_3();
        //Task_4();
        //Task_5();
        //Task_6();
    return 0;
}


