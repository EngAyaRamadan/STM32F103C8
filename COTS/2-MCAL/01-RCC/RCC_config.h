/*
 *################################  RCC_config.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 6 October 2024
 *   Version: 1
 *   SWC    : RCC
*/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*******************************************************************/
/*                                                                 */
/*                     $ ClockType Maybe :                         */
/*                                                                 */
/*                       1-RCC_u8_HSI                                     */
/*                       2-RCC_u8_HSE                                     */
/*                       3-RCC_u8_PLL                                     */
/*                          *PLL_Source                            */
/*                               3.1-RCC_u8_PLL_HSI_DIVIDED_BY_2          */
/*                               3.2-RCC_u8_PLL_HSE                       */
/*                               3.3-RCC_u8_PLL_HSE_DIVIDED_BY_2          */
/*                       4-RCC_u8_HSE_BYPASS                              */
/*                                                                 */
/*******************************************************************/
      
#define RCC_u8_CLK_SYS       RCC_u8_HSI
#define PLL_SOURCE       PLL_HSE_DIVIDED_BY_2

/**********************************************************************/
/*                                                                    */
/*                 Clock Security System May be                       */                                               */
/* 				      1-RCC_u8_DISABLE_CLOCK_SECURITY_SYSTEM          */
/*                    2-RCC_u8_ENABLE_CLOCK_SECURITY_SYSTEM           */                  
/* 				                                                      */
/**********************************************************************/
#define RCC_u8CLOCK_SECURITY_SYSTEM    RCC_u8_DISABLE_CLOCK_SECURITY_SYSTEM


#endif