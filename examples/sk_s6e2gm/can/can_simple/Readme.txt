================================================================================
                                  CAN sample program
================================================================================
version          1.10
================================================================================
This example tests the CAN data transfer and receive.
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
This test requires a configured and connected CAN-USB tool.
After Can_Init() sets the speed to 100 kbps, the code sets up the message buffer, 
then echoes the data received. 
 
If the CAN-USB tool sends the data frame with ID = 0x0A, the data echoes
back. Otherwise, the data frame is filtered.
 
================================================================================
How To Use This Code Example 

* Start debug and run the code
* Connect RX0_2 and TX0_2 to the CAN-H and CAN-L lines with the USB-CAN tool
* Open a CAN-USB tool and set the baud rate to 100 kbps
* Set the data frame in the CAN-USB tool with ID=0x0A and the data echoes back
* Set the data frame in the CAN-USB tool with other IDs and the data does not echo back
   
===============================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit
* CAN-USB tool

Project files are provided for
* ARM GCC v 5.0
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

===============================================================================