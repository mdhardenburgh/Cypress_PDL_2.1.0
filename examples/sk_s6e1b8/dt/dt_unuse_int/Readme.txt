===============================================================================================
                                   Dual timer sample
===============================================================================================
version          1.10
================================================================================
Sample program for the Dual Timer (not using interrupt)
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

This sample uses two dual timer channels. The mode of each channel is as follows.
Channel 0 : Interval mode
Channel 1 : One-shot mode
Interval time for channel 0 is 0.5 sec at first, then the interval time changes
to 1 sec.
The overflow time for channel 1 is 1 sec. This channel repeats 9 times.
The above time interval is calculated when PCLK = 80 MHz
================================================================================
How To Use This Code Example 

1) Rebuild and run the program.
2) Watch the Terminal I/O window (Debug viewer)
   If character doesn't be outputted to the Terminal I/O window (Debug viewer), DT is operating
   normally.
3) GPIO(user set in main.c) outputs HIGH after 0.5 second, then this port outputs HIGH and LOW for every
   second.(according to DT channel 0)

Note:
* The printf content can be output to UART0 (SOT0_0). This is enabled by the 
  DEBUG_PRINT definition in the pdl_user.h. You can disable the output to the 
  terminal by removing the DEBUG_PRINT definition from the pdl_user.h.

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
