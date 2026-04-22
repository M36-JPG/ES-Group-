#define F_CPU 1000000UL
#include <util/delay.h>
#include "INTERFACING.h"
#include "LCD.h"

void LCD_Init(void) {
    GPIO_SetPORT_Direction(LCD_DATA_PORT, 0xFF);
    GPIO_SetPIN_Direction(LCD_CTRL_PORT, LCD_RS_PIN, GPIO_OUTPUT);
    GPIO_SetPIN_Direction(LCD_CTRL_PORT, LCD_RW_PIN, GPIO_OUTPUT);
    GPIO_SetPIN_Direction(LCD_CTRL_PORT, LCD_EN_PIN, GPIO_OUTPUT);
    
    _delay_ms(40);
    LCD_SendCommand(0x38); 
    LCD_SendCommand(0x0C); 
    LCD_SendCommand(0x01); 
}

void LCD_SendCommand(u8 cmd) {
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    GPIO_SetPORT_Value(LCD_DATA_PORT, cmd);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_us(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    _delay_ms(2);
}

void LCD_SendChar(u8 data) {
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    GPIO_SetPORT_Value(LCD_DATA_PORT, data);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_us(1);
    GPIO_SetPIN_Value(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
    _delay_ms(2);
}

void LCD_SendString(const char* str) {
    while(*str) LCD_SendChar(*str++);
}

void LCD_ClearScreen(void) {
    LCD_SendCommand(0x01);
}


