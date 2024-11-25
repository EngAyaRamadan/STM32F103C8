/*
 *################################  RCC_program.c  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 6 October 2024
 *   Version: 1
 *   SWC    : RCC
 */
/*LIB Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"

/* MCAL */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

u8 RCC_u8InitSysClk(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Enable The Clk to be selected */
#if  (RCC_u8_CLK_SYS  == RCC_u8_HSI)
	SET_BIT(RCC->CR,0);
    CLR_BIT(RCC->CFGR , 1);
    CLR_BIT(RCC->CFGR , 0);
#elif (RCC_u8_CLK_SYS == RCC_u8_HSE)
	SET_BIT(RCC->CR,16);
	CLR_BIT(RCC->CFGR,1); SET_BIT(RCC->CFGR,0);
#elif (RCC_u8_CLK_SYS == RCC_u8_HSE_BYPASS)
	SET_BIT(RCC->CR,18);
	CLR_BIT(RCC->CFGR,1); SET_BIT(RCC->CFGR,0);
#elif (RCC_u8_CLK_SYS  == RCC_u8_PLL)
	SET_BIT(RCC->CR,24);
	SET_BIT(RCC->CFGR,1); CLR_BIT(RCC->CFGR,0);
#else
#error  "Wrong Choice"
#endif

#if(RCC_u8CLOCK_SECURITY_SYSTEM == RCC_u8_DISABLE_CLOCK_SECURITY_SYSTEM)
	RCC->CR=0x00080000;
#elif(RCC_u8CLOCK_SECURITY_SYSTEM == RCC_u8_ENABLE_CLOCK_SECURITY_SYSTEM)
	RCC->CR=0x00080000;
#endif

	return Local_u8ErrorState;
}


u8 RCC_u8EnablePreipheralClk (u8 copy_u8BusId,u8 Copy_u8PrepheralId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if( Copy_u8PrepheralId <32)
	{
		switch(copy_u8BusId)
		{
		case RCC_U8_AHP_BUS : SET_BIT(RCC->AHBENR,Copy_u8PrepheralId); break;
		case RCC_U8_APB1_BUS: SET_BIT(RCC->APB1ENR,Copy_u8PrepheralId); break;
		case RCC_U8_APB2_BUS: SET_BIT(RCC->APB2ENR,Copy_u8PrepheralId); break;
		default: Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 RCC_u8DisablePreipheralClk (u8 copy_u8BusId,u8 Copy_u8PrepheralId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if( Copy_u8PrepheralId <32)
	{
		switch(copy_u8BusId)
		{
		case RCC_U8_AHP_BUS : CLR_BIT(RCC->AHBENR,Copy_u8PrepheralId); break;
		case RCC_U8_APB1_BUS: CLR_BIT(RCC->APB1ENR,Copy_u8PrepheralId); break;
		case RCC_U8_APB2_BUS: CLR_BIT(RCC->APB2ENR,Copy_u8PrepheralId); break;
		default: Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}
