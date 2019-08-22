/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates CSV reset when main and sub clock is abmornal
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

/* Initialize P1A */
#define MainClockFailure_LedInit()   Gpio1pin_InitOut(GPIO1PIN_P1A, Gpio1pin_InitDirectionOutput)
#define MainClockFailure_LedOn()     Gpio1pin_Put(GPIO1PIN_P1A, 0)
#define MainClockFailure_LedOff()    Gpio1pin_Put(GPIO1PIN_P1A, 1)

/* Initialize P18 */
#define SubClockFailure_LedInit()    Gpio1pin_InitOut(GPIO1PIN_P18, Gpio1pin_InitDirectionOutput)
#define SubClockFailure_LedOn()      Gpio1pin_Put(GPIO1PIN_P18, 0)
#define SubClockFailure_LedOff()     Gpio1pin_Put(GPIO1PIN_P18, 1)

/* Initialize PB2 */
#define ClockOk_LedInit()   Gpio1pin_InitOut(GPIO1PIN_PB2, Gpio1pin_InitDirectionOutput)
#define ClockOk_LedOn()     Gpio1pin_Put(GPIO1PIN_PB2, 0)
#define ClockOk_LedOff()    Gpio1pin_Put(GPIO1PIN_PB2, 1)

#define RESET_CSV_MASK         (0x0040)

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
    
    /* Initialize LEDs */
    MainClockFailure_LedInit(); 
    MainClockFailure_LedOff();
    SubClockFailure_LedInit(); 
    SubClockFailure_LedOff();
    ClockOk_LedInit();
    ClockOk_LedOn();

    Clk_EnableSubClock(TRUE);

    Csv_EnableMainCsv();
    Csv_EnableSubCsv();
    
    while(1)
    {  
        /* Read causes of resets, reading the register clears all bits */
        u16ResetCause = ResetCause(); 
        /* Check Clock Supervisor bit */
        if (u16ResetCause&RESET_CSV_MASK)
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
       
        /* Clock Failure Detection(CSV) reset is generated */    
        if (TRUE == bClockSupervisor)
        {    
            /* Main Clock Failure Detection(CSV) reset is generated.*/
            if (TRUE == stcCsvStatus.bCsvMainClockStatus) 
            { 
                ClockOk_LedOff();
                while(1)
                {
                    MainClockFailure_LedOff();
                    Delay(1);
                    MainClockFailure_LedOn();
                    Delay(1);
                }
            }
            
            /* Sub Clock Failure Detection(CSV) reset is generated */
            if (TRUE == stcCsvStatus.bCsvSubClockStatus)
            {
                ClockOk_LedOff();
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
