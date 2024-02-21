/*
 * UART_interface.h
 *
 * Created: 26-Feb-23 1:52:53 AM
 *  Author: Qabbani
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "../../SERVICES/STD_TYPES.h"

void UART_vInit(u32 copy_u32Baud);
void UART_vSendData(u8 copy_u8Data);
u8 UART_u8ReceiveData(void);
void UART_vSendString( u8 *copy_u8Ptr);

#endif /* UART_INTERFACE_H_ */