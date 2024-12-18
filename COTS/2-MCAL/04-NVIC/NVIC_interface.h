/*
 *################################  NVIC_interface.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 21 November 2024
 *   Version: 1
 *   SWC    : NVIC
*/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*This function is used to enable specific interrupt*/
u8 NVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber);

/*This function is used to disable specific interrupt*/
u8 NVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber);

/*This function is used to set a pending interrupt*/
u8 NVIC_u8SetInterruptPending(u8 Copy_u8InterruptNumber);

/*This function is used to set a pending interrupt*/
u8 NVIC_u8ClearInterruptPending(u8 Copy_u8InterruptNumber);

/*This function is used to get the current active interrupts*/
u8 NVIC_u8InterruptIsActive(u8 Copy_u8InterruptNumber, u8* Copy_pu8InterruptStatus);

/*This function is used to change the current interrupt group priority*/
u8 NVIC_u8SetGroupPriority(u8 Copy_u8InterruptNumber, u8 Copy_u8GroupPriority);


#endif