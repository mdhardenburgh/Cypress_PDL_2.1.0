/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            External interrupt example.
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
   
uint32_t u32ExtInt6Count = 0, u32ExtInt8Count = 0;
uint32_t u32NmiCount = 0;

/**
 ******************************************************************************
 ** \brief Main_ExtInt6Callback callback function
 ******************************************************************************/
void Main_ExtInt6Callback(void)
{
    u32ExtInt6Count++;
}

/**
 ******************************************************************************
 ** \brief Main_ExtInt8Callback callback function
 ******************************************************************************/
void Main_ExtInt8Callback(void)
{
    u32ExtInt8Count++;
}

/**
 ******************************************************************************
 ** \brief NMI callback function
 ******************************************************************************/
void Main_NmiCallback(void)
{
    u32NmiCount++;
}

/**
 ******************************************************************************
 ** \brief  Main function of PDL
 **
 ** \return int return value, if needed
 ******************************************************************************/
int main(void)
{
    stc_exint_config_t stcExintConfig;
    stc_exint_nmi_config_t stcNmiConfig;

    /* The internal pull-up resistance can be connected for the external 
    interrupt pin with falling edge detection if necessary */
    /* E.g.: Gpio1pin_InitIn ( GPIO1PIN_Pxy, Gpio1pin_InitPullup(1u)); */

    SetPinFunc_INT06_1(0u);                       /* Pin Function: INT06_1 */
    SetPinFunc_INT08_0(0u);                       /* Pin Function: INT08_0 */

    /* Configure interrupt ch.6 and ch.8 */
    PDL_ZERO_STRUCT(stcExintConfig);
    
    /* Before initialize external interrupt ch.6, make sure 
    * PDL_PERIPHERAL_ENABLE_EXINT0 is set to PDL_ON in pdl_user.h
    * If external interrupt ch.6 is not used, set PDL_PERIPHERAL_ENABLE_EXINT6 
    * to PDL_OFF !! Otherwise, the external interrupt ch.6 may be mis-enabled. */
    stcExintConfig.abEnable[ExintInstanceIndexExint6] = 1u;
    stcExintConfig.aenLevel[ExintInstanceIndexExint6] = ExIntFallingEdge;
    stcExintConfig.apfnExintCallback[ExintInstanceIndexExint6] = Main_ExtInt6Callback;
    
    /* Before initialize external interrupt ch.8, make sure 
    * PDL_PERIPHERAL_ENABLE_EXINT3 is set to PDL_ON in pdl_user.h
    * If external interrupt ch.8 is not used, set PDL_PERIPHERAL_ENABLE_EXINT8 
    * to PDL_OFF !! Otherwise, the external interrupt ch.8 may be mis-enabled. */
    stcExintConfig.abEnable[ExintInstanceIndexExint8] = 1u;
    stcExintConfig.aenLevel[ExintInstanceIndexExint8] = ExIntRisingEdge;
    stcExintConfig.apfnExintCallback[ExintInstanceIndexExint8] = Main_ExtInt8Callback;
    
    stcExintConfig.bTouchNvic = TRUE;
       
    Exint_Init(&stcExintConfig);
    
    /* Congfigure NMI */
    PDL_ZERO_STRUCT(stcNmiConfig);
    stcNmiConfig.pfnNmiCallback = Main_NmiCallback;
    
    Exint_Nmi_Init(&stcNmiConfig);
    
    SetPinFunc_NMIX(0u);                      /* Pin Function: NMIX */
   
    while(1)
    {
        /* your code */
    }
}


/* [] END OF FILE */
