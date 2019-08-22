/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example program demonstrates the work of the LVD 
*                   (using interrupt)
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
#if (PDL_MCU_TYPE != PDL_FM0P_TYPE2)
#error This example only supports FM0+ type2 products!
#endif

#if !defined(GPIO1PIN_P3F_INIT)
#error P3F is not available in this product, please change to other pins and \
delete "me"!
#endif

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
boolean_t bLvd0Detect, bLvd1Detect;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/*******************************************************************************
* Function Name: LvdCallback0
********************************************************************************
* Interruption function when the LVD0 detected
*******************************************************************************/
static void LvdCallback0(void)
{
    bLvd0Detect = 1;
}

/*******************************************************************************
* Function Name: LvdCallback1
********************************************************************************
* Interruption function when the LVD1 detected
*******************************************************************************/
static void LvdCallback1(void)
{
    bLvd1Detect = 1;
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
    stc_lvd_config_t stcLvdConfig;
    
    /* Initialize GPIO */
    Gpio1pin_InitOut(GPIO1PIN_P3F, Gpio1pin_InitVal(1u));
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcLvdConfig);
    
    /* Configure LVD ch.0 */
    stcLvdConfig.enLvd0IrqDetectVoltage = Lvd0IrqDetectVoltage270;
    stcLvdConfig.enLvd0IrqReleaseVoltage = Lvd0IrqReleaseVoltage300;
    stcLvdConfig.bLvd0ReleaseVoltageEnable = TRUE;
    stcLvdConfig.pfnIrqCallback[0] = LvdCallback0;
    
    /* Configure LVD ch.1 */
    stcLvdConfig.enLvd1IrqDetectVoltage = Lvd1IrqDetectVoltage180;
    stcLvdConfig.enLvd1IrqReleaseVoltage = Lvd1IrqReleaseVoltage200;
    stcLvdConfig.bLvd1ReleaseVoltageEnable = TRUE;
    stcLvdConfig.pfnIrqCallback[1] = LvdCallback1;
    
    while(Ok != Lvd_Init(&stcLvdConfig))
    {
    }
    
    /* Enable LVD ch.0 interrupt detection */
    Lvd_EnableIrqDetect(0u);
    while(TRUE != Lvd_GetIrqOperationStatus(0u))
    {
    }
    
    /* Enable LVD ch.1 interrupt detection */
    Lvd_EnableIrqDetect(1u);
    while(TRUE != Lvd_GetIrqOperationStatus(1u))
    {   
    }
    
    while(1)
    {
        if(bLvd0Detect == TRUE)
        {
            bLvd0Detect = FALSE;
            Gpio1pin_Put(GPIO1PIN_P3F, 0u);
        }
        
        if(bLvd1Detect == TRUE)
        {
            bLvd1Detect = FALSE;
            Gpio1pin_Put(GPIO1PIN_P3F, 1u);
        }
    }
}


/* [] END OF FILE */
