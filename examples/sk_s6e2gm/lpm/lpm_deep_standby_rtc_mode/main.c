/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates the deep standby RTC mode, which 
*                   is wakeup from RTC by RTC timer interrupt every 30s.
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

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
volatile uint8_t u8TimerIrqtFlag = 0;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/*******************************************************************************
* Function Name: SetLed
********************************************************************************
*  Set port for LED
*******************************************************************************/
static void SetLed(boolean_t bLed)
{
    if (0 == bLed)
    {
        Gpio1pin_Put(GPIO1PIN_P18, 0);
    }
    else
    {
        Gpio1pin_Put(GPIO1PIN_P18, 1);
    }
}

/*******************************************************************************
* Function Name: SampleRtcTimerCb
********************************************************************************
* RTC Timer Interrupt callback function
*******************************************************************************/
static void SampleRtcTimerCb(void)
{
    /* Set timer interruption flag */
    u8TimerIrqtFlag = TRUE;
}

/*******************************************************************************
* Function Name: InitRtc
********************************************************************************
* \brief Configure and start RTC
*******************************************************************************/
static void InitRtc(void)
{   
    stc_rtc_config_t stcRtcConfig;
    stc_rtc_irq_en_t stcRtcEn;
    stc_rtc_irq_cb_t stcRtcCb;
    stc_rtc_time_t stcRtcTime;
    stc_rtc_timer_t stcRtcTimer;
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcRtcConfig);
    PDL_ZERO_STRUCT(stcRtcEn);
    PDL_ZERO_STRUCT(stcRtcCb);
    PDL_ZERO_STRUCT(stcRtcTime);
    PDL_ZERO_STRUCT(stcRtcTimer);
    
    /* Time setting (23:59:00 5th of January 2015) */
    stcRtcTime.u8Second         = 0;                            /* Second      : 00 */
    stcRtcTime.u8Minute         = 59;                           /* Minutes     : 59 */
    stcRtcTime.u8Hour           = 23;                           /* Hour        : 23 */
    stcRtcTime.u8Day            = 5;                            /* Date        : 5th */
    stcRtcTime.u8DayOfWeek      = RtcMonday;                    /* Week        : monday */
    stcRtcTime.u8Month          = RtcJanuary;                   /* Month       : January */
    stcRtcTime.u16Year          = 2015;                         /* Year        : 2015 */
    
    /* Intialize RTC timer */
    stcRtcTimer.enMode = RtcTimerPeriod;
    stcRtcTimer.u32TimerCycle = 30;                              /* Generate interrupt every 30s */
    
    /* Configure interrupt */
    stcRtcEn.bTimerIrq = TRUE;
    stcRtcCb.pfnTimerIrqCb = SampleRtcTimerCb;
    
    /* Clear seconds interrupt flag */
    u8TimerIrqtFlag = FALSE;

    /* Initialize RTC configuration */
    stcRtcConfig.bEnSuboutDivider = FALSE;
    stcRtcConfig.enRtccoSel = RtccoOutput1Hz;
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEA) || (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEB)    
    stcRtcConfig.enClkSel = RtcUseSubClk;
    stcRtcConfig.u32ClkPrescaler = __CLKSO;                      /* sub clock  */
#endif
    stcRtcConfig.pstcTimeDate = &stcRtcTime;
    stcRtcConfig.pstcTimer = &stcRtcTimer;
    stcRtcConfig.pstcIrqEn = &stcRtcEn;
    stcRtcConfig.pstcIrqCb = &stcRtcCb;  
    stcRtcConfig.bRunNotInit = TRUE; /* Don;t do the initialization again when RTC is already running */
    stcRtcConfig.bTouchNvic = TRUE;
    
    /* Initialize the RTC */
    Rtc_Init(&RTC0, &stcRtcConfig);
    
    /* Start RTC */
    Rtc_EnableFunc(&RTC0, RtcCount);
    
    /* Enable timer */
    Rtc_EnableFunc(&RTC0, RtcTimer);
}

/*******************************************************************************
* Function Name: Delay
********************************************************************************
* Time delay
*
* \param  Cnt Count value
*
* \return none
*******************************************************************************/
static void Delay(uint32_t Cnt)
{
    volatile uint32_t i;
    for(;Cnt;Cnt--)
        for(i=SystemCoreClock/2000;i;i--);
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
    volatile uint8_t i = 10;
    en_dstb_ret_cause_t enCause;
    stc_dstb_ret_cause_t stcCause;
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcCause);
    
    enCause = Lpm_ReadDeepStbRetCause();
    
    /* Enable the SUB, it is necessary for the RTC in this example */
    Clk_EnableSubClock(TRUE);
    
    /* Initialize LED IO  */
    Gpio1pin_InitOut(GPIO1PIN_P18, Gpio1pin_InitVal(1u));
   
    /* Initialize RTC */
    InitRtc();
    
    /* Set deep standby wakeup cause */
    stcCause.bRtcEn = 1u;
    Lpm_ConfigDeepStbRetCause(&stcCause);

    if (DeepStbWkupPin0 == enCause)
    {
       /* while(1); */
    }
    else if (DeepStbRtcInt == enCause)
    {
        /* while(1); */
    }

    while(1)
    {
        while(i--)
        {
           SetLed(0);
           Delay(100);
           SetLed(1);
           Delay(100);
        }
        
        Lpm_GoToStandByMode(DeepStbRtcMode, TRUE);
        
        i = 10;
    }
}


/* [] END OF FILE */