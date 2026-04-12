#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_REG.h"
#include "GPIO_INTERFACE.h"

void GPIO_VidsetPinDirection(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction) {
    if (Copy_U8Pin <= 7) {
        if (Copy_U8Direction == GPIO_OUTPUT) {
            switch (Copy_U8Port) {
                case GPIO_PORTA: 
                 SET_BIT(DDRA_REG, Copy_U8Pin);
                 break;
                case GPIO_PORTB:
                 SET_BIT(DDRB_REG, Copy_U8Pin); 
                  break;
                case GPIO_PORTC: 
                 SET_BIT(DDRC_REG, Copy_U8Pin); 
                  break;
                case GPIO_PORTD:
                 SET_BIT(DDRD_REG, Copy_U8Pin);
                   break;
            }
        } else if (Copy_U8Direction == GPIO_INPUT) {
            switch (Copy_U8Port) {
                case GPIO_PORTA:
                 CLR_BIT(DDRA_REG, Copy_U8Pin);
                   break;
                case GPIO_PORTB:
                 CLR_BIT(DDRB_REG, Copy_U8Pin); 
                  break;
                case GPIO_PORTC:
                 CLR_BIT(DDRC_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTD:
                 CLR_BIT(DDRD_REG, Copy_U8Pin);
                  break;
            }
        }
    }
}

void GPIO_VidsetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value) {
    if (Copy_U8Pin <= 7) {
        if (Copy_U8Value == GPIO_HIGH) {
            switch (Copy_U8Port) {
                case GPIO_PORTA:
                 SET_BIT(PORTA_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTB:
                 SET_BIT(PORTB_REG, Copy_U8Pin); 
                  break;
                case GPIO_PORTC:
                 SET_BIT(PORTC_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTD:
                 SET_BIT(PORTD_REG, Copy_U8Pin);
                  break;
            }
        } else if (Copy_U8Value == GPIO_LOW) {
            switch (Copy_U8Port) {
                case GPIO_PORTA:
                 CLR_BIT(PORTA_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTB:
                 CLR_BIT(PORTB_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTC:
                 CLR_BIT(PORTC_REG, Copy_U8Pin);
                  break;
                case GPIO_PORTD:
                 CLR_BIT(PORTD_REG, Copy_U8Pin);
                  break;
            }
        }
    }
}

void GPIO_VidTogglePinValue(u8 Copy_U8Port, u8 Copy_U8Pin) {
    if (Copy_U8Pin <= 7) {
        switch (Copy_U8Port) {
            case GPIO_PORTA:
             TOG_BIT(PORTA_REG, Copy_U8Pin);
              break;
            case GPIO_PORTB:
             TOG_BIT(PORTB_REG, Copy_U8Pin);
              break;
            case GPIO_PORTC:
             TOG_BIT(PORTC_REG, Copy_U8Pin);
              break;
            case GPIO_PORTD:
             TOG_BIT(PORTD_REG, Copy_U8Pin);
              break;
        }

    }
}

u8 GPIO_U8GetPinValue(u8 Copy_U8Port, u8 Copy_U8Pin) {
    u8 Local_U8Result = 0;
    if (Copy_U8Pin <= 7) {
        switch (Copy_U8Port) {
            case GPIO_PORTA:
             Local_U8Result = GET_BIT(PINA_REG, Copy_U8Pin);
              break;
            case GPIO_PORTB:
             Local_U8Result = GET_BIT(PINB_REG, Copy_U8Pin);
              break;
            case GPIO_PORTC:
             Local_U8Result = GET_BIT(PINC_REG, Copy_U8Pin);
              break;
            case GPIO_PORTD:
             Local_U8Result = GET_BIT(PIND_REG, Copy_U8Pin);
              break;
        }
    }
    return Local_U8Result;
}


void GPIO_VidsetPortDirection(u8 Copy_U8Port, u8 Copy_U8Direction) {
    switch (Copy_U8Port) {
        case GPIO_PORTA:
         DDRA_REG = Copy_U8Direction;
          break;
        case GPIO_PORTB:
         DDRB_REG = Copy_U8Direction;
          break;
        case GPIO_PORTC:
         DDRC_REG = Copy_U8Direction;
          break;
        case GPIO_PORTD:
         DDRD_REG = Copy_U8Direction;
          break;
    }
}

void GPIO_VidsetPortValue(u8 Copy_U8Port, u8 Copy_U8Value) {
    switch (Copy_U8Port) {
        case GPIO_PORTA:
         PORTA_REG = Copy_U8Value;
          break;
        case GPIO_PORTB:
         PORTB_REG = Copy_U8Value;
          break;
        case GPIO_PORTC:
         PORTC_REG = Copy_U8Value;
          break;
        case GPIO_PORTD:
         PORTD_REG = Copy_U8Value;
          break;
    }
}

u8 GPIO_U8GetPortValue(u8 Copy_U8Port) {
    u8 Local_U8Result = 0;
    switch (Copy_U8Port) {
        case GPIO_PORTA:
         Local_U8Result = PINA_REG;
          break;
        case GPIO_PORTB:
         Local_U8Result = PINB_REG;
          break;
        case GPIO_PORTC:
         Local_U8Result = PINC_REG;
          break;
        case GPIO_PORTD:
         Local_U8Result = PIND_REG;
          break;
    }
    return Local_U8Result;
}