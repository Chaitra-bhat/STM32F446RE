/*
 * stm32f446re_gpio.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Chait
 */

#include "stm32f446re_gpio.h"
#include "../../Memory_Drivers/Inc/stm32f446re_memory.h"
#include "interrupt_conf.h"
#include "sysconfig.h"

/*
 * Description: This function shall Initialize all the registers of the given GPIO port
 * Name: GPIO_Init
 * Parameter a: Base address and Pin details - Handle input
 * Parameter b: None
 * Return Type: Void
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {
	/* Configure the mode*/
	if(pGPIOHandle->GPIOPinConfig.PinMode <= GPIO_MODE_ANALOG)
	{
		pGPIOHandle->pGPIOx->GPIOx_MODER &= ~(0x3 << pGPIOHandle->GPIOPinConfig.PinNumber);
		pGPIOHandle->pGPIOx->GPIOx_MODER |= (pGPIOHandle->GPIOPinConfig.PinMode << (2*pGPIOHandle->GPIOPinConfig.PinNumber));
	}
	else
	{
		if(pGPIOHandle->GPIOPinConfig.PinMode == GPIO_MODE_IT_FE)
		{
			//configure FTSR register
			EXTI->EXTI_FTSR |= (1<<pGPIOHandle->GPIOPinConfig.PinNumber);

			//Clear RTSR bit
			EXTI->EXTI_RTSR &= ~(1<<pGPIOHandle->GPIOPinConfig.PinNumber);

		}
		else if(pGPIOHandle->GPIOPinConfig.PinMode == GPIO_MODE_IT_RE)
		{
			//Configure RSTR register
			EXTI->EXTI_RTSR |= (1<<pGPIOHandle->GPIOPinConfig.PinNumber);

			EXTI->EXTI_FTSR &= ~(1<<pGPIOHandle->GPIOPinConfig.PinNumber);
		}
		else if(pGPIOHandle->GPIOPinConfig.PinMode == GPIO_MODE_IT_RE_FE)
		{
			// Configure FTSR and RSTR register

			EXTI->EXTI_RTSR |= (1<<pGPIOHandle->GPIOPinConfig.PinNumber);

			EXTI->EXTI_FTSR |= (1<<pGPIOHandle->GPIOPinConfig.PinNumber);
		}

		uint8_t temp1 = (pGPIOHandle->GPIOPinConfig.PinNumber)/4;
		uint8_t temp2 = (pGPIOHandle->GPIOPinConfig.PinNumber)%4;
		uint8_t portcode = GPIO_BASEADRR_TO_CODE(pGPIOHandle->pGPIOx);

		SYSCONFIG->SYSCFG_EXTICR[temp1] |= portcode<<(temp2*4);

		SYSCONFIG_CLK_EN();
		EXTI->EXTI_IMR |= (1<<pGPIOHandle->GPIOPinConfig.PinNumber);
	}

	/*Configure the speed*/
	pGPIOHandle->pGPIOx->GPIOx_OSPEEDR &= ~(0x3 << pGPIOHandle->GPIOPinConfig.PinNumber);
	pGPIOHandle->pGPIOx->GPIOx_OSPEEDR |= (pGPIOHandle->GPIOPinConfig.PinSpeed << (2*pGPIOHandle->GPIOPinConfig.PinNumber));

	/*Configure Pull up or Pull down*/
	pGPIOHandle->pGPIOx->GPIOx_PUPDR &= ~(0x3 << pGPIOHandle->GPIOPinConfig.PinNumber);
	pGPIOHandle->pGPIOx->GPIOx_PUPDR |= (pGPIOHandle->GPIOPinConfig.PinPuPdControl << (2*pGPIOHandle->GPIOPinConfig.PinNumber));

	/*Configure output type*/
	pGPIOHandle->pGPIOx->GPIOx_OTYPER &= ~(1 << pGPIOHandle->GPIOPinConfig.PinNumber);
	pGPIOHandle->pGPIOx->GPIOx_OTYPER |= (pGPIOHandle->GPIOPinConfig.PinOPType << pGPIOHandle->GPIOPinConfig.PinNumber);

	/*Configure for altfunc mode*/
	if(pGPIOHandle->GPIOPinConfig.PinAltFunMode == GPIO_MODE_ALTFUN)
	{
		uint32_t temp1;
		temp1 = (pGPIOHandle->GPIOPinConfig.PinNumber % 8);
		if(pGPIOHandle->GPIOPinConfig.PinNumber <= GPIO_PINNUMBER_7)
		{
			pGPIOHandle->pGPIOx->GPIOx_AFRL &= ~(0xF << pGPIOHandle->GPIOPinConfig.PinNumber);
			pGPIOHandle->pGPIOx->GPIOx_AFRL |= (pGPIOHandle->GPIOPinConfig.PinAltFunMode << 4*temp1);
		}
		else if((pGPIOHandle->GPIOPinConfig.PinNumber) > GPIO_PINNUMBER_7 && (pGPIOHandle->GPIOPinConfig.PinNumber)<= GPIO_PINNUMBER_15)
		{
			pGPIOHandle->pGPIOx->GPIOx_AFRH &= ~(0xF << pGPIOHandle->GPIOPinConfig.PinNumber);
			pGPIOHandle->pGPIOx->GPIOx_AFRH |= (pGPIOHandle->GPIOPinConfig.PinAltFunMode << 4*temp1);
		}
		else
		{
			/*Do Nothing*/
		}

	}

}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {
	if (pGPIOx == GPIOA) {
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOB) {
		GPIOB_REG_RESET();
	} else if (pGPIOx == GPIOC) {
		GPIOC_REG_RESET();
	} else if (pGPIOx == GPIOD) {
		GPIOD_REG_RESET();
	} else if (pGPIOx == GPIOE) {
		GPIOE_REG_RESET();
	} else if (pGPIOx == GPIOF) {
		GPIOF_REG_RESET();
	} else if (pGPIOx == GPIOG) {
		GPIOG_REG_RESET();
	} else if (pGPIOx == GPIOH) {
		GPIOH_REG_RESET();
	} else {
		printf("Invalid Port\n");
	}

}

/*
 * Description: This function shall enable the clock for a particular GPIO peripheral
 * Name: GPIO_PeriClkEnable
 * Parameter a: Base address of the GPIO Port Eg: GPIOA
 * Parameter b: Input to whether enable or disable
 * Parameter c: None
 * Return Type: Void
 */
void GPIO_PeriClkEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi) {
	if (EnOrDi == ENABLE) {
		if (pGPIOx == GPIOA) {
			GPIOA_CLK_ENABLE();
		} else if (pGPIOx == GPIOB) {
			GPIOB_CLK_ENABLE();
		} else if (pGPIOx == GPIOC) {
			GPIOC_CLK_ENABLE();
		} else if (pGPIOx == GPIOD) {
			GPIOD_CLK_ENABLE();
		} else if (pGPIOx == GPIOE) {
			GPIOE_CLK_ENABLE();
		} else if (pGPIOx == GPIOF) {
			GPIOF_CLK_ENABLE();
		} else if (pGPIOx == GPIOG) {
			GPIOG_CLK_ENABLE();
		} else if (pGPIOx == GPIOH) {
			GPIOH_CLK_ENABLE();
		} else {
			printf("Invalid Port\n");
		}
	} else if (EnOrDi == DISABLE) {
		if (pGPIOx == GPIOA) {
			GPIOA_CLK_DISABLE();
		} else if (pGPIOx == GPIOB) {
			GPIOB_CLK_DISABLE();
		} else if (pGPIOx == GPIOC) {
			GPIOC_CLK_DISABLE();
		} else if (pGPIOx == GPIOD) {
			GPIOD_CLK_DISABLE();
		} else if (pGPIOx == GPIOE) {
			GPIOE_CLK_DISABLE();
		} else if (pGPIOx == GPIOF) {
			GPIOF_CLK_DISABLE();
		} else if (pGPIOx == GPIOG) {
			GPIOG_CLK_DISABLE();
		} else if (pGPIOx == GPIOH) {
			GPIOH_CLK_DISABLE();
		} else {
			printf("Invalid Port\n");
		}
	} else {
		printf("Invalid Input\n");
	}
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	uint8_t value;
	value = (uint8_t)((pGPIOx->GPIOx_IDR >> PinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx) {
	uint16_t value;
	value = (uint16_t)(pGPIOx->GPIOx_IDR);
	return value;
}

void GPIO_WriteTOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t Value) {
	if(Value == SET)
	{
		pGPIOx->GPIOx_ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->GPIOx_ODR &= ~(1 << PinNumber);
	}

}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value) {

		pGPIOx->GPIOx_ODR = Value;
}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	pGPIOx->GPIOx_ODR ^= (1<<PinNumber);
}

void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t EnOrDi) {

	if(EnOrDi == ENABLE)
	{
		if(IRQ_Number <=31)
		{
			//Configure ISER0
			*ISER0 |= (1<< IRQ_Number);
		}
		else if(IRQ_Number >31 && IRQ_Number <64)
		{
			//Configure ISER1
			*ISER1 |= (1 << (IRQ_Number%32));
		}
		else if(IRQ_Number >= 64 && IRQ_Number < 96)
		{
			//Configure ISER2
			*ISER2 |= (1 << (IRQ_Number%64));
		}
	}
	else
	{
		if(IRQ_Number <=31)
		{
			//Configure ICER0
			*ICER0 |= (1<<IRQ_Number);
		}
		else if(IRQ_Number >31 && IRQ_Number <64)
		{
			//Configure ICER1
			*ICER1 |= (1 << (IRQ_Number%32));
		}
		else if(IRQ_Number >= 64 && IRQ_Number < 96)
		{
			//Configure ICER2
			*ICER2 |= (1<<(IRQ_Number%64));
		}
	}
}

void GPIO_IRQHandling(uint8_t PinNumber) {

	if(EXTI->EXTI_PR & (1<< PinNumber))
	{
		//Clear the bit
		EXTI->EXTI_PR |= (1<<PinNumber);
	}
}


void GPIO_IRQPriority_Config(uint8_t IRQ_Number,uint32_t Priority)
{
	//First the IPR register
	uint8_t iprx = IRQ_Number/4;
	uint8_t iprx_section = IRQ_Number%4;
	uint8_t shift_amt = (8*iprx_section) + (8 - NO_OF_PR_BITS_IMPLEMENTED);
	*(NVIC_IPR_BASE_ADDR + (iprx*4)) |= (Priority << shift_amt);
}


void delay()
{
	for(int i=0; i<500000/2;i++);
}
