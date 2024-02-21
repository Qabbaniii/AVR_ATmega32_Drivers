/*
 * Drivers.c
 *
 * Created: 04-Dec-22 7:52:26 PM
 *  Author: Qabbani
 */ 
//#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_interface.h"
int main(void)
{	
	u8 LOC_u8Counter=0;
	I2C_vMasterInit(50000);
	while(LOC_u8Counter<10)
	{
		_delay_ms(500);
		I2C_vStart(); // transmit start condition
		I2C_vWriteAddress(0b11100000); // transmit SLA+W
		I2C_vWriteData(LOC_u8Counter+48); // transmit data
		I2C_vStop(); // transmit stop condition
		LOC_u8Counter++;
	}
	
}