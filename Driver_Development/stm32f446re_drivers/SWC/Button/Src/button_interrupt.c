/*
 * button_interrupt.c
 *
 *  Created on: Jun 23, 2024
 *      Author: Chait
 */


#include "button_press.h"
#include "interrupt_conf.h"

void ButtonInterrupt_5ms()
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
	GPIOCBtn.GPIOPinConfig.PinMode = GPIO_MODE_IT_RE;
	GPIOCBtn.GPIOPinConfig.PinSpeed = GPIO_OSPEED_MEDIUM;
	GPIOCBtn.GPIOPinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GPIO_PeriClkEnable(GPIOC, ENABLE);

	GPIO_Init(&GPIOCBtn);

	GPIO_IRQPriority_Config(IRQ_PRIO_EXTI110_15, 15);
	GPIO_IRQConfig(IRQ_PRIO_EXTI110_15, ENABLE);

	while(1);


}


void EXTI15_10_IRQHandler()
{
	GPIO_IRQHandling(GPIO_PINNUMBER_13);
	GPIO_TogglePin(GPIOC, GPIO_PINNUMBER_13);
}
