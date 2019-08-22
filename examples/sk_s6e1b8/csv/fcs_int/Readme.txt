================================================================================
                                      FCS interrupt sample project
================================================================================
version          1.10
================================================================================
Demonstrates the FCS interrupt function
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

Demonstrates the CSV reset when the main and the sub clock are irregular.
FCS: Anomalous Frequency Detection by Clock Supervisor.

================================================================================
How To Use This Code Example 

* Modify these macro definitions corresponding with the test board LED pin.
   #define Led_Init() Gpio1pin_InitOut(GPIO1PIN_P3D, Gpio1pin_InitDirectionOutput)
   #define Led_Off()  Gpio1pin_Put(GPIO1PIN_P3D, 1)
   #define Led_On()   Gpio1pin_Put(GPIO1PIN_P3D, 0)
* Start debug.
* Run the project.
* LED is off.
* Uncomment following code
   Csv_SetFcsDetectRange(ERR_FREQUENCY_LOWER_VAL, ERR_FREQUENCY_UPPER_VAL);
* Re-start debug.
* Run the project.
* LED blinks.

Note:
* The printf content can be output to the Terminal I/O window (Debug viewer) In IAR with semi-hosting 
  mode.
* The printf content can also be output to UART0 (SOT0_0).
  Do these steps to enable this method:
  - Set "PDL_PERIPHERAL_ENABLE_MFS0" and "PDL_UTILITY_ENABLE_UART_PRINTF" to 
  PDL_ON in pdl_user.h
  - Call "Uart_Io_Init()" at the beginning of the main function 
* Before using printf function, enable the definition "DEBUG_PRINT" in 
  pdl_user.h. When you want to program the code into Flash and run the code 
  standalone, disable the definition "DEBUG_PRINT" in pdl_user.h.
   
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
