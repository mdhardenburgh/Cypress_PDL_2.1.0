/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Sample program for Dual Timer (using interrupt)
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
#if !defined(GPIO1PIN_PB2_INIT)
#error PB2 is not available in this MCU product, \
change to other re-location pin! Then delete "me" !
#endif

/* Define to load value for channel 0.5sec interval @ PCLK = 80MHz) */
#define COUNTS_FOR_500_MS                                                78125u

/* Define to load value for channel 1 sec interval @ PCLK = 80MHz) */
#define COUNTS_FOR_1_S                                                156250u

/* Define to load value for channel 2 sec interval @ PCLK = 80MHz) */
#define COUNTS_FOR_2_S                                                312500u

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t u32CountDt0;
static uint32_t u32CountDt1;

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief Initializatio GPIO
 **
 ******************************************************************************/
static void PortInit(void)
{
#if !defined(GPIO1PIN_PB2_INIT)
#error PB2 is not available in this MCU product, \
change to other re-location pin! Then delete "me" !
#endif
    Gpio1pin_InitOut(GPIO1PIN_PB2, Gpio1pin_InitVal(1u));
}

/**
 ******************************************************************************
 ** \brief Set port for LED1
 **
 ******************************************************************************/
static void SetLed0(uint32_t u32Led0)
{
    if (0 == (u32Led0 & 0x00000001))
    {
       Gpio1pin_Put(GPIO1PIN_PB2, 0u);
    }
    else
    {
       Gpio1pin_Put(GPIO1PIN_PB2, 1u);
    }
}

/**
 ******************************************************************************
 ** \brief Callback Function for DT channel 0
 **
 ******************************************************************************/
static void Dt0Callback(void)
{
    Dt_ClrIrqFlag(DtChannel0);    /* Clear Irq */
    u32CountDt0++;
    SetLed0(u32CountDt0);
}

/**
 ******************************************************************************
 ** \brief Callback Function for DT channel 1
 **
 ******************************************************************************/
static void Dt1Callback(void)
{
    Dt_ClrIrqFlag(DtChannel1);    /* Clear Irq */
    u32CountDt1++;
    /* Channel 1 repeats 9 times. */
    if (u32CountDt1 < 8)
    {
        Dt_WriteLoadVal(COUNTS_FOR_2_S, DtChannel1);
    }
}

/**
 ******************************************************************************
 ** \brief  Main function of project
 **
 ** \return int return value, if needed
 **
 ** This sample uses dual timer 2 channels. Mode of each channel is as follows.
 ** Channel 0 : Interval mode
 ** Channel 1 : One-shot mode
 ** Interval time for channel 0 is 0.5 sec at first, then interval time changes
 ** to 1 sec.
 ** Overflow time for channel 1 is 1sec. This channel repeats 9 times.
 **
 ** Above time interval is calculated when PCLK = 80MHz.
 **
 ******************************************************************************/
int main(void)
{
    stc_dt_channel_config_t stcDtChannelConfig0;
    stc_dt_channel_config_t stcDtChannelConfig1;
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcDtChannelConfig0);
    PDL_ZERO_STRUCT(stcDtChannelConfig1);
    
    /* Initialize GPOI */
    PortInit();
    
    /* Initialize configuration */
    stcDtChannelConfig0.u8Mode = DtPeriodic;
    stcDtChannelConfig0.u8PrescalerDiv = DtPrescalerDiv256;
    stcDtChannelConfig0.u8CounterSize = DtCounterSize32; 
    stcDtChannelConfig0.bIrqEnable = TRUE;
    stcDtChannelConfig0.pfnIrqCallback = Dt0Callback;
    stcDtChannelConfig0.bTouchNvic = TRUE;
    
    stcDtChannelConfig1.u8Mode = DtOneShot;
    stcDtChannelConfig1.u8PrescalerDiv = DtPrescalerDiv256;
    stcDtChannelConfig1.u8CounterSize = DtCounterSize32;
    stcDtChannelConfig1.bIrqEnable = TRUE;
    stcDtChannelConfig1.pfnIrqCallback = Dt1Callback;
    stcDtChannelConfig1.bTouchNvic = TRUE;

    /* Initialize interrupt counter */
    u32CountDt0 = 0;
    u32CountDt1 = 0;

    /* Initialize dual timer channel 0 */
    if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig0, DtChannel0))
    {
#ifdef DEBUG_PRINT
        Uart_Io_Init();
        printf("Initial error channel0!\n");
#endif
        while(1);
    }

    /* Initialize dual timer channel 1 */
    if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig1, DtChannel1))
    {
#ifdef DEBUG_PRINT
        printf("Initial error channel1!\n");
#endif
        while(1);
    }
    /* Write load value for channel 0 (0.5sec interval @ PCLK = 80MHz) */
    Dt_WriteLoadVal(COUNTS_FOR_500_MS, DtChannel0);
    /* Write background load value for channel 0 (0.5sec -> 1sec @ PCLK = 80MHz) */
    Dt_WriteBgLoadVal(COUNTS_FOR_1_S, DtChannel0);
    /* Start count for channel 0 */
    Dt_EnableCount(DtChannel0);

    /* Write load value for channel 1 (1sec until overflow @ PCLK = 80MHz) */
    Dt_WriteLoadVal(COUNTS_FOR_1_S, DtChannel1);
    /* Start count for channel 1 */
    Dt_EnableCount(DtChannel1);


    while(1);
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
