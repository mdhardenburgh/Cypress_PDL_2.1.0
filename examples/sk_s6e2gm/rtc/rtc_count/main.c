/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates the calendar function of Real Time 
*                   Clock. Every second the time and date are read, and when the
*                   alarm occurs, a LED will start blinking.
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
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_rtc_time_t   stcTimeDate;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t u32IntHalfSec = 0;
static uint8_t  u8AlarmOccur = 0;
static uint8_t  u8IntSec = 0;
static uint8_t  u8BlinkFlag = 0;
static uint8_t  u8BlinkPolling = 1;

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
    Gpio1pin_InitOut(GPIO1PIN_P1A, Gpio1pin_InitVal(0u));
    Gpio1pin_Put(GPIO1PIN_P1A, u8BlinkPolling);
}

/*******************************************************************************
* Function Name: LedPolling
********************************************************************************
* Inverse LED state twice per second
*******************************************************************************/
static void LedPolling(void)
{
    if(u8BlinkFlag == 1)
    {
        if(u32IntHalfSec == 1)
        {
            Gpio1pin_Put(GPIO1PIN_P1A, u8BlinkPolling);
            u8BlinkPolling = ~u8BlinkPolling;
            u32IntHalfSec = 0;
        }
    }
}

/*******************************************************************************
* Function Name: SampleRtcAlarmCb
********************************************************************************
* Alarm Interrupt
*******************************************************************************/
static void SampleRtcAlarmCb(void)
{
    u8AlarmOccur = 1;
    u8BlinkFlag = 1;
}

/*******************************************************************************
* Function Name: SampleRtcHalfSecondCb
********************************************************************************
* Set 0.5-Second Interrupt flag
*******************************************************************************/
static void SampleRtcHalfSecondCb(void)
{
    u32IntHalfSec = 1;
}

/*******************************************************************************
* Function Name: SampleRtcOneSecondCb
********************************************************************************
* Set One Second Interrupt flag
*******************************************************************************/
static void SampleRtcOneSecondCb(void)
{
    u8IntSec = 1;
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
    stc_rtc_irq_en_t stcIrqEn;
    stc_rtc_irq_cb_t stcIrqCb;

    stc_rtc_alarm_t  stcAlarm;
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcRtcConfig);
    PDL_ZERO_STRUCT(stcTimeDate);
    PDL_ZERO_STRUCT(stcAlarm);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);
	
    /* Clear seconds interrupt flag */
    u8IntSec = FALSE;

    /* Time setting (23:59:00 1st of January 2014) */
    stcTimeDate.u8Second = 0;                    /* Second      : 00 */
    stcTimeDate.u8Minute = 59;                   /* Minutes     : 59 */
    stcTimeDate.u8Hour   = 23;                   /* Hour        : 23 */
    stcTimeDate.u8Day    = 30;                   /* Date        : 30th */
    stcTimeDate.u8Month  = RtcNovember;          /* Month       : November */
    stcTimeDate.u16Year   = 2014;                /* Year        : 2014 */
    (void)Rtc_SetDayOfWeek(&stcTimeDate);        /* Set Day of the Week in stcRtcTime */

    /* Alarm setting (00:00:00 1st of December 2014) */
    stcAlarm.u8Minute = 0;              /* Minutes : 00 */
    stcAlarm.u8Hour   = 0;              /* Hour    : 00 */
    stcAlarm.u8Day    = 1;              /* Date    : 1st */
    stcAlarm.u8Month  = RtcDecember;    /* Month   : December */
    stcAlarm.u16Year   = 2014;          /* Year    : 2014 */

    /* Initilialize interrupts */
    stcIrqEn.bHalfSecondIrq = 1u;
    stcIrqEn.bOneSecondIrq  = 1u;
    stcIrqEn.bAlarmIrq      = 1u;
    stcIrqCb.pfnHalfSecondIrqCb = SampleRtcHalfSecondCb;
    stcIrqCb.pfnOneSecondIrqCb  = SampleRtcOneSecondCb;
    stcIrqCb.pfnAlarmIrqCb      = SampleRtcAlarmCb;

    /* Set time, alarm and interrupt structure pointer */
#if (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEA) || (PDL_RTC_TYPE == PDL_RTC_WITHOUT_VBAT_TYPEB)         
    stcRtcConfig.enClkSel = RtcUseSubClk;
    stcRtcConfig.u32ClkPrescaler = 32768;
#endif    
    stcRtcConfig.pstcTimeDate = &stcTimeDate;
    stcRtcConfig.pstcAlarm = &stcAlarm;
    stcRtcConfig.pstcIrqEn = &stcIrqEn;
    stcRtcConfig.pstcIrqCb = &stcIrqCb;

    stcRtcConfig.bRunNotInit = FALSE; /* Don't initialize when RTC is running */
    stcRtcConfig.bTouchNvic = TRUE;

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
    /* Initialize GPIO for LED */
    PortInit();

    /* Enable the SUB, it is necessary for the RTC in this example */
    Clk_EnableSubClock(TRUE);
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
#endif

    /* Initialization of the RTC */
    InitRtc();

    /* Compare min,hour,day,month,year for Alarm */
    Rtc_EnableFunc(&RTC0, RtcAlarmMinEn);
    Rtc_EnableFunc(&RTC0, RtcAlarmHourEn);
    Rtc_EnableFunc(&RTC0, RtcAlarmDayEn);
    Rtc_EnableFunc(&RTC0, RtcAlarmMonthEn);
    Rtc_EnableFunc(&RTC0, RtcAlarmYearEn);

    /* Start RTC counting */
    Rtc_EnableFunc(&RTC0, RtcCount);

    while (1)
    {
        /* If one second interruption occurs */
        if (TRUE == u8IntSec)
        {
            u8IntSec = FALSE;
            Rtc_ReadDateTime(&RTC0, &stcTimeDate);
        #ifdef DEBUG_PRINT
            /* Print RTC to console */
            printf("%04d/%02d/%02d %02d:%02d:%02d ",
                   stcTimeDate.u16Year,
                   stcTimeDate.u8Month,
                   stcTimeDate.u8Day,
                   stcTimeDate.u8Hour,
                   stcTimeDate.u8Minute,
                   stcTimeDate.u8Second);
            switch (stcTimeDate.u8DayOfWeek)
            {
                case RtcSunday:
                    printf("Sunday\n");
                    break;
                case RtcMonday:
                    printf("Monday\n");
                    break;
                case RtcTuesday:
                    printf("Tuesday\n");
                    break;
                case RtcWednesday:
                    printf("Wednesday\n");
                    break;
                case RtcThursday:
                    printf("Thursday\n");
                    break;
                case RtcFriday:
                    printf("Friday\n");
                    break;
                case RtcSaturday:
                    printf("Saturday\n");
                    break;
                default:
                    break;
            }
        #endif
        }

        if(u8AlarmOccur == 1)
        {
            u8AlarmOccur = 0;
        #ifdef DEBUG_PRINT
            printf("Alarm occurs!\n");
        #endif

            /* Change time */
            stcTimeDate.u8Second = 0;                    /* Second  : 00 */
            stcTimeDate.u8Minute = 30;                   /* Minutes : 30 */
            stcTimeDate.u8Hour   = 9;                    /* Hour    : 9 */

            Rtc_SetDateTime(&RTC0, &stcTimeDate, TRUE, TRUE, FALSE);

        #ifdef DEBUG_PRINT
            printf("New time is set\n");
        #endif
        }

        LedPolling();
    }
}


/* [] END OF FILE */
