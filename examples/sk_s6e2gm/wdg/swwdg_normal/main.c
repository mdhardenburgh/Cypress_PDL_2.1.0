/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Example program for Software watchdog
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

/* Watchdog's clock value depends on SWC_PSR_Val in system header file */
#define WDG_LOAD_VALUE                                                   20000000UL

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t u32CountWdg = 0u;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/*******************************************************************************
* Function Name: PortInit
********************************************************************************
* GPIO Initialization
*******************************************************************************/
static void PortInit(void)
{
   Gpio1pin_InitOut(GPIO1PIN_P1A, Gpio1pin_InitVal(1u));
}

/*******************************************************************************
* Function Name: SetLed
********************************************************************************
* Set port for LED
*******************************************************************************/
static void SetLed(uint32_t u32Led)
{
    if (0 == (u32Led & 0x00000001))
    {
        Gpio1pin_Put(GPIO1PIN_P1A, 0u);
    }
    else
    {
        Gpio1pin_Put(GPIO1PIN_P1A, 1u);
    }
}

/*******************************************************************************
* Function Name: WdgSwCallback
********************************************************************************
* Software watchdog interrupt function. Interruption occurs if watchdog counter 
* reloads.
*******************************************************************************/
static void WdgSwCallback(void)
{
    /* Comment following to see software reset */
    Swwdg_Feed();   /* Clear Irq and Reset Timer */
    ++u32CountWdg;
    SetLed(u32CountWdg);
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
    stc_swwdg_config_t stcSwwdgConfig;
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcSwwdgConfig);
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
#endif

    /* Initialize GPIO for LED */
    PortInit();
    
    /* Initialize Software Watchdog */
    stcSwwdgConfig.u32LoadValue = WDG_LOAD_VALUE;     ///< Timer interval, note that software watchdog's clock is related with SWC_PSR_Val definition in system header file   
    stcSwwdgConfig.bResetEnable = TRUE;         ///< Enables SW watchdog reset
    stcSwwdgConfig.pfnSwwdgIrqCb = WdgSwCallback;
    if (Ok != Swwdg_Init((stc_swwdg_config_t *)&stcSwwdgConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error!\n");
#endif
    }
    else
    {
        /* Start Software watchdog */
        if (Ok == Swwdg_Start())
        {
#ifdef DEBUG_PRINT
            printf("Software Watchdog started\n");
#endif
        }else
        {
#ifdef DEBUG_PRINT
            printf("Error while starting Hardware Watchdog\n");
#endif
        }
    }

    /* Wait for interrupts */
    while(1)
    {
    }
}


/* [] END OF FILE */
