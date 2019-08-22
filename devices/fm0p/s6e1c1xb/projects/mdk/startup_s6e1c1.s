;*******************************************************************************
; Copyright 2016, Cypress Semiconductor Corporation. All rights reserved.
; You may use this file only in accordance with the license, terms, conditions,
; disclaimers, and limitations in the end user license agreement accompanying
; the software package with which this file was provided.
; CYPRESS PROVIDES THIS SOFTWARE "AS IS" AND MAKES NO WARRANTY
; OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS SOFTWARE,
; INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
; MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
; PURPOSE.
;*******************************************************************************
; Stack Configuration
;  Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; Heap Configuration
;  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>

Heap_Size       EQU     0x00000800

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

; Numbered IRQ handler vectors				
				
                DCD     CSV_SWDT_LVD_IRQHandler		; IRQ #0
                DCD     MFS0_RX_TX_IRQHandler		; IRQ #1
                DCD     MFS1_RX_TX_IRQHandler		; IRQ #2
                DCD     Dummy		; IRQ #3
                DCD     MFS3_RX_TX_IRQHandler		; IRQ #4
                DCD     MFS4_RX_TX_IRQHandler		; IRQ #5
                DCD     Dummy		; IRQ #6
                DCD     MFS6_RX_TX_I2CSLAVE_IRQHandler		; IRQ #7
                DCD     MFS7_RX_TX_IRQHandler		; IRQ #8
                DCD     ADC0_IRQHandler		; IRQ #9
                DCD     Dummy		; IRQ #10
                DCD     Dummy		; IRQ #11
                DCD     Dummy		; IRQ #12
                DCD     Dummy		; IRQ #13
                DCD     TIM_IRQHandler		; IRQ #14
                DCD     WC_RTC_DT_IRQHandler		; IRQ #15
                DCD     EXINT0_1_IRQHandler		; IRQ #16
                DCD     EXINT2_3_IRQHandler		; IRQ #17
                DCD     EXINT4_5_IRQHandler		; IRQ #18
                DCD     EXINT6_7_IRQHandler		; IRQ #19
                DCD     EXINT8_IRQHandler		; IRQ #20
                DCD     Dummy		; IRQ #21
                DCD     EXINT12_13_IRQHandler		; IRQ #22
                DCD     EXINT15_IRQHandler		; IRQ #23
                DCD     BT0_4_IRQHandler		; IRQ #24
                DCD     BT1_5_IRQHandler		; IRQ #25
                DCD     BT2_6_IRQHandler		; IRQ #26
                DCD     BT3_7_IRQHandler		; IRQ #27
                DCD     HDMICEC0_1_IRQHandler		; IRQ #28
                DCD     SMCIF1_FLASHIF_IRQHandler		; IRQ #29
                DCD     DSTC_IRQHandler		; IRQ #30


__Vectors_End

__Vectors_Size 	EQU 	__Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

;No FPU                LDR.W R0, =0xE000ED88            ; CPACR is located at address 0xE000ED88
;No FPU                LDR R1, [R0]                     ; Read CPACR
;No FPU                ORR R1, R1, #(0xF << 20)         ; Set bits 20-23 to enable CP10 and CP11 coprocessors
;No FPU                STR R1, [R0]                     ; Write back the modified value to the CPACR

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  CSV_SWDT_LVD_IRQHandler    [WEAK]
                EXPORT  MFS0_RX_TX_IRQHandler    [WEAK]
                EXPORT  MFS1_RX_TX_IRQHandler    [WEAK]
                EXPORT  MFS3_RX_TX_IRQHandler    [WEAK]
                EXPORT  MFS4_RX_TX_IRQHandler    [WEAK]
                EXPORT  MFS6_RX_TX_I2CSLAVE_IRQHandler    [WEAK]
                EXPORT  MFS7_RX_TX_IRQHandler    [WEAK]
                EXPORT  ADC0_IRQHandler    [WEAK]
                EXPORT  TIM_IRQHandler    [WEAK]
                EXPORT  WC_RTC_DT_IRQHandler    [WEAK]
                EXPORT  EXINT0_1_IRQHandler    [WEAK]
                EXPORT  EXINT2_3_IRQHandler    [WEAK]
                EXPORT  EXINT4_5_IRQHandler    [WEAK]
                EXPORT  EXINT6_7_IRQHandler    [WEAK]
                EXPORT  EXINT8_IRQHandler    [WEAK]
                EXPORT  EXINT12_13_IRQHandler    [WEAK]
                EXPORT  EXINT15_IRQHandler    [WEAK]
                EXPORT  BT0_4_IRQHandler    [WEAK]
                EXPORT  BT1_5_IRQHandler    [WEAK]
                EXPORT  BT2_6_IRQHandler    [WEAK]
                EXPORT  BT3_7_IRQHandler    [WEAK]
                EXPORT  HDMICEC0_1_IRQHandler    [WEAK]
                EXPORT  SMCIF1_FLASHIF_IRQHandler    [WEAK]
                EXPORT  DSTC_IRQHandler    [WEAK]

                
                EXPORT  Dummy	          [WEAK]

CSV_SWDT_LVD_IRQHandler		; IRQ #0
MFS0_RX_TX_IRQHandler		; IRQ #1
MFS1_RX_TX_IRQHandler		; IRQ #2
MFS3_RX_TX_IRQHandler		; IRQ #4
MFS4_RX_TX_IRQHandler		; IRQ #5
MFS6_RX_TX_I2CSLAVE_IRQHandler		; IRQ #7
MFS7_RX_TX_IRQHandler		; IRQ #8
ADC0_IRQHandler		; IRQ #9
TIM_IRQHandler		; IRQ #14
WC_RTC_DT_IRQHandler		; IRQ #15
EXINT0_1_IRQHandler		; IRQ #16
EXINT2_3_IRQHandler		; IRQ #17
EXINT4_5_IRQHandler		; IRQ #18
EXINT6_7_IRQHandler		; IRQ #19
EXINT8_IRQHandler		; IRQ #20
EXINT12_13_IRQHandler		; IRQ #22
EXINT15_IRQHandler		; IRQ #23
BT0_4_IRQHandler		; IRQ #24
BT1_5_IRQHandler		; IRQ #25
BT2_6_IRQHandler		; IRQ #26
BT3_7_IRQHandler		; IRQ #27
HDMICEC0_1_IRQHandler		; IRQ #28
SMCIF1_FLASHIF_IRQHandler		; IRQ #29
DSTC_IRQHandler		; IRQ #30

Dummy


                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, = Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem + Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
