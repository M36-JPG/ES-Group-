#include <stdio.h>
/* 1- Must separate between declaration and defination
2- Each driver must be independent
3-  Must write signed or unsigned to make it clear , static , and appropriate  
4- Must use prefix like GPIO 
5- Don't expose registers only MCAl can edit in it 
6- Use enum or #define to avoid magic numbers 
7- Don't use global variables */

/* Registers (Simulation)*/
//3-  Must write signed or unsigned to make it clear , static , and appropriate  
unsigned int GPIO_DIR = 0;   // Port direction (0 = Input, 1 = Output)
unsigned int GPIO_DATA = 0;  // Data

/* Macro definations  */
#define SET_BIT(REG, BIT)   (REG |= (1 << BIT))
#define CLR_BIT(REG, BIT)   (REG &= ~(1 << BIT))
#define READ_BIT(REG, BIT)  ((REG >> BIT) & 1)

/* Function: Initialize Pin Direction */
// 4- Must use prefix like GPIO 
void GPIO_Init(int pin, int direction)
{
    if(direction == 1)
        SET_BIT(GPIO_DIR, pin);   // Output
    else
        CLR_BIT(GPIO_DIR, pin);   // Input
}

/* Function Write to Pin */
void GPIO_Write(int pin, int value)
{
    if(value == 1)
        SET_BIT(GPIO_DATA, pin);  // High
    else
        CLR_BIT(GPIO_DATA, pin);  // Low
}

/* Function: Read from Pin */
int GPIO_Read(int pin)
{
    return READ_BIT(GPIO_DATA, pin);
}


int main()
{
    GPIO_Init(2, 1);     // Pin 2 Output
    GPIO_Write(2, 1);    // High

    int val = GPIO_Read(2);
    printf("Pin Value = %d\n", val);

    return 0;
}
