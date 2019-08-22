/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            An example how to use I2C in master mode
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
#if !defined(SetPinFunc_SOT7_1) || !defined(SetPinFunc_SCK7_1)
#error SOT7_1 or SCK7_1 is not available on this product, please use other \
pins or channels and detele "me".
#endif

#define SAMPLE_I2C_MASTER_TX_BUFFSIZE   sizeof(au8I2cMasterTxBuf)/sizeof(char)
#define SAMPLE_I2C_MASTER_RX_BUFFSIZE   SAMPLE_I2C_MASTER_TX_BUFFSIZE

#define I2C_RET_OK                  0
#define I2C_RET_ERROR               1

#define I2C_DEV_ADDR              (0x3Au)
#define I2C_DEV_ADDR_W            ((I2C_DEV_ADDR << 1u) | 0u)
#define I2C_DEV_ADDR_R            ((I2C_DEV_ADDR << 1u) | 1u)

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
volatile stc_mfsn_i2c_t* I2cCh = &I2C7;
static uint8_t au8I2cMasterTxBuf[] = "0123456789";
static uint8_t au8I2cMasterRxBuf[SAMPLE_I2C_MASTER_RX_BUFFSIZE];

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
* Function Name: InitI2cMaster
********************************************************************************
* Initialize I2C Master
*******************************************************************************/
static void InitI2cMaster(void)
{
    stc_mfs_i2c_config_t stcI2cConfig;
        
    SetPinFunc_SOT7_1();
    SetPinFunc_SCK7_1();
    
    stcI2cConfig.enMsMode = I2cMaster;
    stcI2cConfig.u32BaudRate = 100000u;
    stcI2cConfig.bWaitSelection = FALSE;
    stcI2cConfig.bDmaEnable = FALSE;
    stcI2cConfig.pstcFifoConfig = NULL;
    
    Mfs_I2c_Init(I2cCh, &stcI2cConfig);
}

/*******************************************************************************
* Function Name: I2c_Start
********************************************************************************
* Config the start condition
*
* \param Addr   The Slave address
*
* \return I2C_RET_ERROR  The start condition not generated or Slave address wasn't
*                        appended by ACK                            
* \return I2C_RET_OK     The start condition generated, and the Slave address 
*                        match and ACK generated
*******************************************************************************/
static uint8_t I2c_Start(uint8_t Addr)
{
    /* Prepare I2C device address */
    Mfs_I2c_SendData(I2cCh, Addr);
    
    /* Generate I2C start signal */
    if(Ok != Mfs_I2c_GenerateStart(I2cCh))
    {
        return I2C_RET_ERROR; /* Timeout or other error */
    }

    while(1)
    {
        if(TRUE != Mfs_I2c_GetStatus(I2cCh, I2cRxTxIrq))
        {
            break;
        }
    }
   
    if(I2cNAck == Mfs_I2c_GetAck(I2cCh))
    {
        return I2C_RET_ERROR;   /* NACK */
    }
    
    if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cBusErr))
    {
        return I2C_RET_ERROR; /* Bus error occurs? */
    }
    
    if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cOverrunError))
    {
        return I2C_RET_ERROR; /* Overrun error occurs? */
    }
   
    return I2C_RET_OK;
}

/*******************************************************************************
* Function Name: I2c_Write
********************************************************************************
* Transmit the dedicated size data to device
*
* \param  pTxData Transmit data pointer
*
* \param  u8Size the number of transmitted data
*
* \return I2C_RET_ERROR  The error uccured during transmission
* \return I2C_RET_OK     The transmission is succesfully ended
*******************************************************************************/
static uint8_t I2c_Write(uint8_t *pTxData, uint8_t u8Size)
{
    uint8_t i;
    
    for(i=0; i<u8Size; i++)
    {
        /* Transmit the data */
        Mfs_I2c_SendData(I2cCh, pTxData[i]);
        Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
        
        /* Wait for end of transmission */
        while(1)
        {
            if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cRxTxIrq))
            {
                break;
            }
        }
        
        while(1)
        {
            if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cTxEmpty))
            {
                break;
            }
        }
       
        if(I2cNAck == Mfs_I2c_GetAck(I2cCh))
        {
            return I2C_RET_ERROR;   /* NACK */
        }
        
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cBusErr))
        {
            return I2C_RET_ERROR; /* Bus error occurs? */
        }
        
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cOverrunError))
        {
            return I2C_RET_ERROR; /* Overrun error occurs? */
        }
    }
    
    return I2C_RET_OK;
}

/*******************************************************************************
* Function Name: I2c_Read
********************************************************************************
* Receive the dedicated size data to device
*
* \param  pRxData The receive buffer pointer
*
* \param  u8Size The number of receiving data
*
* \return I2C_RET_ERROR  The error uccured during reception
* \return I2C_RET_OK     The reception is succesfully ended
*******************************************************************************/
static uint8_t I2c_Read(uint8_t *pRxData, uint8_t u8Size)
{
    uint8_t i = 0;
    
    /* Clear interrupt flag generated by device address send */
    Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
    
    if(I2cNAck == Mfs_I2c_GetAck(I2cCh))
    {
        return I2C_RET_ERROR;   /* NACK */
    }
    
    while(i < u8Size)
    {   
        /* Wait for the receive data */
        while(1)
        {
            if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cRxTxIrq))
            {
                break;
            }
        }
        
        if(i == u8Size-1)
        {
            Mfs_I2c_ConfigAck(I2cCh, I2cNAck); /* Last byte send a NACK */
        }
        else
        {
            Mfs_I2c_ConfigAck(I2cCh, I2cAck);
        }
        
        /* Clear interrupt flag and receive data to RX buffer */
        Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
        
        /* Wait for the receive data */
        while(1)
        {
            if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cRxFull))
            {
                break;
            }
        }
         
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cBusErr))
        {
            return I2C_RET_ERROR;   /* Bus error occurs? */
        }
        
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cOverrunError))
        {
            return I2C_RET_ERROR;  /* Overrun error occurs? */
        }
        
        pRxData[i++] = Mfs_I2c_ReceiveData(I2cCh);
    }
    return I2C_RET_OK;
}

/*******************************************************************************
* Function Name: I2c_Stop
********************************************************************************
* Config the stop condition
*
* \return I2C_RET_ERROR Stop condition is unsuccesfully generated
* \return I2C_RET_OK    Stop condition is succesfully generated
*******************************************************************************/
static uint8_t I2c_Stop(void)
{
    /* Generate I2C start signal */
    if(Ok != Mfs_I2c_GenerateStop(I2cCh))
    {
        return I2C_RET_ERROR; /* Timeout or other error */
    }
    /* Clear Stop condition flag */
    while(1)
    {
        if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cStopDetect))
        {
            break;
        }
    }
   
    if(TRUE == Mfs_I2c_GetStatus(I2cCh, I2cBusErr))
    {
        return I2C_RET_ERROR;
    }
   
    Mfs_I2c_ClrStatus(I2cCh, I2cStopDetect);
    Mfs_I2c_ClrStatus(I2cCh, I2cRxTxIrq);
    
    return I2C_RET_OK;
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
    InitI2cMaster();
    
    /* I2C Master Write data */
    I2c_Start(I2C_DEV_ADDR_W);
    I2c_Write(au8I2cMasterTxBuf, SAMPLE_I2C_MASTER_TX_BUFFSIZE);
    I2c_Stop();
    
    /* I2C Master Read data */
    I2c_Start(I2C_DEV_ADDR_R);
    I2c_Read(au8I2cMasterRxBuf, SAMPLE_I2C_MASTER_RX_BUFFSIZE);
    I2c_Stop();
            
    if(Ok != CompareData(au8I2cMasterTxBuf, au8I2cMasterRxBuf, SAMPLE_I2C_MASTER_TX_BUFFSIZE))
    {
        while(1)
        {
            /* Communication fails if code runs here. */           
        } 
    }
    
    while(1)
    {
        /* Data is normally sent and received */        
    } 
}


/* [] END OF FILE */
