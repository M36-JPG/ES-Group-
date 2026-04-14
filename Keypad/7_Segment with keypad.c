#include"7_Segment.h"
#include"GPIO_INTERFACE.h"

static u8 SevenSeg_Arr[10]=
{
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

void SEVENSEG_VidInit(u8 copy_U8Port){

    GPIO_VidSetPortDirection(u8 copy_U8Port,GPIO_INPUT_ALL);
}

void SEVENSEG_VidDisplay(u8 copy_U8Port, u8 copy_U8Number){
if(copy_U8Number <= 9){
    GPIO_VidSetPortDirection (copy_U8Port, SevenSeg_Arr[copy_U8Number]);
}
}

// u8 number[10]={0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};
// void Seven_Segment(u8 copy_u8port){
//     GPIO_VidSetPortDirection(copy_u8port , GPIO_OUTPUT_ALL);

// }
// void Seven_Segment_Display(u8 number , u8 copy_u8port){
//     GPIO_VidSetPortValue(copy_u8port , numbers[number]);
// }