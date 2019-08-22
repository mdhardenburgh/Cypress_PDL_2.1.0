/*******************************************************************************
*  Abstract    : This file contains interrupt vector and startup code.
*
*  Functions   : Reset_Handler
*
*  Target      : Cypress FM microcontrollers
*
*  Environment : Atollic TrueSTUDIO(R)
*
********************************************************************************
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
  .syntax unified
  .thumb

  .global Reset_Handler
  .global InterruptVector
  .global Default_Handler

  /* Linker script definitions */
  /* start address for the initialization values of the .data section */
  .word _sidata
  /* start address for the .data section */
  .word _sdata
  /* end address for the .data section */
  .word _edata
  /* start address for the .bss section */
  .word _sbss
  /* end address for the .bss section */
  .word _ebss

/**
**===========================================================================
**  Program - Reset_Handler
**  Abstract: This code gets called after reset.
**===========================================================================
*/
  .section  .text.Reset_Handler,"ax", %progbits
  .type Reset_Handler, %function
Reset_Handler:
  /* Set stack pointer */
  ldr r0,=_estack
  mov sp, r0
  
  /* START NO FPU IN THIS DEVICE
  ldr     r0, =0xe000ed88           
  ldr     r1,[r0]
  ldr     r2, =0xf00000
  orr     r1,r1,r2
  str     r1,[r0]
  END NO FPU IN THIS DEVICE */
  
  /* Branch to SystemInit function */
  bl SystemInit

  /* Copy data initialization values */
  ldr r1,=_sidata
  ldr r2,=_sdata
  ldr r3,=_edata
  b cmpdata
CopyLoop:
  ldr r0, [r1]
  adds r1, r1, #4
  str r0, [r2]
  adds r2, r2, #4
cmpdata:
  cmp r2, r3
  blt CopyLoop

  /* Clear BSS section */
  movs r0, #0
  ldr r2,=_sbss
  ldr r3,=_ebss
  b cmpbss
ClearLoop:
  str r0, [r2]
  adds r2, r2, #4
cmpbss:
  cmp r2, r3
  blt ClearLoop

  /* Call static constructors */
  bl __libc_init_array

  /* Branch to main */
  bl main

  /* If main returns, branch to Default_Handler. */
  b Default_Handler

  .size  Reset_Handler, .-Reset_Handler

/**
**===========================================================================
**  Program - Default_Handler
**  Abstract: This code gets called when the processor receives an
**    unexpected interrupt.
**===========================================================================
*/
  .section  .text.Default_Handler,"ax", %progbits
Default_Handler:
  b  Default_Handler

  .size  Default_Handler, .-Default_Handler

/**
**===========================================================================
**  Interrupt vector table
**===========================================================================
*/
  .section .isr_vector,"a", %progbits
InterruptVector:
  .word _estack                   /* 0 - Stack pointer */
  .word Reset_Handler             /* 1 - Reset */
  .word NMI_Handler               /* 2 - NMI  */
  .word HardFault_Handler         /* 3 - Hard fault */
  .word MemManage_Handler         /* 4 - Memory management fault */
  .word BusFault_Handler          /* 5 - Bus fault */
  .word UsageFault_Handler        /* 6 - Usage fault */
  .word 0                         /* 7 - Reserved */
  .word 0                         /* 8 - Reserved */
  .word 0                         /* 9 - Reserved */
  .word 0                         /* 10 - Reserved */
  .word SVC_Handler               /* 11 - SVCall */
  .word DebugMonitor_Handler      /* 12 - Reserved for Debug */
  .word 0                         /* 13 - Reserved */
  .word PendSV_Handler            /* 14 - PendSV */
  .word SysTick_Handler           /* 15 - Systick */

  /* External Interrupts */
  .word CSV_IRQHandler		/* IRQ #0 */
  .word SWDT_IRQHandler		/* IRQ #1 */
  .word LVD_IRQHandler		/* IRQ #2 */
  .word MFT0_WFG_DTIF_IRQHandler		/* IRQ #3 */
  .word EXINT0_7_IRQHandler		/* IRQ #4 */
  .word EXINT8_23_IRQHandler		/* IRQ #5 */
  .word DT_IRQHandler		/* IRQ #6 */
  .word MFS0_RX_IRQHandler		/* IRQ #7 */
  .word MFS0_TX_IRQHandler		/* IRQ #8 */
  .word MFS1_RX_IRQHandler		/* IRQ #9 */
  .word MFS1_TX_IRQHandler		/* IRQ #10 */
  .word MFS2_RX_IRQHandler		/* IRQ #11 */
  .word MFS2_TX_IRQHandler		/* IRQ #12 */
  .word MFS3_RX_IRQHandler		/* IRQ #13 */
  .word MFS3_TX_IRQHandler		/* IRQ #14 */
  .word MFS4_RX_IRQHandler		/* IRQ #15 */
  .word MFS4_TX_IRQHandler		/* IRQ #16 */
  .word MFS5_RX_IRQHandler		/* IRQ #17 */
  .word MFS5_TX_IRQHandler		/* IRQ #18 */
  .word MFS6_RX_IRQHandler		/* IRQ #19 */
  .word MFS6_TX_IRQHandler		/* IRQ #20 */
  .word MFS7_RX_IRQHandler		/* IRQ #21 */
  .word MFS7_TX_IRQHandler		/* IRQ #22 */
  .word PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler		/* IRQ #23 */
  .word TIM_SMCIF1_HDMICEC1_IRQHandler		/* IRQ #24 */
  .word ADC0_IRQHandler		/* IRQ #25 */
  .word USB0_F_IRQHandler		/* IRQ #26 */
  .word LCDC_IRQHandler		/* IRQ #27 */
  .word MFT0_FRT_IRQHandler		/* IRQ #28 */
  .word USB0_F_MFT0_ICU_IRQHandler		/* IRQ #29 */
  .word MFT0_OCU_IRQHandler		/* IRQ #30 */
  .word BT0_7_FLASHIF_IRQHandler		/* IRQ #31 */



/**
**===========================================================================
**  Weak interrupt handlers redirected to Default_Handler. These can be
**  overridden in user code.
**===========================================================================
*/
  .weak NMI_Handler
  .thumb_set NMI_Handler, Default_Handler

  .weak HardFault_Handler
  .thumb_set HardFault_Handler, Default_Handler

  .weak MemManage_Handler
  .thumb_set MemManage_Handler, Default_Handler

  .weak BusFault_Handler
  .thumb_set BusFault_Handler, Default_Handler

  .weak UsageFault_Handler
  .thumb_set UsageFault_Handler, Default_Handler

  .weak SVC_Handler
  .thumb_set SVC_Handler, Default_Handler

  .weak DebugMonitor_Handler
  .thumb_set DebugMonitor_Handler, Default_Handler

  .weak PendSV_Handler
  .thumb_set PendSV_Handler, Default_Handler

  .weak SysTick_Handler
  .thumb_set SysTick_Handler, Default_Handler
  
/* IRQ #0 */
  .weak CSV_IRQHandler
  .thumb_set CSV_IRQHandler, Default_Handler

/* IRQ #1 */
  .weak SWDT_IRQHandler
  .thumb_set SWDT_IRQHandler, Default_Handler

/* IRQ #2 */
  .weak LVD_IRQHandler
  .thumb_set LVD_IRQHandler, Default_Handler

/* IRQ #3 */
  .weak MFT0_WFG_DTIF_IRQHandler
  .thumb_set MFT0_WFG_DTIF_IRQHandler, Default_Handler

/* IRQ #4 */
  .weak EXINT0_7_IRQHandler
  .thumb_set EXINT0_7_IRQHandler, Default_Handler

/* IRQ #5 */
  .weak EXINT8_23_IRQHandler
  .thumb_set EXINT8_23_IRQHandler, Default_Handler

/* IRQ #6 */
  .weak DT_IRQHandler
  .thumb_set DT_IRQHandler, Default_Handler

/* IRQ #7 */
  .weak MFS0_RX_IRQHandler
  .thumb_set MFS0_RX_IRQHandler, Default_Handler

/* IRQ #8 */
  .weak MFS0_TX_IRQHandler
  .thumb_set MFS0_TX_IRQHandler, Default_Handler

/* IRQ #9 */
  .weak MFS1_RX_IRQHandler
  .thumb_set MFS1_RX_IRQHandler, Default_Handler

/* IRQ #10 */
  .weak MFS1_TX_IRQHandler
  .thumb_set MFS1_TX_IRQHandler, Default_Handler

/* IRQ #11 */
  .weak MFS2_RX_IRQHandler
  .thumb_set MFS2_RX_IRQHandler, Default_Handler

/* IRQ #12 */
  .weak MFS2_TX_IRQHandler
  .thumb_set MFS2_TX_IRQHandler, Default_Handler

/* IRQ #13 */
  .weak MFS3_RX_IRQHandler
  .thumb_set MFS3_RX_IRQHandler, Default_Handler

/* IRQ #14 */
  .weak MFS3_TX_IRQHandler
  .thumb_set MFS3_TX_IRQHandler, Default_Handler

/* IRQ #15 */
  .weak MFS4_RX_IRQHandler
  .thumb_set MFS4_RX_IRQHandler, Default_Handler

/* IRQ #16 */
  .weak MFS4_TX_IRQHandler
  .thumb_set MFS4_TX_IRQHandler, Default_Handler

/* IRQ #17 */
  .weak MFS5_RX_IRQHandler
  .thumb_set MFS5_RX_IRQHandler, Default_Handler

/* IRQ #18 */
  .weak MFS5_TX_IRQHandler
  .thumb_set MFS5_TX_IRQHandler, Default_Handler

/* IRQ #19 */
  .weak MFS6_RX_IRQHandler
  .thumb_set MFS6_RX_IRQHandler, Default_Handler

/* IRQ #20 */
  .weak MFS6_TX_IRQHandler
  .thumb_set MFS6_TX_IRQHandler, Default_Handler

/* IRQ #21 */
  .weak MFS7_RX_IRQHandler
  .thumb_set MFS7_RX_IRQHandler, Default_Handler

/* IRQ #22 */
  .weak MFS7_TX_IRQHandler
  .thumb_set MFS7_TX_IRQHandler, Default_Handler

/* IRQ #23 */
  .weak PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler
  .thumb_set PPG00_02_20_DSTC_SMCIF0_HDMICEC0_IRQHandler, Default_Handler

/* IRQ #24 */
  .weak TIM_SMCIF1_HDMICEC1_IRQHandler
  .thumb_set TIM_SMCIF1_HDMICEC1_IRQHandler, Default_Handler

/* IRQ #25 */
  .weak ADC0_IRQHandler
  .thumb_set ADC0_IRQHandler, Default_Handler

/* IRQ #26 */
  .weak USB0_F_IRQHandler
  .thumb_set USB0_F_IRQHandler, Default_Handler

/* IRQ #27 */
  .weak LCDC_IRQHandler
  .thumb_set LCDC_IRQHandler, Default_Handler

/* IRQ #28 */
  .weak MFT0_FRT_IRQHandler
  .thumb_set MFT0_FRT_IRQHandler, Default_Handler

/* IRQ #29 */
  .weak USB0_F_MFT0_ICU_IRQHandler
  .thumb_set USB0_F_MFT0_ICU_IRQHandler, Default_Handler

/* IRQ #30 */
  .weak MFT0_OCU_IRQHandler
  .thumb_set MFT0_OCU_IRQHandler, Default_Handler

/* IRQ #31 */
  .weak BT0_7_FLASHIF_IRQHandler
  .thumb_set BT0_7_FLASHIF_IRQHandler, Default_Handler



  .end
