/*
 * BUTTON_Interface.h
 *
 * Created: 30/09/2022 03:08:22 م
 *  Author: Qabbani
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include"../../MCAl/DIO/DIO_interface.h"

void BUTTON_vInit			(u8 copy_u8PortName,u8 copy_u8PinNumber					);
u8 BUTTON_u8Read			(u8 copy_u8PortName,u8 copy_u8PinNumber					);
void BUTTON_vPullUpEnable	(u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Enable);
#endif /* BUTTON_INTERFACE_H_ */