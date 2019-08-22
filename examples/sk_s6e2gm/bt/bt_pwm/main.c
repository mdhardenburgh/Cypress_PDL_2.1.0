/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows the PWM mode of Base timer with breathing LED
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
/* Local pre-processor symbols/macros ('#define') */
/******************************************************************************/
/* BT2 parameter definition */
#define BT2_CYCLE_VALUE                 11249u
#define BT2_MAX_COUNT_VALUE             2038u
#define BT2_COUNT_THRESHOLD_VALUE       1024u
/* PWM out parameter definition */
#define PWM_CYCLE_VALUE                 1200u
#define PWM_DUTY_ADJUST_VALUE           10u

static uint32_t u32ValuePwm = 0; /* Interrupt count value */

/**
 ******************************************************************************
 ** \brief The Reload timer interrupt callback function
 **
 ** \param None
 **
 ** \retval None
 ******************************************************************************/
static void RtUnderflowIrqCallback(void)
{
    uint32_t u32LocalPwm = 0;

    u32ValuePwm++;
    if(BT2_MAX_COUNT_VALUE == u32ValuePwm)
    {
        u32ValuePwm = PWM_DUTY_ADJUST_VALUE;
    }
    if(BT2_COUNT_THRESHOLD_VALUE > u32ValuePwm)
    {
        u32LocalPwm = PWM_DUTY_ADJUST_VALUE + u32ValuePwm;
    }
    else
    {
        u32LocalPwm = BT2_MAX_COUNT_VALUE - u32ValuePwm;
    }

    Bt_Pwm_WriteDutyVal(&BT10, (PWM_CYCLE_VALUE - u32LocalPwm));
}

/**
 ******************************************************************************
 ** \brief PWM initialization
 **
 ** \param None
 **
 ** \retval None
 ******************************************************************************/
static void PWM_Init(void)
{
    stc_bt_pwm_config_t stcPwmConfig;
    stc_bt_rt_config_t stcRtConfig;
    stc_rt_irq_en_t stcIrqEn;
    stc_rt_irq_cb_t stcIrqCb;

    /* Clear structures */
    PDL_ZERO_STRUCT(stcPwmConfig);
    PDL_ZERO_STRUCT(stcRtConfig);
    PDL_ZERO_STRUCT(stcIrqEn);
    PDL_ZERO_STRUCT(stcIrqCb);

    /* BT10 (PWM) is used to driver green color of 3-color LED */
    /* Set requested I/O mode */
    /* Init Output PB2, Value: 1 (Turn off green color of 3-color LED) */
    Gpio1pin_InitOut( GPIO1PIN_PB2, Gpio1pin_InitVal( 1u ) );
    /* Init Output P18, Value: 1 (Turn off blue color of 3-color LED) */
    Gpio1pin_InitOut( GPIO1PIN_P18, Gpio1pin_InitVal( 1u ) );
    /* Uses TIOA10_1 at the output pin of BT ch.10 TIOA */
    SetPinFunc_TIOA10_1_OUT();

    /* Initialize PWM timer */
    stcPwmConfig.enPres = PwmPres1Div512;  /* PWM clock = 175kHz @ PCLK = 90MHz */
    stcPwmConfig.enMode = PwmContinuous;
    stcPwmConfig.enExtTrig = PwmExtTrigDisable;
    stcPwmConfig.enOutputMask = PwmOutputNormal;
    stcPwmConfig.enOutputPolarity = PwmPolarityLow;
    stcPwmConfig.enRestartEn = PwmRestartEnable;
    Bt_Pwm_Init(&BT10 , &stcPwmConfig);
    /* Set cycle and duty value */
    Bt_Pwm_WriteCycleVal(&BT10, PWM_CYCLE_VALUE);
    Bt_Pwm_WriteDutyVal(&BT10, PWM_CYCLE_VALUE - 10);
    /* Enable count operation */
    Bt_Pwm_EnableCount(&BT10);
    /* Start triggered by software */
    Bt_Pwm_EnableSwTrig(&BT10);

    /* BT2 (Reload Timer) is used to change the duty value every 1ms */
    stcIrqEn.bRtUnderflowIrq = 1;
    stcIrqCb.pfnRtUnderflowIrqCb = RtUnderflowIrqCallback;
    /* Initialize reload Timer */
    stcRtConfig.enPres = RtPres1Div16; /* PWM clock = 11.25MHz @ PCLK = 180MHz */
    stcRtConfig.enSize = RtSize16Bit;
    stcRtConfig.enMode = RtReload;
    stcRtConfig.pstcRtIrqCb = &stcIrqCb;
    stcRtConfig.pstcRtIrqEn = &stcIrqEn;
    stcRtConfig.bTouchNvic = TRUE;
    Bt_Rt_Init(&BT2 , &stcRtConfig);
    /* Set cycle and duty value: 11250*1/11.25MHz = 1ms(11250 = 11249 + 1) */
    Bt_Rt_WriteCycleVal(&BT2, BT2_CYCLE_VALUE);
    /* Enable count operation */
    Bt_Pwm_EnableCount(&BT2);
    /* Start triggered by software */
    Bt_Pwm_EnableSwTrig(&BT2);
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int main(void)
{
    /* Initialize PWM */
    PWM_Init();

    while(1)
	{
		/* your code */
	}
}


/* [] END OF FILE */
