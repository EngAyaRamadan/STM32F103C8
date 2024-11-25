/*
 *################################  EXTI_interface.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 25 November 2024
 *   Version: 1
 *   SWC    : EXTI
*/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI_MASKED        0
#define EXTI_NOT_MASKED    1

#define EXTI_RISING_EDGE           1
#define EXTI_FALLING_EDGE          2
#define EXTI_RISING_FALLING_EDGE   3

#define EXTI_LINE_0        0
#define EXTI_LINE_1        1
#define EXTI_LINE_2        2
#define EXTI_LINE_3        3
#define EXTI_LINE_4        4
#define EXTI_LINE5_9       5
#define EXTI_LINE10_15     6


/*This function is used to set a specific EXTI status [Masked - Not masked]*/
u8 EXTI_u8SetInterruptStatus(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIStatus);

/*This function is used to set a specific EXTI edge [Rising - Falling - Rising and falling]*/
u8 EXTI_u8SetInterruptEdge(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIEdge);

/*This function is used to clear a specific EXTI pending status*/
u8 EXTI_u8ClearInterruptPending(u8 Copy_u8EXTINumber);

/*This function is used to get a specific EXTI pending status*/
u8 EXTI_u8IsInterruptActive(u8 Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus);

/*This function is used to set a specific EXTI Callback function*/
u8 EXTI_u8SetInterruptCallback(u8 Copy_u8EXTINumber, void (*Copy_pfCallback)(void));

#endif