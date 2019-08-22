/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Demo the communication between UART3 and UART9
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
#define SAMPLE_UART_RX_BUFFSIZE sizeof(au8UartTxBuf)/sizeof(char)
#define SAMPLE_UART_TX_BUFFSIZE SAMPLE_UART_RX_BUFFSIZE

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_mfs_uart_config_t stcUartConfig;
stc_uart_irq_cb_t stcUart3IrqCb, stcUart9IrqCb;
volatile stc_mfsn_uart_t* UartCh3 = &UART3;
volatile stc_mfsn_uart_t* UartCh9 = &UART9;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8UartTxBuf[] = "Data sent from UART3 to UART9";
static uint8_t au8UartRxBuf[SAMPLE_UART_RX_BUFFSIZE];
static uint8_t u8TxCnt = 0, u8RxCnt = 0;

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
    Mfs_Uart_SendData(UartCh3, au8UartTxBuf[u8TxCnt]);  
    u8TxCnt++;
    if(u8TxCnt >= SAMPLE_UART_TX_BUFFSIZE )
    {
        /* Disable transfer interrupt of UART3 */
        Mfs_Uart_DisableIrq(UartCh3, UartTxIrq);
        return;
    }

}

/*******************************************************************************
* Function Name: Uart9RxIntCallback
********************************************************************************
* UART9 RX interrupt callback function
*******************************************************************************/
void Uart9RxIntCallback(void)
{
    au8UartRxBuf[u8RxCnt] = Mfs_Uart_ReceiveData(UartCh9);
    u8RxCnt++;
    if(u8RxCnt >= SAMPLE_UART_RX_BUFFSIZE )
    {
        /* Disable transfer interrupt of UART9 */
        Mfs_Uart_DisableIrq(UartCh9, UartRxIrq);
        return;
    }
}

/*******************************************************************************
* Function Name: InitUart
********************************************************************************
* Initialization of the UART
*******************************************************************************/
void InitUart(void)
{
    /* Clear structures */
    PDL_ZERO_STRUCT(stcUartConfig);
    PDL_ZERO_STRUCT(stcUart3IrqCb);
    PDL_ZERO_STRUCT(stcUart9IrqCb);  
    
    /* Initailize UART interrupt callback functions */
    stcUart3IrqCb.pfnTxIrqCb = Uart3TxIntCallback;
    stcUart9IrqCb.pfnRxIrqCb = Uart9RxIntCallback;
    
    /* Initialize UART TX and RX channel  */
    stcUartConfig.enMode = UartNormal;
    stcUartConfig.u32BaudRate = 115200;
    stcUartConfig.enDataLength = UartEightBits;
    stcUartConfig.enParity = UartParityNone;
    stcUartConfig.enStopBit = UartOneStopBit;
    stcUartConfig.enBitDirection = UartDataLsbFirst; 
    stcUartConfig.bInvertData = FALSE;
    stcUartConfig.bHwFlow = FALSE;
    stcUartConfig.pstcFifoConfig = NULL;
    stcUartConfig.bUseExtClk = FALSE;
    stcUartConfig.pstcIrqEn = NULL;
    stcUartConfig.pstcIrqCb = &stcUart3IrqCb;
    stcUartConfig.bTouchNvic = TRUE;
    Mfs_Uart_Init(UartCh3, &stcUartConfig);
    
    /* The configuration for another UART instance is all the same except 
    interrupt callback functions */
    stcUartConfig.pstcIrqCb = &stcUart9IrqCb; 
    Mfs_Uart_Init(UartCh9, &stcUartConfig);
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
    /* Initialize UART function I/O */
    SetPinFunc_SIN3_1();
    SetPinFunc_SOT3_1();
    SetPinFunc_SIN9_1();
    SetPinFunc_SOT9_1();  
  
    /* UART initialization */
    InitUart();
    
    /* Enable RX function of UART9 */
    Mfs_Uart_EnableFunc(UartCh9, UartRx);
    /* Enable TX function of UART3 */
    Mfs_Uart_EnableFunc(UartCh3, UartTx);
    
    /* Configure interrupt */    
    Mfs_Uart_EnableIrq(UartCh9, UartRxIrq);
    Mfs_Uart_EnableIrq(UartCh3, UartTxIrq);
    
    while(u8RxCnt < SAMPLE_UART_RX_BUFFSIZE)
    {
    }
        
    Mfs_Uart_DeInit(UartCh3, TRUE);
    Mfs_Uart_DeInit(UartCh9, TRUE);
    
    /* Compare receive data with transfer data */
    if(Error == CompareData(au8UartTxBuf, au8UartRxBuf, SAMPLE_UART_RX_BUFFSIZE))
    {
        while(1)
        {
            /* If code runs here, the communicate error occurs */
        } 
    }
    
    while(1)
    {
        /* Data is normally sent and received */
    } 
}


/* [] END OF FILE */
