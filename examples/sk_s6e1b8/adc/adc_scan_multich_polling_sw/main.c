/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            An example. How to use the ADC conversion in polling mode
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

#define ADC_INPUT_NUM       (2U)
#define ADC_INPUT_CH0       (0U)
#define ADC_INPUT_CH19      (19U)
#define ADC_INPUT_CH        ((1<<ADC_INPUT_CH0) | (1<<ADC_INPUT_CH19))

#define ADC_UNIT            (ADC0)

stc_adcn_t       *pstcAdc         = (stc_adcn_t *)&ADC_UNIT;
stc_adc_config_t stcConfig;
stc_adc_scan_t   stcScanCfg;


uint32_t         u32AdcValue      = 0;      /*  Result value */
uint32_t         u32AdcChannel    = 0;      /* Result channel */
uint32_t         u32AdcCause      = 0;

/**
 ******************************************************************************
 ** \brief  ADC0 initialization and single conversion setup
 ******************************************************************************/
void Main_adc_Init( void )
{
    /* Clear structures */
    PDL_ZERO_STRUCT(stcConfig);
    PDL_ZERO_STRUCT(stcScanCfg);

    /* Scan conversion configuration */
    stcScanCfg.u32ScanCannelSelect.u32AD_CHn = ADC_INPUT_CH;
    stcScanCfg.enScanMode = ScanSingleConversion;
    stcScanCfg.enScanTimerTrigger = AdcNoTimer;
    stcScanCfg.bScanTimerStartEnable = FALSE;
    stcScanCfg.u8ScanFifoDepth = ADC_INPUT_NUM - 1;     /* wait for 2 result */
    
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
    stcConfig.enSamplingTimeN1 = Value8;    /* STX setting multiplier 1: 8  */
    stcConfig.u8SamplingTime1 = 8u;         /* ST value 1 : 8 */
    stcConfig.u8ComparingClockDiv = 3u;     /* Frequency division ratio: 5, 0:Ratio 2, 1:Ratio 3, ... */
    stcConfig.pstcScanInit = &stcScanCfg;
#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("Start. Communication Initialized\n");
#endif
}
/**
 ******************************************************************************
 ** \brief  ADC0 single conversion polling
 ******************************************************************************/
void Main_adc_polling( void )
{
    uint32_t         u32Data          = 0;
    uint32_t         u32SamplingCount = 10;
    uint32_t         u32SamplingNum = 0;

    if (Ok == Adc_Init(pstcAdc, &stcConfig))            /* Init ADC0 */
    {
        Adc_EnableWaitReady(pstcAdc);                   /* Enable ADC0 and wait for ready */
    }
  
    while (u32SamplingCount-- > 0)
    {
        Adc_SwTriggerScan(pstcAdc);                     /* Trigger ADC0 */

        while (1)
        {
            if (TRUE == Adc_GetIrqFlag(pstcAdc, AdcScanIrq))
            {
                Adc_ClrIrqFlag(pstcAdc, AdcScanIrq);
                break;
            }
        }

        u32SamplingNum = ADC_INPUT_NUM;

        /*  resolve the FIFO data */
        while ( u32SamplingNum-- > 0 )
        {
            u32Data = Adc_ReadScanFifo(pstcAdc);
            if (0xFFFFFFFF == u32Data ||
                AdcFifoDataValid != Adc_GetScanDataValid(pstcAdc, u32Data))
            {
#ifdef DEBUG_PRINT
                printf("Invalid Record\n");
#endif
            }
            else
            {
                u32AdcChannel = Adc_GetScanChannel(pstcAdc, u32Data);
                u32AdcValue = Adc_GetScanData(pstcAdc, u32Data);
                u32AdcCause = Adc_GetScanDataCause(pstcAdc, u32Data);

#ifdef DEBUG_PRINT
                if (u32AdcChannel == ADC_INPUT_CH0) 
                {
                  printf("CH:%"PRIu32",val:%"PRIu32" ", u32AdcChannel, u32AdcValue);
                }
                else 
                {
                  printf("CH:%"PRIu32",val:%"PRIu32",R=%"PRIu32"\n", u32AdcChannel, u32AdcValue, u32AdcCause);
                }
#endif
            }
        }
    }

    Adc_DeInit(pstcAdc, TRUE);

    return;
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return int return value, if needed
 ******************************************************************************/
int main( void )
{
    Main_adc_Init();
    while (1)
    {
        Main_adc_polling();
    }
}


/* [] END OF FILE */
