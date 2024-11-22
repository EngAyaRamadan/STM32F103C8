/*
 *################################  STK_interface.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 28 October 2024
 *   Version: 1
 *   SWC    : STK
*/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidInit              (void);

/* Synch function */
u8   STK_u8SetBusyWait         (u32 Copy_u32NumOfTicks);
/* Async functions */
u8   STK_u8SetIntervalSingle   (u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));

u8   STK_u8SetIntervalPeriodic (u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));

void STK_voidStopTimer         (void);
/*function to know the number of tick that timer count */
u8   STK_u8GetElapsedTime      (u32 * Copy_pu32ElapsedTime);
/*function to know the number of tick that timer need to count to arrive (zero) */
u8   STK_u8GetRemainingTime    (u32 * Copy_pu32RemainingTime);

#endif