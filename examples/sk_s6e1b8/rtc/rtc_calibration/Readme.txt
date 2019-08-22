================================================================================
                          RTC example program
================================================================================
version          1.10
================================================================================
This example demonstrates the RTC calibration function
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

In this example, the Real Time Clock is calibrated. 
The original 1 Hz signal divided by a subclock is output from SUBOUT_0, and the
CO signal which was calibrated with the frequency correction module is
output from RTCCO_2.
Then the RTC calibration value is changed in 20 steps.
A frequency tester with high accuracy can be used to monitor the output
change from RTCCO_2 when implementing the calibration function.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Set breakpoint at "if(u16CalVal > 20)"
* Run the code
* Watch the waveform from RTCCO_2 and SUBOUT_0
* Run the code again
* Watch the frequency change from RTCCO_2 with a frequency tester.

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
* terminal software (for example Cypress Serial Port Viewer and Terminal)

================================================================================