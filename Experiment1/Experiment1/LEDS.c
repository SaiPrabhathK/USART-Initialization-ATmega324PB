#include "LEDS.h"
#include "GPIO.h"

void LEDS_Init(volatile GPIO_t * Port_addr, uint8_t LED_pin)
{
	(Port_addr->GPIO_PORT) |= LED_pin;
	GPIO_Output_Init(Port_addr,LED_pin);
}

void LEDS_On(volatile GPIO_t * Port_addr, uint8_t LED_pin)
{
	GPIO_Output_Clear(Port_addr,LED_pin);
}

void LEDS_Off(volatile GPIO_t * Port_addr, uint8_t LED_pin)
{
	GPIO_Output_Set(Port_addr,LED_pin);
}
