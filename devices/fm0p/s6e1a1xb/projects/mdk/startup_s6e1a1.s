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

Stack_Size      EQU     0x00000300

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; Heap Configuration
;  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>

Heap_Size       EQU     0x00000600

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
				
                DCD     CSV_IRQHandler		; IRQ #0
                DCD     SWDT_IRQHandler		; IRQ #1
                DCD     LVD_IRQHandler		; IRQ #2
                DCD     MFT0_WFG_DTIF_IRQHandler		; IRQ #3
                DCD     EXINT0_7_IRQHandler		; IRQ #4
                DCD     Dummy		; IRQ #5
                DCD     DT_QPRC_IRQHandler		; IRQ #6
                DCD     MFS0_RX_IRQHandler		; IRQ #7
                DCD     MFS0_TX_IRQHandler		; IRQ #8
                DCD     MFS1_RX_IRQHandler		; IRQ #9
                DCD     MFS1_TX_IRQHandler		; IRQ #10
                DCD     Dummy		; IRQ #11
                DCD     Dummy		; IRQ #12
                DCD     MFS3_RX_IRQHandler		; IRQ #13
                DCD     MFS3_TX_IRQHandler		; IRQ #14
                DCD     Dummy		; IRQ #15
                DCD     Dummy		; IRQ #16
                DCD     Dummy		; IRQ #17
                DCD     Dummy		; IRQ #18
                DCD     DMAC0_IRQHandler		; IRQ #19
                DCD     DMAC1_IRQHandler		; IRQ #20
                DCD     Dummy		; IRQ #21
                DCD     Dummy		; IRQ #22
                DCD     PPG00_02_04_08_10_12_16_18_20_IRQHandler		; IRQ #23
                DCD     TIM_IRQHandler		; IRQ #24
                DCD     ADC0_IRQHandler		; IRQ #25
                DCD     Dummy		; IRQ #26
                DCD     Dummy		; IRQ #27
                DCD     MFT0_FRT_IRQHandler		; IRQ #28
                DCD     MFT0_ICU_IRQHandler		; IRQ #29
                DCD     MFT0_OCU_IRQHandler		; IRQ #30
                DCD     BT0_3_FLASHIF_IRQHandler		; IRQ #31


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

                EXPORT  CSV_IRQHandler    [WEAK]
                EXPORT  SWDT_IRQHandler    [WEAK]
                EXPORT  LVD_IRQHandler    [WEAK]
                EXPORT  MFT0_WFG_DTIF_IRQHandler    [WEAK]
                EXPORT  EXINT0_7_IRQHandler    [WEAK]
                EXPORT  DT_QPRC_IRQHandler    [WEAK]
                EXPORT  MFS0_RX_IRQHandler    [WEAK]
                EXPORT  MFS0_TX_IRQHandler    [WEAK]
                EXPORT  MFS1_RX_IRQHandler    [WEAK]
                EXPORT  MFS1_TX_IRQHandler    [WEAK]
                EXPORT  MFS3_RX_IRQHandler    [WEAK]
                EXPORT  MFS3_TX_IRQHandler    [WEAK]
                EXPORT  DMAC0_IRQHandler    [WEAK]
                EXPORT  DMAC1_IRQHandler    [WEAK]
                EXPORT  PPG00_02_04_08_10_12_16_18_20_IRQHandler    [WEAK]
                EXPORT  TIM_IRQHandler    [WEAK]
                EXPORT  ADC0_IRQHandler    [WEAK]
                EXPORT  MFT0_FRT_IRQHandler    [WEAK]
                EXPORT  MFT0_ICU_IRQHandler    [WEAK]
                EXPORT  MFT0_OCU_IRQHandler    [WEAK]
                EXPORT  BT0_3_FLASHIF_IRQHandler    [WEAK]

                
                EXPORT  Dummy	          [WEAK]

CSV_IRQHandler		; IRQ #0
SWDT_IRQHandler		; IRQ #1
LVD_IRQHandler		; IRQ #2
MFT0_WFG_DTIF_IRQHandler		; IRQ #3
EXINT0_7_IRQHandler		; IRQ #4
DT_QPRC_IRQHandler		; IRQ #6
MFS0_RX_IRQHandler		; IRQ #7
MFS0_TX_IRQHandler		; IRQ #8
MFS1_RX_IRQHandler		; IRQ #9
MFS1_TX_IRQHandler		; IRQ #10
MFS3_RX_IRQHandler		; IRQ #13
MFS3_TX_IRQHandler		; IRQ #14
DMAC0_IRQHandler		; IRQ #19
DMAC1_IRQHandler		; IRQ #20
PPG00_02_04_08_10_12_16_18_20_IRQHandler		; IRQ #23
TIM_IRQHandler		; IRQ #24
ADC0_IRQHandler		; IRQ #25
MFT0_FRT_IRQHandler		; IRQ #28
MFT0_ICU_IRQHandler		; IRQ #29
MFT0_OCU_IRQHandler		; IRQ #30
BT0_3_FLASHIF_IRQHandler		; IRQ #31

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
