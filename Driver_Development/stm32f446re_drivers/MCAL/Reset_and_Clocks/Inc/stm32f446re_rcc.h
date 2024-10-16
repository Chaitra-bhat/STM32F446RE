/*
 * stm32f446re_rcc.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Chait
 */

#ifndef STM32F446RE_RCC_H_
#define STM32F446RE_RCC_H_

#define RCC_BASE_ADDR			0x40023800UL

typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t RESERVED10;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_RESERVED0;
	volatile uint32_t RCC_RESERVED1;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t RCC_RESERVED2;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_RESERVED3;
	volatile uint32_t RCC_RESERVED4;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t RCC_RESERVED5;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t RCC_RESERVED6;
	volatile uint32_t RCC_RESERVED7;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RCC_RESERVED8;
	volatile uint32_t RCC_RESERVED9;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t DCKCFGR2;
}RCC_RegDef_t;

#define RCC		((RCC_RegDef_t*)RCC_BASE_ADDR)


#endif /* STM32F446RE_RCC_H_ */
