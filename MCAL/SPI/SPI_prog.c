/*
 * SPI_prog.c
 *
 * Created: 01-Mar-23 1:38:56 AM
 *  Author: Qabbani
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../DIO/DIO_interface.h"
#include "SPI_config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void SPI_vInit(void)
{
	// SPI_masterInit
	#if(configMASTER_MODE ==1)
	/*Set SS / MOSI / SCK  as output pins for master*/
	DIO_vSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN7,DIO_u8_PIN_OUTPUT);
	/*Enable Master mode*/
	SET_BIT(SPCR,MSTR);
	/*Set clock to fosc/16*/
	SET_BIT(SPCR,SPR0);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*set SS to high*/
	DIO_vSetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_PIN_HIGH);
	
	// SPI_SlaveInit
	#elif(configMASTER_MODE ==0)
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
	/*Set MISO as output*/
	DIO_vSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_PIN_OUTPUT);
	#endif
}


u8 SPI_u8ExchangeChar(u8 copy_u8Data)
{
	// SPI_SlaveTransmitChar
	#if(configMASTER_MODE ==1)
	/*Clear SS to send data to slave*/
	DIO_vSetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_PIN_LOW);
	/*Put data on SPDR*/
	SPDR=copy_u8Data;
	/*Wait until the transmission is finished*/
	while(GET_BIT(SPSR,SPIF)==0);
	
	// SPI_SlaveReceiveChar
	#elif(configMASTER_MODE ==0)
	/*Put data on SPDR*/
	SPDR=copy_u8Data;
	/*Wait until data is received in SPI register*/
	while(GET_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	#endif
	/*read SPDR*/
	return SPDR ;
}

void SPI_vExchangestring(unsigned char *copy_u8Ptr)
{
	while((*copy_u8Ptr)!=0)
	{
		SPI_u8ExchangeChar(*copy_u8Ptr);
		_delay_ms(300);
		copy_u8Ptr++;
	}
}