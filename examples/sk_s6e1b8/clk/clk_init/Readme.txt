================================================================================
                               Clock example program
================================================================================
version          1.10
================================================================================
Demo clock setting with user configuration
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

This example shows how to use the system clock initialization PDL functions.
For this, the definition CLOCK_SETUP must be set to CLOCK_SETTING_NONE in 
system_FMx.h. First, the reset cause is determined, determining whether there is a 
system clock setup is needed. Afterwards, the main pll clock is set up with
a user configuration value.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Run the code.


Note:
* The printf content can be output to the Terminal I/O window (Debug viewer) in IAR with semi-hosting 
  mode.
* The printf content can also output to UART0 (SOT0_0).
  Follow these steps to enable this method:
  - Set "PDL_PERIPHERAL_ENABLE_MFS0" and "PDL_UTILITY_ENABLE_UART_PRINTF" to 
  PDL_ON in the pdl_user.h.
  - Call "Uart_Io_Init()" at the beginning of the main function.
* Before using the printf function, enable the definition "DEBUG_PRINT" in 
  the pdl_user.h. When you want to program the code into Flash and run the code 
  standalone, disable the definition "DEBUG_PRINT" in the pdl_user.h.

================================================================================
Build Environment

This example works with
* FM0-100L-S6E1B8 Starter Kit

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================
