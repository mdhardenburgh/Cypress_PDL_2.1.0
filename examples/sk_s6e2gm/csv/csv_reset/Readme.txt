================================================================================
                                      CSV reset sample project
================================================================================
version          1.10
================================================================================
Demonstrate the CSV reset function
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

================================================================================
How To Use This Code Example 

* Modify the below macro definition corresponding with the test board LED pin. 
* These pins are configured to work on FM4-176L-S6E2GM kit. 
   RED LED
   #define MainClockFailure_LedInit()   Gpio1pin_InitOut(GPIO1PIN_P1A, Gpio1pin_InitDirectionOutput)
   #define MainClockFailure_LedOn()     Gpio1pin_Put(GPIO1PIN_P1A, 0)
   #define MainClockFailure_LedOff()    Gpio1pin_Put(GPIO1PIN_P1A, 1)
   BLUE LED
   #define SubClockFailure_LedInit()    Gpio1pin_InitOut(GPIO1PIN_P18, Gpio1pin_InitDirectionOutput)
   #define SubClockFailure_LedOn()      Gpio1pin_Put(GPIO1PIN_P18, 0)
   #define SubClockFailure_LedOff()     Gpio1pin_Put(GPIO1PIN_P18, 1) 
   GREEN LED
   #define ClockOk_LedInit()   Gpio1pin_InitOut(GPIO1PIN_PB2, Gpio1pin_InitDirectionOutput)
   #define ClockOk_LedOn()     Gpio1pin_Put(GPIO1PIN_PB2, 0)
   #define ClockOk_LedOff()    Gpio1pin_Put(GPIO1PIN_PB2, 1)

* Start debug.
* Run the project.
* Green LED on.
* Short main clock oscillator pins X0 and X1 to simulate a main clock failure.
* Red LED is polling (indicates a CSV reset caused by a main clock frequency error).
* Press the reset key.
* Short sub clock oscillator pins X0A and X1A to simulate a sub clock failure.
* Blue LED is polling (indicates a CSV reset caused by a sub clock frequency error).

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