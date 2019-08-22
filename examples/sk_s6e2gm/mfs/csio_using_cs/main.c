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
#if !defined(SetPinFunc_SCS63_0) || !defined(SetPinFunc_SCS70_1)
#error SCS63_0 or SCS70_1 is not available on this product, please use other \
pins or channels and detele "me".
#endif

#define SAMPLE_CSIO_SLAVE_RX_BUFFSIZE   sizeof(au8CsioMasterTxBuf)/sizeof(char)
#define SAMPLE_CSIO_MASTER_TX_BUFFSIZE  SAMPLE_CSIO_SLAVE_RX_BUFFSIZE

#define SAMPLE_CSIO_MASTER_RX_BUFFSIZE  sizeof(au8CsioSlaveTxBuf)/sizeof(char)
#define SAMPLE_CSIO_SLAVE_TX_BUFFSIZE   SAMPLE_CSIO_MASTER_RX_BUFFSIZE

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_mfs_csio_config_t stcCsio6Config, stcCsio7Config;
stc_csio_irq_cb_t stcCsio6IrqCb, stcCsio7IrqCb;
stc_csio_cs_t stcCsio6CsConfig, stcCsio7CsConfig;
volatile stc_mfsn_csio_t* CsioCh6 = &CSIO6;
volatile stc_mfsn_csio_t* CsioCh7 = &CSIO7;
volatile uint32_t SendCnt = 0;
volatile uint32_t ReceiveCnt = 0;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8CsioMasterTxBuf[] = "01234567";
static uint8_t au8CsioSlaveTxBuf[] = "abcdefgh";
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
        Mfs_Csio_DisableIrq(CsioCh6, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh6, au8CsioMasterTxBuf[SendCnt], TRUE);  
    SendCnt++;

}

/*******************************************************************************
* Function Name: CsioSlaveRxIntCallback
********************************************************************************
* CSIO slave receive interrupt callback function
*******************************************************************************/
static void CsioSlaveRxIntCallback(void)
{
    au8CsioSlaveRxBuf[ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh7);
    ReceiveCnt++;
    
    if(ReceiveCnt == SAMPLE_CSIO_SLAVE_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh7, CsioRxIrq);
    }
}

/*******************************************************************************
* Function Name: CsioMasterRxIntCallback
********************************************************************************
* CSIO Master receive interrupt callback function
*******************************************************************************/
static void CsioMasterRxIntCallback(void)
{
    au8CsioMasterRxBuf[ReceiveCnt] = Mfs_Csio_ReceiveData(CsioCh6);
    ReceiveCnt++;
    
    if(ReceiveCnt == SAMPLE_CSIO_MASTER_RX_BUFFSIZE)
    {
        /* Disable interrupt */
        Mfs_Csio_DisableIrq(CsioCh6, CsioRxIrq);
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
        Mfs_Csio_DisableIrq(CsioCh7, CsioTxIrq);
        return;
    }
  
    Mfs_Csio_SendData(CsioCh7, au8CsioSlaveTxBuf[SendCnt], TRUE);  
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
    PDL_ZERO_STRUCT(stcCsio6Config);
    PDL_ZERO_STRUCT(stcCsio7Config);
    PDL_ZERO_STRUCT(stcCsio6IrqCb);
    PDL_ZERO_STRUCT(stcCsio7IrqCb);
    PDL_ZERO_STRUCT(stcCsio6CsConfig);
    PDL_ZERO_STRUCT(stcCsio7CsConfig);
    
    /* Initialize interrupt callback functions */
    stcCsio6IrqCb.pfnTxIrqCb = CsioMasterTxIntCallback;
    stcCsio7IrqCb.pfnRxIrqCb = CsioSlaveRxIntCallback;
    
    stcCsio6IrqCb.pfnRxIrqCb = CsioMasterRxIntCallback;
    stcCsio7IrqCb.pfnTxIrqCb = CsioSlaveTxIntCallback;
    
    /* Initialize chip selection configuration */
    stcCsio6CsConfig.enCsStartPin = CsPinScs3;
    stcCsio6CsConfig.enCsEndPin = CsPinScs3; 
    stcCsio6CsConfig.enClkDiv = CsClkNoDiv;
    stcCsio6CsConfig.bActiveHold = FALSE;
    stcCsio6CsConfig.enLevel = CsLowActive;
    stcCsio6CsConfig.u8CsSetupDelayTime = 200u;
    stcCsio6CsConfig.u8CsHoldDelayTime = 200u;
    stcCsio6CsConfig.u16CsDeselectTime = 2000u;
    stcCsio6CsConfig.u8Scs0TransferByteCnt = 0;
    stcCsio6CsConfig.u8Scs1TransferByteCnt = 0;
    stcCsio6CsConfig.u8Scs2TransferByteCnt = 0;
    stcCsio6CsConfig.u8Scs3TransferByteCnt = SAMPLE_CSIO_MASTER_TX_BUFFSIZE;
    stcCsio6CsConfig.bScs0En = FALSE;
    stcCsio6CsConfig.bScs1En = FALSE;
    stcCsio6CsConfig.bScs2En = FALSE;
    stcCsio6CsConfig.bScs3En = TRUE;
    
    stcCsio7CsConfig.bScs0En = TRUE; /* Only the SCS0 can be used in slave mode */
    stcCsio7CsConfig.enLevel = CsLowActive;
    
    /* Initialize CSIO master */
    stcCsio6Config.enMsMode = CsioMaster;
    stcCsio6Config.enActMode = CsioActNormalMode;
    stcCsio6Config.bInvertClk = FALSE;
    stcCsio6Config.u32BaudRate = 100000;
    stcCsio6Config.enDataLength = CsioNineBits;
    stcCsio6Config.enBitDirection = CsioDataMsbFirst;
    stcCsio6Config.enSyncWaitTime = CsioSyncWaitZero;
    stcCsio6Config.pstcFifoConfig = NULL;
    stcCsio6Config.pstcCsConfig = &stcCsio6CsConfig;
    stcCsio6Config.pstcSerialTimer = NULL;
    stcCsio6Config.pstcIrqEn = NULL;
    stcCsio6Config.pstcIrqCb = &stcCsio6IrqCb;
    stcCsio6Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh6, &stcCsio6Config);
    
    /* Initialize CSIO slave */
    stcCsio7Config.enMsMode = CsioSlave;
    stcCsio7Config.enActMode = CsioActNormalMode;
    stcCsio7Config.bInvertClk = FALSE;
    stcCsio7Config.u32BaudRate = 100000;
    stcCsio7Config.enDataLength = CsioNineBits;
    stcCsio7Config.enBitDirection = CsioDataMsbFirst;
    stcCsio7Config.pstcFifoConfig = NULL;
    stcCsio7Config.pstcCsConfig = &stcCsio7CsConfig; /* Only the SCS0 can be used in slave mode */
    stcCsio7Config.pstcSerialTimer = NULL;
    stcCsio7Config.pstcIrqEn = NULL;
    stcCsio7Config.pstcIrqCb = &stcCsio7IrqCb;
    stcCsio7Config.bTouchNvic = TRUE;
    
    Mfs_Csio_Init(CsioCh7, &stcCsio7Config);
}

/*******************************************************************************
* Function Name: Csio_MasterSend
********************************************************************************
* Master sends data to the slave  
*******************************************************************************/
void Csio_MasterSend(void)
{
    /* Enable TX function of CSIO6 */
    Mfs_Csio_EnableFunc(CsioCh6, CsioTx);
    
    /* Enable RX function of CSIO7 */
    Mfs_Csio_EnableFunc(CsioCh7, CsioRx);
    
    /* Configure interrupt */
    Mfs_Csio_EnableIrq(CsioCh7, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh6, CsioTxIrq);
    
    while(SendCnt < SAMPLE_CSIO_MASTER_TX_BUFFSIZE)
    {
        /* Wait until send finish */
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxIdle))
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
    Mfs_Csio_EnableFunc(CsioCh7, CsioTx);
    
    /* Enable TX and RX function of CSIO6 */
    Mfs_Csio_EnableFunc(CsioCh6, CsioTx);
    Mfs_Csio_EnableFunc(CsioCh6, CsioRx);
   
    /* Configure interrupt */
    SendCnt = 0;
    ReceiveCnt = 0;
    
    Mfs_Csio_EnableIrq(CsioCh6, CsioRxIrq);
    Mfs_Csio_EnableIrq(CsioCh7, CsioTxIrq);
     
    /* Master dummy write */
    while(SendCnt < SAMPLE_CSIO_SLAVE_TX_BUFFSIZE)
    {
        while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxEmpty))
        {
            
        }
        Mfs_Csio_SendData(CsioCh6, 0x00u, FALSE);   /* Dummy write */    
    }
    
    while(TRUE != Mfs_Csio_GetStatus(CsioCh6, CsioTxIdle))
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
    SetPinFunc_SIN6_1();
    SetPinFunc_SOT6_1();
    SetPinFunc_SCK6_1();
    SetPinFunc_SCS63_0();
    
    /* Initialization of the GPIO for CSIO7 */
    SetPinFunc_SIN7_1();
    SetPinFunc_SOT7_1();
    SetPinFunc_SCK7_1();
    Gpio1pin_InitIn(GPIO1PIN_P43, Gpio1pin_InitPullup(1u));
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
    
    /* Disable TX function of CSIO6   */
    Mfs_Csio_DisableFunc(CsioCh6, CsioTx);
    /* Disable RX function of CSIO7   */
    Mfs_Csio_DisableFunc(CsioCh7, CsioRx);
    /* Stop Sync Timer   */
    Mfs_Csio_DisableFunc(CsioCh6, CsioSerialTimer);
    
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
    Mfs_Csio_DisableFunc(CsioCh7, CsioTx);
    
    /* Disable TX and RX function of CSIO6 */
    Mfs_Csio_DisableFunc(CsioCh6, CsioTx);
    Mfs_Csio_DisableFunc(CsioCh6, CsioRx);
    
    Mfs_Csio_DeInit(CsioCh6, TRUE);
    Mfs_Csio_DeInit(CsioCh7, TRUE);
    
    while(1)
    {
        /* Data is normally sent and received */
    }
}


/* [] END OF FILE */
