/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            MFT FRT module running with interrupt mode
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

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pdl_header.h"

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
/*******************************************************************************
* MFT channel 
*******************************************************************************/
#define USER_MFT_CH          MFT0_FRT

/*******************************************************************************
* FRT channel 
*******************************************************************************/
#define USER_FRT_CH          MFT_FRT_CH0
#define USER_FRT_OFFSET_CH   MFT_FRT_CH1

#define USER_FRT_MODE0       FrtUpCount
#define USER_FRT_MODE1       FrtUpDownCount

#define USER_FRT_TEST_TIME   (10u)

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
stc_mft_frt_config_t stcFrtConfig;
stc_frt_irq_en_t stcFrtIrqEn;
stc_frt_irq_cb_t stcFrtIrqCallBack;
    
    
/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
/* Interrupt count value of offset mode */
#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
static uint32_t m_au32OffsetChZeroMatchCount[USER_FRT_TEST_TIME];
static uint32_t m_au32OffsetChPeakMatchCount[USER_FRT_TEST_TIME];
#endif
#endif

/* Interrupt count value of normal mode */
static uint32_t m_u32NormalCntPeakMatch;
static uint32_t m_u32NormalCntZeroMatch;

#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
/* Interrupt count value of offset mode */
static uint32_t m_u32OffsetCntPeakMatch;
static uint32_t m_u32OffsetCntZeroMatch;
#endif
#endif

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/*******************************************************************************
* Function Name: NormalFrtPeakIrqCallback
********************************************************************************
* FRT peak match interrupt handler
*******************************************************************************/
static void NormalFrtPeakIrqCallback(void)
{
    m_u32NormalCntPeakMatch++;  /* count for frt peak match */
}

/*******************************************************************************
* Function Name: NormalFrtZeroIrqCallback
********************************************************************************
* FRT zero match interrupt handler
*******************************************************************************/
static void NormalFrtZeroIrqCallback(void)
{
    m_u32NormalCntZeroMatch++; /* count for frt zero match */
}

#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)

/*******************************************************************************
* Function Name: OffsetFrtPeakIrqCallback
********************************************************************************
* FRT peak match interrupt handler
*******************************************************************************/
static void OffsetFrtPeakIrqCallback(void)
{
    m_au32OffsetChPeakMatchCount[m_u32OffsetCntPeakMatch++] = \
    Mft_Frt_GetCurCount(&USER_MFT_CH, USER_FRT_OFFSET_CH);
}

/*******************************************************************************
* Function Name: OffsetFrtZeroIrqCallback
********************************************************************************
* FRT zero match interrupt handler
*******************************************************************************/
static void OffsetFrtZeroIrqCallback(void)
{
    m_au32OffsetChZeroMatchCount[m_u32OffsetCntZeroMatch++] = \
    Mft_Frt_GetCurCount(&USER_MFT_CH, USER_FRT_OFFSET_CH);
}
#endif
#endif

/*******************************************************************************
* Function Name: InitFrtNormalMode
********************************************************************************
* Initialize the FRT in normal mode
*******************************************************************************/
void InitFrtNormalMode(void)
{
    /* Clear structures */
    PDL_ZERO_STRUCT(stcFrtConfig);
    PDL_ZERO_STRUCT(stcFrtIrqEn);
    PDL_ZERO_STRUCT(stcFrtIrqCallBack);
    
    /* Configure frt interrupt mode */
    stcFrtIrqEn.bFrtZeroMatchIrq = TRUE; /* Enable zero match interrupt */
    stcFrtIrqEn.bFrtPeakMatchIrq = TRUE; /* Enable peak match interrupt */

    /* Configure callback function of frt */
    stcFrtIrqCallBack.pfnFrtPeakIrqCb = NormalFrtPeakIrqCallback;
    stcFrtIrqCallBack.pfnFrtZeroIrqCb = NormalFrtZeroIrqCallback;
    
    /* Configure the FRT parameter */
    stcFrtConfig.enFrtMode = USER_FRT_MODE0;
    stcFrtConfig.enFrtClockDiv = FrtPclkDiv256;
    stcFrtConfig.bEnExtClock = FALSE;
    stcFrtConfig.bEnBuffer = TRUE;
    stcFrtConfig.pstcIrqEn = &stcFrtIrqEn;
    stcFrtConfig.pstcIrqCb = &stcFrtIrqCallBack;
    stcFrtConfig.bTouchNvic = TRUE;
    
    Mft_Frt_Init(&USER_MFT_CH ,USER_FRT_CH, &stcFrtConfig);    
}

/*******************************************************************************
* Function Name: InitFrtOffsetMode
********************************************************************************
* Initialize the FRT in offset mode
*******************************************************************************/
void InitFrtOffsetMode(void)
{
#if (PDL_MCU_CORE == PDL_FM4_CORE)
#if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
  
    /* Clear structures */
    PDL_ZERO_STRUCT(stcFrtConfig);
    PDL_ZERO_STRUCT(stcFrtIrqEn);
    PDL_ZERO_STRUCT(stcFrtIrqCallBack);
    
    /* Configure FRT interrupt mode */
    stcFrtIrqEn.bFrtZeroMatchIrq = TRUE; /* Enable zero match interrupt */
    stcFrtIrqEn.bFrtPeakMatchIrq = TRUE; /* Enable peak match interrupt */

    /* Configure callback function of FRT */
    stcFrtIrqCallBack.pfnFrtPeakIrqCb = OffsetFrtPeakIrqCallback;
    stcFrtIrqCallBack.pfnFrtZeroIrqCb = OffsetFrtZeroIrqCallback;
    
    /* Configure the FRT parameter */
    stcFrtConfig.enFrtMode = USER_FRT_MODE1;
    stcFrtConfig.enFrtClockDiv = FrtPclkDiv256;
    stcFrtConfig.bEnExtClock = FALSE;
    stcFrtConfig.bEnBuffer = TRUE;
    stcFrtConfig.pstcIrqEn = &stcFrtIrqEn;
    stcFrtConfig.pstcIrqCb = &stcFrtIrqCallBack;
    stcFrtConfig.bTouchNvic = TRUE;
    
    Mft_Frt_Init(&USER_MFT_CH, USER_FRT_CH, &stcFrtConfig);
#endif
#endif
}

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project for FM family.
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{
/*******************************************************************************    
* Setup the FRT in normal mode 
*******************************************************************************/
    
    /* Initialize the FRT */
    InitFrtNormalMode();

    /* Set frt cycle value */
    Mft_Frt_SetCountCycle(&USER_MFT_CH ,USER_FRT_CH, 50000u);
    /* Start frt */
    Mft_Frt_Start(&USER_MFT_CH ,USER_FRT_CH);

    m_u32NormalCntPeakMatch = 0u;
    m_u32NormalCntZeroMatch = 0u;
    
    while(1)
    {
        /* Stop FRT after occurred 10 times interrupt */
        if((m_u32NormalCntPeakMatch >= USER_FRT_TEST_TIME ) && (m_u32NormalCntZeroMatch >= USER_FRT_TEST_TIME))
        {
            Mft_Frt_Stop(&USER_MFT_CH, USER_FRT_CH);
            break;
        }
    }
    

#if (PDL_MCU_CORE == PDL_FM4_CORE)
    #if(PDL_MCU_TYPE >= PDL_FM4_TYPE3)
/*******************************************************************************
* Setup the FRT in offset mode
*******************************************************************************/    
    
    /* Initialize the FRT */
    InitFrtOffsetMode();
    
    /* Set FRT cycle value */
    Mft_Frt_SetCountCycle(&USER_MFT_CH, USER_FRT_CH, 15000u);
    /* Set offset value */
    Mft_Frt_SetCountCycle(&USER_MFT_CH, USER_FRT_OFFSET_CH, 200u);
    /* Set the ch 1 to offset mode corperating with ch.0 */
    Mft_Frt_SetOffsetMode(&USER_MFT_CH, USER_FRT_OFFSET_CH, TRUE);   
    /* Start FRT */
    Mft_Frt_Start(&USER_MFT_CH, USER_FRT_CH);
    
    m_u32OffsetCntZeroMatch = 0;
    m_u32OffsetCntPeakMatch = 0;
    while(1)
    {
        /* stop FRT after occurred 10 times interrupt */
        if((m_u32OffsetCntZeroMatch >= USER_FRT_TEST_TIME ) && (m_u32OffsetCntPeakMatch >= USER_FRT_TEST_TIME))
        {
            Mft_Frt_Stop(&USER_MFT_CH, USER_FRT_CH);            
            break;
        }
    }
    #endif
#endif

    while(1)
    {
    }
}


/* [] END OF FILE */
