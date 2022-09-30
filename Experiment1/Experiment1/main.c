/*
 * Experiment_1.c
 *
 * Created: 9/28/2022 7:26:45 PM
 * Author : spk6f2
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "GPIO.h" // has #define F_CPU (16000000UL) needed for delay.h
#include "LEDS.h"   // defines wrapper functions to control LEDs
#include "UART.h"
#include <util/delay.h>  // defines _delay_ms() function

int main (void)
{
	// Initialization Area
	UART_Init(UART1, 9600);
	//UART_Init(UART0, 9600);
	/*LEDS_Init(LED0_port,LED0_pin);
	_delay_ms(1000);
	LEDS_Init(LED1_port,LED1_pin);
	_delay_ms(1000);
	LEDS_Init(LED2_port,LED2_pin);
	_delay_ms(1000);
	LEDS_Init(LED3_port,LED3_pin);
	_delay_ms(1000);8*/
	while (1)
	{
		UART_Transmit(UART1, 'U');
		UART_Transmit(UART1, UART_Receive(UART1));
		//UART_Transmit(UART0, 'U');
		/*LEDS_On(LED0_port,LED0_pin);
		_delay_ms(1000);
		LEDS_On(LED1_port,LED1_pin);
		_delay_ms(1000);
		LEDS_On(LED2_port,LED2_pin);
		_delay_ms(1000);
		LEDS_On(LED3_port,LED3_pin);
		_delay_ms(1000);
		LEDS_Off(LED0_port,LED0_pin);
		_delay_ms(1000);
		LEDS_Off(LED1_port,LED1_pin);
		_delay_ms(1000);
		LEDS_Off(LED2_port,LED2_pin);
		_delay_ms(1000);
		LEDS_Off(LED3_port,LED3_pin);
		_delay_ms(1000);*/
	}
	
}
