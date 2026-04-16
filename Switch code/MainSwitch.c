void main(void) {
    
   GPIO_VidsetPinDirection(GPTO_PORTB,0xFF);
   GPIO_VidsetPortvalue(GPTO_PORTB,GPIO_OUTPUT);
   
   while(1);
    
}