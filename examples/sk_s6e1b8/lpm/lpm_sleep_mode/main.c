/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates the work with the Main Module of 
*                   the Low Power consumption Mode peripheral block
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
    volatile uint32_t i;
    
    for(; u32Cnt; u32Cnt--)
    {
        for(i=1000; i != 0; i--)
        {
        }
    }
}

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
* Swith LED finction
*
* \param bLed The desired state of the LED. If bLed = 0 then the LED will turn on,
*             if bLed = 1 then the LED will turn off
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
* Function Name: ExIntCallback
********************************************************************************
* Interruption function callback function
*******************************************************************************/
static void ExIntCallback(void)
{
}

/*******************************************************************************
* Function Name: InitExtInt
********************************************************************************
* External interrupt initialization
*******************************************************************************/
static void InitExtInt(void)
{
    stc_exint_config_t stcExintConfig;
  
    SetPinFunc_INT00_0(0u); /* Pin Function: INT00_0 */

    /* Configure interrupt ch.0 */
    PDL_ZERO_STRUCT(stcExintConfig);
    
    stcExintConfig.abEnable[ExintInstanceIndexExint0] = 1u;
    stcExintConfig.aenLevel[ExintInstanceIndexExint0] = ExIntFallingEdge;
    stcExintConfig.apfnExintCallback[ExintInstanceIndexExint0] = ExIntCallback;
    
    stcExintConfig.bTouchNvic = TRUE;
       
    Exint_Init(&stcExintConfig);
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
    /* GPIO initialization */
    PortInit();

    /* Intialization if the  external interrupt */
    InitExtInt();

    while(1)
    {
        /* Turn on LED */
        SetLed(0); /*  MCU has been wakeup here !*/
        
        Delay(5000u);
        
        /* Turn off LED */
        SetLed(1);
        
        /* Enter sleep mode */
        Lpm_GoToStandByMode(StbSleepMode, TRUE);
    }
}


/* [] END OF FILE */
