#ifndef ADC_H
#define ADC_H
#include "STD_TYPES.h"

#define ADC_REF_AREF 0
#define ADC_REF_AVCC 1
#define ADC_REF_INTERNAL 2 //1:1

#define ADCPRESCALER_2   1
#define ADCPRESCALER_4   2
#define ADCPRESCALER_8   3
#define ADCPRESCALER_16  4
#define ADCPRESCALER_32  5
#define ADCPRESCALER_64  6
#define ADCPRESCALER_128 7


#define ADC_RESOLUTION_10BIT 0
#define ADC_RESOLUTION_8BIT  1


#define ACD_CHANNEL_0  0
#define ACD_CHANNEL_1  1
#define ACD_CHANNEL_2  2
#define ACD_CHANNEL_3  3
#define ACD_CHANNEL_4  4
#define ACD_CHANNEL_5  5
#define ACD_CHANNEL_6  6
#define ACD_CHANNEL_7  7




void ADC_VidInit(u8 Copy_u8Ref ,u8 Copy_u8Prescaler , u8 Copy_u8Resolution );

u16 ADC_U16ReadChannel (u8 Copy_u8Channel);
u8 ADC_U8ReadChannel (u8 Copy_u8Channel);

void ADC_VidEnableIntrrupt (void);
void ADC_VidDisenableIntrrupt (void);
void ADC_VidSetCallback(void (*ptr)(void));


#endif