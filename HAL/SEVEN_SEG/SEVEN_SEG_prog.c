/*
 * _SEVEN_SEG_Prog.c
 *
 * Created: 01/10/2022 08:30:03 م
 *  Author: Qabbani
 */ 
#include"../../MCAl/DIO/DIO_interface.h"
#include "SEVEN_SEG_config.h"

void SEVEN_SEG_vInit(u8 copy_u8_portName)
{
	DIO_vSetPortDirection(copy_u8_portName,0xFF);
}

void SEVEN_SEG_vWrite(u8 copy_u8_portName,u8 copy_u8_portValue)
{
	u8 SEG[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
		
	#if (configCOMMON_CATHODE==1)
	DIO_vSetPortValue(copy_u8_portName,SEG[copy_u8_portValue]);
	#endif	
	
	#if(configCOMMON_CATHODE==0)
	DIO_vSetPortValue(copy_u8_portName,~SEG[copy_u8_portValue]);
	#endif
}

