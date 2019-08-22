/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            CAN example
*
********************************************************************************
* \copyright
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
* CYPRESS PROVIDES THIS SOFTWARE "AS IS" AND MAKES NO WARRANTY
* OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS SOFTWARE,
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
* PURPOSE.
*******************************************************************************/

#include "pdl_header.h"
#include "string.h"

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define CAN_MAX_RX_TEST_MESSAGES 2

/******************************************************************************/
/* Global variable definitions ('static')                                     */
/******************************************************************************/
static uint8_t u8StatusCounter = 0;
static uint8_t u8ErrorCounter = 0;
volatile static uint8_t u8TransmitCounter = 0;
volatile static uint8_t u8ReceiveCounter = 0;
volatile static boolean_t bReceiveFlag = 0;
static uint32_t u32MsgIdMask1;
volatile static en_can_status_t aenStatus[CAN_MAX_RX_TEST_MESSAGES];
static stc_can_config_t   stcCanConfig;
static stc_can_msg_data_t stcMsgData;
static stc_can_msg_id_t   stcMsgId;
static stc_can_msg_t      stcMsgBuffer1;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/******************************************************************************
 ** \brief Can Transmission Complete Callback
 ******************************************************************************/
static void CanTxCompleteCb(uint8_t u8MsgBuf)
{
  u8TransmitCounter++;
}

/******************************************************************************
 ** \brief Can Reception Callback
 ******************************************************************************/
static void CanRxReceivedCb(uint8_t u8MsgBuf, stc_can_msg_t* pstcRxMsg)
{
  u8ReceiveCounter++;
  bReceiveFlag = 1u;
}

/******************************************************************************
 ** \brief Can Status Callback
 ******************************************************************************/
static void CanStatusCb(en_can_status_t enCanStatus)
{
  aenStatus[u8StatusCounter] = enCanStatus;  /* Collect CAN status callback data */

  u8StatusCounter++;
}

/******************************************************************************
 ** \brief Can Error Callback
 ******************************************************************************/
static void CanErrorCb(en_can_error_t enCanError)
{
  u8ErrorCounter++;
}

/**
 ******************************************************************************
 ** \brief CAN0 example
 **
 ** This test requires a configured and connected CAN-USB tool.
 **
 ** After Can_Init() to 100k Bit/s. The echo test is implemented. And
 ** if CAN-USB tool send the data frame with ID = 0x0A, the data will be echo
 ** back. Otherwise, the data frame is filtered.
 **
 ******************************************************************************/
int main(void)
{
    stc_cann_t*         pstcCan        = NULL; /* CAN instance pointer */
    stc_can_msg_id_t*   pstcMsgId      = NULL; /* Message ID pointer */
    stc_can_msg_data_t* pstcMsgData    = NULL; /* Message Data pointer */
    stc_can_msg_t*      pstcMsgBuffer1 = NULL; /* Message Buffer 1 pointer */
   
    SetPinFunc_RX0_2(0u);         /* CAN reception pin */
    SetPinFunc_TX0_2(0u);         /* CAN transmission pin */
    
    /* Set CAN instance */ 
    pstcCan = (stc_cann_t*)(&CAN0);
    
    /* Set Message ID pointer */
    pstcMsgId = &stcMsgId;
    
    /* Set Message Data pointer */
    pstcMsgData = &stcMsgData;
    
    /* Set Message Buffer 1 pointer */
    pstcMsgBuffer1 = &stcMsgBuffer1;
    
    stcCanConfig.pfnStatusCallback = (can_status_chg_func_ptr_t)CanStatusCb;
    stcCanConfig.pfnErrorCallback = (can_error_func_ptr_t)CanErrorCb;
    stcCanConfig.bDisableAutomaticRetransmission = FALSE;
    
    /* 100k Bit/s */
    /* Fsys / (TSEG1 + TSEG2 + 1) */
    /* (40M / (13 + 6 + 1)*20) */
    stcCanConfig.bTouchPrescaler = TRUE;
    stcCanConfig.stcBitrate.u8TimeSegment1  = 13;
    stcCanConfig.stcBitrate.u8TimeSegment2  = 6;
    stcCanConfig.stcBitrate.u8SyncJumpWidth = 4;
    stcCanConfig.stcBitrate.u16Prescaler = 16;
    stcCanConfig.stcBitrate.enCanPrescaler = CanPreDiv15; /* 200 MHz / 5 = 40 MHz */

    /* RX buffer 1 settings (CAN auto-response) */
    stcMsgBuffer1.stcIdentifier.u32Identifier = 0x0A;
    stcMsgBuffer1.stcIdentifier.bExtended = FALSE;
    u32MsgIdMask1 = 0xFFFFFFFF; /* Compare all the IDE bits */
    
    if (Ok == Can_Init(pstcCan, &stcCanConfig))
    {
        u8TransmitCounter = 0;
        u8ReceiveCounter = 0;
    
        while(1)
        {
            /* Set message buffer 2 to receive buffer */
            Can_SetReceiveMsgBuffer(pstcCan, 2, pstcMsgBuffer1, u32MsgIdMask1, (can_rx_msg_func_ptr_t)CanRxReceivedCb);

            /* Wait for receive finish */
            while(1u != bReceiveFlag);
            bReceiveFlag = 0u;

            /* TX buffer settings */
            stcMsgId.u32Identifier = 0x12 ;
            stcMsgId.bExtended = FALSE ;
            
            /* Prepare for transfer */
            Can_SetTransmitMsgBuffer(pstcCan, 1, pstcMsgId, (can_tx_msg_func_ptr_t)CanTxCompleteCb);
            
            /* Send back the data received */
            pstcMsgData->u8DataLengthCode = 8u;
            memcpy(pstcMsgData->au8Data, &pstcMsgBuffer1->stcData, pstcMsgData->u8DataLengthCode);
            
            Can_UpdateAndTransmitMsgBuffer(pstcCan, 1, pstcMsgData, CanImmediateTransmit);
        }
    }
    else
    {
    	while(1)
    	{
    	}
    }
}


/* [] END OF FILE */
