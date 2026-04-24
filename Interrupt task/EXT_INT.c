#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXT_INT.h"

// Registers
#define EICRA (*(volatile u8*)0x55)
#define EIMSK (*(volatile u8*)0x3D)
#define SREG  (*(volatile u8*)0x5F)


static void (*INT0_Callback)(void) = NULL;

void EXT_INT0_Init(u8 sense)
{
    EICRA &= ~(0x03);   
    EICRA |= sense;     
}

void EXT_INT0_Enable(void)
{
    SET_BIT(EIMSK, 0);
}

void EXT_INT_GlobalEnable(void)
{
    SET_BIT(SREG, 7);
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    INT0_Callback = ptr;
}

// ISR
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (INT0_Callback != NULL)
    {
        INT0_Callback();
    }
}