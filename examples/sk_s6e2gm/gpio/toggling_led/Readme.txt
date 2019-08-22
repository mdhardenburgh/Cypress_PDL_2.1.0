================================================================================
                               GPIO example program
================================================================================
version          1.10
================================================================================
This example shows how to toggle an LED on a button press using GPIO.
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

This example configures a pin to be the input pin with a resistor pull up.
This pin is connected to the SW2 switch on the FM4-176L-S6E2GM. Then it sets
a fast I/O to be the output pin that is connected to the green color component
of an RGB LED. In main() loop the code copies the state of the input pin to the
output pin. As a result, the LED is ON when the switch is pressed and OFF 
otherwise.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Run the code.
* Press the onboard switch to light an LED.

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit
* multimeter or oscilloscope

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================