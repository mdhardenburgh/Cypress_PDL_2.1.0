================================================================================
                              LVD example program
================================================================================
version          1.10
================================================================================
This example program demonstrates the work of the LVD (using interrupt)
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

This is a sample program for LVD (using interrupt). To use this example, you need a 
regulated DC power supply. If you supply the MCU with a voltage lower than 
1.8 V, an LED will turn on. If the supply voltage is higher than 1.8 V,
the LED will turn off.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* GND and VCC connect between board and DC power supply, then turn on
  Voltage of the power supply is adjusted more than 3.0 V
* Rebuild and run the program
* Decrease voltage gradually. P3F turns high when VCC is lower than 2.7 V
  
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
* regulated DC supply

================================================================================
