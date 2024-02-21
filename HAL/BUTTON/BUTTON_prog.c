/*
 * BUTTON_Prog.c
 *
 * Created: 30/09/2022 03:08:43 م
 *  Author: Qabbani
 */ 
#include"../../MCAl/DIO/DIO_interface.h"

void BUTTON_vInit(u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNumber,DIO_u8_PIN_INPUT);
}

u8 BUTTON_u8Read(u8 copy_u8PortName,u8 copy_u8PinNumber)
{
	return DIO_u8GetPinValue(copy_u8PortName,copy_u8PinNumber);
}

void BUTTON_vPullUpEnable (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Enable)
{
	// default of PUD is 0
	DIO_vPullUpEnable(copy_u8PortName,copy_u8PinNumber,copy_u8Enable);

}

	

