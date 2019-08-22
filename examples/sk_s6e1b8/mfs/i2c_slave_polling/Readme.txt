================================================================================
                               I2C Slave Example
================================================================================
version          1.10
================================================================================
This example demonstrates the work of the I2C in slave mode
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

This example demonstrates I2C data transfer and receive in slave mode. 
This example was designed to work with "i2c_master_polling" example.

================================================================================
How To Use This Code Example 

* Make the following connections before using this example:
  Master (1st board "i2c_master_polling")   Slave (2nd board with "i2c_slave_polling")
  SCK7_1   ---------------------------      SCK7_1
  SOT7_1   ---------------------------      SOT7_1
* The I2C lines must be pulled up and the boards should have a common ground connection.
* Use the Debug build in the project file
* Build and download the example to the board
* Run the example "i2c_slave_polling"
* Run the example "i2c_master_polling"
* Break
* Check the sent buffer(au8I2cSlaveTxBuf) and the receive buffer(au8I2cSlaveRxBuf)

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