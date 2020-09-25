/*
 * Function_Define.h
 *
 * Created: 12/2/2019 3:58:34 PM
 *  Author: ADMIN
 */ 


#ifndef FUNCTION_DEFINE_H_
#define FUNCTION_DEFINE_H_

//#include "instrins.h"
//16 --> 8 x 2
#define HIBYTE(v1)              ((unsigned char)((v1)>>8))                      //v1 is uint16_t
#define LOBYTE(v1)              ((unsigned char)((v1)&0xFF))
//8 x 2 --> 16
#define MAKEWORD(v1,v2)         ((((uint16_t)(v1))<<8)+(uint16_t)(v2))      //v1,v2 is unsigned char
//8 x 4 --> 32
#define MAKELONG(v1,v2,v3,v4)   (UINT32)((v1<<32)+(v2<<16)+(v3<<8)+v4)  //v1,v2,v3,v4 is unsigned char
//32 --> 16 x 2
#define YBYTE1(v1)              ((uint16_t)((v1)>>16))                    //v1 is UINT32
#define YBYTE0(v1)              ((uint16_t)((v1)&0xFFFF))
//32 --> 8 x 4
#define TBYTE3(v1)              ((unsigned char)((v1)>>24))                     //v1 is UINT32
#define TBYTE2(v1)              ((unsigned char)((v1)>>16))
#define TBYTE1(v1)              ((unsigned char)((v1)>>8))
#define TBYTE0(v1)              ((unsigned char)((v1)&0xFF))

#define SET_BIT0        0x01
#define SET_BIT1        0x02
#define SET_BIT2        0x04
#define SET_BIT3        0x08
#define SET_BIT4        0x10
#define SET_BIT5        0x20
#define SET_BIT6        0x40
#define SET_BIT7        0x80
#define SET_BIT8        0x0100
#define SET_BIT9        0x0200
#define SET_BIT10       0x0400
#define SET_BIT11       0x0800
#define SET_BIT12       0x1000
#define SET_BIT13       0x2000
#define SET_BIT14       0x4000
#define SET_BIT15       0x8000

#define CLR_BIT0        0xFE
#define CLR_BIT1        0xFD
#define CLR_BIT2        0xFB
#define CLR_BIT3        0xF7
#define CLR_BIT4        0xEF
#define CLR_BIT5        0xDF
#define CLR_BIT6        0xBF
#define CLR_BIT7        0x7F
#define CLR_BIT8        0xFEFF
#define CLR_BIT9        0xFDFF
#define CLR_BIT10       0xFBFF
#define CLR_BIT11       0xF7FF
#define CLR_BIT12       0xEFFF
#define CLR_BIT13       0xDFFF
#define CLR_BIT14       0xBFFF
#define CLR_BIT15       0x7FFF

#define FAIL            1
#define PASS            0
/*****************************************************************************************
* For GPIO INIT setting
*****************************************************************************************/
//------------------- Define I/O as Output -------------------
#define PA_Output_Mode      DDRA |= 0xFF;
#define PA0_Output_Mode     DDRA |= SET_BIT0;
#define PA1_Output_Mode     DDRA |= SET_BIT1;
#define PA2_Output_Mode     DDRA |= SET_BIT2;
#define PA3_Output_Mode     DDRA |= SET_BIT3;
#define PA4_Output_Mode     DDRA |= SET_BIT4;
#define PA5_Output_Mode     DDRA |= SET_BIT5;
#define PA6_Output_Mode     DDRA |= SET_BIT6;
#define PA7_Output_Mode     DDRA |= SET_BIT7;

#define PB_Output_Mode      DDRB |= 0xFF;
#define PB0_Output_Mode     DDRB |= SET_BIT0;
#define PB1_Output_Mode     DDRB |= SET_BIT1;
#define PB2_Output_Mode     DDRB |= SET_BIT2;
#define PB3_Output_Mode     DDRB |= SET_BIT3;
#define PB4_Output_Mode     DDRB |= SET_BIT4;
#define PB5_Output_Mode     DDRB |= SET_BIT5;
#define PB6_Output_Mode     DDRB |= SET_BIT6;
#define PB7_Output_Mode     DDRB |= SET_BIT7;

#define PC_Output_Mode      DDRC |= 0xFF;
#define PC0_Output_Mode     DDRC |= SET_BIT0;
#define PC1_Output_Mode     DDRC |= SET_BIT1;
#define PC2_Output_Mode     DDRC |= SET_BIT2;
#define PC3_Output_Mode     DDRC |= SET_BIT3;
#define PC4_Output_Mode     DDRC |= SET_BIT4;
#define PC5_Output_Mode     DDRC |= SET_BIT5;
#define PC6_Output_Mode     DDRC |= SET_BIT6;
#define PC7_Output_Mode     DDRC |= SET_BIT7;

#define PD_Output_Mode      DDRD |= 0xFF;
#define PD0_Output_Mode     DDRD |= SET_BIT0;
#define PD1_Output_Mode     DDRD |= SET_BIT1;
#define PD2_Output_Mode     DDRD |= SET_BIT2;
#define PD3_Output_Mode     DDRD |= SET_BIT3;
#define PD4_Output_Mode     DDRD |= SET_BIT4;
#define PD5_Output_Mode     DDRD |= SET_BIT5;
#define PD6_Output_Mode     DDRD |= SET_BIT6;
#define PD7_Output_Mode     DDRD |= SET_BIT7;

//------------------- Define I/O as Input -------------------
#define PA_Input_Mode      DDRA &= 0x00;
#define PA0_Input_Mode     DDRA &= CLR_BIT0;
#define PA1_Input_Mode     DDRA &= CLR_BIT1;
#define PA2_Input_Mode     DDRA &= CLR_BIT2;
#define PA3_Input_Mode     DDRA &= CLR_BIT3;
#define PA4_Input_Mode     DDRA &= CLR_BIT4;
#define PA5_Input_Mode     DDRA &= CLR_BIT5;
#define PA6_Input_Mode     DDRA &= CLR_BIT6;
#define PA7_Input_Mode     DDRA &= CLR_BIT7;

#define PB_Input_Mode      DDRB &= 0x00;
#define PB0_Input_Mode     DDRB &= CLR_BIT0;
#define PB1_Input_Mode     DDRB &= CLR_BIT1;
#define PB2_Input_Mode     DDRB &= CLR_BIT2;
#define PB3_Input_Mode     DDRB &= CLR_BIT3;
#define PB4_Input_Mode     DDRB &= CLR_BIT4;
#define PB5_Input_Mode     DDRB &= CLR_BIT5;
#define PB6_Input_Mode     DDRB &= CLR_BIT6;
#define PB7_Input_Mode     DDRB &= CLR_BIT7;

#define PC_Input_Mode      DDRC &= 0x00;
#define PC0_Input_Mode     DDRC &= CLR_BIT0;
#define PC1_Input_Mode     DDRC &= CLR_BIT1;
#define PC2_Input_Mode     DDRC &= CLR_BIT2;
#define PC3_Input_Mode     DDRC &= CLR_BIT3;
#define PC4_Input_Mode     DDRC &= CLR_BIT4;
#define PC5_Input_Mode     DDRC &= CLR_BIT5;
#define PC6_Input_Mode     DDRC &= CLR_BIT6;
#define PC7_Input_Mode     DDRC &= CLR_BIT7;

#define PD_Input_Mode      DDRD &= 0x00;
#define PD0_Input_Mode     DDRD &= CLR_BIT0;
#define PD1_Input_Mode     DDRD &= CLR_BIT1;
#define PD2_Input_Mode     DDRD &= CLR_BIT2;
#define PD3_Input_Mode     DDRD &= CLR_BIT3;
#define PD4_Input_Mode     DDRD &= CLR_BIT4;
#define PD5_Input_Mode     DDRD &= CLR_BIT5;
#define PD6_Input_Mode     DDRD &= CLR_BIT6;
#define PD7_Input_Mode     DDRD &= CLR_BIT7;

/*****************************************************************************************
* For Clock Source INIT setting
*****************************************************************************************/





#endif /* FUNCTION_DEFINE_H_ */