/*******************************************************************************
* \file             main.c
* 
* \version          1.10
*
* \brief            Read the unique ID of MCU with several method
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
#include <inttypes.h>

/*******************************************************************************
* Function Name: main
********************************************************************************
* Main function of project for FM family.
*
* \return int return value, if needed
*******************************************************************************/
int main(void)
{
    stc_unique_id_t stcUniqueId;          /* PDL structure of Unique ID register set */
    uint32_t        u32UniqueId0;         /* Unique ID 0 */
    uint32_t        u32UniqueId1;         /* Unique ID 1 */
    uint64_t        u64UniqueIdComplete;  /* Complete 41-Bit Unique ID */
    
#ifdef DEBUG_PRINT	
    Uart_Io_Init();
#endif
    
    PDL_ZERO_STRUCT(stcUniqueId);
    
    if (Ok == Uid_ReadUniqueId(&stcUniqueId))
    {
        u32UniqueId0 = Uid_ReadUniqueId0();
        u32UniqueId1 = Uid_ReadUniqueId1();
      
        if (((stcUniqueId.u32Uidr0 >> 4u) != u32UniqueId0) ||
           ((stcUniqueId.u32Uidr1      ) != u32UniqueId1))
        {
            while(1u)
            {
                /* Read Error */
            }   
        }
    }
    else
    {
        while(1u)
        {
            /* Error handling here */
        }   
    }
    
    u64UniqueIdComplete = Uid_ReadUniqueId64();
    
    if (((u64UniqueIdComplete >> 28ul)        != u32UniqueId1) ||
        ((0x0FFFFFFFul & u64UniqueIdComplete) != u32UniqueId0))
    {
         while(1u)
         {
             /* Read Error */
         }             
    }
    
#ifdef DEBUG_PRINT	
    printf("The unique ID is:\n");
    printf("Hexadecimal: %"PRIx32"%"PRIx32"\n", stcUniqueId.u32Uidr1, stcUniqueId.u32Uidr0);
    printf("Decimal: %"PRIu32"%"PRIu32"\n", stcUniqueId.u32Uidr1, stcUniqueId.u32Uidr0);
#endif
    
    while(1u)
    {
        /* Read of the unique ID is succesfully completed */
    }                  
}


/* [] END OF FILE */
