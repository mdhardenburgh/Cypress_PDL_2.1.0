/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates communication between CSIO6 and 
*                   CSIO7 with interrupt mode. 
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

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pdl_header.h"

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define SAMPLE_CSIO_SLAVE_RX_BUFFSIZE   sizeof(au8CsioMasterTxBuf)/sizeof(char)
#define SAMPLE_CSIO_MASTER_TX_BUFFSIZE  SAMPLE_CSIO_SLAVE_RX_BUFFSIZE

#define SAMPLE_CSIO_MASTER_RX_BUFFSIZE  sizeof(au8CsioSlaveTxBuf)/sizeof(char)
#define SAMPLE_CSIO_SLAVE_TX_BUFFSIZE   SAMPLE_CSIO_MASTER_RX_BUFFSIZE 

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_mfs_csio_config_t stcCsio6Config, stcCsio7Config;
stc_csio_irq_cb_t stcCsio6IrqCb, stcCsio7IrqCb;
volatile stc_mfsn_csio_t* CsioCh6 = &CSIO6;
volatile stc_mfsn_csio_t* CsioCh7 = &CSIO7;
uint32_t u32SendCnt = 0, u32ReceiveCnt = 0;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8CsioMasterTxBuf[] = "CSIO master sends data to CSIO Slave";
static uint8_t au8CsioSlaveTxBuf[] = "CSIO master reads data from CSIO Slave";
static uint8_t au8CsioMasterRxBuf[SAMPLE_CSIO_MASTER_RX_BUFFSIZE];
static uint8_t au8CsioSlaveRxBuf[SAMPLE_CSIO_SLAVE_RX_BUFFSIZE];

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/*******************************************************************************
* Function Name: CompareData
********************************************************************************
* Compare each data in the input two buffers
*
* \param pBuf1      First buffer
*
* \param pBuf2      Second buffer
* 
* \param u8Length   Buffer length 
*       
* \return Ok        The data in a buffer1 are the same with that in a buffer2
* \return Error     The data in the buffer1 are not the same with that in the 
*                   buffer2 
*******************************************************************************/
static en_result_t CompareData(uint8_t* pBuf1, uint8_t* pBuf2, uint8_t u8Length)
{
    while(u8Length--)
    {
        if(*pBuf1++ != *pBuf2++)
        {
            return Error;
        }
    }
    
    return Ok;
}

/*******************************************************************************
* Function Name: CsioMasterTxIrqCallback
********************************************************************************
* CSIO master transfer interrupt callback function
*******************************************************************************/
static void CsioMasterTxIrqCallback(void)
{
    if(u32SendCnt == SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh6, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh6, au8CsioMasterTxBuf[u32SendCnt], TRUE);  
    u32SendCnt++;
}

/*******************************************************************************
* Function Name: CsioSlaveRxIrqCallback
********************************************************************************
* CSIO slave receive interrupt callback function
*******************************************************************************/
static void CsioSlaveRxIrqCallback(void)
{
    au8CsioSlaveRxBuf[u32ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh7);
    u32ReceiveCnt++;
    
    if(u32ReceiveCnt == SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh7, CsioRxIrq);
    }
}

/*******************************************************************************
* Function Name: CsioMasterRxIrqCallback
********************************************************************************
* CSIO Master receive interrupt callback function
*******************************************************************************/
static void CsioMasterRxIrqCallback(void)
{
    au8CsioMasterRxBuf[u32ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh6);
    u32ReceiveCnt++;
    
    if(u32ReceiveCnt == SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh6, CsioRxIrq);
        return;
    }
}

/*******************************************************************************
* Function Name: CsioSlaveTxIrqCallback
********************************************************************************
* CSIO slave transfer interrupt callback function
*******************************************************************************/
static void CsioSlaveTxIrqCallback(void)
{
    if(u32SendCnt == SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh7, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh7, au8CsioSlaveTxBuf[u32SendCnt], TRUE);  
    u32SendCnt++;
}

/*******************************************************************************
* Function Name: InitCsio
********************************************************************************
* Initialization of the CSIO
*******************************************************************************/
void InitCsio(void)
{
    /* Clear configuration structure */
    PDL_ZERO_STRUCT(stcCsio6Config);
    PDL_ZERO_STRUCT(stcCsio7Config);
    PDL_ZERO_STRUCT(stcCsio6IrqCb);
    PDL_ZERO_STRUCT(stcCsio7IrqCb);
    
    /* Initialize CSIO interrupt callback functions */
    stcCsio6IrqCb.pfnTxIrqCb = CsioMasterTxIrqCallback;
    stcCsio7IrqCb.pfnRxIrqCb = CsioSlaveRxIrqCallback;
    
    stcCsio6IrqCb.pfnRxIrqCb = CsioMasterRxIrqCallback;
    stcCsio7IrqCb.pfnTxIrqCb = CsioSlaveTxIrqCallback;      
    
    /* Initialize CSIO master  */
    stcCsio6Config.enMsMode = CsioMaster;
    stcCsio6Config.enActMode = CsioActNormalMode;
    stcCsio6Config.bInvertClk = FALSE;
    stcCsio6Config.u32BaudRate = 100000;
    stcCsio6Config.enDataLength = CsioEightBits;
    stcCsio6Config.enBitDirection = CsioDataMsbFirst;
    stcCsio6Config.enSyncWaitTime = CsioSyncWaitZero;
    stcCsio6Config.pstcFifoConfig = NULL;
    stcCsio6Config.pstcIrqCb = &stcCsio6IrqCb;
    stcCsio6Config.pstcIrqEn = NULL;
    stcCsio6Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh6, &stcCsio6Config);
    
    /* Initialize CSIO slave  */
    stcCsio7Config.enMsMode = CsioSlave;
    stcCsio7Config.enActMode = CsioActNormalMode;
    stcCsio7Config.bInvertClk = FALSE;
    stcCsio7Config.u32BaudRate = 100000;
    stcCsio7Config.enDataLength = CsioEightBits;
    stcCsio7Config.enBitDirection = CsioDataMsbFirst;
    stcCsio7Config.pstcFifoConfig = NULL;
    stcCsio7Config.pstcIrqCb = &stcCsio7IrqCb;
    stcCsio7Config.pstcIrqEn = NULL;
    stcCsio7Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh7, &stcCsio7Config);
}

/*******************************************************************************
* Function Name: Csio_MasterSend
********************************************************************************
* The Master sends data to the Slave  
*******************************************************************************/
void Csio_MasterSend(void)
{    
    /* Configure interrupt */
    Mfs_Csio_EnableIrq(CsioCh7, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh6, CsioTxIrq);
    
    /* Enable RX function of CSIO7   */
    Mfs_Csio_EnableFunc(CsioCh7, CsioRx);
    /* Enable TX function of CSIO6   */
    Mfs_Csio_EnableFunc(CsioCh6, CsioTx);
    
    while(u32SendCnt < SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Wait for TX finish */
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxIdle))
    {
        /* Wait for TX bus idle (until last data is sent) */
    }
    
    while(u32ReceiveCnt < SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Wait for RX finish */
    }
}

/*******************************************************************************
* Function Name: Csio_MasterReceive
********************************************************************************
* The Master receives data from the Slave
*******************************************************************************/
void Csio_MasterReceive(void)
{    
    /* Configure interrupt */
    Mfs_Csio_EnableIrq(CsioCh6, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh7, CsioTxIrq);
    
    /* Enable TX function of CSIO7 */
    Mfs_Csio_EnableFunc(CsioCh7, CsioTx);
    
    /* Enable TX and RX function of CSIO6 */
    Mfs_Csio_EnableFunc(CsioCh6, CsioTx);
    Mfs_Csio_EnableFunc(CsioCh6, CsioRx);
 
    /* Send dummy data */
    while(u32SendCnt < SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxEmpty))
        {
            
        }
        Mfs_Csio_SendData(CsioCh6, 0x00u, FALSE);   /* Dummy write */
    }
        
    while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxIdle))
    {
        /* Wait for Master TX bus idle (until last data is sent) */
    }
    
    while(u32ReceiveCnt < SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Wait for receive finish */
    }
}

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project for FM family.
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{    
    /* GPIO initialization */
    SetPinFunc_SIN6_1(); /* Initializatiion of the GPIO used for CSIO6 */
    SetPinFunc_SOT6_1();
    SetPinFunc_SCK6_1();
    
    SetPinFunc_SIN7_1(); /* Initializatiion of the GPIO used for CSIO7 */
    SetPinFunc_SOT7_1();
    SetPinFunc_SCK7_1();
      
    /* Initialize CSIO */
    InitCsio();
    
    u32SendCnt = 0;
    u32ReceiveCnt = 0;
    
    /* Master send data to the slave */
    Csio_MasterSend();
    
    /* Compare receive data with transfer data */
    if(Error == CompareData(au8CsioMasterTxBuf, au8CsioSlaveRxBuf, SAMPLE_CSIO_SLAVE_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }
    
    /* Disable TX function of CSIO6 */
    Mfs_Csio_DisableFunc(CsioCh6, CsioTx);
    /* Disable RX function of CSIO7 */
    Mfs_Csio_DisableFunc(CsioCh7, CsioRx);
    
    
    u32SendCnt = 0;
    u32ReceiveCnt = 0;
    
    /* Master receives data from the Slave */
    Csio_MasterReceive();
    
    /* Compare receive data with transfer data */
    if(Error == CompareData(au8CsioMasterRxBuf, au8CsioSlaveTxBuf, SAMPLE_CSIO_MASTER_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }
    
    Mfs_Csio_DeInit(CsioCh6, TRUE);
    Mfs_Csio_DeInit(CsioCh7, TRUE);
    
    while(1)
    {
        /* Data is normally sent and received */
    }
}


/* [] END OF FILE */
