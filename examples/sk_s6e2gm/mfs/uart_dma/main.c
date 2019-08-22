/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Demo the communication between UART3 and UART6 with interrupt 
*                   mode using DMA
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
#define SAMPLE_UART_RX_BUFFSIZE     (8u)
#define SAMPLE_UART_TX_BUFFSIZE     (8u)

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
volatile stc_mfsn_uart_t* UartCh3 = &UART3;
volatile stc_mfsn_uart_t* UartCh6 = &UART6;
stc_mfs_uart_config_t stcUartConfig;
stc_uart_irq_cb_t  stcUart3IrqCb, stcUart6IrqCb;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8UartTxBuf[SAMPLE_UART_TX_BUFFSIZE];
static uint8_t au8UartRxBuf[SAMPLE_UART_RX_BUFFSIZE];
static boolean_t bDma0Finished, bDma1Finished;

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
* Function Name: Uart3TxIntCallback
********************************************************************************
* UART3 TX interrupt callback function
*******************************************************************************/
void Uart3TxIntCallback(void)
{
    /* Should never enter */
}

/*******************************************************************************
* Function Name: Uart6RxIntCallback
********************************************************************************
* UART6 RX interrupt callback function
*******************************************************************************/
void Uart6RxIntCallback(void)
{
   /* Should never enter */
}

/*******************************************************************************
* Function Name: Dma0ErrorCallback
********************************************************************************
* DMA Error callback function
*
* \param u8ErrorCode
*******************************************************************************/
void Dma0ErrorCallback(uint8_t u8ErrorCode)
{
    /* Error handling */
}

/*******************************************************************************
* Function Name: Dma0FinishCallback
********************************************************************************
* DMA finish callback function
*******************************************************************************/
void Dma0FinishCallback(void)
{
    Mfs_Uart_DisableIrq(UartCh3, UartTxIrq);

    bDma0Finished = TRUE;         /* Set DMA finished notification flag */
}

/*******************************************************************************
* Function Name: Dma1ErrorCallback
********************************************************************************
* DMA Error callback function
*
* \param u8ErrorCode
*******************************************************************************/
void Dma1ErrorCallback(uint8_t u8ErrorCode)
{
    /* Error handling */
}

/*******************************************************************************
* Function Name: Dma1FinishCallback
********************************************************************************
* DMA finish callback function
*******************************************************************************/
void Dma1FinishCallback(void)
{
    Mfs_Uart_DisableIrq(UartCh6, UartRxIrq);

    bDma1Finished = TRUE;         /* Set DMA finished notification flag */
}

/*******************************************************************************
* Function Name: DmaInit
********************************************************************************
* DMA configuration
*******************************************************************************/
void DmaInit(void)
{
    stc_dma_config_t stcDma0Config, stcDma1Config;
    stc_dma_irq_en_t stcDma0IrqEn, stcDma1IrqEn;
    stc_dma_irq_cb_t  stcDma0IrqCb, stcDma1IrqCb;

    /* Clear local configuration structure to zero */
    PDL_ZERO_STRUCT(stcDma0Config);
    PDL_ZERO_STRUCT(stcDma0IrqEn);
    PDL_ZERO_STRUCT(stcDma0IrqCb);
    PDL_ZERO_STRUCT(stcDma1Config);
    PDL_ZERO_STRUCT(stcDma1IrqEn);
    PDL_ZERO_STRUCT(stcDma1IrqCb);

    /* Initialize interrupts */
    stcDma0IrqEn.bCompleteIrq = 1u;
    stcDma0IrqEn.bErrorIrq = 1u;
    stcDma0IrqCb.pfnDmaCompletionIrqCb = Dma0FinishCallback;
    stcDma0IrqCb.pfnDmaErrorIrqCb = Dma0ErrorCallback;
    
    stcDma1IrqEn.bCompleteIrq = 1u;
    stcDma1IrqEn.bErrorIrq = 1u;
    stcDma1IrqCb.pfnDmaCompletionIrqCb = Dma1FinishCallback;
    stcDma1IrqCb.pfnDmaErrorIrqCb = Dma1ErrorCallback;
    
    /* DMAC0 configuration */
    stcDma0Config.enDmaIdrq = MfsTx3;
    stcDma0Config.u8BlockCount = 1u;
    stcDma0Config.u16TransferCount = SAMPLE_UART_TX_BUFFSIZE ;
    stcDma0Config.enTransferMode = DmaDemandTransfer;
    stcDma0Config.enTransferWidth = Dma8Bit;
    stcDma0Config.u32SourceAddress = (uint32_t)&(au8UartTxBuf[0u]); /* UART data address */
    stcDma0Config.u32DestinationAddress = MFS3_DATA_REG_ADDR;	    /* Destination array's address */
    stcDma0Config.bFixedSource = FALSE;
    stcDma0Config.bFixedDestination = TRUE;
    stcDma0Config.bReloadCount = TRUE;       /* Reload count for next data package */
    stcDma0Config.bReloadSource = TRUE;      /* Reload source address for next data package */
    stcDma0Config.bReloadDestination = FALSE;
    stcDma0Config.bEnableBitMask = TRUE;     /* Don't clear enable bit after transfer completion */
    stcDma0Config.pstcIrqEn = &stcDma0IrqEn;
    stcDma0Config.pstcIrqCb = &stcDma0IrqCb;
    stcDma0Config.bTouchNvic = TRUE;

    if (Ok == Dma_InitChannel(0u, &stcDma0Config)) /* Initialize DMA channel 0 */
    {
         Dma_SetChannel(0u, TRUE, FALSE, FALSE);   /* Enable channel */
    }

    /* DMAC1 configuration */
    stcDma1Config.enDmaIdrq = MfsRx6Sel24;
    stcDma1Config.u8BlockCount = 1u;
    stcDma1Config.u16TransferCount = SAMPLE_UART_RX_BUFFSIZE ;
    stcDma1Config.enTransferMode = DmaDemandTransfer;
    stcDma1Config.enTransferWidth = Dma8Bit;
    stcDma1Config.u32SourceAddress = MFS6_DATA_REG_ADDR ; /* UART data address */
    stcDma1Config.u32DestinationAddress = (uint32_t)&(au8UartRxBuf[0u]); /* Destination array's address */
    stcDma1Config.bFixedSource = TRUE;
    stcDma1Config.bFixedDestination = FALSE;
    stcDma1Config.bReloadCount = TRUE;       /* Reload count for next data package */
    stcDma1Config.bReloadSource = FALSE;
    stcDma1Config.bReloadDestination = TRUE; /* Reload destination for next data package */
    stcDma1Config.bEnableBitMask = TRUE;     /* Don't clear enable bit after transfer completion */
    stcDma1Config.pstcIrqEn = &stcDma1IrqEn;
    stcDma1Config.pstcIrqCb = &stcDma1IrqCb;
    stcDma1Config.bTouchNvic = TRUE;

    if (Ok == Dma_InitChannel(1u, &stcDma1Config))    /* Initialize DMA channel 1 */
    {
        Dma_SetChannel(1u, TRUE, FALSE, FALSE);	      /* Enable channel */
    }

    Dma_Enable();            /* Overall enable of DMA */

}

/*******************************************************************************
* Function Name: UartInit
********************************************************************************
* UART configuration
*******************************************************************************/
void UartInit(void)
{
    /* Clear structures */
    PDL_ZERO_STRUCT(stcUart3IrqCb);
    PDL_ZERO_STRUCT(stcUart6IrqCb);
   
    /* Initialize interrupt callback functions */
    stcUart3IrqCb.pfnTxIrqCb = Uart3TxIntCallback;
    stcUart6IrqCb.pfnRxIrqCb = Uart6RxIntCallback;
    
    /* Initialize UART TX and RX channel */
    stcUartConfig.enMode = UartNormal;
    stcUartConfig.u32BaudRate = 115200;
    stcUartConfig.enDataLength = UartEightBits;
    stcUartConfig.enParity = UartParityNone;
    stcUartConfig.enStopBit = UartOneStopBit;
    stcUartConfig.enBitDirection = UartDataLsbFirst;
    stcUartConfig.bInvertData = FALSE;
    stcUartConfig.bHwFlow = FALSE;
    stcUartConfig.pstcFifoConfig = NULL;
    stcUartConfig.pstcIrqEn = NULL;
    stcUartConfig.bTouchNvic = TRUE;
    
    stcUartConfig.pstcIrqCb = &stcUart3IrqCb;
    Mfs_Uart_Init(UartCh3, &stcUartConfig);
    
    stcUartConfig.pstcIrqCb = &stcUart6IrqCb;
    Mfs_Uart_Init(UartCh6, &stcUartConfig);
}

/*******************************************************************************
* Function Name: Uart3TxRxData
********************************************************************************
* Test 1st UART transfer/receive data with DMA
*******************************************************************************/
void Uart3TxRxData(void)
{
    uint8_t u8i;
    
    /* Initialize send data */
    for(u8i = 0; u8i < SAMPLE_UART_TX_BUFFSIZE; u8i++)
    {
        au8UartTxBuf[u8i] = u8i;
    }
    /* Clear DMA transfer finish flag */
    bDma0Finished = FALSE;
    bDma1Finished = FALSE;

    /* Configure interrupt */
    Mfs_Uart_EnableIrq(UartCh6, UartRxIrq);
    Mfs_Uart_EnableIrq(UartCh3, UartTxIrq);
    
    while(bDma0Finished != TRUE)
    {
        /* Wait for TX finish */
    }
    
    while(bDma1Finished != TRUE)
    {
        /* Wait for RX finish */
    }
}

/*******************************************************************************
* Function Name: Uart6TxRxData
********************************************************************************
* Test 6th UART transfer/receive data with DMA
*******************************************************************************/
void Uart6TxRxData(void)
{    
    uint8_t u8i;
    
    /* Initialize send data */
    for(u8i = 0; u8i < SAMPLE_UART_TX_BUFFSIZE; u8i++)
    {
        au8UartTxBuf[u8i] = ~u8i;
    }
    
    /* Clear DMA transfer finish flag */
    bDma0Finished = FALSE;
    bDma1Finished = FALSE;

    /* Configure interrupt */
    Mfs_Uart_EnableIrq(UartCh6, UartRxIrq);
    Mfs_Uart_EnableIrq(UartCh3, UartTxIrq);

    while(bDma0Finished != TRUE)
    {
        /* Wait for TX finish */
    }

    while(bDma1Finished != TRUE)
    {
        /* Wait for RX finish */
    }
}

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project 
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{
    /* Initialize UART function I/O */
    SetPinFunc_SIN3_1();
    SetPinFunc_SOT3_1();
    SetPinFunc_SIN6_1();
    SetPinFunc_SOT6_1();
        
    /* Initialize the UART */
    UartInit();

    /* Initialize and enable the DMA */
    DmaInit();

    /* Enable RX function of UART3   */
    Mfs_Uart_EnableFunc(UartCh6, UartRx);
    /* Enable TX function of UART3   */
    Mfs_Uart_EnableFunc(UartCh3, UartTx);

    /* Transfer/Receive the data by UART3 */
    Uart3TxRxData();
    
    /* Compare receive data with transfer data */
    if(Error == CompareData(au8UartTxBuf, au8UartRxBuf, SAMPLE_UART_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }

    /* Transfer/Receive the data by UART6 */
    Uart6TxRxData();

    /* Compare received data with transferred data */
    if(Error == CompareData(au8UartTxBuf, au8UartRxBuf, SAMPLE_UART_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        }
    }

    Mfs_Uart_DeInit(UartCh3, TRUE);
    Mfs_Uart_DeInit(UartCh6, TRUE);

    Dma_Disable() ;
    Dma_DeInitChannel(0u, TRUE);
    Dma_DeInitChannel(1u, TRUE);

    while(1)
    {
        /* Data is normally sent and received */
    }
}


/* [] END OF FILE */
