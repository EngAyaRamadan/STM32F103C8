/*
 *################################  DMA_interface.h  ######################
 *   Author : Aya Ramadan
 * 	 Date   : 28 November 2024
 *   Version: 1
 *   SWC    : DMA
*/

#ifndef DMA_interface_H
#define DMA_interface_H

/*DMA Channels*/
#define DMA_CHANNEL1    0
#define DMA_CHANNEL2    1
#define DMA_CHANNEL3    2
#define DMA_CHANNEL4    3
#define DMA_CHANNEL5    4
#define DMA_CHANNEL6    5
#define DMA_CHANNEL7    6

/*Channels' priorities*/
#define DMA_PRI_LOW         0
#define DMA_PRI_MED         1
#define DMA_PRI_HIGH        2
#define DMA_PRI_VERY_HIGH   3

/*Channel data transfer type*/
#define DMA_PER_TO_MEM  0
#define DMA_MEM_TO_PER  1
#define DMA_MEM_TO_MEM  2

/*Channel data size*/
#define DMA_DS_1BYTE    0
#define DMA_DS_2BYTES   1
#define DMA_DS_4BYTES   2

/*Channel enable/disable auto increment*/
#define DMA_DIS_AUTOINC 0
#define DMA_EN_AUTOINC  1

/* DMA Mode--->Circular or Not (single transfer) */
#define DMA_DIS_CIRCULAR  0
#define DMA_EN_CIRCULAR   1

//Interrupt Enable
#define DMA_TCIE  1
#define DMA_HTIE  2
#define DMA_TEIE  3

//DMA Flags
#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3

/**************************************** typedefs ****************************************/

/*DMA Configuration structure*/
typedef struct
{
	u8 channelNumber;
	u8 channelPriority;
	u8 DirectionTransferType;
	u8 MemoryDataSize;
	u8 prephiralDataSize;
	u8 MemoryIncrementMode;
	u8 prephiralIncrementMode;
	u8 DMAMode;
}DMA_configStruct_t;

/**************************************** Functions' prototypes ****************************************/

/*This function is used to initialize a specific DMA channel*/
u8 DMA_u8DMAChannelInit(DMA_configStruct_t* Copy_pstructDMAChannelConfig);

u8 DMA_voidDMAEnable( DMA_configStruct_t* Copy_pstructDMAChannelConfig );

u8 DMA_voidDMADisable( DMA_configStruct_t* Copy_pstructDMAChannelConfig );

u8 DMA_voidClearFlag( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8Flag );

u8 DMA_u8GetFlag( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8Flag , u8* Copy_u8result );

u8 DMA_voidInerruptEnable( DMA_configStruct_t* Copy_pstructDMAChannelConfig , u8 Copy_u8INTSource );

/*This function is used to transfer data by DMA from source to destination (by interrupt)*/
u8 DMA_u8DMAChannelTransfer(u8 Copy_u8ChannelNumber, u32* Copy_u32SrcAddress, u32* Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers);

/*This function is used to transfer data by DMA from source to destination (by polling)*/
u8 DMA_u8DMAChannelTransfer_busyWait(u8 Copy_u8ChannelNumber, u32* Copy_u32SrcAddress, u32* Copy_u32DesAddress, u16 Copy_u16NumberOfTransfers);

/*This function is used to set the call back function of a DMA channel*/
u8 DMA_u8DMASetCallBack(u8 Copy_u8ChannelNumber, void (*pf) (void) );


#endif
