/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example demonstrates both interrupt and polling access mode of PWC timer.
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
#include <inttypes.h>

/*---------------------------------------------------------------------------*/
/* local defines                                                             */
/*---------------------------------------------------------------------------*/
#if !defined(SetPinFunc_TIOA2_0_OUT)
#error TIOA2_0 BT2 pins are not available in this MCU product, \
change to other re-location pins or BT channels! Then delete "me" !
#endif

#if !defined(SetPinFunc_TIOB0_0_IN)
#error TIOB0_0 BT2 pins are not available in this MCU product, \
change to other re-location pins or BT channels! Then delete "me" ! \
Note that the pin name in some product is TIOB00_0, thus SetPinFunc_TIOB00_0_IN \
should be called for such product!
#endif

/* The PWM output is used as measured wave for PWC timer, connect P42(TIOA2_0) 
* with P4A(TIOB0_0) before running the program. */
/* PWM  */
#define  USER_BT_PWM             BT2
#define  PwmInitOutput()         SetPinFunc_TIOA2_0_OUT();

/* PWC */
#define  USER_BT_PWC             BT0
#define  USER_BT_TIMER_SIZE      PwcSize32Bit
#define  PwcInitInput()         SetPinFunc_TIOB0_0_IN();

#define  MEASURE_CNT_MAX         (10)

/*---------------------------------------------------------------------------*/
/* local data                                                                */
/*---------------------------------------------------------------------------*/
volatile static uint32_t m_u32CntIntMeasure, m_u32CntMeasureErr;
static uint32_t m_u32CntIntOverflow;
static uint32_t m_aMeasureResult[MEASURE_CNT_MAX];

/*---------------------------------------------------------------------------*/
/* local functions prototypes                                                */
/*---------------------------------------------------------------------------*/
static void PwcOverflowIntHandler(void);
static void PwcMeasCmpIrqHandler(void);

/*!
 ******************************************************************************
 ** \brief PWC timer example code
 **
 ** 1. Register initialization
 ** 2. Callback function initialization.
 ** 3. Enable interrupt.
 ** 4. Enable count operation.
 ******************************************************************************
 */
int main(void)
{
    stc_bt_pwm_config_t stcPwmConfig;
    stc_bt_pwc_config_t stcPwcConfig;
    stc_pwc_irq_en_t stcPwcIrqEn;
    stc_pwc_irq_cb_t stcPwcIrqCallback;
    
    uint32_t u32Cnt;

    // Clear structures
    PDL_ZERO_STRUCT(stcPwmConfig);
    PDL_ZERO_STRUCT(stcPwcConfig);
    PDL_ZERO_STRUCT(stcPwcIrqEn);
    PDL_ZERO_STRUCT(stcPwcIrqCallback);
    
    /*------------- PWM Generation -----------------*/
    /* Set IO port  */
    PwmInitOutput(); 
        
    /* PWM configuration */
    Bt_ConfigIOMode(&USER_BT_PWM, BtIoMode0);
    stcPwmConfig.enPres = PwmPres1Div4;
    stcPwmConfig.enMode = PwmContinuous;
    stcPwmConfig.enExtTrig = PwmExtTrigDisable;
    stcPwmConfig.enOutputMask = PwmOutputNormal;
    stcPwmConfig.enOutputPolarity = PwmPolarityLow;
    stcPwmConfig.enRestartEn = PwmRestartEnable;
    Bt_Pwm_Init(&USER_BT_PWM , &stcPwmConfig);
    Bt_Pwm_WriteCycleVal(&USER_BT_PWM, 999);
    Bt_Pwm_WriteDutyVal(&USER_BT_PWM, 499);

    /* Start PWM */
    Bt_Pwm_EnableCount(&USER_BT_PWM);
    Bt_Pwm_EnableSwTrig(&USER_BT_PWM);
    /*---------------------------------------------*/
    
#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("==================================================\n");
    printf("PWC Example Program Start \n");
    printf("==================================================\n");
#endif
    
    /* Set IO port  */
    PwcInitInput();
       
    /* Initialize interrupt */
    stcPwcConfig.pstcPwcIrqEn = &stcPwcIrqEn;
    stcPwcConfig.pstcPwcIrqCb = &stcPwcIrqCallback;
      
    /* PWC register initialization */
    stcPwcConfig.enPres = PwcPres1Div4;
    stcPwcConfig.enMode = PwcContinuous;
    stcPwcConfig.enMeasureEdge = PwcMeasureRisingToFalling;
    stcPwcConfig.enSize = USER_BT_TIMER_SIZE;
    stcPwcConfig.bTouchNvic =  TRUE;
   
    /* Enable Interrupt */
    stcPwcConfig.pstcPwcIrqEn->bPwcMeasureCompleteIrq = TRUE;
    stcPwcConfig.pstcPwcIrqEn->bPwcMeasureOverflowIrq = TRUE;
    stcPwcConfig.pstcPwcIrqCb->pfnPwcMeasureCompleteIrqCb = PwcMeasCmpIrqHandler;
    stcPwcConfig.pstcPwcIrqCb->pfnPwcMeasureOverflowIrqCb = PwcOverflowIntHandler;
    Bt_Pwc_Init(&USER_BT_PWC, &stcPwcConfig);
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Enable Interrupt mode, Waiting for mesaurment compeleted \n");
#endif      
    
    /* Enable count operatoin */
    Bt_Pwc_EnableCount(&USER_BT_PWC);

    /* Waiting for mesaurment compeleted */
    while(m_u32CntIntMeasure < MEASURE_CNT_MAX);
    
    Bt_Pwc_DisableIrq(&USER_BT_PWC, PwcMeasureCompleteIrq);
    Bt_Pwc_DisableIrq(&USER_BT_PWC, PwcMeasureOverflowIrq);
#ifdef DEBUG_PRINT
    printf("Interrupt times:\n"); 
    printf("BT_INT_TYP_MEASURE: %"PRIu32"\n", m_u32CntIntMeasure);
    printf("BT_INT_TYP_OVERFLOW: %"PRIu32"\n", m_u32CntIntOverflow);
    printf("Measure error: %"PRIu32"\n", m_u32CntMeasureErr);
    for(u32Cnt=0; u32Cnt<MEASURE_CNT_MAX; u32Cnt++)
    {
        printf("Measurement result %"PRIu32": %"PRIu32"\n", (u32Cnt+1), m_aMeasureResult[u32Cnt]);
    }
#endif     
 
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("Disable Interrupt, enable query mode, Waiting for mesaurment compeleted\n");
#endif
 
    m_u32CntIntMeasure = 0;
    m_u32CntIntOverflow = 0;
    m_u32CntMeasureErr = 0; 
    
    for(u32Cnt = 0; u32Cnt < MEASURE_CNT_MAX; u32Cnt++)
    {
        m_aMeasureResult[u32Cnt] = 0;
    } 
    /* Interrupt query mode */
    do 
    {   
        if (Bt_Pwc_GetIrqFlag(&USER_BT_PWC, PwcMeasureCompleteIrq) == PdlSet)
        {
            if (stcPwcConfig.enSize == PwcSize16Bit)
            {
                m_aMeasureResult[m_u32CntIntMeasure] = Bt_Pwc_Get16BitMeasureData(&USER_BT_PWC) +
                    (m_u32CntIntOverflow * 0x10000); 
            }
            else /* BT_32IT_TIMER */
            {
                /* Comment this line if testing measure error feature */
		m_aMeasureResult[m_u32CntIntMeasure] = Bt_Pwc_Get32BitMeasureData(&USER_BT_PWC);
            }
            m_u32CntIntOverflow = 0;
            m_u32CntIntMeasure++;
            
            if (Bt_Pwc_GetErrorFlag(&USER_BT_PWC) == PdlSet)
            {            
                m_u32CntMeasureErr++;
            }
        }
        else if (Bt_Pwc_GetIrqFlag(&USER_BT_PWC, PwcMeasureOverflowIrq) == PdlSet)
        {   
            Bt_Pwc_ClrIrqFlag(&USER_BT_PWC, PwcMeasureOverflowIrq);
            m_u32CntIntOverflow++;
        }
        
    } while(m_u32CntIntMeasure < MEASURE_CNT_MAX);
    
#ifdef DEBUG_PRINT
    printf("Interrupt request times:\n"); 
    printf("BT_INT_TYP_MEASURE: %"PRIu32"\n", m_u32CntIntMeasure);
    printf("BT_INT_TYP_OVERFLOW: %"PRIu32"\n", m_u32CntIntOverflow);
    printf("Measure error: %"PRIu32"\n", m_u32CntMeasureErr);
    for(u32Cnt=0; u32Cnt<MEASURE_CNT_MAX; u32Cnt++)
    {
        printf("Measurement result %"PRIu32": %"PRIu32"\n", (u32Cnt+1), m_aMeasureResult[u32Cnt]);
    }   
#endif 
    
    Bt_Pwc_DisableCount(&USER_BT_PWC); 
    
#ifdef DEBUG_PRINT 
    printf("==================================================\n");
    printf("PWC Example Program End \n");
    printf("==================================================\n");
#endif    
    
    while(1)
	{
	    /* your code */	
	}
}

/*---------------------------------------------------------------------------*/
/* local functions                                                           */
/*---------------------------------------------------------------------------*/
/*!
 ******************************************************************************
 ** \brief PWC overflow interrupt handler
 ******************************************************************************
 */
static void PwcOverflowIntHandler(void)
{
    /* user code here */
    m_u32CntIntOverflow++;
}

/*!
 ******************************************************************************
 ** \brief PWC measure complete interrupt handler
 ******************************************************************************
 */
static void PwcMeasCmpIrqHandler(void)
{
    /* user code here */
    if (m_u32CntIntMeasure < MEASURE_CNT_MAX)
    {  
        if (USER_BT_TIMER_SIZE == PwcSize16Bit) 
        {
            m_aMeasureResult[m_u32CntIntMeasure] = Bt_Pwc_Get16BitMeasureData(&USER_BT_PWC) +
                (m_u32CntIntOverflow * 0xffff);
        }
        else /* BT_32IT_TIMER */
        {
            m_aMeasureResult[m_u32CntIntMeasure] = Bt_Pwc_Get32BitMeasureData(&USER_BT_PWC);
        }             
        m_u32CntIntMeasure++;
    } 
    else
    {
        if (USER_BT_TIMER_SIZE == PwcSize16Bit) 
        {
            Bt_Pwc_Get16BitMeasureData(&USER_BT_PWC);
        }
        else
        {
            Bt_Pwc_Get32BitMeasureData(&USER_BT_PWC);
        }
    }
    m_u32CntIntOverflow = 0;
}


/* [] END OF FILE */
