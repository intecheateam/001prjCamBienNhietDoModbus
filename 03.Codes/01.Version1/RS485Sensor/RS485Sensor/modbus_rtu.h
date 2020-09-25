/*
 * modbus_rtu.h
 *
 * Created: 10/26/2019 3:19:41 PM
 *  Author: 
 */ 


#ifndef MODBUS_RTU_H_
#define MODBUS_RTU_H_
#define ERROR_NOT_SUPPORTED_FOR_COMMAND          1
#define ERROR_START_ADDRESS                      2
#define ERROR_NUMBER_OF_DATA                     3
#define ERROR__UNKNOWN_COMMAND                   4


void          ModbusRTU_SendFrame(unsigned char *buff, unsigned char len);
void          ModbusRTU_ErrorHandling(unsigned char addr, unsigned char st_error);
unsigned int  ModRTU_CRC(unsigned char *buff, int len);
unsigned int  ModRTU_CheckCRC(unsigned char *buff, int len);
void          ModbusRTU_FrameHandling(unsigned char addr, unsigned char *buff, unsigned char len, unsigned int temp, unsigned int hum);


#endif /* MODBUS_RTU_H_ */