/*
 * _SEVEN_SEG_Interface.h
 *
 * Created: 1/10/2022 08:29:35 م
 *  Author: Qabbani
 */ 


#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_
#include"../../MCAl/DIO/DIO_interface.h"

void  SEVEN_SEG_vInit		(u8 copy_u8_portName						);
void SEVEN_SEG_vWrite		(u8 copy_u8_portName,u8 copy_u8_portValue	);


#endif /* SEVEN_SEG_INTERFACE_H_ */