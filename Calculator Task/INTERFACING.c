#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_REG.h"
#include "INTERFACING.h"

void GPIO_SetPIN_Direction(u8 PORT, u8 PIN, u8 DIR) {
    if (DIR == GPIO_OUTPUT) {
        switch(PORT) {
            case PORTB: SET_BIT(DDRB_REG, PIN); break;
            case PORTC: SET_BIT(DDRC_REG, PIN); break;
            case PORTD: SET_BIT(DDRD_REG, PIN); break;
        }
    } else {
        switch(PORT) {
            case PORTB: CLR_BIT(DDRB_REG, PIN); break;
            case PORTC: CLR_BIT(DDRC_REG, PIN); break;
            case PORTD: CLR_BIT(DDRD_REG, PIN); break;
        }
    }
}

void GPIO_SetPIN_Value(u8 PORT, u8 PIN, u8 VAL) {
    if (VAL == HIGH) {
        switch(PORT) {
            case PORTB: SET_BIT(PORTB_REG, PIN); break;
            case PORTC: SET_BIT(PORTC_REG, PIN); break;
            case PORTD: SET_BIT(PORTD_REG, PIN); break;
        }
    } else {
        switch(PORT) {
            case PORTB: CLR_BIT(PORTB_REG, PIN); break;
            case PORTC: CLR_BIT(PORTC_REG, PIN); break;
            case PORTD: CLR_BIT(PORTD_REG, PIN); break;
        }
    }
}

u8 GPIO_GETPIN_Value(u8 PORT, u8 PIN) {
    u8 res = 0;
    switch(PORT) {
        case PORTB: res = GET_BIT(PINB_REG, PIN); break;
        case PORTC: res = GET_BIT(PINC_REG, PIN); break;
        case PORTD: res = GET_BIT(PIND_REG, PIN); break;
    }
    return res;
}

void GPIO_SetPORT_Direction(u8 PORT, u8 DIR) {
    switch(PORT) {
        case PORTB: DDRB_REG = DIR; break;
        case PORTC: DDRC_REG = DIR; break;
        case PORTD: DDRD_REG = DIR; break;
    }
}

void GPIO_SetPORT_Value(u8 PORT, u8 VAL) {
    switch(PORT) {
        case PORTB: PORTB_REG = VAL; break;
        case PORTC: PORTC_REG = VAL; break;
        case PORTD: PORTD_REG = VAL; break;
    }
}
