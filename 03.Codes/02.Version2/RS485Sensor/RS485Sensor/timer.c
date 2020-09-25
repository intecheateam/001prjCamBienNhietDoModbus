/*
 * timer.c
 *
 * Created: 10/26/2019 11:12:34 AM
 *  Author: 
 */ 

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SFR_Macro.h"
#include "Function_Define.h"


void timer0_Init(unsigned char scale) {
	// initialising the timer with prescaling
	TCCR0 &= 0b11111000;
    TCCR0 |= scale;
	// initialize timer0
	TCNT0 = 0;    
	// enable overflow interrupt
	TIMSK |= (1 << TOIE0);
	 // enable global interrupts
	 sei();
}
void timer0_Disable() {
	clr_TOIE0;
}
void timer0_Enable(void) {
	set_TOIE0;
}
void timer2_Init(unsigned char scale) {
	// set up timer with prescaler
    TCCR2 &= 0b11111000;
    TCCR2 |= scale;
	// initialize counter
	TCNT2 = 0;
	
	// enable overflow interrupt
	TIMSK |= (1 << TOIE2);
	
	// enable global interrupts
	sei();
}

void timer2_Disable(void) {
    clr_TOIE2;
}
void timer2_Enable(void) {
	set_TOIE2;
}
