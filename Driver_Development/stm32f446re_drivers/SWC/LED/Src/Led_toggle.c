/*
 * Led_toggle.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Chait
 */


#include "stm32f446re_gpio.h"

#if(PROJECT_LED == 1)

void LED_Blinky_5ms()
{
	GPIO_Handle_t GPIOALed;

	/*Pin Configuration for LED configuration*/
	GPIOALed.pGPIOx = GPIOA;
	GPIOALed.GPIOPinConfig.PinNumber = GPIO_PINNUMBER_5;
	GPIOALed.GPIOPinConfig.PinMode = GPIO_MODE_OUTPUT;
	GPIOALed.GPIOPinConfig.PinOPType = GPIO_OTYPE_PUPL;
	GPIOALed.GPIOPinConfig.PinSpeed = GPIO_OSPEED_MEDIUM;
	GPIOALed.GPIOPinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClkEnable(GPIOA, ENABLE);

	GPIO_Init(&GPIOALed);

	while(1)
	{
		GPIO_TogglePin(GPIOA, GPIO_PINNUMBER_5);
		delay();
	}
}

#endif
