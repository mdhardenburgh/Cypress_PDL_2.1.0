/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Demo the communication between UART0 and UART1
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

#if (PDL_MCU_CORE == PDL_FM0P_CORE)
#if (PDL_MCU_TYPE == PDL_FM0P_TYPE1) || (PDL_MCU_TYPE == PDL_FM0P_TYPE2)
#define SAMPLE_UART_FIFO_MAX_CAPACITY         (128u)
#else
#define SAMPLE_UART_FIFO_MAX_CAPACITY         (64u)
#endif
#elif (PDL_MCU_CORE == PDL_FM4_CORE)          
#define SAMPLE_UART_FIFO_MAX_CAPACITY         (64u)
#elif (PDL_MCU_CORE == PDL_FM3_CORE)          
#define SAMPLE_UART_FIFO_MAX_CAPACITY         (16u)
#endif

#define SAMPLE_UART_FIFO_RX_CNT               (8u)

/*******************************************************************************
* UART TX FIFO information structure 
*******************************************************************************/
typedef struct stc_tx_fifo_info
{
    uint32_t u32TxCnt;
    uint8_t* pTxBuf;
    boolean_t bTxFinish;
    
}stc_tx_fifo_info_t;

/*******************************************************************************
* UART RX FIFO information structure
*******************************************************************************/
typedef struct stc_rx_fifo_info
{
    uint32_t u32RxCnt;
    uint8_t* pRxBuf;
    boolean_t bRxFinish;
    
}stc_rx_fifo_info_t;

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_mfs_uart_config_t stcUartConfig;
stc_mfs_fifo_config_t stcFifoConfig;
stc_uart_irq_cb_t stcUart0IrqCb, stcUart1IrqCb;
stc_tx_fifo_info_t stcTxFifoInfo = {0};
stc_rx_fifo_info_t stcRxFifoInfo = {0};

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
volatile stc_mfsn_uart_t* UartCh0 = &UART0;
volatile stc_mfsn_uart_t* UartCh1 = &UART1;
static uint8_t au8UartTxBuf[200] = "Data sent from UART0 to UART1";
static uint8_t au8UartRxBuf[SAMPLE_UART_RX_BUFFSIZE];

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
* Function Name: Uart0FifoTxIntCallback
********************************************************************************
* UART0 FIFO TX interrupt callback function
*******************************************************************************/
void Uart0FifoTxIntCallback(void)
{
    uint8_t u8i = 0;
    if(stcTxFifoInfo.u32TxCnt > SAMPLE_UART_FIFO_MAX_CAPACITY)
    {
        while(u8i < SAMPLE_UART_FIFO_MAX_CAPACITY)
        {
            Mfs_Uart_SendData(UartCh0, *stcTxFifoInfo.pTxBuf++);
            u8i++;
        }
        stcTxFifoInfo.u32TxCnt -= SAMPLE_UART_FIFO_MAX_CAPACITY;
        return;
    }
    
    while(u8i < stcTxFifoInfo.u32TxCnt)
    {
        Mfs_Uart_SendData(UartCh0, *stcTxFifoInfo.pTxBuf++);
        u8i++;
    }
  
    Mfs_Uart_DisableIrq(UartCh0, UartTxFifoIrq);
    
    stcTxFifoInfo.bTxFinish = TRUE;
}

/*******************************************************************************
* Function Name: Uart1RxIntCallback
********************************************************************************
* UART0 RX interrupt callback function
*******************************************************************************/
void Uart1RxIntCallback(void)
{
    uint8_t u8i = 0;
    if(stcRxFifoInfo.u32RxCnt > SAMPLE_UART_FIFO_RX_CNT) 
    {
        /* Receive data when RX FIFO count match with SAMPLE_UART_FIFO_RX_CNT */
        while(u8i < SAMPLE_UART_FIFO_RX_CNT)
        {
            *stcRxFifoInfo.pRxBuf++ = Mfs_Uart_ReceiveData(UartCh1); 
            u8i++;
        }
        stcRxFifoInfo.u32RxCnt -= SAMPLE_UART_FIFO_RX_CNT;
        return;
    }
    
    /* Receive data when RX FIFO is idle */
    /* idle means FIFO count is less than SAMPLE_UART_FIFO_RX_CNT and
       RX FIFO don't receive data from then on for a short time. */
    while(u8i < stcRxFifoInfo.u32RxCnt)
    {
        *stcRxFifoInfo.pRxBuf++ = Mfs_Uart_ReceiveData(UartCh1);
        u8i++;
    }
    
    Mfs_Uart_DisableIrq(UartCh1, UartRxIrq);
    
    stcRxFifoInfo.bRxFinish = TRUE;
}

/*******************************************************************************
* Function Name: InitUart
********************************************************************************
* Initialization of the UART
*******************************************************************************/
void InitUart(void)
{
    /* Initialize the FIFO information */
    stcTxFifoInfo.u32TxCnt = SAMPLE_UART_TX_BUFFSIZE;
    stcTxFifoInfo.pTxBuf = au8UartTxBuf;
    stcTxFifoInfo.bTxFinish = FALSE;
    
    stcRxFifoInfo.u32RxCnt = SAMPLE_UART_RX_BUFFSIZE;
    stcRxFifoInfo.pRxBuf = au8UartRxBuf;
    stcRxFifoInfo.bRxFinish = FALSE;
    
    /* Clear all configuration structures */
    PDL_ZERO_STRUCT(stcUartConfig);
    PDL_ZERO_STRUCT(stcFifoConfig);
    PDL_ZERO_STRUCT(stcUart0IrqCb);
    PDL_ZERO_STRUCT(stcUart1IrqCb);
    
    /* Initialize FIFO configuration */
    stcFifoConfig.enFifoSel = MfsTxFifo1RxFifo2;
    stcFifoConfig.u8ByteCount1 = 0;
    stcFifoConfig.u8ByteCount2 = 8;
    
    /* Initialize interrupt callback structure */
    stcUart0IrqCb.pfnTxFifoIrqCb = Uart0FifoTxIntCallback;
    stcUart1IrqCb.pfnRxIrqCb = Uart1RxIntCallback;
    
    /* Initialize UART TX and RX channel */
    stcUartConfig.enMode = UartNormal;
    stcUartConfig.u32BaudRate = 115200;
    stcUartConfig.enDataLength = UartEightBits;
    stcUartConfig.enParity = UartParityNone;
    stcUartConfig.enStopBit = UartOneStopBit;
    stcUartConfig.enBitDirection = UartDataLsbFirst; 
    stcUartConfig.bInvertData = FALSE;
    stcUartConfig.bHwFlow = FALSE;
    stcUartConfig.pstcFifoConfig = &stcFifoConfig;
    stcUartConfig.bUseExtClk = FALSE;
    stcUartConfig.pstcIrqEn = NULL;
    stcUartConfig.pstcIrqCb = &stcUart0IrqCb;
    stcUartConfig.bTouchNvic = TRUE;
    Mfs_Uart_Init(UartCh0, &stcUartConfig);
    
    /* The configuration is same for both channels except interrupt callback functions */
    stcUartConfig.pstcIrqCb = &stcUart1IrqCb; 
    Mfs_Uart_Init(UartCh1, &stcUartConfig);
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
    SetPinFunc_SIN0_1();
    SetPinFunc_SOT0_1();
    SetPinFunc_SIN1_2();
    SetPinFunc_SOT1_2();
    
    /* UART initialization */
    InitUart();
    
    /* Enable RX function of UART0 */
    Mfs_Uart_EnableFunc(UartCh1, UartRx);
    /* Enable TX function of UART0 */
    Mfs_Uart_EnableFunc(UartCh0, UartTx);
    
    /* Configure interrupt */    
    Mfs_Uart_EnableIrq(UartCh1, UartRxIrq);
    Mfs_Uart_EnableIrq(UartCh0, UartTxFifoIrq);
    
    while(stcRxFifoInfo.bRxFinish != TRUE)
    {
        /* Wait while all data is not sent */        
    }
        
    Mfs_Uart_DeInit(UartCh0, TRUE);
    Mfs_Uart_DeInit(UartCh1, TRUE);
    
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
