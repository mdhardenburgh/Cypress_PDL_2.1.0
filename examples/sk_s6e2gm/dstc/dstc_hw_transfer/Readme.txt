===============================================================================================
                                      PDL DSTC project
===============================================================================================
version          1.10
================================================================================
This example shows how to use the DSTC for hardware transfer.
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

This example demonstrates the hardware tranfer of DSTC. The Base Timer interrupt is used to trigger
DSTC transferring.

An array for source data is filled with "random data" (au32SourceData[]).
A descriptor for HW transfer is set (stcDstcExample). Afterwards the DSTC 
transfer to the destination array (au32DestinationData) is triggered by the
base timer 0 interrupt in single-shot mode. The flag bDtscEndNotify 
indicates the end of the transfer. If there is no error 
(bDstcErrorFlasg == FALSE) the destination data is compared 
with the source data.

================================================================================
How To Use This Code Example 

* Rebuild and start debug.
* Run the project.
* Break, and check whether the code stops at "while(1)". Also check whether the data in the array of 
"au32SourceData" and "au32DestinationData" are same.

Note:
* The printf content can be output to the Terminal I/O window (Debug viewer) in IAR in semi-hosting 
  mode.
* The printf content can also be output to UART0 (SOT0_0).
  Do these steps to enable this method:
  - Set "PDL_PERIPHERAL_ENABLE_MFS0" and "PDL_UTILITY_ENABLE_UART_PRINTF" to 
  PDL_ON in pdl_user.h
  - Call "Uart_Io_Init()" at the beginning of the main function. 
* Before using the printf function, enable the definition "DEBUG_PRINT" in 
  pdl_user.h. When you want to program the code into Flash and run the code 
  standalone, disable the definition "DEBUG_PRINT" in pdl_user.h.

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit
* Regulated DC power supply (DC Power)

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================