===============================================================================================
                               PWC timer example program
===============================================================================================
version          1.10
================================================================================
Demo PWC function of Base Timer by measuring a PWM wave.
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
  
This example demonstrates both the interrupt and polling access modes of the PWC timer. 
The PWM output is used as measured wave for the PWC timer. 
================================================================================
How To Use This Code Example 

* Connect P42 (TIOA2_0) with P11 (TIOB0_2).
* Rebuild and run the program.  
* Watch the Terminal I/O window (Debug viewer) and the PWM wave with an oscilloscope.

Note:
* The printf content can be output to UART0 (SOT0_0). This is enabled with the 
  DEBUG_PRINT definition in the pdl_user.h. You can disable the output to the 
  terminal by removing the DEBUG_PRINT definition from the pdl_user.h.

================================================================================
Terminal window setup

Establish a connection to the board using your preferred terminal software. Each 
terminal program has its own user interface. We assume you are familiar with how
to change settings. This code example requires these settings for the connection:
- Port: specify the serial port in use
- Baud rate: 115200
- Data: 8 bit
- Parity: none
- Stop bit: 1
- Flow control: none

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit
* Oscilloscope

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

This code example also requires
* terminal software (for example, Cypress Serial Port Viewer and Terminal)

================================================================================
