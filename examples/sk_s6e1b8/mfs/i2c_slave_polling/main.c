/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            An example how to use I2C in slave mode
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
#include "string.h"

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#if !defined(SetPinFunc_SOT7_1) || !defined(SetPinFunc_SCK7_1)
#error SOT7_1 or SCK7_1 is not available on this product, please use other pins \
or channels and detele "me".
#endif

#define SAMPLE_I2C_MASTER_TX_BUFFSIZE   sizeof(au8I2cSlaveTxBuf)/sizeof(char)
#define SAMPLE_I2C_MASTER_RX_BUFFSIZE   sizeof(au8O2cSlaveRxBuf)/sizeof(char)

#define I2C_RET_OK                  0
#define I2C_RET_ERROR               1

#define I2C_DEV_ADDR              (0x3Au)

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
volatile stc_mfsn_i2c_t* I2cCh = &I2C7;
static uint8_t au8I2cSlaveTxBuf[50];
static uint8_t au8I2cSlaveRxBuf[50];

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/*******************************************************************************
* Function Name: DelayTime
********************************************************************************
* Dummy delay
*
* \param u32Cnt Time count
*******************************************************************************/
void DelayTime(uint32_t u32Cnt)
{
   while(u32Cnt > 0)
   {
       --u32Cnt;
   }
}

/*******************************************************************************
* Function Name: InitI2cSlave
********************************************************************************
* Initialize I2C slave
*******************************************************************************/
void InitI2cSlave(void)
{
    stc_mfs_i2c_config_t stcI2cConfig;
    
    PDL_ZERO_STRUCT(stcI2cConfig);
    
    stcI2cConfig.enMsMode = I2cSlave;
    stcI2cConfig.u32BaudRate = 100000u;
    stcI2cConfig.u8SlaveAddr = I2C_DEV_ADDR;
    stcI2cConfig.u8SlaveMaskAddr = 0x7Fu;
    stcI2cConfig.bWaitSelection = FALSE;
    stcI2cConfig.bDmaEnable = FALSE;
    stcI2cConfig.pstcFifoConfig = NULL;

    Mfs_I2c_Init(I2cCh, &stcI2cConfig);
}

/*******************************************************************************
* Function Name: I2c_SlaveWriteData
********************************************************************************
* Transmit the dedicated size data to device
*
* \param  pu8TxData Transmit data pointer
*
* \param  pu32Size The number of transmitted data
*******************************************************************************/
void I2c_SlaveWriteData(uint8_t *pu8TxData, uint32_t *pu32Size)
{
    uint8_t i=0;
    while(1)
    {
        /* Transmit the data */
        Mfs_I2c_SendData(I2cCh, pu8TxData[i++]);
        Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
        
        /* Wait for end of transmission */
        while(1)
        {
            if(Mfs_I2c_GetStatus(I2cCh, I2cRxTxIrq) == TRUE)
            {
                break;
            }
        }
        
        while(1)
        {    
            if(Mfs_I2c_GetStatus(I2cCh, I2cTxEmpty) == TRUE)
            {
                break;
            }
        }
        
        if(Mfs_I2c_GetAck(I2cCh) == I2cAck)
        {
            /* continue to send */
        }
        else
        {
            /* Master tells that it is last data he wants to read, check the stop signal then */
            Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq); /* Release bus  */
            break;
        }
    }
    
    /* Check the stop condition */
    while(1)
    {
        if(Mfs_I2c_GetStatus(I2cCh, I2cStopDetect) == TRUE)
        {            
            Mfs_I2c_ClrStatus(I2cCh, I2cStopDetect);
            Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
            break;
        }
    }
    
    *pu32Size = i;
}

/*******************************************************************************
* Function Name: I2c_SlaveReadData
********************************************************************************
* Receive the dedicated size data to device
*
* \param  pu8RxData The receive buffer pointer
*
* \param  pu32Sizethe The number of receiving data
*
*******************************************************************************/
void I2c_SlaveReadData(uint8_t *pu8RxData, uint32_t *pu32Size)
{
    uint8_t i = 0;
    while(1)
    {
        /* Stop condition and NACK */
        if(Mfs_I2c_GetStatus(I2cCh, I2cStopDetect) == TRUE)
        {            
            Mfs_I2c_ClrStatus(I2cCh, I2cStopDetect);
            Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
            
            break;
        }
        
        /* Bus Error */
        if(Mfs_I2c_GetStatus(I2cCh, I2cBusErr) == TRUE)
        {
            Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
            break;
        }
        
        Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
                
        if(Mfs_I2c_GetStatus(I2cCh, I2cRxFull) == TRUE)
        {
            pu8RxData[i++] = Mfs_I2c_ReceiveData(I2cCh);
            Mfs_I2c_ConfigAck(I2cCh, I2cAck);
            Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
            
        }
    }
    
    *pu32Size = i;
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
    uint32_t WriteLength, ReadLength;
    
    /* GPIO Initialization */
    SetPinFunc_SOT7_1();
    SetPinFunc_SCK7_1();
    
    InitI2cSlave();
    
    while(1)
    {
        /* polling flag of first data */
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cDevAddrMatch))
        {
            if(i2c_slave_tx_master_rx == Mfs_I2c_GetDataDir(I2cCh))/* Tx */
            {
                DelayTime(10);
                I2c_SlaveWriteData(au8I2cSlaveTxBuf, &WriteLength);
            }
            else/* Rx */
            {
                I2c_SlaveReadData(au8I2cSlaveRxBuf,&ReadLength);
                memset(au8I2cSlaveTxBuf, 0, sizeof(au8I2cSlaveTxBuf));
                memcpy(au8I2cSlaveTxBuf, au8I2cSlaveRxBuf, ReadLength);
            }
        }
    }
}


/* [] END OF FILE */
