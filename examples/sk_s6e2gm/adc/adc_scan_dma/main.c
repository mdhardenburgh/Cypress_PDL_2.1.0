/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use the ADC with DMA transfer.
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

#include "pdl_header.h"
#include <inttypes.h>

#define DMA_MAX_COUNT       (32u)
#define ADC_INPUT_NUM       (1)
#define ADC_INPUT_CH17      (17)
#define ADC_INPUT_CH        (1<<ADC_INPUT_CH17)
#define ADC_UNIT            (ADC0)
#define DMA_CH              (0)

/******************************************************************************/
/* Global variable                                                            */
/******************************************************************************/
boolean_t           bDmaFinished        = FALSE;          /* DMA finished notification flag */
uint32_t            au32DestinationData[DMA_MAX_COUNT];   /* Destination data */


/**
 ******************************************************************************
 ** \brief  DMA finish callback function
 ******************************************************************************/
void Main_dma_finish_callback( void )
{
    Adc_StopScanRepeat(&ADC_UNIT);  /* Stop ADC scan repeat conversion */

    bDmaFinished = TRUE;            /* Set DMA finished notification flag */
}

/**
 ******************************************************************************
 ** \brief  DMA configuration
 ******************************************************************************/
void Main_Dma_Config( void )
{
    stc_dma_config_t    stcConfigDma;
    stc_dma_irq_en_t stcIrqEn;
    stc_dma_irq_cb_t stcIrqCb;

    /* Clear local configuration structure to zero. */
    PDL_ZERO_STRUCT(stcConfigDma);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);

    /* Initialize interrupt structure */
    stcIrqEn.bCompleteIrq = TRUE;
    stcIrqCb.pfnDmaCompletionIrqCb = Main_dma_finish_callback;
    
    /* DMAC0 configuration */
    stcConfigDma.enDmaIdrq = Adc0;
    stcConfigDma.u8BlockCount = 1u;
    stcConfigDma.u16TransferCount = DMA_MAX_COUNT;
    stcConfigDma.enTransferMode = DmaDemandTransfer;
    stcConfigDma.enTransferWidth = Dma32Bit;
    stcConfigDma.u32SourceAddress = ADC0_SCAN_FIFO_ADDR;
    stcConfigDma.u32DestinationAddress = (uint32_t)&au32DestinationData[0u];
    stcConfigDma.bFixedSource = TRUE;
    stcConfigDma.bFixedDestination = FALSE;
    stcConfigDma.bReloadCount = FALSE;
    stcConfigDma.bReloadSource = FALSE;
    stcConfigDma.bReloadDestination = FALSE;
    stcConfigDma.bEnableBitMask = FALSE;
    stcConfigDma.pstcIrqEn = &stcIrqEn;
    stcConfigDma.pstcIrqCb = &stcIrqCb;
    stcConfigDma.bTouchNvic = TRUE;
    
    if (Ok == Dma_InitChannel(DMA_CH, &stcConfigDma))      /* Initialize DMA channel 0 */
    {
        Dma_Enable();            /* Overall enable of DMA */
        Dma_SetChannel(DMA_CH, TRUE, FALSE, FALSE);       /* Enable channel */
    }
}

/**
 ******************************************************************************
 ** \brief  Print ADC result data in the terminal window
 **
 ** \param [in] pData       Pointer to print data buffer.
 ** \param [in] u32cnt      data buffer size.
 **
 ** \retval
 **
 ******************************************************************************/
void PrintAdcData( uint32_t *pData, uint32_t u32cnt )
{
    stc_adcn_t *pstcAdc      = (stc_adcn_t *)&ADC_UNIT;
    uint16_t   i             = 0;
    uint32_t   u32AdcValue   = 0;
    uint32_t   u32AdcChannel = 0;
    uint8_t    u8AdcCause    = 0;
    uint32_t   u32Data       = 0;
    uint32_t   u32Times      = u32cnt;

    while (i < u32Times)
    {
        u32Data = *(pData + i);

        u32AdcChannel = Adc_GetPrioChannel(pstcAdc, u32Data);
        u32AdcValue = Adc_GetPrioData(pstcAdc, u32Data);
        u8AdcCause = Adc_GetPrioDataCause(pstcAdc, u32Data);

        if (TRUE == Adc_GetScanDataValid(pstcAdc, u32Data))
        {
#ifdef DEBUG_PRINT
            printf("%03d, CH:%"PRIu32",val:%"PRIu32",R=%"PRIu8"\n", i, u32AdcChannel, u32AdcValue, u8AdcCause);
#endif
        }
        else
        {
#ifdef DEBUG_PRINT
           printf("%"PRIu16": Invalid Record\n", i);
#endif
        }
        i++;
    }
#ifdef DEBUG_PRINT
           printf("..Finished\n");
#endif
    
}

/**
 ******************************************************************************
 ** \brief  ADC0 configuration
 ******************************************************************************/
void Main_Adc_Config( void )
{
    stc_adcn_t          *pstcAdc   = (stc_adcn_t *)&ADC_UNIT;
    stc_adc_irq_en_t    stcIrqEn;
    stc_adc_config_t    stcConfig;	
    stc_adc_scan_t      stcScanCfg;
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcConfig);
    PDL_ZERO_STRUCT(stcScanCfg);
    PDL_ZERO_STRUCT(stcIrqEn);
    
    /* Initialize configuration */
    stcIrqEn.bScanIrq = TRUE;
    
    /* Scan conversion configuration */
    stcScanCfg.u32ScanCannelSelect.u32AD_CHn = ADC_INPUT_CH;
    stcScanCfg.enScanMode = ScanRepeatConversion;
    stcScanCfg.enScanTimerTrigger = AdcNoTimer;
    stcScanCfg.bScanTimerStartEnable = FALSE;
    stcScanCfg.u8ScanFifoDepth = ADC_INPUT_NUM - 1;     /* wait 2 result */
    
/******************************************************************************
*      Common setting
*      Conversion time = Sampling time + Compare time
*      The sampling time should comply with a certain range to guarantee the 
*      accuracy (Tmin < Ts < Tmax).
*      For the value of Tmin and Tmax (e.g. 10us), see the product datasheet
*      for detail (12-bit A/D converter of Electrical Characteristics chapter)
******************************************************************************/
/******************************************************************************
*      For FM4 and FM0+, the calculation of sampling time and compare time is 
*      shown as following:
*      Sampling time = HCLK cycle * Frequency division ratio * {(ST set value +
*                                              1) * STX setting multiplier + 3}
*
*      At the following configuration:
*      Sampling time = 5ns * 5 * {(8+1)*8+3} = 1.875us (if HCLK = 200MHz)
*      Sampling time = 25ns * 5 * {(8+1)*8+3} = 9.375us (if HCLK = 40MHz)
*
*      Compare time = Compare clock cycle * 14 = Base clock (HCLK) cycle * 
+                                             Frequency division ratio * 14
*      At following configuration:
*      Compare time = 5ns * 5 * 14 = 350ns (if HCLK = 200MHz)
*      Compare time = 25ns * 5 * 14 = 1750ns (if HCLK = 40MHz)
******************************************************************************/
/******************************************************************************
*      For FM3, the calculation of sampling time and compare time is shown as 
*      following:
*      Sampling time = HCLK cycle * {(ST set value + 1) * STX setting multiplier + 3}
*      At the following configuration:
*      Sampling time = 7ns * {(8+1)*8+3} = 0.52us (if HCLK = 144MHz)
*****************************************************************************/
/****************************************************************************
*      Compare time = Compare clock cycle * 14 = Base clock (HCLK) cycle * 
*                                              Frequency division ratio * 14
*      At following configuration:
*      Compare time = 7ns * 5 * 14 = 490ns (if HCLK = 144MHz)
*****************************************************************************/ 
    stcConfig.bLsbAlignment = TRUE;
    stcConfig.u32SamplingTimeSelect.u32AD_CHn = 0;  
    stcConfig.enSamplingTimeN0 = Value8;    /* STX setting multiplier 0: 8 */
    stcConfig.u8SamplingTime0 = 8u;         /* ST value 0 : 8 */ 
    stcConfig.enSamplingTimeN1 = Value8;    /* STX setting multiplier 1: 8   */
    stcConfig.u8SamplingTime1 = 8u;         /* ST value 1 : 8 */
    stcConfig.u8ComparingClockDiv = 3u;     /* Frequency division ratio: 5, 0:Ratio 2, 1:Ratio 3, ... */
    stcConfig.pstcScanInit = &stcScanCfg;
    stcConfig.pstcIrqEn = &stcIrqEn;
    stcConfig.bTouchNvic = TRUE;
   
    if (Ok == Adc_Init(pstcAdc, &stcConfig))    /* Init ADC0 */
    {
        Adc_EnableWaitReady(pstcAdc);           /* Enable ADC0 and wait for ready */
        Adc_SwTriggerScan(pstcAdc);             /* Trigger ADC0 */
    }	
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return int return value, if needed
 ******************************************************************************/
int main( void )
{
    Main_Dma_Config();
    Main_Adc_Config();

#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("Started..\n");
#endif
    
    while (FALSE == bDmaFinished);      /* Wait for interrupt notification */

    PrintAdcData(au32DestinationData,
                 sizeof(au32DestinationData) / sizeof(au32DestinationData[0]));
    Adc_DeInit((stc_adcn_t *)&ADC_UNIT, TRUE);
    Dma_DeInitChannel(DMA_CH, TRUE);    
    
    while (1)
    {
      
    }
}


/* [] END OF FILE */
