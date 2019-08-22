/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows the clock gating procedure
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

#if (PDL_MCU_CORE != PDL_FM4_CORE) && (PDL_MCU_CORE != PDL_FM0P_CORE)
#error Only FM4 and FM0+ device support clock gating function!
#endif

#define  PpgInitOutput()     SetPinFunc_TIOA0_0_OUT()

/*!
 ******************************************************************************
 ** \brief PPG trigger interrupt handler
 ******************************************************************************
 */
/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
/*! \brief Interrupt count value */
static uint32_t m_u32CntIntTrg;

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PpgUnderflowIrqHandler(void);
static void PpgTrigIrqHandler(void);
static void bt_ppg_init(void);

static void PpgTrigIrqHandler(void)
{
    m_u32CntIntTrg++;
}

static void PpgUnderflowIrqHandler(void)
{
    
}
void bt_ppg_init(void)
{
    stc_bt_ppg_config_t stcPpgConfig;
    stc_ppg_irq_en_t    stcIrqEn;
    stc_ppg_irq_cb_t    stcIrqCb;
    
    /* Set Basetimer IO port   */
    PpgInitOutput();
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcPpgConfig);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);
    
    /* Initialize interrupt */
    stcPpgConfig.pstcPpgIrqEn = &stcIrqEn;
    stcPpgConfig.pstcPpgIrqCb = &stcIrqCb;
    
    /* Initialize PPG timer */
    stcPpgConfig.enPres = PpgPres1Div4;  /* PPG clock = 5MHz @ PCLK = 20MHz */
    stcPpgConfig.enMode = PpgContinuous; 
    stcPpgConfig.enExtTrig = PpgExtTrigDisable;
    stcPpgConfig.enOutputMask = PpgOutputNormal;
    stcPpgConfig.enOutputPolarity = PpgPolarityLow;
    stcPpgConfig.enRestartEn = PpgRestartEnable;
    stcPpgConfig.pstcPpgIrqEn->bPpgTrigIrq = TRUE;
    stcPpgConfig.pstcPpgIrqEn->bPpgUnderflowIrq = TRUE;
    stcPpgConfig.pstcPpgIrqCb->pfnPpgTrigIrqCb = PpgTrigIrqHandler;
    stcPpgConfig.pstcPpgIrqCb->pfnPpgUnderflowIrqCb = PpgUnderflowIrqHandler;
    stcPpgConfig.bTouchNvic = TRUE;
    Bt_Ppg_Init(&BT0, &stcPpgConfig);
    
    /* Set cycle and duty value */
    Bt_Ppg_WriteLowWidthVal(&BT0, 499);   /* Cycle = (1+m)*PPG clock cycle = 100us */
    Bt_Ppg_WriteHighWidthVal(&BT0, 499);  /* Duty = (1+m)*PPG clock cycle = 100us */
          
    /* Enable count operatoin */
    Bt_Ppg_EnableCount(&BT0);
    
    /* Start triggered by software */
    Bt_Ppg_EnableSwTrig(&BT0);
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return int return value, if needed
 ******************************************************************************/
int main(void)
{
    bt_ppg_init();
    Clk_PeripheralClockDisable(ClkGateBt0123);                   /* Disable Clock of BT0 */ 
    bt_ppg_init();
    while (TRUE == Clk_PeripheralGetClockState(ClkGateBt0123))   
    {
		/* Wait for disable (== FALSE) */
	}
    
    Clk_PeripheralSetReset(ClkResetBt0123);                       /* Set BT0 to reset state */
    bt_ppg_init();
    Clk_PeripheralClearReset(ClkResetBt0123);                     /* Release BT0 from reset state */
    bt_ppg_init();
    Clk_PeripheralClockEnable(ClkGateBt0123);                    /* Enable Clock of BT0 */
    while (FALSE == Clk_PeripheralGetClockState(ClkGateBt0123))  
    {
		/* Wait for enable (== TRUE) */
	}
    bt_ppg_init();
    while(1)
    {
		/* your code */
	}
}

/* [] END OF FILE */

