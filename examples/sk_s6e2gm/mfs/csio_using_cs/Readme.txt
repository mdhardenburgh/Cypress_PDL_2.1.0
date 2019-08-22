================================================================================
                               CSIO example program
================================================================================
version          1.10
================================================================================
This example demonstrates communication between CSIO1 and CSIO3 with interrupt 
mode using CS pin
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

This sample demonstrates the communication between CSIO6 and CSIO7 with interrupt mode using CS pin.
CSIO6 is the master and CSIO7 is the slave. First the master sends data to the
slave and then the Master reads data from the slave.

Attention:
* This example supports only MFS channels equipped with the Chip Selection
   function.
* Check whether the MFS has the CS function in the device data sheet
* Change MFS channel by modifing following setting:
   - The variable of "CsioCh6" and "CsioCh7"
   - The GPIO setting of SIN, SCK , SOT, SCS pins. Note that in some device,
     the pin name of SCS pin is SCSx_y, which means this device don't 
     support the start and end CS pin selection function. So the filed 
     of "enCsStartPin" and "enCsEndPin" need not be configured for 
     this device.

================================================================================
How To Use This Code Example

* Use the Debug build in the project file
* Build and download the example to the board
* Make the following connection:
  Master(ch.6) Slave(ch.7)
  SCK6_1 ----- SCK7_1
  SIN6_1 ----- SOT7_1
  SOT6_1 ----- SIN7_1
  SCS63_0 ----- SCS70_1
* Rebuild program and start debug
* Set the breakpoint at "if(Error == CompareData(au8CsioMasterTxBuf, au8CsioSlaveRxBuf, SAMPLE_CSIO_SLAVE_RX_BUFFSIZE))"
* Run
* Check the Master transfer buffer array and Slave receive buffer array
* Set the breakpoint at "if(Error == CompareData(au8CsioMasterRxBuf, au8CsioSlaveTxBuf, SAMPLE_CSIO_MASTER_RX_BUFFSIZE))" 
* Run
* Check the Slave transfer buffer array and Master receive buffer array

================================================================================
Build Environment

This example works with
* FM4-176L-S6E2GM Pioneer Kit

Project files are provided for
* ARM GCC v 4.9
* Atollic TrueStudio v 5.5.2
* IAR Embedded Workbench v 7.50.1
* iSystem winIDEA v 9.12
* Keil uVision v 5.17

================================================================================