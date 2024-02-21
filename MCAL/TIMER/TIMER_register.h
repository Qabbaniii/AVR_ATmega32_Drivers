/*
 * TIMER_register.h
 *
 * Created: 07-Dec-22 1:41:56 AM
 *  Author: Qabbani
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


/* Timer 0 */

#define TCNT0   *((volatile u8 *) 0x52)
#define TCCR0   *((volatile u8 *) 0x53)

#define MCUSR   *((volatile u16 *) 0x54)
#define MCUCSR  *((volatile u8 *) 0x54)
#define MCUCR   *((volatile u8 *) 0x55)

#define TWCR    *((volatile u8 *) 0x56)

#define SPMCR   *((volatile u8 *) 0x57)

#define TIFR    *((volatile u8 *) 0x58)
#define TIMSK   *((volatile u8 *) 0x59)

#define GIFR    *((volatile u8 *) 0x5A)
#define GIMSK   _SFR_IO8(0x3B)
#define GICR    *((volatile u8 *) 0x5B)

#define OCR0    *((volatile u8 *) 0x5C)

/* Timer 1 */
#define ICR1    *((volatile u16 *) 0x46)
#define ICR1L   *((volatile u8 *) 0x46)
#define ICR1H   *((volatile u8 *) 0x47)
#define OCR1B   *((volatile u8 *) 0x5A)
#define OCR1BL  *((volatile u8 *) 0x48)
#define OCR1BH  *((volatile u8 *) 0x49)
#define OCR1A   *((volatile u16 *) 0x4A)
#define OCR1AL  *((volatile u8 *) 0x4A)
#define OCR1AH  *((volatile u8 *) 0x4B)
#define TCNT1   *((volatile u16 *) 0x4C)
#define TCNT1L  *((volatile u8 *) 0x4C)
#define TCNT1H  *((volatile u8 *) 0x4D)
#define TCCR1B  *((volatile u8 *) 0x4E)
#define TCCR1A  *((volatile u8 *) 0x4F)

#define SFIOR   *((volatile u8 *) 0x50)

#define OSCCAL  *((volatile u8 *) 0x51)
#define OCDR    OSCCAL

/* Timer 2 */
#define OCR2    *((volatile u8 *) 0x43)
#define TCNT2   *((volatile u8 *) 0x44)
#define TCCR2   *((volatile u8 *) 0x45)
#endif /* TIMER_REGISTER_H_ */