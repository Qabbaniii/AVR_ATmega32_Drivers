/*
 * BUZ_inteface.h
 *
 * Created: 30/09/2022 09:11:05 ص
 *  Author: Qabbani
 */ 


#ifndef HAL_BUZ_BUZ_INTERFACE_H_
#define HAL_BUZ_BUZ_INTERFACE_H_

#include"../../MCAl/DIO/DIO_interface.h"

    /*  Function Prototype  */
void BUZ_init   (u8 copy_u8PortName,u8 copy_u8PinNumber);
void BUZ_ON   (u8 copy_u8PortName,u8 copy_u8PinNumber);
void BUZ_OFF  (u8 copy_u8PortName,u8 copy_u8PinNumber);
void BUZ_TOG (u8 copy_u8PortName,u8 copy_u8PinNumber);
u8 LED_GET_STATUS (u8 copy_u8PortName,u8 copy_u8PinNumber);
#endif /* HAL_BUZ_BUZ_INTERFACE_H_ */