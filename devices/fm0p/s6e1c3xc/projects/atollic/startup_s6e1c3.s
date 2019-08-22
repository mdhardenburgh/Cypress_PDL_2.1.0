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
  .word CSV_SWDT_LVD_IRQHandler		/* IRQ #0 */
  .word MFS0_RX_TX_IRQHandler		/* IRQ #1 */
  .word MFS1_RX_TX_IRQHandler		/* IRQ #2 */
  .word Default_Handler		/* IRQ #3 */
  .word MFS3_RX_TX_IRQHandler		/* IRQ #4 */
  .word MFS4_RX_TX_IRQHandler		/* IRQ #5 */
  .word Default_Handler		/* IRQ #6 */
  .word MFS6_RX_TX_I2CSLAVE_IRQHandler		/* IRQ #7 */
  .word MFS7_RX_TX_IRQHandler		/* IRQ #8 */
  .word ADC0_IRQHandler		/* IRQ #9 */
  .word USB0_F_ED123_IRQHandler		/* IRQ #10 */
  .word USB0_F_ED450I_IRQHandler		/* IRQ #11 */
  .word USB0_F_ED0O_ST_IRQHandler		/* IRQ #12 */
  .word USB0_H_IRQHandler		/* IRQ #13 */
  .word TIM_IRQHandler		/* IRQ #14 */
  .word WC_RTC_DT_IRQHandler		/* IRQ #15 */
  .word EXINT0_1_IRQHandler		/* IRQ #16 */
  .word EXINT2_3_IRQHandler		/* IRQ #17 */
  .word EXINT4_5_IRQHandler		/* IRQ #18 */
  .word EXINT6_7_IRQHandler		/* IRQ #19 */
  .word EXINT8_IRQHandler		/* IRQ #20 */
  .word Default_Handler		/* IRQ #21 */
  .word EXINT12_13_IRQHandler		/* IRQ #22 */
  .word EXINT15_IRQHandler		/* IRQ #23 */
  .word BT0_4_IRQHandler		/* IRQ #24 */
  .word BT1_5_IRQHandler		/* IRQ #25 */
  .word BT2_6_IRQHandler		/* IRQ #26 */
  .word BT3_7_IRQHandler		/* IRQ #27 */
  .word HDMICEC0_1_IRQHandler		/* IRQ #28 */
  .word SMCIF1_FLASHIF_IRQHandler		/* IRQ #29 */
  .word DSTC_IRQHandler		/* IRQ #30 */



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
  .weak CSV_SWDT_LVD_IRQHandler
  .thumb_set CSV_SWDT_LVD_IRQHandler, Default_Handler

/* IRQ #1 */
  .weak MFS0_RX_TX_IRQHandler
  .thumb_set MFS0_RX_TX_IRQHandler, Default_Handler

/* IRQ #2 */
  .weak MFS1_RX_TX_IRQHandler
  .thumb_set MFS1_RX_TX_IRQHandler, Default_Handler

/* IRQ #4 */
  .weak MFS3_RX_TX_IRQHandler
  .thumb_set MFS3_RX_TX_IRQHandler, Default_Handler

/* IRQ #5 */
  .weak MFS4_RX_TX_IRQHandler
  .thumb_set MFS4_RX_TX_IRQHandler, Default_Handler

/* IRQ #7 */
  .weak MFS6_RX_TX_I2CSLAVE_IRQHandler
  .thumb_set MFS6_RX_TX_I2CSLAVE_IRQHandler, Default_Handler

/* IRQ #8 */
  .weak MFS7_RX_TX_IRQHandler
  .thumb_set MFS7_RX_TX_IRQHandler, Default_Handler

/* IRQ #9 */
  .weak ADC0_IRQHandler
  .thumb_set ADC0_IRQHandler, Default_Handler

/* IRQ #10 */
  .weak USB0_F_ED123_IRQHandler
  .thumb_set USB0_F_ED123_IRQHandler, Default_Handler

/* IRQ #11 */
  .weak USB0_F_ED450I_IRQHandler
  .thumb_set USB0_F_ED450I_IRQHandler, Default_Handler

/* IRQ #12 */
  .weak USB0_F_ED0O_ST_IRQHandler
  .thumb_set USB0_F_ED0O_ST_IRQHandler, Default_Handler

/* IRQ #13 */
  .weak USB0_H_IRQHandler
  .thumb_set USB0_H_IRQHandler, Default_Handler

/* IRQ #14 */
  .weak TIM_IRQHandler
  .thumb_set TIM_IRQHandler, Default_Handler

/* IRQ #15 */
  .weak WC_RTC_DT_IRQHandler
  .thumb_set WC_RTC_DT_IRQHandler, Default_Handler

/* IRQ #16 */
  .weak EXINT0_1_IRQHandler
  .thumb_set EXINT0_1_IRQHandler, Default_Handler

/* IRQ #17 */
  .weak EXINT2_3_IRQHandler
  .thumb_set EXINT2_3_IRQHandler, Default_Handler

/* IRQ #18 */
  .weak EXINT4_5_IRQHandler
  .thumb_set EXINT4_5_IRQHandler, Default_Handler

/* IRQ #19 */
  .weak EXINT6_7_IRQHandler
  .thumb_set EXINT6_7_IRQHandler, Default_Handler

/* IRQ #20 */
  .weak EXINT8_IRQHandler
  .thumb_set EXINT8_IRQHandler, Default_Handler

/* IRQ #22 */
  .weak EXINT12_13_IRQHandler
  .thumb_set EXINT12_13_IRQHandler, Default_Handler

/* IRQ #23 */
  .weak EXINT15_IRQHandler
  .thumb_set EXINT15_IRQHandler, Default_Handler

/* IRQ #24 */
  .weak BT0_4_IRQHandler
  .thumb_set BT0_4_IRQHandler, Default_Handler

/* IRQ #25 */
  .weak BT1_5_IRQHandler
  .thumb_set BT1_5_IRQHandler, Default_Handler

/* IRQ #26 */
  .weak BT2_6_IRQHandler
  .thumb_set BT2_6_IRQHandler, Default_Handler

/* IRQ #27 */
  .weak BT3_7_IRQHandler
  .thumb_set BT3_7_IRQHandler, Default_Handler

/* IRQ #28 */
  .weak HDMICEC0_1_IRQHandler
  .thumb_set HDMICEC0_1_IRQHandler, Default_Handler

/* IRQ #29 */
  .weak SMCIF1_FLASHIF_IRQHandler
  .thumb_set SMCIF1_FLASHIF_IRQHandler, Default_Handler

/* IRQ #30 */
  .weak DSTC_IRQHandler
  .thumb_set DSTC_IRQHandler, Default_Handler



  .end
