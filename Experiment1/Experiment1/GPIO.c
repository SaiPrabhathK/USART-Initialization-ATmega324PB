#include "GPIO.h"

void GPIO_Output_Init(volatile GPIO_t *Port_addr, uint8_t pin_mask)
{
	(Port_addr->GPIO_DDR) |= pin_mask;	
}

void GPIO_Output_Set(volatile GPIO_t *Port_addr, uint8_t pin_mask)
{
	(Port_addr->GPIO_PORT) |= pin_mask;
}

void GPIO_Output_Clear(volatile GPIO_t *Port_addr, uint8_t pin_mask)
{
	(Port_addr->GPIO_PORT) &= !pin_mask;
}