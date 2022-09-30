#include <stdio.h>
#include "GPIO.h"

#define Async_Mode (0<<6)
#define Sync_Mode (1<<6)
#define No_Parity (0<<4)
#define Even_Parity (2<<4)
#define One_Stop_Bit (0<<3)
#define Two_Stop_Bits (1<<3)
#define E8_Bit_Data ((1<<1)|(1<<2))

#define U2X_VAL (0)
#define U2X (1)
#define RXEN (4)
#define TXEN (3)
#define UDRE (5)
#define UDRIE (5)
#define RXC (7)

typedef struct UART
{
	volatile uint8_t UART_UCSRA;
	volatile uint8_t UART_UCSRB;
	volatile uint8_t UART_UCSRC;
	volatile uint8_t UART_UCSRD;
	volatile uint8_t UART_UBRRL;
	volatile uint8_t UART_UBRRH;
	volatile uint8_t UART_UDR;
} UART_t;

#define UART0 ((volatile UART_t *)(0xC0))   // or (&UCSRA0)
#define UART1 ((volatile UART_t *)(0xC8))   // or (&UCSRA1)
#define UART2 ((volatile UART_t *)(0xD0))   // or (&UCSRA2)

void UART_Init (volatile UART_t *UART_addr, uint32_t Baud_Rate);
uint8_t UART_Transmit(volatile UART_t *UART_addr, uint8_t send_value);
uint8_t UART_Receive(volatile UART_t *UART_addr);