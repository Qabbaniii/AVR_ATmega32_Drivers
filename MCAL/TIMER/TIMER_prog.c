/*
 * TIMER_prog.c
 *
 * Created: 06-Dec-22 10:39:19 PM
 *  Author: Qabbani
 */ 

#include "TIMER_register.h"
#include "TIMER_interface.h"
void TIMER0_CTC_init_interrupt(void)
 {
	/* select CTC mode*/ 
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=79;
	/* select timer clock prescaller*/ //1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
	
}  /* go to ISR every 10ms -|- 0.128ms*79 = 10.1ms*/


void TIMER0_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void TIMER0_wave_fastPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock 1024*/
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void TIMER0_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

void TIMER2_overflow_init_interrupt(void)
{
	/* select CTC mode default (Normal) Overflow */
	
	/* select timer clock ClkTS2*/
	SET_BIT(ASSR,AS2);
	/* select timer prescaller */
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,TOIE2);
}
void TIMER1_ICU(void)
{
	#define F_CPU 1000000UL
	u16 a,b,c,high,period,duty_cycle,frequency;
	LCD_vInit();
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */

	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	c = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */

	TCCR1B = 0;  		/* Stop the timer */
		
		if(a<b && b<c)  	/* Check for valid condition, 
					          to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;
			duty_cycle=((float)high/period)*100;
			frequency=F_CPU/(period);
			LCD_vSendString("duty:");
			LCD_vSendChar((duty_cycle/10)+48);
			LCD_vSendChar((duty_cycle%10)+48);
			LCD_vSendChar('%');
			LCD_vMoveCursor(2,1);
			LCD_vSendString("freq:");
			LCD_vSendChar((frequency/1000)+48);
			LCD_vSendChar(((frequency/100)%10)+48);
			LCD_vSendChar(((frequency/10)%10)+48);
			LCD_vSendChar((frequency%10)+48);
			LCD_vSendString("HZ");
		}
		else
		{
			LCD_vClearScreen();
			LCD_vSendString("out of range");
		
		}	
}



void TIMER1_wave_fastPWM(f32 value) //mode 14
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,5);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	
	//eldegree el wahda = (0.5/90) for examble 3awez 18 degree = 18* 0.00555 +1.5 
}
