/*
 *################################  RCC_interface.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 6 October 2024
 *   Version: 1
 *   SWC    : RCC
*/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Macros for Buses*/
#define RCC_U8_AHP_BUS         1
#define RCC_U8_APB1_BUS        2
#define RCC_U8_APB2_BUS        3


/* AHB Bus Peripheral*/
#define    RCC_U8_DMA1         0
#define    RCC_U8_DMA2         1
#define    RCC_U8_SRAM         2
#define    RCC_U8_FLITF        4
#define    RCC_U8_CRC          6
#define    RCC_U8_FSMC         8
#define    RCC_U8_SDIO         10

/* APB1 Bus Peripheral*/
#define    RCC_U8_TIM2         0
#define    RCC_U8_TIM3         1
#define    RCC_U8_TIM4         2
#define    RCC_U8_TIM5         3
#define    RCC_U8_TIM6         4
#define    RCC_U8_TIM7         5
#define    RCC_U8_TIM12        6
#define    RCC_U8_TIM13        7
#define    RCC_U8_TIM14        8
#define    RCC_U8_WWDG         11
#define    RCC_U8_SPI2         14
#define    RCC_U8_SPI3         15
#define    RCC_U8_USART2       17
#define    RCC_U8_USART3       18
#define    RCC_U8_UART4        19
#define    RCC_U8_UART5        20
#define    RCC_U8_I2C1         21
#define    RCC_U8_I2C2         22
#define    RCC_U8_USB          23
#define    RCC_U8_CAN          25
#define    RCC_U8_BKP          27
#define    RCC_U8_PWR          28
#define    RCC_U8_DAC          29

/* APB2 Bus Peripheral*/
#define    RCC_U8_AFIO         0
#define    RCC_U8_GPIOA        2
#define    RCC_U8_GPIOB        3
#define    RCC_U8_GPIOC        4
#define    RCC_U8_GPIOD        5
#define    RCC_U8_GPIOE        6
#define    RCC_U8_GPIOF        7
#define    RCC_U8_GPIOG        8
#define    RCC_U8_ADC1         9
#define    RCC_U8_ADC2         10
#define    RCC_U8_TIM1         11
#define    RCC_U8_SPI1         12
#define    RCC_U8_TIM8         13
#define    RCC_U8_USART1       14
#define    RCC_U8_ADC3         15
#define    RCC_U8_TIM9         19
#define    RCC_U8_TIM10        20
#define    RCC_U8_TIM11        21


u8 RCC_u8InitSysClk(void);
u8 RCC_u8EnablePreipheralClk (u8 copy_u8BusId,u8 Copy_u8PrepheralId);
u8 RCC_u8DisablePreipheralClk (u8 copy_u8BusId,u8 Copy_u8PrepheralId);


#endif