/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use the DMA for software block transfer
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

#define DMA_MAX_COUNT 256u

boolean_t   bDmaFinished = FALSE;					/* DMA finished notification flag */
uint32_t    au32SourceData[DMA_MAX_COUNT];		/* Source data (filled in main() ) */
uint32_t    au32DestinationData[DMA_MAX_COUNT];

/**
 ******************************************************************************
 ** \brief  DMA Error callback function
 ******************************************************************************/
void Main_dma_error_callback(uint8_t u8ErrorCode)
{
    /* Error handling ... Should never happen. */
}

/**
 ******************************************************************************
 ** \brief  DMNA finish callback function
 ******************************************************************************/
void Main_dma_finish_callback(void)
{
    bDmaFinished = TRUE;                  	/* Set DMA finished notification flag */
}

/**
 ******************************************************************************
 ** \brief  ADC0 initialization and single conversion start
 ******************************************************************************/
void Main_dma(void)
{
    stc_dma_config_t stcConfigDma;
    stc_dma_irq_sel_t stcIrqSel;
    stc_dma_irq_cb_t  stcIrqCb;

    /* Clear local configuration structure to zero. */
    PDL_ZERO_STRUCT(stcConfigDma);	
    PDL_ZERO_STRUCT(stcIrqSel);	
    PDL_ZERO_STRUCT(stcIrqCb);	

    /* Initialize interrupt */
    stcIrqSel.bCompleteIrq = TRUE;
    stcIrqSel.bErrorIrq    = TRUE;
    stcIrqCb.pfnDmaCompletionIrqCb = Main_dma_finish_callback;
    stcIrqCb.pfnDmaErrorIrqCb      = Main_dma_error_callback;

    /* DMMAC0 configuration */
    stcConfigDma.enDmaIdrq = Software;
    stcConfigDma.u8BlockCount = 1u;
    stcConfigDma.u16TransferCount = DMA_MAX_COUNT ;   
    stcConfigDma.enTransferMode = DmaBlockTransfer;
    stcConfigDma.enTransferWidth = Dma32Bit;
    stcConfigDma.u32SourceAddress = (uint32_t) &au32SourceData[0u];			/* Source array's address */
    stcConfigDma.u32DestinationAddress = (uint32_t) &au32DestinationData[0u];	/* Destination array's address */
    stcConfigDma.bFixedSource = FALSE;
    stcConfigDma.bFixedDestination = FALSE;
    stcConfigDma.bReloadCount = FALSE;     
    stcConfigDma.bReloadSource = FALSE;
    stcConfigDma.bReloadDestination = FALSE;
    stcConfigDma.bEnableBitMask = FALSE;
    stcConfigDma.pstcIrqCb = &stcIrqCb;
    stcConfigDma.pstcIrqEn = &stcIrqSel;
    stcConfigDma.bTouchNvic = TRUE;

    if (Ok == Dma_InitChannel(0u, &stcConfigDma))      /* Initialize DMA channel 0 */
    {    
        Dma_Enable();            /* Overall enable of DMA */

        Dma_SetChannel(0u, TRUE, FALSE, TRUE);	      /* Enable channel and software trigger */
    }
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return int return value, if needed
 ******************************************************************************/
int main(void)
{
    uint32_t  u8Count;
    boolean_t bError = FALSE;

    /* Fill Source data with "random" data */
    for (u8Count = 0; u8Count < DMA_MAX_COUNT; u8Count++)
    {
        au32SourceData[u8Count] = (uint32_t)u8Count ^ 0x12345678u;    
    }

    Main_dma();                   /* Setup DMA and start transfer */

    while(FALSE == bDmaFinished)
	{
		/* Wait for DMA finished notification flag */	
	}

    Dma_Disable();				/* Disable DMA */

    /* Compare data */
    for (u8Count = 0; u8Count < DMA_MAX_COUNT; u8Count++)
    {
        if (au32SourceData[u8Count] != au32DestinationData[u8Count])
        {
            bError = TRUE;
            break;
        }
    }

    if (TRUE == bError)
    {
        while(1)
        {
			/* Should never happen ... */
		}
    }

    while(1)
    {
		/* your code */
	}  
}


/* [] END OF FILE */
