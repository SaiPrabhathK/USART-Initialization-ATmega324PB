/*
 * UART_Print.h
 *
 * Created: 9/4/2020 4:36:37 PM
 *  Author: youngerr
 */ 


#ifndef UART_PRINT_H_
#define UART_PRINT_H_

char * Export_print_buffer(void);
uint8_t Copy_String_to_Buffer(const char flash_string[], uint8_t num_bytes, char buffer_p[]);
void UART_Transmit_String(volatile uint8_t * UART_addr, uint8_t num_bytes,char string_name[]);



#endif /* UART_PRINT_H_ */