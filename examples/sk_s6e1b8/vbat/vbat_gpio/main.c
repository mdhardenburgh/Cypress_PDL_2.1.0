/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This code example demonstrates how to work with VBAT port 
*                   (P48, P49)
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
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static boolean_t bInputLevel;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project for FM family.
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{
#if ((SCM_CTL_Val & 0x08) == 0x08)
    while (Ok != Clk_DisableSubClock())
    {
    }      
#endif
    
    stc_vbat_config_t stcVbatConfig;
    
    stcVbatConfig.u8ClkDiv = 0x6E;
    stcVbatConfig.bLinkSubClk = FALSE; /* Disconnect sub clock with clock control module */
    stcVbatConfig.bVbatClkEn = FALSE;  /* Stop sub clock supply to VBAT domain */
    stcVbatConfig.enSustainCurrent = ClkStandard;
    stcVbatConfig.enBoostCurrent = ClkStandard;
    stcVbatConfig.enClkBoostTime = ClkBoost50ms;
    
    while(Ok != Vbat_Init(&stcVbatConfig))
    {
    }
  
    /* Initialize P48,P49 to output with initial low */
    Vbat_InitGpioOutput(VbatGpioP48, 0u, FALSE);
    Vbat_InitGpioOutput(VbatGpioP49, 0u, FALSE);
    
    /* Set output level to high */
    Vbat_PutPinP48(1u);
    Vbat_PutPinP49(1u);
    
    /* Set output level to low */
    Vbat_PutPinP48(0u);
    Vbat_PutPinP49(0u);
    
    /* Initialize P48, P49 to input */
    Vbat_InitGpioInput(VbatGpioP48, TRUE);
    Vbat_InitGpioInput(VbatGpioP49, TRUE);
    
    /* Get input level */
    bInputLevel = Vbat_GetPinP48();
    if(bInputLevel == 1u)
    {
    }
    
    bInputLevel = Vbat_GetPinP49();
    if(bInputLevel == 1u)
    {
    }
  
    while(1)
    {
    }
}

/* [] END OF FILE */
