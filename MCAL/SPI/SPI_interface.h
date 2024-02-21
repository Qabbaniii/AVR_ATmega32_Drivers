/*
 * SPI_interface.h
 *
 * Created: 01-Mar-23 1:38:12 AM
 *  Author: Qabbani
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_vInit(void);
u8 SPI_u8ExchangeChar(u8 copy_u8Data);
void SPI_MasterTransmitstring(unsigned char *copy_u8Ptr);

#endif /* SPI_INTERFACE_H_ */