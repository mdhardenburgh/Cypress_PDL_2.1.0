/*******************************************************************************
* Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
* CYPRESS PROVIDES THIS SOFTWARE "AS IS" AND MAKES NO WARRANTY
* OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS SOFTWARE,
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
* PURPOSE.
*******************************************************************************/

                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table

                DATA
__vector_table  DCD     sfe(CSTACK)               ; Top of Stack
		        DCD     Reset_Handler             ; Reset
                DCD     NMI_Handler               ; NMI
                DCD     HardFault_Handler         ; Hard Fault
                DCD     MemManage_Handler         ; MPU Fault
                DCD     BusFault_Handler          ; Bus Fault
                DCD     UsageFault_Handler        ; Usage Fault
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall
                DCD     DebugMon_Handler          ; Debug Monitor
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV
                DCD     SysTick_Handler           ; SysTick

; Numbered IRQ handler vectors

; Note: renaming to device dependent ISR function names are done in
;       pdl.h (section "IRQ name definition for all type MCUs"

                DCD     CSV_IRQHandler
                DCD     SWDT_IRQHandler
                DCD     LVD_IRQHandler
                DCD     MFT0_WFG_DTIF_IRQHandler
                DCD     EXINT0_7_IRQHandler
                DCD     EXINT8_23_IRQHandler
                DCD     DT_IRQHandler
                DCD     MFS0_RX_IRQHandler
                DCD     MFS0_TX_IRQHandler
                DCD     MFS1_RX_IRQHandler
                DCD     MFS1_TX_IRQHandler
                DCD     MFS2_RX_IRQHandler
                DCD     MFS2_TX_IRQHandler
                DCD     MFS3_RX_IRQHandler
                DCD     MFS3_TX_IRQHandler
                DCD     MFS4_RX_IRQHandler
                DCD     MFS4_TX_IRQHandler
                DCD     MFS5_RX_IRQHandler
                DCD     MFS5_TX_IRQHandler
                DCD     MFS6_RX_IRQHandler
                DCD     MFS6_TX_IRQHandler
                DCD     MFS7_RX_IRQHandler
                DCD     MFS7_TX_IRQHandler
                DCD     PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler
                DCD     TIM_SMCIF1_HDMICEC1_IRQHandler
                DCD     ADC0_IRQHandler
                DCD     USB0_F_IRQHandler
                DCD     Dummy
                DCD     MFT0_FRT_IRQHandler
                DCD     USB0_F_MFT0_ICU_IRQHandler
                DCD     MFT0_OCU_IRQHandler
                DCD     BT0_7_FLASHIF_IRQHandler


                THUMB
; Dummy Exception Handlers (infinite loops which can be modified)

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

;No FPU                LDR.W R0, =0xE000ED88            ; CPACR is located at address 0xE000ED88
;No FPU                LDR R1, [R0]                     ; Read CPACR
;No FPU                ORR R1, R1, #(0xF << 20)         ; Set bits 20-23 to enable CP10 and CP11 coprocessors
;No FPU                STR R1, [R0]                     ; Write back the modified value to the CPACR

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0
                
                PUBWEAK NMI_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
                B       NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
                B       HardFault_Handler

                PUBWEAK MemManage_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
                B       MemManage_Handler

                PUBWEAK BusFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
                B       BusFault_Handler

                PUBWEAK UsageFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
                B       UsageFault_Handler

                PUBWEAK SVC_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
                B       SVC_Handler

                PUBWEAK DebugMon_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
                B       DebugMon_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
                B       PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
                B       SysTick_Handler

                
                PUBWEAK CSV_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
CSV_IRQHandler
                B       CSV_IRQHandler

                PUBWEAK SWDT_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
SWDT_IRQHandler
                B       SWDT_IRQHandler

                PUBWEAK LVD_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
LVD_IRQHandler
                B       LVD_IRQHandler

                PUBWEAK MFT0_WFG_DTIF_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFT0_WFG_DTIF_IRQHandler
                B       MFT0_WFG_DTIF_IRQHandler

                PUBWEAK EXINT0_7_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
EXINT0_7_IRQHandler
                B       EXINT0_7_IRQHandler

                PUBWEAK EXINT8_23_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
EXINT8_23_IRQHandler
                B       EXINT8_23_IRQHandler

                PUBWEAK DT_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
DT_IRQHandler
                B       DT_IRQHandler

                PUBWEAK MFS0_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS0_RX_IRQHandler
                B       MFS0_RX_IRQHandler

                PUBWEAK MFS0_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS0_TX_IRQHandler
                B       MFS0_TX_IRQHandler

                PUBWEAK MFS1_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS1_RX_IRQHandler
                B       MFS1_RX_IRQHandler

                PUBWEAK MFS1_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS1_TX_IRQHandler
                B       MFS1_TX_IRQHandler

                PUBWEAK MFS2_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS2_RX_IRQHandler
                B       MFS2_RX_IRQHandler

                PUBWEAK MFS2_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS2_TX_IRQHandler
                B       MFS2_TX_IRQHandler

                PUBWEAK MFS3_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS3_RX_IRQHandler
                B       MFS3_RX_IRQHandler

                PUBWEAK MFS3_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS3_TX_IRQHandler
                B       MFS3_TX_IRQHandler

                PUBWEAK MFS4_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS4_RX_IRQHandler
                B       MFS4_RX_IRQHandler

                PUBWEAK MFS4_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS4_TX_IRQHandler
                B       MFS4_TX_IRQHandler

                PUBWEAK MFS5_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS5_RX_IRQHandler
                B       MFS5_RX_IRQHandler

                PUBWEAK MFS5_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS5_TX_IRQHandler
                B       MFS5_TX_IRQHandler

                PUBWEAK MFS6_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS6_RX_IRQHandler
                B       MFS6_RX_IRQHandler

                PUBWEAK MFS6_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS6_TX_IRQHandler
                B       MFS6_TX_IRQHandler

                PUBWEAK MFS7_RX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS7_RX_IRQHandler
                B       MFS7_RX_IRQHandler

                PUBWEAK MFS7_TX_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFS7_TX_IRQHandler
                B       MFS7_TX_IRQHandler

                PUBWEAK PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler
                B       PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler

                PUBWEAK TIM_SMCIF1_HDMICEC1_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
TIM_SMCIF1_HDMICEC1_IRQHandler
                B       TIM_SMCIF1_HDMICEC1_IRQHandler

                PUBWEAK ADC0_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
ADC0_IRQHandler
                B       ADC0_IRQHandler

                PUBWEAK USB0_F_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
USB0_F_IRQHandler
                B       USB0_F_IRQHandler

                PUBWEAK MFT0_FRT_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFT0_FRT_IRQHandler
                B       MFT0_FRT_IRQHandler

                PUBWEAK USB0_F_MFT0_ICU_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
USB0_F_MFT0_ICU_IRQHandler
                B       USB0_F_MFT0_ICU_IRQHandler

                PUBWEAK MFT0_OCU_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
MFT0_OCU_IRQHandler
                B       MFT0_OCU_IRQHandler

                PUBWEAK BT0_7_FLASHIF_IRQHandler
                SECTION .text:CODE:REORDER:NOROOT(1)
BT0_7_FLASHIF_IRQHandler
                B       BT0_7_FLASHIF_IRQHandler




                PUBWEAK Dummy
                SECTION .text:CODE:REORDER:NOROOT(1)
Dummy
                B       Dummy

                END
