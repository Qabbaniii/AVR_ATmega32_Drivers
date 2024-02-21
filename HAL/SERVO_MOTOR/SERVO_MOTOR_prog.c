/*
 * SERVO_MOTOR_prog.c
 *
 * Created: 22-Feb-23 2:56:53 AM
 *  Author: Qabbani
 */ 
#include "SERVO_MOTOR_interface.h"

void SERVO_MOTOR_vSetPositionD(u8 copy_u8PortName, u8 copy_u8PinNamber,f32 copy_f32Degree) //mode 14
{
	/* set OC1A as output pin */
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNamber,1);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	if(copy_f32Degree>0)
	{
		OCR1A=(1.5+(copy_f32Degree*0.005555555))*1000;	
	}else 
	{
		OCR1A=(1.5-(copy_f32Degree*0.005555555))*1000;
	}
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	
	//eldegree el wahda = (0.5/90) for examble 3awez 18 degree = 18* 0.00555 +1.5
}

void SERVO_MOTOR_vSetPositionT(u8 copy_u8PortName, u8 copy_u8PinNamber,f32 copy_f32Tick) //mode 14
{
	/* set OC1A as output pin */
	DIO_vSetPinDirection(copy_u8PortName,copy_u8PinNamber,1);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=copy_f32Tick*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	//eldegree el wahda = (0.5/90) for examble 3awez 18 degree = 18* 0.00555 +1.5
}