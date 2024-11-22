/*
 *################################  RCC_private.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 6 October 2024
 *   Version: 1
 *   SWC    : RCC
*/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*Clock Type*/
#define RCC_u8_HSI                         1
#define RCC_u8_HSE                         2
#define RCC_u8_PLL                         3
#define RCC_u8_PLL_HSI_DIVIDED_BY_2        4
#define RCC_u8_PLL_HSE                     5
#define RCC_u8_PLL_HSE_DIVIDED_BY_2        6
#define RCC_u8_HSE_BYPASS                  7

/**********************************************************************/
/*                                                                    */
/*                 Clock Security System May be                       */
/*                 1-Enable:                                          */
/* 				   To Set HSI By H.W When There are Failure In HSE    */
/* 				   To Set HSI By H.W When Leaving Stop Or Standby     */
/* 				   2-Disable                                          */
/* 				   The Previouse To Feature Doesnot Happen            */
/*                                                                    */
/**********************************************************************/
#define RCC_u8_DISABLE_CLOCK_SECURITY_SYSTEM              0
#define RCC_u8_ENABLE_CLOCK_SECURITY_SYSTEM               1



#endif