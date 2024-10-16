/*
 * stm32f446re_gpio.h
 *
 *  Created on: Jun 17, 2024
 *      Author: Chait
 */

#ifndef INC_STM32F446RE_GPIO_H_
#define INC_STM32F446RE_GPIO_H_

#include <stdio.h>
#include <stdint.h>

#include <stm32f446re_StdTypes.h>
#include "../../Reset_and_Clocks/Inc/stm32f446re_rcc.h"

#define GPIOA_BASE_ADDR			0x40020000UL
#define GPIOB_BASE_ADDR			0x40020400UL
#define GPIOC_BASE_ADDR			0x40020800UL
#define GPIOD_BASE_ADDR			0x40020C00UL
#define GPIOE_BASE_ADDR			0x40021000UL
#define GPIOF_BASE_ADDR			0x40021400UL
#define GPIOG_BASE_ADDR			0x40021800UL
#define GPIOH_BASE_ADDR			0x40021C00UL

/*APB1 peripherals*/
#define CRC_BASE_ADDR			0x40023000UL


/* Structure Registers of GPIO*/
typedef struct {
	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;
} GPIO_RegDef_t;

#define GPIOA		(GPIO_RegDef_t*)GPIOA_BASE_ADDR
#define GPIOB		(GPIO_RegDef_t*)GPIOB_BASE_ADDR
#define GPIOC		(GPIO_RegDef_t*)GPIOC_BASE_ADDR
#define GPIOD		(GPIO_RegDef_t*)GPIOD_BASE_ADDR
#define GPIOE		(GPIO_RegDef_t*)GPIOE_BASE_ADDR
#define GPIOF		(GPIO_RegDef_t*)GPIOF_BASE_ADDR
#define GPIOG		(GPIO_RegDef_t*)GPIOG_BASE_ADDR
#define GPIOH		(GPIO_RegDef_t*)GPIOH_BASE_ADDR


#define GPIOA_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<0))
#define GPIOB_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<1))
#define GPIOC_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<2))
#define GPIOD_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<3))
#define GPIOE_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<4))
#define GPIOF_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<5))
#define GPIOG_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<6))
#define GPIOH_CLK_ENABLE()		((RCC->RCC_AHB1ENR)|= (1<<7))

#define GPIOA_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<0))
#define GPIOB_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<1))
#define GPIOC_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<2))
#define GPIOD_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<3))
#define GPIOE_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<4))
#define GPIOF_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<5))
#define GPIOG_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<6))
#define GPIOH_CLK_DISABLE()		((RCC->RCC_AHB1ENR) &= ~(1<<7))

#define GPIOA_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<0) ;(RCC->RCC_AHB1RSTR) &= ~(1<<0);}while(0)
#define GPIOB_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<1) ;(RCC->RCC_AHB1RSTR) &= ~(1<<1);}while(0)
#define GPIOC_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<2) ;(RCC->RCC_AHB1RSTR) &= ~(1<<2);}while(0)
#define GPIOD_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<3) ;(RCC->RCC_AHB1RSTR) &= ~(1<<3);}while(0)
#define GPIOE_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<4) ;(RCC->RCC_AHB1RSTR) &= ~(1<<4);}while(0)
#define GPIOF_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<5) ;(RCC->RCC_AHB1RSTR) &= ~(1<<5);}while(0)
#define GPIOG_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<6) ;(RCC->RCC_AHB1RSTR) &= ~(1<<6);}while(0)
#define GPIOH_REG_RESET()		do{(RCC->RCC_AHB1RSTR) |= (1<<7) ;(RCC->RCC_AHB1RSTR) &= ~(1<<7);}while(0)

typedef struct {
	uint8_t PinNumber;
	uint8_t PinMode;
	uint8_t PinSpeed;
	uint8_t PinPuPdControl;
	uint8_t PinOPType;
	uint8_t PinAltFunMode;

} GPIO_PinConfig_t;

typedef struct {
	GPIO_RegDef_t *pGPIOx; // Base address of any GPIO port
	GPIO_PinConfig_t GPIOPinConfig;
} GPIO_Handle_t;

#define GPIO_MODE_INPUT		0U
#define GPIO_MODE_OUTPUT	1U
#define GPIO_MODE_ALTFUN	2U
#define GPIO_MODE_ANALOG	3U
#define GPIO_MODE_IT_FE		4U
#define GPIO_MODE_IT_RE		5U
#define GPIO_MODE_IT_RE_FE	6U

#define GPIO_OTYPE_PUPL		0U
#define GPIO_OTYPE_OD		1U

#define GPIO_OSPEED_LOW		0U
#define GPIO_OSPEED_MEDIUM	1U
#define GPIO_OSPEED_FAST	2U
#define GPIO_OSPEED_HIGH	3U

#define GPIO_PUPD_NONE		0U
#define GPIO_PUPD_PULLUP	1U
#define GPIO_PUPD_PULLDOWN	2U

#define GPIO_PINNUMBER_0	0U
#define GPIO_PINNUMBER_1	1U
#define GPIO_PINNUMBER_2	2U
#define GPIO_PINNUMBER_3	3U
#define GPIO_PINNUMBER_4	4U
#define GPIO_PINNUMBER_5	5U
#define GPIO_PINNUMBER_6	6U
#define GPIO_PINNUMBER_7	7U
#define GPIO_PINNUMBER_8	8U
#define GPIO_PINNUMBER_9	9U
#define GPIO_PINNUMBER_10	10U
#define GPIO_PINNUMBER_11	11U
#define GPIO_PINNUMBER_12	12U
#define GPIO_PINNUMBER_13	13U
#define GPIO_PINNUMBER_14	14U
#define GPIO_PINNUMBER_15	15U

#define GPIO_BASEADRR_TO_CODE(x)	((x == GPIOA) ? 0: \
								 (x == GPIOB) ? 1: \
								 (x == GPIOC) ? 2: \
								 (x == GPIOD) ? 3: \
								 (x == GPIOE) ? 4: \
								 (x == GPIOF) ? 5: \
								 (x == GPIOG) ? 6: \
								 (x == GPIOH) ? 7: 0)


#define NO_OF_PR_BITS_IMPLEMENTED		4

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
void GPIO_PeriClkEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteTOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t EnOrDi);
void GPIO_IRQHandling(uint8_t PinNumber);
void GPIO_IRQPriority_Config(uint8_t IRQ_Number,uint32_t Priority);

void delay(void);
#endif /* INC_STM32F446RE_GPIO_H_ */
