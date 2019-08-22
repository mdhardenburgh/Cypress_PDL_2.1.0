/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Example program for Software Watchdog in window mode
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

/* Count frequency = PCLK0/(2^SWC_PSR). 
*  Time = WDG_LOAD_VALUE/Count frequency */
#define WDG_LOAD_VALUE                                            20000000UL

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#if (PDL_MCU_CORE != PDL_FM4_CORE) && (PDL_MCU_CORE != PDL_FM0P_CORE)
#error "Only FM4 and FM0+ products supports windows function of software watchdog!"
#endif

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static volatile uint8_t u8SwwdtActive;

/* Table to store status of window watchdog error */
static volatile uint8_t au8ErrorStatus[2] = {0, 0};

/* Timing table for reloading to watchdog timer */
/* Please use these values when debugging performs by flash and optimization is not used. */
static const volatile uint32_t au32CountValue[2]  = 
{
#if (__HCLK == 160000000)  
  #if defined (__ICCARM__)
    2285712,    /* Interruption will occur */
    22857139    /* Interruption will not occur */
  #else
    199998,     /* Interruption will occur */
    31999998    /* Interruption will not occur */
  #endif
#elif (__HCLK == 40000000)
#if defined (__ICCARM__)
     6908554,   /* Interruption will occur */
     16314278    /* Interruption will not occur */
#else
    2099980,   /* Interruption will occur */
   10099998    /* Interruption will not occur */
#endif
#else
#error "This example is related with MCU core clock. Understand the principle \
of this example, then establish the au32CountValue array by yourself! "          
#endif          
};

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/*******************************************************************************
* Function Name: WdgSwCallback
********************************************************************************
* Software watchdog interrupt function. 
*******************************************************************************/
static void WdgSwCallback(void)
{
    /* Stop software watchdog (*) */
    Swwdg_Stop();
  
    /* Clear interrupt */
    Swwdg_Feed();
	
    /* Software watchdog in-acitve */
    u8SwwdtActive = FALSE;

    /* (*)Software watchdog has to be stopped since interruption occurs,
       when interruption cause was cleared and watchdog counter was reloaded.*/
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
    volatile uint32_t u32Count;
    volatile uint8_t  u8Index;    
    stc_swwdg_config_t stcSwwdgConfig;
    
    PDL_ZERO_STRUCT(stcSwwdgConfig);
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
    printf("Started..\n");
#endif

    u8SwwdtActive = FALSE;
    /* Initialize Software watchdog */
    stcSwwdgConfig.u32LoadValue = WDG_LOAD_VALUE;    ///< WDG Timer interval   
    stcSwwdgConfig.bResetEnable = TRUE;        ///< Enables SW watchdog reset
    stcSwwdgConfig.bWinWdgEnable = TRUE;       ///< Disables Window watchdog mode  
    stcSwwdgConfig.bWinWdgResetEnable = FALSE;
    stcSwwdgConfig.u8TimingWindow = en_swwdg_timing_window_50;
    stcSwwdgConfig.pfnSwwdgIrqCb = WdgSwCallback;
    
    u8Index = 0;
    if (Ok != Swwdg_Init((stc_swwdg_config_t *)&stcSwwdgConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error!\n");
#endif
        while (1)
        {   
        }
    }

    u8Index = 0;
    while (2 > u8Index)
    {
        /* Restart software watchdog */
        Swwdg_Start();
        u8SwwdtActive = TRUE;
        /* Adjust the timing for reloading watchdog counter */
        u32Count = au32CountValue[u8Index];
        while (0 != (u32Count--))
        {
            continue;
        }
        __disable_irq();
        /* Clear interrupt and reload watchdog counter */
        Swwdg_Feed();
        __enable_irq();
        /* Insert cycle for interrupt */
        PDL_WAIT_LOOP_HOOK();
        /* If watchdog is in-active, error is occured */
        if (FALSE == u8SwwdtActive)
        {
            /* Error status set */
            au8ErrorStatus[u8Index] = 1;
        }
        u8Index++;
        __disable_irq();
        /* If watchdog is active */
        if (TRUE == u8SwwdtActive)
        {
            /* Stop software watchdog and clear interrupt */
            WdgSwCallback();
        }
        __enable_irq();
    }

    /* wait for interrupts */
    while(1)
    {
    }
}


/* [] END OF FILE */
