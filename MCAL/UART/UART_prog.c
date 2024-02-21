/*
 * UART_prog.c
 *
 * Created: 26-Feb-23 2:01:06 AM
 *  Author: Qabbani
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

void UART_vInit(u32 copy_u32Baud)
{
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	u16 UBRR ;
	UBRR=(F_CPU/(16*copy_u32Baud))-1 ;
	UBRRH=(u8)(UBRR>>8);
	UBRRL=(u8)UBRR;
	/*2 - Enable USART Sender & Receiver*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	/*3 - Choose number of data bits to be sent,parity and stop bits from UCSRC
	, We will work with 8 bits data,1 stop bit and no parity bits*/
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_vSendData(u8 copy_u8Data)
{
	/*Wait for UDR transmit buffer to be empty*/
	while(GET_BIT(UCSRA,UDRE)==0);
	/*Put data to UDR transmit buffer transmit*/
	UDR=copy_u8Data ;
}

u8 UART_u8ReceiveData(void)
{
	/*Wait for UDR receive buffer to be filled with data*/
	while(GET_BIT(UCSRA,RXC)==0);
	/*Receive data from UDR receive buffer*/
	return UDR ;
}

void UART_vSendString( u8 *copy_u8Ptr)
{
	while(*copy_u8Ptr!=0)
	{
		UART_vSendData(*copy_u8Ptr);
		copy_u8Ptr++;
		_delay_ms(100);
	}
}

 