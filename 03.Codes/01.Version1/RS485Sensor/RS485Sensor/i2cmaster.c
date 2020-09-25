#include <avr/io.h>
#include "i2cmaster.h"



void TWI_Init(void) {
	TWSR = 0x00;                          // Prescaler = 1
	TWBR = 0x18;
	TWAR = (2<<1) | 1;
	TWCR = (1<<TWEA)|(1<<TWEN)|(1<<TWIE);   //ACK is set, TWI, Interrupt is ENABLE
}
unsigned char TWI_Master_Send_Array(unsigned char Addr, unsigned char data[], unsigned char leng) {
	cbi(TWCR,TWIE);
	// Sent START Condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & 0x80) == 0x00);             // Check and wait for TWINT bit = 1;
	if ((TWSR & 0xF8) != 0x80) {
		TWI_Init();
		return (TWSR & 0xF8);
	} 
	// Sent Device Address
	
	
	
}