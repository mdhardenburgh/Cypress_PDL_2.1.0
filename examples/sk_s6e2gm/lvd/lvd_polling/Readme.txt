================================================================================
                            LVD example program
================================================================================
version          1.10
================================================================================
Main Module for LVD sample (unuse interrupt)
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

Sample program for LVD (without interrupt).

================================================================================
How To Use This Code Example 

* GND and VCC connect between the board and DC power supply, then turn on.
  Voltage of the power supply is adjusted to more than 3.0 V
* Use the Debug build in the project file
* Build and download the example to the board
* Run the code
* Decrease voltage gradually. P18 turns to high when VCC is lower than 3.0 V.
 
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

This code example also requires
* regulated DC supply

================================================================================