================================================================================
                  Low power consumption mode example program
================================================================================
version          1.10
================================================================================
This example demonstrates the Low Power 
Consumption mode peripheral block
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

This example demonstrates entering sleep mode and waking up from sleep 
mode with an external interrupt.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Connect INT00_1 with ullup resistance.
* Start debug.
* Stop debug (code has been programmed).
* Give the INT00_1 pin a low trigger. See the LED (P18) is on. (This indicates that 
  the MCU woke up.)
* After a little delay the LED will be switched off, and MCU will go into sleep mode
  again and will be ready for the next wakeup.


================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit

Project files are provided for
* ARM GCC v 4.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================