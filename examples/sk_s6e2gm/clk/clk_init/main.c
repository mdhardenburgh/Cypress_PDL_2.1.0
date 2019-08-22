/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use the system clock initialization
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

/**
 ******************************************************************************
 ** \brief  PDL clock initialization
 ******************************************************************************/
void Main_ClkInit(void)
{
  static stc_reset_result_t stcResetCause;
  stc_clk_config_t          stcClockConfig;

  Reset_GetCause(&stcResetCause);

    do
    {
        if (TRUE == stcResetCause.bSoftware)
        {
            /* Place code here */
        }

        if (TRUE == stcResetCause.bAnomalousFrequency)
        {
            /* Place code here */
            break;
        }

        if (TRUE == stcResetCause.bHardwareWatchdog)
        {
            /* Place code here */
            break;
        }

        if (TRUE == stcResetCause.bSoftwareWatchdog)
        {
            /* Place code here */
            break;
        }

        if (TRUE == stcResetCause.bInitx)
        {
            /* Place code here */
        }

        if (TRUE == stcResetCause.bPowerOn)
        {
            /* Place code here */
        }

        PDL_ZERO_STRUCT(stcClockConfig);

        stcClockConfig.enBaseClkDiv     = BaseClkDiv1;
        stcClockConfig.enAPB0Div        = Apb0Div1;
        stcClockConfig.enAPB1Div        = Apb1Div1;
        stcClockConfig.bAPB1Disable     = FALSE;
        stcClockConfig.enMCOWaitTime    = McoWaitExp117;
        stcClockConfig.enSCOWaitTime    = ScoWaitExp10;
        stcClockConfig.enPLLOWaitTime   = PlloWaitExp19;
        /* PLLCLK = Main Osc * (PLLN / PLLK), please refer to Clock chapter in peripehral manual for K, N, M value */
        stcClockConfig.u8PllK           = 1;
        stcClockConfig.u8PllN           = 10;
        stcClockConfig.u8PllM           = 2;

        /* Initialize clock */
        if(Ok != Clk_Init(&stcClockConfig))
        {
            while(1);
        }

        Clk_EnableMainClock(TRUE);                          /* ... now enable Main oscillator */
        Clk_EnablePllClock(TRUE);                           /* ... now enable PLL oscillator */

        Clk_SetSource(ClkPll);                              /* ... and transit to Main Clock */

    }while(0);
}

/**
 ******************************************************************************
 ** \brief  Main function of PDL
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int main(void)
{
  Main_ClkInit();

  while(1)
  {
	  /* your code */
  }
}


/* [] END OF FILE */
