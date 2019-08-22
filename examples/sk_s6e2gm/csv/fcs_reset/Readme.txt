================================================================================
                                      FCS reset sample project
================================================================================
version          1.10
================================================================================
Demonstrate the FCS reset function
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

Demonstrate the Anomalous Frequency Detection (FCS) reset when the Main clock 
frequency is irregular.

================================================================================
How To Use This Code Example 

* Use the Release build in the project file.
* Build and download the example to the board.
* Run the program.
* LED is off.
* Uncomment following code
   Csv_SetFcsDetectRange(ERR_FREQUENCY_LOWER_VAL, ERR_FREQUENCY_UPPER_VAL);
* Rebuild and download the example to the board.
* Run the program.
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
