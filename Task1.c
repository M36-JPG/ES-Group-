#include <stdio.h>

unsigned int GPIO_DIR = 0;  
unsigned int GPIO_DATA = 0;  

#define SET_BIT(REG, BIT)   (REG |= (1 << BIT))
#define CLR_BIT(REG, BIT)   (REG &= ~(1 << BIT))
#define READ_BIT(REG, BIT)  ((REG >> BIT) & 1)


void GPIO_Init(int pin, int direction)
{
    if(direction == 1)
        SET_BIT(GPIO_DIR, pin);   
    else
        CLR_BIT(GPIO_DIR, pin);  
}


void GPIO_Write(int pin, int value)
{
    if(value == 1)
        SET_BIT(GPIO_DATA, pin); 
    else
        CLR_BIT(GPIO_DATA, pin);  
}


int GPIO_Read(int pin)
{
    return READ_BIT(GPIO_DATA, pin);
}


int main()
{
    GPIO_Init(2, 1);   
    GPIO_Write(2, 1);    

    int val = GPIO_Read(2);
    printf("Pin Value = %d\n", val);

    return 0;
}
