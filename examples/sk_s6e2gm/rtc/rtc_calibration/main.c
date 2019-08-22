/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates the RTC calibration function
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
#if !defined(SetPinFunc_RTCCO_1) || !defined(SetPinFunc_SUBOUT_0)
#error "RTCCO_1, and SUBOUT_0 are used in this example, if these pins are not available, \
change to other pins!"
#endif

#if (PDL_RTC_TYPE != PDL_RTC_WITHOUT_VBAT_TYPEA)  /* FM0+/FM4/FM3 other types */
/*******************************************************************************
* As the calibration module can only slow the sub clock frequency by masking the
* clock pulses, always set the prescaler less than 32768
*******************************************************************************/
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEB)
#define RTC_CLOCK_PRES                  32760  /* FM4 and FM0+ TYPE2 fixed to 32768 */
#endif
/*******************************************************************************
* Set the calibration cycle to 20s
*******************************************************************************/
#define RTC_CLOCK_CALIBRATION_CYCLE     20
/*******************************************************************************
*  Assume standard frequency of subclock is 32768Hz, the actual minimum
*  frequency of sub clock is 32760Hz. So the deviation is
* (32768-32760)/32760 = 244.2ppm
* To calibrate 1 step can regulate 1.526ppm, if the calibraiton cycle is 20s
* 1/32768*20 = 1.526ppm
* The initial calibration step count is 160
* 244.2/1.526 = 160 steps
*******************************************************************************/
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEB)
#define RTC_CAL_CENTER_VAL              160
#else
#define RTC_CAL_CENTER_VAL              0
#endif
#else                                                        /* FM3 TYPE3,4,5 */
/*******************************************************************************
* As the calibration module can only slow the sub clock frequency by masking the
* clock pulses, always set the prescaler less than 32768
*******************************************************************************/
#define RTC_CLOCK_PRES                  32766
/*******************************************************************************
*  Assume standard frequency of subclock is 32768Hz, the actual minimum
*  frequency of sub clock is 32766Hz. So the deviation is
* (32768-32766)/32766 = 61ppm
* To calibrate 1 step can regulate 0.954ppm, if the calibraiton cycle is 32s
* 1/32768*32 = 0.954ppm
* The initial calibration step count is 64
* 61/0.954 = 64 steps
*******************************************************************************/
#define RTC_CAL_CENTER_VAL              64
#endif

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/*******************************************************************************
* Function Name: Delay
********************************************************************************
* Time delay function
*
* \param u32Cnt Number of cycles to wait
*******************************************************************************/
static void Delay(uint32_t u32Cnt)
{
    uint32_t i;
    
    for(; u32Cnt; u32Cnt--)
    {
        for(i=1000; i != 0; i--)
        {
            
        }
    }
}

/*******************************************************************************
* Function Name: InitRtc
********************************************************************************
* Initialize RTC
*******************************************************************************/
static void InitRtc(void)
{
    en_result_t enResult;
    stc_rtc_config_t stcRtcConfig;
    stc_rtc_freq_corr_t stcFreqCorrConfig;
    stc_rtc_time_t stcTimeDate;

    /* Clear structures */
    PDL_ZERO_STRUCT(stcRtcConfig);
    PDL_ZERO_STRUCT(stcFreqCorrConfig);
    PDL_ZERO_STRUCT(stcTimeDate);

    /* Initialize RTCCO */
    SetPinFunc_RTCCO_1();
    stcRtcConfig.enRtccoSel = RtccoOutput1Hz;

    /* Initialize SUBOUT */
    SetPinFunc_SUBOUT_0();
    stcRtcConfig.bEnSuboutDivider = TRUE;
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEA)    
    stcRtcConfig.enDividerRatio = RtcDivRatio512;
#else
    stcRtcConfig.enDividerRatio = RtcDivRatio32768;
#endif    
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEA) || (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEB)  /* FM3, FM0+ TYPE1 has clock prescaler */
    stcRtcConfig.u32ClkPrescaler = RTC_CLOCK_PRES;
#endif
    /* Frequency correction setting */
    stcFreqCorrConfig.u16FreqCorrValue = RTC_CAL_CENTER_VAL;
#if (PDL_RTC_TYPE != PDL_RTC_WITHOUT_VBAT_TYPEA)  /* FM3 TYPE3,4,5 has fixed calibration cycle */
    stcFreqCorrConfig.u16FreqCorrCycle = RTC_CLOCK_CALIBRATION_CYCLE;
#endif
    /* Time setting (23:59:00 31st of December 2014) */
    stcTimeDate.u8Second = 0;                    /* Second      : 00 */
    stcTimeDate.u8Minute = 59;                   /* Minutes     : 59 */
    stcTimeDate.u8Hour   = 23;                   /* Hour        : 23 */
    stcTimeDate.u8Day    = 30;                   /* Date        : 30th */
    stcTimeDate.u8Month  = RtcDecember;          /* Month       : December */
    stcTimeDate.u16Year   = 2014;                /* Year        : 2014 */
    (void)Rtc_SetDayOfWeek(&stcTimeDate);        /* Set Day of the Week in stcRtcTime */

    /* Set frequency correction, time pointer */
    stcRtcConfig.pstcFreqCorrConfig = &stcFreqCorrConfig;
    stcRtcConfig.pstcTimeDate = &stcTimeDate;

    /* Initialize the RTC */
    enResult = Rtc_Init(&RTC0, &stcRtcConfig);

    if (Ok != enResult)
    {
#ifdef DEBUG_PRINT
        printf("Initial error!\n");
#endif
        while(1)
        {
            
        }
    }

    /* Start RTC cunting */
    Rtc_EnableFunc(&RTC0, RtcCount);
 
    /* Start calibration */
    Rtc_EnableFunc(&RTC0, RtcFreqCorr);
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
    uint16_t u16CalVal;

    /* Enable the SUB, it is necessary for the RTC in this example */
    Clk_EnableSubClock(TRUE);
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
#endif
    
#ifdef DEBUG_PRINT
    printf("***********************************************************\n");
    printf("*   RTC Calibration test                                  *\n");
    printf("*   Output 1Hz signal (before calibration) from SUBOUT_0  *\n");
    printf("*   Output 1Hz signal (after calibration) from RTCCO_1    *\n");
    printf("***********************************************************\n");
#endif

    /* Configure RTC */
    InitRtc();

    u16CalVal = RTC_CAL_CENTER_VAL;

    Rtc_SetFreqCorrValue(&RTC0, u16CalVal);

    Delay(1000);

    if(u16CalVal > 20)
    {
        Rtc_SetFreqCorrValue(&RTC0, (u16CalVal - 20));
    }
    else
    {
        Rtc_SetFreqCorrValue(&RTC0, (u16CalVal + 20));
    }

    while(1)
    {
    }
}


/* [] END OF FILE */
