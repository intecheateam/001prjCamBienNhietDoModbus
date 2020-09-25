/*
 * SHT31.c
 *
 * Created: 12/9/2019 4:16:52 AM
 *  Author: ADMIN
 */ 
#ifndef F_CPU
#define F_CPU 11059200UL
#endif

#include "twi.h"
#include "SHT31.h"
#include "Function_Define.h"
#include "SFR_Macro.h"
#include <util/delay.h>

void SHT31_Init(unsigned long int vruli_freq) {
	TWIInit(vruli_freq);
}
void SHT31_Soft_Reset(void){
	TWIStart();
	TWIWrite(SHT31_ADDR_WRITE);
	TWIWrite(HIBYTE(SHT31_SOFT_RESET));
	TWIWrite(LOBYTE(SHT31_SOFT_RESET));
	TWIStop();
}
void SHT31_SingleShot_Mode(float *vrf_temp, float *vrf_hum) {
	unsigned char vruc_temp[2], vruc_hum[2], vruc_crc[2];
	unsigned int vrui_tc,vrui_rh;
	TWIStart();
	TWIWrite(SHT31_ADDR_WRITE);
	TWIWrite(HIBYTE(SHT31_ENABLECLOCK_HI));
	TWIWrite(LOBYTE(SHT31_ENABLECLOCK_HI));
	TWIStop();
	_delay_ms(1);
	TWIStart();
	TWIWrite(SHT31_ADDR_READ);
	_delay_ms(10);
	vruc_temp[0] = TWIReadACK();
	vruc_temp[1] = TWIReadACK();
	vruc_crc[0]  = TWIReadACK();
	vruc_hum[0]  = TWIReadACK();
	vruc_hum[1]  = TWIReadACK();
	vruc_crc[1]  = TWIReadNACK();
	TWIStop();
	vrui_tc = MAKEWORD(vruc_temp[0],vruc_temp[1]);
	vrui_rh = MAKEWORD(vruc_hum[0],vruc_hum[1]);
	*vrf_temp =  -45.0+175.0*(vrui_tc/65535.0);
	*vrf_hum  =  100.0*(vrui_rh/65535.0);	
}