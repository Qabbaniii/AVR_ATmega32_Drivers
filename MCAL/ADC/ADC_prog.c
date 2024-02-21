
/*
 * ADC_prog.c
 *
 * Created: 05-Dec-22 9:03:59 PM
 *  Author: Qabbani
 */ 

/* include services */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"

//include peripheral header

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_register.h"

void ADC_vInit(void)
{
	SET_BIT(ADMUX,REFS0);  //1. configure VREF
	SET_BIT(ADMUX,REFS1);
	
	SET_BIT(ADMUX,MUX0);   //2. Select ADC channel 
	
	SET_BIT(ADCSRA,ADEN);  //3. enable ADC
	
	SET_BIT(ADCSRA,ADPS2); //4. ADC clock Prescaler select
	SET_BIT(ADCSRA,ADPS1);
}

u16 ADC_u16Read(void)
{
	u16 LOC_u16ReadVal;
	SET_BIT(ADCSRA,ADSC);            //1. start conversion
	
	while(GET_BIT(ADCSRA,ADIF)==0);  //2. Stay in loop till ADIF become 1
	SET_BIT(ADCSRA,ADIF);            //3. clear ADIF Manual (not ISR)
	
	LOC_u16ReadVal =ADCL;            //4. write on ADC Data Register
	LOC_u16ReadVal |=(ADCH<<8);
	
	return LOC_u16ReadVal;
}


//temperature meter project
/* 
 
 #include "../HAL/LED/LED_interface.h"
 #include "../MCAL/DIO/DIO_interface.h"
 #include "../MCAL/ADC/ADC_interface.h"
 #include "../MCAL/LCD/LCD_interface.h"


 u16 temperatue;
 int main(void)
 {
	 LCD_vInit();
	 ADC_vInit();
	 LCD_vSendString("Temperature=");
	 while(1)
	 {
		 
		 temperatue=(ADC_u16Read()*0.25); //Using internal VREF  :temp = 2.56*readVal*1000 / 1024* 10
		 
		 if(temperatue<10)
		 {
			 LCD_vMoveCursor(1,13);
			 LCD_vSendChar(0x30);
			 LCD_vSendChar((temperatue%10)+48);
			 LCD_vSendChar(0xDF);
			 LCD_vSendChar(0x43);
		 }
		 else if( temperatue<100)
		 {
			 LCD_vMoveCursor(1,13);
			 LCD_vSendChar((temperatue/10)+48);
			 LCD_vSendChar((temperatue%10)+48);
			 LCD_vSendChar(0XDF);
			 LCD_vSendChar(0X43);
			 
		 }
		 else
		 {
			 
		 }
		 
	 }
 }
*/