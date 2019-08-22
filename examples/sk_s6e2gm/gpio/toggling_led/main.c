/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to toggle an LED on a button press
*                   using GPIO.
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

/**
 ******************************************************************************
 ** \brief  Uses GPIO to light an LED when an SW button is pressed.
 **
 ** \return int return value, if needed
 ** \note The optimization need to be enabled to achieve high IO polling speed
 ******************************************************************************/
int main(void)
{
    /* Initialize Port 2 Pin 0 to be an input pin, with resistive pull up.
    * P20 is connected to the onboard user switch button.
    */
    Gpio1pin_InitIn(GPIO1PIN_P20, Gpio1pin_InitPullup(1u));
    
    /* Initialize Port B Pin 2 to be an output pin, with initial level high.
    * PB2 controls green color of the onboard RGB LED.
    */     
    Gpio1pin_InitOut(GPIO1PIN_PB2, Gpio1pin_InitVal(1u));
    
    while(1)
    {
        /* Copy the state of the input pin to the output pin */
        Gpio1pin_Put(GPIO1PIN_PB2, Gpio1pin_Get(GPIO1PIN_P20));
    }
}


/* [] END OF FILE */
