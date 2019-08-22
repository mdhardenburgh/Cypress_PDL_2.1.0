/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates printf function via UART0
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

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project for FM family.
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{   
    Uart_Io_Init();/* Initializatio of the UART unit and GPIO used in the communication */
  
    printf("Welcome to use Cypress PDL 2.1!\n");
    
    while(1)
    {
         /* Data is normally sent and received */        
    }
}


/* [] END OF FILE */
