/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use the DSTC for hardware transfer.
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

#define DSTC_MAXDATA         (16u)

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
uint32_t au32SourceData[DSTC_MAXDATA];
uint32_t au32DestinationData[DSTC_MAXDATA];

boolean_t bDtscEndNotify  = FALSE;
boolean_t bDstcErrorFlasg = FALSE;

stc_dstc_des0123_t stcDstcExample;

stc_pwm_irq_cb_t stcIrqCb;

/**
 ******************************************************************************
 ** \brief  DSTC Notify Callback
 ******************************************************************************/
void Main_DstcBt0Callback(void)
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
  Dstc_SetHwintclrBit(DSTC_IRQ_NUMBER_BT0_IRQ0);
  Dstc_SetCommand(CmdErclr);    /* Clear DSTC error bits */
  Dstc_SetCommand(CmdMkclr);    /* Clear all DQMSK bits */
  
  bDtscEndNotify  = TRUE;
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
    uint8_t             u8Counter;
    stc_dstc_config_t   stcDstcConfig;
    stc_bt_pwm_config_t stcPwmConfig;
    stc_pwm_irq_en_t    stcPwmIrqEn;
    boolean_t           bCompareError = FALSE;
    
    PDL_ZERO_STRUCT(stcDstcConfig);
    PDL_ZERO_STRUCT(stcPwmConfig);
    PDL_ZERO_STRUCT(stcPwmIrqEn);
    
    /* Fill Source Data */
    for (u8Counter = 0; u8Counter < DSTC_MAXDATA; u8Counter++)
    {
      /* "Random" data */
      au32SourceData[u8Counter] = ((u8Counter << 8u) ^ 0x12345678u) + u8Counter;
    }
    
    /* Initialize BT interrupts */
    stcPwmIrqEn.bPwmUnderflowIrq = TRUE;
    
    /* Set requested BT I/O mode */
    Bt_ConfigIOMode(&BT0, BtIoMode0);
    
    /* Initialize BT as PWM timer */
    stcPwmConfig.enPres           = PwmPres1Div4;
    stcPwmConfig.enMode           = PwmOneshot; 
    stcPwmConfig.enExtTrig        = PwmExtTrigDisable;
    stcPwmConfig.enOutputMask     = PwmOutputNormal;
    stcPwmConfig.enOutputPolarity = PwmPolarityLow;
    stcPwmConfig.enRestartEn      = PwmRestartDisable;
    stcPwmConfig.pstcPwmIrqEn     = &stcPwmIrqEn;
    stcPwmConfig.bTouchNvic       = TRUE;
    Bt_Pwm_Init(&BT0, &stcPwmConfig);
    
    Bt_Pwm_WriteCycleVal(&BT0, 55655u);     /* just some values ... */
    Bt_Pwm_WriteDutyVal(&BT0, 33u); 
     
    /* Enable BT count operatoin */
    Bt_Pwm_EnableCount(&BT0);
    
    /* Init Descriptor set for DES0, DES1, DES2, DES3, DES4, DES6 */
    
    /* DES0 */
    stcDstcExample.DES0.DV    = 1u;
    stcDstcExample.DES0.ST    = 0u;
    stcDstcExample.DES0.MODE  = 0u;       /* Mode 0 */
    stcDstcExample.DES0.ORL   = 0u;       /* No reload from DES4, DES5, DES6. The descriptor only includes DES0, DES1, DES2, DES3. */
    stcDstcExample.DES0.TW    = 2u;       /* 32 Bit */
    stcDstcExample.DES0.SAC   = 1u;       /* The address is increased by TW��1 at every transfer with InnerReload. */
    stcDstcExample.DES0.DAC   = 0u;       /* The address is increased by TW��1 at every transfer without InnerReload. */
    stcDstcExample.DES0.CHRS  = 0x10u;    /* An interrupt flag has been set when IRM =1 and ORM = 1 */
    stcDstcExample.DES0.DMSET = 0u;       /* Set BT0 mask bit */
    stcDstcExample.DES0.ACK   = 1u;       /* Send acknowledge to BT0 */
    stcDstcExample.DES0.CHLK  = 0u;       
    stcDstcExample.DES0.PCHK  = DSTC_PCHK_CALC(stcDstcExample.u32DES0);
    
    /* DES1 */
    stcDstcExample.DES1_mode0.ORM = 1u;
    stcDstcExample.DES1_mode0.IIN = DSTC_MAXDATA;
    
    /* DES2 */
    stcDstcExample.DES2 = (uint32_t)&au32SourceData[0];
    
    /* DES3 */
    stcDstcExample.DES3 = (uint32_t)&au32DestinationData[0];
    
    /* Configure DSTC */
    stcDstcConfig.u32Destp               = (uint32_t)&stcDstcExample;
    stcDstcConfig.bSwInterruptEnable     = FALSE;
    stcDstcConfig.bErInterruptEnable     = TRUE;
    stcDstcConfig.bReadSkipBufferDisable = FALSE;
    stcDstcConfig.bErrorStopEnable       = TRUE;
    stcDstcConfig.enSwTransferPriority   = Priority1_31;
    stcDstcConfig.pfnErrorCallback       = &Main_DstcErrorCallback;
    stcDstcConfig.pfnDstcBt0Irq0Callback = &Main_DstcBt0Callback;
    stcDstcConfig.bTouchNvic             = TRUE;
    
    Dstc_Init(&stcDstcConfig);
    Dstc_SetCommand(CmdErclr);
    Dstc_SetCommand(CmdRbclr);
    Dstc_SetHwdesp(DSTC_IRQ_NUMBER_BT0_IRQ0, 0u); /* BT0, DES Offset 0 */
    Dstc_SetDreqenbBit(DSTC_IRQ_NUMBER_BT0_IRQ0); /* Switch BT0 to DSTC */
    
    /* Start BT triggered by software */
    Bt_Pwm_EnableSwTrig(&BT0);
    
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
