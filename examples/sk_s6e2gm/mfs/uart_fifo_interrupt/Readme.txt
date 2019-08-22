================================================================================
                               UART example program
================================================================================
version          1.10
================================================================================
Demo the communication between UART3 and UART9
================================================================================
Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
You may use this file only in accordance with the license, terms, conditions,
disclaimers, and limitations in the end user license agreement accompanying
the software package with which this file was provided.
CYPRESS PROVIDES THIS SOFTWARE "AS IS" AND MAKES NO WARRANTY
OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS SOFTWARE,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
PURPOSE.
================================================================================
Description

This example demonstrates communication between UART7 and UART6 with 
interrupt mode using FIFO. 
The SOT7_1 should be connected with SIN6_1 before using this example.

Attention:
* This example supports only the MFS equipped with FIFO.
* Change UART channel by modifying following:
   - The variable of "UartCh7" and "UartCh6"
   - The UART GPIO pin setting
   - Enable the used UART peripheral definitions in pdl_user.h
   
================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Connect SOT7_1 with SIN6_1
* Run the code
* Check the TX buffer(au8UartTxBuf) and RX buffer(au8UartRxBuf). 
   
================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit

Project files are provided for
* ARM GCC v 4.9
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================