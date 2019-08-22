================================================================================
                  Low power consumption mode sample project
================================================================================
version          1.10
================================================================================
This example demonstrates enter deep standby RTC mode and wakeup from RTC interrupt
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

This example demonstrates the deep standby RTC mode, which is wakened from
the RTC by the RTC timer interrupt every 30 s. 
You can see that the MCU is in normal run mode when the LED (P3F) is blinking. 
The LED turns off when the MCU enters deep standby RTC mode. 
Please note that wakeup from WKUP0 is always enabled. The wakeup
event is triggered by inputting low to WKUP0. WKUP0 must be pulled up
before using this example.

================================================================================
How To Use This Code Example 

* Switch on Release build in Your preferred IDE. Debug build is not recommended 
  because in Debug build, the program is downloaded to the SRAM. When MCU returns
  from deep standby modes, it starts executing from the reset vector and executes
  the program from the flash.
* Connect WKUP0 with pull-up resistance
* Rebuild and run the program
* Watch the LED, which will blink several times.
* System enters into deep standby RTC mode, and the LED will turn off.
* After 30 s, the MCU will wake from deep standby RTC mode 
   (deep standby reset occurs and the steps 1 through 5 repeat)

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

================================================================================
