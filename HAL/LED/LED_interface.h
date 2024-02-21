/*
 * LED_inteface.h
 *
 * Created: 30/09/2022 09:11:05 ص
 *  Author: Qabbani
 */ 


#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include"../../MCAl/DIO/DIO_interface.h"

    /*  Function Prototype  */
void LED_vInit   (u8 copy_u8PortName,u8 copy_u8PinNumber);
void LED_vOn   (u8 copy_u8PortName,u8 copy_u8PinNumber);
void LED_vOff  (u8 copy_u8PortName,u8 copy_u8PinNumber);
void LED_vToggle (u8 copy_u8PortName,u8 copy_u8PinNumber);
u8 LED_u8GetStatus (u8 copy_u8PortName,u8 copy_u8PinNumber);
#endif /* HAL_LED_LED_INTERFACE_H_ */
