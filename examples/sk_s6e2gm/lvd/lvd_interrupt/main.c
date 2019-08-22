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
#if !defined(GPIO1PIN_P18_INIT)
#error P18 is not available in this product, please change to other pins and \
delete "me"!
#endif

#if (PDL_MCU_CORE == PDL_FM3_CORE) || (PDL_MCU_CORE == PDL_FM0P_CORE)
#define LVD_IRQ_VOLTAGE           Lvd0IrqDetectVoltage300                                        
#elif (PDL_MCU_CORE == PDL_FM4_CORE)
#if (PDL_MCU_TYPE == PDL_FM4_TYPE1) || (PDL_MCU_TYPE == PDL_FM4_TYPE2) || (PDL_MCU_TYPE == PDL_FM4_TYPE6)
#define LVD_IRQ_VOLTAGE           Lvd0IrqDetectVoltage300   
#else 
#define LVD_IRQ_VOLTAGE           Lvd0IrqDetectVoltage310   
#endif
#endif

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
volatile boolean_t bLowVoltageDetect;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/*******************************************************************************
* Function Name: LvdCallback0
********************************************************************************
* Interruption function when the LVD0 detected
*******************************************************************************/
static void LvdCallback(void)
{
    bLowVoltageDetect = 1;
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
    en_result_t enRet;
    stc_lvd_config_t stcLvdConfig;
    
    /* Initialize GPIO */
    Gpio1pin_InitOut(GPIO1PIN_P18, Gpio1pin_InitVal(1u));
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcLvdConfig);
    
    stcLvdConfig.enLvd0IrqDetectVoltage = LVD_IRQ_VOLTAGE;
    stcLvdConfig.pfnIrqCallback[0] = LvdCallback;
    
    enRet = Lvd_Init(&stcLvdConfig);
    
    if(Ok != enRet)
    {
        while(1);
    }
    
    /* Enable LVD interrupt detection */
    Lvd_EnableIrqDetect(0u);
    while(TRUE != Lvd_GetIrqOperationStatus(0u))
    {
    }
    
    while(1)
    {
        if(bLowVoltageDetect == TRUE)
        {
            bLowVoltageDetect = FALSE;
            Gpio1pin_Put(GPIO1PIN_P18, 0u);
        }
    }
}


/* [] END OF FILE */
