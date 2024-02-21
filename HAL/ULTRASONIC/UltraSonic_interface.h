/*
 * UltraSonic_interface.h
 *
 * Created: 20-Feb-23 12:54:32 AM
 *  Author: Qabbani
 */ 
/*
*just return the distance 
*/
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

static void UltraSonic_vSendPulse(u8 copy_u8PortName, u8 copy_u8PinNamber);
u8 UltraSonic_u8GetDistance(u8 copy_u8PortName, u8 copy_u8PinNamber);

#endif /* ULTRASONIC_INTERFACE_H_ */