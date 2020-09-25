/*
 * SHT31.h
 *
 * Created: 12/9/2019 4:16:32 AM
 *  Author: ADMIN
 */ 


#ifndef SHT31_H_
#define SHT31_H_

#define SHT31_ADDR_WRITE      0x8A
#define SHT31_ADDR_READ       0x8B
#define SHT31_SOFT_RESET      0x30A2
#define SHT31_ENABLECLOCK_HI  0x2C06
#define SHT31_ENABLECLOCK_ME  0x2C0D
#define SHT31_ENABLECLOCK_LO  0x2C10
#define SHT31_DISABLECLOCK_HI 0x2400
#define SHT31_DISABLECLOCK_ME 0x240B
#define SHT31_DISABLECLOCK_LO 0x2416



#include "twi.h"

void SHT31_Init(unsigned long int vruli_freq);
void SHT31_Soft_Reset(void);
void SHT31_SingleShot_Mode(float *vrf_temp, float *vrf_hum);


#endif /* SHT31_H_ */