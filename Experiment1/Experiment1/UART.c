#include "UART.h"

uint16_t UBRR_value;

void UART_Init (volatile UART_t * UART_addr, uint32_t Baud_Rate)
{
	
	UBRR_value = (uint16_t)(((F_CPU/OSC_DIV)/(8UL*(2-U2X_VAL)*(uint32_t)Baud_Rate))-1); //(uint16_t)((((F_CPU/OSC_DIV)+(4UL*(2-U2X)*Baud_Rate))/(8UL*(2-U2X)*Baud_Rate))-1);
	UART_addr->UART_UBRRH = UBRR_value/256;  // Calculates upper 8 bits
	UART_addr->UART_UBRRL = UBRR_value%256;    // Calculates lower 8 bits
	UART_addr->UART_UCSRA &= ~(1<<U2X); //Setting the U2X bit in USCRA
	UART_addr->UART_UCSRC =(Async_Mode|No_Parity|One_Stop_Bit|E8_Bit_Data);
	UART_addr->UART_UCSRB |= ((1<<RXEN)|(1<<TXEN)); //Rx & Tx enabled
	UART_addr->UART_UCSRB &= ~(1<<UDRIE); //Interrupts (UDRIE) disabled
}

uint8_t UART_Transmit(UART_t volatile *UART_addr, uint8_t send_value)
{
	uint8_t status;
	do
	{
		// Read the status bits in UCSRA
		status = UART_addr->UART_UCSRA;
		// AND to isolate only UDRE, repeat while UDRE==0
	
	} while ((status & (1 << UDRE))!=(1 << UDRE));
	
	// Place the send_value into the USART data register
	UART_addr->UART_UDR = send_value;
	// Return some value
	return 0;
}

uint8_t UART_Receive(volatile UART_t *UART_addr)
{
	uint8_t received_value;
	uint8_t status;
	do
	{
		// Read the status bits in UCSRA
		status = UART_addr->UART_UCSRA;
		// AND to isolate only RXC, repeat while RXC==0
	
	} while ((status & (1 << RXC))!=(1 << RXC));
	
	// Read the received value from the USART Data Register (UDR).
	received_value = UART_addr->UART_UDR;
	// Return some value
	return received_value;
}