/*
 * timer.h
 *
 * Created: 12/2/2019 3:55:00 PM
 *  Author: ADMIN
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define NO_CLOCK_SOURCE                  0
#define NO_PRESCALING                    1
#define PRESCALING_8_TIMER0              2
#define PRESCALING_64_TIMER0             3
#define PRESCALING_256_TIMER0            4
#define PRESCALING_1024_TIMER0           5
#define FALLING_EXT_PIN_TIMER0           6
#define RISING_EXT_PIN_TIMER0            7

#define PRESCALING_8_TIMER2              2
#define PRESCALING_32_TIMER2             3
#define PRESCALING_64_TIMER2             4
#define PRESCALING_128_TIMER2            5
#define PRESCALING_256_TIMER2            6
#define PRESCALING_1024_TIMER2           7



void timer0_Init(unsigned char scale);
void timer0_Disable(void);
void timer0_Enable(void);
void timer2_Init(unsigned char scale);
void timer2_Disable(void);
void timer2_Enable(void);




#endif /* TIMER_H_ */