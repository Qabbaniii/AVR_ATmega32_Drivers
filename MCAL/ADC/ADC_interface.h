/*
 * ADC_interface.h
 *
 * Created: 04-Dec-22 8:00:45 PM
 *  Author: Qabbani
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5

#define ADIF    4
#define ADIE    3

#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6

#define ADLAR   5

#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

/* SFIOR */
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5


// prototype of function

void ADC_vInit(void);
u16 ADC_u16Read(void);
#endif /* ADC_INTERFACE_H_ */
