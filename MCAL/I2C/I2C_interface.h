/*
 * I2C_interface.h
 *
 * Created: 09-Mar-23 4:20:03 AM
 *  Author: Qabbani
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


void I2C_vMasterInit(u32 copy_u32SCL_Clock);
void I2C_vStart(void);
void I2C_vWriteAddress(u8 copy_u8Address);
void I2C_vWriteData(u8 copy_u8Data);
void I2C_vStop(void);
void I2C_vSetAddress(u8 copy_u8Address);
u8 I2C_vSlaveRead(void);



#endif /* I2C_INTERFACE_H_ */