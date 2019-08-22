/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates enter RTC mode and wakeup from RTC 
*                   interrupt
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

#define VB_CLK_DIV_Val     0x4Eu

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
volatile uint8_t u8TimerIrqtFlag = 0;

/*******************************************************************************
* Function Name: PortInit
********************************************************************************
* GPIO Initialization
*******************************************************************************/
static void PortInit(void)
{
   Gpio1pin_InitOut(GPIO1PIN_P3F, Gpio1pin_InitVal(1u));
}

/*******************************************************************************
* Function Name: SetLed
********************************************************************************
* Set port for LED
*******************************************************************************/
static void SetLed(boolean_t bLed)
{
    if (0 == bLed)
    {
        Gpio1pin_Put(GPIO1PIN_P3F, 0);
    }
    else
    {
        Gpio1pin_Put(GPIO1PIN_P3F, 1);
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
* Configure and start RTC
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
    stcRtcTime.u8Second         = 0;                /* Second      : 00 */
    stcRtcTime.u8Minute         = 59;               /* Minutes     : 59 */
    stcRtcTime.u8Hour           = 23;               /* Hour        : 23 */
    stcRtcTime.u8Day            = 5;                /* Date        : 5th */
    stcRtcTime.u8DayOfWeek      = RtcMonday;        /* Week        : monday */   
    stcRtcTime.u8Month          = RtcJanuary;       /* Month       : January */
    stcRtcTime.u16Year          = 2015;             /* Year        : 2015 */
    
    /* Intialize RTC timer */
    stcRtcTimer.enMode = RtcTimerPeriod;
    stcRtcTimer.u32TimerCycle = 5; /* Generate interrupt every 5s */
    
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
    stcRtcConfig.u32ClkPrescaler = __CLKSO; /* sub clock */
#endif
    stcRtcConfig.pstcTimeDate = &stcRtcTime;
    stcRtcConfig.pstcTimer = &stcRtcTimer;
    stcRtcConfig.pstcIrqEn = &stcRtcEn;
    stcRtcConfig.pstcIrqCb = &stcRtcCb;  
    stcRtcConfig.bTouchNvic = TRUE;
    
    /* Initialize the RTC */
    Rtc_Init(&RTC0, &stcRtcConfig);
    
    /* Start RTC */
    Rtc_EnableFunc(&RTC0, RtcCount);
    
    /* Enable timer */
    Rtc_EnableFunc(&RTC0, RtcTimer);
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
    stc_vbat_config_t stcVbatConfig;
  
    Vbat_SetPinFunc_X0A_X1A();
    /* Configure Vbat domain */
    stcVbatConfig.u8ClkDiv = VB_CLK_DIV_Val;
    stcVbatConfig.bLinkSubClk = FALSE;
    stcVbatConfig.bVbatClkEn = TRUE;
    stcVbatConfig.enBoostCurrent = ClkStandard;
    stcVbatConfig.enClkBoostTime = ClkBoost125ms;
    stcVbatConfig.enSustainCurrent = ClkStandard;
    Vbat_Init(&stcVbatConfig);
    /* Enable sub clock */
    Clk_EnableSubClock(TRUE);
    
    PortInit();
    
    /* Turn off LED */
    SetLed(1);
    
    /* Configure and start RTC */
    InitRtc();

    while(1)
    {
        /* Enter to the RTC mode */
        Lpm_GoToStandByMode(StbRtcMode, TRUE);
        
        if(u8TimerIrqtFlag == TRUE) /* wakeup here! RTC interrupt flag is set in the callback function */
        {
            u8TimerIrqtFlag = FALSE;
            
            /* Turn on LED */
            SetLed(0);
            
            Rtc_ClrIrqFlag(&RTC0, RtcHalfSecondIrq);
            
            while(Rtc_GetIrqFlag(&RTC0, RtcHalfSecondIrq) != TRUE)
            {
                /* Wait 0.5s */
            }
            
            /* Turn off LED */
            SetLed(1);
            
            Rtc_ClrIrqFlag(&RTC0, RtcHalfSecondIrq);
            
            while(Rtc_GetIrqFlag(&RTC0, RtcHalfSecondIrq) != TRUE)
            {
                /* Wait 0.5s */
            }
        }
    }
}


/* [] END OF FILE */
