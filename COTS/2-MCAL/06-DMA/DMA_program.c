/*
 *################################  DMA_program.c ######################
 *   Author : Aya Ramadan
 * 	 Date   : 28 November 2024
 *   Version: 1
 *   SWC    : DMA
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f103xx.h"

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"


typedef void (*fptr_t)(void);
fptr_t Global_pfArr[7] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};


u8 DMA_u8DMAChannelInit(DMA_configStruct_t* Copy_pstructDMAChannelConfig)
{
	u8 Local_errorState = STD_TYPES_OK;
	  /* mask CCR Register */
      DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR = 0;

      /* Direction of teransfer */
	if( (Copy_pstructDMAChannelConfig -> DirectionTransferType) == DMA_MEM_TO_MEM)
	   {
		 SET_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 14);
	   }
	else if( (Copy_pstructDMAChannelConfig -> DirectionTransferType) == DMA_MEM_TO_PER)
	   {
		 SET_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 4);
	   }
    else if( (Copy_pstructDMAChannelConfig -> DirectionTransferType) == DMA_PER_TO_MEM)
	   {
		 CLR_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 4);
	   }
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	   /*Periority channal */
	if( Copy_pstructDMAChannelConfig -> channelPriority == DMA_PRI_LOW )
	   {
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 12 );
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 13 );
       }
	else if( Copy_pstructDMAChannelConfig -> channelPriority == DMA_PRI_MED )
	   {
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 12 );
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 13 );
       }
	else if( Copy_pstructDMAChannelConfig -> channelPriority == DMA_PRI_HIGH )
	   {
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 12 );
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 13 );
	   }
	else if( Copy_pstructDMAChannelConfig -> channelPriority == DMA_PRI_VERY_HIGH )
	   {
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 12 );
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 13 );
	   }
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	 /*memory size */
	if( Copy_pstructDMAChannelConfig ->MemoryDataSize == DMA_DS_1BYTE ){

		CLR_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 10 );
		CLR_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 11 );

	}else if( Copy_pstructDMAChannelConfig ->MemoryDataSize == DMA_DS_2BYTES  ){

		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 10 );
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 11 );

	}else if ( Copy_pstructDMAChannelConfig ->MemoryDataSize == DMA_DS_4BYTES ){

		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 10 );
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 11 );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	/* prephiral size */
	if( Copy_pstructDMAChannelConfig ->prephiralDataSize == DMA_DS_1BYTE ){

		CLR_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 8 );
		CLR_BIT(DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 9 );

	}else if( Copy_pstructDMAChannelConfig ->prephiralDataSize == DMA_DS_2BYTES  ){

		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 8 );
		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 9 );

	}else if ( Copy_pstructDMAChannelConfig ->prephiralDataSize == DMA_DS_4BYTES ){

		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 8 );
		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 9 );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	 /*memory auto increment*/
	if( Copy_pstructDMAChannelConfig ->MemoryIncrementMode == DMA_EN_AUTOINC ){

		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 7  );

	}else if (  Copy_pstructDMAChannelConfig ->MemoryIncrementMode == DMA_DIS_AUTOINC ){

		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 7  );

	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	 /*prephiral auto increment*/
	if( Copy_pstructDMAChannelConfig ->prephiralIncrementMode == DMA_EN_AUTOINC ){

		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 6  );

	}else if (  Copy_pstructDMAChannelConfig ->prephiralIncrementMode == DMA_DIS_AUTOINC ){

		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 6  );

	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}

	/* DMA Mode*/
	if( Copy_pstructDMAChannelConfig ->DMAMode == DMA_EN_CIRCULAR ){

		SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 5  );

	}else if( Copy_pstructDMAChannelConfig ->DMAMode == DMA_DIS_CIRCULAR ){

		CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 5  );

	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}

	return Local_errorState;
}

u8 DMA_voidDMAEnable( DMA_configStruct_t* Copy_pstructDMAChannelConfig )
{
	u8 Local_errorState = STD_TYPES_OK;
	if(Copy_pstructDMAChannelConfig -> channelNumber <= DMA_CHANNEL7)
	{
	  /*clear all flags*/
	  SET_BIT( DMA->IFCR , ((Copy_pstructDMAChannelConfig -> channelNumber*4) + DMA_GIF) );

	  SET_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , 0  );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	return Local_errorState;
}

u8 DMA_voidDMADisable( DMA_configStruct_t* Copy_pstructDMAChannelConfig )
{
	u8 Local_errorState = STD_TYPES_OK;
	if(Copy_pstructDMAChannelConfig -> channelNumber <= DMA_CHANNEL7)
	{
	  CLR_BIT( DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR, 0  );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	return Local_errorState;
}

u8 DMA_voidClearFlag( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8Flag )
{
		u8 Local_errorState = STD_TYPES_OK;
	if(Copy_pstructDMAChannelConfig -> channelNumber <= DMA_CHANNEL7 && (Copy_u8Flag== DMA_GIF || Copy_u8Flag== DMA_TCIF || Copy_u8Flag== DMA_HTIF || Copy_u8Flag== DMA_TEIF ))
	{
	 SET_BIT( DMA->IFCR , ((Copy_pstructDMAChannelConfig -> channelNumber*4) + Copy_u8Flag) );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	return Local_errorState;
}

u8   DMA_u8GetFlag( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8Flag , u8* Copy_u8result )
{
	u8 Local_errorState = STD_TYPES_OK;
	if(Copy_pstructDMAChannelConfig -> channelNumber <= DMA_CHANNEL7 && (Copy_u8Flag== DMA_GIF || Copy_u8Flag== DMA_TCIF || Copy_u8Flag== DMA_HTIF || Copy_u8Flag== DMA_TEIF ))
	{
	 *Copy_u8result=GET_BIT( DMA->ISR , ((Copy_pstructDMAChannelConfig -> channelNumber*4) + Copy_u8Flag) );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	return Local_errorState;


}

u8 DMA_voidInerruptEnable( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8INTSource )
{
	u8 Local_errorState = STD_TYPES_OK;
	if(Copy_pstructDMAChannelConfig -> channelNumber <= DMA_CHANNEL7 && (Copy_u8INTSource== DMA_TEIE || Copy_u8INTSource== DMA_HTIE || Copy_u8INTSource== DMA_TCIE  ))
	{
	 SET_BIT(  DMA->CHANNEL[ Copy_pstructDMAChannelConfig -> channelNumber ].CCR , Copy_u8INTSource );
	}
	else{
		Local_errorState = STD_TYPES_NOK;
	}
	return Local_errorState;

}



u8 DMA_u8DMAChannelTransfer(u8 Copy_u8ChannelNumber, u32* Copy_u32SrcAddress, u32* Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
	u8 Local_errorState = STD_TYPES_NOK;
	/*Setting the number of transfers*/
	DMA->CHANNEL[Copy_u8ChannelNumber ].CNDTR = Copy_u16NumberOfTransfers;

	/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber ].CCR, 14))
			{
				DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR =  Copy_u32SrcAddress;
				DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR =  Copy_u32DesAddress;
				Local_errorState = STD_TYPES_OK;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber ].CCR, 4))
				{
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR = Copy_u32SrcAddress;
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR = Copy_u32DesAddress;
				}
				else
				{
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR = Copy_u32SrcAddress;
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR = Copy_u32DesAddress;
				}
				Local_errorState = STD_TYPES_OK;
			}

	return Local_errorState;
}

u8 DMA_u8DMAChannelTransfer_busyWait(u8 Copy_u8ChannelNumber, u32 *Copy_u32SrcAddress, u32 *Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers)
{
		u8 Local_errorState = STD_TYPES_NOK;
	/*Setting the number of transfers*/
	DMA->CHANNEL[Copy_u8ChannelNumber ].CNDTR = Copy_u16NumberOfTransfers;

	/*Checking if the memory to memory option is available*/
			if(GET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber ].CCR, 14))
			{
				DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR =  Copy_u32SrcAddress;
				DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR =  Copy_u32DesAddress;
				Local_errorState = STD_TYPES_OK;
			}
			else
			{
				/*Checking if the memory to peripheral option is available*/
				if(GET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber ].CCR, 4))
				{
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR = Copy_u32SrcAddress;
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR = Copy_u32DesAddress;
				}
				else
				{
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CPAR = Copy_u32SrcAddress;
					DMA->CHANNEL[ Copy_u8ChannelNumber ].CMAR = Copy_u32DesAddress;
				}
				Local_errorState = STD_TYPES_OK;
			}

	/*Polling over TC flag*/
	while(! (GET_BIT(DMA-> ISR, (1 + ( 4*Copy_u8ChannelNumber ) ) ) ) );

	/*Clearing the TC flag*/
	SET_BIT(DMA-> IFCR, (1 + (4*(Copy_u8ChannelNumber - 1))) );

	return Local_errorState;
}

u8 DMA_u8DMASetCallBack(u8 Copy_u8ChannelNumber, void (*pf) (void))
{
	u8 Local_errorState = STD_TYPES_OK;

	Global_pfArr[Copy_u8ChannelNumber] = pf;

	return Local_errorState;
}

/**************************************** Handlers ****************************************/

void DMA1_Channel1_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA -> IFCR, 1);

	if(Global_pfArr[0] != NULL)
	{
		Global_pfArr[0]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA->IFCR, 5);

	if(Global_pfArr[1] != NULL)
	{
		Global_pfArr[1]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA-> IFCR, 9);

	if(Global_pfArr[2] != NULL)
	{
		Global_pfArr[2]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA->IFCR, 13);

	if(Global_pfArr[3] != NULL)
	{
		Global_pfArr[3]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel5_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA->IFCR, 17);

	if(Global_pfArr[4] != NULL)
	{
		Global_pfArr[4]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel6_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA->IFCR, 21);

	if(Global_pfArr[5] != NULL)
	{
		Global_pfArr[5]();
	}
	else
	{
		/*Do nothing*/
	}
}

void DMA1_Channel7_IRQHandler(void)
{
	/*Clearing the TC flag*/
	SET_BIT(DMA->IFCR, 25);

	if(Global_pfArr[6] != NULL)
	{
		Global_pfArr[6]();
	}
	else
	{
		/*Do nothing*/
	}
}
