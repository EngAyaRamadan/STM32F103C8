/*
 *################################  stm32f103xx.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 6 October 2024
 *   Version: 1
 *   SWC    : stm32f103xx
*/

#ifndef  STM32F103xx_H_
#define  STM32F103xx_H_

/********************** RCC Registers ********************/
#define RCC_u32_BASE_ADDRESS    0x40021000

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
	
}RCC_RegDef_t;

#define  RCC    ((RCC_RegDef_t*)RCC_u32_BASE_ADDRESS)
/********************************************************/
/******************************** GPIO Registers **************************************/
#define GPIO_u32_GPIOA_BASE_ADDRESS                       0x40010800U
#define GPIO_u32_GPIOB_BASE_ADDRESS                       0x40010C00U
#define GPIO_u32_GPIOC_BASE_ADDRESS                       0x40011000U 

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA                          ((GPIO_RegDef_t*)GPIO_u32_GPIOA_BASE_ADDRESS)
#define GPIOB                          ((GPIO_RegDef_t*)GPIO_u32_GPIOB_BASE_ADDRESS)
#define GPIOC                          ((GPIO_RegDef_t*)GPIO_u32_GPIOC_BASE_ADDRESS)


/**************************************************************************************/

/******************************** SYSTICK Registers ***********************************/

#define STK_u32_BASE_ADDRESS                                0xE000E010U

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_RegDef_t;

#define STK                                  ((STK_RegDef_t*)STK_u32_BASE_ADDRESS)

/**************************************************************************************/
/******************************** NVIC Registers ***********************************/

#define NVIC_u32_BASE_ADDRESS                                0xE000E100U

typedef struct
{
	volatile u32 ISER[32];
	volatile u32 ICER[32];
	volatile u32 ISPR[32];
	volatile u32 ICPR[32];
	volatile u32 IABR[64];
	volatile u32 IPR[9];
}NVIC_RegDef_t;

#define NVIC                                  ((NVIC_RegDef_t*)NVIC_u32_BASE_ADDRESS)
#define SCB_AIRCR                             (*(volatile u32*)(0xE000ED0C))

/**************************************************************************************/
/******************************** EXTI Registers ***********************************/

#define EXTI_u32_BASE_ADDRESS                                0x40010400U

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_RegDef_t;

#define EXTI                                  ((EXTI_RegDef_t*)EXTI_u32_BASE_ADDRESS)

/**************************************************************************************/
#endif
