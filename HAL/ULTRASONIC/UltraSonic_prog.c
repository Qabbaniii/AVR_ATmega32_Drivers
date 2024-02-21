/*
 * UltraSonic_prog.c
 *
 * Created: 20-Feb-23 12:54:56 AM
 *  Author: Qabbani
 */ 

#include "UltraSonic_interface.h"

static void UltraSonic_vSendPulse(u8 copy_u8PortName, u8 copy_u8PinNamber)
{
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNamber,1);
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNamber,DIO_u8_PIN_HIGH);
	_delay_ms(20);
	DIO_vSetPinValue(copy_u8PortName,copy_u8PinNamber,DIO_u8_PIN_LOW);
}

u8 UltraSonic_u8GetDistance(u8 copy_u8PortName, u8 copy_u8PinNamber)
{
	#define F_CPU 1000000UL
	u16 a,b,high,copy_u16Distance;
	
	TCCR1A = 0;
	TIFR |= (1<<ICF1);  	// Clear ICF (Input Capture flag)
	UltraSonic_vSendPulse(copy_u8PortName,copy_u8PinNamber);

	TCCR1B = 0xc1;  	// Rising edge, no prescaler , noise canceler
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		// Take value of capture register
	TIFR = (1<<ICF1);  	// Clear ICF flag
	
	TCCR1B = 0x81;  	// Falling edge, no prescaler ,noise canceler
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		// Take value of capture register
	TIFR = (1<<ICF1);  	// Clear ICF flag
	
	TCNT1=0;
	TCCR1B = 0;  		// Stop the timer
	high=b-a;
	
	copy_u16Distance=((high*34600)/(F_CPU*2)) ; //F_CPU = 1 M
	return copy_u16Distance;
}