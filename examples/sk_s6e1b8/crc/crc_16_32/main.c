/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            This example shows how to use Cyclic Redundancy Check(CRC) driver
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

#define EXPECTED_CRC_VALUE                                            0x6AEA5AF1UL
/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
/* CRC table for check */
static const uint32_t au32ConstData[64] = {
    0x6393B370, 0xF2BB4FC0, 0x6D793D2C, 0x508B2092, 0x6697DDF6, 0xB7BF1228, 0xF7BB601A, 0x76D15ECA, 
    0x3C6FDC10, 0xA8C94C74, 0x65397F56, 0x29C5EA64, 0x9073F6CE, 0x76038E2E, 0xE183948A, 0xBB67E860, 
    0x5EABC934, 0xE5830890, 0x9D4D08D8, 0xEC1F28F8, 0xC4BBB344, 0x2C45998E, 0xEF7717DC, 0x13BFA29C, 
    0x72F92CF2, 0xE72BB6D6, 0x160512A6, 0xEA7DCCF6, 0xBD5FF930, 0xB40538CE, 0x972782C2, 0xF1FBDBE6, 
    0x4C8F38E0, 0x6A850590, 0x42312D34, 0x7E41DA84, 0x6ED15DE6, 0xF5499BF2, 0xD0A5F576, 0x5EBDA620, 
    0x091BFE16, 0xCAD17E80, 0x2727A07C, 0x274BC946, 0x2805863E, 0x068F7E80, 0x368577AE, 0x192936B4, 
    0x30D1CD26, 0x21D3E6F0, 0x7CB5CBF0, 0xABFFE464, 0xB269868E, 0x4CDB8780, 0x25D7589C, 0xB6DD4686, 
    0xD663962A, 0x67CB9FA2, 0xCD318688, 0x393DAA84, 0x71F342AA, 0x9BAFA978, 0xDE2F8EFA, 0xC3FF71FE
};

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief  Main function of project
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int main(void)
{
    stc_crc_config_t stcCrcConfig;
    uint32_t         u32CrcResult;
    uint8_t          u8Count;
    uint8_t          u8CrcError;

    u8CrcError = 0;
    
#ifdef DEBUG_PRINT
    Uart_Io_Init();
    printf("CRC test start!\n");
#endif    
/******************************************************************************/
/*                 CRC32 Test                                                 */     
/******************************************************************************/    
    stcCrcConfig.enMode              = Crc32;
    stcCrcConfig.bUseDma             = FALSE;
    stcCrcConfig.bFinalXor           = FALSE;
    stcCrcConfig.bResultLsbFirst     = FALSE;
    stcCrcConfig.bResultLittleEndian = TRUE;
    stcCrcConfig.bDataLsbFirst       = FALSE;
    stcCrcConfig.bDataLittleEndian   = TRUE;
    stcCrcConfig.u32CrcInitValue     = 0xFFFFFFFF;

/* 1. Test 32-bit pushing    */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error1!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}
    }

    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push32(au32ConstData[u8Count]);
    }

    u32CrcResult = Crc_ReadResult();
    if (EXPECTED_CRC_VALUE != u32CrcResult)
    {
#ifdef DEBUG_PRINT
        printf("CRC32 Err (32bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();

/* 2. Test 16-bit pushing */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error2!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}
    }

    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push16((uint16_t)(0xFFFF & au32ConstData[u8Count]));
        Crc_Push16((uint16_t)(0xFFFF & (au32ConstData[u8Count] >> 16)));
    }

    u32CrcResult = Crc_ReadResult();
    if (EXPECTED_CRC_VALUE != u32CrcResult)		
    {
#ifdef DEBUG_PRINT
        printf("CRC32 Err (16bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();

/* 3. Test 8-bit pushing */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error3!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}
    }

    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push8((uint8_t)(0xFF & au32ConstData[u8Count]));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 8)));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 16)));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 24)));
    }

    u32CrcResult = Crc_ReadResult();
    if (EXPECTED_CRC_VALUE != u32CrcResult)
    {
#ifdef DEBUG_PRINT
        printf("CRC32 Err (8bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();

/******************************************************************************/
/*                 CRC16 Test                                                 */     
/******************************************************************************/    
    stcCrcConfig.enMode              = Crc16;
    stcCrcConfig.bUseDma             = FALSE;
    stcCrcConfig.bFinalXor           = FALSE;
    stcCrcConfig.bResultLsbFirst     = FALSE;
    stcCrcConfig.bResultLittleEndian = TRUE;
    stcCrcConfig.bDataLsbFirst       = FALSE;
    stcCrcConfig.bDataLittleEndian   = TRUE;
    stcCrcConfig.u32CrcInitValue     = 0xFFFFFFFF;
    
/* 1. Test 32-bit pushing    */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error4!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}	
    }


    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push32(au32ConstData[u8Count]);
    }

    u32CrcResult = Crc_ReadResult();
    if (0x14B40000 != u32CrcResult)
    {
#ifdef DEBUG_PRINT
        printf("CRC16 Err (32bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();

/* 2. Test 16-bit pushing    */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error5!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}
    }

    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push16((uint16_t)(0xFFFF & au32ConstData[u8Count]));
        Crc_Push16((uint16_t)(0xFFFF & (au32ConstData[u8Count] >> 16)));
    }

    u32CrcResult = Crc_ReadResult();
    if (0x14B40000 != u32CrcResult)
    {
#ifdef DEBUG_PRINT
        printf("CRC16 Err (16bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();

/* 3. Test 8-bit pushing    */
    if (Ok != Crc_Init(&stcCrcConfig))
    {
#ifdef DEBUG_PRINT
        printf("Initial error6!\n");
#endif
        while(1)
		{
			/* Crc_Init() error */
		}
    }

    for (u8Count = 0; u8Count < 64; u8Count++)
    {
        Crc_Push8((uint8_t)(0xFF & au32ConstData[u8Count]));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 8)));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 16)));
        Crc_Push8((uint8_t)(0xFF & (au32ConstData[u8Count] >> 24)));
    }

    u32CrcResult = Crc_ReadResult();
    if (0x14B40000 != u32CrcResult)
    {
#ifdef DEBUG_PRINT
        printf("CRC16 Err (8bit pushing) : 0x%"PRIx32"\n", u32CrcResult);
#endif
        u8CrcError++;
    }
    Crc_DeInit();
    
    if (0 != u8CrcError)
    {
#ifdef DEBUG_PRINT
        printf("Total CRC error count : %"PRIu8"\n", u8CrcError);
#endif
    }
    else
    {
#ifdef DEBUG_PRINT
        printf("CRC test finish normally!\n");
#endif    
    }
    
    while(1)
	{
		/* your code */
	}
}


/* [] END OF FILE */
