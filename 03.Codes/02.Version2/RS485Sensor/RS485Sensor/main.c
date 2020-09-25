/*
 * RS485Sensor.c
 *
 * Created: 12/4/2019 8:42:47 AM
 * Author : ADMIN
 */ 
#define F_CPU 11059200UL

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include "Function_Define.h"
#include "SFR_Macro.h"
#include "SHT31.h"
#include "timer.h"
#include "uart.h"
#include "modbus_rtu.h"


#define TIMER0_PRESCALING PRESCALING_64_TIMER0
#define ADDR 0x000B
#define eeprom_rw(v_addr) eeprom_read_word ((uint16_t *)(v_addr))
#define eeprom_ww(v_addr, v_dat) eeprom_write_word ((uint16_t *)(v_addr), (uint16_t)(v_dat))

volatile unsigned int vrui_temp = 0, vrui_hum = 0;
unsigned char vruc_modbus_temp[2];
float vrf_temp, vrf_hum;
volatile unsigned int vrui_timer0_overflow = 0;
volatile unsigned char vruc_countmodbuslength=0, vruc_modbuslength = 0;
unsigned char vruc_modbusrtu_data[20];
unsigned char vruc_rxc_data='A', vruc_rxc_flag=0;
unsigned char vruc_length;
unsigned char vruc_modbus_address = 0x01, vruc_modbus_oldaddress= 0xFF;
volatile unsigned int  vruc_scanvalue_overflow = 0, vruc_blinkled_overflow = 0; 
volatile unsigned char vruc_scanvalue_flag=0, vruc_blinkled_flag = 0;
unsigned long int vruli_baudrate;
unsigned int vrui_baudrate = 96;



void fnPort_Init() {
	PD3_Output_Mode;
	PD2_Output_Mode;
	set_PD2;
	set_PD3;
//LED in LED7Segment	
	PB0_Output_Mode;     //Pin40    D 
	PB1_Output_Mode;     //Pin41    E
	PB2_Output_Mode;	 //Pin42    C
	PB3_Output_Mode;	 //Pin43    A
	PB4_Output_Mode;	 //Pin44    B
	PB5_Output_Mode;	 //Pin1     F
	PB6_Output_Mode;	 //Pin2     G
//Turnoff LED 7 Seg
	set_PB3;
	set_PB4;
	set_PB2;
	set_PB0;
	set_PB1;
	set_PB5;
	set_PB6;
//Pin control LED7Segment
	PA0_Output_Mode;     //Pin37    UP 12x
	PA1_Output_Mode;     //Pin36    UP 1x3 
	PA2_Output_Mode;	 //Pin35    UP x23
	PA3_Output_Mode;	 //Pin34    DOWN 45x
	PA4_Output_Mode;	 //Pin33    DOWN 4x6
	PA5_Output_Mode;     //Pin32    DOWN x56
//Turn off pin control LED7Segment
    set_PA0;
    set_PA1;
    set_PA2;
    set_PA3;
    set_PA4;
    set_PA5;
//SCL-SDA
//     PC0_Output_Mode;
// 	PC1_Output_Mode;	
// 	clr_PC0;
// 	clr_PC1;
    PC2_Input_Mode;
	PC3_Input_Mode;
	PC4_Input_Mode;
	PC5_Input_Mode;
	
	PD7_Input_Mode;    // CAL
	set_PD7;
}
unsigned char fnAddressScan(void) {
	unsigned char addr;
	addr = (PINC>>2)&0x0F;
	return addr;
}
void fnNumberofLED(unsigned char vruc_number) {
	switch(vruc_number) {
		case 0  :
		    clr_PB3;
		    clr_PB4;
		    clr_PB2;
		    clr_PB0;
		    clr_PB1;
		    clr_PB5;
		    set_PB6;
		    break;
		case 1  :
		    set_PB3;
		    clr_PB4;
		    clr_PB2;
		    set_PB0;
		    set_PB1;
		    set_PB5;
		    set_PB6;
		    break;
		case 2  :
		    clr_PB3;
		    clr_PB4;
		    set_PB2;
		    clr_PB0;
		    clr_PB1;
		    set_PB5;
		    clr_PB6;
		    break;
		case 3  :
		    clr_PB3;
		    clr_PB4;
		    clr_PB2;
		    clr_PB0;
		    set_PB1;
		    set_PB5;
		    clr_PB6;
		    break;
		case 4  :
		    set_PB3;
		    clr_PB4;
		    clr_PB2;
		    set_PB0;
		    set_PB1;
		    clr_PB5;
		    clr_PB6;
		    break;
		case 5  :
		    clr_PB3;
		    set_PB4;
		    clr_PB2;
		    clr_PB0;
		    set_PB1;
		    clr_PB5;
		    clr_PB6;
		    break;
		case 6  :
		    clr_PB3;
		    set_PB4;
		    clr_PB2;
		    clr_PB0;
		    clr_PB1;
		    clr_PB5;
		    clr_PB6;
		    break;
		case 7  :
		    clr_PB3;
		    clr_PB4;
		    clr_PB2;
		    set_PB0;
		    set_PB1;
		    set_PB5;
		    set_PB6;
		    break;
		case 8  :
		    clr_PB3;
		    clr_PB4;
		    clr_PB2;
		    clr_PB0;
		    clr_PB1;
		    clr_PB5;
		    clr_PB6;
		    break;
		case 9:
		    clr_PB3;
		    clr_PB4;
		    clr_PB2;
		    clr_PB0;
		    set_PB1;
		    clr_PB5;
		    clr_PB6;
		    break;
		default :
		    break;
	}
}
void fnScanLED(unsigned int temp,unsigned int hum) {
	unsigned char i;
	i = temp % 10;
	fnNumberofLED(i);
	clr_PA0;
    _delay_us(100);
	set_PA0;
	i = (temp%100)/10;
	fnNumberofLED(i);
	clr_PA1;
    _delay_us(100);
	set_PA1;
	i = temp/100;
	fnNumberofLED(i);
	clr_PA2;
    _delay_us(100);
	set_PA2;
	i = hum % 10;
	fnNumberofLED(i);
	clr_PA3;
    _delay_us(100);
	set_PA3;
	i = (hum%100)/10;
	fnNumberofLED(i);
	clr_PA4;
    _delay_us(100);
	set_PA4;
	i = hum/100;
	fnNumberofLED(i);
	clr_PA5;
    _delay_us(100);
	set_PA5;
}
void fnScanLED_SetBaud(void) {
	set_PB3;
	set_PB4;
	set_PB2;
	clr_PB0;
	clr_PB1;
	clr_PB5;
	clr_PB6;
	clr_PA0;	
	_delay_us(100);
	set_PA0;
	clr_PB3;
	set_PB4;
	set_PB2;
	clr_PB0;
	clr_PB1;
	clr_PB5;
	clr_PB6;
	clr_PA1;
	_delay_us(100);
	set_PA1;
	clr_PB3;
	set_PB4;
	clr_PB2;
	clr_PB0;
	set_PB1;
	clr_PB5;
	clr_PB6;
	clr_PA2;
	_delay_us(100);
	set_PA2;
	set_PB3;
	set_PB4;
	clr_PB2;
	clr_PB0;
	clr_PB1;
	set_PB5;
	set_PB6;
	clr_PA3;
	_delay_us(100);
	set_PA3;
	clr_PB3;
	clr_PB4;
	clr_PB2;
	set_PB0;
	clr_PB1;
	clr_PB5;
	clr_PB6;
	clr_PA4;
	_delay_us(100);
	set_PA4;
	set_PB3;
	set_PB4;
	clr_PB2;
	clr_PB0;
	clr_PB1;
	clr_PB5;
	clr_PB6;
	clr_PA5;
	_delay_us(100);
	set_PA5;
}
void fnScanLED_Baud(unsigned int baud) {
	unsigned char i;
	i = (baud%100)/10;
	fnNumberofLED(i);
	clr_PA0;
	_delay_us(50);
	set_PA0;
	i = (baud%1000)/100;
	fnNumberofLED(i);
	clr_PA1;
	_delay_us(50);
	set_PA1;
	i = (baud%10000)/1000;
	fnNumberofLED(i);
	clr_PA2;
	_delay_us(50);
	set_PA2;
	fnNumberofLED(0);
	clr_PA3;
	_delay_us(50);
	set_PA3;
	fnNumberofLED(0);
	clr_PA4;
	_delay_us(50);
	set_PA4;
	i = baud%10;
	fnNumberofLED(i);
	clr_PA5;
	_delay_us(50);
	set_PA5;
}
void WDT_On(void) {
	/*
	Watchdog timer enables with typical timeout period 2.1 
	second.
	*/
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

void WDT_Off(void) {
	/*
	This function use for disable the watchdog timer.
	*/
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

int main(void) {
	if (eeprom_rw(ADDR) == 0xFFFF) {
		eeprom_ww(ADDR, 0x60);
	}
	vrui_baudrate = eeprom_rw(ADDR);
	vruli_baudrate = vrui_baudrate*100;
	fnPort_Init();
	timer2_Init(PRESCALING_64_TIMER2);
	timer2_Enable();
    sei();
	vruc_modbus_address = fnAddressScan();
	if (((PIND>>7) & 0x01) == 0) {
		vruc_modbus_address += 15;
	}
	else {
	    if (vruc_modbus_address == 0) {
			vruc_blinkled_flag = 1;
			while(vruc_modbus_address != vruc_modbus_oldaddress || vruc_modbus_address > 8 || vruc_modbus_address == 0) {
				vruc_modbus_oldaddress = vruc_modbus_address;
				_delay_ms(2000);
				vruc_modbus_address = fnAddressScan();
			}
			switch (vruc_modbus_address) {
				case 1:
				    vrui_baudrate = 12;
				    break;
				case 2:
				    vrui_baudrate = 24;
				    break;
				case 3:
				    vrui_baudrate = 48;
				    break;
				case 4:
				    vrui_baudrate = 96;
				    break;				
				case 5:
				    vrui_baudrate = 192;
				    break;		
				case 6:
				    vrui_baudrate = 384;
				    break;				
				case 7:
				    vrui_baudrate = 576;
				    break;				
				case 8:
				    vrui_baudrate = 1152;
				    break;						
			}
			eeprom_ww(ADDR, vrui_baudrate);
			vruc_blinkled_flag = 2;
			timer2_Disable();
			clr_PD3;
			while(1) {
				fnScanLED_Baud(vrui_baudrate);
			}
		} 	
	}
	sei();
    SHT31_Init(10000);
	UART_Init(vruli_baudrate);
    SHT31_Soft_Reset();
	clr_PD2;
    while (1) {	
		WDT_On();
	    SHT31_SingleShot_Mode(&vrf_temp, &vrf_hum);
		WDT_Off();
 	    _delay_ms(200);

    }
}

ISR (USART_RXC_vect) {
	if (vruc_countmodbuslength == 0) {
		vrui_timer0_overflow = 0;
	} 
	vruc_modbusrtu_data[vruc_countmodbuslength] = UDR;
	vruc_countmodbuslength++;
}
ISR(TIMER2_OVF_vect) {
	if (vruc_blinkled_flag == 1) {
		vruc_blinkled_overflow++;
		fnScanLED_SetBaud();
		if (vruc_blinkled_overflow < 100) {
			clr_PD3;
		}
		else if (vruc_blinkled_overflow >=100 && vruc_blinkled_overflow < 200) {
			set_PD3;
		}
		else {
			vruc_blinkled_overflow = 0;
		}
	}
	else if (vruc_blinkled_flag == 0){
		if (vruc_countmodbuslength != 0) {
			vrui_timer0_overflow++;
		}
		else {
			vrui_timer0_overflow=0;
		}
		if(vrui_timer0_overflow > 15) {
			if (vruc_modbuslength != vruc_countmodbuslength) {
				vruc_modbuslength = vruc_countmodbuslength;
				vruc_rxc_flag = 1;
				vrui_timer0_overflow = 0;
			}
			vruc_countmodbuslength = 0;
		}
		vruc_scanvalue_overflow++;
		if (vruc_scanvalue_overflow >= 500) {
			vrui_temp = vrf_temp*10;
			vrui_hum  = vrf_hum*10;
			vruc_scanvalue_overflow = 0;
		}
		fnScanLED(vrui_hum, vrui_temp);
	}
	if (vruc_rxc_flag == 1) {
	    set_PD2;
        ModbusRTU_FrameHandling(vruc_modbus_address, vruc_modbusrtu_data, vruc_modbuslength, vrf_temp*100, vrf_hum*100);
//         for (unsigned char i = 0; i < vruc_modbuslength;i++) {
//            UART_TxChar(vruc_modbusrtu_data[i]);
// 		   UART_TxChar(i);
//  	   }
	    _delay_ms(2);
	    vruc_rxc_flag = 0;
	    vruc_modbuslength = 0;
	    clr_PD2;
	}
}