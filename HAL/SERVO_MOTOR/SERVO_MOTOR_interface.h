/*
 * SERVO_MOTOR_interface.h
 *
 * Created: 22-Feb-23 2:56:32 AM
 *  Author: Qabbani
 */ 

#ifndef SERVO_MOTOR_INTERFACE_H_
#define SERVO_MOTOR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../Services/BIT_MATH.h"
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

void SERVO_MOTOR_vSetPositionD(u8 copy_u8PortName, u8 copy_u8PinNamber,f32 copy_f32Degree);
void SERVO_MOTOR_vSetPositionT(u8 copy_u8PortName, u8 copy_u8PinNamber,f32 copy_f32Tick);

#endif /* SERVO_MOTOR_INTERFACE_H_ */