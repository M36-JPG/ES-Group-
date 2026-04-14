#ifndef _7_SEGMENT_H_
#define _7_SEGMENT_H_
#include"BIT_MATH.h"
#include"STD_TYPES.h"

extern u8 numbers[10];
void Seven_Segment_inti(u8 copy_u8port);
void Seven_Segment_Display(u8 number , u8 copy_u8port);
#endif