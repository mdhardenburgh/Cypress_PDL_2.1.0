/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use the DSTC for software transfer.
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

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/ 
#if (PDL_MCU_CORE == PDL_FM4_CORE) 
/* Support */
#elif (PDL_MCU_CORE == PDL_FM0P_CORE)
#if (PDL_MCU_TYPE >= PDL_FM0P_TYPE2)
/* Support */
#endif
#else
#error DSTC is not available on this device!
#endif

#define DSTC_MAXDATA 16u

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
uint32_t au32SourceData[DSTC_MAXDATA];
uint32_t au32DestinationData[DSTC_MAXDATA];

boolean_t bDtscEndNotify  = FALSE;
boolean_t bDstcErrorFlasg = FALSE;

stc_dstc_des012346_t stcDstcExample;

/**
 ******************************************************************************
 ** \brief  DSTC Notify Callback
 ******************************************************************************/
void Main_DstcNotifySwCallback(void)
{
    bDtscEndNotify = TRUE;
}

/**
 ******************************************************************************
 ** \brief  DSTC Error Callback
 ******************************************************************************/
void Main_DstcErrorCallback(en_dstc_est_error_t enEstError,
                            uint16_t            u16ErrorChannel,
                            uint16_t            u16ErrorDesPointer,
                            boolean_t           bSoftwareError,
                            boolean_t           bDoubleError,
                            boolean_t           bErrorStop)
{
    bDtscEndNotify = TRUE;
    bDstcErrorFlasg = TRUE;
  
    /* Further error handling here ... */
}

/**
 ******************************************************************************
 ** \brief  Main function of PDL
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int main(void)
{
    uint8_t           u8Counter;
    stc_dstc_config_t stcDstcConfig;
    boolean_t         bCompareError = FALSE;
    
    PDL_ZERO_STRUCT(stcDstcConfig);
    
    /* Fill Source Data */
    for (u8Counter = 0; u8Counter < DSTC_MAXDATA; u8Counter++)
    {
      /* "Random" data */
      au32SourceData[u8Counter] = ((u8Counter << 8u) ^ 0x12345678u) + u8Counter;
    }
    
    /* Init Descriptor set for DES0, DES1, DES2, DES3, DES4, DES6 */
    
    /* DES0 */
    stcDstcExample.DES0.DV   = 1u;
    stcDstcExample.DES0.ST   = 0u;
    stcDstcExample.DES0.MODE = 0u;
    stcDstcExample.DES0.ORL  = 5u;
    stcDstcExample.DES0.TW   = 2u;        /* 32 Bit */
    stcDstcExample.DES0.SAC  = 1u;
    stcDstcExample.DES0.DAC  = 0u;
    stcDstcExample.DES0.CHRS = 0x14u;
    stcDstcExample.DES0.ACK  = 0u;
    stcDstcExample.DES0.CHLK = 0u;
    stcDstcExample.DES0.PCHK = DSTC_PCHK_CALC(stcDstcExample.u32DES0);
    
    /* DES1 */
    stcDstcExample.DES1_mode0.ORM = 1u;
    stcDstcExample.DES1_mode0.IIN = DSTC_MAXDATA;
    
    /* DES2 */
    stcDstcExample.DES2 = (uint32_t)&au32SourceData[0];
    
    /* DES3 */
    stcDstcExample.DES3 = (uint32_t)&au32DestinationData[0];
    
    /* DES4 */
    stcDstcExample.DES4_mode0.ORM = 1u;
    stcDstcExample.DES4_mode0.IIN = DSTC_MAXDATA;
    
    /* DES6 */
    stcDstcExample.DES6 =  (uint32_t)&au32DestinationData[0];
    
    /* Configure DSTC */
    stcDstcConfig.u32Destp               = (uint32_t)&stcDstcExample;
    stcDstcConfig.bSwInterruptEnable     = TRUE;
    stcDstcConfig.bErInterruptEnable     = TRUE;
    stcDstcConfig.bReadSkipBufferDisable = TRUE;
    stcDstcConfig.bErrorStopEnable       = TRUE;
    stcDstcConfig.enSwTransferPriority   = PriorityHighest;
    stcDstcConfig.pfnNotifySwCallback    = &Main_DstcNotifySwCallback;
    stcDstcConfig.pfnErrorCallback       = &Main_DstcErrorCallback;
    stcDstcConfig.bTouchNvic             = TRUE;
    
    Dstc_Init(&stcDstcConfig);
    
    Dstc_SwTrigger(0u);   /* Start SW transfer with DES + 0 offset */
    
    while(FALSE == bDtscEndNotify)
    {
		/* bDtscEndNotify */
	}
    
    if (TRUE == bDstcErrorFlasg)
    {
        /* Error handling */
    }
    else
    {
        for (u8Counter = 0; u8Counter < DSTC_MAXDATA; u8Counter++)
        {
            /* Check destination data */
            if (au32SourceData[u8Counter] != au32DestinationData[u8Counter])
            {
                bCompareError = TRUE;
                break;
            }
        }
    }
    
    if (TRUE == bCompareError)
    {
        /* Error handling here ... */
        __NOP();
    }

    while(1)
    {
		/* your code */
	}
}


/* [] END OF FILE */
