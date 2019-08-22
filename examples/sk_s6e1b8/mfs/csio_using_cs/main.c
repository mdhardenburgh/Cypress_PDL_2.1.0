/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates communication between CSIO6 and 
*                   CSIO7 with interrupt mode using CS pin
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
stc_mfs_csio_config_t stcCsioMasterConfig, stcCsioSlaveConfig;
stc_csio_irq_cb_t stcCsioMasterIrqCb, stcCsioSlaveIrqCb;
stc_csio_cs_t stcCsioMasterCsConfig, stcCsioSlaveCsConfig;
volatile stc_mfsn_csio_t* CsioMasterCh = &CSIO6;
volatile stc_mfsn_csio_t* CsioSlaveCh = &CSIO7;
uint32_t SendCnt = 0, ReceiveCnt = 0;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8CsioMasterTxBuf[] = "0123456";
static uint8_t au8CsioSlaveTxBuf[] = "abcdefg";
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
* Function Name: CsioMasterTxIntCallback
********************************************************************************
* CSIO master transfer interrupt callback function
*******************************************************************************/
static void CsioMasterTxIntCallback(void)
{
    if(SendCnt == SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioMasterCh, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioMasterCh, au8CsioMasterTxBuf[SendCnt], TRUE);  
    SendCnt++;

}

/*******************************************************************************
* Function Name: CsioSlaveRxIntCallback
********************************************************************************
* CSIO slave receive interrupt callback function
*******************************************************************************/
static void CsioSlaveRxIntCallback(void)
{
    au8CsioSlaveRxBuf[ReceiveCnt] = Mfs_Csio_ReceiveData(CsioSlaveCh);
    ReceiveCnt++;
    
    if(ReceiveCnt == SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioSlaveCh, CsioRxIrq);
    }
}

/*******************************************************************************
* Function Name: CsioMasterRxIntCallback
********************************************************************************
* CSIO Master receive interrupt callback function
*******************************************************************************/
static void CsioMasterRxIntCallback(void)
{
    au8CsioMasterRxBuf[ReceiveCnt] = Mfs_Csio_ReceiveData(CsioMasterCh);
    ReceiveCnt++;
    
    if(ReceiveCnt == SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioMasterCh, CsioRxIrq);
        return;
    }
}

/*******************************************************************************
* Function Name: CsioSlaveTxIntCallback
********************************************************************************
* CSIO slave transfer interrupt callback function
*******************************************************************************/
static void CsioSlaveTxIntCallback(void)
{
    if(SendCnt == SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioSlaveCh, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioSlaveCh, au8CsioSlaveTxBuf[SendCnt], TRUE);  
    SendCnt++;
}

/*******************************************************************************
* Function Name: InitCsio
********************************************************************************
* Initialization of the CSIO
*******************************************************************************/
void InitCsio(void)
{
    /* Clear configuration structure */
    PDL_ZERO_STRUCT(stcCsioMasterConfig);
    PDL_ZERO_STRUCT(stcCsioSlaveConfig);
    PDL_ZERO_STRUCT(stcCsioMasterIrqCb);
    PDL_ZERO_STRUCT(stcCsioSlaveIrqCb);
    PDL_ZERO_STRUCT(stcCsioMasterCsConfig);
    PDL_ZERO_STRUCT(stcCsioSlaveCsConfig);
    
    /* Initialize interrupt callback functions */
    stcCsioMasterIrqCb.pfnTxIrqCb = CsioMasterTxIntCallback;
    stcCsioSlaveIrqCb.pfnRxIrqCb = CsioSlaveRxIntCallback;
    
    stcCsioMasterIrqCb.pfnRxIrqCb = CsioMasterRxIntCallback;
    stcCsioSlaveIrqCb.pfnTxIrqCb = CsioSlaveTxIntCallback;
    
    /* Initialize chip selection configuration */
    stcCsioMasterCsConfig.enCsStartPin = CsPinScs1;
    stcCsioMasterCsConfig.enCsEndPin = CsPinScs1; 
    stcCsioMasterCsConfig.enClkDiv = CsClkNoDiv;
    stcCsioMasterCsConfig.bActiveHold = FALSE;
    stcCsioMasterCsConfig.enLevel = CsLowActive;
    stcCsioMasterCsConfig.u8CsSetupDelayTime = 200u;
    stcCsioMasterCsConfig.u8CsHoldDelayTime = 200u;
    stcCsioMasterCsConfig.u16CsDeselectTime = 2000u;
    stcCsioMasterCsConfig.u8Scs0TransferByteCnt = SAMPLE_CSIO_MASTER_TX_BUFFSIZE;
    stcCsioMasterCsConfig.u8Scs1TransferByteCnt = 0;
    stcCsioMasterCsConfig.u8Scs2TransferByteCnt = 0;
    stcCsioMasterCsConfig.u8Scs3TransferByteCnt = 0;
    stcCsioMasterCsConfig.bScs0En = FALSE;
    stcCsioMasterCsConfig.bScs1En = TRUE;
    stcCsioMasterCsConfig.bScs2En = FALSE;
    stcCsioMasterCsConfig.bScs3En = FALSE;
    
    stcCsioSlaveCsConfig.bScs0En = TRUE; /* Only the SCS0 can be used in slave mode */
    stcCsioSlaveCsConfig.enLevel = CsLowActive;
    
    /* Initialize CSIO master */
    stcCsioMasterConfig.enMsMode = CsioMaster;
    stcCsioMasterConfig.enActMode = CsioActNormalMode;
    stcCsioMasterConfig.bInvertClk = FALSE;
    stcCsioMasterConfig.u32BaudRate = 100000;
    stcCsioMasterConfig.enDataLength = CsioEightBits;
    stcCsioMasterConfig.enBitDirection = CsioDataMsbFirst;
    stcCsioMasterConfig.enSyncWaitTime = CsioSyncWaitZero;
    stcCsioMasterConfig.pstcFifoConfig = NULL;
    stcCsioMasterConfig.pstcCsConfig = &stcCsioMasterCsConfig;
    stcCsioMasterConfig.pstcSerialTimer = NULL;
    stcCsioMasterConfig.pstcIrqEn = NULL;
    stcCsioMasterConfig.pstcIrqCb = &stcCsioMasterIrqCb;
    stcCsioMasterConfig.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioMasterCh, &stcCsioMasterConfig);
    
    /* Initialize CSIO slave */
    stcCsioSlaveConfig.enMsMode = CsioSlave;
    stcCsioSlaveConfig.enActMode = CsioActNormalMode;
    stcCsioSlaveConfig.bInvertClk = FALSE;
    stcCsioSlaveConfig.u32BaudRate = 100000;
    stcCsioSlaveConfig.enDataLength = CsioEightBits;
    stcCsioSlaveConfig.enBitDirection = CsioDataMsbFirst;
    stcCsioSlaveConfig.pstcFifoConfig = NULL;
    stcCsioSlaveConfig.pstcCsConfig = &stcCsioSlaveCsConfig; /* Only the SCS0 can be used in slave mode */
    stcCsioSlaveConfig.pstcSerialTimer = NULL;
    stcCsioSlaveConfig.pstcIrqEn = NULL;
    stcCsioSlaveConfig.pstcIrqCb = &stcCsioSlaveIrqCb;
    stcCsioSlaveConfig.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioSlaveCh, &stcCsioSlaveConfig);
}

/*******************************************************************************
* Function Name: Csio_MasterSend
********************************************************************************
* Master sends data to the slave  
*******************************************************************************/
void Csio_MasterSend(void)
{
    /* Enable TX function of CSIO6 */
    Mfs_Csio_EnableFunc(CsioMasterCh, CsioTx);
    
    /* Enable RX function of CSIO7 */
    Mfs_Csio_EnableFunc(CsioSlaveCh, CsioRx);
    
    /* Configure interrupt */
    Mfs_Csio_EnableIrq(CsioSlaveCh, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioMasterCh, CsioTxIrq);
    
    while(SendCnt < SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Wait until send finish */
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioMasterCh, CsioTxIdle))
    {
        /* Wait until TX bus idle */
    }
    
    while(ReceiveCnt < SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Wait until receive finish */
    }
}

/*******************************************************************************
* Function Name: Csio_MasterReceive
********************************************************************************
* Master receives data from slave
*******************************************************************************/
void Csio_MasterReceive(void)
{
    /* Enable TX function of CSIO6 */
    Mfs_Csio_EnableFunc(CsioSlaveCh, CsioTx);
    
    /* Enable TX and RX function of CSIO0 */
    Mfs_Csio_EnableFunc(CsioMasterCh, CsioTx);
    Mfs_Csio_EnableFunc(CsioMasterCh, CsioRx);
   
    /* Configure interrupt */
    SendCnt = 0;
    ReceiveCnt = 0;
    
    Mfs_Csio_EnableIrq(CsioMasterCh, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioSlaveCh, CsioTxIrq);
     
    /* Master dummy write */
    while(SendCnt < SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        while(TRUE != Mfs_Csio_GetStatus(CsioMasterCh, CsioTxEmpty))
        {
            
        }
        Mfs_Csio_SendData(CsioMasterCh, 0x00u, FALSE);   /* Dummy write */ 
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioMasterCh, CsioTxIdle))
    {
        /* wait until TX bus idle */
    }
    
    while(ReceiveCnt < SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Wait receive finish */
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
    /* Initialize CSIO function I/O */    
    /* Initialization of the GPIO for CSIO6 */
    SetPinFunc_SIN6_0();
    SetPinFunc_SOT6_0();
    SetPinFunc_SCK6_0();
    SetPinFunc_SCS61_1();
    
    /* Initialization of the GPIO for CSIO7 */
    SetPinFunc_SIN7_2();
    SetPinFunc_SOT7_2();
    SetPinFunc_SCK7_2();
    Gpio1pin_InitIn(GPIO1PIN_P4A, Gpio1pin_InitPullup(1u));
    SetPinFunc_SCS70_1();
    
    /* Initialization of the CSIO unit */
    InitCsio();
    
    SendCnt = 0;
    ReceiveCnt = 0;
    
    /* Master sends data to the Slave */
    Csio_MasterSend();

    /* Compare receive data with transfer data */
    if(Error == CompareData(au8CsioMasterTxBuf, au8CsioSlaveRxBuf, SAMPLE_CSIO_SLAVE_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }
    
    /* Disable TX function of CSIO0   */
    Mfs_Csio_DisableFunc(CsioMasterCh, CsioTx);
    /* Disable RX function of CSIO6   */
    Mfs_Csio_DisableFunc(CsioSlaveCh, CsioRx);
    /* Stop Sync Timer   */
    Mfs_Csio_DisableFunc(CsioMasterCh, CsioSerialTimer);
    
    SendCnt = 0;
    ReceiveCnt = 0;
    
    /* Master receive data from the Slave */
    Csio_MasterReceive();
    
    /* Compare receive data with transfer data */
    if(Error == CompareData(au8CsioMasterRxBuf, au8CsioSlaveTxBuf, SAMPLE_CSIO_MASTER_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }
    
    /* Disable TX function of CSIO7 */
    Mfs_Csio_DisableFunc(CsioSlaveCh, CsioTx);
    
    /* Disable TX and RX function of CSIO6 */
    Mfs_Csio_DisableFunc(CsioMasterCh, CsioTx);
    Mfs_Csio_DisableFunc(CsioMasterCh, CsioRx);
    
    Mfs_Csio_DeInit(CsioMasterCh, TRUE);
    Mfs_Csio_DeInit(CsioSlaveCh, TRUE);
    
    while(1)
    {
        /* Data is normally sent and received */
    }
}


/* [] END OF FILE */
