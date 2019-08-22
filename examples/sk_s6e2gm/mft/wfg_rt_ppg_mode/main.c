/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example performs RT-PPG mode of MFT WFG module
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
/* FRT module */
#define USER_FRT             MFT1_FRT    
#define USER_FRT_CH          MFT_FRT_CH2
#define USER_FRT_MODE        FrtUpCount
#define USER_FRT_CYCLE       50000

/* OCU module */
#define USER_OCU             MFT1_OCU
#define USER_OCU_CH0         MFT_OCU_CH0
#define USER_OCU_CH1         MFT_OCU_CH1
#define USER_OCU_FRT_CH      USER_FRT_CH
#define USER_OCU_COUPLE_CH   MFT_OCU_CH10

#define USER_OCU_CH0_CMPVAL1 (10000)
#define USER_OCU_CH0_CMPVAL2 (20000)
#define USER_OCU_CH1_CMPVAL1 (30000)
#define USER_OCU_CH1_CMPVAL2 (40000)

/* WFG module */
#define USER_WFG              MFT1_WFG
#define USER_WFG_CH           MFT_WFG_CH10
#define WFG_GTEN_BITS         GtenBits11B 
#define WFG_PSEL_BITS         PselBits00B
#define WFG_PGEN_BITS         PgenBits11B
#define WFG_DMOD_BITS         DmodBits00B 
#define WFG_WFTA              2000
#define WFG_WFTB              WFG_WFTA
#define InitWfgOutput()       {SetPinFunc_RTO10_0(); SetPinFunc_RTO11_0();}

/* PPG module */
#define USER_PPG_CH           PPG_CH8

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint8_t m_u8Ocu0IntFlag = 0;
static uint8_t m_u8Ocu1IntFlag = 0;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/*******************************************************************************
* Function Name: Ocu0IntCallback
********************************************************************************
* OCU channel 0 interrupt callback function
*******************************************************************************/
static void Ocu0IntCallback(void)
{
    if(m_u8Ocu0IntFlag)
    {
        Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH0, USER_OCU_CH0_CMPVAL1);
    }
    else
    {
        Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH0, USER_OCU_CH0_CMPVAL2);
    }
    m_u8Ocu0IntFlag = !m_u8Ocu0IntFlag;
}

/*******************************************************************************
* Function Name: Ocu1IntCallback
********************************************************************************
* OCU channel 1 interrupt callback function
*******************************************************************************/
static void Ocu1IntCallback(void)
{
    if(m_u8Ocu1IntFlag)
    {
        Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH1, USER_OCU_CH1_CMPVAL1);
    }
    else
    {
        Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH1, USER_OCU_CH1_CMPVAL2);
    }
    m_u8Ocu1IntFlag = !m_u8Ocu1IntFlag;
}

/*******************************************************************************
* Function Name: InitFrt
********************************************************************************
* Init user free run timer
*******************************************************************************/
static void InitFrt(void)
{
    stc_mft_frt_config_t stcFrtConfig;

    /* Clear structure */
    PDL_ZERO_STRUCT(stcFrtConfig);
    
    /* Configure the FRT parameter */
    stcFrtConfig.enFrtMode = USER_FRT_MODE;
    stcFrtConfig.enFrtClockDiv = FrtPclkDiv64;
    stcFrtConfig.bEnExtClock = FALSE;
    stcFrtConfig.bEnBuffer = FALSE;

    Mft_Frt_Stop(&USER_FRT,USER_FRT_CH);
    /* Init frt module */
    Mft_Frt_Init(&USER_FRT,USER_FRT_CH,&stcFrtConfig);
    /* Set frt cycle value */
    Mft_Frt_SetCountCycle(&USER_FRT,USER_FRT_CH, USER_FRT_CYCLE);

    return;
}

/*******************************************************************************
* Function Name: InitFrt
********************************************************************************
* Init user output compare unit
*******************************************************************************/
static void InitOcu(void)
{
    stc_mft_ocu_config_t stcOcuConfig0, stcOcuConfig1;
    stc_ocu_even_compare_config_t stcCh0CompareConfig;
    stc_ocu_odd_compare_config_t  stcCh1CompareConfig;
    
    /* Clear structures */
    PDL_ZERO_STRUCT(stcOcuConfig0);
    PDL_ZERO_STRUCT(stcOcuConfig1);
    PDL_ZERO_STRUCT(stcCh0CompareConfig);
    PDL_ZERO_STRUCT(stcCh1CompareConfig);
    
    /* Configure the OCU parameter */
    stcOcuConfig0.enFrtConnect = (en_mft_ocu_frt_t)USER_OCU_FRT_CH;
    stcOcuConfig0.bFm4 = TRUE;
    stcOcuConfig0.enPinState = RtLowLevel;
    stcOcuConfig0.enOccpBufMode = OccpBufDisable;
    stcOcuConfig0.enOcseBufMode = OcseBufDisable;
    stcOcuConfig0.bIrqEnable = TRUE;
    stcOcuConfig0.pfnIrqCallback = Ocu0IntCallback;
    stcOcuConfig0.bTouchNvic = TRUE;
    
    stcOcuConfig1.enFrtConnect = (en_mft_ocu_frt_t)USER_OCU_FRT_CH;
    stcOcuConfig1.bFm4 = TRUE;
    stcOcuConfig1.enPinState = RtLowLevel;
    stcOcuConfig1.enOccpBufMode = OccpBufDisable;
    stcOcuConfig1.enOcseBufMode = OcseBufDisable;
    stcOcuConfig1.bIrqEnable = TRUE;
    stcOcuConfig1.pfnIrqCallback = Ocu1IntCallback;
    stcOcuConfig1.bTouchNvic = TRUE;

    /* Init OCU */
    Mft_Ocu_Init(&USER_OCU,USER_OCU_CH0,&stcOcuConfig0);
    Mft_Ocu_Init(&USER_OCU,USER_OCU_CH1,&stcOcuConfig1);

    /*
    1 change mode
    OCSE0:  0x00000FFF 
    OCSE1:  0x0FF00FFF 
    */
    stcCh0CompareConfig.enFrtZeroEvenMatchEvenChRtStatus = RtOutputReverse;
    stcCh0CompareConfig.enFrtZeroEvenNotMatchEvenChRtStatus = RtOutputHold;
    stcCh0CompareConfig.enFrtUpCntEvenMatchEvenChRtStatus = RtOutputReverse;
    stcCh0CompareConfig.enFrtPeakEvenMatchEvenChRtStatus = RtOutputReverse;
    stcCh0CompareConfig.enFrtPeakEvenNotMatchEvenChStatus = RtOutputHold;
    stcCh0CompareConfig.enFrtDownCntEvenMatchEvenChRtStatus = RtOutputReverse;
    stcCh0CompareConfig.enIopFlagWhenFrtZeroEvenMatch = IopFlagSet;
    stcCh0CompareConfig.enIopFlagWhenFrtUpCntEvenMatch = IopFlagSet;
    stcCh0CompareConfig.enIopFlagWhenFrtPeakEvenMatch = IopFlagSet;
    stcCh0CompareConfig.enIopFlagWhenFrtDownCntEvenMatch = IopFlagSet;
    
    stcCh1CompareConfig.enFrtZeroOddMatchEvenMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtZeroOddMatchEvenNotMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtZeroOddNotMatchEvenMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enFrtZeroOddNotMatchEvenNotMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enFrtUpCntOddMatchEvenMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtUpCntOddMatchEvenNotMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtUpCntOddNotMatchEvenMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enFrtPeakOddMatchEvenMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtPeakOddMatchEvenNotMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtPeakOddNotMatchEvenMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enFrtPeakOddNotMatchEvenNotMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enFrtDownOddMatchEvenMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtDownOddMatchEvenNotMatchOddChRtStatus = RtOutputReverse;
    stcCh1CompareConfig.enFrtDownOddNotMatchEvenMatchOddChRtStatus = RtOutputHold;
    stcCh1CompareConfig.enIopFlagWhenFrtZeroOddMatch = IopFlagSet;
    stcCh1CompareConfig.enIopFlagWhenFrtUpCntOddMatch = IopFlagSet;
    stcCh1CompareConfig.enIopFlagWhenFrtPeakOddMatch = IopFlagSet;
    stcCh1CompareConfig.enIopFlagWhenFrtDownCntOddMatch = IopFlagSet;
    
    Mft_Ocu_SetEvenChCompareMode(&USER_OCU, USER_OCU_CH0, &stcCh0CompareConfig);
    Mft_Ocu_SetOddChCompareMode(&USER_OCU, USER_OCU_CH1, &stcCh1CompareConfig);

    /* Write OCU compare value */
    Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH0,USER_OCU_CH0_CMPVAL1);
    Mft_Ocu_WriteOccp(&USER_OCU,USER_OCU_CH1,USER_OCU_CH1_CMPVAL1);

}

/*******************************************************************************
* Function Name: InitPpg
********************************************************************************
* Init User PPG module
*******************************************************************************/
static void InitPpg(void)
{
    stc_ppg_config_t stcPpgConfig;

    /* Clear structures */
    PDL_ZERO_STRUCT(stcPpgConfig);

    /* Set the ppg config value */
    stcPpgConfig.enEvenClock = PpgPclkDiv4;
    stcPpgConfig.enOddClock = PpgPclkDiv4;
    stcPpgConfig.enEvenLevel = PpgReverseLevel;
    stcPpgConfig.enOddLevel = PpgReverseLevel;
    stcPpgConfig.enTrig = PpgSoftwareTrig;
    stcPpgConfig.enMode = Ppg8Bit8Bit;

    /* Init ppg */
    Ppg_Init(USER_PPG_CH,&stcPpgConfig);
    Ppg_SetLevelWidth(USER_PPG_CH,100,100);
    Ppg_StartSoftwareTrig(USER_PPG_CH);

    return;
}

/*******************************************************************************
* Function Name: InitWfg
********************************************************************************
* Init User Waveform Generator Unit
*******************************************************************************/
static void InitWfg(void)
{
    stc_wfg_config_t stcWfgConfig;
    
    /* Clear structure */
    PDL_ZERO_STRUCT(stcWfgConfig);
    
    /* Configure WFG structure */
    stcWfgConfig.enMode = WfgRtPpgMode;
    stcWfgConfig.enPselBits = WFG_PSEL_BITS;
    stcWfgConfig.enPgenBits = WFG_PGEN_BITS;
    stcWfgConfig.enGtenBits = WFG_GTEN_BITS;
    stcWfgConfig.enDmodBits = WFG_DMOD_BITS;
    stcWfgConfig.enClk = WfgPlckDiv64;

    /* Enable WFG GPIO */
    InitWfgOutput();

    /* Config WFG module */
    Mft_Wfg_Init(&USER_WFG, USER_WFG_CH, &stcWfgConfig);

    return;
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
   
#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("==================================================\n");
    printf("          WFG Sample Start \n");
    printf(" WFG running with RT-PPG mode;\n");
    printf(" please observe the RTO10_0 and RTO11_0 output by \n oscillograph\n");
    printf(".......\n");
#endif

    /* Init FRT */
    InitFrt();
    /* Init OCU */
    InitOcu();
    /* Init PPG, use PPG0 */
    InitPpg();
    /* Init WFG */
    InitWfg();
    
    /* Start FRT */
    Mft_Frt_Start(&USER_FRT,USER_FRT_CH);
    /* Enable OCU operation */
    Mft_Ocu_EnableOperation(&USER_OCU,USER_OCU_CH0);
    Mft_Ocu_EnableOperation(&USER_OCU,USER_OCU_CH1);

    while(1)
    {
    }
}


/* [] END OF FILE */
