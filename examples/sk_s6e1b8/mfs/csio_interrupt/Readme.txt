================================================================================
                               CSIO example program
================================================================================
version          1.10
================================================================================
This example demonstrates communication between CSIO0 and CSIO1 with 
interrupt mode
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

This example demonstrates the communication between CSIO0 and CSIO1 with 
interrupt mode. CSIO0  is the master and CSIO1  is the slave. At first the master 
sends data to the slave and then the master reads data from the slave.

================================================================================
How To Use This Code Example 

* Use the Debug build in the project file
* Build and download the example to the board
* Make the following connections:
  Master(ch.0)     Slave(ch.1)
  SCK0_1   -----   SCK1_1
  SIN0_1   -----   SOT1_1
  SOT0_1   -----   SIN1_2
* Rebuild program and start debug
* Set the breakpoint at "if(Error == CompareData(au8CsioMasterTxBuf, au8CsioSlaveRxBuf, SAMPLE_CSIO_SLAVE_RX_BUFFSIZE))"
* Run the code
* Check the master transfer buffer array and the slave receive buffer array
* Set the breakpoint at "if(Error == CompareData(au8CsioMasterRxBuf, au8CsioSlaveTxBuf, SAMPLE_CSIO_MASTER_RX_BUFFSIZE))" 
* Run the code
* Check the slave transfer buffer array and the master receive buffer array

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