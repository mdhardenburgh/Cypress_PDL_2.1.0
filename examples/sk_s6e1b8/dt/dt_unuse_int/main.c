/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Sample program for Dual Timer (un-using interrupt).
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
#if !defined(GPIO1PIN_P3E_INIT)
#error P3E is not available in this MCU product, \
change to other re-location pin! Then delete "me" !
#endif
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
/* Configuration for channel 0 */
static const stc_dt_channel_config_t stcDtChannelConfig0 = {
    DtPeriodic,         /* Periodic mode */
    DtPrescalerDiv256,  /* Prescaler dividor f/256 */
    DtCounterSize32     /* 32bits counter size */
};

/* Configuration for channel 1 */
static const stc_dt_channel_config_t stcDtChannelConfig1 = {
    DtOneShot,          /* One-shot mode */
    DtPrescalerDiv256,  /* Prescaler dividor f/256 */
    DtCounterSize32     /* 32bits counter size */
};

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
#if !defined(GPIO1PIN_P3E_INIT)
#error P3E is not available in this MCU product, \
change to other re-location pin! Then delete "me" !
#endif
  Gpio1pin_InitOut(GPIO1PIN_P3E, Gpio1pin_InitVal(1u));
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
        Gpio1pin_Put(GPIO1PIN_P3E, 0u);
    }
    else
    {
        Gpio1pin_Put(GPIO1PIN_P3E, 1u);
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
 ** The above time interval is calculated when PCLK = 80MHz
 **
 ******************************************************************************/
int main(void)
{
    uint32_t u32CountDt0;
    uint32_t u32CountDt1;

    PortInit();

    /* Initialize dual timer channel 0 */
    if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig0, DtChannel0))
    {
#ifdef DEBUG_PRINT
        Uart_Io_Init();
        printf("Initial error channel 0!\n");
#endif
        while(1);
    }

    /* Initialize dual timer channel 1 */
    if (Ok != Dt_Init((stc_dt_channel_config_t*)&stcDtChannelConfig1, DtChannel1))
    {
#ifdef DEBUG_PRINT
        printf("Initial error channel 1!\n");
#endif
        while(1);
    }

    /* Initialize interrupt counter */
    u32CountDt0 = 0;
    u32CountDt1 = 0;

    /* Write load value for channel 0 (0.5sec interval @ PCLK=80MHz ) */
    Dt_WriteLoadVal(78125, DtChannel0);
    /* Write background load value for channel 0 (0.5sec -> 1sec @ PCLK=80MHz) */
    Dt_WriteBgLoadVal(156250, DtChannel0);
    /* Start count for channel 0 */
    Dt_EnableCount(DtChannel0);

    /* Write load value for channel 1 (1sec until overflow @ PCLK=80MHz) */
    Dt_WriteLoadVal(156250, DtChannel1);
    /* Start count for channel 1 */
    Dt_EnableCount(DtChannel1);

    while(1)
    {
        /* Check interrupt for channel 0 */
        if (TRUE == Dt_GetIrqFlag(DtChannel0))
        {
            Dt_ClrIrqFlag(DtChannel0);    /* Clear Irq */
            u32CountDt0++;
            SetLed0(u32CountDt0);
        }
        /* Check interrupt for channel 1 */
        if (TRUE == Dt_GetIrqFlag(DtChannel1))
        {
            Dt_ClrIrqFlag(DtChannel1);    /* Clear Irq */
            /* Channel 1 repeats 9 times. */
            if (u32CountDt1 < 8)
            {
                u32CountDt1++;
                Dt_WriteLoadVal(156250, DtChannel1);
            }
        }
    }
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
