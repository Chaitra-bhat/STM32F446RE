/*
 * button_press.c
 *
 *  Created on: Jun 21, 2024
 *      Author: Chait
 */
#include "button_press.h"


void Button_Press_5ms()
{
	GPIO_Handle_t GPIOALed, GPIOCBtn;

	/*Pin Configuration for LED configuration*/
	GPIOALed.pGPIOx = GPIOA;
	GPIOALed.GPIOPinConfig.PinNumber = GPIO_PINNUMBER_5;
	GPIOALed.GPIOPinConfig.PinMode = GPIO_MODE_OUTPUT;
	GPIOALed.GPIOPinConfig.PinOPType = GPIO_OTYPE_PUPL;
	GPIOALed.GPIOPinConfig.PinSpeed = GPIO_OSPEED_MEDIUM;
	GPIOALed.GPIOPinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClkEnable(GPIOA, ENABLE);

	GPIO_Init(&GPIOALed);

	/* Pin configuration for button configuration*/
	GPIOCBtn.pGPIOx = GPIOC;
	GPIOCBtn.GPIOPinConfig.PinNumber = GPIO_PINNUMBER_13;
	GPIOCBtn.GPIOPinConfig.PinMode = GPIO_MODE_INPUT;
	GPIOCBtn.GPIOPinConfig.PinSpeed = GPIO_OSPEED_MEDIUM;
	GPIOCBtn.GPIOPinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClkEnable(GPIOC, ENABLE);

	GPIO_Init(&GPIOCBtn);


	while(1)
	{
		if(GPIO_ReadPin(GPIOC, GPIO_PINNUMBER_13) == PRESSED )
		{
		delay();
		GPIO_TogglePin(GPIOA, GPIO_PINNUMBER_5);
		delay();
		}
	}
}
