================================================================================
                               ADC example program
================================================================================
version          1.10
================================================================================
This example samples single channel of ADC in polling mode
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

This example sets the ADC0 channel 19 in single conversion mode and fetches
the result by using polling.
A software trigger starts the conversion. Adc_GetIrqFlag() is used
to check whether the conversion has completed.
When the conversion has completed, the result data prints to the terminal
I/O.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Run the code.
* Run a terminal with a speed of 115200 baud to observe I/O data.
* Check the output value in terminal I/O to see whether it is equal to potentiometer settings:
   the output value from 0~4095 maps to DC 0~3.3v.    
* Instead of AN19 that is connected to an onboard potentiometer, you can connect another input to the
  regulated DC power supply. For example, connect AN00 to V+ of the DC source, AVSS to
  V- of the DC source, and change the define in main.c from AN19 to AN00.

Note:
* The printf content can be output to UART0 (SOT0_0). This is enabled with the 
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