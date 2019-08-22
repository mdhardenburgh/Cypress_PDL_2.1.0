================================================================================
                        Software watchdog example program
================================================================================
version          1.10
================================================================================
Sample program for the Software Watchdog (using window mode).
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

This example program demonstrates how to use Software Watchdog in window mode

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Run the code
* Set the break point on line 170 "while(1)".
* Open the watch window and register au8ErrorStatus to watch window.
* Start the program.
* Watch the Terminal I/O window (Debug viewer)
  If a character isn't output to the Terminal I/O window (Debug viewer),
  the Software Watchdog is operating normally.
* If the program stops at the break point, watch the au8ErrorStatus values on the watch 
  window.
  If the values of au8ErrorStatus as shown below, the window mode of the Software Watchdog 
  is operating normally.

  au8ErrorStatus[0] : 1
  au8ErrorStatus[1] : 0

Note:
* The printf content can be output to UART0 (SOT0_0). This is enabled by 
  DEBUG_PRINT definition in the pdl_user.h. You can disable the output to the 
  terminal by removing DEBUG_PRINT definition from the pdl_user.h. 
  
================================================================================
Terminal window setup

Establish a connection to the board using your preferred terminal software. Each 
terminal program has its own user interface. We assume you are familiar with how
to change settings. This code example requires these settings for the connection.
- Port: specify the serial port in use
- Baud rate: 115200
- Data: 8 bit
- Parity: none
- Stop bit: 1
- Flow control: none

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

This code example also requires
* terminal software (for example, Cypress Serial Port Viewer and Terminal)

================================================================================
