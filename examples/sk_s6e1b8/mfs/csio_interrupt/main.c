/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates communication between CSIO0 and 
*                   CSIO1 with interrupt mode. 
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
stc_mfs_csio_config_t stcCsio0Config, stcCsio1Config;
stc_csio_irq_cb_t stcCsio0IrqCb, stcCsio1IrqCb;
volatile stc_mfsn_csio_t* CsioCh0 = &CSIO0;
volatile stc_mfsn_csio_t* CsioCh1 = &CSIO1;
uint32_t u32SendCnt = 0, u32ReceiveCnt = 0;

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/
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
        Mfs_Csio_DisableIrq(CsioCh0, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh0, au8CsioMasterTxBuf[u32SendCnt], TRUE);  
    u32SendCnt++;
}

/*******************************************************************************
* Function Name: CsioSlaveRxIrqCallback
********************************************************************************
* CSIO slave receive interrupt callback function
*******************************************************************************/
static void CsioSlaveRxIrqCallback(void)
{
    au8CsioSlaveRxBuf[u32ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh1);
    u32ReceiveCnt++;
    
    if(u32ReceiveCnt == SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh1, CsioRxIrq);
    }
}

/*******************************************************************************
* Function Name: CsioMasterRxIrqCallback
********************************************************************************
* CSIO Master receive interrupt callback function
*******************************************************************************/
static void CsioMasterRxIrqCallback(void)
{
    au8CsioMasterRxBuf[u32ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh0);
    u32ReceiveCnt++;
    
    if(u32ReceiveCnt == SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh0, CsioRxIrq);
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
        Mfs_Csio_DisableIrq(CsioCh1, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh1, au8CsioSlaveTxBuf[u32SendCnt], TRUE);  
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
    PDL_ZERO_STRUCT(stcCsio0Config);
    PDL_ZERO_STRUCT(stcCsio1Config);
    PDL_ZERO_STRUCT(stcCsio0IrqCb);
    PDL_ZERO_STRUCT(stcCsio1IrqCb);
    
    /* Initialize CSIO interrupt callback functions */
    stcCsio0IrqCb.pfnTxIrqCb = CsioMasterTxIrqCallback;
    stcCsio1IrqCb.pfnRxIrqCb = CsioSlaveRxIrqCallback;
    
    stcCsio0IrqCb.pfnRxIrqCb = CsioMasterRxIrqCallback;
    stcCsio1IrqCb.pfnTxIrqCb = CsioSlaveTxIrqCallback;      
    
    /* Initialize CSIO master  */
    stcCsio0Config.enMsMode = CsioMaster;
    stcCsio0Config.enActMode = CsioActNormalMode;
    stcCsio0Config.bInvertClk = FALSE;
    stcCsio0Config.u32BaudRate = 100000;
    stcCsio0Config.enDataLength = CsioEightBits;
    stcCsio0Config.enBitDirection = CsioDataMsbFirst;
    stcCsio0Config.enSyncWaitTime = CsioSyncWaitZero;
    stcCsio0Config.pstcFifoConfig = NULL;
    stcCsio0Config.pstcIrqCb = &stcCsio0IrqCb;
    stcCsio0Config.pstcIrqEn = NULL;
    stcCsio0Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh0, &stcCsio0Config);
    
    /* Initialize CSIO slave  */
    stcCsio1Config.enMsMode = CsioSlave;
    stcCsio1Config.enActMode = CsioActNormalMode;
    stcCsio1Config.bInvertClk = FALSE;
    stcCsio1Config.u32BaudRate = 100000;
    stcCsio1Config.enDataLength = CsioEightBits;
    stcCsio1Config.enBitDirection = CsioDataMsbFirst;
    stcCsio1Config.pstcFifoConfig = NULL;
    stcCsio1Config.pstcIrqCb = &stcCsio1IrqCb;
    stcCsio1Config.pstcIrqEn = NULL;
    stcCsio1Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh1, &stcCsio1Config);
}

/*******************************************************************************
* Function Name: Csio_MasterSend
********************************************************************************
* The Master sends data to the Slave  
*******************************************************************************/
void Csio_MasterSend(void)
{    
    /* Configure interrupt */
    Mfs_Csio_EnableIrq(CsioCh1, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh0, CsioTxIrq);
    
    /* Enable RX function of CSIO1   */
    Mfs_Csio_EnableFunc(CsioCh1, CsioRx);
    /* Enable TX function of CSIO0   */
    Mfs_Csio_EnableFunc(CsioCh0, CsioTx);
    
    while(u32SendCnt < SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Wait for TX finish */
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioCh0, CsioTxIdle))
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
    Mfs_Csio_EnableIrq(CsioCh0, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh1, CsioTxIrq);
    
    /* Enable TX function of CSIO1 */
    Mfs_Csio_EnableFunc(CsioCh1, CsioTx);
    
    /* Enable TX and RX function of CSIO0 */
    Mfs_Csio_EnableFunc(CsioCh0, CsioTx);
    Mfs_Csio_EnableFunc(CsioCh0, CsioRx);
 
    /* Send dummy data */
    while(u32SendCnt < SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        while(TRUE != Mfs_Csio_GetStatus(CsioCh0, CsioTxEmpty))
        {
            
        }
        Mfs_Csio_SendData(CsioCh0, 0x00u, FALSE);   /* Dummy write */
    }
        
    while(TRUE != Mfs_Csio_GetStatus(CsioCh0, CsioTxIdle))
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
    SetPinFunc_SIN0_1(); /* Initializatiion of the GPIO used for CSIO0 */
    SetPinFunc_SOT0_1();
    SetPinFunc_SCK0_1();
    
    SetPinFunc_SIN1_2(); /* Initializatiion of the GPIO used for CSIO1 */
    SetPinFunc_SOT1_1();
    SetPinFunc_SCK1_1();
      
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
    
    /* Disable TX function of CSIO0 */
    Mfs_Csio_DisableFunc(CsioCh0, CsioTx);
    /* Disable RX function of CSIO1 */
    Mfs_Csio_DisableFunc(CsioCh1, CsioRx);
    
    
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
    
    Mfs_Csio_DeInit(CsioCh0, TRUE);
    Mfs_Csio_DeInit(CsioCh1, TRUE);
    
    while(1)
    {
        /* Data is normally sent and received */
    }
}


/* [] END OF FILE */
