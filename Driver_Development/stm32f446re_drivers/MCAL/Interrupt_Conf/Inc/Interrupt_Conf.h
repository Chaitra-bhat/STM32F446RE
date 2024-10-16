/*
 * Interrupt_Conf.h
 *
 *  Created on: Jun 22, 2024
 *      Author: Chait
 */

#ifndef INTERRUPT_CONF_INC_INTERRUPT_CONF_H_
#define INTERRUPT_CONF_INC_INTERRUPT_CONF_H_

#define EXTI_BASE_ADDR		0x40013C00UL

typedef struct{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
}EXTI_Reg_Def;

#define EXTI 			((EXTI_Reg_Def*)EXTI_BASE_ADDR)

#define IRQ_PRIO_EXTI0			6
#define IRQ_PRIO_EXTI1			7
#define IRQ_PRIO_EXTI2			8
#define IRQ_PRIO_EXTI3			9
#define IRQ_PRIO_EXTI4			10
#define IRQ_PRIO_EXTI5_9		23
#define IRQ_PRIO_EXTI110_15		40

#define ISER0					 ((volatile uint32_t*)0xE000E100UL)
#define ISER1					 ((volatile uint32_t*)0xE000E104UL)
#define ISER2					 ((volatile uint32_t*)0xE000E108UL)
#define ISER3					 ((volatile uint32_t*)0xE000E10CUL)
#define ISER4					 ((volatile uint32_t*)0xE000E110UL)
#define ISER5					 ((volatile uint32_t*)0xE000E114UL)
#define ISER6					 ((volatile uint32_t*)0xE000E118UL)
#define ISER7					 ((volatile uint32_t*)0xE000E11CUL)

#define ICER0					 ((volatile uint32_t*)0xE000E180UL)
#define ICER1					 ((volatile uint32_t*)0xE000E184UL)
#define ICER2					 ((volatile uint32_t*)0xE000E188UL)
#define ICER3					 ((volatile uint32_t*)0xE000E18CUL)
#define ICER4					 ((volatile uint32_t*)0xE000E190UL)
#define ICER5					 ((volatile uint32_t*)0xE000E194UL)
#define ICER6					 ((volatile uint32_t*)0xE000E198UL)
#define ICER7					 ((volatile uint32_t*)0xE000E19CUL)

#define NVIC_IPR_BASE_ADDR		 ((volatile uint32_t*)0xE000E400)


#endif /* INTERRUPT_CONF_INC_INTERRUPT_CONF_H_ */
