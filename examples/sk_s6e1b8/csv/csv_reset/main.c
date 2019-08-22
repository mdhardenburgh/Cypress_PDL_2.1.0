/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Demonstrates the Clock Supervisor (CSV) operation.
*                   The CSV monitors the main and sub clocks and generates a
*                   reset request when monitored clock fails.
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

/* Initialize P3D */
#define MainClockFailure_LedInit()   Gpio1pin_InitOut(GPIO1PIN_P3D, Gpio1pin_InitDirectionOutput)
#define MainClockFailure_LedOn()     Gpio1pin_Put(GPIO1PIN_P3D, 0)
#define MainClockFailure_LedOff()    Gpio1pin_Put(GPIO1PIN_P3D, 1)

/* Initialize P3E */
#define SubClockFailure_LedInit()    Gpio1pin_InitOut(GPIO1PIN_P3E, Gpio1pin_InitDirectionOutput)
#define SubClockFailure_LedOn()      Gpio1pin_Put(GPIO1PIN_P3E, 0)
#define SubClockFailure_LedOff()     Gpio1pin_Put(GPIO1PIN_P3E, 1)

#define RESET_CSV_MASK         (0x0040)
#define VB_CLK_DIV_Val          0x4Eu
/******************************************************************************/
/* Local Functions                                                            */
/******************************************************************************/
static void Delay(uint32_t Cnt);
static uint16_t ResetCause(void);

/*
 ******************************************************************************
 ** \brief Clock supervisor mode main function
 ******************************************************************************
 */
int main(void)
{   
    static uint16_t u16ResetCause = 0;
    static stc_csv_status_t stcCsvStatus ; 
    boolean_t bClockSupervisor = FALSE;
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
    
    /* Initialize LEDs */
    MainClockFailure_LedInit(); 
    MainClockFailure_LedOff();
    SubClockFailure_LedInit(); 
    SubClockFailure_LedOff();
    
    Clk_EnableSubClock(TRUE);

    Csv_EnableMainCsv();
    Csv_EnableSubCsv();
    
    while(1)
    {  
        /* Read reset cause. Reading the register clears all bits. */
        u16ResetCause = ResetCause();

        /* Check CSV bit */
        if (u16ResetCause & RESET_CSV_MASK)
        {
            Csv_DisableMainCsv();    
            Csv_DisableSubCsv();  
            bClockSupervisor = TRUE;
        }
        else
        {
            bClockSupervisor = FALSE;
        }
        
        /* Read CSV status */
        Csv_GetCsvFailCause(&stcCsvStatus);
       
        /* Clock failure detection reset has been generated */    
        if (TRUE == bClockSupervisor)
        {    
            /* Main clock failure detection reset has been generated.*/
            if (TRUE == stcCsvStatus.bCsvMainClockStatus) 
            { 
                while(1)
                {
                    MainClockFailure_LedOff();
                    Delay(1);
                    MainClockFailure_LedOn();
                    Delay(1);
                }
            }
            
            /* Sub clock failure detection reset has been generated */
            if (TRUE == stcCsvStatus.bCsvSubClockStatus)
            {  
                while(1)
                {
                    SubClockFailure_LedOff();
                    Delay(1);
                    SubClockFailure_LedOn();
                    Delay(1);
                }
            }
        } 
    }
}

/*
 ******************************************************************************
 ** \brief Time delay
 ******************************************************************************
 */
static void Delay(uint32_t u32Cnt)
{
    uint32_t u32i;
    for(; u32Cnt; u32Cnt--)
        for(u32i=SystemCoreClock/5; u32i; u32i--);
}

/*
 ******************************************************************************
 ** \brief Get reset cause
 ******************************************************************************
 */
static uint16_t ResetCause(void)
{
    uint16_t u16ResetCause = 0;
    
    u16ResetCause = FM_CRG->RST_STR; 
    return u16ResetCause; 
}


/* [] END OF FILE */
