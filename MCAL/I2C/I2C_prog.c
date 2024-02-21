/*
 * I2C_prog.c
 *
 * Created: 09-Mar-23 4:20:36 AM
 *  Author: Qabbani
 */ 

#include <avr/io.h>
#include "I2C_config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#define F_CPU 8000000UL
#define prescalar 1

void I2C_vMasterInit(u32 copy_u32SCL_Clock)
{
	TWBR= (u8) (((F_CPU/copy_u32SCL_Clock)-16)/(2*prescalar));
	if (prescalar==1)
	{
		TWSR=0;
	}
	else if (prescalar==4)
	{
		TWSR=1;
	}
	else if (prescalar==16)
	{
		TWSR=2;
	}
	else if (prescalar==64)
	{
		TWSR=3;
	}
	
}

void I2C_vStart(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x08); // start condition has been transmitted
}

void I2C_vWriteAddress(u8 copy_u8Address)
{
	TWDR=copy_u8Address;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x18); // SLA+write has been transmitted and ACK has been received
}

void I2C_vWriteData(u8 copy_u8Data)
{
	TWDR=copy_u8Data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0); //wait to finish
	while ((TWSR & 0XF8) != 0x28); // data has been transmitted and ACK has been received
}

void I2C_vStop(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_vSetAddress(u8 copy_u8Address)
{
	TWAR=copy_u8Address;
}

u8 I2C_vSlaveRead(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x60); // own SLA+W has been received and ACK has been returned
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GET_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0XF8) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
	return TWDR ;
}