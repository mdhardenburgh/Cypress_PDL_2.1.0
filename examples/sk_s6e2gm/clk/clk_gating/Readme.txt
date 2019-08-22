================================================================================
                               Clock example program
================================================================================
version          1.10
================================================================================
Demo peripheral clock enable/disable and peripheral reset with clock API
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
Description:

This example shows how to gate the clock of a peripheral, reset it,
and enable it again. The Base Timer BT0 is used as an example of the contolled 
peripheral.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Run the code.
* Observe with an oscilloscope connected to output TIOA0_0 how the clock of 
  a peripheral is gated, reset, and re-enabled.
   
Note:
* The printf content can be output to the Terminal I/O window (Debug viewer) in 
  IAR with semi-hosting mode.
* The printf content can also output to UART0 (SOT0_0).
  Make following steps to enable this method:
  - Set "PDL_PERIPHERAL_ENABLE_MFS0" and "PDL_UTILITY_ENABLE_UART_PRINTF" to 
  PDL_ON in the pdl_user.h.
  - Call "Uart_Io_Init()" at the beginning of the main function.
* Before using the printf function, enable the definition "DEBUG_PRINT" in 
  pdl_user.h. When you want to program the code into Flash and run the code 
  standalone, disable the definition "DEBUG_PRINT" in the pdl_user.h.

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit
* oscilloscope

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================