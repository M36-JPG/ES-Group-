#ifndef LCD_H
#define LCD_H

#include "STD_TYPES.h"

#define LCD_DATA_PORT  PORTB
#define LCD_CTRL_PORT  PORTC
#define LCD_RS_PIN     PIN0
#define LCD_RW_PIN     PIN1
#define LCD_EN_PIN     PIN2

void LCD_Init(void);
void LCD_SendCommand(u8 cmd);
void LCD_SendChar(u8 data);
void LCD_SendString(const char* str);
void LCD_ClearScreen(void);

#endif

