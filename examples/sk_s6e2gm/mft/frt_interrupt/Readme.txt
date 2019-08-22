================================================================================
                              FRT example program
================================================================================
version          1.10
================================================================================
MFT FRT module running with interrupt mode
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

This example shows the MFT FRT module running with interrupt mode. This example first  
demonstrates how to access free run timer normal count mode with peak/zero match interrupt. Then 
it demonstrates the free run timer offset count mode (which is supported only by products after 
TYPE3 of FM4).

================================================================================
How To Use This Code Example 

* Rebuild this project 
* Set breakpoint at "while(1)"
* Run the code
* After code stops, check following variables in the watch window:
m_u32NormalCntPeakMatch: 10 (it indicates 10 peak match event occurs in normal mode)
m_u32NormalCntZeroMatch: 10 (it indicates 10 zero match event occurs in normal mode)

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit

Project files are provided for
* ARM GCC v 4.9
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================