/*
 * LED_Prog.c
 *
 * Created: 30/09/2022 09:10:16 ص
 *  Author: Qabbani
 */ 


#include <stdio.h>
#include"../../MCAl/DIO/DIO_interface.h"


void LED_vInit   (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_OUTPUT);
}

void LED_vOn (u8 copy_u8PortName,u8 copy_u8PinNumber){
	
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_HIGH);
}

void LED_vOff (u8 copy_u8PortName,u8 copy_u8PinNumber){
	
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_LOW);
}

void LED_vToggle (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	
	DIO_vTogglePin(copy_u8PortName,copy_u8PinNumber);
}


u8 LED_u8GetStatus (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	DIO_u8GetPinValue(copy_u8PortName,copy_u8PinNumber);
}