/*
 * SFR_Macro.h
 *
 * Created: 12/2/2019 3:57:04 PM
 *  Author: ADMIN
 */ 


#ifndef SFR_MACRO_H_
#define SFR_MACRO_H_

//------------------- Set & Clear bit of  SREG - AVR Status Register ------------------
#define set_SREG       SREG |= 0xFF;
#define set_C          SREG |= SET_BIT0;
#define set_Z          SREG |= SET_BIT1;
#define set_N          SREG |= SET_BIT2;
#define set_V          SREG |= SET_BIT3;
#define set_S          SREG |= SET_BIT4;
#define set_H          SREG |= SET_BIT5;
#define set_T          SREG |= SET_BIT6;
#define set_I          SREG |= SET_BIT7;

#define clr_C          SREG &= 0x00;
#define clr_Z          SREG &= CLR_BIT1;
#define clr_N          SREG &= CLR_BIT2;
#define clr_V          SREG &= CLR_BIT3;
#define clr_S          SREG &= CLR_BIT4;
#define clr_H          SREG &= CLR_BIT5;
#define clr_T          SREG &= CLR_BIT6;
#define clr_I          SREG &= CLR_BIT7;
//------------------- Set & Clear bit of  SPH and SPL – Stack Pointer High and Low Register -------------------
#define set_SPL          SPL  |= 0xFF;
#define set_SP0          SPL  |= SET_BIT0;
#define set_SP1          SPL  |= SET_BIT1;
#define set_SP2          SPL  |= SET_BIT2;
#define set_SP3          SPL  |= SET_BIT3;
#define set_SP4          SPL  |= SET_BIT4;
#define set_SP5          SPL  |= SET_BIT5;
#define set_SP6          SPL  |= SET_BIT6;
#define set_SP7          SPL  |= SET_BIT7;
#define set_SPH          SPH  |= 0xFF;
#define set_SP8          SPH  |= SET_BIT0;
#define set_SP9          SPH  |= SET_BIT1;
#define set_SP10         SPH  |= SET_BIT2;
#define set_SP11         SPH  |= SET_BIT3;
#define set_SP12         SPH  |= SET_BIT4;
#define set_SP13         SPH  |= SET_BIT5;
#define set_SP14         SPH  |= SET_BIT6;
#define set_SP15         SPH  |= SET_BIT7;

#define clr_SPL          SPL &= 0x00;
#define clr_SP0          SPL &= CLR_BIT0;
#define clr_SP1          SPL &= CLR_BIT1;
#define clr_SP2          SPL &= CLR_BIT2;
#define clr_SP3          SPL &= CLR_BIT3;
#define clr_SP4          SPL &= CLR_BIT4;
#define clr_SP5          SPL &= CLR_BIT5;
#define clr_SP6          SPL &= CLR_BIT6;
#define clr_SP7          SPL &= CLR_BIT7;
#define clr_SPH          SPH &= 0x00;
#define clr_SP8          SPH &= CLR_BIT0;
#define clr_SP9          SPH &= CLR_BIT1;
#define clr_SP10         SPH &= CLR_BIT2;
#define clr_SP11         SPH &= CLR_BIT3;
#define clr_SP12         SPH &= CLR_BIT4;
#define clr_SP13         SPH &= CLR_BIT5;
#define clr_SP14         SPH &= CLR_BIT6;
#define clr_SP15         SPH &= CLR_BIT7;
//------------------- Set & Clear bit of  GICR – General Interrupt Control Register -------------------
#define set_GICR         GICR  |= 0b11100011;
#define set_IVCE         GICR  |= SET_BIT0;
#define set_IVSEL        GICR  |= SET_BIT1;
#define set_INT2         GICR  |= SET_BIT5;
#define set_INT0         GICR  |= SET_BIT6;
#define set_INT1         GICR  |= SET_BIT7;

#define clr_GICR         GICR  &= 0b00011100;
#define clr_IVCE         GICR  &= CLR_BIT0;
#define clr_IVSEL        GICR  &= CLR_BIT1;
#define clr_INT2         GICR  &= CLR_BIT5;
#define clr_INT0         GICR  &= CLR_BIT6;
#define clr_INT1         GICR  &= CLR_BIT7;
//------------------- Set & Clear bit of  GIFR – General Interrupt Flag Register -------------------
#define set_GIFR         GIFR  |= 0b11100000;
#define set_INTF2        GIFR  |= SET_BIT5;
#define set_INTF0        GIFR  |= SET_BIT6;
#define set_INTF1        GIFR  |= SET_BIT7;

#define clr_GIFR         GIFR  &= 0b00011111;
#define clr_INTF2        GIFR  &= CLR_BIT5;
#define clr_INTF0        GIFR  &= CLR_BIT6;
#define clr_INTF1        GIFR  &= CLR_BIT7;
//------------------- Set & Clear bit of  TIMSK – Timer/Counter Interrupt Mask Register -------------------
#define set_TIMSK        TIMSK  |= 0xFF;
#define set_TOIE0        TIMSK  |= SET_BIT0;
#define set_OCIE0        TIMSK  |= SET_BIT1;
#define set_TOIE1        TIMSK  |= SET_BIT2;
#define set_OCIE1B       TIMSK  |= SET_BIT3;
#define set_OCIE1A       TIMSK  |= SET_BIT4;
#define set_TICIE1       TIMSK  |= SET_BIT5;
#define set_TOIE2        TIMSK  |= SET_BIT6;
#define set_OCIE2        TIMSK  |= SET_BIT7;

#define clr_TIMSK        TIMSK  &= 0x00;
#define clr_TOIE0        TIMSK  &= CLR_BIT0;
#define clr_OCIE0        TIMSK  &= CLR_BIT1;
#define clr_TOIE1        TIMSK  &= CLR_BIT2;
#define clr_OCIE1B       TIMSK  &= CLR_BIT3;
#define clr_OCIE1A       TIMSK  &= CLR_BIT4;
#define clr_TICIE1       TIMSK  &= CLR_BIT5;
#define clr_TOIE2        TIMSK  &= CLR_BIT6;
#define clr_OCIE2        TIMSK  &= CLR_BIT7;
//------------------- Set & Clear bit of  TIFR qP Timer/Counter Interrupt Flag Register -------------------
#define set_TIFR         TIFR   |= 0xFF;
#define set_TOV0         TIFR   |= SET_BIT0;
#define set_OCF0         TIFR   |= SET_BIT1;
#define set_TOV1         TIFR   |= SET_BIT2;
#define set_OCF1B        TIFR   |= SET_BIT3;
#define set_OCF1A        TIFR   |= SET_BIT4;
#define set_ICF1         TIFR   |= SET_BIT5;
#define set_TOV2         TIFR   |= SET_BIT6;
#define set_OCF2         TIFR   |= SET_BIT7;

#define clr_TIFR         TIFR   &= 0x00;
#define clr_TOV0         TIFR   &= CLR_BIT0;
#define clr_OCF0         TIFR   &= CLR_BIT1;
#define clr_TOV1         TIFR   &= CLR_BIT2;
#define clr_OCF1B        TIFR   &= CLR_BIT3;
#define clr_OCF1A        TIFR   &= CLR_BIT4;
#define clr_ICF1         TIFR   &= CLR_BIT5;
#define clr_TOV2         TIFR   &= CLR_BIT6;
#define clr_OCF2         TIFR   &= CLR_BIT7;
//------------------- Set & Clear bit of  SPMCR – Store Program Memory Control Register -------------------
#define set_SPMCR        SPMCSR  |= 0b11011111;
#define set_SPMEN        SPMCSR  |= SET_BIT0;
#define set_PGERS        SPMCSR  |= SET_BIT1;
#define set_PGWRT        SPMCSR  |= SET_BIT2;
#define set_BLBSET       SPMCSR  |= SET_BIT3;
#define set_RWWSRE       SPMCSR  |= SET_BIT4;
#define set_RWWSB        SPMCSR  |= SET_BIT6;
#define set_SPMIE        SPMCSR  |= SET_BIT7;

#define clr_SPMCR        SPMCSR  &= 0b00100000;
#define clr_SPMEN        SPMCSR  &= CLR_BIT0;
#define clr_PGERS        SPMCSR  &= CLR_BIT1;
#define clr_PGWRT        SPMCSR  &= CLR_BIT2;
#define clr_BLBSET       SPMCSR  &= CLR_BIT3;
#define clr_RWWSRE       SPMCSR  &= CLR_BIT4;
#define clr_RWWSB        SPMCSR  &= CLR_BIT6;
#define clr_SPMIE        SPMCSR  &= CLR_BIT7;
//------------------- Set & Clear bit of  TWCR – TWI Control Register -------------------
#define set_TWCR         TWCR   |= 0b11111101;
#define set_TWIE         TWCR   |= SET_BIT0;
#define set_TWEN         TWCR   |= SET_BIT2;
#define set_TWWC         TWCR   |= SET_BIT3;
#define set_TWSTO        TWCR   |= SET_BIT4;
#define set_TWSTA        TWCR   |= SET_BIT5;
#define set_TWEA         TWCR   |= SET_BIT6;
#define set_TWINT        TWCR   |= SET_BIT7;

#define clr_TWCR         TWCR   &= 0b00000010;
#define clr_TWIE         TWCR   &= CLR_BIT0;
#define clr_TWEN         TWCR   &= CLR_BIT2;
#define clr_TWWC         TWCR   &= CLR_BIT3;
#define clr_TWSTO        TWCR   &= CLR_BIT4;
#define clr_TWSTA        TWCR   &= CLR_BIT5;
#define clr_TWEA         TWCR   &= CLR_BIT6;
#define clr_TWINT        TWCR   &= CLR_BIT7;
//------------------- Set & Clear bit of  MCUCR – MCU Control Register -------------------
#define set_MCUCR        MCUCR  |= 0xFF;
#define set_ISC00        MCUCR  |= SET_BIT0;
#define set_ISC01        MCUCR  |= SET_BIT1;
#define set_ISC10        MCUCR  |= SET_BIT2;
#define set_ISC11        MCUCR  |= SET_BIT3;
#define set_SM0          MCUCR  |= SET_BIT4;
#define set_SM1          MCUCR  |= SET_BIT5;
#define set_SE           MCUCR  |= SET_BIT6;
#define set_SM2          MCUCR  |= SET_BIT7;

#define clr_MCUCR        MCUCR  &= 0x00;
#define clr_ISC00        MCUCR  &= CLR_BIT0;
#define clr_ISC01        MCUCR  &= CLR_BIT1;
#define clr_ISC10        MCUCR  &= CLR_BIT2;
#define clr_ISC11        MCUCR  &= CLR_BIT3;
#define clr_SM0          MCUCR  &= CLR_BIT4;
#define clr_SM1          MCUCR  &= CLR_BIT5;
#define clr_SE           MCUCR  &= CLR_BIT6;
#define clr_SM2          MCUCR  &= CLR_BIT7;
//------------------- Set & Clear bit of  MCUCSR – MCU Control and Status Register -------------------
#define set_MCUCSR       MCUCSR  |= 0b11011111;
#define set_PORF         MCUCSR  |= SET_BIT0;
#define set_EXTRF        MCUCSR  |= SET_BIT1;
#define set_BORF         MCUCSR  |= SET_BIT2;
#define set_WDRF         MCUCSR  |= SET_BIT3;
#define set_JTRF         MCUCSR  |= SET_BIT4;
#define set_ISC2         MCUCSR  |= SET_BIT6;
#define set_JTD          MCUCSR  |= SET_BIT7;

#define clr_MCUCSR       MCUCSR  &= 0b00100000;
#define clr_PORF         MCUCSR  &= CLR_BIT0;
#define clr_EXTRF        MCUCSR  &= CLR_BIT1;
#define clr_BORF         MCUCSR  &= CLR_BIT2;
#define clr_WDRF         MCUCSR  &= CLR_BIT3;
#define clr_JTRF         MCUCSR  &= CLR_BIT4;
#define clr_ISC2         MCUCSR  &= CLR_BIT6;
#define clr_JTD          MCUCSR  &= CLR_BIT7;
//------------------- Set & Clear bit of  TCCR0 – Timer/Counter Control Register -------------------
#define set_TCCR0        TCCR0  |= 0xFF;
#define set_CS00         TCCR0  |= SET_BIT0;
#define set_CS01         TCCR0  |= SET_BIT1;
#define set_CS02         TCCR0  |= SET_BIT2;
#define set_WGM01        TCCR0  |= SET_BIT3;
#define set_COM00        TCCR0  |= SET_BIT4;
#define set_COM01        TCCR0  |= SET_BIT5;
#define set_WGM00        TCCR0  |= SET_BIT6;
#define set_FOC0         TCCR0  |= SET_BIT7;

#define clr_TCCR0        TCCR0  &= 0x00;
#define clr_CS00         TCCR0  &= CLR_BIT0;
#define clr_CS01         TCCR0  &= CLR_BIT1;
#define clr_CS02         TCCR0  &= CLR_BIT2;
#define clr_WGM01        TCCR0  &= CLR_BIT3;
#define clr_COM00        TCCR0  &= CLR_BIT4;
#define clr_COM01        TCCR0  &= CLR_BIT5;
#define clr_WGM00        TCCR0  &= CLR_BIT6;
#define clr_FOC0         TCCR0  &= CLR_BIT7;
//------------------- Set & Clear bit of  SFIOR – Special Function I/O Register -------------------
#define set_SFIOR        SFIOR  |= 0b11101111;
#define set_PSR10        SFIOR  |= SET_BIT0;
#define set_PSR2         SFIOR  |= SET_BIT1;
#define set_PUD          SFIOR  |= SET_BIT2;
#define set_ACME         SFIOR  |= SET_BIT3;
#define set_ADTS0        SFIOR  |= SET_BIT5;
#define set_ADTS1        SFIOR  |= SET_BIT6;
#define set_ADTS2        SFIOR  |= SET_BIT7;

#define clr_SFIOR        SFIOR  &= 0b00010000;
#define clr_PSR10        SFIOR  &= CLR_BIT0;
#define clr_PSR2         SFIOR  &= CLR_BIT1;
#define clr_PUD          SFIOR  &= CLR_BIT2;
#define clr_ACME         SFIOR  &= CLR_BIT3;
#define clr_ADTS0        SFIOR  &= CLR_BIT5;
#define clr_ADTS1        SFIOR  &= CLR_BIT6;
#define clr_ADTS2        SFIOR  &= CLR_BIT7;
//------------------- Set & Clear bit of  TCCR1A – Timer/Counter1 Control Register A -------------------
#define set_TCCR1A       TCCR1A  |= 0xFF;
#define set_WGM10        TCCR1A  |= SET_BIT0;
#define set_WGM11        TCCR1A  |= SET_BIT1;
#define set_FOC1B        TCCR1A  |= SET_BIT2;
#define set_FOC1A        TCCR1A  |= SET_BIT3;
#define set_COM1B0       TCCR1A  |= SET_BIT4;
#define set_COM1B1       TCCR1A  |= SET_BIT5;
#define set_COM1A0       TCCR1A  |= SET_BIT6;
#define set_COM1A1       TCCR1A  |= SET_BIT7;

#define clr_TCCR1A       TCCR1A  &= 0x00;
#define clr_WGM10        TCCR1A  &= CLR_BIT0;
#define clr_WGM11        TCCR1A  &= CLR_BIT1;
#define clr_FOC1B        TCCR1A  &= CLR_BIT2;
#define clr_FOC1A        TCCR1A  &= CLR_BIT3;
#define clr_COM1B0       TCCR1A  &= CLR_BIT4;
#define clr_COM1B1       TCCR1A  &= CLR_BIT5;
#define clr_COM1A0       TCCR1A  &= CLR_BIT6;
#define clr_COM1A1       TCCR1A  &= CLR_BIT7;
//------------------- Set & Clear bit of  TCCR1B – Timer/Counter1 Control Register B -------------------
#define set_TCCR1B       TCCR1B  |= 0b11011111;
#define set_CS10         TCCR1B  |= SET_BIT0;
#define set_CS11         TCCR1B  |= SET_BIT1;
#define set_CS12         TCCR1B  |= SET_BIT2;
#define set_WGM12        TCCR1B  |= SET_BIT3;
#define set_WGM13        TCCR1B  |= SET_BIT4;
#define set_ICES1        TCCR1B  |= SET_BIT6;
#define set_ICNC1        TCCR1B  |= SET_BIT7;

#define clr_TCCR1B       TCCR1B  &= 0b00100000;
#define clr_CS10         TCCR1B  &= CLR_BIT0;
#define clr_CS11         TCCR1B  &= CLR_BIT1;
#define clr_CS12         TCCR1B  &= CLR_BIT2;
#define clr_WGM12        TCCR1B  &= CLR_BIT3;
#define clr_WGM13        TCCR1B  &= CLR_BIT4;
#define clr_ICES1        TCCR1B  &= CLR_BIT6;
#define clr_ICNC1        TCCR1B  &= CLR_BIT7;
//------------------- Set & Clear bit of  TCCR2 – Timer/Counter Control Register -------------------
#define set_TCCR2        TCCR2  |= 0xFF;
#define set_CS20         TCCR2  |= SET_BIT0;
#define set_CS21         TCCR2  |= SET_BIT1;
#define set_CS22         TCCR2  |= SET_BIT2;
#define set_WGM21        TCCR2  |= SET_BIT3;
#define set_COM20        TCCR2  |= SET_BIT4;
#define set_COM21        TCCR2  |= SET_BIT5;
#define set_WGM20        TCCR2  |= SET_BIT6;
#define set_FOC2         TCCR2  |= SET_BIT7;

#define clr_TCCR2        TCCR2  &= 0x00;
#define clr_CS20         TCCR2  &= CLR_BIT0;
#define clr_CS21         TCCR2  &= CLR_BIT1;
#define clr_CS22         TCCR2  &= CLR_BIT2;
#define clr_WGM21        TCCR2  &= CLR_BIT3;
#define clr_COM20        TCCR2  &= CLR_BIT4;
#define clr_COM21        TCCR2  &= CLR_BIT5;
#define clr_WGM20        TCCR2  &= CLR_BIT6;
#define clr_FOC2         TCCR2  &= CLR_BIT7;
//------------------- Set & Clear bit of  ASSR – Asynchronous Status Register -------------------
#define set_ASSR         ASSR  |= 0b00001000;
#define set_AS2          ASSR  |= SET_BIT3;

#define clr_ASSR         ASSR  &= 0b11110111;
#define clr_AS2          ASSR  &= CLR_BIT3;
//------------------- Set & Clear bit of  WDTCR – Watchdog Timer Control Register -------------------
#define set_WDTCR        WDTCR  |= 0b00011111;
#define set_WDP0         WDTCR  |= SET_BIT0;
#define set_WDP1         WDTCR  |= SET_BIT1;
#define set_WDP2         WDTCR  |= SET_BIT2;
#define set_WDE          WDTCR  |= SET_BIT3;
#define set_WDTOE        WDTCR  |= SET_BIT4;

#define clr_WDTCR        WDTCR  &= 0b11100000;
#define clr_WDP0         WDTCR  &= CLR_BIT0;
#define clr_WDP1         WDTCR  &= CLR_BIT1;
#define clr_WDP2         WDTCR  &= CLR_BIT2;
#define clr_WDE          WDTCR  &= CLR_BIT3;
#define clr_WDTOE        WDTCR  &= CLR_BIT4;
//------------------- Set & Clear bit of  UBRRL and UBRRH – USART Baud Rate Registers -------------------
#define set_UBRRH          UBRRH  |= 0b10001111;
#define set_UBRR8          UBRRH  |= SET_BIT0;
#define set_UBRR9          UBRRH  |= SET_BIT1;
#define set_UBRR10         UBRRH  |= SET_BIT2;
#define set_UBRR11         UBRRH  |= SET_BIT3;
#define set_URSEL_UBRR     UBRRH  |= SET_BIT7;
#define set_UBRRL          UBRRL  |= 0xFF;
#define set_UBRR0          UBRRL  |= SET_BIT0;
#define set_UBRR1          UBRRL  |= SET_BIT1;
#define set_UBRR2          UBRRL  |= SET_BIT2;
#define set_UBRR3          UBRRL  |= SET_BIT3;
#define set_UBRR4          UBRRL  |= SET_BIT4;
#define set_UBRR5          UBRRL  |= SET_BIT5;
#define set_UBRR6          UBRRL  |= SET_BIT6;
#define set_UBRR7          UBRRL  |= SET_BIT7;

#define clr_UBRRH          UBRRH &= 0b01110000;
#define clr_UBRR8          UBRRH &= CLR_BIT0;
#define clr_UBRR9          UBRRH &= CLR_BIT1;
#define clr_UBRR10         UBRRH &= CLR_BIT2;
#define clr_UBRR11         UBRRH &= CLR_BIT3;
#define clr_URSEL_UBRR     UBRRH &= CLR_BIT7;
#define clr_UBRRL          UBRRL &= 0x00;
#define clr_UBRR0          UBRRL &= CLR_BIT0;
#define clr_UBRR1          UBRRL &= CLR_BIT1;
#define clr_UBRR2          UBRRL &= CLR_BIT2;
#define clr_UBRR3          UBRRL &= CLR_BIT3;
#define clr_UBRR4          UBRRL &= CLR_BIT4;
#define clr_UBRR5          UBRRL &= CLR_BIT5;
#define clr_UBRR6          UBRRL &= CLR_BIT6;
#define clr_UBRR7          UBRRL &= CLR_BIT7;
//------------------- Set & Clear bit of  UCSRC – USART Control and Status Register C -------------------
#define set_UCSRC          UCSRC  |= 0xFF;
#define set_UCPOL          UCSRC  |= SET_BIT0;
#define set_UCSZ0          UCSRC  |= SET_BIT1;
#define set_UCSZ1          UCSRC  |= SET_BIT2;
#define set_USBS           UCSRC  |= SET_BIT3;
#define set_UPM0           UCSRC  |= SET_BIT4;
#define set_UPM1           UCSRC  |= SET_BIT5;
#define set_UMSEL          UCSRC  |= SET_BIT6;
#define set_URSEL_UCSRC    UCSRC  |= SET_BIT7;

#define clr_UCSRC          UCSRC  &= 0x00;
#define clr_UCPOL          UCSRC  &= CLR_BIT0;
#define clr_UCSZ0          UCSRC  &= CLR_BIT1;
#define clr_UCSZ1          UCSRC  &= CLR_BIT2;
#define clr_USBS           UCSRC  &= CLR_BIT3;
#define clr_UPM0           UCSRC  &= CLR_BIT4;
#define clr_UPM1           UCSRC  &= CLR_BIT5;
#define clr_UMSEL          UCSRC  &= CLR_BIT6;
#define clr_URSEL_UCSRC    UCSRC  &= CLR_BIT7;
//------------------- Set & Clear bit of  EEARH and EEARL – The EEPROM Address Register -------------------
#define set_EEARL          EEARL  |= 0xFF;
#define set_EEAR0          EEARL  |= SET_BIT0;
#define set_EEAR1          EEARL  |= SET_BIT1;
#define set_EEAR2          EEARL  |= SET_BIT2;
#define set_EEAR3          EEARL  |= SET_BIT3;
#define set_EEAR4          EEARL  |= SET_BIT4;
#define set_EEAR5          EEARL  |= SET_BIT5;
#define set_EEAR6          EEARL  |= SET_BIT6;
#define set_EEAR7          EEARL  |= SET_BIT7;
#define set_EEARH          EEARH  |= 0xFF;
#define set_EEAR8          EEARH  |= SET_BIT0;

#define clr_EEARL          EEARL &= 0x00;
#define clr_EEAR0          EEARL &= CLR_BIT0;
#define clr_EEAR1          EEARL &= CLR_BIT1;
#define clr_EEAR2          EEARL &= CLR_BIT2;
#define clr_EEAR3          EEARL &= CLR_BIT3;
#define clr_EEAR4          EEARL &= CLR_BIT4;
#define clr_EEAR5          EEARL &= CLR_BIT5;
#define clr_EEAR6          EEARL &= CLR_BIT6;
#define clr_EEAR7          EEARL &= CLR_BIT7;
#define clr_EEARH          EEARH &= 0x00;
#define clr_EEAR8          EEARH &= CLR_BIT0;
//------------------- Set & Clear bit of  EEDR – The EEPROM Data Register -------------------
#define set_EEDR           EEDR  |= 0xFF;
#define set_EEDR0          EEDR  |= SET_BIT0;
#define set_EEDR1          EEDR  |= SET_BIT1;
#define set_EEDR2          EEDR  |= SET_BIT2;
#define set_EEDR3          EEDR  |= SET_BIT3;
#define set_EEDR4          EEDR  |= SET_BIT4;
#define set_EEDR5          EEDR  |= SET_BIT5;
#define set_EEDR6          EEDR  |= SET_BIT6;
#define set_EEDR7          EEDR  |= SET_BIT7;

#define clr_EEDR           EEDR &= 0x00;
#define clr_EEDR0          EEDR &= CLR_BIT0;
#define clr_EEDR1          EEDR &= CLR_BIT1;
#define clr_EEDR2          EEDR &= CLR_BIT2;
#define clr_EEDR3          EEDR &= CLR_BIT3;
#define clr_EEDR4          EEDR &= CLR_BIT4;
#define clr_EEDR5          EEDR &= CLR_BIT5;
#define clr_EEDR6          EEDR &= CLR_BIT6;
#define clr_EEDR7          EEDR &= CLR_BIT7;
//------------------- Set & Clear bit of  EECR – The EEPROM Data Register -------------------
#define set_EECR           EECR  |= 0xFF;
#define set_EECR0          EECR  |= SET_BIT0;
#define set_EECR1          EECR  |= SET_BIT1;
#define set_EECR2          EECR  |= SET_BIT2;
#define set_EECR3          EECR  |= SET_BIT3;

#define clr_EECR           EECR &= 0x00;
#define clr_EECR0          EECR &= CLR_BIT0;
#define clr_EECR1          EECR &= CLR_BIT1;
#define clr_EECR2          EECR &= CLR_BIT2;
#define clr_EECR3          EECR &= CLR_BIT3;
//------------------- Set & Clear bit of  I/O  -------------------
#define set_PA         PORTA |= 0xFF;
#define set_PA0        PORTA |= SET_BIT0;
#define set_PA1        PORTA |= SET_BIT1;
#define set_PA2        PORTA |= SET_BIT2;
#define set_PA3        PORTA |= SET_BIT3;
#define set_PA4        PORTA |= SET_BIT4;
#define set_PA5        PORTA |= SET_BIT5;
#define set_PA6        PORTA |= SET_BIT6;
#define set_PA7        PORTA |= SET_BIT7;

#define set_PB         PORTB |= 0xFF;
#define set_PB0        PORTB |= SET_BIT0;
#define set_PB1        PORTB |= SET_BIT1;
#define set_PB2        PORTB |= SET_BIT2;
#define set_PB3        PORTB |= SET_BIT3;
#define set_PB4        PORTB |= SET_BIT4;
#define set_PB5        PORTB |= SET_BIT5;
#define set_PB6        PORTB |= SET_BIT6;
#define set_PB7        PORTB |= SET_BIT7;

#define set_PC         PORTC |= 0xFF;
#define set_PC0        PORTC |= SET_BIT0;
#define set_PC1        PORTC |= SET_BIT1;
#define set_PC2        PORTC |= SET_BIT2;
#define set_PC3        PORTC |= SET_BIT3;
#define set_PC4        PORTC |= SET_BIT4;
#define set_PC5        PORTC |= SET_BIT5;
#define set_PC6        PORTC |= SET_BIT6;
#define set_PC7        PORTC |= SET_BIT7;

#define set_PD         PORTD |= 0xFF;
#define set_PD0        PORTD |= SET_BIT0;
#define set_PD1        PORTD |= SET_BIT1;
#define set_PD2        PORTD |= SET_BIT2;
#define set_PD3        PORTD |= SET_BIT3;
#define set_PD4        PORTD |= SET_BIT4;
#define set_PD5        PORTD |= SET_BIT5;
#define set_PD6        PORTD |= SET_BIT6;
#define set_PD7        PORTD |= SET_BIT7;

#define clr_PA         PORTA &= 0x00;
#define clr_PA0        PORTA &= CLR_BIT0;
#define clr_PA1        PORTA &= CLR_BIT1;
#define clr_PA2        PORTA &= CLR_BIT2;
#define clr_PA3        PORTA &= CLR_BIT3;
#define clr_PA4        PORTA &= CLR_BIT4;
#define clr_PA5        PORTA &= CLR_BIT5;
#define clr_PA6        PORTA &= CLR_BIT6;
#define clr_PA7        PORTA &= CLR_BIT7;

#define clr_PB         PORTB &= 0x00;
#define clr_PB0        PORTB &= CLR_BIT0;
#define clr_PB1        PORTB &= CLR_BIT1;
#define clr_PB2        PORTB &= CLR_BIT2;
#define clr_PB3        PORTB &= CLR_BIT3;
#define clr_PB4        PORTB &= CLR_BIT4;
#define clr_PB5        PORTB &= CLR_BIT5;
#define clr_PB6        PORTB &= CLR_BIT6;
#define clr_PB7        PORTB &= CLR_BIT7;

#define clr_PC         PORTC &= 0x00;
#define clr_PC0        PORTC &= CLR_BIT0;
#define clr_PC1        PORTC &= CLR_BIT1;
#define clr_PC2        PORTC &= CLR_BIT2;
#define clr_PC3        PORTC &= CLR_BIT3;
#define clr_PC4        PORTC &= CLR_BIT4;
#define clr_PC5        PORTC &= CLR_BIT5;
#define clr_PC6        PORTC &= CLR_BIT6;
#define clr_PC7        PORTC &= CLR_BIT7;

#define clr_PD         PORTD &= 0x00;
#define clr_PD0        PORTD &= CLR_BIT0;
#define clr_PD1        PORTD &= CLR_BIT1;
#define clr_PD2        PORTD &= CLR_BIT2;
#define clr_PD3        PORTD &= CLR_BIT3;
#define clr_PD4        PORTD &= CLR_BIT4;
#define clr_PD5        PORTD &= CLR_BIT5;
#define clr_PD6        PORTD &= CLR_BIT6;
#define clr_PD7        PORTD &= CLR_BIT7;

#define set_PORTA         PORTA |= 0xFF;
#define set_PORTA0        PORTA |= SET_BIT0;
#define set_PORTA1        PORTA |= SET_BIT1;
#define set_PORTA2        PORTA |= SET_BIT2;
#define set_PORTA3        PORTA |= SET_BIT3;
#define set_PORTA4        PORTA |= SET_BIT4;
#define set_PORTA5        PORTA |= SET_BIT5;
#define set_PORTA6        PORTA |= SET_BIT6;
#define set_PORTA7        PORTA |= SET_BIT7;

#define set_PORTB         PORTB |= 0xFF;
#define set_PORTB0        PORTB |= SET_BIT0;
#define set_PORTB1        PORTB |= SET_BIT1;
#define set_PORTB2        PORTB |= SET_BIT2;
#define set_PORTB3        PORTB |= SET_BIT3;
#define set_PORTB4        PORTB |= SET_BIT4;
#define set_PORTB5        PORTB |= SET_BIT5;
#define set_PORTB6        PORTB |= SET_BIT6;
#define set_PORTB7        PORTB |= SET_BIT7;

#define set_PORTC         PORTC |= 0xFF;
#define set_PORTC0        PORTC |= SET_BIT0;
#define set_PORTC1        PORTC |= SET_BIT1;
#define set_PORTC2        PORTC |= SET_BIT2;
#define set_PORTC3        PORTC |= SET_BIT3;
#define set_PORTC4        PORTC |= SET_BIT4;
#define set_PORTC5        PORTC |= SET_BIT5;
#define set_PORTC6        PORTC |= SET_BIT6;
#define set_PORTC7        PORTC |= SET_BIT7;

#define set_PORTD         PORTD |= 0xFF;
#define set_PORTD0        PORTD |= SET_BIT0;
#define set_PORTD1        PORTD |= SET_BIT1;
#define set_PORTD2        PORTD |= SET_BIT2;
#define set_PORTD3        PORTD |= SET_BIT3;
#define set_PORTD4        PORTD |= SET_BIT4;
#define set_PORTD5        PORTD |= SET_BIT5;
#define set_PORTD6        PORTD |= SET_BIT6;
#define set_PORTD7        PORTD |= SET_BIT7;

#define clr_PORTA         PORTA &= 0x00;
#define clr_PORTA0        PORTA &= CLR_BIT0;
#define clr_PORTA1        PORTA &= CLR_BIT1;
#define clr_PORTA2        PORTA &= CLR_BIT2;
#define clr_PORTA3        PORTA &= CLR_BIT3;
#define clr_PORTA4        PORTA &= CLR_BIT4;
#define clr_PORTA5        PORTA &= SET_BIT5;
#define clr_PORTA6        PORTA &= CLR_BIT6;
#define clr_PORTA7        PORTA &= CLR_BIT7;

#define clr_PORTB         PORTB &= 0x00;
#define clr_PORTB0        PORTB &= CLR_BIT0;
#define clr_PORTB1        PORTB &= CLR_BIT1;
#define clr_PORTB2        PORTB &= CLR_BIT2;
#define clr_PORTB3        PORTB &= CLR_BIT3;
#define clr_PORTB4        PORTB &= CLR_BIT4;
#define clr_PORTB5        PORTB &= CLR_BIT5;
#define clr_PORTB6        PORTB &= CLR_BIT6;
#define clr_PORTB7        PORTB &= CLR_BIT7;

#define clr_PORTC         PORTC &= 0x00;
#define clr_PORTC0        PORTC &= CLR_BIT0;
#define clr_PORTC1        PORTC &= CLR_BIT1;
#define clr_PORTC2        PORTC &= CLR_BIT2;
#define clr_PORTC3        PORTC &= CLR_BIT3;
#define clr_PORTC4        PORTC &= CLR_BIT4;
#define clr_PORTC5        PORTC &= CLR_BIT5;
#define clr_PORTC6        PORTC &= CLR_BIT6;
#define clr_PORTC7        PORTC &= CLR_BIT7;

#define clr_PORTD         PORTD &= 0x00;
#define clr_PORTD0        PORTD &= CLR_BIT0;
#define clr_PORTD1        PORTD &= CLR_BIT1;
#define clr_PORTD2        PORTD &= CLR_BIT2;
#define clr_PORTD3        PORTD &= CLR_BIT3;
#define clr_PORTD4        PORTD &= CLR_BIT4;
#define clr_PORTD5        PORTD &= CLR_BIT5;
#define clr_PORTD6        PORTD &= CLR_BIT6;
#define clr_PORTD7        PORTD &= CLR_BIT7;
//------------------- Set & Clear bit of  DDR  -------------------
#define set_DDRA         DDRA |= 0xFF;
#define set_DDRA0        DDRA |= SET_BIT0;
#define set_DDRA1        DDRA |= SET_BIT1;
#define set_DDRA2        DDRA |= SET_BIT2;
#define set_DDRA3        DDRA |= SET_BIT3;
#define set_DDRA4        DDRA |= SET_BIT4;
#define set_DDRA5        DDRA |= SET_BIT5;
#define set_DDRA6        DDRA |= SET_BIT6;
#define set_DDRA7        DDRA |= SET_BIT7;

#define set_DDRB         DDRB |= 0xFF;
#define set_DDRB0        DDRB |= SET_BIT0;
#define set_DDRB1        DDRB |= SET_BIT1;
#define set_DDRB2        DDRB |= SET_BIT2;
#define set_DDRB3        DDRB |= SET_BIT3;
#define set_DDRB4        DDRB |= SET_BIT4;
#define set_DDRB5        DDRB |= SET_BIT5;
#define set_DDRB6        DDRB |= SET_BIT6;
#define set_DDRB7        DDRB |= SET_BIT7;

#define set_DDRC         DDRC |= 0xFF;
#define set_DDRC0        DDRC |= SET_BIT0;
#define set_DDRC1        DDRC |= SET_BIT1;
#define set_DDRC2        DDRC |= SET_BIT2;
#define set_DDRC3        DDRC |= SET_BIT3;
#define set_DDRC4        DDRC |= SET_BIT4;
#define set_DDRC5        DDRC |= SET_BIT5;
#define set_DDRC6        DDRC |= SET_BIT6;
#define set_DDRC7        DDRC |= SET_BIT7;

#define set_DDRD         DDRD |= 0xFF;
#define set_DDRD0        DDRD |= SET_BIT0;
#define set_DDRD1        DDRD |= SET_BIT1;
#define set_DDRD2        DDRD |= SET_BIT2;
#define set_DDRD3        DDRD |= SET_BIT3;
#define set_DDRD4        DDRD |= SET_BIT4;
#define set_DDRD5        DDRD |= SET_BIT5;
#define set_DDRD6        DDRD |= SET_BIT6;
#define set_DDRD7        DDRD |= SET_BIT7;

#define clr_DDRA         DDRA &= 0x00;
#define clr_DDRA0        DDRA &= CLR_BIT0;
#define clr_DDRA1        DDRA &= CLR_BIT1;
#define clr_DDRA2        DDRA &= CLR_BIT2;
#define clr_DDRA3        DDRA &= CLR_BIT3;
#define clr_DDRA4        DDRA &= CLR_BIT4;
#define clr_DDRA5        DDRA &= SET_BIT5;
#define clr_DDRA6        DDRA &= CLR_BIT6;
#define clr_DDRA7        DDRA &= CLR_BIT7;

#define clr_DDRB         DDRB &= 0x00;
#define clr_DDRB0        DDRB &= CLR_BIT0;
#define clr_DDRB1        DDRB &= CLR_BIT1;
#define clr_DDRB2        DDRB &= CLR_BIT2;
#define clr_DDRB3        DDRB &= CLR_BIT3;
#define clr_DDRB4        DDRB &= CLR_BIT4;
#define clr_DDRB5        DDRB &= CLR_BIT5;
#define clr_DDRB6        DDRB &= CLR_BIT6;
#define clr_DDRB7        DDRB &= CLR_BIT7;

#define clr_DDRC         DDRC &= 0x00;
#define clr_DDRC0        DDRC &= CLR_BIT0;
#define clr_DDRC1        DDRC &= CLR_BIT1;
#define clr_DDRC2        DDRC &= CLR_BIT2;
#define clr_DDRC3        DDRC &= CLR_BIT3;
#define clr_DDRC4        DDRC &= CLR_BIT4;
#define clr_DDRC5        DDRC &= CLR_BIT5;
#define clr_DDRC6        DDRC &= CLR_BIT6;
#define clr_DDRC7        DDRC &= CLR_BIT7;

#define clr_DDRD         DDRD &= 0x00;
#define clr_DDRD0        DDRD &= CLR_BIT0;
#define clr_DDRD1        DDRD &= CLR_BIT1;
#define clr_DDRD2        DDRD &= CLR_BIT2;
#define clr_DDRD3        DDRD &= CLR_BIT3;
#define clr_DDRD4        DDRD &= CLR_BIT4;
#define clr_DDRD5        DDRD &= CLR_BIT5;
#define clr_DDRD6        DDRD &= CLR_BIT6;
#define clr_DDRD7        DDRD &= CLR_BIT7;
//------------------- Set & Clear bit of  SPSR – SPI Status Register  -------------------
#define set_SPSR         SPSR |= 0b00000001;
#define set_SPI2X        SPSR |= 0b00000001;
//------------------- Set & Clear bit of  SPCR – SPI Control Register  -------------------
#define set_SPCR         SPCR |= 0xFF;
#define set_SPR0         SPCR |= SET_BIT0;
#define set_SPR1         SPCR |= SET_BIT1;
#define set_CPHA         SPCR |= SET_BIT2;
#define set_CPOL         SPCR |= SET_BIT3;
#define set_MSTR         SPCR |= SET_BIT4;
#define set_DORD         SPCR |= SET_BIT5;
#define set_SPE          SPCR |= SET_BIT6;
#define set_SPIE         SPCR |= SET_BIT7;

#define clr_SPCR         SPCR &= 0x00;
#define clr_SPR0         SPCR &= CLR_BIT0;
#define clr_SPR1         SPCR &= CLR_BIT1;
#define clr_CPHA         SPCR &= CLR_BIT2;
#define clr_CPOL         SPCR &= CLR_BIT3;
#define clr_MSTR         SPCR &= CLR_BIT4;
#define clr_DORD         SPCR &= CLR_BIT5;
#define clr_SPE          SPCR &= CLR_BIT6;
#define clr_SPIE         SPCR &= CLR_BIT7;
//------------------- Set & Clear bit of  UCSRA – USART Control and Status Register A  -------------------
#define set_MPCM         UCSRA |= SET_BIT0;
#define set_U2X          UCSRA |= SET_BIT1;
#define set_TXC          UCSRA |= SET_BIT6;

#define clr_MPCM         UCSRA &= CLR_BIT0;
#define clr_U2X          UCSRA &= CLR_BIT1;
#define clr_TXC          UCSRA &= CLR_BIT6;
//------------------- Set & Clear bit of  UCSRB – USART Control and Status Register B  -------------------
#define set_TXB8         UCSRB |= SET_BIT0;
#define set_UCSZ2        UCSRB |= SET_BIT2;
#define set_TXEN         UCSRB |= SET_BIT3;
#define set_RXEN         UCSRB |= SET_BIT4;
#define set_UDRIE        UCSRB |= SET_BIT5;
#define set_TXCIE        UCSRB |= SET_BIT6;
#define set_RXCIE        UCSRB |= SET_BIT7;

#define clr_TXB8         UCSRB &= CLR_BIT0;
#define clr_UCSZ2        UCSRB &= CLR_BIT2;
#define clr_TXEN         UCSRB &= CLR_BIT3;
#define clr_RXEN         UCSRB &= CLR_BIT4;
#define clr_UDRIE        UCSRB &= CLR_BIT5;
#define clr_TXCIE        UCSRB &= CLR_BIT6;
#define clr_RXCIE        UCSRB &= CLR_BIT7;
//------------------- Set & Clear bit of  ACSR – Analog Comparator Control and Status Register  -------------------
#define set_ACIS0        ACSR |= SET_BIT0;
#define set_SCIS1        ACSR |= SET_BIT1;
#define set_ACIC         ACSR |= SET_BIT2;
#define set_ACIE         ACSR |= SET_BIT3;
#define set_ACI          ACSR |= SET_BIT4;
#define set_ACBG         ACSR |= SET_BIT6;
#define set_ACD          ACSR |= SET_BIT7;

#define clr_ACIS0        ACSR &= CLR_BIT0;
#define clr_SCIS1        ACSR &= CLR_BIT1;
#define clr_ACIC         ACSR &= CLR_BIT2;
#define clr_ACIE         ACSR &= CLR_BIT3;
#define clr_ACI          ACSR &= CLR_BIT4;
#define clr_ACBG         ACSR &= CLR_BIT6;
#define clr_ACD          ACSR &= CLR_BIT7;
//------------------- Set & Clear bit of  ADMUX – ADC Multiplexer Selection Register  -------------------
#define set_ADMUX        ADMUX |= 0xFF;
#define set_MUX0         ADMUX |= SET_BIT0;
#define set_MUX1         ADMUX |= SET_BIT1;
#define set_MUX2         ADMUX |= SET_BIT2;
#define set_MUX3         ADMUX |= SET_BIT3;
#define set_MUX4         ADMUX |= SET_BIT4;
#define set_ADLAR        ADMUX |= SET_BIT5;
#define set_REDS0        ADMUX |= SET_BIT6;
#define set_REFS1        ADMUX |= SET_BIT7;

#define clr_ADMUX        ADMUX &= 0x00;
#define clr_MUX0         ADMUX &= CLR_BIT0;
#define clr_MUX1         ADMUX &= CLR_BIT1;
#define clr_MUX2         ADMUX &= CLR_BIT2;
#define clr_MUX3         ADMUX &= CLR_BIT3;
#define clr_MUX4         ADMUX &= CLR_BIT4;
#define clr_ADLAR        ADMUX &= CLR_BIT5;
#define clr_REDS0        ADMUX &= CLR_BIT6;
#define clr_REFS1        ADMUX &= CLR_BIT7;
//------------------- Set & Clear bit of  ADCSRA – ADC Control and Status Register A  -------------------
#define set_ADCSRA       ADCSRA |= 0xFF;
#define set_ADPS0        ADCSRA |= SET_BIT0;
#define set_ADPS1        ADCSRA |= SET_BIT1;
#define set_ADPS2        ADCSRA |= SET_BIT2;
#define set_ADIE         ADCSRA |= SET_BIT3;
#define set_ADIF         ADCSRA |= SET_BIT4;
#define set_ADATE        ADCSRA |= SET_BIT5;
#define set_ADSC         ADCSRA |= SET_BIT6;
#define set_ADEN         ADCSRA |= SET_BIT7;

#define clr_ADCSRA       ADCSRA &= 0x00;
#define clr_ADPS0        ADCSRA &= CLR_BIT0;
#define clr_ADPS1        ADCSRA &= CLR_BIT1;
#define clr_ADPS2        ADCSRA &= CLR_BIT2;
#define clr_ADIE         ADCSRA &= CLR_BIT3;
#define clr_ADIF         ADCSRA &= CLR_BIT4;
#define clr_ADATE        ADCSRA &= CLR_BIT5;
#define clr_ADSC         ADCSRA &= CLR_BIT6;
#define clr_ADEN         ADCSRA &= CLR_BIT7;
//------------------- Set & Clear bit of  TWBR – TWI Bit Rate Register  -------------------
#define set_TWBR         TWBR |= 0xFF;
#define set_TWBR0        TWBR |= SET_BIT0;
#define set_TWBR1        TWBR |= SET_BIT1;
#define set_TWBR2        TWBR |= SET_BIT2;
#define set_TWBR3        TWBR |= SET_BIT3;
#define set_TWBR4        TWBR |= SET_BIT4;
#define set_TWBR5        TWBR |= SET_BIT5;
#define set_TWBR6        TWBR |= SET_BIT6;
#define set_TWBR7        TWBR |= SET_BIT7;

#define clr_TWBR         TWBR &= 0x00;
#define clr_TWBR0        TWBR &= CLR_BIT0;
#define clr_TWBR1        TWBR &= CLR_BIT1;
#define clr_TWBR2        TWBR &= CLR_BIT2;
#define clr_TWBR3        TWBR &= CLR_BIT3;
#define clr_TWBR4        TWBR &= CLR_BIT4;
#define clr_TWBR5        TWBR &= CLR_BIT5;
#define clr_TWBR6        TWBR &= CLR_BIT6;
#define clr_TWBR7        TWBR &= CLR_BIT7;
//------------------- Set & Clear bit of  TWSR – TWI Status Register  -------------------
#define set_TWPS0        TWSR |= SET_BIT0;
#define set_TWPS1        TWSR |= SET_BIT1;

#define clr_TWPS0        TWSR &= CLR_BIT0;
#define clr_TWPS1        TWSR &= CLR_BIT1;
//------------------- Set & Clear bit of TWAR– TWI (Slave) Address Register  -------------------
#define set_TWAR         TWAR |= 0xFF;
#define set_TWGCE        TWAR |= SET_BIT0;
#define set_TWA0        TWAR |= SET_BIT1;
#define set_TWA1        TWAR |= SET_BIT2;
#define set_TWA2        TWAR |= SET_BIT3;
#define set_TWA3        TWAR |= SET_BIT4;
#define set_TWA4        TWAR |= SET_BIT5;
#define set_TWA5        TWAR |= SET_BIT6;
#define set_TWA6        TWAR |= SET_BIT7;

#define clr_TWAR        TWAR &= 0x00;
#define clr_TWGCE       TWAR &= CLR_BIT0;
#define clr_TWA0        TWAR &= CLR_BIT1;
#define clr_TWA1        TWAR &= CLR_BIT2;
#define clr_TWA2        TWAR &= CLR_BIT3;
#define clr_TWA3        TWAR &= CLR_BIT4;
#define clr_TWA4        TWAR &= CLR_BIT5;
#define clr_TWA5        TWAR &= CLR_BIT6;
#define clr_TWA6        TWAR &= CLR_BIT7;
//------------------- End  ------------------- ///




#endif /* SFR_MACRO_H_ */