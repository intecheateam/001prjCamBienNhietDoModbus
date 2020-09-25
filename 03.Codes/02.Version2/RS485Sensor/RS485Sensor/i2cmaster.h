#ifdef _I2CMASTER_H_
#define _I2CMASTER_H

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef cbi
#define cbi(port, bit)    (port) &= ~(1<<(bit)) 
#endif
#ifndef sbi
#define sbi(port, bit)    (port) |=  (1<<(bit))
#endif
/* For Master Use */
//--Rate at 8MHz of CPU_Clock
// #define SET_222KHZ     10h
// #define SET_100KHZ     20h
//--Command of TWCR
#define TWI_WRITE    0
#define TWI_READ     1
#define TWI_START    (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)   //0xA4
#define TWI_STOP     (1<<TWINT)|(1<<TWSTO)|(1<<TWEN)   //0x94
#define TWI_Clear_TWINT    (1<<TWINT)|(1<<TWEN)        //0x84
#define TWI_Read_ACK       (1<<TWINT)|(1<<TWEA)|(1<<TWEN)    //0xC4
//--Code For TWI Master Transmitter
#define _START_Sent     0x08    // Starrt Condition has been sent successful
#define _R_START_Sent   0x10    // RÊPAT START Condition has been sent successful
#define _SLA_W_ACK      0x18    // SLA adress, W has been sent, received ACK
#define _SLA_W_NACK     0x20    // SLA address, W has been sent, received NOT ACK
#define _DATA_ACK       0x28    // DATA has been sent, ACK has been received
#define _DATA_NACK      0x30    // DATA has been sent, NOT ACK has been received
//--Code For TWI Master Receiver
#define _SLA_R_ACK      0x40    // SLA address, READ bit has been sent, ACK has been transmitted
#define _SLA_R_NACK     0x48    // SLA address, READ bit has been sent, NOT ACK has been transmitted
#define _DATA_Rec_ACK   0x50    // DATA has been received, ACK hass been received
#define _DATA_Rec_NACK  0x58    // DATA has been received, NOT ACK hass been received

void TWI_Init(void);
unsigned char TWI_Master_Send_Array(unsigned char Addr, unsigned char data[], unsigned char leng);
  

#endif