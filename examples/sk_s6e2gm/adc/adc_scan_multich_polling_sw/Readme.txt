================================================================================
                               ADC example program
================================================================================
version          1.10
================================================================================
This example samples multi channels of ADC in polling mode
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
================================================================================
This example samples multi channels of ADC in polling mode. The ADC0 channel 1 
and channel 17 are set to single conversion mode. A software trigger starts the conversion. 
The function Adc_GetIrqFlag() is used for polling at the end of the conversion. The results 
of the ADC conversion print to the terminal I/O afterwards.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file.
* Build and download the example to the board.
* Connect regulated DC power supply: AN01 to V+ of the DC source, AVSS to 
  V- of the DC source. AN17 is connected to onboard phototransistor.
* Turn on the DC power.
* Run the code.
* Run the terminal with a speed of 115200 baud to observe I/O data.
* Check the output value in the terminal I/O to see whether it is equal to DC power settings and 
  illumination intensity of onboard phototransistor:
   the output value from 0~4096 maps to DC 0~3.3v.

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
* FM4-176L-S6E2GM Pioneer Kit
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
