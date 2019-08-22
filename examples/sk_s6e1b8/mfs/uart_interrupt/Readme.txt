================================================================================
                               UART example program
================================================================================
version          1.10
================================================================================
This example demonstrates the communication between UART0 and UART1
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

This example demonstrates communication between UART0 and UART1 with 
interrupt mode. 
The SOT0_1 should be connected with SIN1_2 before using this example.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Connect SOT0_1 with SIN1_2
* Run the code
* Check the TX buffer(au8UartTxBuf) and the RX buffer(au8UartRxBuf). 

================================================================================
Build Environment

This example works with
* FM0-100L-S6E1B8 Starter Kit

Project files are provided for
* ARM GCC v 4.9
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================