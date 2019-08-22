/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Example program for Hardware watchdog
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
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t u32CountWdg = 0u;

/*******************************************************************************
* Function Name: SetLed
********************************************************************************
* Set port for LED
*******************************************************************************/
static void SetLed(uint32_t u32Led)
{
    if (0 == (u32Led & 1u))
    {
        Gpio1pin_Put(GPIO1PIN_P3D, 0u);
    }
    else
    {
        Gpio1pin_Put(GPIO1PIN_P3D, 1u);
    }
}

/*******************************************************************************
* Function Name: WdgHwCallback
********************************************************************************
* Hardware watchdog interrupt function
*******************************************************************************/
static void WdgHwCallback(void)
{
    /* Comment following to demonstrate the hardware watchdog reset */
    Hwwdg_Feed(0x55u, 0xAAu);   /* Clear Irq and Reset Timer */
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
    stc_hwwdg_config_t stcHwwdgConfig;
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcHwwdgConfig);
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
#endif

    /* Initialize P3D to be an output pin, with inital level high. This is connected
    * to the on-board RGB LED.
    */
    Gpio1pin_InitOut(GPIO1PIN_P3D, Gpio1pin_InitVal(1u));
    
    /* Initialize structure */
    stcHwwdgConfig.u32LoadValue = 100000u;   /* Interval: 1s (@CLKLC:100kHz) */
    stcHwwdgConfig.bResetEnable = TRUE;      /* Enables Hardware watchdog reset */
    stcHwwdgConfig.pfnHwwdgIrqCb = WdgHwCallback;
    
    /* Initialize Hardware Watchdog */
    if (Ok != Hwwdg_Init(&stcHwwdgConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initialization error\n");
#endif
    }
    else
    {
        /* Start the Hardware Watchdog */
        if (Ok == Hwwdg_Start())
        {
#ifdef DEBUG_PRINT
            printf("Hardware Watchdog started\n");
#endif
        }else
        {
#ifdef DEBUG_PRINT
            printf("Error while starting Hardware Watchdog\n");
#endif
        }
    }
    
    while(1);
}


/* [] END OF FILE */
