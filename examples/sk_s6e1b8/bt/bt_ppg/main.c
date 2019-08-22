/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates both interrupt and polling access mode of PPG timer.
*
********************************************************************************
* \copyright
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

#include "pdl_header.h"
#include "inttypes.h"

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/
#define  USER_BT             BT0
#if !defined(SetPinFunc_TIOA0_0_OUT)
#error TIOA0_0  pin is not available in this MCU product, \
change to other re-location pin or BT channel! Then delete "me" !
#endif     

/* PPG wave can be observed at P40 */
#define  PpgInitOutput()     SetPinFunc_TIOA0_0_OUT() 

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
/*! \brief Interrupt count value */
static uint32_t m_u32CntIntTrg, m_u32CntIntUnder;

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PpgUnderflowIrqHandler(void);
static void PpgTrigIrqHandler(void);
static void Delay(void);

/*!
 ******************************************************************************
 ** \brief PPG timer example code
 **
 ** 1. Initialization
 ** 3. Enable interrupt.
 ** 4. Enable count operation.
 ** 5. Start software trigger.
 ** 6. Disable interrupt
 ** 7. Restart software trigger
 ** 8. Disable count operation.
 ******************************************************************************
 */
int main(void)
{
    stc_bt_ppg_config_t stcPpgConfig;
    stc_ppg_irq_en_t    stcIrqEn;
    stc_ppg_irq_cb_t    stcIrqCb;
    
    uint32_t u32Cnt=0;

#ifdef DEBUG_PRINT 
    Uart_Io_Init();
    printf("==================================================\n");
    printf("PPG Example Program Start \n");
    printf("==================================================\n");
#endif
  
    /* Set Basetimer IO port   */
    PpgInitOutput();
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcPpgConfig);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);
    
    /* Initialize interrupt */
    stcPpgConfig.pstcPpgIrqEn = &stcIrqEn;
    stcPpgConfig.pstcPpgIrqCb = &stcIrqCb;
    
    /* Initialize PPG timer */
    stcPpgConfig.enPres = PpgPres1Div4;  /* PPG clock = 5MHz @ PCLK = 20MHz */
    stcPpgConfig.enMode = PpgContinuous; 
    stcPpgConfig.enExtTrig = PpgExtTrigDisable;
    stcPpgConfig.enOutputMask = PpgOutputNormal;
    stcPpgConfig.enOutputPolarity = PpgPolarityLow;
    stcPpgConfig.enRestartEn = PpgRestartEnable;
    stcPpgConfig.pstcPpgIrqEn->bPpgTrigIrq = TRUE;
    stcPpgConfig.pstcPpgIrqEn->bPpgUnderflowIrq = TRUE;
    stcPpgConfig.pstcPpgIrqCb->pfnPpgTrigIrqCb = PpgTrigIrqHandler;
    stcPpgConfig.pstcPpgIrqCb->pfnPpgUnderflowIrqCb = PpgUnderflowIrqHandler;
    stcPpgConfig.bTouchNvic = TRUE;
    Bt_Ppg_Init(&USER_BT, &stcPpgConfig);
    
    /* Set cycle and duty value */
    Bt_Ppg_WriteLowWidthVal(&USER_BT, 499);   /* Cycle = (1+m)*PPG clock cycle = 100us */
    Bt_Ppg_WriteHighWidthVal(&USER_BT, 499);  /* Duty = (1+m)*PPG clock cycle = 100us */
          
    /* Enable count operatoin */
    Bt_Ppg_EnableCount(&USER_BT);
    
    /* Start triggered by software */
    Bt_Ppg_EnableSwTrig(&USER_BT);
    
    /* Delay some time */
    Delay();     

#ifdef DEBUG_PRINT 
    printf("Cycle: %d\n", 499);
    printf("Duty: %d\n", 499);       
#endif    
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Enable Interrupt mode, waiting several seconds approximately\n");
#endif  
    
    /* Delay some time  */
    Delay(); 
    
#ifdef DEBUG_PRINT 
    printf("Interrupt times:\n"); 
    printf("PPG trigger interrupt:   %"PRIu32"\n", m_u32CntIntTrg);
    printf("PPG underflow interrupt: %"PRIu32"\n", m_u32CntIntUnder);
#endif
    
    /* Disable Interrupt */
    Bt_Ppg_DisableIrq(&USER_BT, PpgTrigIrq);
    Bt_Ppg_DisableIrq(&USER_BT, PpgUnderflowIrq);
       
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Disable Interrupt mode, waiting several seconds approximately\n");
#endif
    
    m_u32CntIntTrg = 0;
    m_u32CntIntUnder = 0;   
    
    /* Delay some time */
    Delay(); 
    
#ifdef DEBUG_PRINT 
    printf("Interrupt times:\n"); 
    printf("PPG trigger interrupt:   %"PRIu32"\n", m_u32CntIntTrg);
    printf("PPG underflow interrupt: %"PRIu32"\n", m_u32CntIntUnder);
#endif 
    
    /* Restart triggered by software */
    Bt_Ppg_EnableSwTrig(&USER_BT);
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Enable query mode, waiting several seconds approximately\n");
#endif
 
    m_u32CntIntTrg = 0;
    m_u32CntIntUnder = 0; 
    
    /* Interrupt query mode */
    do 
    {   
        if (Bt_Ppg_GetIrqFlag(&USER_BT, PpgTrigIrq) == PdlSet)
        {
            Bt_Ppg_ClrIrqFlag(&USER_BT, PpgTrigIrq);
            m_u32CntIntTrg++;
        }
        else if (Bt_Ppg_GetIrqFlag(&USER_BT, PpgUnderflowIrq) == PdlSet)
        {
            Bt_Ppg_ClrIrqFlag(&USER_BT, PpgUnderflowIrq);
            m_u32CntIntUnder++;
        }
        u32Cnt++;
    } while(u32Cnt <2500000UL);
    
#ifdef DEBUG_PRINT
    printf("Interrupt request times:\n"); 
    printf("PPG trigger interrupt:   %"PRIu32"\n", m_u32CntIntTrg);
    printf("PPG underflow interrupt: %"PRIu32"\n", m_u32CntIntUnder);
#endif 
    
    /* Disable PPG count */
    Bt_Ppg_DisableCount(&USER_BT);
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("PPG Example Program End \n");
    printf("==================================================\n");
#endif
    
    while(1);
}
/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/

/*!
 ******************************************************************************
 ** \brief PPG underflow interrupt handler
 ******************************************************************************
 */
static void PpgUnderflowIrqHandler(void)
{
    m_u32CntIntUnder++;
}

/*!
 ******************************************************************************
 ** \brief PPG trigger interrupt handler
 ******************************************************************************
 */
static void PpgTrigIrqHandler(void)
{
    m_u32CntIntTrg++;
}

/*
 ******************************************************************************
 ** \brief Delay requested secondes approximately
 ******************************************************************************
 */
static void Delay(void)
{
    int32_t u8Cnt1,u8Cnt2;
   
    u8Cnt2 = SystemCoreClock;
     
    u8Cnt1 = 0;
    while (1) 
    {
        u8Cnt1++;
        if (u8Cnt1 > u8Cnt2) 
        {
            break;
        }
    }   
}


/* [] END OF FILE */
