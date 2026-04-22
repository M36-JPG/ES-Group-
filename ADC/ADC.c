#include "ADC.h"
#include "BIT_MATH.h"

#define ADMUX *((volatile u8*)0x7C)
#define ADCSRA *((volatile u8*)0x7A)
#define ADCSRB *((volatile u8*)0x7B)
#define ADCL *((volatile u8*)0x78)
#define ADCH *((volatile u8*)0x79)
#define ADC *((volatile u16*)0x7C)
#define DIDR0 *((volatile u8*)0x7E)
#define SREG *((volatile u8*)0x5F)


void ADC_VidInit(u8 Copy_u8Ref ,u8 Copy_u8Prescaler , u8 Copy_u8Resolution ){

    //1_REF Voltage
    
    switch(Copy_u8Ref){

        case ADC_REF_AREF:

        CLR_BIT(ADMUX,6);
        CLR_BIT(ADMUX,7);

        break;

        case ADC_REF_AVCC: 

        SIT_BIT(ADMUX,6);
        CLR_BIT(ADMUX,7);

        break;

        case ADC_REF_INTERNAL:

        SIT_BIT(ADMUX,6);
        SIT_BIT(ADMUX,7);
        break;

        default :
        break;



    }




    //2_Reslution
     

    if(Copy_u8Resolution == ADC_RESOLUTION_10BIT){

        CLR_BIT(ADMUX,5);

    }

    else if(Copy_u8Resolution == ADC_RESOLUTION_8BIT){
        SET_BIT(ADMUX,5);
    }


    //3_Prescaler

    ADCSRA = ADCSRA & 0xF8;
    ADCSRA = ADCSRA | Copy_u8Prescaler;


    //4_Enable

    SET_BIT (ADCSRA ,)
}
u16 ADC_U16ReadChannel (u8 Copy_u8Channel){



}
u8 ADC_U8ReadChannel (u8 Copy_u8Channel){


}

void ADC_VidEnableIntrrupt (void){


}
void ADC_VidDisenableIntrrupt (void){



}
void ADC_VidSetCallback(void (*ptr)(void)){



}
