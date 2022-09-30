#ifndef LEDS_H
#define LEDS_H

#include <stdio.h>
#include "GPIO.h"

// Assuming OLED board connected to EXT4
//LED) on PC7
#define LED0_port PC
#define LED0_pin (1<<7)

//LED1 on PB3
#define LED1_port PB
#define LED1_pin (1<<3)

//LED2 on PE4
#define LED2_port PE
#define LED2_pin (1<<4)

//LED3 on PA7
#define LED3_port PA
#define LED3_pin (1<<7)

void LEDS_Init(volatile GPIO_t * Port_addr, uint8_t LED_pin);
void LEDS_Off(volatile GPIO_t * Port_addr, uint8_t LED_pin);
void LEDS_On(volatile GPIO_t * Port_addr, uint8_t LED_pin);

#endif