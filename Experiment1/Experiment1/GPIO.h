/* GPIO_Output_Init(),
GPIO_Output_Set() and GPIO_Output_Clear()
*/

#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>

#define F_CPU 16000000UL
#define OSC_DIV (1)
#define PA ((volatile GPIO_t *)(0x20))   //(&PINA)
#define PB ((volatile GPIO_t *)(0x23))   //(&PINB)
#define PC ((volatile GPIO_t *)(0x26))   //(&PINC)
#define PD ((volatile GPIO_t *)(0x29))   //(&PIND)
#define PE ((volatile GPIO_t *)(0x2C))   //(&PINE)

typedef struct GPIO
{
	volatile uint8_t GPIO_PIN;
	volatile uint8_t GPIO_DDR;
	volatile uint8_t GPIO_PORT;
}GPIO_t;

void GPIO_Output_Init(volatile GPIO_t *Port_addr, uint8_t pin_mask);
void GPIO_Output_Set(volatile GPIO_t *Port_addr, uint8_t pin_mask);
void GPIO_Output_Clear(volatile GPIO_t *Port_addr, uint8_t pin_mask);

#endif