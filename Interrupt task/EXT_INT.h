#ifndef EXT_INT_H
#define EXT_INT_H

#include "STD_TYPES.h"

// Sense Control
#define LOW_LEVEL     0x00
#define ANY_CHANGE    0x01
#define FALLING_EDGE  0x02
#define RISING_EDGE   0x03

void EXT_INT0_Init(u8 sense);
void EXT_INT0_Enable(void);
void EXT_INT_GlobalEnable(void);
void EXT_INT0_SetCallback(void (*ptr)(void));

#endif