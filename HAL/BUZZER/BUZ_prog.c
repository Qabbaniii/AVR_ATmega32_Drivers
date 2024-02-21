/*
 * BUZ_Prog.c
 *
 * Created: 30/09/2022 09:10:16 ص
 *  Author: Qabbani
 */ 


#include <stdio.h>
#include"../../MCAl/DIO/DIO_interface.h"


void BUZ_init   (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_OUTPUT);
}

void BUZ_ON (u8 copy_u8PortName,u8 copy_u8PinNumber){
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_HIGH);
}

void BUZ_OFF (u8 copy_u8PortName,u8 copy_u8PinNumber){
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_LOW);
}

void BUZ_TOG (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_OUTPUT);
	DIO_vTogglePin(copy_u8PortName,copy_u8PinNumber);
}


u8 BUZ_GET_STATUS (u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	return DIO_u8GetPinValue(copy_u8PortName,copy_u8PinNumber);
}