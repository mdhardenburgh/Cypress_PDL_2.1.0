================================================================================
                      External Interrupt example project
================================================================================
version          1.10
================================================================================
This example configures two external interrupt channels with falling edge and 
rising edge detection
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

This example configures two external interrupt channels and demonstrates 
the external interrupt occurrence with valid falling and rising edge input.
It also demonstrates the NMI interrupt with a falling edge input in the NMIX pin.
INT06_0 input is set to falling edge and the dedicated callback function 
counts the events. 
INT08_1 input is set to rising edge and the dedicated callback function counts
the events.
The NMI callback function is set, and the NMIX pin is enabled. If a falling 
edge is detected on NMIX, the NMIX interrupt occurs.

================================================================================
How To Use This Code Example 

* Pull-up INT06_0 and NMIX, pull-down INT08_1.
* Run the project.
* Connect INT06_0 to GND.
* Check whether External Interrupt 0 occurs by watching the variable "u32ExtInt6Count"
* Connect INT08_1 to VCC.
* Check whether External Interrupt 3 occurs by watching the variable "u32ExtInt8Count"
* Connect NMIX to GND
* Check whether the NMI interrupt occurs by watching the variable "u32NmiCount"

Note:
* The printf content can be output to UART0 (SOT0_0). This is enabled by the 
  DEBUG_PRINT definition in the pdl_user.h. You can disable the output to the 
  terminal by removing the DEBUG_PRINT definition from the pdl_user.h.

================================================================================
Terminal window setup

Establish a connection to the board using your preferred terminal software. Each 
terminal program has its own user interface. We assume you are familiar with how
to change settings. This code example requires these settings for the connection.
- Port: specify the serial port in use
- Baud rate: 115200
- Data: 8 bit
- Parity: none
- Stop bit: 1
- Flow control: none

================================================================================
Build Environment

This example works with
* FM0-100L-S6E1B8 Starter Kit
* Regulated DC power supply (DC Power)

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

This code example also requires
* terminal software (for example, Cypress Serial Port Viewer and Terminal)

================================================================================
