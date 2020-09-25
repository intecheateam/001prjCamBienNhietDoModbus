/*
 * modbus_rtu.c
 *
 * Created: 10/26/2019 3:33:16 PM
 *  Author: 
 */ 
#include <avr/io.h>
#include "modbus_rtu.h"
#include "Function_Define.h"
#include "uart.h"

unsigned int ModRTU_CheckCRC(unsigned char *buff, int len) {
	unsigned int crc = 0xFFFF;

	for (int pos = 0; pos < len; pos++) {
		crc ^= (unsigned int) *(buff+pos); // XOR byte into least sig. byte of crc

		for (int i = 8; i != 0; i--) { // Loop over each bit
			if ((crc & 0x0001) != 0) { // If the LSB is set
				crc >>= 1; // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else // Else LSB is not set
			crc >>= 1; // Just shift right
		}
	}
	// Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
	return crc;
}


void         ModbusRTU_ErrorHandling(unsigned char addr, unsigned char st_error) {
	unsigned char buff[10];
	
	switch (st_error) {
		case 1: 
		     buff[0] = addr;
			 buff[1] = 0x81;
			 buff[2] = 0x01;			 
			 buff[3] = LOBYTE(ModRTU_CheckCRC(buff,3));
			 buff[4] = HIBYTE(ModRTU_CheckCRC(buff,3));
			 for (unsigned char i = 0; i <= 4; i++) {
				 UART_TxChar(buff[i]);
			 }
		break;
		case 2:
		     buff[0] = addr;
		     buff[1] = 0x81;
		     buff[2] = 0x02;
			 buff[3] = LOBYTE(ModRTU_CheckCRC(buff,3));
			 buff[4] = HIBYTE(ModRTU_CheckCRC(buff,3));
		     for (unsigned char i = 0; i <= 4; i++) {
			     UART_TxChar(buff[i]);
		     }
		break;
		case 3:
		     buff[0] = addr;
		     buff[1] = 0x84;
		     buff[2] = 0x03;
			 buff[3] = LOBYTE(ModRTU_CheckCRC(buff,3));
			 buff[4] = HIBYTE(ModRTU_CheckCRC(buff,3));			 
		     for (unsigned char i = 0; i <= 4; i++) {
			     UART_TxChar(buff[i]);	
			 }
		break;
		case 4:
		     buff[0] = addr;
		     buff[1] = 0x84;
		     buff[2] = 0x04;
			 buff[3] = LOBYTE(ModRTU_CheckCRC(buff,3));
			 buff[4] = HIBYTE(ModRTU_CheckCRC(buff,3));			 
		     for (unsigned char i = 0; i <= 4; i++) {
			     UART_TxChar(buff[i]);
		     }		
		break;
	}
}

void         ModbusRTU_SendFrame(unsigned char *buff, unsigned char len) {
    unsigned char i,crcl,crch;
	unsigned int crc;
	unsigned char buff1[len];
	for(i=0;i<len;i++) {
	    	buff1[i] = *(buff+i);
	}
	crc = ModRTU_CheckCRC(buff1,len);
	crcl = crc & 0x00FF;
	crch = (crc >> 8) & 0x00FF;
	for (i = 0; i< len;i++) {
		UART_TxChar(buff1[i]);
	}
	UART_TxChar(crcl);
	UART_TxChar(crch);
}

// void ModbusRTU_FrameHandling(unsigned char addr, unsigned char *buff, unsigned char len, unsigned int temp, unsigned int hum) {
// // 	unsigned int crc, start_address,total_data;
// // 	unsigned char templ, temph, huml, humh, buff_send[10];
// 	if (len == 8) {
// /*	     crc = ModRTU_CheckCRC(buff,len-2);*/
// /*	     if (addr == *(buff+0)) { */
// // 	         if (*(buff+len-1) == HIBYTE(crc) && *(buff+len-2) == LOBYTE(crc)) {
// // 	     	    if (*(buff+1) == 4) {
// // 	     			start_address = MAKEWORD(*(buff+2), *(buff+3));
// // 	     			total_data    = MAKEWORD(*(buff+4), *(buff+5));
// // 	     			templ  = LOBYTE(temp);
// // 	     			temph  = HIBYTE(temp);
// // 	     			huml   = LOBYTE(hum);
// // 	     			humh   = HIBYTE(hum);
// 	     			if (start_address == 0) {
// 	     				if (total_data == 0) {
// 	     					buff_send[0] = addr;
// 	     					buff_send[1] = 0x04;
// 	     					buff_send[2] = 0x00;
// 	     					ModbusRTU_SendFrame(buff_send, 3);
// 	     				}
// 	     				else if (total_data == 1) {
// 	     					buff_send[0] = addr;
// 	     					buff_send[1] = 0x04;
// 	     					buff_send[2] = 0x02;	
// 	     					buff_send[3] = temph;
// 	     					buff_send[4] = templ;
// 	     					ModbusRTU_SendFrame(buff_send, 5);											
// 	     				}
// 	     				else if (total_data == 2) {
// 	     					buff_send[0] = addr;
// 	     					buff_send[1] = 0x04;
// 	     					buff_send[2] = 0x04;
// 	     					buff_send[3] = temph;
// 	     					buff_send[4] = templ;
// 	     					buff_send[5] = humh;
// 	     					buff_send[6] = huml;
// 	     					ModbusRTU_SendFrame(buff_send, 7);																		
// 	     				}
// 	     				else {
// 	     					ModbusRTU_ErrorHandling(addr, ERROR_NUMBER_OF_DATA);
// 	     				}
// 	     			}
// 	     			else if (start_address == 1) {
// 	     				if (total_data == 0) {
// 	     				    buff_send[0] = addr;
// 	     				    buff_send[1] = 0x04;
// 	     				    buff_send[2] = 0x00;
// 	     				    ModbusRTU_SendFrame(buff_send, 3);
// 	     				}
// 	     				else if (total_data == 1) {
// 	     					buff_send[0] = addr;
// 	     					buff_send[1] = 0x04;
// 	     					buff_send[2] = 0x02;
// 	     					buff_send[3] = humh;
// 	     					buff_send[4] = huml;
// 	     					ModbusRTU_SendFrame(buff_send, 5);						
// 	     				}
// 	     				else {
// 	     					ModbusRTU_ErrorHandling(addr, ERROR_NUMBER_OF_DATA);
// 	     				}
// 	     			}
// 	     			else {
// 	     				ModbusRTU_ErrorHandling(addr,ERROR_START_ADDRESS);
// 	     			}
// 	     		}
// 	     		else {
// 	     			ModbusRTU_ErrorHandling(addr, ERROR_NOT_SUPPORTED_FOR_COMMAND);
// 	     		}
// 	     	}
// 	     }
// // 	     for (unsigned i = 0; i < len;i++) {
// // 	     	*(buff+i) = '\0';
// // 	     }
// 	}
// 	else {
// 		ModbusRTU_ErrorHandling(addr, ERROR__UNKNOWN_COMMAND);
// 	}
// }

void ModbusRTU_FrameHandling(unsigned char addr, unsigned char *buff, unsigned char len, unsigned int temp, unsigned int hum) {
	unsigned int crc, start_address,total_data;
	unsigned char templ, temph, huml, humh, buff_send[10];
	if (addr == *(buff+0)) { 
	    crc = ModRTU_CheckCRC(buff,len-2);
		if (*(buff+len-1) == HIBYTE(crc) && *(buff+len-2) == LOBYTE(crc)) {
		    if (len == 8) {
				if (*(buff+1) == 4) {
	     		    start_address = MAKEWORD(*(buff+2), *(buff+3));
	     		    total_data    = MAKEWORD(*(buff+4), *(buff+5));
	     		    templ  = LOBYTE(temp);
	     		    temph  = HIBYTE(temp);
	     		    huml   = LOBYTE(hum);
	     		    humh   = HIBYTE(hum);					    
	     		    if (start_address == 0) {
		    	    	if (total_data == 0) {
			 	    		buff_send[0] = addr;
			 	    		buff_send[1] = 0x04;
			 	    		buff_send[2] = 0x00;
			 	    		ModbusRTU_SendFrame(buff_send, 3);
		    	    	}
		    	    	else if (total_data == 1) {
			 	    		buff_send[0] = addr;
			 	    		buff_send[1] = 0x04;
			 	    		buff_send[2] = 0x02;
			 	    		buff_send[3] = temph;
			 	    		buff_send[4] = templ;
			 	    		ModbusRTU_SendFrame(buff_send, 5);
		    	    	}
		    	    	else if (total_data == 2) {
			 	    		buff_send[0] = addr;
			 	    		buff_send[1] = 0x04;
			 	    		buff_send[2] = 0x04;
			 	    		buff_send[3] = temph;
			 	    		buff_send[4] = templ;
			 	    		buff_send[5] = humh;
			 	    		buff_send[6] = huml;
			 	    		ModbusRTU_SendFrame(buff_send, 7);
		    	    	}
		    	    	else {
			 	    		ModbusRTU_ErrorHandling(addr, ERROR_NUMBER_OF_DATA);
		    	    	}
	     		    }
	     		    else if (start_address == 1) {
		    	    	if (total_data == 0) {
			 	    		buff_send[0] = addr;
			 	    		buff_send[1] = 0x04;
			 	    		buff_send[2] = 0x00;
			 	    		ModbusRTU_SendFrame(buff_send, 3);
		    	    	}
		    	    	else if (total_data == 1) {
			 	    		buff_send[0] = addr;
			 	    		buff_send[1] = 0x04;
			 	    		buff_send[2] = 0x02;
			 	    		buff_send[3] = humh;
			 	    		buff_send[4] = huml;
			 	    		ModbusRTU_SendFrame(buff_send, 5);
		    	    	}
		    	    	else {
			 	    		ModbusRTU_ErrorHandling(addr, ERROR_NUMBER_OF_DATA);
		    	    	}
	     		    }
	     		    else {
		    	    	ModbusRTU_ErrorHandling(addr,ERROR_START_ADDRESS);
	     		    }						
				}
				else {
					ModbusRTU_ErrorHandling(addr, ERROR_NOT_SUPPORTED_FOR_COMMAND);
				}
			}
			else {
		        ModbusRTU_ErrorHandling(addr, ERROR__UNKNOWN_COMMAND);					
			}
		}
	}
}