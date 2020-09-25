/*
 * twi.c
 *
 * Created: 1/7/2012 23:06:28
 *  Author: embedds.com
*/
#ifndef F_CPU
#define F_CPU 11059200
#endif
#include "twi.h"
#include <util/delay.h>
#include "uart.h"

void TWIInit(unsigned long int vruli_freq)
{
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = (unsigned char)(((F_CPU/vruli_freq)-16)/8);
	//enable TWI
	TWCR = (1<<TWEN);
}
//send start signal
void TWIStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
//send stop signal
void TWIStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
//read byte with ACK
uint8_t TWIReadACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
//read byte with NACK
uint8_t TWIReadNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
uint8_t TWIGetStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}