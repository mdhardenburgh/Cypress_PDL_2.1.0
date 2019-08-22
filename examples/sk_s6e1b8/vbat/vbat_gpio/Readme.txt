================================================================================
                          VBAT domain code example
================================================================================
version          1.10
================================================================================
This code example demonstrates how to work with VBAT port (P48, P49) 
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

This example configures pins P48 and P49 in the VBAT domain to GPIO, and
tests the output and input functions of them.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Run the code
* Watch the VBAT port (P48, P49) level change, when executing 
  the 'Vbat_PutPinPXX' function.
* Watch the bInputLevel value, after bringing the VBAT port (P48, P49) 
  high, when executing the 'Vbat_GetPinPXX' function. 
* Watch the bInputLevel value, after bringing the VBAT port (P48, P49) 
  low, when executing the 'Vbat_GetPinPXX' function.

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
