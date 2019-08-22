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

#if (PDL_MCU_CORE != PDL_FM0P_CORE)
#error "Only FM0+ supports fast GPIO function"
#endif

/**
 ******************************************************************************
 ** \brief  Uses GPIO to light an LED when an SW button is pressed.
 **
 ** \return int return value, if needed
 ** \note The optimization need to be enabled to achieve high IO polling speed
 ******************************************************************************/
int main(void)
{
    /* Initialize Port 0 Pin 8 to be an input pin, with resistive pull up.
    * P08 is connected to the onboard user switch button.
    */
    Gpio1pin_InitIn(GPIO1PIN_P08, Gpio1pin_InitPullup(1u));
    
    /* Enable Fast GPIO output mode on Port 3 Pin E
    *    F E D C B A 9 8 7 6 5 4 3 2 1 0
    * b' 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    *                                  |-> P3E
    */
    FGpio_EnableOutput(FGpioPort3, 0x4000u);

    /* Initialize Port 3 Pin E to be an output pin, with initial level high.
    * P3E controls green color of the onboard RGB LED.
    */     
    FGpio1pin_InitOut(FGPIO1PIN_P3E, FGpio1pin_InitVal(0xFFu));
    
    while(1)
    {
        /* Copy the state of the input pin to the output pin */
        FGpio1pin_Put(FGPIO1PIN_P3E, Gpio1pin_Get(GPIO1PIN_P08));
    }
}


/* [] END OF FILE */
