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

Demonstrates the Clock Supervisor (CSV) reset when the main and the sub clock 
are irregular. 
FCS: Anomalous Frequency Detection by Clock Supervisor. Within the specified period
between an edge and the next edge of the divided clock of high-speed CR, this 
function counts up the internal counter value using the main clock. If the count
value reaches out of the set window range, the function determines that the main
clock frequency is anomalous, and outputs an interrupt request to the CPU or 
a system reset request.

================================================================================
How To Use This Code Example 

* Modify these macro definitions corresponding with the test board LED pin.
   #define Led_Init() Gpio1pin_InitOut(GPIO1PIN_PB2, Gpio1pin_InitDirectionOutput)
   #define Led_Off()  Gpio1pin_Put(GPIO1PIN_PB2, 1)
   #define Led_On()   Gpio1pin_Put(GPIO1PIN_PB2, 0)
* Start debug.
* Run the project.
* LED is off.
* Uncomment following code
   Csv_SetFcsDetectRange(ERR_FREQUENCY_LOWER_VAL, ERR_FREQUENCY_UPPER_VAL);
* Re-start debug.
* Run the project.
* LED blinks.
  
================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================
