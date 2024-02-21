/*
 * ADC_register.h
 *
 * Created: 04-Dec-22 8:02:01 PM
 *  Author: Qabbani
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADC     *((volatile u16 *) 0x24)
#define ADCL    *((volatile u8 *) 0x24)
#define ADCH    *((volatile u8 *) 0x25)

#define ADCSRA  *((volatile u8 *) 0x26)
#define ADMUX   *((volatile u8 *) 0x27)

#define SFIOR   *((volatile u8 *) 0x50)

#endif /* ADC_REGISTER_H_ */