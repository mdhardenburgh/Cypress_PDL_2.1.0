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

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
volatile stc_mfsn_uart_t* UartCh0 = &UART0;
volatile stc_mfsn_uart_t* UartCh1 = &UART1;
stc_mfs_uart_config_t stcUartConfig;
uint8_t u8Cnt = 0;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t au8UartTxBuf[] = "Data sent from UART0 to UART1";
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
* Function Name: InitUart
********************************************************************************
* Initialization of the UART
*******************************************************************************/
void InitUart(void)
{
   PDL_ZERO_STRUCT(stcUartConfig);
   
   /* Initialize UART TX and RX channel */
    stcUartConfig.enMode = UartNormal;
    stcUartConfig.u32BaudRate = 115200;
    stcUartConfig.enDataLength = UartEightBits;
    stcUartConfig.enParity = UartParityNone;
    stcUartConfig.enStopBit = UartOneStopBit;
    stcUartConfig.enBitDirection = UartDataLsbFirst; 
    stcUartConfig.bInvertData = FALSE;
    stcUartConfig.bHwFlow = FALSE;
    stcUartConfig.bUseExtClk = FALSE;
    stcUartConfig.pstcFifoConfig = NULL;

    Mfs_Uart_Init(UartCh0, &stcUartConfig);
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
    
    /* Enable TX function of UART0 */
    Mfs_Uart_EnableFunc(UartCh0, UartTx);
    /* Enable RX function of UART1 */
    Mfs_Uart_EnableFunc(UartCh1, UartRx);
    
    while(u8Cnt < SAMPLE_UART_RX_BUFFSIZE)
    {
        while (TRUE != Mfs_Uart_GetStatus(UartCh0, UartTxEmpty)); /* wait until TX buffer empty */
        Mfs_Uart_SendData(UartCh0, au8UartTxBuf[u8Cnt]);  
        
        while(TRUE != Mfs_Uart_GetStatus(UartCh1, UartRxFull)); /* wait until RX buffer full */
        au8UartRxBuf[u8Cnt] = Mfs_Uart_ReceiveData(UartCh1);
        
        u8Cnt++;
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
