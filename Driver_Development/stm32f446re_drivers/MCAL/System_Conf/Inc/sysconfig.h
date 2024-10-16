/*
 * sysconfig.h
 *
 *  Created on: Jun 22, 2024
 *      Author: Chait
 */

#ifndef SYSTEM_CONF_INC_SYSCONFIG_H_
#define SYSTEM_CONF_INC_SYSCONFIG_H_

#include "stm32f446re_rcc.h"

#define SYSCONF_BASE_ADDR		0x40013800UL

typedef struct{
	volatile uint32_t SYSCFG_MEMRMP;
	volatile uint32_t SYSCFG_PMC;
	volatile uint32_t SYSCFG_EXTICR[4];
	volatile uint32_t RESERVED1[2];
	volatile uint32_t SYSCFG_CMPCR;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t SYSCFG_CFGR;
}Sysconf_Reg_Def;

#define SYSCONFIG				((Sysconf_Reg_Def*)SYSCONF_BASE_ADDR)
#define SYSCONFIG_CLK_EN()		((RCC->RCC_APB2ENR) |= (1<<14))

#endif /* SYSTEM_CONF_INC_SYSCONFIG_H_ */
