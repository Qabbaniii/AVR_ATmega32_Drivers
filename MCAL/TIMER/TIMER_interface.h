/*
 * TIMER_interface.h
 *
 * Created: 07-Dec-22 1:45:30 AM
 *  Author: Qabbani
 */

 
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

#include <avr/interrupt.h>
//Timer interrupt

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0


/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

void TIMER0_CTC_init_interrupt(void);
void TIMER0_wave_nonPWM(void);
void TIMER0_wave_fastPWM(void);
void TIMER0_wave_phasecorrectPWM(void);

void TIMER2_overflow_init_interrupt(void);

void TIMER1_ICU(void);
void TIMER1_wave_fastPWM(f32 value);
#endif /* TIMER_INTERFACE_H_ */