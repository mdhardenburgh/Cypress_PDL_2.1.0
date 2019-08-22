/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Demonstrate the CR trimming procedure
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

/******************************************************************************
 * Local definitions
 ******************************************************************************/
#define   CR_TRIMMING_PROC_INIT                         0
#define   CR_TRIMMING_PROC_TMAXCOARSE_MEAS_INIT         1
#define   CR_TRIMMING_PROC_TMAXCOARSE_MEAS_START        2
#define   CR_TRIMMING_PROC_TMAXCOARSE_MEAS_ONGOING      3
#define   CR_TRIMMING_PROC_TMAXCOARSE_MEAS_FINISH       4
#define   CR_TRIMMING_PROC_TMINCOARSE_MEAS_INIT         5
#define   CR_TRIMMING_PROC_TMINCOARSE_MEAS_START        6
#define   CR_TRIMMING_PROC_TMINCOARSE_MEAS_ONGOING      7
#define   CR_TRIMMING_PROC_TMINCOARSE_MEAS_FINISH       8
#define   CR_TRIMMING_PROC_CAL_COARSE_VAL               9
#define   CR_TRIMMING_PROC_SET_COARSE_VAL               10
#define   CR_TRIMMING_PROC_TUNE_COARSE_VAL              11
#define   CR_TRIMMING_PROC_TMAXFINE_MEAS_INIT           21
#define   CR_TRIMMING_PROC_TMAXFINE_MEAS_START          22
#define   CR_TRIMMING_PROC_TMAXFINE_MEAS_ONGOING        23
#define   CR_TRIMMING_PROC_TMAXFINE_MEAS_FINISH         24
#define   CR_TRIMMING_PROC_TMINFINE_MEAS_INIT           25
#define   CR_TRIMMING_PROC_TMINFINE_MEAS_START          26
#define   CR_TRIMMING_PROC_TMINFINE_MEAS_ONGOING        27
#define   CR_TRIMMING_PROC_TMINFINE_MEAS_FINISH         28
#define   CR_TRIMMING_PROC_CAL_FINE_VAL                 29
#define   CR_TRIMMING_PROC_SET_FINE_VAL                 30
#define   CR_TRIMMING_PROC_TUNE_FINE_VAL                31
#define   CR_TRIMMING_PROC_FINISH                       50

#define   CR_TRIMMING_RET_OK                            0
#define   CR_TRIMMING_RET_ERR                           1

#define APB1_DIV        (1<<(APBC1_PSR_Val&0x3))
#define APB1_CLOCK      (SystemCoreClock/APB1_DIV/1000000)

/* bit6:4 111 - Uses at the pin for measuring trimming of the high-speed CR 
*  frequency division clock. */
#define TIOB0S_MEAS_CR_TRIMM_VAL                        7u
#define TIOB0S_SHIFT                                    4u
#define TIOB0S_BITS                                     3u

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
typedef struct stc_coarse_cycle
{
    float32_t f32TTarget;
    float32_t f32TMaxCoarse;
    float32_t f32TMinCoarse;

}stc_coarse_cycle_t;

typedef struct stc_fine_cycle
{
    float32_t f32TTarget;
    float32_t f32TMaxFine;
    float32_t f32TMinFine;

}stc_fine_cycle_t;

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t m_u32CntIntMeasure, m_u32CntIntOverflow;
static uint32_t m_aMeasureResult[10];

/**
 ******************************************************************************
 ** \brief  PWC measurement compete callback function
 *****************************************************************************
*/
static void PwcMeasCmpIntHandler( void )
{
    m_aMeasureResult[m_u32CntIntMeasure++] = Bt_Pwc_Get16BitMeasureData(&BT0);
}

/**
 ******************************************************************************
 ** \brief  PWC overflow callback function
 *****************************************************************************
*/
static void PwcOverflowIntHandler( void )
{
    m_u32CntIntOverflow++;
}

/**
 ******************************************************************************
 ** \brief  Calculate CR coarse value
 **
 ** \param [out] pu8CoarseData      output the CR coarse value after calculation
 ** \param [in]  pstcCrCycle        CR cycle information, refer to the calulation
 **                                 formula at the High-CR trimming chapter in PM.
 ** \return void
 **
 *****************************************************************************
*/
void CalCrCoarse( uint8_t *pu8CoarseData, stc_coarse_cycle_t *pstcCrCycle )
{
    *pu8CoarseData = (uint8_t)((pstcCrCycle->f32TTarget - (pstcCrCycle->f32TMaxCoarse - pstcCrCycle->f32TMinCoarse) /
                                (float32_t)31 - pstcCrCycle->f32TMaxCoarse) / ((pstcCrCycle->f32TMinCoarse - pstcCrCycle->f32TMaxCoarse) / (float32_t)31));
}

/**
 ******************************************************************************
 ** \brief  Calculate CR fine value
 **
 ** \param [out] pu8FineData        output the CR fine value after calculation
 ** \param [in] pstcCrCycle         CR cycle information, refer to the calulation
 **                                 formula at the High-CR trimming chapter in PM.
 ** \return void
 **
 *****************************************************************************
*/
void CalCrFine( uint8_t *pu8FineData, stc_fine_cycle_t *pstcCrCycle )
{
    *pu8FineData = (uint8_t)((pstcCrCycle->f32TTarget - (pstcCrCycle->f32TMaxFine - pstcCrCycle->f32TMinFine) /
                              (float32_t)31 - pstcCrCycle->f32TMaxFine) / ((pstcCrCycle->f32TMinFine - pstcCrCycle->f32TMaxFine) / (float32_t)31));
}


/**
 ******************************************************************************
 ** \brief  High-cr trimming procedure
 **
 ** \param [in] f32CrMinFreq        CR minimum frequency after trimming, unit:MHz
 ** \param [in] f32CrMaxFreq        CR maximum frequency after trimming, unit:MHz
 ** \param [in] f32ExpCrFreq        Expected CR value after trimming, unit:MHz
 ** \param [in] u8DefaultTempTrimData   Temperature trim data, should be
 **                                     regulated according to current temperature.
 ** \param [out] pCrTrimmingData    Pointer to final trimming data
 **
 ** \return CR trimming status
 ** \retval CR_TRIMMING_RET_OK
 ** \retval CR_TRIMMING_RET_ERR
 **
 *****************************************************************************
*/
uint8_t CrTrimmingProcess( float32_t f32CrMinFreq,
                           float32_t f32CrMaxFreq,
                           float32_t f32ExpCrFreq,
                           uint8_t u8DefaultTempTrimData,
                           uint32_t *pCrTrimmingData )
{
    uint8_t             u8TrimState       = CR_TRIMMING_PROC_INIT;
    stc_bt_pwc_config_t stcPwcConfig;
    stc_pwc_irq_en_t    stcPwcIrqEn    ;
    stc_pwc_irq_cb_t    stcPwcIrqCallback;
    uint8_t             u8TempTrimData    = u8DefaultTempTrimData;
    uint8_t             u8i               = 0;
    uint16_t            u16CrTrimData     = 0;
    uint32_t            u32MeasData       = 0;
    uint8_t             u8CoarseData      = 0;
    uint8_t             u8FineData        = 0;
    float32_t           f32TMaxCoarse     = 0;
    float32_t           f32TMinCoarse     = 0;
    float32_t           f32TMaxFine       = 0;
    float32_t           f32TMinFine       = 0;
    float32_t           f32FinalCycle     = 0;
    stc_coarse_cycle_t  stcCoarseCycle    = { 0 };
    stc_fine_cycle_t    stcFineCycle      = { 0 };

    /* Clear structures */
    PDL_ZERO_STRUCT(stcPwcIrqEn);
    PDL_ZERO_STRUCT(stcPwcIrqCallback);
    
    while (1)
    {
        switch ( u8TrimState )
        {
            case CR_TRIMMING_PROC_INIT:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_INIT\n");
#endif
                /* Set CR divider */
                Cr_SetFreqDiv(CrFreqDivBy512);

                /* Use CR as input for TIOB */
                PINRELOC_SET_EPFR(FM_GPIO->EPFR04, TIOB0S_SHIFT, TIOB0S_BITS, TIOB0S_MEAS_CR_TRIMM_VAL);

                /* Init PWC mode of BT0 */
                /* Set IO Mode */
                Bt_ConfigIOMode(&BT0, BtIoMode0);

                /* Initialize PWC interrupt structure */
                stcPwcIrqEn.bPwcMeasureCompleteIrq = 1;
                stcPwcIrqEn.bPwcMeasureOverflowIrq = 1;
                stcPwcIrqCallback.pfnPwcMeasureCompleteIrqCb = PwcMeasCmpIntHandler;
                stcPwcIrqCallback.pfnPwcMeasureOverflowIrqCb = PwcOverflowIntHandler;
                
                /* PWC register initialization */
                stcPwcConfig.enPres = PwcPresNone;
                stcPwcConfig.enMode = PwcContinuous;
                stcPwcConfig.enMeasureEdge = PwcMeasureRisingToRising;
                stcPwcConfig.enSize = PwcSize16Bit;
                stcPwcConfig.pstcPwcIrqEn = &stcPwcIrqEn;
                stcPwcConfig.pstcPwcIrqCb = &stcPwcIrqCallback;
                stcPwcConfig.bTouchNvic = TRUE;

                Bt_Pwc_Init(&BT0, &stcPwcConfig);

                u8TrimState++;
                break;

            case CR_TRIMMING_PROC_TMAXCOARSE_MEAS_INIT:
            case CR_TRIMMING_PROC_TMAXFINE_MEAS_INIT:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMAXFINE_MEAS_INIT\n");
#endif
                if (u8TrimState == CR_TRIMMING_PROC_TMAXCOARSE_MEAS_INIT)
                {
                    u8FineData = 0x00;
                    u8CoarseData = 0x00;
                }
                else
                {
                    u8FineData = 0x00;
                }
                u16CrTrimData = (u8FineData & 0x1F) | ((u8CoarseData & 0x1F) << 5);
                Cr_SetTempTrimmingData(u8TempTrimData);
                Cr_SetFreqTrimmingData(u16CrTrimData);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMAXCOARSE_MEAS_START:
            case CR_TRIMMING_PROC_TMAXFINE_MEAS_START:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMAXFINE_MEAS_START\n");
#endif
                m_u32CntIntMeasure = 0;
                /* Enable count operatoin */
                Bt_Pwc_EnableCount(&BT0);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMAXCOARSE_MEAS_ONGOING:
            case CR_TRIMMING_PROC_TMAXFINE_MEAS_ONGOING:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMAXFINE_MEAS_ONGOING\n");
#endif
                while (m_u32CntIntMeasure < 10)
                {
                    if (m_u32CntIntOverflow)
                    {
                        /* Disable count operatoin */
                        Bt_Pwc_DisableCount(&BT0);
#ifdef DEBUG_PRINT
                        printf("CR_TRIMMING_RET_ERR\n");
#endif
                        return CR_TRIMMING_RET_ERR;
                    }
                }
                /* Disable count operatoin */
                Bt_Pwc_DisableCount(&BT0);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMAXCOARSE_MEAS_FINISH:
            case CR_TRIMMING_PROC_TMAXFINE_MEAS_FINISH:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMAXFINE_MEAS_ONGOING\n");
#endif
                u32MeasData = 0;
                for ( u8i = 0; u8i < 10; u8i++ )
                {
                    u32MeasData += m_aMeasureResult[u8i];
                }
                u32MeasData = u32MeasData / 10;
                if (u8TrimState == CR_TRIMMING_PROC_TMAXCOARSE_MEAS_FINISH)
                {
                    f32TMaxCoarse = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);
                }
                else
                {
                    f32TMaxFine = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);
                }
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMINCOARSE_MEAS_INIT:
            case CR_TRIMMING_PROC_TMINFINE_MEAS_INIT:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMINFINE_MEAS_INIT\n");
#endif
                if (u8TrimState == CR_TRIMMING_PROC_TMINCOARSE_MEAS_INIT)
                {
                    u8FineData = 0x00;
                    u8CoarseData = 0x1F;
                }
                else
                {
                    u8FineData = 0x1F;
                }
                u16CrTrimData = (u8FineData & 0x1F) | ((u8CoarseData & 0x1F) << 5);
                Cr_SetTempTrimmingData(u8TempTrimData);
                Cr_SetFreqTrimmingData(u16CrTrimData);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMINCOARSE_MEAS_START:
            case CR_TRIMMING_PROC_TMINFINE_MEAS_START:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMINFINE_MEAS_START\n");
#endif
                m_u32CntIntMeasure = 0;
                /* Enable count operatoin */
                Bt_Pwc_EnableCount(&BT0);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMINCOARSE_MEAS_ONGOING:
            case CR_TRIMMING_PROC_TMINFINE_MEAS_ONGOING:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMINFINE_MEAS_ONGOING\n");
#endif
                while (m_u32CntIntMeasure < 10)
                {
                    if (m_u32CntIntOverflow)
                    {
                        /* Disable count operatoin */
                        Bt_Pwc_DisableCount(&BT0);
                        return CR_TRIMMING_RET_ERR;
                    }
                }
                /* Disable count operatoin */
                Bt_Pwc_DisableCount(&BT0);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TMINCOARSE_MEAS_FINISH:
            case CR_TRIMMING_PROC_TMINFINE_MEAS_FINISH:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TMINFINE_MEAS_FINISH\n");
#endif
                u32MeasData = 0;
                for ( u8i = 0; u8i < 10; u8i++ )
                {
                    u32MeasData += m_aMeasureResult[u8i];
                }
                u32MeasData = u32MeasData / 10;
                if (u8TrimState == CR_TRIMMING_PROC_TMINCOARSE_MEAS_FINISH)
                {
                    f32TMinCoarse = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);
                }
                else
                {
                    f32TMinFine = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);
                }
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_CAL_COARSE_VAL:
            case CR_TRIMMING_PROC_CAL_FINE_VAL:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_CAL_FINE_VAL\n");
#endif
                if (u8TrimState == CR_TRIMMING_PROC_CAL_COARSE_VAL)
                {
                    stcCoarseCycle.f32TMaxCoarse = f32TMaxCoarse;
                    stcCoarseCycle.f32TMinCoarse = f32TMinCoarse;
                    stcCoarseCycle.f32TTarget = 1 / f32ExpCrFreq;
                    CalCrCoarse(&u8CoarseData, &stcCoarseCycle);
                }
                else
                {
                    stcFineCycle.f32TMaxFine = f32TMaxFine;
                    stcFineCycle.f32TMinFine = f32TMinFine;
                    stcFineCycle.f32TTarget = 1 / f32ExpCrFreq;
                    CalCrFine(&u8FineData, &stcFineCycle);
                }
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_SET_COARSE_VAL:
            case CR_TRIMMING_PROC_SET_FINE_VAL:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_SET_FINE_VAL\n");
#endif
                if (u8TrimState ==  CR_TRIMMING_PROC_SET_COARSE_VAL)
                {
                    u8FineData = 0x00;
                    u16CrTrimData = (u8FineData & 0x1F) | ((u8CoarseData & 0x1F) << 5);
                }
                else
                {
                    u16CrTrimData = (u8FineData & 0x1F) | ((u8CoarseData & 0x1F) << 5);
                }
                Cr_SetTempTrimmingData(u8TempTrimData);
                Cr_SetFreqTrimmingData(u16CrTrimData);
                u8TrimState++;
                break;
            case CR_TRIMMING_PROC_TUNE_COARSE_VAL:
            case CR_TRIMMING_PROC_TUNE_FINE_VAL:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_TUNE_FINE_VAL\n");
#endif
                m_u32CntIntMeasure = 0;
                /* Enable count operatoin */
                Bt_Pwc_EnableCount(&BT0);

                while (m_u32CntIntMeasure < 10)
                {
                    if (m_u32CntIntOverflow)
                    {
                        /* Disable count operatoin */
                        Bt_Pwc_DisableCount(&BT0);
                        return CR_TRIMMING_RET_ERR;
                    }
#ifdef DEBUG_PRINT
                    printf("m_u32CntIntMeasure = %"PRIu32"\n", m_u32CntIntMeasure);
#endif
                }
#ifdef DEBUG_PRINT
                printf("m_u32CntIntMeasure = %"PRIu32"\n", m_u32CntIntMeasure);
#endif
                /* Disable count operatoin */
                Bt_Pwc_DisableCount(&BT0);

                u32MeasData = 0;
                for ( u8i = 0; u8i < 10; u8i++ )
                {
                    u32MeasData += m_aMeasureResult[u8i];
                }
                u32MeasData = u32MeasData / 10;
                if (u8TrimState == CR_TRIMMING_PROC_TUNE_COARSE_VAL)
                {
                    f32FinalCycle = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);

                    /* Freq > 4MHz, continue to tune */
                    if (f32FinalCycle < 1 / f32ExpCrFreq)
                    {
                        if (u8CoarseData == 0)
                        {
                            return CR_TRIMMING_RET_ERR;
                        }

                        u8CoarseData--;
                        u8TrimState--;

                    }
                    else
                    {
                        u8TrimState = CR_TRIMMING_PROC_TMAXFINE_MEAS_INIT;
                    }
                }
                else
                {
                    f32FinalCycle = (float32_t)u32MeasData / (float32_t)(APB1_CLOCK * 512);

                    if (f32FinalCycle < 1 / f32ExpCrFreq)
                    {
                        if (u8FineData == 0)
                        {
                            return CR_TRIMMING_RET_ERR;
                        }
                        u8FineData--;   /* Freq > 4MHz, sub fine data */
                    }
                    else
                    {
                        if (u8FineData == 0x1F)
                        {
                            return CR_TRIMMING_RET_ERR;
                        }
                        u8FineData++;    /* Freq < 4MHz, add fine data */
                    }

                    u8TrimState--;

                    if (f32FinalCycle > 1 / f32CrMaxFreq && f32FinalCycle < 1 / f32CrMinFreq)
                    {
                        u8TrimState = CR_TRIMMING_PROC_FINISH;
                    }

                }
                break;
            case CR_TRIMMING_PROC_FINISH:
#ifdef DEBUG_PRINT
                printf("CR_TRIMMING_PROC_FINISH\n");
#endif
                u16CrTrimData = (u8FineData & 0x1F) | ((u8CoarseData & 0x1F) << 5);
                Cr_SetTempTrimmingData(u8TempTrimData);
                Cr_SetFreqTrimmingData(u16CrTrimData);
                break;
        }

        if (u8TrimState == CR_TRIMMING_PROC_FINISH)
        {
            *pCrTrimmingData = u16CrTrimData | (u8TempTrimData << 16) | (0x00u << 24);
            break;
        }
    }

    return CR_TRIMMING_RET_OK;
}

/**
 ******************************************************************************
 ** \brief  Main function of PDL
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int main( void )
{
    uint8_t   u8TempTrimData = 0x10;
    uint32_t  u32CrTrimData;
    float32_t f32CrMaxFreq   = 4.005;
    float32_t f32CrFreq      = 4.000;
    float32_t f32CrMinFreq   = 3.995;

#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("*************************************\n");
    printf("*            CR Trimming start      *\n");
    printf("*************************************\n");
#endif

    if (CR_TRIMMING_RET_OK != CrTrimmingProcess(f32CrMinFreq, f32CrMaxFreq, f32CrFreq, u8TempTrimData, &u32CrTrimData))
    {
#ifdef DEBUG_PRINT
        printf("CR Trimming failed!\n");
#endif
        while (1)
		{
			/* CR Trimming failed */
		}	
    }

#ifdef DEBUG_PRINT
    printf("CR Trimming success!\n");
    printf("CR Trimming Data = 0x%08"PRIx32"\n", u32CrTrimData);
#endif

    /* Uncomment following to watch CR output if needed */
    /* SetPinFunc_CROUT_1(); */

    /* Use the Flash operation API to write the data into CR trimming data */
    /* address in the Flash. */

    while (1)
	{
		/* your code */		
	}
}


/* [] END OF FILE */
