/*******************************************************************************
* Copyright (C) 2013-2016, Cypress Semiconductor Corporation or a              *
* subsidiary of Cypress Semiconductor Corporation.  All rights reserved.       *
*                                                                              *
* This software, including source code, documentation and related              *
* materials ("Software"), is owned by Cypress Semiconductor Corporation or     *
* one of its subsidiaries ("Cypress") and is protected by and subject to       *
* worldwide patent protection (United States and foreign), United States       *
* copyright laws and international treaty provisions. Therefore, you may use   *
* this Software only as provided in the license agreement accompanying the     *
* software package from which you obtained this Software ("EULA").             *
*                                                                              *
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,     *
* non-transferable license to copy, modify, and compile the                    *
* Software source code solely for use in connection with Cypress's             *
* integrated circuit products.  Any reproduction, modification, translation,   *
* compilation, or representation of this Software except as specified          *
* above is prohibited without the express written permission of Cypress.       *
*                                                                              *
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO                         *
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,                         *
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED                                 *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A                              *
* PARTICULAR PURPOSE. Cypress reserves the right to make                       *
* changes to the Software without notice. Cypress does not assume any          *
* liability arising out of the application or use of the Software or any       *
* product or circuit described in the Software. Cypress does not               *
* authorize its products for use in any products where a malfunction or        *
* failure of the Cypress product may reasonably be expected to result in       *
* significant property damage, injury or death ("High Risk Product"). By       *
* including Cypress's product in a High Risk Product, the manufacturer         *
* of such system or application assumes all risk of such use and in doing      *
* so agrees to indemnify Cypress against all liability.                        *
*******************************************************************************/
/** \file gpio_s6e1b3xg.h
 **
 ** Header file for S6E1B3XG GPIO functions, included in gpio.h
 **
 ** History:
 **   - 2015-12-04  2.0  NOSU	Clean ALL FM Series pin files
 **
 ** Timestamp:
 **   - 2015-12-16 18:30:18  Auto created by GpioHeaderGenerator Rev 1.0.0
 **
 ******************************************************************************/

#ifndef __GPIO_S6E1B3XG_H__
#define __GPIO_S6E1B3XG_H__

#include <stdint.h>

#define PINCONFIG_SET_REG(pinreg,pos,width,value)    \
          ((pinreg) = (((pinreg) & ~(((1u<<(width))-1u)<<(pos))) | \
          ((value) << (pos))))

/******************************************************************************
   GPIO
*******************************************************************************/

/*---- GPIO bit P00 ----*/
#define GPIO1PIN_P00_GET                ( bFM_GPIO_PDIR0_P0 )

#define GPIO1PIN_P00_PUT(v)             ( bFM_GPIO_PDOR0_P0=(v) )

#define GPIO1PIN_P00_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P00_INITIN(v) \
                                                           : GPIO1PIN_P00_INITOUT(v) )

#define GPIO1PIN_P00_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P0=(v).bPullup; \
                                            bFM_GPIO_DDR0_P0=0u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

#define GPIO1PIN_P00_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P0=1u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

/*---- GPIO bit NP00 ----*/
#define GPIO1PIN_NP00_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P0)) )

#define GPIO1PIN_NP00_PUT(v)            ( bFM_GPIO_PDOR0_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP00_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP00_INITIN(v) \
                                                           : GPIO1PIN_NP00_INITOUT(v) )

#define GPIO1PIN_NP00_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P0=(v).bPullup; \
                                            bFM_GPIO_DDR0_P0=0u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

#define GPIO1PIN_NP00_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P0=1u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

/*---- GPIO bit P01 ----*/
#define GPIO1PIN_P01_GET                ( bFM_GPIO_PDIR0_P1 )

#define GPIO1PIN_P01_PUT(v)             ( bFM_GPIO_PDOR0_P1=(v) )

#define GPIO1PIN_P01_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P01_INITIN(v) \
                                                           : GPIO1PIN_P01_INITOUT(v) )

#define GPIO1PIN_P01_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P1=(v).bPullup; \
                                            bFM_GPIO_DDR0_P1=0u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

#define GPIO1PIN_P01_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P1=1u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

/*---- GPIO bit NP01 ----*/
#define GPIO1PIN_NP01_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P1)) )

#define GPIO1PIN_NP01_PUT(v)            ( bFM_GPIO_PDOR0_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP01_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP01_INITIN(v) \
                                                           : GPIO1PIN_NP01_INITOUT(v) )

#define GPIO1PIN_NP01_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P1=(v).bPullup; \
                                            bFM_GPIO_DDR0_P1=0u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

#define GPIO1PIN_NP01_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P1=1u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

/*---- GPIO bit P02 ----*/
#define GPIO1PIN_P02_GET                ( bFM_GPIO_PDIR0_P2 )

#define GPIO1PIN_P02_PUT(v)             ( bFM_GPIO_PDOR0_P2=(v) )

#define GPIO1PIN_P02_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P02_INITIN(v) \
                                                           : GPIO1PIN_P02_INITOUT(v) )

#define GPIO1PIN_P02_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P2=(v).bPullup; \
                                            bFM_GPIO_DDR0_P2=0u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

#define GPIO1PIN_P02_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P2=1u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

/*---- GPIO bit NP02 ----*/
#define GPIO1PIN_NP02_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P2)) )

#define GPIO1PIN_NP02_PUT(v)            ( bFM_GPIO_PDOR0_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP02_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP02_INITIN(v) \
                                                           : GPIO1PIN_NP02_INITOUT(v) )

#define GPIO1PIN_NP02_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P2=(v).bPullup; \
                                            bFM_GPIO_DDR0_P2=0u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

#define GPIO1PIN_NP02_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P2=1u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

/*---- GPIO bit P03 ----*/
#define GPIO1PIN_P03_GET                ( bFM_GPIO_PDIR0_P3 )

#define GPIO1PIN_P03_PUT(v)             ( bFM_GPIO_PDOR0_P3=(v) )

#define GPIO1PIN_P03_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P03_INITIN(v) \
                                                           : GPIO1PIN_P03_INITOUT(v) )

#define GPIO1PIN_P03_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P3=(v).bPullup; \
                                            bFM_GPIO_DDR0_P3=0u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

#define GPIO1PIN_P03_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P3=1u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

/*---- GPIO bit NP03 ----*/
#define GPIO1PIN_NP03_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P3)) )

#define GPIO1PIN_NP03_PUT(v)            ( bFM_GPIO_PDOR0_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP03_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP03_INITIN(v) \
                                                           : GPIO1PIN_NP03_INITOUT(v) )

#define GPIO1PIN_NP03_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P3=(v).bPullup; \
                                            bFM_GPIO_DDR0_P3=0u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

#define GPIO1PIN_NP03_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P3=1u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

/*---- GPIO bit P04 ----*/
#define GPIO1PIN_P04_GET                ( bFM_GPIO_PDIR0_P4 )

#define GPIO1PIN_P04_PUT(v)             ( bFM_GPIO_PDOR0_P4=(v) )

#define GPIO1PIN_P04_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P04_INITIN(v) \
                                                           : GPIO1PIN_P04_INITOUT(v) )

#define GPIO1PIN_P04_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P4=(v).bPullup; \
                                            bFM_GPIO_DDR0_P4=0u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

#define GPIO1PIN_P04_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P4=1u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

/*---- GPIO bit NP04 ----*/
#define GPIO1PIN_NP04_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P4)) )

#define GPIO1PIN_NP04_PUT(v)            ( bFM_GPIO_PDOR0_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP04_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP04_INITIN(v) \
                                                           : GPIO1PIN_NP04_INITOUT(v) )

#define GPIO1PIN_NP04_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P4=(v).bPullup; \
                                            bFM_GPIO_DDR0_P4=0u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

#define GPIO1PIN_NP04_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P4=1u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

/*---- GPIO bit P05 ----*/
#define GPIO1PIN_P05_GET                ( bFM_GPIO_PDIR0_P5 )

#define GPIO1PIN_P05_PUT(v)             ( bFM_GPIO_PDOR0_P5=(v) )

#define GPIO1PIN_P05_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P05_INITIN(v) \
                                                           : GPIO1PIN_P05_INITOUT(v) )

#define GPIO1PIN_P05_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PCR0_P5=(v).bPullup; \
                                            bFM_GPIO_DDR0_P5=0u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

#define GPIO1PIN_P05_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PDOR0_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P5=1u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

/*---- GPIO bit NP05 ----*/
#define GPIO1PIN_NP05_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P5)) )

#define GPIO1PIN_NP05_PUT(v)            ( bFM_GPIO_PDOR0_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP05_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP05_INITIN(v) \
                                                           : GPIO1PIN_NP05_INITOUT(v) )

#define GPIO1PIN_NP05_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PCR0_P5=(v).bPullup; \
                                            bFM_GPIO_DDR0_P5=0u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

#define GPIO1PIN_NP05_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PDOR0_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P5=1u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

/*---- GPIO bit P06 ----*/
#define GPIO1PIN_P06_GET                ( bFM_GPIO_PDIR0_P6 )

#define GPIO1PIN_P06_PUT(v)             ( bFM_GPIO_PDOR0_P6=(v) )

#define GPIO1PIN_P06_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P06_INITIN(v) \
                                                           : GPIO1PIN_P06_INITOUT(v) )

#define GPIO1PIN_P06_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PCR0_P6=(v).bPullup; \
                                            bFM_GPIO_DDR0_P6=0u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

#define GPIO1PIN_P06_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PDOR0_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P6=1u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

/*---- GPIO bit NP06 ----*/
#define GPIO1PIN_NP06_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P6)) )

#define GPIO1PIN_NP06_PUT(v)            ( bFM_GPIO_PDOR0_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP06_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP06_INITIN(v) \
                                                           : GPIO1PIN_NP06_INITOUT(v) )

#define GPIO1PIN_NP06_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PCR0_P6=(v).bPullup; \
                                            bFM_GPIO_DDR0_P6=0u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

#define GPIO1PIN_NP06_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PDOR0_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P6=1u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

/*---- GPIO bit P07 ----*/
#define GPIO1PIN_P07_GET                ( bFM_GPIO_PDIR0_P7 )

#define GPIO1PIN_P07_PUT(v)             ( bFM_GPIO_PDOR0_P7=(v) )

#define GPIO1PIN_P07_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P07_INITIN(v) \
                                                           : GPIO1PIN_P07_INITOUT(v) )

#define GPIO1PIN_P07_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PCR0_P7=(v).bPullup; \
                                            bFM_GPIO_DDR0_P7=0u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

#define GPIO1PIN_P07_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PDOR0_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P7=1u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

/*---- GPIO bit NP07 ----*/
#define GPIO1PIN_NP07_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P7)) )

#define GPIO1PIN_NP07_PUT(v)            ( bFM_GPIO_PDOR0_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP07_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP07_INITIN(v) \
                                                           : GPIO1PIN_NP07_INITOUT(v) )

#define GPIO1PIN_NP07_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PCR0_P7=(v).bPullup; \
                                            bFM_GPIO_DDR0_P7=0u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

#define GPIO1PIN_NP07_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PDOR0_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P7=1u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

/*---- GPIO bit P08 ----*/
#define GPIO1PIN_P08_GET                ( bFM_GPIO_PDIR0_P8 )

#define GPIO1PIN_P08_PUT(v)             ( bFM_GPIO_PDOR0_P8=(v) )

#define GPIO1PIN_P08_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P08_INITIN(v) \
                                                           : GPIO1PIN_P08_INITOUT(v) )

#define GPIO1PIN_P08_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PCR0_P8=(v).bPullup; \
                                            bFM_GPIO_DDR0_P8=0u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

#define GPIO1PIN_P08_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PDOR0_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P8=1u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

/*---- GPIO bit NP08 ----*/
#define GPIO1PIN_NP08_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P8)) )

#define GPIO1PIN_NP08_PUT(v)            ( bFM_GPIO_PDOR0_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP08_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP08_INITIN(v) \
                                                           : GPIO1PIN_NP08_INITOUT(v) )

#define GPIO1PIN_NP08_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PCR0_P8=(v).bPullup; \
                                            bFM_GPIO_DDR0_P8=0u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

#define GPIO1PIN_NP08_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PDOR0_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P8=1u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

/*---- GPIO bit P09 ----*/
#define GPIO1PIN_P09_GET                ( bFM_GPIO_PDIR0_P9 )

#define GPIO1PIN_P09_PUT(v)             ( bFM_GPIO_PDOR0_P9=(v) )

#define GPIO1PIN_P09_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P09_INITIN(v) \
                                                           : GPIO1PIN_P09_INITOUT(v) )

#define GPIO1PIN_P09_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_P9=(v).bPullup; \
                                            bFM_GPIO_DDR0_P9=0u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

#define GPIO1PIN_P09_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_P9=(v).bInitVal; \
                                            bFM_GPIO_DDR0_P9=1u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

/*---- GPIO bit NP09 ----*/
#define GPIO1PIN_NP09_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_P9)) )

#define GPIO1PIN_NP09_PUT(v)            ( bFM_GPIO_PDOR0_P9=(uint32_t)(!(v)) )

#define GPIO1PIN_NP09_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP09_INITIN(v) \
                                                           : GPIO1PIN_NP09_INITOUT(v) )

#define GPIO1PIN_NP09_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P9=(v).bPullup; \
                                            bFM_GPIO_DDR0_P9=0u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

#define GPIO1PIN_NP09_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_P9=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_P9=1u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

/*---- GPIO bit P0A ----*/
#define GPIO1PIN_P0A_GET                ( bFM_GPIO_PDIR0_PA )

#define GPIO1PIN_P0A_PUT(v)             ( bFM_GPIO_PDOR0_PA=(v) )

#define GPIO1PIN_P0A_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0A_INITIN(v) \
                                                           : GPIO1PIN_P0A_INITOUT(v) )

#define GPIO1PIN_P0A_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_PA=(v).bPullup; \
                                            bFM_GPIO_DDR0_PA=0u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

#define GPIO1PIN_P0A_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_PA=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PA=1u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

/*---- GPIO bit NP0A ----*/
#define GPIO1PIN_NP0A_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PA)) )

#define GPIO1PIN_NP0A_PUT(v)            ( bFM_GPIO_PDOR0_PA=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0A_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0A_INITIN(v) \
                                                           : GPIO1PIN_NP0A_INITOUT(v) )

#define GPIO1PIN_NP0A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PA=(v).bPullup; \
                                            bFM_GPIO_DDR0_PA=0u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

#define GPIO1PIN_NP0A_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_PA=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PA=1u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

/*---- GPIO bit P0B ----*/
#define GPIO1PIN_P0B_GET                ( bFM_GPIO_PDIR0_PB )

#define GPIO1PIN_P0B_PUT(v)             ( bFM_GPIO_PDOR0_PB=(v) )

#define GPIO1PIN_P0B_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0B_INITIN(v) \
                                                           : GPIO1PIN_P0B_INITOUT(v) )

#define GPIO1PIN_P0B_INITIN(v)          do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PB=(v).bPullup; \
                                            bFM_GPIO_DDR0_PB=0u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

#define GPIO1PIN_P0B_INITOUT(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PDOR0_PB=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PB=1u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

/*---- GPIO bit NP0B ----*/
#define GPIO1PIN_NP0B_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PB)) )

#define GPIO1PIN_NP0B_PUT(v)            ( bFM_GPIO_PDOR0_PB=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0B_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0B_INITIN(v) \
                                                           : GPIO1PIN_NP0B_INITOUT(v) )

#define GPIO1PIN_NP0B_INITIN(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PB=(v).bPullup; \
                                            bFM_GPIO_DDR0_PB=0u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

#define GPIO1PIN_NP0B_INITOUT(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PDOR0_PB=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PB=1u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

/*---- GPIO bit P0C ----*/
#define GPIO1PIN_P0C_GET                ( bFM_GPIO_PDIR0_PC )

#define GPIO1PIN_P0C_PUT(v)             ( bFM_GPIO_PDOR0_PC=(v) )

#define GPIO1PIN_P0C_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0C_INITIN(v) \
                                                           : GPIO1PIN_P0C_INITOUT(v) )

#define GPIO1PIN_P0C_INITIN(v)          do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PC=(v).bPullup; \
                                            bFM_GPIO_DDR0_PC=0u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

#define GPIO1PIN_P0C_INITOUT(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PDOR0_PC=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PC=1u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

/*---- GPIO bit NP0C ----*/
#define GPIO1PIN_NP0C_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PC)) )

#define GPIO1PIN_NP0C_PUT(v)            ( bFM_GPIO_PDOR0_PC=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0C_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0C_INITIN(v) \
                                                           : GPIO1PIN_NP0C_INITOUT(v) )

#define GPIO1PIN_NP0C_INITIN(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PC=(v).bPullup; \
                                            bFM_GPIO_DDR0_PC=0u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

#define GPIO1PIN_NP0C_INITOUT(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PDOR0_PC=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PC=1u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

/*---- GPIO bit P0D ----*/
#define GPIO1PIN_P0D_GET                ( bFM_GPIO_PDIR0_PD )

#define GPIO1PIN_P0D_PUT(v)             ( bFM_GPIO_PDOR0_PD=(v) )

#define GPIO1PIN_P0D_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0D_INITIN(v) \
                                                           : GPIO1PIN_P0D_INITOUT(v) )

#define GPIO1PIN_P0D_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_PD=(v).bPullup; \
                                            bFM_GPIO_DDR0_PD=0u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

#define GPIO1PIN_P0D_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_PD=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PD=1u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

/*---- GPIO bit NP0D ----*/
#define GPIO1PIN_NP0D_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PD)) )

#define GPIO1PIN_NP0D_PUT(v)            ( bFM_GPIO_PDOR0_PD=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0D_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0D_INITIN(v) \
                                                           : GPIO1PIN_NP0D_INITOUT(v) )

#define GPIO1PIN_NP0D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PD=(v).bPullup; \
                                            bFM_GPIO_DDR0_PD=0u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

#define GPIO1PIN_NP0D_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_PD=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PD=1u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

/*---- GPIO bit P0E ----*/
#define GPIO1PIN_P0E_GET                ( bFM_GPIO_PDIR0_PE )

#define GPIO1PIN_P0E_PUT(v)             ( bFM_GPIO_PDOR0_PE=(v) )

#define GPIO1PIN_P0E_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0E_INITIN(v) \
                                                           : GPIO1PIN_P0E_INITOUT(v) )

#define GPIO1PIN_P0E_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_PE=(v).bPullup; \
                                            bFM_GPIO_DDR0_PE=0u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

#define GPIO1PIN_P0E_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_PE=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PE=1u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

/*---- GPIO bit NP0E ----*/
#define GPIO1PIN_NP0E_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PE)) )

#define GPIO1PIN_NP0E_PUT(v)            ( bFM_GPIO_PDOR0_PE=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0E_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0E_INITIN(v) \
                                                           : GPIO1PIN_NP0E_INITOUT(v) )

#define GPIO1PIN_NP0E_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PE=(v).bPullup; \
                                            bFM_GPIO_DDR0_PE=0u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

#define GPIO1PIN_NP0E_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_PE=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PE=1u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

/*---- GPIO bit P0F ----*/
#define GPIO1PIN_P0F_GET                ( bFM_GPIO_PDIR0_PF )

#define GPIO1PIN_P0F_PUT(v)             ( bFM_GPIO_PDOR0_PF=(v) )

#define GPIO1PIN_P0F_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P0F_INITIN(v) \
                                                           : GPIO1PIN_P0F_INITOUT(v) )

#define GPIO1PIN_P0F_INITIN(v)          do{ \
                                            bFM_GPIO_PCR0_PF=(v).bPullup; \
                                            bFM_GPIO_DDR0_PF=0u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

#define GPIO1PIN_P0F_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR0_PF=(v).bInitVal; \
                                            bFM_GPIO_DDR0_PF=1u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

/*---- GPIO bit NP0F ----*/
#define GPIO1PIN_NP0F_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR0_PF)) )

#define GPIO1PIN_NP0F_PUT(v)            ( bFM_GPIO_PDOR0_PF=(uint32_t)(!(v)) )

#define GPIO1PIN_NP0F_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP0F_INITIN(v) \
                                                           : GPIO1PIN_NP0F_INITOUT(v) )

#define GPIO1PIN_NP0F_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PF=(v).bPullup; \
                                            bFM_GPIO_DDR0_PF=0u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

#define GPIO1PIN_NP0F_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR0_PF=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR0_PF=1u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

/*---- GPIO bit P10 ----*/
#define GPIO1PIN_P10_GET                ( bFM_GPIO_PDIR1_P0 )

#define GPIO1PIN_P10_PUT(v)             ( bFM_GPIO_PDOR1_P0=(v) )

#define GPIO1PIN_P10_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P10_INITIN(v) \
                                                           : GPIO1PIN_P10_INITOUT(v) )

#define GPIO1PIN_P10_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PCR1_P0=(v).bPullup; \
                                            bFM_GPIO_DDR1_P0=0u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

#define GPIO1PIN_P10_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PDOR1_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P0=1u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

/*---- GPIO bit NP10 ----*/
#define GPIO1PIN_NP10_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P0)) )

#define GPIO1PIN_NP10_PUT(v)            ( bFM_GPIO_PDOR1_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP10_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP10_INITIN(v) \
                                                           : GPIO1PIN_NP10_INITOUT(v) )

#define GPIO1PIN_NP10_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PCR1_P0=(v).bPullup; \
                                            bFM_GPIO_DDR1_P0=0u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

#define GPIO1PIN_NP10_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PDOR1_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P0=1u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

/*---- GPIO bit P11 ----*/
#define GPIO1PIN_P11_GET                ( bFM_GPIO_PDIR1_P1 )

#define GPIO1PIN_P11_PUT(v)             ( bFM_GPIO_PDOR1_P1=(v) )

#define GPIO1PIN_P11_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P11_INITIN(v) \
                                                           : GPIO1PIN_P11_INITOUT(v) )

#define GPIO1PIN_P11_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PCR1_P1=(v).bPullup; \
                                            bFM_GPIO_DDR1_P1=0u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

#define GPIO1PIN_P11_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PDOR1_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P1=1u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

/*---- GPIO bit NP11 ----*/
#define GPIO1PIN_NP11_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P1)) )

#define GPIO1PIN_NP11_PUT(v)            ( bFM_GPIO_PDOR1_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP11_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP11_INITIN(v) \
                                                           : GPIO1PIN_NP11_INITOUT(v) )

#define GPIO1PIN_NP11_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PCR1_P1=(v).bPullup; \
                                            bFM_GPIO_DDR1_P1=0u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

#define GPIO1PIN_NP11_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PDOR1_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P1=1u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

/*---- GPIO bit P12 ----*/
#define GPIO1PIN_P12_GET                ( bFM_GPIO_PDIR1_P2 )

#define GPIO1PIN_P12_PUT(v)             ( bFM_GPIO_PDOR1_P2=(v) )

#define GPIO1PIN_P12_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P12_INITIN(v) \
                                                           : GPIO1PIN_P12_INITOUT(v) )

#define GPIO1PIN_P12_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PCR1_P2=(v).bPullup; \
                                            bFM_GPIO_DDR1_P2=0u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

#define GPIO1PIN_P12_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PDOR1_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P2=1u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

/*---- GPIO bit NP12 ----*/
#define GPIO1PIN_NP12_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P2)) )

#define GPIO1PIN_NP12_PUT(v)            ( bFM_GPIO_PDOR1_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP12_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP12_INITIN(v) \
                                                           : GPIO1PIN_NP12_INITOUT(v) )

#define GPIO1PIN_NP12_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PCR1_P2=(v).bPullup; \
                                            bFM_GPIO_DDR1_P2=0u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

#define GPIO1PIN_NP12_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PDOR1_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P2=1u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

/*---- GPIO bit P13 ----*/
#define GPIO1PIN_P13_GET                ( bFM_GPIO_PDIR1_P3 )

#define GPIO1PIN_P13_PUT(v)             ( bFM_GPIO_PDOR1_P3=(v) )

#define GPIO1PIN_P13_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P13_INITIN(v) \
                                                           : GPIO1PIN_P13_INITOUT(v) )

#define GPIO1PIN_P13_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PCR1_P3=(v).bPullup; \
                                            bFM_GPIO_DDR1_P3=0u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

#define GPIO1PIN_P13_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PDOR1_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P3=1u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

/*---- GPIO bit NP13 ----*/
#define GPIO1PIN_NP13_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P3)) )

#define GPIO1PIN_NP13_PUT(v)            ( bFM_GPIO_PDOR1_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP13_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP13_INITIN(v) \
                                                           : GPIO1PIN_NP13_INITOUT(v) )

#define GPIO1PIN_NP13_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PCR1_P3=(v).bPullup; \
                                            bFM_GPIO_DDR1_P3=0u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

#define GPIO1PIN_NP13_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PDOR1_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P3=1u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

/*---- GPIO bit P14 ----*/
#define GPIO1PIN_P14_GET                ( bFM_GPIO_PDIR1_P4 )

#define GPIO1PIN_P14_PUT(v)             ( bFM_GPIO_PDOR1_P4=(v) )

#define GPIO1PIN_P14_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P14_INITIN(v) \
                                                           : GPIO1PIN_P14_INITOUT(v) )

#define GPIO1PIN_P14_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PCR1_P4=(v).bPullup; \
                                            bFM_GPIO_DDR1_P4=0u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

#define GPIO1PIN_P14_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PDOR1_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P4=1u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

/*---- GPIO bit NP14 ----*/
#define GPIO1PIN_NP14_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P4)) )

#define GPIO1PIN_NP14_PUT(v)            ( bFM_GPIO_PDOR1_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP14_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP14_INITIN(v) \
                                                           : GPIO1PIN_NP14_INITOUT(v) )

#define GPIO1PIN_NP14_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PCR1_P4=(v).bPullup; \
                                            bFM_GPIO_DDR1_P4=0u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

#define GPIO1PIN_NP14_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PDOR1_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P4=1u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

/*---- GPIO bit P15 ----*/
#define GPIO1PIN_P15_GET                ( bFM_GPIO_PDIR1_P5 )

#define GPIO1PIN_P15_PUT(v)             ( bFM_GPIO_PDOR1_P5=(v) )

#define GPIO1PIN_P15_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P15_INITIN(v) \
                                                           : GPIO1PIN_P15_INITOUT(v) )

#define GPIO1PIN_P15_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PCR1_P5=(v).bPullup; \
                                            bFM_GPIO_DDR1_P5=0u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

#define GPIO1PIN_P15_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PDOR1_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P5=1u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

/*---- GPIO bit NP15 ----*/
#define GPIO1PIN_NP15_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P5)) )

#define GPIO1PIN_NP15_PUT(v)            ( bFM_GPIO_PDOR1_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP15_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP15_INITIN(v) \
                                                           : GPIO1PIN_NP15_INITOUT(v) )

#define GPIO1PIN_NP15_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PCR1_P5=(v).bPullup; \
                                            bFM_GPIO_DDR1_P5=0u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

#define GPIO1PIN_NP15_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PDOR1_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P5=1u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

/*---- GPIO bit P16 ----*/
#define GPIO1PIN_P16_GET                ( bFM_GPIO_PDIR1_P6 )

#define GPIO1PIN_P16_PUT(v)             ( bFM_GPIO_PDOR1_P6=(v) )

#define GPIO1PIN_P16_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P16_INITIN(v) \
                                                           : GPIO1PIN_P16_INITOUT(v) )

#define GPIO1PIN_P16_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR1_P6=(v).bPullup; \
                                            bFM_GPIO_DDR1_P6=0u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

#define GPIO1PIN_P16_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PDOR1_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P6=1u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

/*---- GPIO bit NP16 ----*/
#define GPIO1PIN_NP16_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P6)) )

#define GPIO1PIN_NP16_PUT(v)            ( bFM_GPIO_PDOR1_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP16_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP16_INITIN(v) \
                                                           : GPIO1PIN_NP16_INITOUT(v) )

#define GPIO1PIN_NP16_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR1_P6=(v).bPullup; \
                                            bFM_GPIO_DDR1_P6=0u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

#define GPIO1PIN_NP16_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PDOR1_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P6=1u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

/*---- GPIO bit P17 ----*/
#define GPIO1PIN_P17_GET                ( bFM_GPIO_PDIR1_P7 )

#define GPIO1PIN_P17_PUT(v)             ( bFM_GPIO_PDOR1_P7=(v) )

#define GPIO1PIN_P17_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P17_INITIN(v) \
                                                           : GPIO1PIN_P17_INITOUT(v) )

#define GPIO1PIN_P17_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR1_P7=(v).bPullup; \
                                            bFM_GPIO_DDR1_P7=0u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

#define GPIO1PIN_P17_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PDOR1_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P7=1u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

/*---- GPIO bit NP17 ----*/
#define GPIO1PIN_NP17_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P7)) )

#define GPIO1PIN_NP17_PUT(v)            ( bFM_GPIO_PDOR1_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP17_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP17_INITIN(v) \
                                                           : GPIO1PIN_NP17_INITOUT(v) )

#define GPIO1PIN_NP17_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR1_P7=(v).bPullup; \
                                            bFM_GPIO_DDR1_P7=0u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

#define GPIO1PIN_NP17_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PDOR1_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P7=1u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

/*---- GPIO bit P18 ----*/
#define GPIO1PIN_P18_GET                ( bFM_GPIO_PDIR1_P8 )

#define GPIO1PIN_P18_PUT(v)             ( bFM_GPIO_PDOR1_P8=(v) )

#define GPIO1PIN_P18_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P18_INITIN(v) \
                                                           : GPIO1PIN_P18_INITOUT(v) )

#define GPIO1PIN_P18_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PCR1_P8=(v).bPullup; \
                                            bFM_GPIO_DDR1_P8=0u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

#define GPIO1PIN_P18_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PDOR1_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P8=1u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

/*---- GPIO bit NP18 ----*/
#define GPIO1PIN_NP18_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P8)) )

#define GPIO1PIN_NP18_PUT(v)            ( bFM_GPIO_PDOR1_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP18_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP18_INITIN(v) \
                                                           : GPIO1PIN_NP18_INITOUT(v) )

#define GPIO1PIN_NP18_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PCR1_P8=(v).bPullup; \
                                            bFM_GPIO_DDR1_P8=0u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

#define GPIO1PIN_NP18_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PDOR1_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P8=1u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

/*---- GPIO bit P19 ----*/
#define GPIO1PIN_P19_GET                ( bFM_GPIO_PDIR1_P9 )

#define GPIO1PIN_P19_PUT(v)             ( bFM_GPIO_PDOR1_P9=(v) )

#define GPIO1PIN_P19_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P19_INITIN(v) \
                                                           : GPIO1PIN_P19_INITOUT(v) )

#define GPIO1PIN_P19_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PCR1_P9=(v).bPullup; \
                                            bFM_GPIO_DDR1_P9=0u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

#define GPIO1PIN_P19_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PDOR1_P9=(v).bInitVal; \
                                            bFM_GPIO_DDR1_P9=1u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

/*---- GPIO bit NP19 ----*/
#define GPIO1PIN_NP19_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_P9)) )

#define GPIO1PIN_NP19_PUT(v)            ( bFM_GPIO_PDOR1_P9=(uint32_t)(!(v)) )

#define GPIO1PIN_NP19_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP19_INITIN(v) \
                                                           : GPIO1PIN_NP19_INITOUT(v) )

#define GPIO1PIN_NP19_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PCR1_P9=(v).bPullup; \
                                            bFM_GPIO_DDR1_P9=0u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

#define GPIO1PIN_NP19_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PDOR1_P9=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_P9=1u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

/*---- GPIO bit P1A ----*/
#define GPIO1PIN_P1A_GET                ( bFM_GPIO_PDIR1_PA )

#define GPIO1PIN_P1A_PUT(v)             ( bFM_GPIO_PDOR1_PA=(v) )

#define GPIO1PIN_P1A_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P1A_INITIN(v) \
                                                           : GPIO1PIN_P1A_INITOUT(v) )

#define GPIO1PIN_P1A_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PCR1_PA=(v).bPullup; \
                                            bFM_GPIO_DDR1_PA=0u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

#define GPIO1PIN_P1A_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PDOR1_PA=(v).bInitVal; \
                                            bFM_GPIO_DDR1_PA=1u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

/*---- GPIO bit NP1A ----*/
#define GPIO1PIN_NP1A_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_PA)) )

#define GPIO1PIN_NP1A_PUT(v)            ( bFM_GPIO_PDOR1_PA=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1A_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP1A_INITIN(v) \
                                                           : GPIO1PIN_NP1A_INITOUT(v) )

#define GPIO1PIN_NP1A_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PCR1_PA=(v).bPullup; \
                                            bFM_GPIO_DDR1_PA=0u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

#define GPIO1PIN_NP1A_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PDOR1_PA=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_PA=1u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

/*---- GPIO bit P1B ----*/
#define GPIO1PIN_P1B_GET                ( bFM_GPIO_PDIR1_PB )

#define GPIO1PIN_P1B_PUT(v)             ( bFM_GPIO_PDOR1_PB=(v) )

#define GPIO1PIN_P1B_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P1B_INITIN(v) \
                                                           : GPIO1PIN_P1B_INITOUT(v) )

#define GPIO1PIN_P1B_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PCR1_PB=(v).bPullup; \
                                            bFM_GPIO_DDR1_PB=0u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

#define GPIO1PIN_P1B_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PDOR1_PB=(v).bInitVal; \
                                            bFM_GPIO_DDR1_PB=1u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

/*---- GPIO bit NP1B ----*/
#define GPIO1PIN_NP1B_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_PB)) )

#define GPIO1PIN_NP1B_PUT(v)            ( bFM_GPIO_PDOR1_PB=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1B_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP1B_INITIN(v) \
                                                           : GPIO1PIN_NP1B_INITOUT(v) )

#define GPIO1PIN_NP1B_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PCR1_PB=(v).bPullup; \
                                            bFM_GPIO_DDR1_PB=0u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

#define GPIO1PIN_NP1B_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PDOR1_PB=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_PB=1u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

/*---- GPIO bit P1C ----*/
#define GPIO1PIN_P1C_GET                ( bFM_GPIO_PDIR1_PC )

#define GPIO1PIN_P1C_PUT(v)             ( bFM_GPIO_PDOR1_PC=(v) )

#define GPIO1PIN_P1C_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P1C_INITIN(v) \
                                                           : GPIO1PIN_P1C_INITOUT(v) )

#define GPIO1PIN_P1C_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PCR1_PC=(v).bPullup; \
                                            bFM_GPIO_DDR1_PC=0u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

#define GPIO1PIN_P1C_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PDOR1_PC=(v).bInitVal; \
                                            bFM_GPIO_DDR1_PC=1u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

/*---- GPIO bit NP1C ----*/
#define GPIO1PIN_NP1C_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_PC)) )

#define GPIO1PIN_NP1C_PUT(v)            ( bFM_GPIO_PDOR1_PC=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1C_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP1C_INITIN(v) \
                                                           : GPIO1PIN_NP1C_INITOUT(v) )

#define GPIO1PIN_NP1C_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PCR1_PC=(v).bPullup; \
                                            bFM_GPIO_DDR1_PC=0u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

#define GPIO1PIN_NP1C_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PDOR1_PC=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_PC=1u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

/*---- GPIO bit P1D ----*/
#define GPIO1PIN_P1D_GET                ( bFM_GPIO_PDIR1_PD )

#define GPIO1PIN_P1D_PUT(v)             ( bFM_GPIO_PDOR1_PD=(v) )

#define GPIO1PIN_P1D_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P1D_INITIN(v) \
                                                           : GPIO1PIN_P1D_INITOUT(v) )

#define GPIO1PIN_P1D_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PCR1_PD=(v).bPullup; \
                                            bFM_GPIO_DDR1_PD=0u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

#define GPIO1PIN_P1D_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PDOR1_PD=(v).bInitVal; \
                                            bFM_GPIO_DDR1_PD=1u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

/*---- GPIO bit NP1D ----*/
#define GPIO1PIN_NP1D_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_PD)) )

#define GPIO1PIN_NP1D_PUT(v)            ( bFM_GPIO_PDOR1_PD=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1D_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP1D_INITIN(v) \
                                                           : GPIO1PIN_NP1D_INITOUT(v) )

#define GPIO1PIN_NP1D_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PCR1_PD=(v).bPullup; \
                                            bFM_GPIO_DDR1_PD=0u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

#define GPIO1PIN_NP1D_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PDOR1_PD=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_PD=1u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

/*---- GPIO bit P1E ----*/
#define GPIO1PIN_P1E_GET                ( bFM_GPIO_PDIR1_PE )

#define GPIO1PIN_P1E_PUT(v)             ( bFM_GPIO_PDOR1_PE=(v) )

#define GPIO1PIN_P1E_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P1E_INITIN(v) \
                                                           : GPIO1PIN_P1E_INITOUT(v) )

#define GPIO1PIN_P1E_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PCR1_PE=(v).bPullup; \
                                            bFM_GPIO_DDR1_PE=0u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

#define GPIO1PIN_P1E_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PDOR1_PE=(v).bInitVal; \
                                            bFM_GPIO_DDR1_PE=1u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

/*---- GPIO bit NP1E ----*/
#define GPIO1PIN_NP1E_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR1_PE)) )

#define GPIO1PIN_NP1E_PUT(v)            ( bFM_GPIO_PDOR1_PE=(uint32_t)(!(v)) )

#define GPIO1PIN_NP1E_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP1E_INITIN(v) \
                                                           : GPIO1PIN_NP1E_INITOUT(v) )

#define GPIO1PIN_NP1E_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PCR1_PE=(v).bPullup; \
                                            bFM_GPIO_DDR1_PE=0u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

#define GPIO1PIN_NP1E_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PDOR1_PE=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR1_PE=1u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

/*---- GPIO bit P20 ----*/
#define GPIO1PIN_P20_GET                ( bFM_GPIO_PDIR2_P0 )

#define GPIO1PIN_P20_PUT(v)             ( bFM_GPIO_PDOR2_P0=(v) )

#define GPIO1PIN_P20_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P20_INITIN(v) \
                                                           : GPIO1PIN_P20_INITOUT(v) )

#define GPIO1PIN_P20_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PCR2_P0=(v).bPullup; \
                                            bFM_GPIO_DDR2_P0=0u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

#define GPIO1PIN_P20_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PDOR2_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P0=1u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

/*---- GPIO bit NP20 ----*/
#define GPIO1PIN_NP20_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P0)) )

#define GPIO1PIN_NP20_PUT(v)            ( bFM_GPIO_PDOR2_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP20_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP20_INITIN(v) \
                                                           : GPIO1PIN_NP20_INITOUT(v) )

#define GPIO1PIN_NP20_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PCR2_P0=(v).bPullup; \
                                            bFM_GPIO_DDR2_P0=0u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

#define GPIO1PIN_NP20_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PDOR2_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P0=1u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

/*---- GPIO bit P21 ----*/
#define GPIO1PIN_P21_GET                ( bFM_GPIO_PDIR2_P1 )

#define GPIO1PIN_P21_PUT(v)             ( bFM_GPIO_PDOR2_P1=(v) )

#define GPIO1PIN_P21_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P21_INITIN(v) \
                                                           : GPIO1PIN_P21_INITOUT(v) )

#define GPIO1PIN_P21_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define GPIO1PIN_P21_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PDOR2_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- GPIO bit NP21 ----*/
#define GPIO1PIN_NP21_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P1)) )

#define GPIO1PIN_NP21_PUT(v)            ( bFM_GPIO_PDOR2_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP21_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP21_INITIN(v) \
                                                           : GPIO1PIN_NP21_INITOUT(v) )

#define GPIO1PIN_NP21_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define GPIO1PIN_NP21_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PDOR2_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- GPIO bit P22 ----*/
#define GPIO1PIN_P22_GET                ( bFM_GPIO_PDIR2_P2 )

#define GPIO1PIN_P22_PUT(v)             ( bFM_GPIO_PDOR2_P2=(v) )

#define GPIO1PIN_P22_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P22_INITIN(v) \
                                                           : GPIO1PIN_P22_INITOUT(v) )

#define GPIO1PIN_P22_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define GPIO1PIN_P22_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PDOR2_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- GPIO bit NP22 ----*/
#define GPIO1PIN_NP22_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P2)) )

#define GPIO1PIN_NP22_PUT(v)            ( bFM_GPIO_PDOR2_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP22_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP22_INITIN(v) \
                                                           : GPIO1PIN_NP22_INITOUT(v) )

#define GPIO1PIN_NP22_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define GPIO1PIN_NP22_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PDOR2_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- GPIO bit P23 ----*/
#define GPIO1PIN_P23_GET                ( bFM_GPIO_PDIR2_P3 )

#define GPIO1PIN_P23_PUT(v)             ( bFM_GPIO_PDOR2_P3=(v) )

#define GPIO1PIN_P23_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P23_INITIN(v) \
                                                           : GPIO1PIN_P23_INITOUT(v) )

#define GPIO1PIN_P23_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define GPIO1PIN_P23_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PDOR2_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

/*---- GPIO bit NP23 ----*/
#define GPIO1PIN_NP23_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P3)) )

#define GPIO1PIN_NP23_PUT(v)            ( bFM_GPIO_PDOR2_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP23_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP23_INITIN(v) \
                                                           : GPIO1PIN_NP23_INITOUT(v) )

#define GPIO1PIN_NP23_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define GPIO1PIN_NP23_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PDOR2_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

/*---- GPIO bit P24 ----*/
#define GPIO1PIN_P24_GET                ( bFM_GPIO_PDIR2_P4 )

#define GPIO1PIN_P24_PUT(v)             ( bFM_GPIO_PDOR2_P4=(v) )

#define GPIO1PIN_P24_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P24_INITIN(v) \
                                                           : GPIO1PIN_P24_INITOUT(v) )

#define GPIO1PIN_P24_INITIN(v)          do{ \
                                            bFM_GPIO_PCR2_P4=(v).bPullup; \
                                            bFM_GPIO_DDR2_P4=0u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

#define GPIO1PIN_P24_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR2_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P4=1u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

/*---- GPIO bit NP24 ----*/
#define GPIO1PIN_NP24_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P4)) )

#define GPIO1PIN_NP24_PUT(v)            ( bFM_GPIO_PDOR2_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP24_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP24_INITIN(v) \
                                                           : GPIO1PIN_NP24_INITOUT(v) )

#define GPIO1PIN_NP24_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P4=(v).bPullup; \
                                            bFM_GPIO_DDR2_P4=0u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

#define GPIO1PIN_NP24_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR2_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P4=1u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

/*---- GPIO bit P25 ----*/
#define GPIO1PIN_P25_GET                ( bFM_GPIO_PDIR2_P5 )

#define GPIO1PIN_P25_PUT(v)             ( bFM_GPIO_PDOR2_P5=(v) )

#define GPIO1PIN_P25_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P25_INITIN(v) \
                                                           : GPIO1PIN_P25_INITOUT(v) )

#define GPIO1PIN_P25_INITIN(v)          do{ \
                                            bFM_GPIO_PCR2_P5=(v).bPullup; \
                                            bFM_GPIO_DDR2_P5=0u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

#define GPIO1PIN_P25_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR2_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P5=1u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

/*---- GPIO bit NP25 ----*/
#define GPIO1PIN_NP25_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P5)) )

#define GPIO1PIN_NP25_PUT(v)            ( bFM_GPIO_PDOR2_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP25_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP25_INITIN(v) \
                                                           : GPIO1PIN_NP25_INITOUT(v) )

#define GPIO1PIN_NP25_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P5=(v).bPullup; \
                                            bFM_GPIO_DDR2_P5=0u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

#define GPIO1PIN_NP25_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR2_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P5=1u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

/*---- GPIO bit P26 ----*/
#define GPIO1PIN_P26_GET                ( bFM_GPIO_PDIR2_P6 )

#define GPIO1PIN_P26_PUT(v)             ( bFM_GPIO_PDOR2_P6=(v) )

#define GPIO1PIN_P26_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P26_INITIN(v) \
                                                           : GPIO1PIN_P26_INITOUT(v) )

#define GPIO1PIN_P26_INITIN(v)          do{ \
                                            bFM_GPIO_PCR2_P6=(v).bPullup; \
                                            bFM_GPIO_DDR2_P6=0u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

#define GPIO1PIN_P26_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR2_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P6=1u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

/*---- GPIO bit NP26 ----*/
#define GPIO1PIN_NP26_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P6)) )

#define GPIO1PIN_NP26_PUT(v)            ( bFM_GPIO_PDOR2_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP26_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP26_INITIN(v) \
                                                           : GPIO1PIN_NP26_INITOUT(v) )

#define GPIO1PIN_NP26_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P6=(v).bPullup; \
                                            bFM_GPIO_DDR2_P6=0u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

#define GPIO1PIN_NP26_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR2_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P6=1u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

/*---- GPIO bit P27 ----*/
#define GPIO1PIN_P27_GET                ( bFM_GPIO_PDIR2_P7 )

#define GPIO1PIN_P27_PUT(v)             ( bFM_GPIO_PDOR2_P7=(v) )

#define GPIO1PIN_P27_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P27_INITIN(v) \
                                                           : GPIO1PIN_P27_INITOUT(v) )

#define GPIO1PIN_P27_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PCR2_P7=(v).bPullup; \
                                            bFM_GPIO_DDR2_P7=0u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

#define GPIO1PIN_P27_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PDOR2_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P7=1u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

/*---- GPIO bit NP27 ----*/
#define GPIO1PIN_NP27_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P7)) )

#define GPIO1PIN_NP27_PUT(v)            ( bFM_GPIO_PDOR2_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP27_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP27_INITIN(v) \
                                                           : GPIO1PIN_NP27_INITOUT(v) )

#define GPIO1PIN_NP27_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PCR2_P7=(v).bPullup; \
                                            bFM_GPIO_DDR2_P7=0u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

#define GPIO1PIN_NP27_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PDOR2_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P7=1u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

/*---- GPIO bit P28 ----*/
#define GPIO1PIN_P28_GET                ( bFM_GPIO_PDIR2_P8 )

#define GPIO1PIN_P28_PUT(v)             ( bFM_GPIO_PDOR2_P8=(v) )

#define GPIO1PIN_P28_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P28_INITIN(v) \
                                                           : GPIO1PIN_P28_INITOUT(v) )

#define GPIO1PIN_P28_INITIN(v)          do{ \
                                            bFM_GPIO_PCR2_P8=(v).bPullup; \
                                            bFM_GPIO_DDR2_P8=0u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

#define GPIO1PIN_P28_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR2_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P8=1u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

/*---- GPIO bit NP28 ----*/
#define GPIO1PIN_NP28_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P8)) )

#define GPIO1PIN_NP28_PUT(v)            ( bFM_GPIO_PDOR2_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP28_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP28_INITIN(v) \
                                                           : GPIO1PIN_NP28_INITOUT(v) )

#define GPIO1PIN_NP28_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P8=(v).bPullup; \
                                            bFM_GPIO_DDR2_P8=0u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

#define GPIO1PIN_NP28_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR2_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P8=1u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

/*---- GPIO bit P30 ----*/
#define GPIO1PIN_P30_GET                ( bFM_GPIO_PDIR3_P0 )

#define GPIO1PIN_P30_PUT(v)             ( bFM_GPIO_PDOR3_P0=(v) )

#define GPIO1PIN_P30_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P30_INITIN(v) \
                                                           : GPIO1PIN_P30_INITOUT(v) )

#define GPIO1PIN_P30_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P0=(v).bPullup; \
                                            bFM_GPIO_DDR3_P0=0u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

#define GPIO1PIN_P30_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P0=1u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

/*---- GPIO bit NP30 ----*/
#define GPIO1PIN_NP30_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P0)) )

#define GPIO1PIN_NP30_PUT(v)            ( bFM_GPIO_PDOR3_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP30_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP30_INITIN(v) \
                                                           : GPIO1PIN_NP30_INITOUT(v) )

#define GPIO1PIN_NP30_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P0=(v).bPullup; \
                                            bFM_GPIO_DDR3_P0=0u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

#define GPIO1PIN_NP30_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P0=1u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

/*---- GPIO bit P31 ----*/
#define GPIO1PIN_P31_GET                ( bFM_GPIO_PDIR3_P1 )

#define GPIO1PIN_P31_PUT(v)             ( bFM_GPIO_PDOR3_P1=(v) )

#define GPIO1PIN_P31_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P31_INITIN(v) \
                                                           : GPIO1PIN_P31_INITOUT(v) )

#define GPIO1PIN_P31_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P1=(v).bPullup; \
                                            bFM_GPIO_DDR3_P1=0u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

#define GPIO1PIN_P31_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P1=1u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

/*---- GPIO bit NP31 ----*/
#define GPIO1PIN_NP31_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P1)) )

#define GPIO1PIN_NP31_PUT(v)            ( bFM_GPIO_PDOR3_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP31_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP31_INITIN(v) \
                                                           : GPIO1PIN_NP31_INITOUT(v) )

#define GPIO1PIN_NP31_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P1=(v).bPullup; \
                                            bFM_GPIO_DDR3_P1=0u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

#define GPIO1PIN_NP31_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P1=1u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

/*---- GPIO bit P32 ----*/
#define GPIO1PIN_P32_GET                ( bFM_GPIO_PDIR3_P2 )

#define GPIO1PIN_P32_PUT(v)             ( bFM_GPIO_PDOR3_P2=(v) )

#define GPIO1PIN_P32_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P32_INITIN(v) \
                                                           : GPIO1PIN_P32_INITOUT(v) )

#define GPIO1PIN_P32_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P2=(v).bPullup; \
                                            bFM_GPIO_DDR3_P2=0u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

#define GPIO1PIN_P32_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P2=1u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

/*---- GPIO bit NP32 ----*/
#define GPIO1PIN_NP32_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P2)) )

#define GPIO1PIN_NP32_PUT(v)            ( bFM_GPIO_PDOR3_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP32_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP32_INITIN(v) \
                                                           : GPIO1PIN_NP32_INITOUT(v) )

#define GPIO1PIN_NP32_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P2=(v).bPullup; \
                                            bFM_GPIO_DDR3_P2=0u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

#define GPIO1PIN_NP32_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P2=1u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

/*---- GPIO bit P33 ----*/
#define GPIO1PIN_P33_GET                ( bFM_GPIO_PDIR3_P3 )

#define GPIO1PIN_P33_PUT(v)             ( bFM_GPIO_PDOR3_P3=(v) )

#define GPIO1PIN_P33_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P33_INITIN(v) \
                                                           : GPIO1PIN_P33_INITOUT(v) )

#define GPIO1PIN_P33_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P3=(v).bPullup; \
                                            bFM_GPIO_DDR3_P3=0u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

#define GPIO1PIN_P33_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P3=1u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

/*---- GPIO bit NP33 ----*/
#define GPIO1PIN_NP33_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P3)) )

#define GPIO1PIN_NP33_PUT(v)            ( bFM_GPIO_PDOR3_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP33_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP33_INITIN(v) \
                                                           : GPIO1PIN_NP33_INITOUT(v) )

#define GPIO1PIN_NP33_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P3=(v).bPullup; \
                                            bFM_GPIO_DDR3_P3=0u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

#define GPIO1PIN_NP33_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P3=1u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

/*---- GPIO bit P34 ----*/
#define GPIO1PIN_P34_GET                ( bFM_GPIO_PDIR3_P4 )

#define GPIO1PIN_P34_PUT(v)             ( bFM_GPIO_PDOR3_P4=(v) )

#define GPIO1PIN_P34_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P34_INITIN(v) \
                                                           : GPIO1PIN_P34_INITOUT(v) )

#define GPIO1PIN_P34_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P4=(v).bPullup; \
                                            bFM_GPIO_DDR3_P4=0u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

#define GPIO1PIN_P34_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P4=1u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

/*---- GPIO bit NP34 ----*/
#define GPIO1PIN_NP34_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P4)) )

#define GPIO1PIN_NP34_PUT(v)            ( bFM_GPIO_PDOR3_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP34_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP34_INITIN(v) \
                                                           : GPIO1PIN_NP34_INITOUT(v) )

#define GPIO1PIN_NP34_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P4=(v).bPullup; \
                                            bFM_GPIO_DDR3_P4=0u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

#define GPIO1PIN_NP34_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P4=1u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

/*---- GPIO bit P35 ----*/
#define GPIO1PIN_P35_GET                ( bFM_GPIO_PDIR3_P5 )

#define GPIO1PIN_P35_PUT(v)             ( bFM_GPIO_PDOR3_P5=(v) )

#define GPIO1PIN_P35_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P35_INITIN(v) \
                                                           : GPIO1PIN_P35_INITOUT(v) )

#define GPIO1PIN_P35_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P5=(v).bPullup; \
                                            bFM_GPIO_DDR3_P5=0u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

#define GPIO1PIN_P35_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P5=1u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

/*---- GPIO bit NP35 ----*/
#define GPIO1PIN_NP35_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P5)) )

#define GPIO1PIN_NP35_PUT(v)            ( bFM_GPIO_PDOR3_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP35_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP35_INITIN(v) \
                                                           : GPIO1PIN_NP35_INITOUT(v) )

#define GPIO1PIN_NP35_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P5=(v).bPullup; \
                                            bFM_GPIO_DDR3_P5=0u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

#define GPIO1PIN_NP35_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P5=1u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

/*---- GPIO bit P36 ----*/
#define GPIO1PIN_P36_GET                ( bFM_GPIO_PDIR3_P6 )

#define GPIO1PIN_P36_PUT(v)             ( bFM_GPIO_PDOR3_P6=(v) )

#define GPIO1PIN_P36_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P36_INITIN(v) \
                                                           : GPIO1PIN_P36_INITOUT(v) )

#define GPIO1PIN_P36_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P6=(v).bPullup; \
                                            bFM_GPIO_DDR3_P6=0u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

#define GPIO1PIN_P36_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P6=1u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

/*---- GPIO bit NP36 ----*/
#define GPIO1PIN_NP36_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P6)) )

#define GPIO1PIN_NP36_PUT(v)            ( bFM_GPIO_PDOR3_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP36_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP36_INITIN(v) \
                                                           : GPIO1PIN_NP36_INITOUT(v) )

#define GPIO1PIN_NP36_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P6=(v).bPullup; \
                                            bFM_GPIO_DDR3_P6=0u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

#define GPIO1PIN_NP36_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P6=1u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

/*---- GPIO bit P37 ----*/
#define GPIO1PIN_P37_GET                ( bFM_GPIO_PDIR3_P7 )

#define GPIO1PIN_P37_PUT(v)             ( bFM_GPIO_PDOR3_P7=(v) )

#define GPIO1PIN_P37_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P37_INITIN(v) \
                                                           : GPIO1PIN_P37_INITOUT(v) )

#define GPIO1PIN_P37_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P7=(v).bPullup; \
                                            bFM_GPIO_DDR3_P7=0u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

#define GPIO1PIN_P37_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P7=1u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

/*---- GPIO bit NP37 ----*/
#define GPIO1PIN_NP37_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P7)) )

#define GPIO1PIN_NP37_PUT(v)            ( bFM_GPIO_PDOR3_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP37_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP37_INITIN(v) \
                                                           : GPIO1PIN_NP37_INITOUT(v) )

#define GPIO1PIN_NP37_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P7=(v).bPullup; \
                                            bFM_GPIO_DDR3_P7=0u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

#define GPIO1PIN_NP37_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P7=1u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

/*---- GPIO bit P38 ----*/
#define GPIO1PIN_P38_GET                ( bFM_GPIO_PDIR3_P8 )

#define GPIO1PIN_P38_PUT(v)             ( bFM_GPIO_PDOR3_P8=(v) )

#define GPIO1PIN_P38_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P38_INITIN(v) \
                                                           : GPIO1PIN_P38_INITOUT(v) )

#define GPIO1PIN_P38_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P8=(v).bPullup; \
                                            bFM_GPIO_DDR3_P8=0u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

#define GPIO1PIN_P38_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P8=1u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

/*---- GPIO bit NP38 ----*/
#define GPIO1PIN_NP38_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P8)) )

#define GPIO1PIN_NP38_PUT(v)            ( bFM_GPIO_PDOR3_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP38_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP38_INITIN(v) \
                                                           : GPIO1PIN_NP38_INITOUT(v) )

#define GPIO1PIN_NP38_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P8=(v).bPullup; \
                                            bFM_GPIO_DDR3_P8=0u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

#define GPIO1PIN_NP38_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P8=1u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

/*---- GPIO bit P39 ----*/
#define GPIO1PIN_P39_GET                ( bFM_GPIO_PDIR3_P9 )

#define GPIO1PIN_P39_PUT(v)             ( bFM_GPIO_PDOR3_P9=(v) )

#define GPIO1PIN_P39_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P39_INITIN(v) \
                                                           : GPIO1PIN_P39_INITOUT(v) )

#define GPIO1PIN_P39_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_P9=(v).bPullup; \
                                            bFM_GPIO_DDR3_P9=0u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

#define GPIO1PIN_P39_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_P9=(v).bInitVal; \
                                            bFM_GPIO_DDR3_P9=1u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

/*---- GPIO bit NP39 ----*/
#define GPIO1PIN_NP39_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_P9)) )

#define GPIO1PIN_NP39_PUT(v)            ( bFM_GPIO_PDOR3_P9=(uint32_t)(!(v)) )

#define GPIO1PIN_NP39_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP39_INITIN(v) \
                                                           : GPIO1PIN_NP39_INITOUT(v) )

#define GPIO1PIN_NP39_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P9=(v).bPullup; \
                                            bFM_GPIO_DDR3_P9=0u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

#define GPIO1PIN_NP39_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_P9=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_P9=1u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

/*---- GPIO bit P3A ----*/
#define GPIO1PIN_P3A_GET                ( bFM_GPIO_PDIR3_PA )

#define GPIO1PIN_P3A_PUT(v)             ( bFM_GPIO_PDOR3_PA=(v) )

#define GPIO1PIN_P3A_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3A_INITIN(v) \
                                                           : GPIO1PIN_P3A_INITOUT(v) )

#define GPIO1PIN_P3A_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PA=(v).bPullup; \
                                            bFM_GPIO_DDR3_PA=0u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

#define GPIO1PIN_P3A_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PA=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PA=1u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

/*---- GPIO bit NP3A ----*/
#define GPIO1PIN_NP3A_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PA)) )

#define GPIO1PIN_NP3A_PUT(v)            ( bFM_GPIO_PDOR3_PA=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3A_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3A_INITIN(v) \
                                                           : GPIO1PIN_NP3A_INITOUT(v) )

#define GPIO1PIN_NP3A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PA=(v).bPullup; \
                                            bFM_GPIO_DDR3_PA=0u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

#define GPIO1PIN_NP3A_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PA=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PA=1u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

/*---- GPIO bit P3B ----*/
#define GPIO1PIN_P3B_GET                ( bFM_GPIO_PDIR3_PB )

#define GPIO1PIN_P3B_PUT(v)             ( bFM_GPIO_PDOR3_PB=(v) )

#define GPIO1PIN_P3B_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3B_INITIN(v) \
                                                           : GPIO1PIN_P3B_INITOUT(v) )

#define GPIO1PIN_P3B_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PB=(v).bPullup; \
                                            bFM_GPIO_DDR3_PB=0u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

#define GPIO1PIN_P3B_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PB=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PB=1u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

/*---- GPIO bit NP3B ----*/
#define GPIO1PIN_NP3B_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PB)) )

#define GPIO1PIN_NP3B_PUT(v)            ( bFM_GPIO_PDOR3_PB=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3B_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3B_INITIN(v) \
                                                           : GPIO1PIN_NP3B_INITOUT(v) )

#define GPIO1PIN_NP3B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PB=(v).bPullup; \
                                            bFM_GPIO_DDR3_PB=0u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

#define GPIO1PIN_NP3B_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PB=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PB=1u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

/*---- GPIO bit P3C ----*/
#define GPIO1PIN_P3C_GET                ( bFM_GPIO_PDIR3_PC )

#define GPIO1PIN_P3C_PUT(v)             ( bFM_GPIO_PDOR3_PC=(v) )

#define GPIO1PIN_P3C_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3C_INITIN(v) \
                                                           : GPIO1PIN_P3C_INITOUT(v) )

#define GPIO1PIN_P3C_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PC=(v).bPullup; \
                                            bFM_GPIO_DDR3_PC=0u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

#define GPIO1PIN_P3C_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PC=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PC=1u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

/*---- GPIO bit NP3C ----*/
#define GPIO1PIN_NP3C_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PC)) )

#define GPIO1PIN_NP3C_PUT(v)            ( bFM_GPIO_PDOR3_PC=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3C_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3C_INITIN(v) \
                                                           : GPIO1PIN_NP3C_INITOUT(v) )

#define GPIO1PIN_NP3C_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PC=(v).bPullup; \
                                            bFM_GPIO_DDR3_PC=0u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

#define GPIO1PIN_NP3C_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PC=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PC=1u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

/*---- GPIO bit P3D ----*/
#define GPIO1PIN_P3D_GET                ( bFM_GPIO_PDIR3_PD )

#define GPIO1PIN_P3D_PUT(v)             ( bFM_GPIO_PDOR3_PD=(v) )

#define GPIO1PIN_P3D_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3D_INITIN(v) \
                                                           : GPIO1PIN_P3D_INITOUT(v) )

#define GPIO1PIN_P3D_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PD=(v).bPullup; \
                                            bFM_GPIO_DDR3_PD=0u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

#define GPIO1PIN_P3D_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PD=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PD=1u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

/*---- GPIO bit NP3D ----*/
#define GPIO1PIN_NP3D_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PD)) )

#define GPIO1PIN_NP3D_PUT(v)            ( bFM_GPIO_PDOR3_PD=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3D_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3D_INITIN(v) \
                                                           : GPIO1PIN_NP3D_INITOUT(v) )

#define GPIO1PIN_NP3D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PD=(v).bPullup; \
                                            bFM_GPIO_DDR3_PD=0u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

#define GPIO1PIN_NP3D_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PD=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PD=1u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

/*---- GPIO bit P3E ----*/
#define GPIO1PIN_P3E_GET                ( bFM_GPIO_PDIR3_PE )

#define GPIO1PIN_P3E_PUT(v)             ( bFM_GPIO_PDOR3_PE=(v) )

#define GPIO1PIN_P3E_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3E_INITIN(v) \
                                                           : GPIO1PIN_P3E_INITOUT(v) )

#define GPIO1PIN_P3E_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PE=(v).bPullup; \
                                            bFM_GPIO_DDR3_PE=0u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

#define GPIO1PIN_P3E_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PE=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PE=1u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

/*---- GPIO bit NP3E ----*/
#define GPIO1PIN_NP3E_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PE)) )

#define GPIO1PIN_NP3E_PUT(v)            ( bFM_GPIO_PDOR3_PE=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3E_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3E_INITIN(v) \
                                                           : GPIO1PIN_NP3E_INITOUT(v) )

#define GPIO1PIN_NP3E_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PE=(v).bPullup; \
                                            bFM_GPIO_DDR3_PE=0u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

#define GPIO1PIN_NP3E_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PE=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PE=1u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

/*---- GPIO bit P3F ----*/
#define GPIO1PIN_P3F_GET                ( bFM_GPIO_PDIR3_PF )

#define GPIO1PIN_P3F_PUT(v)             ( bFM_GPIO_PDOR3_PF=(v) )

#define GPIO1PIN_P3F_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P3F_INITIN(v) \
                                                           : GPIO1PIN_P3F_INITOUT(v) )

#define GPIO1PIN_P3F_INITIN(v)          do{ \
                                            bFM_GPIO_PCR3_PF=(v).bPullup; \
                                            bFM_GPIO_DDR3_PF=0u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

#define GPIO1PIN_P3F_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR3_PF=(v).bInitVal; \
                                            bFM_GPIO_DDR3_PF=1u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

/*---- GPIO bit NP3F ----*/
#define GPIO1PIN_NP3F_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR3_PF)) )

#define GPIO1PIN_NP3F_PUT(v)            ( bFM_GPIO_PDOR3_PF=(uint32_t)(!(v)) )

#define GPIO1PIN_NP3F_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP3F_INITIN(v) \
                                                           : GPIO1PIN_NP3F_INITOUT(v) )

#define GPIO1PIN_NP3F_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PF=(v).bPullup; \
                                            bFM_GPIO_DDR3_PF=0u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

#define GPIO1PIN_NP3F_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR3_PF=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR3_PF=1u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

/*---- GPIO bit P40 ----*/
#define GPIO1PIN_P40_GET                ( bFM_GPIO_PDIR4_P0 )

#define GPIO1PIN_P40_PUT(v)             ( bFM_GPIO_PDOR4_P0=(v) )

#define GPIO1PIN_P40_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P40_INITIN(v) \
                                                           : GPIO1PIN_P40_INITOUT(v) )

#define GPIO1PIN_P40_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P0=(v).bPullup; \
                                            bFM_GPIO_DDR4_P0=0u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

#define GPIO1PIN_P40_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P0=1u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

/*---- GPIO bit NP40 ----*/
#define GPIO1PIN_NP40_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P0)) )

#define GPIO1PIN_NP40_PUT(v)            ( bFM_GPIO_PDOR4_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP40_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP40_INITIN(v) \
                                                           : GPIO1PIN_NP40_INITOUT(v) )

#define GPIO1PIN_NP40_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P0=(v).bPullup; \
                                            bFM_GPIO_DDR4_P0=0u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

#define GPIO1PIN_NP40_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P0=1u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

/*---- GPIO bit P41 ----*/
#define GPIO1PIN_P41_GET                ( bFM_GPIO_PDIR4_P1 )

#define GPIO1PIN_P41_PUT(v)             ( bFM_GPIO_PDOR4_P1=(v) )

#define GPIO1PIN_P41_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P41_INITIN(v) \
                                                           : GPIO1PIN_P41_INITOUT(v) )

#define GPIO1PIN_P41_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P1=(v).bPullup; \
                                            bFM_GPIO_DDR4_P1=0u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

#define GPIO1PIN_P41_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P1=1u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

/*---- GPIO bit NP41 ----*/
#define GPIO1PIN_NP41_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P1)) )

#define GPIO1PIN_NP41_PUT(v)            ( bFM_GPIO_PDOR4_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP41_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP41_INITIN(v) \
                                                           : GPIO1PIN_NP41_INITOUT(v) )

#define GPIO1PIN_NP41_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P1=(v).bPullup; \
                                            bFM_GPIO_DDR4_P1=0u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

#define GPIO1PIN_NP41_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P1=1u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

/*---- GPIO bit P42 ----*/
#define GPIO1PIN_P42_GET                ( bFM_GPIO_PDIR4_P2 )

#define GPIO1PIN_P42_PUT(v)             ( bFM_GPIO_PDOR4_P2=(v) )

#define GPIO1PIN_P42_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P42_INITIN(v) \
                                                           : GPIO1PIN_P42_INITOUT(v) )

#define GPIO1PIN_P42_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P2=(v).bPullup; \
                                            bFM_GPIO_DDR4_P2=0u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

#define GPIO1PIN_P42_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P2=1u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

/*---- GPIO bit NP42 ----*/
#define GPIO1PIN_NP42_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P2)) )

#define GPIO1PIN_NP42_PUT(v)            ( bFM_GPIO_PDOR4_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP42_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP42_INITIN(v) \
                                                           : GPIO1PIN_NP42_INITOUT(v) )

#define GPIO1PIN_NP42_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P2=(v).bPullup; \
                                            bFM_GPIO_DDR4_P2=0u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

#define GPIO1PIN_NP42_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P2=1u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

/*---- GPIO bit P43 ----*/
#define GPIO1PIN_P43_GET                ( bFM_GPIO_PDIR4_P3 )

#define GPIO1PIN_P43_PUT(v)             ( bFM_GPIO_PDOR4_P3=(v) )

#define GPIO1PIN_P43_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P43_INITIN(v) \
                                                           : GPIO1PIN_P43_INITOUT(v) )

#define GPIO1PIN_P43_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P3=(v).bPullup; \
                                            bFM_GPIO_DDR4_P3=0u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

#define GPIO1PIN_P43_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P3=1u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

/*---- GPIO bit NP43 ----*/
#define GPIO1PIN_NP43_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P3)) )

#define GPIO1PIN_NP43_PUT(v)            ( bFM_GPIO_PDOR4_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP43_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP43_INITIN(v) \
                                                           : GPIO1PIN_NP43_INITOUT(v) )

#define GPIO1PIN_NP43_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P3=(v).bPullup; \
                                            bFM_GPIO_DDR4_P3=0u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

#define GPIO1PIN_NP43_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P3=1u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

/*---- GPIO bit P44 ----*/
#define GPIO1PIN_P44_GET                ( bFM_GPIO_PDIR4_P4 )

#define GPIO1PIN_P44_PUT(v)             ( bFM_GPIO_PDOR4_P4=(v) )

#define GPIO1PIN_P44_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P44_INITIN(v) \
                                                           : GPIO1PIN_P44_INITOUT(v) )

#define GPIO1PIN_P44_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P4=(v).bPullup; \
                                            bFM_GPIO_DDR4_P4=0u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

#define GPIO1PIN_P44_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P4=1u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

/*---- GPIO bit NP44 ----*/
#define GPIO1PIN_NP44_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P4)) )

#define GPIO1PIN_NP44_PUT(v)            ( bFM_GPIO_PDOR4_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP44_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP44_INITIN(v) \
                                                           : GPIO1PIN_NP44_INITOUT(v) )

#define GPIO1PIN_NP44_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P4=(v).bPullup; \
                                            bFM_GPIO_DDR4_P4=0u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

#define GPIO1PIN_NP44_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P4=1u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

/*---- GPIO bit P45 ----*/
#define GPIO1PIN_P45_GET                ( bFM_GPIO_PDIR4_P5 )

#define GPIO1PIN_P45_PUT(v)             ( bFM_GPIO_PDOR4_P5=(v) )

#define GPIO1PIN_P45_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P45_INITIN(v) \
                                                           : GPIO1PIN_P45_INITOUT(v) )

#define GPIO1PIN_P45_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P5=(v).bPullup; \
                                            bFM_GPIO_DDR4_P5=0u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

#define GPIO1PIN_P45_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P5=1u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

/*---- GPIO bit NP45 ----*/
#define GPIO1PIN_NP45_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P5)) )

#define GPIO1PIN_NP45_PUT(v)            ( bFM_GPIO_PDOR4_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP45_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP45_INITIN(v) \
                                                           : GPIO1PIN_NP45_INITOUT(v) )

#define GPIO1PIN_NP45_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P5=(v).bPullup; \
                                            bFM_GPIO_DDR4_P5=0u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

#define GPIO1PIN_NP45_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P5=1u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

/*---- GPIO bit P46 ----*/
#define GPIO1PIN_P46_GET                ( bFM_RTC_VBDIR_VDIR3 )

#define GPIO1PIN_P46_PUT(v)             do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR3=(v); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_P46_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P46_INITIN(v) \
                                                           : GPIO1PIN_P46_INITOUT(v) )

#define GPIO1PIN_P46_INITIN(v)          do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR3=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR3=0u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_P46_INITOUT(v)      do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR3=(v).bInitVal; \
                                            bFM_RTC_VBDDR_VDDR3=1u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit NP46 ----*/
#define GPIO1PIN_NP46_GET               ( (uint32_t)(!(uint32_t)(bFM_RTC_VBDIR_VDIR3)) )

#define GPIO1PIN_NP46_PUT(v)            do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR3=(uint32_t)(!(v)); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_NP46_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP46_INITIN(v) \
                                                           : GPIO1PIN_NP46_INITOUT(v) )

#define GPIO1PIN_NP46_INITIN(v)         do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR3=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR3=0u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_NP46_INITOUT(v)        do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_RTC_VBDDR_VDDR3=1u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit P47 ----*/
#define GPIO1PIN_P47_GET                ( bFM_RTC_VBDIR_VDIR2 )

#define GPIO1PIN_P47_PUT(v)             do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR2=(v); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_P47_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P47_INITIN(v) \
                                                           : GPIO1PIN_P47_INITOUT(v) )

#define GPIO1PIN_P47_INITIN(v)          do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR2=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR2=0u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_P47_INITOUT(v)      do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR2=(v).bInitVal; \
                                            bFM_RTC_VBDDR_VDDR2=1u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit NP47 ----*/
#define GPIO1PIN_NP47_GET               ( (uint32_t)(!(uint32_t)(bFM_RTC_VBDIR_VDIR2)) )

#define GPIO1PIN_NP47_PUT(v)            do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR2=(uint32_t)(!(v)); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_NP47_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP47_INITIN(v) \
                                                           : GPIO1PIN_NP47_INITOUT(v) )

#define GPIO1PIN_NP47_INITIN(v)         do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR2=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR2=0u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_NP47_INITOUT(v)        do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_RTC_VBDDR_VDDR2=1u; \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit P48 ----*/
#define GPIO1PIN_P48_GET                ( bFM_RTC_VBDIR_VDIR0 )

#define GPIO1PIN_P48_PUT(v)             do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR0=(v); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_P48_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P48_INITIN(v) \
                                                           : GPIO1PIN_P48_INITOUT(v) )

#define GPIO1PIN_P48_INITIN(v)          do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR0=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR0=0u; \
                                            bFM_RTC_VBPFR_VPFR0=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_P48_INITOUT(v)      do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR0=(v).bInitVal; \
                                            bFM_RTC_VBDDR_VDDR0=1u; \
                                            bFM_RTC_VBPFR_VPFR0=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit NP48 ----*/
#define GPIO1PIN_NP48_GET               ( (uint32_t)(!(uint32_t)(bFM_RTC_VBDIR_VDIR0)) )

#define GPIO1PIN_NP48_PUT(v)            do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR0=(uint32_t)(!(v)); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_NP48_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP48_INITIN(v) \
                                                           : GPIO1PIN_NP48_INITOUT(v) )

#define GPIO1PIN_NP48_INITIN(v)         do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR0=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR0=0u; \
                                            bFM_RTC_VBPFR_VPFR0=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_NP48_INITOUT(v)        do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_RTC_VBDDR_VDDR0=1u; \
                                            bFM_RTC_VBPFR_VPFR0=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit P49 ----*/
#define GPIO1PIN_P49_GET                ( bFM_RTC_VBDIR_VDIR1 )

#define GPIO1PIN_P49_PUT(v)             do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR1=(v); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_P49_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P49_INITIN(v) \
                                                           : GPIO1PIN_P49_INITOUT(v) )

#define GPIO1PIN_P49_INITIN(v)          do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR1=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR1=0u; \
                                            bFM_RTC_VBPFR_VPFR1=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_P49_INITOUT(v)      do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR1=(v).bInitVal; \
                                            bFM_RTC_VBDDR_VDDR1=1u; \
                                            bFM_RTC_VBPFR_VPFR1=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit NP49 ----*/
#define GPIO1PIN_NP49_GET               ( (uint32_t)(!(uint32_t)(bFM_RTC_VBDIR_VDIR1)) )

#define GPIO1PIN_NP49_PUT(v)            do{ FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR1=(uint32_t)(!(v)); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        } while(0u)

#define GPIO1PIN_NP49_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP49_INITIN(v) \
                                                           : GPIO1PIN_NP49_INITOUT(v) )

#define GPIO1PIN_NP49_INITIN(v)         do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPCR_VPCR1=(v).bPullup; \
                                            bFM_RTC_VBDDR_VDDR1=0u; \
                                            bFM_RTC_VBPFR_VPFR1=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

#define GPIO1PIN_NP49_INITOUT(v)        do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBDOR_VDOR1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_RTC_VBDDR_VDDR1=1u; \
                                            bFM_RTC_VBPFR_VPFR1=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while(0u)

/*---- GPIO bit P4A ----*/
#define GPIO1PIN_P4A_GET                ( bFM_GPIO_PDIR4_PA )

#define GPIO1PIN_P4A_PUT(v)             ( bFM_GPIO_PDOR4_PA=(v) )

#define GPIO1PIN_P4A_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P4A_INITIN(v) \
                                                           : GPIO1PIN_P4A_INITOUT(v) )

#define GPIO1PIN_P4A_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_PA=(v).bPullup; \
                                            bFM_GPIO_DDR4_PA=0u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

#define GPIO1PIN_P4A_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_PA=(v).bInitVal; \
                                            bFM_GPIO_DDR4_PA=1u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

/*---- GPIO bit NP4A ----*/
#define GPIO1PIN_NP4A_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_PA)) )

#define GPIO1PIN_NP4A_PUT(v)            ( bFM_GPIO_PDOR4_PA=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4A_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP4A_INITIN(v) \
                                                           : GPIO1PIN_NP4A_INITOUT(v) )

#define GPIO1PIN_NP4A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PA=(v).bPullup; \
                                            bFM_GPIO_DDR4_PA=0u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

#define GPIO1PIN_NP4A_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_PA=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_PA=1u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

/*---- GPIO bit P4B ----*/
#define GPIO1PIN_P4B_GET                ( bFM_GPIO_PDIR4_PB )

#define GPIO1PIN_P4B_PUT(v)             ( bFM_GPIO_PDOR4_PB=(v) )

#define GPIO1PIN_P4B_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P4B_INITIN(v) \
                                                           : GPIO1PIN_P4B_INITOUT(v) )

#define GPIO1PIN_P4B_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_PB=(v).bPullup; \
                                            bFM_GPIO_DDR4_PB=0u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

#define GPIO1PIN_P4B_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_PB=(v).bInitVal; \
                                            bFM_GPIO_DDR4_PB=1u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

/*---- GPIO bit NP4B ----*/
#define GPIO1PIN_NP4B_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_PB)) )

#define GPIO1PIN_NP4B_PUT(v)            ( bFM_GPIO_PDOR4_PB=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4B_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP4B_INITIN(v) \
                                                           : GPIO1PIN_NP4B_INITOUT(v) )

#define GPIO1PIN_NP4B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PB=(v).bPullup; \
                                            bFM_GPIO_DDR4_PB=0u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

#define GPIO1PIN_NP4B_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_PB=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_PB=1u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

/*---- GPIO bit P4C ----*/
#define GPIO1PIN_P4C_GET                ( bFM_GPIO_PDIR4_PC )

#define GPIO1PIN_P4C_PUT(v)             ( bFM_GPIO_PDOR4_PC=(v) )

#define GPIO1PIN_P4C_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P4C_INITIN(v) \
                                                           : GPIO1PIN_P4C_INITOUT(v) )

#define GPIO1PIN_P4C_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_PC=(v).bPullup; \
                                            bFM_GPIO_DDR4_PC=0u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

#define GPIO1PIN_P4C_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_PC=(v).bInitVal; \
                                            bFM_GPIO_DDR4_PC=1u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

/*---- GPIO bit NP4C ----*/
#define GPIO1PIN_NP4C_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_PC)) )

#define GPIO1PIN_NP4C_PUT(v)            ( bFM_GPIO_PDOR4_PC=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4C_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP4C_INITIN(v) \
                                                           : GPIO1PIN_NP4C_INITOUT(v) )

#define GPIO1PIN_NP4C_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PC=(v).bPullup; \
                                            bFM_GPIO_DDR4_PC=0u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

#define GPIO1PIN_NP4C_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_PC=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_PC=1u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

/*---- GPIO bit P4D ----*/
#define GPIO1PIN_P4D_GET                ( bFM_GPIO_PDIR4_PD )

#define GPIO1PIN_P4D_PUT(v)             ( bFM_GPIO_PDOR4_PD=(v) )

#define GPIO1PIN_P4D_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P4D_INITIN(v) \
                                                           : GPIO1PIN_P4D_INITOUT(v) )

#define GPIO1PIN_P4D_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_PD=(v).bPullup; \
                                            bFM_GPIO_DDR4_PD=0u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

#define GPIO1PIN_P4D_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_PD=(v).bInitVal; \
                                            bFM_GPIO_DDR4_PD=1u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

/*---- GPIO bit NP4D ----*/
#define GPIO1PIN_NP4D_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_PD)) )

#define GPIO1PIN_NP4D_PUT(v)            ( bFM_GPIO_PDOR4_PD=(uint32_t)(!(v)) )

#define GPIO1PIN_NP4D_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP4D_INITIN(v) \
                                                           : GPIO1PIN_NP4D_INITOUT(v) )

#define GPIO1PIN_NP4D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PD=(v).bPullup; \
                                            bFM_GPIO_DDR4_PD=0u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

#define GPIO1PIN_NP4D_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_PD=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_PD=1u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

/*---- GPIO bit P50 ----*/
#define GPIO1PIN_P50_GET                ( bFM_GPIO_PDIR5_P0 )

#define GPIO1PIN_P50_PUT(v)             ( bFM_GPIO_PDOR5_P0=(v) )

#define GPIO1PIN_P50_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P50_INITIN(v) \
                                                           : GPIO1PIN_P50_INITOUT(v) )

#define GPIO1PIN_P50_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P0=(v).bPullup; \
                                            bFM_GPIO_DDR5_P0=0u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

#define GPIO1PIN_P50_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P0=1u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

/*---- GPIO bit NP50 ----*/
#define GPIO1PIN_NP50_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P0)) )

#define GPIO1PIN_NP50_PUT(v)            ( bFM_GPIO_PDOR5_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP50_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP50_INITIN(v) \
                                                           : GPIO1PIN_NP50_INITOUT(v) )

#define GPIO1PIN_NP50_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P0=(v).bPullup; \
                                            bFM_GPIO_DDR5_P0=0u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

#define GPIO1PIN_NP50_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P0=1u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

/*---- GPIO bit P51 ----*/
#define GPIO1PIN_P51_GET                ( bFM_GPIO_PDIR5_P1 )

#define GPIO1PIN_P51_PUT(v)             ( bFM_GPIO_PDOR5_P1=(v) )

#define GPIO1PIN_P51_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P51_INITIN(v) \
                                                           : GPIO1PIN_P51_INITOUT(v) )

#define GPIO1PIN_P51_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P1=(v).bPullup; \
                                            bFM_GPIO_DDR5_P1=0u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

#define GPIO1PIN_P51_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P1=1u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

/*---- GPIO bit NP51 ----*/
#define GPIO1PIN_NP51_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P1)) )

#define GPIO1PIN_NP51_PUT(v)            ( bFM_GPIO_PDOR5_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP51_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP51_INITIN(v) \
                                                           : GPIO1PIN_NP51_INITOUT(v) )

#define GPIO1PIN_NP51_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P1=(v).bPullup; \
                                            bFM_GPIO_DDR5_P1=0u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

#define GPIO1PIN_NP51_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P1=1u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

/*---- GPIO bit P52 ----*/
#define GPIO1PIN_P52_GET                ( bFM_GPIO_PDIR5_P2 )

#define GPIO1PIN_P52_PUT(v)             ( bFM_GPIO_PDOR5_P2=(v) )

#define GPIO1PIN_P52_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P52_INITIN(v) \
                                                           : GPIO1PIN_P52_INITOUT(v) )

#define GPIO1PIN_P52_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P2=(v).bPullup; \
                                            bFM_GPIO_DDR5_P2=0u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

#define GPIO1PIN_P52_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P2=1u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

/*---- GPIO bit NP52 ----*/
#define GPIO1PIN_NP52_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P2)) )

#define GPIO1PIN_NP52_PUT(v)            ( bFM_GPIO_PDOR5_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP52_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP52_INITIN(v) \
                                                           : GPIO1PIN_NP52_INITOUT(v) )

#define GPIO1PIN_NP52_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P2=(v).bPullup; \
                                            bFM_GPIO_DDR5_P2=0u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

#define GPIO1PIN_NP52_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P2=1u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

/*---- GPIO bit P53 ----*/
#define GPIO1PIN_P53_GET                ( bFM_GPIO_PDIR5_P3 )

#define GPIO1PIN_P53_PUT(v)             ( bFM_GPIO_PDOR5_P3=(v) )

#define GPIO1PIN_P53_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P53_INITIN(v) \
                                                           : GPIO1PIN_P53_INITOUT(v) )

#define GPIO1PIN_P53_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P3=(v).bPullup; \
                                            bFM_GPIO_DDR5_P3=0u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

#define GPIO1PIN_P53_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P3=1u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

/*---- GPIO bit NP53 ----*/
#define GPIO1PIN_NP53_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P3)) )

#define GPIO1PIN_NP53_PUT(v)            ( bFM_GPIO_PDOR5_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP53_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP53_INITIN(v) \
                                                           : GPIO1PIN_NP53_INITOUT(v) )

#define GPIO1PIN_NP53_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P3=(v).bPullup; \
                                            bFM_GPIO_DDR5_P3=0u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

#define GPIO1PIN_NP53_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P3=1u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

/*---- GPIO bit P54 ----*/
#define GPIO1PIN_P54_GET                ( bFM_GPIO_PDIR5_P4 )

#define GPIO1PIN_P54_PUT(v)             ( bFM_GPIO_PDOR5_P4=(v) )

#define GPIO1PIN_P54_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P54_INITIN(v) \
                                                           : GPIO1PIN_P54_INITOUT(v) )

#define GPIO1PIN_P54_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P4=(v).bPullup; \
                                            bFM_GPIO_DDR5_P4=0u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

#define GPIO1PIN_P54_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P4=1u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

/*---- GPIO bit NP54 ----*/
#define GPIO1PIN_NP54_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P4)) )

#define GPIO1PIN_NP54_PUT(v)            ( bFM_GPIO_PDOR5_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP54_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP54_INITIN(v) \
                                                           : GPIO1PIN_NP54_INITOUT(v) )

#define GPIO1PIN_NP54_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P4=(v).bPullup; \
                                            bFM_GPIO_DDR5_P4=0u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

#define GPIO1PIN_NP54_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P4=1u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

/*---- GPIO bit P55 ----*/
#define GPIO1PIN_P55_GET                ( bFM_GPIO_PDIR5_P5 )

#define GPIO1PIN_P55_PUT(v)             ( bFM_GPIO_PDOR5_P5=(v) )

#define GPIO1PIN_P55_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P55_INITIN(v) \
                                                           : GPIO1PIN_P55_INITOUT(v) )

#define GPIO1PIN_P55_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P5=(v).bPullup; \
                                            bFM_GPIO_DDR5_P5=0u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

#define GPIO1PIN_P55_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P5=1u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

/*---- GPIO bit NP55 ----*/
#define GPIO1PIN_NP55_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P5)) )

#define GPIO1PIN_NP55_PUT(v)            ( bFM_GPIO_PDOR5_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP55_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP55_INITIN(v) \
                                                           : GPIO1PIN_NP55_INITOUT(v) )

#define GPIO1PIN_NP55_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P5=(v).bPullup; \
                                            bFM_GPIO_DDR5_P5=0u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

#define GPIO1PIN_NP55_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P5=1u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

/*---- GPIO bit P56 ----*/
#define GPIO1PIN_P56_GET                ( bFM_GPIO_PDIR5_P6 )

#define GPIO1PIN_P56_PUT(v)             ( bFM_GPIO_PDOR5_P6=(v) )

#define GPIO1PIN_P56_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P56_INITIN(v) \
                                                           : GPIO1PIN_P56_INITOUT(v) )

#define GPIO1PIN_P56_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P6=(v).bPullup; \
                                            bFM_GPIO_DDR5_P6=0u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

#define GPIO1PIN_P56_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P6=1u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

/*---- GPIO bit NP56 ----*/
#define GPIO1PIN_NP56_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P6)) )

#define GPIO1PIN_NP56_PUT(v)            ( bFM_GPIO_PDOR5_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP56_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP56_INITIN(v) \
                                                           : GPIO1PIN_NP56_INITOUT(v) )

#define GPIO1PIN_NP56_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P6=(v).bPullup; \
                                            bFM_GPIO_DDR5_P6=0u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

#define GPIO1PIN_NP56_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P6=1u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

/*---- GPIO bit P57 ----*/
#define GPIO1PIN_P57_GET                ( bFM_GPIO_PDIR5_P7 )

#define GPIO1PIN_P57_PUT(v)             ( bFM_GPIO_PDOR5_P7=(v) )

#define GPIO1PIN_P57_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P57_INITIN(v) \
                                                           : GPIO1PIN_P57_INITOUT(v) )

#define GPIO1PIN_P57_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P7=(v).bPullup; \
                                            bFM_GPIO_DDR5_P7=0u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

#define GPIO1PIN_P57_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P7=1u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

/*---- GPIO bit NP57 ----*/
#define GPIO1PIN_NP57_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P7)) )

#define GPIO1PIN_NP57_PUT(v)            ( bFM_GPIO_PDOR5_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP57_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP57_INITIN(v) \
                                                           : GPIO1PIN_NP57_INITOUT(v) )

#define GPIO1PIN_NP57_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P7=(v).bPullup; \
                                            bFM_GPIO_DDR5_P7=0u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

#define GPIO1PIN_NP57_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P7=1u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

/*---- GPIO bit P58 ----*/
#define GPIO1PIN_P58_GET                ( bFM_GPIO_PDIR5_P8 )

#define GPIO1PIN_P58_PUT(v)             ( bFM_GPIO_PDOR5_P8=(v) )

#define GPIO1PIN_P58_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P58_INITIN(v) \
                                                           : GPIO1PIN_P58_INITOUT(v) )

#define GPIO1PIN_P58_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P8=(v).bPullup; \
                                            bFM_GPIO_DDR5_P8=0u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

#define GPIO1PIN_P58_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P8=1u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

/*---- GPIO bit NP58 ----*/
#define GPIO1PIN_NP58_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P8)) )

#define GPIO1PIN_NP58_PUT(v)            ( bFM_GPIO_PDOR5_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP58_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP58_INITIN(v) \
                                                           : GPIO1PIN_NP58_INITOUT(v) )

#define GPIO1PIN_NP58_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P8=(v).bPullup; \
                                            bFM_GPIO_DDR5_P8=0u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

#define GPIO1PIN_NP58_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P8=1u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

/*---- GPIO bit P59 ----*/
#define GPIO1PIN_P59_GET                ( bFM_GPIO_PDIR5_P9 )

#define GPIO1PIN_P59_PUT(v)             ( bFM_GPIO_PDOR5_P9=(v) )

#define GPIO1PIN_P59_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P59_INITIN(v) \
                                                           : GPIO1PIN_P59_INITOUT(v) )

#define GPIO1PIN_P59_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_P9=(v).bPullup; \
                                            bFM_GPIO_DDR5_P9=0u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

#define GPIO1PIN_P59_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_P9=(v).bInitVal; \
                                            bFM_GPIO_DDR5_P9=1u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

/*---- GPIO bit NP59 ----*/
#define GPIO1PIN_NP59_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_P9)) )

#define GPIO1PIN_NP59_PUT(v)            ( bFM_GPIO_PDOR5_P9=(uint32_t)(!(v)) )

#define GPIO1PIN_NP59_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP59_INITIN(v) \
                                                           : GPIO1PIN_NP59_INITOUT(v) )

#define GPIO1PIN_NP59_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P9=(v).bPullup; \
                                            bFM_GPIO_DDR5_P9=0u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

#define GPIO1PIN_NP59_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_P9=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_P9=1u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

/*---- GPIO bit P5A ----*/
#define GPIO1PIN_P5A_GET                ( bFM_GPIO_PDIR5_PA )

#define GPIO1PIN_P5A_PUT(v)             ( bFM_GPIO_PDOR5_PA=(v) )

#define GPIO1PIN_P5A_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P5A_INITIN(v) \
                                                           : GPIO1PIN_P5A_INITOUT(v) )

#define GPIO1PIN_P5A_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_PA=(v).bPullup; \
                                            bFM_GPIO_DDR5_PA=0u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

#define GPIO1PIN_P5A_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_PA=(v).bInitVal; \
                                            bFM_GPIO_DDR5_PA=1u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

/*---- GPIO bit NP5A ----*/
#define GPIO1PIN_NP5A_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_PA)) )

#define GPIO1PIN_NP5A_PUT(v)            ( bFM_GPIO_PDOR5_PA=(uint32_t)(!(v)) )

#define GPIO1PIN_NP5A_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP5A_INITIN(v) \
                                                           : GPIO1PIN_NP5A_INITOUT(v) )

#define GPIO1PIN_NP5A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_PA=(v).bPullup; \
                                            bFM_GPIO_DDR5_PA=0u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

#define GPIO1PIN_NP5A_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_PA=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_PA=1u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

/*---- GPIO bit P5B ----*/
#define GPIO1PIN_P5B_GET                ( bFM_GPIO_PDIR5_PB )

#define GPIO1PIN_P5B_PUT(v)             ( bFM_GPIO_PDOR5_PB=(v) )

#define GPIO1PIN_P5B_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P5B_INITIN(v) \
                                                           : GPIO1PIN_P5B_INITOUT(v) )

#define GPIO1PIN_P5B_INITIN(v)          do{ \
                                            bFM_GPIO_PCR5_PB=(v).bPullup; \
                                            bFM_GPIO_DDR5_PB=0u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

#define GPIO1PIN_P5B_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR5_PB=(v).bInitVal; \
                                            bFM_GPIO_DDR5_PB=1u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

/*---- GPIO bit NP5B ----*/
#define GPIO1PIN_NP5B_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR5_PB)) )

#define GPIO1PIN_NP5B_PUT(v)            ( bFM_GPIO_PDOR5_PB=(uint32_t)(!(v)) )

#define GPIO1PIN_NP5B_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP5B_INITIN(v) \
                                                           : GPIO1PIN_NP5B_INITOUT(v) )

#define GPIO1PIN_NP5B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_PB=(v).bPullup; \
                                            bFM_GPIO_DDR5_PB=0u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

#define GPIO1PIN_NP5B_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR5_PB=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR5_PB=1u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

/*---- GPIO bit P60 ----*/
#define GPIO1PIN_P60_GET                ( bFM_GPIO_PDIR6_P0 )

#define GPIO1PIN_P60_PUT(v)             ( bFM_GPIO_PDOR6_P0=(v) )

#define GPIO1PIN_P60_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P60_INITIN(v) \
                                                           : GPIO1PIN_P60_INITOUT(v) )

#define GPIO1PIN_P60_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P0=(v).bPullup; \
                                            bFM_GPIO_DDR6_P0=0u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

#define GPIO1PIN_P60_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P0=1u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

/*---- GPIO bit NP60 ----*/
#define GPIO1PIN_NP60_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P0)) )

#define GPIO1PIN_NP60_PUT(v)            ( bFM_GPIO_PDOR6_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP60_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP60_INITIN(v) \
                                                           : GPIO1PIN_NP60_INITOUT(v) )

#define GPIO1PIN_NP60_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P0=(v).bPullup; \
                                            bFM_GPIO_DDR6_P0=0u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

#define GPIO1PIN_NP60_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P0=1u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

/*---- GPIO bit P61 ----*/
#define GPIO1PIN_P61_GET                ( bFM_GPIO_PDIR6_P1 )

#define GPIO1PIN_P61_PUT(v)             ( bFM_GPIO_PDOR6_P1=(v) )

#define GPIO1PIN_P61_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P61_INITIN(v) \
                                                           : GPIO1PIN_P61_INITOUT(v) )

#define GPIO1PIN_P61_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P1=(v).bPullup; \
                                            bFM_GPIO_DDR6_P1=0u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

#define GPIO1PIN_P61_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P1=1u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

/*---- GPIO bit NP61 ----*/
#define GPIO1PIN_NP61_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P1)) )

#define GPIO1PIN_NP61_PUT(v)            ( bFM_GPIO_PDOR6_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP61_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP61_INITIN(v) \
                                                           : GPIO1PIN_NP61_INITOUT(v) )

#define GPIO1PIN_NP61_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P1=(v).bPullup; \
                                            bFM_GPIO_DDR6_P1=0u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

#define GPIO1PIN_NP61_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P1=1u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

/*---- GPIO bit P62 ----*/
#define GPIO1PIN_P62_GET                ( bFM_GPIO_PDIR6_P2 )

#define GPIO1PIN_P62_PUT(v)             ( bFM_GPIO_PDOR6_P2=(v) )

#define GPIO1PIN_P62_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P62_INITIN(v) \
                                                           : GPIO1PIN_P62_INITOUT(v) )

#define GPIO1PIN_P62_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P2=(v).bPullup; \
                                            bFM_GPIO_DDR6_P2=0u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

#define GPIO1PIN_P62_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P2=1u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

/*---- GPIO bit NP62 ----*/
#define GPIO1PIN_NP62_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P2)) )

#define GPIO1PIN_NP62_PUT(v)            ( bFM_GPIO_PDOR6_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP62_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP62_INITIN(v) \
                                                           : GPIO1PIN_NP62_INITOUT(v) )

#define GPIO1PIN_NP62_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P2=(v).bPullup; \
                                            bFM_GPIO_DDR6_P2=0u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

#define GPIO1PIN_NP62_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P2=1u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

/*---- GPIO bit P63 ----*/
#define GPIO1PIN_P63_GET                ( bFM_GPIO_PDIR6_P3 )

#define GPIO1PIN_P63_PUT(v)             ( bFM_GPIO_PDOR6_P3=(v) )

#define GPIO1PIN_P63_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P63_INITIN(v) \
                                                           : GPIO1PIN_P63_INITOUT(v) )

#define GPIO1PIN_P63_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P3=(v).bPullup; \
                                            bFM_GPIO_DDR6_P3=0u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

#define GPIO1PIN_P63_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P3=1u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

/*---- GPIO bit NP63 ----*/
#define GPIO1PIN_NP63_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P3)) )

#define GPIO1PIN_NP63_PUT(v)            ( bFM_GPIO_PDOR6_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP63_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP63_INITIN(v) \
                                                           : GPIO1PIN_NP63_INITOUT(v) )

#define GPIO1PIN_NP63_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P3=(v).bPullup; \
                                            bFM_GPIO_DDR6_P3=0u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

#define GPIO1PIN_NP63_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P3=1u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

/*---- GPIO bit P64 ----*/
#define GPIO1PIN_P64_GET                ( bFM_GPIO_PDIR6_P4 )

#define GPIO1PIN_P64_PUT(v)             ( bFM_GPIO_PDOR6_P4=(v) )

#define GPIO1PIN_P64_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P64_INITIN(v) \
                                                           : GPIO1PIN_P64_INITOUT(v) )

#define GPIO1PIN_P64_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P4=(v).bPullup; \
                                            bFM_GPIO_DDR6_P4=0u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

#define GPIO1PIN_P64_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P4=1u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

/*---- GPIO bit NP64 ----*/
#define GPIO1PIN_NP64_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P4)) )

#define GPIO1PIN_NP64_PUT(v)            ( bFM_GPIO_PDOR6_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP64_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP64_INITIN(v) \
                                                           : GPIO1PIN_NP64_INITOUT(v) )

#define GPIO1PIN_NP64_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P4=(v).bPullup; \
                                            bFM_GPIO_DDR6_P4=0u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

#define GPIO1PIN_NP64_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P4=1u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

/*---- GPIO bit P65 ----*/
#define GPIO1PIN_P65_GET                ( bFM_GPIO_PDIR6_P5 )

#define GPIO1PIN_P65_PUT(v)             ( bFM_GPIO_PDOR6_P5=(v) )

#define GPIO1PIN_P65_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P65_INITIN(v) \
                                                           : GPIO1PIN_P65_INITOUT(v) )

#define GPIO1PIN_P65_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P5=(v).bPullup; \
                                            bFM_GPIO_DDR6_P5=0u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

#define GPIO1PIN_P65_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P5=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P5=1u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

/*---- GPIO bit NP65 ----*/
#define GPIO1PIN_NP65_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P5)) )

#define GPIO1PIN_NP65_PUT(v)            ( bFM_GPIO_PDOR6_P5=(uint32_t)(!(v)) )

#define GPIO1PIN_NP65_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP65_INITIN(v) \
                                                           : GPIO1PIN_NP65_INITOUT(v) )

#define GPIO1PIN_NP65_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P5=(v).bPullup; \
                                            bFM_GPIO_DDR6_P5=0u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

#define GPIO1PIN_NP65_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P5=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P5=1u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

/*---- GPIO bit P66 ----*/
#define GPIO1PIN_P66_GET                ( bFM_GPIO_PDIR6_P6 )

#define GPIO1PIN_P66_PUT(v)             ( bFM_GPIO_PDOR6_P6=(v) )

#define GPIO1PIN_P66_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P66_INITIN(v) \
                                                           : GPIO1PIN_P66_INITOUT(v) )

#define GPIO1PIN_P66_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P6=(v).bPullup; \
                                            bFM_GPIO_DDR6_P6=0u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

#define GPIO1PIN_P66_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P6=1u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

/*---- GPIO bit NP66 ----*/
#define GPIO1PIN_NP66_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P6)) )

#define GPIO1PIN_NP66_PUT(v)            ( bFM_GPIO_PDOR6_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP66_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP66_INITIN(v) \
                                                           : GPIO1PIN_NP66_INITOUT(v) )

#define GPIO1PIN_NP66_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P6=(v).bPullup; \
                                            bFM_GPIO_DDR6_P6=0u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

#define GPIO1PIN_NP66_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P6=1u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

/*---- GPIO bit P67 ----*/
#define GPIO1PIN_P67_GET                ( bFM_GPIO_PDIR6_P7 )

#define GPIO1PIN_P67_PUT(v)             ( bFM_GPIO_PDOR6_P7=(v) )

#define GPIO1PIN_P67_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P67_INITIN(v) \
                                                           : GPIO1PIN_P67_INITOUT(v) )

#define GPIO1PIN_P67_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P7=(v).bPullup; \
                                            bFM_GPIO_DDR6_P7=0u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

#define GPIO1PIN_P67_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P7=1u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

/*---- GPIO bit NP67 ----*/
#define GPIO1PIN_NP67_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P7)) )

#define GPIO1PIN_NP67_PUT(v)            ( bFM_GPIO_PDOR6_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP67_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP67_INITIN(v) \
                                                           : GPIO1PIN_NP67_INITOUT(v) )

#define GPIO1PIN_NP67_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P7=(v).bPullup; \
                                            bFM_GPIO_DDR6_P7=0u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

#define GPIO1PIN_NP67_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P7=1u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

/*---- GPIO bit P68 ----*/
#define GPIO1PIN_P68_GET                ( bFM_GPIO_PDIR6_P8 )

#define GPIO1PIN_P68_PUT(v)             ( bFM_GPIO_PDOR6_P8=(v) )

#define GPIO1PIN_P68_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P68_INITIN(v) \
                                                           : GPIO1PIN_P68_INITOUT(v) )

#define GPIO1PIN_P68_INITIN(v)          do{ \
                                            bFM_GPIO_PCR6_P8=(v).bPullup; \
                                            bFM_GPIO_DDR6_P8=0u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

#define GPIO1PIN_P68_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR6_P8=(v).bInitVal; \
                                            bFM_GPIO_DDR6_P8=1u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

/*---- GPIO bit NP68 ----*/
#define GPIO1PIN_NP68_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR6_P8)) )

#define GPIO1PIN_NP68_PUT(v)            ( bFM_GPIO_PDOR6_P8=(uint32_t)(!(v)) )

#define GPIO1PIN_NP68_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP68_INITIN(v) \
                                                           : GPIO1PIN_NP68_INITOUT(v) )

#define GPIO1PIN_NP68_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P8=(v).bPullup; \
                                            bFM_GPIO_DDR6_P8=0u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

#define GPIO1PIN_NP68_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR6_P8=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR6_P8=1u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

/*---- GPIO bit P70 ----*/
#define GPIO1PIN_P70_GET                ( bFM_GPIO_PDIR7_P0 )

#define GPIO1PIN_P70_PUT(v)             ( bFM_GPIO_PDOR7_P0=(v) )

#define GPIO1PIN_P70_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P70_INITIN(v) \
                                                           : GPIO1PIN_P70_INITOUT(v) )

#define GPIO1PIN_P70_INITIN(v)          do{ \
                                            bFM_GPIO_PCR7_P0=(v).bPullup; \
                                            bFM_GPIO_DDR7_P0=0u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

#define GPIO1PIN_P70_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR7_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR7_P0=1u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

/*---- GPIO bit NP70 ----*/
#define GPIO1PIN_NP70_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR7_P0)) )

#define GPIO1PIN_NP70_PUT(v)            ( bFM_GPIO_PDOR7_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP70_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP70_INITIN(v) \
                                                           : GPIO1PIN_NP70_INITOUT(v) )

#define GPIO1PIN_NP70_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P0=(v).bPullup; \
                                            bFM_GPIO_DDR7_P0=0u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

#define GPIO1PIN_NP70_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR7_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR7_P0=1u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

/*---- GPIO bit P71 ----*/
#define GPIO1PIN_P71_GET                ( bFM_GPIO_PDIR7_P1 )

#define GPIO1PIN_P71_PUT(v)             ( bFM_GPIO_PDOR7_P1=(v) )

#define GPIO1PIN_P71_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P71_INITIN(v) \
                                                           : GPIO1PIN_P71_INITOUT(v) )

#define GPIO1PIN_P71_INITIN(v)          do{ \
                                            bFM_GPIO_PCR7_P1=(v).bPullup; \
                                            bFM_GPIO_DDR7_P1=0u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

#define GPIO1PIN_P71_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR7_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR7_P1=1u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

/*---- GPIO bit NP71 ----*/
#define GPIO1PIN_NP71_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR7_P1)) )

#define GPIO1PIN_NP71_PUT(v)            ( bFM_GPIO_PDOR7_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP71_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP71_INITIN(v) \
                                                           : GPIO1PIN_NP71_INITOUT(v) )

#define GPIO1PIN_NP71_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P1=(v).bPullup; \
                                            bFM_GPIO_DDR7_P1=0u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

#define GPIO1PIN_NP71_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR7_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR7_P1=1u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

/*---- GPIO bit P72 ----*/
#define GPIO1PIN_P72_GET                ( bFM_GPIO_PDIR7_P2 )

#define GPIO1PIN_P72_PUT(v)             ( bFM_GPIO_PDOR7_P2=(v) )

#define GPIO1PIN_P72_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P72_INITIN(v) \
                                                           : GPIO1PIN_P72_INITOUT(v) )

#define GPIO1PIN_P72_INITIN(v)          do{ \
                                            bFM_GPIO_PCR7_P2=(v).bPullup; \
                                            bFM_GPIO_DDR7_P2=0u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

#define GPIO1PIN_P72_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR7_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR7_P2=1u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

/*---- GPIO bit NP72 ----*/
#define GPIO1PIN_NP72_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR7_P2)) )

#define GPIO1PIN_NP72_PUT(v)            ( bFM_GPIO_PDOR7_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP72_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP72_INITIN(v) \
                                                           : GPIO1PIN_NP72_INITOUT(v) )

#define GPIO1PIN_NP72_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P2=(v).bPullup; \
                                            bFM_GPIO_DDR7_P2=0u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

#define GPIO1PIN_NP72_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR7_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR7_P2=1u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

/*---- GPIO bit P73 ----*/
#define GPIO1PIN_P73_GET                ( bFM_GPIO_PDIR7_P3 )

#define GPIO1PIN_P73_PUT(v)             ( bFM_GPIO_PDOR7_P3=(v) )

#define GPIO1PIN_P73_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P73_INITIN(v) \
                                                           : GPIO1PIN_P73_INITOUT(v) )

#define GPIO1PIN_P73_INITIN(v)          do{ \
                                            bFM_GPIO_PCR7_P3=(v).bPullup; \
                                            bFM_GPIO_DDR7_P3=0u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

#define GPIO1PIN_P73_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR7_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR7_P3=1u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

/*---- GPIO bit NP73 ----*/
#define GPIO1PIN_NP73_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR7_P3)) )

#define GPIO1PIN_NP73_PUT(v)            ( bFM_GPIO_PDOR7_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP73_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP73_INITIN(v) \
                                                           : GPIO1PIN_NP73_INITOUT(v) )

#define GPIO1PIN_NP73_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P3=(v).bPullup; \
                                            bFM_GPIO_DDR7_P3=0u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

#define GPIO1PIN_NP73_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR7_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR7_P3=1u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

/*---- GPIO bit P74 ----*/
#define GPIO1PIN_P74_GET                ( bFM_GPIO_PDIR7_P4 )

#define GPIO1PIN_P74_PUT(v)             ( bFM_GPIO_PDOR7_P4=(v) )

#define GPIO1PIN_P74_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P74_INITIN(v) \
                                                           : GPIO1PIN_P74_INITOUT(v) )

#define GPIO1PIN_P74_INITIN(v)          do{ \
                                            bFM_GPIO_PCR7_P4=(v).bPullup; \
                                            bFM_GPIO_DDR7_P4=0u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

#define GPIO1PIN_P74_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR7_P4=(v).bInitVal; \
                                            bFM_GPIO_DDR7_P4=1u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

/*---- GPIO bit NP74 ----*/
#define GPIO1PIN_NP74_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR7_P4)) )

#define GPIO1PIN_NP74_PUT(v)            ( bFM_GPIO_PDOR7_P4=(uint32_t)(!(v)) )

#define GPIO1PIN_NP74_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP74_INITIN(v) \
                                                           : GPIO1PIN_NP74_INITOUT(v) )

#define GPIO1PIN_NP74_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P4=(v).bPullup; \
                                            bFM_GPIO_DDR7_P4=0u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

#define GPIO1PIN_NP74_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR7_P4=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR7_P4=1u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

/*---- GPIO bit P80 ----*/
#define GPIO1PIN_P80_GET                ( bFM_GPIO_PDIR8_P0 )

#define GPIO1PIN_P80_PUT(v)             ( bFM_GPIO_PDOR8_P0=(v) )

#define GPIO1PIN_P80_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P80_INITIN(v) \
                                                           : GPIO1PIN_P80_INITOUT(v) )

#define GPIO1PIN_P80_INITIN(v)          do{ \
                                            bFM_GPIO_DDR8_P0=0u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

#define GPIO1PIN_P80_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR8_P0=(v).bInitVal; \
                                            bFM_GPIO_DDR8_P0=1u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

/*---- GPIO bit NP80 ----*/
#define GPIO1PIN_NP80_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR8_P0)) )

#define GPIO1PIN_NP80_PUT(v)            ( bFM_GPIO_PDOR8_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NP80_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP80_INITIN(v) \
                                                           : GPIO1PIN_NP80_INITOUT(v) )

#define GPIO1PIN_NP80_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P0=0u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

#define GPIO1PIN_NP80_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR8_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR8_P0=1u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

/*---- GPIO bit P81 ----*/
#define GPIO1PIN_P81_GET                ( bFM_GPIO_PDIR8_P1 )

#define GPIO1PIN_P81_PUT(v)             ( bFM_GPIO_PDOR8_P1=(v) )

#define GPIO1PIN_P81_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P81_INITIN(v) \
                                                           : GPIO1PIN_P81_INITOUT(v) )

#define GPIO1PIN_P81_INITIN(v)          do{ \
                                            bFM_GPIO_DDR8_P1=0u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

#define GPIO1PIN_P81_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR8_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR8_P1=1u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

/*---- GPIO bit NP81 ----*/
#define GPIO1PIN_NP81_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR8_P1)) )

#define GPIO1PIN_NP81_PUT(v)            ( bFM_GPIO_PDOR8_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP81_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP81_INITIN(v) \
                                                           : GPIO1PIN_NP81_INITOUT(v) )

#define GPIO1PIN_NP81_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P1=0u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

#define GPIO1PIN_NP81_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR8_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR8_P1=1u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

/*---- GPIO bit P82 ----*/
#define GPIO1PIN_P82_GET                ( bFM_GPIO_PDIR8_P2 )

#define GPIO1PIN_P82_PUT(v)             ( bFM_GPIO_PDOR8_P2=(v) )

#define GPIO1PIN_P82_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P82_INITIN(v) \
                                                           : GPIO1PIN_P82_INITOUT(v) )

#define GPIO1PIN_P82_INITIN(v)          do{ \
                                            bFM_GPIO_DDR8_P2=0u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

#define GPIO1PIN_P82_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR8_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR8_P2=1u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

/*---- GPIO bit NP82 ----*/
#define GPIO1PIN_NP82_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR8_P2)) )

#define GPIO1PIN_NP82_PUT(v)            ( bFM_GPIO_PDOR8_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP82_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP82_INITIN(v) \
                                                           : GPIO1PIN_NP82_INITOUT(v) )

#define GPIO1PIN_NP82_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P2=0u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

#define GPIO1PIN_NP82_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR8_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR8_P2=1u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

/*---- GPIO bit PE0 ----*/
#define GPIO1PIN_PE0_GET                ( bFM_GPIO_PDIRE_P0 )

#define GPIO1PIN_PE0_PUT(v)             ( bFM_GPIO_PDORE_P0=(v) )

#define GPIO1PIN_PE0_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_PE0_INITIN(v) \
                                                           : GPIO1PIN_PE0_INITOUT(v) )

#define GPIO1PIN_PE0_INITIN(v)          do{ \
                                            bFM_GPIO_PCRE_P0=(v).bPullup; \
                                            bFM_GPIO_DDRE_P0=0u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

#define GPIO1PIN_PE0_INITOUT(v)         do{ \
                                            bFM_GPIO_PDORE_P0=(v).bInitVal; \
                                            bFM_GPIO_DDRE_P0=1u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

/*---- GPIO bit NPE0 ----*/
#define GPIO1PIN_NPE0_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIRE_P0)) )

#define GPIO1PIN_NPE0_PUT(v)            ( bFM_GPIO_PDORE_P0=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE0_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NPE0_INITIN(v) \
                                                           : GPIO1PIN_NPE0_INITOUT(v) )

#define GPIO1PIN_NPE0_INITIN(v)         do{ \
                                            bFM_GPIO_PCRE_P0=(v).bPullup; \
                                            bFM_GPIO_DDRE_P0=0u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

#define GPIO1PIN_NPE0_INITOUT(v)        do{ \
                                            bFM_GPIO_PDORE_P0=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDRE_P0=1u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

/*---- GPIO bit PE2 ----*/
#define GPIO1PIN_PE2_GET                ( bFM_GPIO_PDIRE_P2 )

#define GPIO1PIN_PE2_PUT(v)             ( bFM_GPIO_PDORE_P2=(v) )

#define GPIO1PIN_PE2_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_PE2_INITIN(v) \
                                                           : GPIO1PIN_PE2_INITOUT(v) )

#define GPIO1PIN_PE2_INITIN(v)          do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P2=(v).bPullup; \
                                            bFM_GPIO_DDRE_P2=0u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

#define GPIO1PIN_PE2_INITOUT(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PDORE_P2=(v).bInitVal; \
                                            bFM_GPIO_DDRE_P2=1u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

/*---- GPIO bit NPE2 ----*/
#define GPIO1PIN_NPE2_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIRE_P2)) )

#define GPIO1PIN_NPE2_PUT(v)            ( bFM_GPIO_PDORE_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE2_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NPE2_INITIN(v) \
                                                           : GPIO1PIN_NPE2_INITOUT(v) )

#define GPIO1PIN_NPE2_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P2=(v).bPullup; \
                                            bFM_GPIO_DDRE_P2=0u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

#define GPIO1PIN_NPE2_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PDORE_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDRE_P2=1u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

/*---- GPIO bit PE3 ----*/
#define GPIO1PIN_PE3_GET                ( bFM_GPIO_PDIRE_P3 )

#define GPIO1PIN_PE3_PUT(v)             ( bFM_GPIO_PDORE_P3=(v) )

#define GPIO1PIN_PE3_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_PE3_INITIN(v) \
                                                           : GPIO1PIN_PE3_INITOUT(v) )

#define GPIO1PIN_PE3_INITIN(v)          do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P3=(v).bPullup; \
                                            bFM_GPIO_DDRE_P3=0u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

#define GPIO1PIN_PE3_INITOUT(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PDORE_P3=(v).bInitVal; \
                                            bFM_GPIO_DDRE_P3=1u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

/*---- GPIO bit NPE3 ----*/
#define GPIO1PIN_NPE3_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIRE_P3)) )

#define GPIO1PIN_NPE3_PUT(v)            ( bFM_GPIO_PDORE_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NPE3_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NPE3_INITIN(v) \
                                                           : GPIO1PIN_NPE3_INITOUT(v) )

#define GPIO1PIN_NPE3_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P3=(v).bPullup; \
                                            bFM_GPIO_DDRE_P3=0u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

#define GPIO1PIN_NPE3_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PDORE_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDRE_P3=1u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

/******************************************************************************
   Fast GPIO
*******************************************************************************/

/*---- Fast GPIO bit P00 ----*/
#define FGPIO1PIN_P00_GET               ( FM_FASTIO->FPDIR0_f.P0 )

#define FGPIO1PIN_P00_PUT(v)            ( FM_FASTIO->FPDOR0_f.P0=(v) )

#define FGPIO1PIN_P00_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P00_INITIN(v) \
                                                           : FGPIO1PIN_P00_INITOUT(v) )

#define FGPIO1PIN_P00_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P0=(v).bPullup; \
                                            bFM_GPIO_DDR0_P0=0u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

#define FGPIO1PIN_P00_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P0=1u; \
                                            bFM_GPIO_DDR0_P0=1u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

/*---- Fast GPIO bit NP00 ----*/
#define FGPIO1PIN_NP00_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P0)) )

#define FGPIO1PIN_NP00_PUT(v)           ( FM_FASTIO->FPDOR0_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP00_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP00_INITIN(v) \
                                                           : FGPIO1PIN_NP00_INITOUT(v) )

#define FGPIO1PIN_NP00_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P0=(v).bPullup; \
                                            bFM_GPIO_DDR0_P0=0u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

#define FGPIO1PIN_NP00_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P0=1u; \
                                            bFM_GPIO_DDR0_P0=1u; \
                                            bFM_GPIO_PFR0_P0=0u; }while(0u)

/*---- Fast GPIO bit P01 ----*/
#define FGPIO1PIN_P01_GET               ( FM_FASTIO->FPDIR0_f.P1 )

#define FGPIO1PIN_P01_PUT(v)            ( FM_FASTIO->FPDOR0_f.P1=(v) )

#define FGPIO1PIN_P01_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P01_INITIN(v) \
                                                           : FGPIO1PIN_P01_INITOUT(v) )

#define FGPIO1PIN_P01_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P1=(v).bPullup; \
                                            bFM_GPIO_DDR0_P1=0u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

#define FGPIO1PIN_P01_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P1=1u; \
                                            bFM_GPIO_DDR0_P1=1u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

/*---- Fast GPIO bit NP01 ----*/
#define FGPIO1PIN_NP01_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P1)) )

#define FGPIO1PIN_NP01_PUT(v)           ( FM_FASTIO->FPDOR0_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP01_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP01_INITIN(v) \
                                                           : FGPIO1PIN_NP01_INITOUT(v) )

#define FGPIO1PIN_NP01_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P1=(v).bPullup; \
                                            bFM_GPIO_DDR0_P1=0u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

#define FGPIO1PIN_NP01_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P1=1u; \
                                            bFM_GPIO_DDR0_P1=1u; \
                                            bFM_GPIO_PFR0_P1=0u; }while(0u)

/*---- Fast GPIO bit P02 ----*/
#define FGPIO1PIN_P02_GET               ( FM_FASTIO->FPDIR0_f.P2 )

#define FGPIO1PIN_P02_PUT(v)            ( FM_FASTIO->FPDOR0_f.P2=(v) )

#define FGPIO1PIN_P02_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P02_INITIN(v) \
                                                           : FGPIO1PIN_P02_INITOUT(v) )

#define FGPIO1PIN_P02_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P2=(v).bPullup; \
                                            bFM_GPIO_DDR0_P2=0u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

#define FGPIO1PIN_P02_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P2=1u; \
                                            bFM_GPIO_DDR0_P2=1u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

/*---- Fast GPIO bit NP02 ----*/
#define FGPIO1PIN_NP02_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P2)) )

#define FGPIO1PIN_NP02_PUT(v)           ( FM_FASTIO->FPDOR0_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP02_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP02_INITIN(v) \
                                                           : FGPIO1PIN_NP02_INITOUT(v) )

#define FGPIO1PIN_NP02_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P2=(v).bPullup; \
                                            bFM_GPIO_DDR0_P2=0u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

#define FGPIO1PIN_NP02_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P2=1u; \
                                            bFM_GPIO_DDR0_P2=1u; \
                                            bFM_GPIO_PFR0_P2=0u; }while(0u)

/*---- Fast GPIO bit P03 ----*/
#define FGPIO1PIN_P03_GET               ( FM_FASTIO->FPDIR0_f.P3 )

#define FGPIO1PIN_P03_PUT(v)            ( FM_FASTIO->FPDOR0_f.P3=(v) )

#define FGPIO1PIN_P03_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P03_INITIN(v) \
                                                           : FGPIO1PIN_P03_INITOUT(v) )

#define FGPIO1PIN_P03_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P3=(v).bPullup; \
                                            bFM_GPIO_DDR0_P3=0u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

#define FGPIO1PIN_P03_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P3=1u; \
                                            bFM_GPIO_DDR0_P3=1u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

/*---- Fast GPIO bit NP03 ----*/
#define FGPIO1PIN_NP03_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P3)) )

#define FGPIO1PIN_NP03_PUT(v)           ( FM_FASTIO->FPDOR0_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP03_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP03_INITIN(v) \
                                                           : FGPIO1PIN_NP03_INITOUT(v) )

#define FGPIO1PIN_NP03_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P3=(v).bPullup; \
                                            bFM_GPIO_DDR0_P3=0u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

#define FGPIO1PIN_NP03_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P3=1u; \
                                            bFM_GPIO_DDR0_P3=1u; \
                                            bFM_GPIO_PFR0_P3=0u; }while(0u)

/*---- Fast GPIO bit P04 ----*/
#define FGPIO1PIN_P04_GET               ( FM_FASTIO->FPDIR0_f.P4 )

#define FGPIO1PIN_P04_PUT(v)            ( FM_FASTIO->FPDOR0_f.P4=(v) )

#define FGPIO1PIN_P04_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P04_INITIN(v) \
                                                           : FGPIO1PIN_P04_INITOUT(v) )

#define FGPIO1PIN_P04_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P4=(v).bPullup; \
                                            bFM_GPIO_DDR0_P4=0u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

#define FGPIO1PIN_P04_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P4=1u; \
                                            bFM_GPIO_DDR0_P4=1u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

/*---- Fast GPIO bit NP04 ----*/
#define FGPIO1PIN_NP04_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P4)) )

#define FGPIO1PIN_NP04_PUT(v)           ( FM_FASTIO->FPDOR0_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP04_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP04_INITIN(v) \
                                                           : FGPIO1PIN_NP04_INITOUT(v) )

#define FGPIO1PIN_NP04_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P4=(v).bPullup; \
                                            bFM_GPIO_DDR0_P4=0u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

#define FGPIO1PIN_NP04_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P4=1u; \
                                            bFM_GPIO_DDR0_P4=1u; \
                                            bFM_GPIO_PFR0_P4=0u; }while(0u)

/*---- Fast GPIO bit P05 ----*/
#define FGPIO1PIN_P05_GET               ( FM_FASTIO->FPDIR0_f.P5 )

#define FGPIO1PIN_P05_PUT(v)            ( FM_FASTIO->FPDOR0_f.P5=(v) )

#define FGPIO1PIN_P05_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P05_INITIN(v) \
                                                           : FGPIO1PIN_P05_INITOUT(v) )

#define FGPIO1PIN_P05_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PCR0_P5=(v).bPullup; \
                                            bFM_GPIO_DDR0_P5=0u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

#define FGPIO1PIN_P05_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            FM_FASTIO->FPDOR0_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P5=1u; \
                                            bFM_GPIO_DDR0_P5=1u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

/*---- Fast GPIO bit NP05 ----*/
#define FGPIO1PIN_NP05_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P5)) )

#define FGPIO1PIN_NP05_PUT(v)           ( FM_FASTIO->FPDOR0_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP05_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP05_INITIN(v) \
                                                           : FGPIO1PIN_NP05_INITOUT(v) )

#define FGPIO1PIN_NP05_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PCR0_P5=(v).bPullup; \
                                            bFM_GPIO_DDR0_P5=0u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

#define FGPIO1PIN_NP05_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            FM_FASTIO->FPDOR0_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P5=1u; \
                                            bFM_GPIO_DDR0_P5=1u; \
                                            bFM_GPIO_PFR0_P5=0u; }while(0u)

/*---- Fast GPIO bit P06 ----*/
#define FGPIO1PIN_P06_GET               ( FM_FASTIO->FPDIR0_f.P6 )

#define FGPIO1PIN_P06_PUT(v)            ( FM_FASTIO->FPDOR0_f.P6=(v) )

#define FGPIO1PIN_P06_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P06_INITIN(v) \
                                                           : FGPIO1PIN_P06_INITOUT(v) )

#define FGPIO1PIN_P06_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PCR0_P6=(v).bPullup; \
                                            bFM_GPIO_DDR0_P6=0u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

#define FGPIO1PIN_P06_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            FM_FASTIO->FPDOR0_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P6=1u; \
                                            bFM_GPIO_DDR0_P6=1u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

/*---- Fast GPIO bit NP06 ----*/
#define FGPIO1PIN_NP06_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P6)) )

#define FGPIO1PIN_NP06_PUT(v)           ( FM_FASTIO->FPDOR0_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP06_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP06_INITIN(v) \
                                                           : FGPIO1PIN_NP06_INITOUT(v) )

#define FGPIO1PIN_NP06_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            bFM_GPIO_PCR0_P6=(v).bPullup; \
                                            bFM_GPIO_DDR0_P6=0u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

#define FGPIO1PIN_NP06_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            FM_FASTIO->FPDOR0_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P6=1u; \
                                            bFM_GPIO_DDR0_P6=1u; \
                                            bFM_GPIO_PFR0_P6=0u; }while(0u)

/*---- Fast GPIO bit P07 ----*/
#define FGPIO1PIN_P07_GET               ( FM_FASTIO->FPDIR0_f.P7 )

#define FGPIO1PIN_P07_PUT(v)            ( FM_FASTIO->FPDOR0_f.P7=(v) )

#define FGPIO1PIN_P07_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P07_INITIN(v) \
                                                           : FGPIO1PIN_P07_INITOUT(v) )

#define FGPIO1PIN_P07_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PCR0_P7=(v).bPullup; \
                                            bFM_GPIO_DDR0_P7=0u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

#define FGPIO1PIN_P07_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            FM_FASTIO->FPDOR0_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P7=1u; \
                                            bFM_GPIO_DDR0_P7=1u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

/*---- Fast GPIO bit NP07 ----*/
#define FGPIO1PIN_NP07_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P7)) )

#define FGPIO1PIN_NP07_PUT(v)           ( FM_FASTIO->FPDOR0_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP07_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP07_INITIN(v) \
                                                           : FGPIO1PIN_NP07_INITOUT(v) )

#define FGPIO1PIN_NP07_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            bFM_GPIO_PCR0_P7=(v).bPullup; \
                                            bFM_GPIO_DDR0_P7=0u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

#define FGPIO1PIN_NP07_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            FM_FASTIO->FPDOR0_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P7=1u; \
                                            bFM_GPIO_DDR0_P7=1u; \
                                            bFM_GPIO_PFR0_P7=0u; }while(0u)

/*---- Fast GPIO bit P08 ----*/
#define FGPIO1PIN_P08_GET               ( FM_FASTIO->FPDIR0_f.P8 )

#define FGPIO1PIN_P08_PUT(v)            ( FM_FASTIO->FPDOR0_f.P8=(v) )

#define FGPIO1PIN_P08_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P08_INITIN(v) \
                                                           : FGPIO1PIN_P08_INITOUT(v) )

#define FGPIO1PIN_P08_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PCR0_P8=(v).bPullup; \
                                            bFM_GPIO_DDR0_P8=0u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

#define FGPIO1PIN_P08_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            FM_FASTIO->FPDOR0_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P8=1u; \
                                            bFM_GPIO_DDR0_P8=1u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

/*---- Fast GPIO bit NP08 ----*/
#define FGPIO1PIN_NP08_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P8)) )

#define FGPIO1PIN_NP08_PUT(v)           ( FM_FASTIO->FPDOR0_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP08_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP08_INITIN(v) \
                                                           : FGPIO1PIN_NP08_INITOUT(v) )

#define FGPIO1PIN_NP08_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            bFM_GPIO_PCR0_P8=(v).bPullup; \
                                            bFM_GPIO_DDR0_P8=0u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

#define FGPIO1PIN_NP08_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            FM_FASTIO->FPDOR0_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P8=1u; \
                                            bFM_GPIO_DDR0_P8=1u; \
                                            bFM_GPIO_PFR0_P8=0u; }while(0u)

/*---- Fast GPIO bit P09 ----*/
#define FGPIO1PIN_P09_GET               ( FM_FASTIO->FPDIR0_f.P9 )

#define FGPIO1PIN_P09_PUT(v)            ( FM_FASTIO->FPDOR0_f.P9=(v) )

#define FGPIO1PIN_P09_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P09_INITIN(v) \
                                                           : FGPIO1PIN_P09_INITOUT(v) )

#define FGPIO1PIN_P09_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_P9=(v).bPullup; \
                                            bFM_GPIO_DDR0_P9=0u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

#define FGPIO1PIN_P09_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.P9=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.P9=1u; \
                                            bFM_GPIO_DDR0_P9=1u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

/*---- Fast GPIO bit NP09 ----*/
#define FGPIO1PIN_NP09_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.P9)) )

#define FGPIO1PIN_NP09_PUT(v)           ( FM_FASTIO->FPDOR0_f.P9=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP09_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP09_INITIN(v) \
                                                           : FGPIO1PIN_NP09_INITOUT(v) )

#define FGPIO1PIN_NP09_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_P9=(v).bPullup; \
                                            bFM_GPIO_DDR0_P9=0u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

#define FGPIO1PIN_NP09_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.P9=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.P9=1u; \
                                            bFM_GPIO_DDR0_P9=1u; \
                                            bFM_GPIO_PFR0_P9=0u; }while(0u)

/*---- Fast GPIO bit P0A ----*/
#define FGPIO1PIN_P0A_GET               ( FM_FASTIO->FPDIR0_f.PA )

#define FGPIO1PIN_P0A_PUT(v)            ( FM_FASTIO->FPDOR0_f.PA=(v) )

#define FGPIO1PIN_P0A_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0A_INITIN(v) \
                                                           : FGPIO1PIN_P0A_INITOUT(v) )

#define FGPIO1PIN_P0A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PA=(v).bPullup; \
                                            bFM_GPIO_DDR0_PA=0u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

#define FGPIO1PIN_P0A_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.PA=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PA=1u; \
                                            bFM_GPIO_DDR0_PA=1u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

/*---- Fast GPIO bit NP0A ----*/
#define FGPIO1PIN_NP0A_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PA)) )

#define FGPIO1PIN_NP0A_PUT(v)           ( FM_FASTIO->FPDOR0_f.PA=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0A_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0A_INITIN(v) \
                                                           : FGPIO1PIN_NP0A_INITOUT(v) )

#define FGPIO1PIN_NP0A_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_PA=(v).bPullup; \
                                            bFM_GPIO_DDR0_PA=0u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

#define FGPIO1PIN_NP0A_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.PA=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PA=1u; \
                                            bFM_GPIO_DDR0_PA=1u; \
                                            bFM_GPIO_PFR0_PA=0u; }while(0u)

/*---- Fast GPIO bit P0B ----*/
#define FGPIO1PIN_P0B_GET               ( FM_FASTIO->FPDIR0_f.PB )

#define FGPIO1PIN_P0B_PUT(v)            ( FM_FASTIO->FPDOR0_f.PB=(v) )

#define FGPIO1PIN_P0B_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0B_INITIN(v) \
                                                           : FGPIO1PIN_P0B_INITOUT(v) )

#define FGPIO1PIN_P0B_INITIN(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PB=(v).bPullup; \
                                            bFM_GPIO_DDR0_PB=0u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

#define FGPIO1PIN_P0B_INITOUT(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            FM_FASTIO->FPDOR0_f.PB=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PB=1u; \
                                            bFM_GPIO_DDR0_PB=1u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

/*---- Fast GPIO bit NP0B ----*/
#define FGPIO1PIN_NP0B_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PB)) )

#define FGPIO1PIN_NP0B_PUT(v)           ( FM_FASTIO->FPDOR0_f.PB=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0B_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0B_INITIN(v) \
                                                           : FGPIO1PIN_NP0B_INITOUT(v) )

#define FGPIO1PIN_NP0B_INITIN(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PB=(v).bPullup; \
                                            bFM_GPIO_DDR0_PB=0u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

#define FGPIO1PIN_NP0B_INITOUT(v)       do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            FM_FASTIO->FPDOR0_f.PB=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PB=1u; \
                                            bFM_GPIO_DDR0_PB=1u; \
                                            bFM_GPIO_PFR0_PB=0u; }while(0u)

/*---- Fast GPIO bit P0C ----*/
#define FGPIO1PIN_P0C_GET               ( FM_FASTIO->FPDIR0_f.PC )

#define FGPIO1PIN_P0C_PUT(v)            ( FM_FASTIO->FPDOR0_f.PC=(v) )

#define FGPIO1PIN_P0C_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0C_INITIN(v) \
                                                           : FGPIO1PIN_P0C_INITOUT(v) )

#define FGPIO1PIN_P0C_INITIN(v)         do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PC=(v).bPullup; \
                                            bFM_GPIO_DDR0_PC=0u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

#define FGPIO1PIN_P0C_INITOUT(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            FM_FASTIO->FPDOR0_f.PC=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PC=1u; \
                                            bFM_GPIO_DDR0_PC=1u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

/*---- Fast GPIO bit NP0C ----*/
#define FGPIO1PIN_NP0C_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PC)) )

#define FGPIO1PIN_NP0C_PUT(v)           ( FM_FASTIO->FPDOR0_f.PC=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0C_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0C_INITIN(v) \
                                                           : FGPIO1PIN_NP0C_INITOUT(v) )

#define FGPIO1PIN_NP0C_INITIN(v)        do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            bFM_GPIO_PCR0_PC=(v).bPullup; \
                                            bFM_GPIO_DDR0_PC=0u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

#define FGPIO1PIN_NP0C_INITOUT(v)       do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            FM_FASTIO->FPDOR0_f.PC=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PC=1u; \
                                            bFM_GPIO_DDR0_PC=1u; \
                                            bFM_GPIO_PFR0_PC=0u; }while(0u)

/*---- Fast GPIO bit P0D ----*/
#define FGPIO1PIN_P0D_GET               ( FM_FASTIO->FPDIR0_f.PD )

#define FGPIO1PIN_P0D_PUT(v)            ( FM_FASTIO->FPDOR0_f.PD=(v) )

#define FGPIO1PIN_P0D_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0D_INITIN(v) \
                                                           : FGPIO1PIN_P0D_INITOUT(v) )

#define FGPIO1PIN_P0D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PD=(v).bPullup; \
                                            bFM_GPIO_DDR0_PD=0u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

#define FGPIO1PIN_P0D_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.PD=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PD=1u; \
                                            bFM_GPIO_DDR0_PD=1u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

/*---- Fast GPIO bit NP0D ----*/
#define FGPIO1PIN_NP0D_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PD)) )

#define FGPIO1PIN_NP0D_PUT(v)           ( FM_FASTIO->FPDOR0_f.PD=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0D_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0D_INITIN(v) \
                                                           : FGPIO1PIN_NP0D_INITOUT(v) )

#define FGPIO1PIN_NP0D_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_PD=(v).bPullup; \
                                            bFM_GPIO_DDR0_PD=0u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

#define FGPIO1PIN_NP0D_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.PD=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PD=1u; \
                                            bFM_GPIO_DDR0_PD=1u; \
                                            bFM_GPIO_PFR0_PD=0u; }while(0u)

/*---- Fast GPIO bit P0E ----*/
#define FGPIO1PIN_P0E_GET               ( FM_FASTIO->FPDIR0_f.PE )

#define FGPIO1PIN_P0E_PUT(v)            ( FM_FASTIO->FPDOR0_f.PE=(v) )

#define FGPIO1PIN_P0E_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0E_INITIN(v) \
                                                           : FGPIO1PIN_P0E_INITOUT(v) )

#define FGPIO1PIN_P0E_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PE=(v).bPullup; \
                                            bFM_GPIO_DDR0_PE=0u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

#define FGPIO1PIN_P0E_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.PE=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PE=1u; \
                                            bFM_GPIO_DDR0_PE=1u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

/*---- Fast GPIO bit NP0E ----*/
#define FGPIO1PIN_NP0E_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PE)) )

#define FGPIO1PIN_NP0E_PUT(v)           ( FM_FASTIO->FPDOR0_f.PE=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0E_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0E_INITIN(v) \
                                                           : FGPIO1PIN_NP0E_INITOUT(v) )

#define FGPIO1PIN_NP0E_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_PE=(v).bPullup; \
                                            bFM_GPIO_DDR0_PE=0u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

#define FGPIO1PIN_NP0E_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.PE=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PE=1u; \
                                            bFM_GPIO_DDR0_PE=1u; \
                                            bFM_GPIO_PFR0_PE=0u; }while(0u)

/*---- Fast GPIO bit P0F ----*/
#define FGPIO1PIN_P0F_GET               ( FM_FASTIO->FPDIR0_f.PF )

#define FGPIO1PIN_P0F_PUT(v)            ( FM_FASTIO->FPDOR0_f.PF=(v) )

#define FGPIO1PIN_P0F_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P0F_INITIN(v) \
                                                           : FGPIO1PIN_P0F_INITOUT(v) )

#define FGPIO1PIN_P0F_INITIN(v)         do{ \
                                            bFM_GPIO_PCR0_PF=(v).bPullup; \
                                            bFM_GPIO_DDR0_PF=0u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

#define FGPIO1PIN_P0F_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR0_f.PF=(v).bInitVal; \
                                            FM_GPIO->FPOER0_f.PF=1u; \
                                            bFM_GPIO_DDR0_PF=1u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

/*---- Fast GPIO bit NP0F ----*/
#define FGPIO1PIN_NP0F_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR0_f.PF)) )

#define FGPIO1PIN_NP0F_PUT(v)           ( FM_FASTIO->FPDOR0_f.PF=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP0F_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP0F_INITIN(v) \
                                                           : FGPIO1PIN_NP0F_INITOUT(v) )

#define FGPIO1PIN_NP0F_INITIN(v)        do{ \
                                            bFM_GPIO_PCR0_PF=(v).bPullup; \
                                            bFM_GPIO_DDR0_PF=0u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

#define FGPIO1PIN_NP0F_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR0_f.PF=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER0_f.PF=1u; \
                                            bFM_GPIO_DDR0_PF=1u; \
                                            bFM_GPIO_PFR0_PF=0u; }while(0u)

/*---- Fast GPIO bit P10 ----*/
#define FGPIO1PIN_P10_GET               ( FM_FASTIO->FPDIR1_f.P0 )

#define FGPIO1PIN_P10_PUT(v)            ( FM_FASTIO->FPDOR1_f.P0=(v) )

#define FGPIO1PIN_P10_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P10_INITIN(v) \
                                                           : FGPIO1PIN_P10_INITOUT(v) )

#define FGPIO1PIN_P10_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PCR1_P0=(v).bPullup; \
                                            bFM_GPIO_DDR1_P0=0u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

#define FGPIO1PIN_P10_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            FM_FASTIO->FPDOR1_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P0=1u; \
                                            bFM_GPIO_DDR1_P0=1u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

/*---- Fast GPIO bit NP10 ----*/
#define FGPIO1PIN_NP10_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P0)) )

#define FGPIO1PIN_NP10_PUT(v)           ( FM_FASTIO->FPDOR1_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP10_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP10_INITIN(v) \
                                                           : FGPIO1PIN_NP10_INITOUT(v) )

#define FGPIO1PIN_NP10_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            bFM_GPIO_PCR1_P0=(v).bPullup; \
                                            bFM_GPIO_DDR1_P0=0u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

#define FGPIO1PIN_NP10_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            FM_FASTIO->FPDOR1_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P0=1u; \
                                            bFM_GPIO_DDR1_P0=1u; \
                                            bFM_GPIO_PFR1_P0=0u; }while(0u)

/*---- Fast GPIO bit P11 ----*/
#define FGPIO1PIN_P11_GET               ( FM_FASTIO->FPDIR1_f.P1 )

#define FGPIO1PIN_P11_PUT(v)            ( FM_FASTIO->FPDOR1_f.P1=(v) )

#define FGPIO1PIN_P11_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P11_INITIN(v) \
                                                           : FGPIO1PIN_P11_INITOUT(v) )

#define FGPIO1PIN_P11_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PCR1_P1=(v).bPullup; \
                                            bFM_GPIO_DDR1_P1=0u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

#define FGPIO1PIN_P11_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            FM_FASTIO->FPDOR1_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P1=1u; \
                                            bFM_GPIO_DDR1_P1=1u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

/*---- Fast GPIO bit NP11 ----*/
#define FGPIO1PIN_NP11_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P1)) )

#define FGPIO1PIN_NP11_PUT(v)           ( FM_FASTIO->FPDOR1_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP11_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP11_INITIN(v) \
                                                           : FGPIO1PIN_NP11_INITOUT(v) )

#define FGPIO1PIN_NP11_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PCR1_P1=(v).bPullup; \
                                            bFM_GPIO_DDR1_P1=0u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

#define FGPIO1PIN_NP11_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            FM_FASTIO->FPDOR1_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P1=1u; \
                                            bFM_GPIO_DDR1_P1=1u; \
                                            bFM_GPIO_PFR1_P1=0u; }while(0u)

/*---- Fast GPIO bit P12 ----*/
#define FGPIO1PIN_P12_GET               ( FM_FASTIO->FPDIR1_f.P2 )

#define FGPIO1PIN_P12_PUT(v)            ( FM_FASTIO->FPDOR1_f.P2=(v) )

#define FGPIO1PIN_P12_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P12_INITIN(v) \
                                                           : FGPIO1PIN_P12_INITOUT(v) )

#define FGPIO1PIN_P12_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PCR1_P2=(v).bPullup; \
                                            bFM_GPIO_DDR1_P2=0u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

#define FGPIO1PIN_P12_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            FM_FASTIO->FPDOR1_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P2=1u; \
                                            bFM_GPIO_DDR1_P2=1u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

/*---- Fast GPIO bit NP12 ----*/
#define FGPIO1PIN_NP12_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P2)) )

#define FGPIO1PIN_NP12_PUT(v)           ( FM_FASTIO->FPDOR1_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP12_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP12_INITIN(v) \
                                                           : FGPIO1PIN_NP12_INITOUT(v) )

#define FGPIO1PIN_NP12_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            bFM_GPIO_PCR1_P2=(v).bPullup; \
                                            bFM_GPIO_DDR1_P2=0u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

#define FGPIO1PIN_NP12_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            FM_FASTIO->FPDOR1_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P2=1u; \
                                            bFM_GPIO_DDR1_P2=1u; \
                                            bFM_GPIO_PFR1_P2=0u; }while(0u)

/*---- Fast GPIO bit P13 ----*/
#define FGPIO1PIN_P13_GET               ( FM_FASTIO->FPDIR1_f.P3 )

#define FGPIO1PIN_P13_PUT(v)            ( FM_FASTIO->FPDOR1_f.P3=(v) )

#define FGPIO1PIN_P13_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P13_INITIN(v) \
                                                           : FGPIO1PIN_P13_INITOUT(v) )

#define FGPIO1PIN_P13_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PCR1_P3=(v).bPullup; \
                                            bFM_GPIO_DDR1_P3=0u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

#define FGPIO1PIN_P13_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            FM_FASTIO->FPDOR1_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P3=1u; \
                                            bFM_GPIO_DDR1_P3=1u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

/*---- Fast GPIO bit NP13 ----*/
#define FGPIO1PIN_NP13_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P3)) )

#define FGPIO1PIN_NP13_PUT(v)           ( FM_FASTIO->FPDOR1_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP13_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP13_INITIN(v) \
                                                           : FGPIO1PIN_NP13_INITOUT(v) )

#define FGPIO1PIN_NP13_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            bFM_GPIO_PCR1_P3=(v).bPullup; \
                                            bFM_GPIO_DDR1_P3=0u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

#define FGPIO1PIN_NP13_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            FM_FASTIO->FPDOR1_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P3=1u; \
                                            bFM_GPIO_DDR1_P3=1u; \
                                            bFM_GPIO_PFR1_P3=0u; }while(0u)

/*---- Fast GPIO bit P14 ----*/
#define FGPIO1PIN_P14_GET               ( FM_FASTIO->FPDIR1_f.P4 )

#define FGPIO1PIN_P14_PUT(v)            ( FM_FASTIO->FPDOR1_f.P4=(v) )

#define FGPIO1PIN_P14_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P14_INITIN(v) \
                                                           : FGPIO1PIN_P14_INITOUT(v) )

#define FGPIO1PIN_P14_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PCR1_P4=(v).bPullup; \
                                            bFM_GPIO_DDR1_P4=0u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

#define FGPIO1PIN_P14_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            FM_FASTIO->FPDOR1_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P4=1u; \
                                            bFM_GPIO_DDR1_P4=1u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

/*---- Fast GPIO bit NP14 ----*/
#define FGPIO1PIN_NP14_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P4)) )

#define FGPIO1PIN_NP14_PUT(v)           ( FM_FASTIO->FPDOR1_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP14_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP14_INITIN(v) \
                                                           : FGPIO1PIN_NP14_INITOUT(v) )

#define FGPIO1PIN_NP14_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            bFM_GPIO_PCR1_P4=(v).bPullup; \
                                            bFM_GPIO_DDR1_P4=0u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

#define FGPIO1PIN_NP14_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            FM_FASTIO->FPDOR1_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P4=1u; \
                                            bFM_GPIO_DDR1_P4=1u; \
                                            bFM_GPIO_PFR1_P4=0u; }while(0u)

/*---- Fast GPIO bit P15 ----*/
#define FGPIO1PIN_P15_GET               ( FM_FASTIO->FPDIR1_f.P5 )

#define FGPIO1PIN_P15_PUT(v)            ( FM_FASTIO->FPDOR1_f.P5=(v) )

#define FGPIO1PIN_P15_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P15_INITIN(v) \
                                                           : FGPIO1PIN_P15_INITOUT(v) )

#define FGPIO1PIN_P15_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PCR1_P5=(v).bPullup; \
                                            bFM_GPIO_DDR1_P5=0u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

#define FGPIO1PIN_P15_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            FM_FASTIO->FPDOR1_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P5=1u; \
                                            bFM_GPIO_DDR1_P5=1u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

/*---- Fast GPIO bit NP15 ----*/
#define FGPIO1PIN_NP15_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P5)) )

#define FGPIO1PIN_NP15_PUT(v)           ( FM_FASTIO->FPDOR1_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP15_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP15_INITIN(v) \
                                                           : FGPIO1PIN_NP15_INITOUT(v) )

#define FGPIO1PIN_NP15_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            bFM_GPIO_PCR1_P5=(v).bPullup; \
                                            bFM_GPIO_DDR1_P5=0u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

#define FGPIO1PIN_NP15_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            FM_FASTIO->FPDOR1_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P5=1u; \
                                            bFM_GPIO_DDR1_P5=1u; \
                                            bFM_GPIO_PFR1_P5=0u; }while(0u)

/*---- Fast GPIO bit P16 ----*/
#define FGPIO1PIN_P16_GET               ( FM_FASTIO->FPDIR1_f.P6 )

#define FGPIO1PIN_P16_PUT(v)            ( FM_FASTIO->FPDOR1_f.P6=(v) )

#define FGPIO1PIN_P16_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P16_INITIN(v) \
                                                           : FGPIO1PIN_P16_INITOUT(v) )

#define FGPIO1PIN_P16_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR1_P6=(v).bPullup; \
                                            bFM_GPIO_DDR1_P6=0u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

#define FGPIO1PIN_P16_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            FM_FASTIO->FPDOR1_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P6=1u; \
                                            bFM_GPIO_DDR1_P6=1u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

/*---- Fast GPIO bit NP16 ----*/
#define FGPIO1PIN_NP16_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P6)) )

#define FGPIO1PIN_NP16_PUT(v)           ( FM_FASTIO->FPDOR1_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP16_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP16_INITIN(v) \
                                                           : FGPIO1PIN_NP16_INITOUT(v) )

#define FGPIO1PIN_NP16_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR1_P6=(v).bPullup; \
                                            bFM_GPIO_DDR1_P6=0u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

#define FGPIO1PIN_NP16_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            FM_FASTIO->FPDOR1_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P6=1u; \
                                            bFM_GPIO_DDR1_P6=1u; \
                                            bFM_GPIO_PFR1_P6=0u; }while(0u)

/*---- Fast GPIO bit P17 ----*/
#define FGPIO1PIN_P17_GET               ( FM_FASTIO->FPDIR1_f.P7 )

#define FGPIO1PIN_P17_PUT(v)            ( FM_FASTIO->FPDOR1_f.P7=(v) )

#define FGPIO1PIN_P17_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P17_INITIN(v) \
                                                           : FGPIO1PIN_P17_INITOUT(v) )

#define FGPIO1PIN_P17_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR1_P7=(v).bPullup; \
                                            bFM_GPIO_DDR1_P7=0u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

#define FGPIO1PIN_P17_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            FM_FASTIO->FPDOR1_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P7=1u; \
                                            bFM_GPIO_DDR1_P7=1u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

/*---- Fast GPIO bit NP17 ----*/
#define FGPIO1PIN_NP17_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P7)) )

#define FGPIO1PIN_NP17_PUT(v)           ( FM_FASTIO->FPDOR1_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP17_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP17_INITIN(v) \
                                                           : FGPIO1PIN_NP17_INITOUT(v) )

#define FGPIO1PIN_NP17_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR1_P7=(v).bPullup; \
                                            bFM_GPIO_DDR1_P7=0u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

#define FGPIO1PIN_NP17_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            FM_FASTIO->FPDOR1_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P7=1u; \
                                            bFM_GPIO_DDR1_P7=1u; \
                                            bFM_GPIO_PFR1_P7=0u; }while(0u)

/*---- Fast GPIO bit P18 ----*/
#define FGPIO1PIN_P18_GET               ( FM_FASTIO->FPDIR1_f.P8 )

#define FGPIO1PIN_P18_PUT(v)            ( FM_FASTIO->FPDOR1_f.P8=(v) )

#define FGPIO1PIN_P18_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P18_INITIN(v) \
                                                           : FGPIO1PIN_P18_INITOUT(v) )

#define FGPIO1PIN_P18_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PCR1_P8=(v).bPullup; \
                                            bFM_GPIO_DDR1_P8=0u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

#define FGPIO1PIN_P18_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            FM_FASTIO->FPDOR1_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P8=1u; \
                                            bFM_GPIO_DDR1_P8=1u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

/*---- Fast GPIO bit NP18 ----*/
#define FGPIO1PIN_NP18_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P8)) )

#define FGPIO1PIN_NP18_PUT(v)           ( FM_FASTIO->FPDOR1_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP18_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP18_INITIN(v) \
                                                           : FGPIO1PIN_NP18_INITOUT(v) )

#define FGPIO1PIN_NP18_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            bFM_GPIO_PCR1_P8=(v).bPullup; \
                                            bFM_GPIO_DDR1_P8=0u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

#define FGPIO1PIN_NP18_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            FM_FASTIO->FPDOR1_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P8=1u; \
                                            bFM_GPIO_DDR1_P8=1u; \
                                            bFM_GPIO_PFR1_P8=0u; }while(0u)

/*---- Fast GPIO bit P19 ----*/
#define FGPIO1PIN_P19_GET               ( FM_FASTIO->FPDIR1_f.P9 )

#define FGPIO1PIN_P19_PUT(v)            ( FM_FASTIO->FPDOR1_f.P9=(v) )

#define FGPIO1PIN_P19_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P19_INITIN(v) \
                                                           : FGPIO1PIN_P19_INITOUT(v) )

#define FGPIO1PIN_P19_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PCR1_P9=(v).bPullup; \
                                            bFM_GPIO_DDR1_P9=0u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

#define FGPIO1PIN_P19_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            FM_FASTIO->FPDOR1_f.P9=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.P9=1u; \
                                            bFM_GPIO_DDR1_P9=1u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

/*---- Fast GPIO bit NP19 ----*/
#define FGPIO1PIN_NP19_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.P9)) )

#define FGPIO1PIN_NP19_PUT(v)           ( FM_FASTIO->FPDOR1_f.P9=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP19_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP19_INITIN(v) \
                                                           : FGPIO1PIN_NP19_INITOUT(v) )

#define FGPIO1PIN_NP19_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            bFM_GPIO_PCR1_P9=(v).bPullup; \
                                            bFM_GPIO_DDR1_P9=0u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

#define FGPIO1PIN_NP19_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            FM_FASTIO->FPDOR1_f.P9=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.P9=1u; \
                                            bFM_GPIO_DDR1_P9=1u; \
                                            bFM_GPIO_PFR1_P9=0u; }while(0u)

/*---- Fast GPIO bit P1A ----*/
#define FGPIO1PIN_P1A_GET               ( FM_FASTIO->FPDIR1_f.PA )

#define FGPIO1PIN_P1A_PUT(v)            ( FM_FASTIO->FPDOR1_f.PA=(v) )

#define FGPIO1PIN_P1A_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P1A_INITIN(v) \
                                                           : FGPIO1PIN_P1A_INITOUT(v) )

#define FGPIO1PIN_P1A_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PCR1_PA=(v).bPullup; \
                                            bFM_GPIO_DDR1_PA=0u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

#define FGPIO1PIN_P1A_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            FM_FASTIO->FPDOR1_f.PA=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.PA=1u; \
                                            bFM_GPIO_DDR1_PA=1u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

/*---- Fast GPIO bit NP1A ----*/
#define FGPIO1PIN_NP1A_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.PA)) )

#define FGPIO1PIN_NP1A_PUT(v)           ( FM_FASTIO->FPDOR1_f.PA=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP1A_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP1A_INITIN(v) \
                                                           : FGPIO1PIN_NP1A_INITOUT(v) )

#define FGPIO1PIN_NP1A_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            bFM_GPIO_PCR1_PA=(v).bPullup; \
                                            bFM_GPIO_DDR1_PA=0u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

#define FGPIO1PIN_NP1A_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            FM_FASTIO->FPDOR1_f.PA=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.PA=1u; \
                                            bFM_GPIO_DDR1_PA=1u; \
                                            bFM_GPIO_PFR1_PA=0u; }while(0u)

/*---- Fast GPIO bit P1B ----*/
#define FGPIO1PIN_P1B_GET               ( FM_FASTIO->FPDIR1_f.PB )

#define FGPIO1PIN_P1B_PUT(v)            ( FM_FASTIO->FPDOR1_f.PB=(v) )

#define FGPIO1PIN_P1B_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P1B_INITIN(v) \
                                                           : FGPIO1PIN_P1B_INITOUT(v) )

#define FGPIO1PIN_P1B_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PCR1_PB=(v).bPullup; \
                                            bFM_GPIO_DDR1_PB=0u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

#define FGPIO1PIN_P1B_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            FM_FASTIO->FPDOR1_f.PB=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.PB=1u; \
                                            bFM_GPIO_DDR1_PB=1u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

/*---- Fast GPIO bit NP1B ----*/
#define FGPIO1PIN_NP1B_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.PB)) )

#define FGPIO1PIN_NP1B_PUT(v)           ( FM_FASTIO->FPDOR1_f.PB=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP1B_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP1B_INITIN(v) \
                                                           : FGPIO1PIN_NP1B_INITOUT(v) )

#define FGPIO1PIN_NP1B_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            bFM_GPIO_PCR1_PB=(v).bPullup; \
                                            bFM_GPIO_DDR1_PB=0u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

#define FGPIO1PIN_NP1B_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            FM_FASTIO->FPDOR1_f.PB=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.PB=1u; \
                                            bFM_GPIO_DDR1_PB=1u; \
                                            bFM_GPIO_PFR1_PB=0u; }while(0u)

/*---- Fast GPIO bit P1C ----*/
#define FGPIO1PIN_P1C_GET               ( FM_FASTIO->FPDIR1_f.PC )

#define FGPIO1PIN_P1C_PUT(v)            ( FM_FASTIO->FPDOR1_f.PC=(v) )

#define FGPIO1PIN_P1C_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P1C_INITIN(v) \
                                                           : FGPIO1PIN_P1C_INITOUT(v) )

#define FGPIO1PIN_P1C_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PCR1_PC=(v).bPullup; \
                                            bFM_GPIO_DDR1_PC=0u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

#define FGPIO1PIN_P1C_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            FM_FASTIO->FPDOR1_f.PC=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.PC=1u; \
                                            bFM_GPIO_DDR1_PC=1u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

/*---- Fast GPIO bit NP1C ----*/
#define FGPIO1PIN_NP1C_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.PC)) )

#define FGPIO1PIN_NP1C_PUT(v)           ( FM_FASTIO->FPDOR1_f.PC=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP1C_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP1C_INITIN(v) \
                                                           : FGPIO1PIN_NP1C_INITOUT(v) )

#define FGPIO1PIN_NP1C_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            bFM_GPIO_PCR1_PC=(v).bPullup; \
                                            bFM_GPIO_DDR1_PC=0u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

#define FGPIO1PIN_NP1C_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            FM_FASTIO->FPDOR1_f.PC=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.PC=1u; \
                                            bFM_GPIO_DDR1_PC=1u; \
                                            bFM_GPIO_PFR1_PC=0u; }while(0u)

/*---- Fast GPIO bit P1D ----*/
#define FGPIO1PIN_P1D_GET               ( FM_FASTIO->FPDIR1_f.PD )

#define FGPIO1PIN_P1D_PUT(v)            ( FM_FASTIO->FPDOR1_f.PD=(v) )

#define FGPIO1PIN_P1D_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P1D_INITIN(v) \
                                                           : FGPIO1PIN_P1D_INITOUT(v) )

#define FGPIO1PIN_P1D_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PCR1_PD=(v).bPullup; \
                                            bFM_GPIO_DDR1_PD=0u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

#define FGPIO1PIN_P1D_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            FM_FASTIO->FPDOR1_f.PD=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.PD=1u; \
                                            bFM_GPIO_DDR1_PD=1u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

/*---- Fast GPIO bit NP1D ----*/
#define FGPIO1PIN_NP1D_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.PD)) )

#define FGPIO1PIN_NP1D_PUT(v)           ( FM_FASTIO->FPDOR1_f.PD=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP1D_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP1D_INITIN(v) \
                                                           : FGPIO1PIN_NP1D_INITOUT(v) )

#define FGPIO1PIN_NP1D_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            bFM_GPIO_PCR1_PD=(v).bPullup; \
                                            bFM_GPIO_DDR1_PD=0u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

#define FGPIO1PIN_NP1D_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            FM_FASTIO->FPDOR1_f.PD=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.PD=1u; \
                                            bFM_GPIO_DDR1_PD=1u; \
                                            bFM_GPIO_PFR1_PD=0u; }while(0u)

/*---- Fast GPIO bit P1E ----*/
#define FGPIO1PIN_P1E_GET               ( FM_FASTIO->FPDIR1_f.PE )

#define FGPIO1PIN_P1E_PUT(v)            ( FM_FASTIO->FPDOR1_f.PE=(v) )

#define FGPIO1PIN_P1E_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P1E_INITIN(v) \
                                                           : FGPIO1PIN_P1E_INITOUT(v) )

#define FGPIO1PIN_P1E_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PCR1_PE=(v).bPullup; \
                                            bFM_GPIO_DDR1_PE=0u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

#define FGPIO1PIN_P1E_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            FM_FASTIO->FPDOR1_f.PE=(v).bInitVal; \
                                            FM_GPIO->FPOER1_f.PE=1u; \
                                            bFM_GPIO_DDR1_PE=1u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

/*---- Fast GPIO bit NP1E ----*/
#define FGPIO1PIN_NP1E_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR1_f.PE)) )

#define FGPIO1PIN_NP1E_PUT(v)           ( FM_FASTIO->FPDOR1_f.PE=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP1E_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP1E_INITIN(v) \
                                                           : FGPIO1PIN_NP1E_INITOUT(v) )

#define FGPIO1PIN_NP1E_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            bFM_GPIO_PCR1_PE=(v).bPullup; \
                                            bFM_GPIO_DDR1_PE=0u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

#define FGPIO1PIN_NP1E_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            FM_FASTIO->FPDOR1_f.PE=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER1_f.PE=1u; \
                                            bFM_GPIO_DDR1_PE=1u; \
                                            bFM_GPIO_PFR1_PE=0u; }while(0u)

/*---- Fast GPIO bit P20 ----*/
#define FGPIO1PIN_P20_GET               ( FM_FASTIO->FPDIR2_f.P0 )

#define FGPIO1PIN_P20_PUT(v)            ( FM_FASTIO->FPDOR2_f.P0=(v) )

#define FGPIO1PIN_P20_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P20_INITIN(v) \
                                                           : FGPIO1PIN_P20_INITOUT(v) )

#define FGPIO1PIN_P20_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PCR2_P0=(v).bPullup; \
                                            bFM_GPIO_DDR2_P0=0u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

#define FGPIO1PIN_P20_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            FM_FASTIO->FPDOR2_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P0=1u; \
                                            bFM_GPIO_DDR2_P0=1u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

/*---- Fast GPIO bit NP20 ----*/
#define FGPIO1PIN_NP20_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P0)) )

#define FGPIO1PIN_NP20_PUT(v)           ( FM_FASTIO->FPDOR2_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP20_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP20_INITIN(v) \
                                                           : FGPIO1PIN_NP20_INITOUT(v) )

#define FGPIO1PIN_NP20_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            bFM_GPIO_PCR2_P0=(v).bPullup; \
                                            bFM_GPIO_DDR2_P0=0u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

#define FGPIO1PIN_NP20_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            FM_FASTIO->FPDOR2_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P0=1u; \
                                            bFM_GPIO_DDR2_P0=1u; \
                                            bFM_GPIO_PFR2_P0=0u; }while(0u)

/*---- Fast GPIO bit P21 ----*/
#define FGPIO1PIN_P21_GET               ( FM_FASTIO->FPDIR2_f.P1 )

#define FGPIO1PIN_P21_PUT(v)            ( FM_FASTIO->FPDOR2_f.P1=(v) )

#define FGPIO1PIN_P21_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P21_INITIN(v) \
                                                           : FGPIO1PIN_P21_INITOUT(v) )

#define FGPIO1PIN_P21_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define FGPIO1PIN_P21_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            FM_FASTIO->FPDOR2_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P1=1u; \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- Fast GPIO bit NP21 ----*/
#define FGPIO1PIN_NP21_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P1)) )

#define FGPIO1PIN_NP21_PUT(v)           ( FM_FASTIO->FPDOR2_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP21_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP21_INITIN(v) \
                                                           : FGPIO1PIN_NP21_INITOUT(v) )

#define FGPIO1PIN_NP21_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define FGPIO1PIN_NP21_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            FM_FASTIO->FPDOR2_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P1=1u; \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- Fast GPIO bit P22 ----*/
#define FGPIO1PIN_P22_GET               ( FM_FASTIO->FPDIR2_f.P2 )

#define FGPIO1PIN_P22_PUT(v)            ( FM_FASTIO->FPDOR2_f.P2=(v) )

#define FGPIO1PIN_P22_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P22_INITIN(v) \
                                                           : FGPIO1PIN_P22_INITOUT(v) )

#define FGPIO1PIN_P22_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define FGPIO1PIN_P22_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            FM_FASTIO->FPDOR2_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P2=1u; \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- Fast GPIO bit NP22 ----*/
#define FGPIO1PIN_NP22_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P2)) )

#define FGPIO1PIN_NP22_PUT(v)           ( FM_FASTIO->FPDOR2_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP22_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP22_INITIN(v) \
                                                           : FGPIO1PIN_NP22_INITOUT(v) )

#define FGPIO1PIN_NP22_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define FGPIO1PIN_NP22_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            FM_FASTIO->FPDOR2_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P2=1u; \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- Fast GPIO bit P23 ----*/
#define FGPIO1PIN_P23_GET               ( FM_FASTIO->FPDIR2_f.P3 )

#define FGPIO1PIN_P23_PUT(v)            ( FM_FASTIO->FPDOR2_f.P3=(v) )

#define FGPIO1PIN_P23_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P23_INITIN(v) \
                                                           : FGPIO1PIN_P23_INITOUT(v) )

#define FGPIO1PIN_P23_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define FGPIO1PIN_P23_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            FM_FASTIO->FPDOR2_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P3=1u; \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

/*---- Fast GPIO bit NP23 ----*/
#define FGPIO1PIN_NP23_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P3)) )

#define FGPIO1PIN_NP23_PUT(v)           ( FM_FASTIO->FPDOR2_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP23_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP23_INITIN(v) \
                                                           : FGPIO1PIN_NP23_INITOUT(v) )

#define FGPIO1PIN_NP23_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define FGPIO1PIN_NP23_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            FM_FASTIO->FPDOR2_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P3=1u; \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

/*---- Fast GPIO bit P24 ----*/
#define FGPIO1PIN_P24_GET               ( FM_FASTIO->FPDIR2_f.P4 )

#define FGPIO1PIN_P24_PUT(v)            ( FM_FASTIO->FPDOR2_f.P4=(v) )

#define FGPIO1PIN_P24_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P24_INITIN(v) \
                                                           : FGPIO1PIN_P24_INITOUT(v) )

#define FGPIO1PIN_P24_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P4=(v).bPullup; \
                                            bFM_GPIO_DDR2_P4=0u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

#define FGPIO1PIN_P24_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR2_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P4=1u; \
                                            bFM_GPIO_DDR2_P4=1u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

/*---- Fast GPIO bit NP24 ----*/
#define FGPIO1PIN_NP24_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P4)) )

#define FGPIO1PIN_NP24_PUT(v)           ( FM_FASTIO->FPDOR2_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP24_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP24_INITIN(v) \
                                                           : FGPIO1PIN_NP24_INITOUT(v) )

#define FGPIO1PIN_NP24_INITIN(v)        do{ \
                                            bFM_GPIO_PCR2_P4=(v).bPullup; \
                                            bFM_GPIO_DDR2_P4=0u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

#define FGPIO1PIN_NP24_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR2_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P4=1u; \
                                            bFM_GPIO_DDR2_P4=1u; \
                                            bFM_GPIO_PFR2_P4=0u; }while(0u)

/*---- Fast GPIO bit P25 ----*/
#define FGPIO1PIN_P25_GET               ( FM_FASTIO->FPDIR2_f.P5 )

#define FGPIO1PIN_P25_PUT(v)            ( FM_FASTIO->FPDOR2_f.P5=(v) )

#define FGPIO1PIN_P25_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P25_INITIN(v) \
                                                           : FGPIO1PIN_P25_INITOUT(v) )

#define FGPIO1PIN_P25_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P5=(v).bPullup; \
                                            bFM_GPIO_DDR2_P5=0u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

#define FGPIO1PIN_P25_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR2_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P5=1u; \
                                            bFM_GPIO_DDR2_P5=1u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

/*---- Fast GPIO bit NP25 ----*/
#define FGPIO1PIN_NP25_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P5)) )

#define FGPIO1PIN_NP25_PUT(v)           ( FM_FASTIO->FPDOR2_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP25_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP25_INITIN(v) \
                                                           : FGPIO1PIN_NP25_INITOUT(v) )

#define FGPIO1PIN_NP25_INITIN(v)        do{ \
                                            bFM_GPIO_PCR2_P5=(v).bPullup; \
                                            bFM_GPIO_DDR2_P5=0u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

#define FGPIO1PIN_NP25_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR2_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P5=1u; \
                                            bFM_GPIO_DDR2_P5=1u; \
                                            bFM_GPIO_PFR2_P5=0u; }while(0u)

/*---- Fast GPIO bit P26 ----*/
#define FGPIO1PIN_P26_GET               ( FM_FASTIO->FPDIR2_f.P6 )

#define FGPIO1PIN_P26_PUT(v)            ( FM_FASTIO->FPDOR2_f.P6=(v) )

#define FGPIO1PIN_P26_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P26_INITIN(v) \
                                                           : FGPIO1PIN_P26_INITOUT(v) )

#define FGPIO1PIN_P26_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P6=(v).bPullup; \
                                            bFM_GPIO_DDR2_P6=0u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

#define FGPIO1PIN_P26_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR2_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P6=1u; \
                                            bFM_GPIO_DDR2_P6=1u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

/*---- Fast GPIO bit NP26 ----*/
#define FGPIO1PIN_NP26_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P6)) )

#define FGPIO1PIN_NP26_PUT(v)           ( FM_FASTIO->FPDOR2_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP26_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP26_INITIN(v) \
                                                           : FGPIO1PIN_NP26_INITOUT(v) )

#define FGPIO1PIN_NP26_INITIN(v)        do{ \
                                            bFM_GPIO_PCR2_P6=(v).bPullup; \
                                            bFM_GPIO_DDR2_P6=0u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

#define FGPIO1PIN_NP26_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR2_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P6=1u; \
                                            bFM_GPIO_DDR2_P6=1u; \
                                            bFM_GPIO_PFR2_P6=0u; }while(0u)

/*---- Fast GPIO bit P27 ----*/
#define FGPIO1PIN_P27_GET               ( FM_FASTIO->FPDIR2_f.P7 )

#define FGPIO1PIN_P27_PUT(v)            ( FM_FASTIO->FPDOR2_f.P7=(v) )

#define FGPIO1PIN_P27_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P27_INITIN(v) \
                                                           : FGPIO1PIN_P27_INITOUT(v) )

#define FGPIO1PIN_P27_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PCR2_P7=(v).bPullup; \
                                            bFM_GPIO_DDR2_P7=0u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

#define FGPIO1PIN_P27_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            FM_FASTIO->FPDOR2_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P7=1u; \
                                            bFM_GPIO_DDR2_P7=1u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

/*---- Fast GPIO bit NP27 ----*/
#define FGPIO1PIN_NP27_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P7)) )

#define FGPIO1PIN_NP27_PUT(v)           ( FM_FASTIO->FPDOR2_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP27_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP27_INITIN(v) \
                                                           : FGPIO1PIN_NP27_INITOUT(v) )

#define FGPIO1PIN_NP27_INITIN(v)        do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            bFM_GPIO_PCR2_P7=(v).bPullup; \
                                            bFM_GPIO_DDR2_P7=0u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

#define FGPIO1PIN_NP27_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            FM_FASTIO->FPDOR2_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P7=1u; \
                                            bFM_GPIO_DDR2_P7=1u; \
                                            bFM_GPIO_PFR2_P7=0u; }while(0u)

/*---- Fast GPIO bit P28 ----*/
#define FGPIO1PIN_P28_GET               ( FM_FASTIO->FPDIR2_f.P8 )

#define FGPIO1PIN_P28_PUT(v)            ( FM_FASTIO->FPDOR2_f.P8=(v) )

#define FGPIO1PIN_P28_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P28_INITIN(v) \
                                                           : FGPIO1PIN_P28_INITOUT(v) )

#define FGPIO1PIN_P28_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P8=(v).bPullup; \
                                            bFM_GPIO_DDR2_P8=0u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

#define FGPIO1PIN_P28_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR2_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER2_f.P8=1u; \
                                            bFM_GPIO_DDR2_P8=1u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

/*---- Fast GPIO bit NP28 ----*/
#define FGPIO1PIN_NP28_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR2_f.P8)) )

#define FGPIO1PIN_NP28_PUT(v)           ( FM_FASTIO->FPDOR2_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP28_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP28_INITIN(v) \
                                                           : FGPIO1PIN_NP28_INITOUT(v) )

#define FGPIO1PIN_NP28_INITIN(v)        do{ \
                                            bFM_GPIO_PCR2_P8=(v).bPullup; \
                                            bFM_GPIO_DDR2_P8=0u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

#define FGPIO1PIN_NP28_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR2_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P8=1u; \
                                            bFM_GPIO_DDR2_P8=1u; \
                                            bFM_GPIO_PFR2_P8=0u; }while(0u)

/*---- Fast GPIO bit P30 ----*/
#define FGPIO1PIN_P30_GET               ( FM_FASTIO->FPDIR3_f.P0 )

#define FGPIO1PIN_P30_PUT(v)            ( FM_FASTIO->FPDOR3_f.P0=(v) )

#define FGPIO1PIN_P30_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P30_INITIN(v) \
                                                           : FGPIO1PIN_P30_INITOUT(v) )

#define FGPIO1PIN_P30_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P0=(v).bPullup; \
                                            bFM_GPIO_DDR3_P0=0u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

#define FGPIO1PIN_P30_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P0=1u; \
                                            bFM_GPIO_DDR3_P0=1u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

/*---- Fast GPIO bit NP30 ----*/
#define FGPIO1PIN_NP30_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P0)) )

#define FGPIO1PIN_NP30_PUT(v)           ( FM_FASTIO->FPDOR3_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP30_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP30_INITIN(v) \
                                                           : FGPIO1PIN_NP30_INITOUT(v) )

#define FGPIO1PIN_NP30_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P0=(v).bPullup; \
                                            bFM_GPIO_DDR3_P0=0u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

#define FGPIO1PIN_NP30_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P0=1u; \
                                            bFM_GPIO_DDR3_P0=1u; \
                                            bFM_GPIO_PFR3_P0=0u; }while(0u)

/*---- Fast GPIO bit P31 ----*/
#define FGPIO1PIN_P31_GET               ( FM_FASTIO->FPDIR3_f.P1 )

#define FGPIO1PIN_P31_PUT(v)            ( FM_FASTIO->FPDOR3_f.P1=(v) )

#define FGPIO1PIN_P31_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P31_INITIN(v) \
                                                           : FGPIO1PIN_P31_INITOUT(v) )

#define FGPIO1PIN_P31_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P1=(v).bPullup; \
                                            bFM_GPIO_DDR3_P1=0u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

#define FGPIO1PIN_P31_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P1=1u; \
                                            bFM_GPIO_DDR3_P1=1u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

/*---- Fast GPIO bit NP31 ----*/
#define FGPIO1PIN_NP31_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P1)) )

#define FGPIO1PIN_NP31_PUT(v)           ( FM_FASTIO->FPDOR3_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP31_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP31_INITIN(v) \
                                                           : FGPIO1PIN_NP31_INITOUT(v) )

#define FGPIO1PIN_NP31_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P1=(v).bPullup; \
                                            bFM_GPIO_DDR3_P1=0u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

#define FGPIO1PIN_NP31_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P1=1u; \
                                            bFM_GPIO_DDR3_P1=1u; \
                                            bFM_GPIO_PFR3_P1=0u; }while(0u)

/*---- Fast GPIO bit P32 ----*/
#define FGPIO1PIN_P32_GET               ( FM_FASTIO->FPDIR3_f.P2 )

#define FGPIO1PIN_P32_PUT(v)            ( FM_FASTIO->FPDOR3_f.P2=(v) )

#define FGPIO1PIN_P32_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P32_INITIN(v) \
                                                           : FGPIO1PIN_P32_INITOUT(v) )

#define FGPIO1PIN_P32_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P2=(v).bPullup; \
                                            bFM_GPIO_DDR3_P2=0u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

#define FGPIO1PIN_P32_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P2=1u; \
                                            bFM_GPIO_DDR3_P2=1u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

/*---- Fast GPIO bit NP32 ----*/
#define FGPIO1PIN_NP32_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P2)) )

#define FGPIO1PIN_NP32_PUT(v)           ( FM_FASTIO->FPDOR3_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP32_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP32_INITIN(v) \
                                                           : FGPIO1PIN_NP32_INITOUT(v) )

#define FGPIO1PIN_NP32_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P2=(v).bPullup; \
                                            bFM_GPIO_DDR3_P2=0u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

#define FGPIO1PIN_NP32_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P2=1u; \
                                            bFM_GPIO_DDR3_P2=1u; \
                                            bFM_GPIO_PFR3_P2=0u; }while(0u)

/*---- Fast GPIO bit P33 ----*/
#define FGPIO1PIN_P33_GET               ( FM_FASTIO->FPDIR3_f.P3 )

#define FGPIO1PIN_P33_PUT(v)            ( FM_FASTIO->FPDOR3_f.P3=(v) )

#define FGPIO1PIN_P33_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P33_INITIN(v) \
                                                           : FGPIO1PIN_P33_INITOUT(v) )

#define FGPIO1PIN_P33_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P3=(v).bPullup; \
                                            bFM_GPIO_DDR3_P3=0u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

#define FGPIO1PIN_P33_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P3=1u; \
                                            bFM_GPIO_DDR3_P3=1u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

/*---- Fast GPIO bit NP33 ----*/
#define FGPIO1PIN_NP33_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P3)) )

#define FGPIO1PIN_NP33_PUT(v)           ( FM_FASTIO->FPDOR3_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP33_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP33_INITIN(v) \
                                                           : FGPIO1PIN_NP33_INITOUT(v) )

#define FGPIO1PIN_NP33_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P3=(v).bPullup; \
                                            bFM_GPIO_DDR3_P3=0u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

#define FGPIO1PIN_NP33_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P3=1u; \
                                            bFM_GPIO_DDR3_P3=1u; \
                                            bFM_GPIO_PFR3_P3=0u; }while(0u)

/*---- Fast GPIO bit P34 ----*/
#define FGPIO1PIN_P34_GET               ( FM_FASTIO->FPDIR3_f.P4 )

#define FGPIO1PIN_P34_PUT(v)            ( FM_FASTIO->FPDOR3_f.P4=(v) )

#define FGPIO1PIN_P34_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P34_INITIN(v) \
                                                           : FGPIO1PIN_P34_INITOUT(v) )

#define FGPIO1PIN_P34_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P4=(v).bPullup; \
                                            bFM_GPIO_DDR3_P4=0u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

#define FGPIO1PIN_P34_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P4=1u; \
                                            bFM_GPIO_DDR3_P4=1u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

/*---- Fast GPIO bit NP34 ----*/
#define FGPIO1PIN_NP34_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P4)) )

#define FGPIO1PIN_NP34_PUT(v)           ( FM_FASTIO->FPDOR3_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP34_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP34_INITIN(v) \
                                                           : FGPIO1PIN_NP34_INITOUT(v) )

#define FGPIO1PIN_NP34_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P4=(v).bPullup; \
                                            bFM_GPIO_DDR3_P4=0u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

#define FGPIO1PIN_NP34_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P4=1u; \
                                            bFM_GPIO_DDR3_P4=1u; \
                                            bFM_GPIO_PFR3_P4=0u; }while(0u)

/*---- Fast GPIO bit P35 ----*/
#define FGPIO1PIN_P35_GET               ( FM_FASTIO->FPDIR3_f.P5 )

#define FGPIO1PIN_P35_PUT(v)            ( FM_FASTIO->FPDOR3_f.P5=(v) )

#define FGPIO1PIN_P35_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P35_INITIN(v) \
                                                           : FGPIO1PIN_P35_INITOUT(v) )

#define FGPIO1PIN_P35_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P5=(v).bPullup; \
                                            bFM_GPIO_DDR3_P5=0u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

#define FGPIO1PIN_P35_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P5=1u; \
                                            bFM_GPIO_DDR3_P5=1u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

/*---- Fast GPIO bit NP35 ----*/
#define FGPIO1PIN_NP35_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P5)) )

#define FGPIO1PIN_NP35_PUT(v)           ( FM_FASTIO->FPDOR3_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP35_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP35_INITIN(v) \
                                                           : FGPIO1PIN_NP35_INITOUT(v) )

#define FGPIO1PIN_NP35_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P5=(v).bPullup; \
                                            bFM_GPIO_DDR3_P5=0u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

#define FGPIO1PIN_NP35_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P5=1u; \
                                            bFM_GPIO_DDR3_P5=1u; \
                                            bFM_GPIO_PFR3_P5=0u; }while(0u)

/*---- Fast GPIO bit P36 ----*/
#define FGPIO1PIN_P36_GET               ( FM_FASTIO->FPDIR3_f.P6 )

#define FGPIO1PIN_P36_PUT(v)            ( FM_FASTIO->FPDOR3_f.P6=(v) )

#define FGPIO1PIN_P36_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P36_INITIN(v) \
                                                           : FGPIO1PIN_P36_INITOUT(v) )

#define FGPIO1PIN_P36_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P6=(v).bPullup; \
                                            bFM_GPIO_DDR3_P6=0u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

#define FGPIO1PIN_P36_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P6=1u; \
                                            bFM_GPIO_DDR3_P6=1u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

/*---- Fast GPIO bit NP36 ----*/
#define FGPIO1PIN_NP36_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P6)) )

#define FGPIO1PIN_NP36_PUT(v)           ( FM_FASTIO->FPDOR3_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP36_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP36_INITIN(v) \
                                                           : FGPIO1PIN_NP36_INITOUT(v) )

#define FGPIO1PIN_NP36_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P6=(v).bPullup; \
                                            bFM_GPIO_DDR3_P6=0u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

#define FGPIO1PIN_NP36_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P6=1u; \
                                            bFM_GPIO_DDR3_P6=1u; \
                                            bFM_GPIO_PFR3_P6=0u; }while(0u)

/*---- Fast GPIO bit P37 ----*/
#define FGPIO1PIN_P37_GET               ( FM_FASTIO->FPDIR3_f.P7 )

#define FGPIO1PIN_P37_PUT(v)            ( FM_FASTIO->FPDOR3_f.P7=(v) )

#define FGPIO1PIN_P37_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P37_INITIN(v) \
                                                           : FGPIO1PIN_P37_INITOUT(v) )

#define FGPIO1PIN_P37_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P7=(v).bPullup; \
                                            bFM_GPIO_DDR3_P7=0u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

#define FGPIO1PIN_P37_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P7=1u; \
                                            bFM_GPIO_DDR3_P7=1u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

/*---- Fast GPIO bit NP37 ----*/
#define FGPIO1PIN_NP37_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P7)) )

#define FGPIO1PIN_NP37_PUT(v)           ( FM_FASTIO->FPDOR3_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP37_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP37_INITIN(v) \
                                                           : FGPIO1PIN_NP37_INITOUT(v) )

#define FGPIO1PIN_NP37_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P7=(v).bPullup; \
                                            bFM_GPIO_DDR3_P7=0u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

#define FGPIO1PIN_NP37_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P7=1u; \
                                            bFM_GPIO_DDR3_P7=1u; \
                                            bFM_GPIO_PFR3_P7=0u; }while(0u)

/*---- Fast GPIO bit P38 ----*/
#define FGPIO1PIN_P38_GET               ( FM_FASTIO->FPDIR3_f.P8 )

#define FGPIO1PIN_P38_PUT(v)            ( FM_FASTIO->FPDOR3_f.P8=(v) )

#define FGPIO1PIN_P38_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P38_INITIN(v) \
                                                           : FGPIO1PIN_P38_INITOUT(v) )

#define FGPIO1PIN_P38_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P8=(v).bPullup; \
                                            bFM_GPIO_DDR3_P8=0u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

#define FGPIO1PIN_P38_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P8=1u; \
                                            bFM_GPIO_DDR3_P8=1u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

/*---- Fast GPIO bit NP38 ----*/
#define FGPIO1PIN_NP38_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P8)) )

#define FGPIO1PIN_NP38_PUT(v)           ( FM_FASTIO->FPDOR3_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP38_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP38_INITIN(v) \
                                                           : FGPIO1PIN_NP38_INITOUT(v) )

#define FGPIO1PIN_NP38_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P8=(v).bPullup; \
                                            bFM_GPIO_DDR3_P8=0u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

#define FGPIO1PIN_NP38_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P8=1u; \
                                            bFM_GPIO_DDR3_P8=1u; \
                                            bFM_GPIO_PFR3_P8=0u; }while(0u)

/*---- Fast GPIO bit P39 ----*/
#define FGPIO1PIN_P39_GET               ( FM_FASTIO->FPDIR3_f.P9 )

#define FGPIO1PIN_P39_PUT(v)            ( FM_FASTIO->FPDOR3_f.P9=(v) )

#define FGPIO1PIN_P39_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P39_INITIN(v) \
                                                           : FGPIO1PIN_P39_INITOUT(v) )

#define FGPIO1PIN_P39_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_P9=(v).bPullup; \
                                            bFM_GPIO_DDR3_P9=0u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

#define FGPIO1PIN_P39_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.P9=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.P9=1u; \
                                            bFM_GPIO_DDR3_P9=1u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

/*---- Fast GPIO bit NP39 ----*/
#define FGPIO1PIN_NP39_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.P9)) )

#define FGPIO1PIN_NP39_PUT(v)           ( FM_FASTIO->FPDOR3_f.P9=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP39_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP39_INITIN(v) \
                                                           : FGPIO1PIN_NP39_INITOUT(v) )

#define FGPIO1PIN_NP39_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_P9=(v).bPullup; \
                                            bFM_GPIO_DDR3_P9=0u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

#define FGPIO1PIN_NP39_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.P9=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.P9=1u; \
                                            bFM_GPIO_DDR3_P9=1u; \
                                            bFM_GPIO_PFR3_P9=0u; }while(0u)

/*---- Fast GPIO bit P3A ----*/
#define FGPIO1PIN_P3A_GET               ( FM_FASTIO->FPDIR3_f.PA )

#define FGPIO1PIN_P3A_PUT(v)            ( FM_FASTIO->FPDOR3_f.PA=(v) )

#define FGPIO1PIN_P3A_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3A_INITIN(v) \
                                                           : FGPIO1PIN_P3A_INITOUT(v) )

#define FGPIO1PIN_P3A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PA=(v).bPullup; \
                                            bFM_GPIO_DDR3_PA=0u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

#define FGPIO1PIN_P3A_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PA=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PA=1u; \
                                            bFM_GPIO_DDR3_PA=1u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

/*---- Fast GPIO bit NP3A ----*/
#define FGPIO1PIN_NP3A_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PA)) )

#define FGPIO1PIN_NP3A_PUT(v)           ( FM_FASTIO->FPDOR3_f.PA=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3A_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3A_INITIN(v) \
                                                           : FGPIO1PIN_NP3A_INITOUT(v) )

#define FGPIO1PIN_NP3A_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PA=(v).bPullup; \
                                            bFM_GPIO_DDR3_PA=0u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

#define FGPIO1PIN_NP3A_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PA=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PA=1u; \
                                            bFM_GPIO_DDR3_PA=1u; \
                                            bFM_GPIO_PFR3_PA=0u; }while(0u)

/*---- Fast GPIO bit P3B ----*/
#define FGPIO1PIN_P3B_GET               ( FM_FASTIO->FPDIR3_f.PB )

#define FGPIO1PIN_P3B_PUT(v)            ( FM_FASTIO->FPDOR3_f.PB=(v) )

#define FGPIO1PIN_P3B_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3B_INITIN(v) \
                                                           : FGPIO1PIN_P3B_INITOUT(v) )

#define FGPIO1PIN_P3B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PB=(v).bPullup; \
                                            bFM_GPIO_DDR3_PB=0u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

#define FGPIO1PIN_P3B_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PB=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PB=1u; \
                                            bFM_GPIO_DDR3_PB=1u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

/*---- Fast GPIO bit NP3B ----*/
#define FGPIO1PIN_NP3B_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PB)) )

#define FGPIO1PIN_NP3B_PUT(v)           ( FM_FASTIO->FPDOR3_f.PB=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3B_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3B_INITIN(v) \
                                                           : FGPIO1PIN_NP3B_INITOUT(v) )

#define FGPIO1PIN_NP3B_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PB=(v).bPullup; \
                                            bFM_GPIO_DDR3_PB=0u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

#define FGPIO1PIN_NP3B_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PB=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PB=1u; \
                                            bFM_GPIO_DDR3_PB=1u; \
                                            bFM_GPIO_PFR3_PB=0u; }while(0u)

/*---- Fast GPIO bit P3C ----*/
#define FGPIO1PIN_P3C_GET               ( FM_FASTIO->FPDIR3_f.PC )

#define FGPIO1PIN_P3C_PUT(v)            ( FM_FASTIO->FPDOR3_f.PC=(v) )

#define FGPIO1PIN_P3C_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3C_INITIN(v) \
                                                           : FGPIO1PIN_P3C_INITOUT(v) )

#define FGPIO1PIN_P3C_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PC=(v).bPullup; \
                                            bFM_GPIO_DDR3_PC=0u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

#define FGPIO1PIN_P3C_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PC=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PC=1u; \
                                            bFM_GPIO_DDR3_PC=1u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

/*---- Fast GPIO bit NP3C ----*/
#define FGPIO1PIN_NP3C_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PC)) )

#define FGPIO1PIN_NP3C_PUT(v)           ( FM_FASTIO->FPDOR3_f.PC=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3C_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3C_INITIN(v) \
                                                           : FGPIO1PIN_NP3C_INITOUT(v) )

#define FGPIO1PIN_NP3C_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PC=(v).bPullup; \
                                            bFM_GPIO_DDR3_PC=0u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

#define FGPIO1PIN_NP3C_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PC=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PC=1u; \
                                            bFM_GPIO_DDR3_PC=1u; \
                                            bFM_GPIO_PFR3_PC=0u; }while(0u)

/*---- Fast GPIO bit P3D ----*/
#define FGPIO1PIN_P3D_GET               ( FM_FASTIO->FPDIR3_f.PD )

#define FGPIO1PIN_P3D_PUT(v)            ( FM_FASTIO->FPDOR3_f.PD=(v) )

#define FGPIO1PIN_P3D_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3D_INITIN(v) \
                                                           : FGPIO1PIN_P3D_INITOUT(v) )

#define FGPIO1PIN_P3D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PD=(v).bPullup; \
                                            bFM_GPIO_DDR3_PD=0u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

#define FGPIO1PIN_P3D_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PD=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PD=1u; \
                                            bFM_GPIO_DDR3_PD=1u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

/*---- Fast GPIO bit NP3D ----*/
#define FGPIO1PIN_NP3D_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PD)) )

#define FGPIO1PIN_NP3D_PUT(v)           ( FM_FASTIO->FPDOR3_f.PD=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3D_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3D_INITIN(v) \
                                                           : FGPIO1PIN_NP3D_INITOUT(v) )

#define FGPIO1PIN_NP3D_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PD=(v).bPullup; \
                                            bFM_GPIO_DDR3_PD=0u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

#define FGPIO1PIN_NP3D_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PD=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PD=1u; \
                                            bFM_GPIO_DDR3_PD=1u; \
                                            bFM_GPIO_PFR3_PD=0u; }while(0u)

/*---- Fast GPIO bit P3E ----*/
#define FGPIO1PIN_P3E_GET               ( FM_FASTIO->FPDIR3_f.PE )

#define FGPIO1PIN_P3E_PUT(v)            ( FM_FASTIO->FPDOR3_f.PE=(v) )

#define FGPIO1PIN_P3E_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3E_INITIN(v) \
                                                           : FGPIO1PIN_P3E_INITOUT(v) )

#define FGPIO1PIN_P3E_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PE=(v).bPullup; \
                                            bFM_GPIO_DDR3_PE=0u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

#define FGPIO1PIN_P3E_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PE=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PE=1u; \
                                            bFM_GPIO_DDR3_PE=1u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

/*---- Fast GPIO bit NP3E ----*/
#define FGPIO1PIN_NP3E_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PE)) )

#define FGPIO1PIN_NP3E_PUT(v)           ( FM_FASTIO->FPDOR3_f.PE=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3E_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3E_INITIN(v) \
                                                           : FGPIO1PIN_NP3E_INITOUT(v) )

#define FGPIO1PIN_NP3E_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PE=(v).bPullup; \
                                            bFM_GPIO_DDR3_PE=0u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

#define FGPIO1PIN_NP3E_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PE=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PE=1u; \
                                            bFM_GPIO_DDR3_PE=1u; \
                                            bFM_GPIO_PFR3_PE=0u; }while(0u)

/*---- Fast GPIO bit P3F ----*/
#define FGPIO1PIN_P3F_GET               ( FM_FASTIO->FPDIR3_f.PF )

#define FGPIO1PIN_P3F_PUT(v)            ( FM_FASTIO->FPDOR3_f.PF=(v) )

#define FGPIO1PIN_P3F_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P3F_INITIN(v) \
                                                           : FGPIO1PIN_P3F_INITOUT(v) )

#define FGPIO1PIN_P3F_INITIN(v)         do{ \
                                            bFM_GPIO_PCR3_PF=(v).bPullup; \
                                            bFM_GPIO_DDR3_PF=0u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

#define FGPIO1PIN_P3F_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR3_f.PF=(v).bInitVal; \
                                            FM_GPIO->FPOER3_f.PF=1u; \
                                            bFM_GPIO_DDR3_PF=1u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

/*---- Fast GPIO bit NP3F ----*/
#define FGPIO1PIN_NP3F_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR3_f.PF)) )

#define FGPIO1PIN_NP3F_PUT(v)           ( FM_FASTIO->FPDOR3_f.PF=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP3F_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP3F_INITIN(v) \
                                                           : FGPIO1PIN_NP3F_INITOUT(v) )

#define FGPIO1PIN_NP3F_INITIN(v)        do{ \
                                            bFM_GPIO_PCR3_PF=(v).bPullup; \
                                            bFM_GPIO_DDR3_PF=0u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

#define FGPIO1PIN_NP3F_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR3_f.PF=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER3_f.PF=1u; \
                                            bFM_GPIO_DDR3_PF=1u; \
                                            bFM_GPIO_PFR3_PF=0u; }while(0u)

/*---- Fast GPIO bit P40 ----*/
#define FGPIO1PIN_P40_GET               ( FM_FASTIO->FPDIR4_f.P0 )

#define FGPIO1PIN_P40_PUT(v)            ( FM_FASTIO->FPDOR4_f.P0=(v) )

#define FGPIO1PIN_P40_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P40_INITIN(v) \
                                                           : FGPIO1PIN_P40_INITOUT(v) )

#define FGPIO1PIN_P40_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P0=(v).bPullup; \
                                            bFM_GPIO_DDR4_P0=0u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

#define FGPIO1PIN_P40_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P0=1u; \
                                            bFM_GPIO_DDR4_P0=1u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

/*---- Fast GPIO bit NP40 ----*/
#define FGPIO1PIN_NP40_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P0)) )

#define FGPIO1PIN_NP40_PUT(v)           ( FM_FASTIO->FPDOR4_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP40_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP40_INITIN(v) \
                                                           : FGPIO1PIN_NP40_INITOUT(v) )

#define FGPIO1PIN_NP40_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P0=(v).bPullup; \
                                            bFM_GPIO_DDR4_P0=0u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

#define FGPIO1PIN_NP40_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P0=1u; \
                                            bFM_GPIO_DDR4_P0=1u; \
                                            bFM_GPIO_PFR4_P0=0u; }while(0u)

/*---- Fast GPIO bit P41 ----*/
#define FGPIO1PIN_P41_GET               ( FM_FASTIO->FPDIR4_f.P1 )

#define FGPIO1PIN_P41_PUT(v)            ( FM_FASTIO->FPDOR4_f.P1=(v) )

#define FGPIO1PIN_P41_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P41_INITIN(v) \
                                                           : FGPIO1PIN_P41_INITOUT(v) )

#define FGPIO1PIN_P41_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P1=(v).bPullup; \
                                            bFM_GPIO_DDR4_P1=0u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

#define FGPIO1PIN_P41_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P1=1u; \
                                            bFM_GPIO_DDR4_P1=1u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

/*---- Fast GPIO bit NP41 ----*/
#define FGPIO1PIN_NP41_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P1)) )

#define FGPIO1PIN_NP41_PUT(v)           ( FM_FASTIO->FPDOR4_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP41_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP41_INITIN(v) \
                                                           : FGPIO1PIN_NP41_INITOUT(v) )

#define FGPIO1PIN_NP41_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P1=(v).bPullup; \
                                            bFM_GPIO_DDR4_P1=0u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

#define FGPIO1PIN_NP41_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P1=1u; \
                                            bFM_GPIO_DDR4_P1=1u; \
                                            bFM_GPIO_PFR4_P1=0u; }while(0u)

/*---- Fast GPIO bit P42 ----*/
#define FGPIO1PIN_P42_GET               ( FM_FASTIO->FPDIR4_f.P2 )

#define FGPIO1PIN_P42_PUT(v)            ( FM_FASTIO->FPDOR4_f.P2=(v) )

#define FGPIO1PIN_P42_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P42_INITIN(v) \
                                                           : FGPIO1PIN_P42_INITOUT(v) )

#define FGPIO1PIN_P42_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P2=(v).bPullup; \
                                            bFM_GPIO_DDR4_P2=0u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

#define FGPIO1PIN_P42_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P2=1u; \
                                            bFM_GPIO_DDR4_P2=1u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

/*---- Fast GPIO bit NP42 ----*/
#define FGPIO1PIN_NP42_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P2)) )

#define FGPIO1PIN_NP42_PUT(v)           ( FM_FASTIO->FPDOR4_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP42_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP42_INITIN(v) \
                                                           : FGPIO1PIN_NP42_INITOUT(v) )

#define FGPIO1PIN_NP42_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P2=(v).bPullup; \
                                            bFM_GPIO_DDR4_P2=0u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

#define FGPIO1PIN_NP42_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P2=1u; \
                                            bFM_GPIO_DDR4_P2=1u; \
                                            bFM_GPIO_PFR4_P2=0u; }while(0u)

/*---- Fast GPIO bit P43 ----*/
#define FGPIO1PIN_P43_GET               ( FM_FASTIO->FPDIR4_f.P3 )

#define FGPIO1PIN_P43_PUT(v)            ( FM_FASTIO->FPDOR4_f.P3=(v) )

#define FGPIO1PIN_P43_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P43_INITIN(v) \
                                                           : FGPIO1PIN_P43_INITOUT(v) )

#define FGPIO1PIN_P43_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P3=(v).bPullup; \
                                            bFM_GPIO_DDR4_P3=0u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

#define FGPIO1PIN_P43_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P3=1u; \
                                            bFM_GPIO_DDR4_P3=1u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

/*---- Fast GPIO bit NP43 ----*/
#define FGPIO1PIN_NP43_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P3)) )

#define FGPIO1PIN_NP43_PUT(v)           ( FM_FASTIO->FPDOR4_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP43_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP43_INITIN(v) \
                                                           : FGPIO1PIN_NP43_INITOUT(v) )

#define FGPIO1PIN_NP43_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P3=(v).bPullup; \
                                            bFM_GPIO_DDR4_P3=0u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

#define FGPIO1PIN_NP43_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P3=1u; \
                                            bFM_GPIO_DDR4_P3=1u; \
                                            bFM_GPIO_PFR4_P3=0u; }while(0u)

/*---- Fast GPIO bit P44 ----*/
#define FGPIO1PIN_P44_GET               ( FM_FASTIO->FPDIR4_f.P4 )

#define FGPIO1PIN_P44_PUT(v)            ( FM_FASTIO->FPDOR4_f.P4=(v) )

#define FGPIO1PIN_P44_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P44_INITIN(v) \
                                                           : FGPIO1PIN_P44_INITOUT(v) )

#define FGPIO1PIN_P44_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P4=(v).bPullup; \
                                            bFM_GPIO_DDR4_P4=0u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

#define FGPIO1PIN_P44_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P4=1u; \
                                            bFM_GPIO_DDR4_P4=1u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

/*---- Fast GPIO bit NP44 ----*/
#define FGPIO1PIN_NP44_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P4)) )

#define FGPIO1PIN_NP44_PUT(v)           ( FM_FASTIO->FPDOR4_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP44_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP44_INITIN(v) \
                                                           : FGPIO1PIN_NP44_INITOUT(v) )

#define FGPIO1PIN_NP44_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P4=(v).bPullup; \
                                            bFM_GPIO_DDR4_P4=0u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

#define FGPIO1PIN_NP44_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P4=1u; \
                                            bFM_GPIO_DDR4_P4=1u; \
                                            bFM_GPIO_PFR4_P4=0u; }while(0u)

/*---- Fast GPIO bit P45 ----*/
#define FGPIO1PIN_P45_GET               ( FM_FASTIO->FPDIR4_f.P5 )

#define FGPIO1PIN_P45_PUT(v)            ( FM_FASTIO->FPDOR4_f.P5=(v) )

#define FGPIO1PIN_P45_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P45_INITIN(v) \
                                                           : FGPIO1PIN_P45_INITOUT(v) )

#define FGPIO1PIN_P45_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P5=(v).bPullup; \
                                            bFM_GPIO_DDR4_P5=0u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

#define FGPIO1PIN_P45_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P5=1u; \
                                            bFM_GPIO_DDR4_P5=1u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

/*---- Fast GPIO bit NP45 ----*/
#define FGPIO1PIN_NP45_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P5)) )

#define FGPIO1PIN_NP45_PUT(v)           ( FM_FASTIO->FPDOR4_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP45_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP45_INITIN(v) \
                                                           : FGPIO1PIN_NP45_INITOUT(v) )

#define FGPIO1PIN_NP45_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P5=(v).bPullup; \
                                            bFM_GPIO_DDR4_P5=0u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

#define FGPIO1PIN_NP45_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P5=1u; \
                                            bFM_GPIO_DDR4_P5=1u; \
                                            bFM_GPIO_PFR4_P5=0u; }while(0u)

/*---- Fast GPIO bit P4A ----*/
#define FGPIO1PIN_P4A_GET               ( FM_FASTIO->FPDIR4_f.PA )

#define FGPIO1PIN_P4A_PUT(v)            ( FM_FASTIO->FPDOR4_f.PA=(v) )

#define FGPIO1PIN_P4A_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P4A_INITIN(v) \
                                                           : FGPIO1PIN_P4A_INITOUT(v) )

#define FGPIO1PIN_P4A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PA=(v).bPullup; \
                                            bFM_GPIO_DDR4_PA=0u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

#define FGPIO1PIN_P4A_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.PA=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.PA=1u; \
                                            bFM_GPIO_DDR4_PA=1u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

/*---- Fast GPIO bit NP4A ----*/
#define FGPIO1PIN_NP4A_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.PA)) )

#define FGPIO1PIN_NP4A_PUT(v)           ( FM_FASTIO->FPDOR4_f.PA=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP4A_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP4A_INITIN(v) \
                                                           : FGPIO1PIN_NP4A_INITOUT(v) )

#define FGPIO1PIN_NP4A_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_PA=(v).bPullup; \
                                            bFM_GPIO_DDR4_PA=0u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

#define FGPIO1PIN_NP4A_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.PA=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.PA=1u; \
                                            bFM_GPIO_DDR4_PA=1u; \
                                            bFM_GPIO_PFR4_PA=0u; }while(0u)

/*---- Fast GPIO bit P4B ----*/
#define FGPIO1PIN_P4B_GET               ( FM_FASTIO->FPDIR4_f.PB )

#define FGPIO1PIN_P4B_PUT(v)            ( FM_FASTIO->FPDOR4_f.PB=(v) )

#define FGPIO1PIN_P4B_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P4B_INITIN(v) \
                                                           : FGPIO1PIN_P4B_INITOUT(v) )

#define FGPIO1PIN_P4B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PB=(v).bPullup; \
                                            bFM_GPIO_DDR4_PB=0u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

#define FGPIO1PIN_P4B_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.PB=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.PB=1u; \
                                            bFM_GPIO_DDR4_PB=1u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

/*---- Fast GPIO bit NP4B ----*/
#define FGPIO1PIN_NP4B_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.PB)) )

#define FGPIO1PIN_NP4B_PUT(v)           ( FM_FASTIO->FPDOR4_f.PB=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP4B_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP4B_INITIN(v) \
                                                           : FGPIO1PIN_NP4B_INITOUT(v) )

#define FGPIO1PIN_NP4B_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_PB=(v).bPullup; \
                                            bFM_GPIO_DDR4_PB=0u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

#define FGPIO1PIN_NP4B_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.PB=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.PB=1u; \
                                            bFM_GPIO_DDR4_PB=1u; \
                                            bFM_GPIO_PFR4_PB=0u; }while(0u)

/*---- Fast GPIO bit P4C ----*/
#define FGPIO1PIN_P4C_GET               ( FM_FASTIO->FPDIR4_f.PC )

#define FGPIO1PIN_P4C_PUT(v)            ( FM_FASTIO->FPDOR4_f.PC=(v) )

#define FGPIO1PIN_P4C_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P4C_INITIN(v) \
                                                           : FGPIO1PIN_P4C_INITOUT(v) )

#define FGPIO1PIN_P4C_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PC=(v).bPullup; \
                                            bFM_GPIO_DDR4_PC=0u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

#define FGPIO1PIN_P4C_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.PC=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.PC=1u; \
                                            bFM_GPIO_DDR4_PC=1u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

/*---- Fast GPIO bit NP4C ----*/
#define FGPIO1PIN_NP4C_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.PC)) )

#define FGPIO1PIN_NP4C_PUT(v)           ( FM_FASTIO->FPDOR4_f.PC=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP4C_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP4C_INITIN(v) \
                                                           : FGPIO1PIN_NP4C_INITOUT(v) )

#define FGPIO1PIN_NP4C_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_PC=(v).bPullup; \
                                            bFM_GPIO_DDR4_PC=0u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

#define FGPIO1PIN_NP4C_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.PC=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.PC=1u; \
                                            bFM_GPIO_DDR4_PC=1u; \
                                            bFM_GPIO_PFR4_PC=0u; }while(0u)

/*---- Fast GPIO bit P4D ----*/
#define FGPIO1PIN_P4D_GET               ( FM_FASTIO->FPDIR4_f.PD )

#define FGPIO1PIN_P4D_PUT(v)            ( FM_FASTIO->FPDOR4_f.PD=(v) )

#define FGPIO1PIN_P4D_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P4D_INITIN(v) \
                                                           : FGPIO1PIN_P4D_INITOUT(v) )

#define FGPIO1PIN_P4D_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_PD=(v).bPullup; \
                                            bFM_GPIO_DDR4_PD=0u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

#define FGPIO1PIN_P4D_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.PD=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.PD=1u; \
                                            bFM_GPIO_DDR4_PD=1u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

/*---- Fast GPIO bit NP4D ----*/
#define FGPIO1PIN_NP4D_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.PD)) )

#define FGPIO1PIN_NP4D_PUT(v)           ( FM_FASTIO->FPDOR4_f.PD=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP4D_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP4D_INITIN(v) \
                                                           : FGPIO1PIN_NP4D_INITOUT(v) )

#define FGPIO1PIN_NP4D_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_PD=(v).bPullup; \
                                            bFM_GPIO_DDR4_PD=0u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

#define FGPIO1PIN_NP4D_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.PD=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.PD=1u; \
                                            bFM_GPIO_DDR4_PD=1u; \
                                            bFM_GPIO_PFR4_PD=0u; }while(0u)

/*---- Fast GPIO bit P50 ----*/
#define FGPIO1PIN_P50_GET               ( FM_FASTIO->FPDIR5_f.P0 )

#define FGPIO1PIN_P50_PUT(v)            ( FM_FASTIO->FPDOR5_f.P0=(v) )

#define FGPIO1PIN_P50_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P50_INITIN(v) \
                                                           : FGPIO1PIN_P50_INITOUT(v) )

#define FGPIO1PIN_P50_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P0=(v).bPullup; \
                                            bFM_GPIO_DDR5_P0=0u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

#define FGPIO1PIN_P50_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P0=1u; \
                                            bFM_GPIO_DDR5_P0=1u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

/*---- Fast GPIO bit NP50 ----*/
#define FGPIO1PIN_NP50_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P0)) )

#define FGPIO1PIN_NP50_PUT(v)           ( FM_FASTIO->FPDOR5_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP50_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP50_INITIN(v) \
                                                           : FGPIO1PIN_NP50_INITOUT(v) )

#define FGPIO1PIN_NP50_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P0=(v).bPullup; \
                                            bFM_GPIO_DDR5_P0=0u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

#define FGPIO1PIN_NP50_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P0=1u; \
                                            bFM_GPIO_DDR5_P0=1u; \
                                            bFM_GPIO_PFR5_P0=0u; }while(0u)

/*---- Fast GPIO bit P51 ----*/
#define FGPIO1PIN_P51_GET               ( FM_FASTIO->FPDIR5_f.P1 )

#define FGPIO1PIN_P51_PUT(v)            ( FM_FASTIO->FPDOR5_f.P1=(v) )

#define FGPIO1PIN_P51_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P51_INITIN(v) \
                                                           : FGPIO1PIN_P51_INITOUT(v) )

#define FGPIO1PIN_P51_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P1=(v).bPullup; \
                                            bFM_GPIO_DDR5_P1=0u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

#define FGPIO1PIN_P51_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P1=1u; \
                                            bFM_GPIO_DDR5_P1=1u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

/*---- Fast GPIO bit NP51 ----*/
#define FGPIO1PIN_NP51_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P1)) )

#define FGPIO1PIN_NP51_PUT(v)           ( FM_FASTIO->FPDOR5_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP51_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP51_INITIN(v) \
                                                           : FGPIO1PIN_NP51_INITOUT(v) )

#define FGPIO1PIN_NP51_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P1=(v).bPullup; \
                                            bFM_GPIO_DDR5_P1=0u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

#define FGPIO1PIN_NP51_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P1=1u; \
                                            bFM_GPIO_DDR5_P1=1u; \
                                            bFM_GPIO_PFR5_P1=0u; }while(0u)

/*---- Fast GPIO bit P52 ----*/
#define FGPIO1PIN_P52_GET               ( FM_FASTIO->FPDIR5_f.P2 )

#define FGPIO1PIN_P52_PUT(v)            ( FM_FASTIO->FPDOR5_f.P2=(v) )

#define FGPIO1PIN_P52_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P52_INITIN(v) \
                                                           : FGPIO1PIN_P52_INITOUT(v) )

#define FGPIO1PIN_P52_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P2=(v).bPullup; \
                                            bFM_GPIO_DDR5_P2=0u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

#define FGPIO1PIN_P52_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P2=1u; \
                                            bFM_GPIO_DDR5_P2=1u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

/*---- Fast GPIO bit NP52 ----*/
#define FGPIO1PIN_NP52_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P2)) )

#define FGPIO1PIN_NP52_PUT(v)           ( FM_FASTIO->FPDOR5_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP52_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP52_INITIN(v) \
                                                           : FGPIO1PIN_NP52_INITOUT(v) )

#define FGPIO1PIN_NP52_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P2=(v).bPullup; \
                                            bFM_GPIO_DDR5_P2=0u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

#define FGPIO1PIN_NP52_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P2=1u; \
                                            bFM_GPIO_DDR5_P2=1u; \
                                            bFM_GPIO_PFR5_P2=0u; }while(0u)

/*---- Fast GPIO bit P53 ----*/
#define FGPIO1PIN_P53_GET               ( FM_FASTIO->FPDIR5_f.P3 )

#define FGPIO1PIN_P53_PUT(v)            ( FM_FASTIO->FPDOR5_f.P3=(v) )

#define FGPIO1PIN_P53_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P53_INITIN(v) \
                                                           : FGPIO1PIN_P53_INITOUT(v) )

#define FGPIO1PIN_P53_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P3=(v).bPullup; \
                                            bFM_GPIO_DDR5_P3=0u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

#define FGPIO1PIN_P53_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P3=1u; \
                                            bFM_GPIO_DDR5_P3=1u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

/*---- Fast GPIO bit NP53 ----*/
#define FGPIO1PIN_NP53_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P3)) )

#define FGPIO1PIN_NP53_PUT(v)           ( FM_FASTIO->FPDOR5_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP53_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP53_INITIN(v) \
                                                           : FGPIO1PIN_NP53_INITOUT(v) )

#define FGPIO1PIN_NP53_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P3=(v).bPullup; \
                                            bFM_GPIO_DDR5_P3=0u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

#define FGPIO1PIN_NP53_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P3=1u; \
                                            bFM_GPIO_DDR5_P3=1u; \
                                            bFM_GPIO_PFR5_P3=0u; }while(0u)

/*---- Fast GPIO bit P54 ----*/
#define FGPIO1PIN_P54_GET               ( FM_FASTIO->FPDIR5_f.P4 )

#define FGPIO1PIN_P54_PUT(v)            ( FM_FASTIO->FPDOR5_f.P4=(v) )

#define FGPIO1PIN_P54_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P54_INITIN(v) \
                                                           : FGPIO1PIN_P54_INITOUT(v) )

#define FGPIO1PIN_P54_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P4=(v).bPullup; \
                                            bFM_GPIO_DDR5_P4=0u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

#define FGPIO1PIN_P54_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P4=1u; \
                                            bFM_GPIO_DDR5_P4=1u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

/*---- Fast GPIO bit NP54 ----*/
#define FGPIO1PIN_NP54_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P4)) )

#define FGPIO1PIN_NP54_PUT(v)           ( FM_FASTIO->FPDOR5_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP54_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP54_INITIN(v) \
                                                           : FGPIO1PIN_NP54_INITOUT(v) )

#define FGPIO1PIN_NP54_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P4=(v).bPullup; \
                                            bFM_GPIO_DDR5_P4=0u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

#define FGPIO1PIN_NP54_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P4=1u; \
                                            bFM_GPIO_DDR5_P4=1u; \
                                            bFM_GPIO_PFR5_P4=0u; }while(0u)

/*---- Fast GPIO bit P55 ----*/
#define FGPIO1PIN_P55_GET               ( FM_FASTIO->FPDIR5_f.P5 )

#define FGPIO1PIN_P55_PUT(v)            ( FM_FASTIO->FPDOR5_f.P5=(v) )

#define FGPIO1PIN_P55_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P55_INITIN(v) \
                                                           : FGPIO1PIN_P55_INITOUT(v) )

#define FGPIO1PIN_P55_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P5=(v).bPullup; \
                                            bFM_GPIO_DDR5_P5=0u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

#define FGPIO1PIN_P55_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P5=1u; \
                                            bFM_GPIO_DDR5_P5=1u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

/*---- Fast GPIO bit NP55 ----*/
#define FGPIO1PIN_NP55_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P5)) )

#define FGPIO1PIN_NP55_PUT(v)           ( FM_FASTIO->FPDOR5_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP55_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP55_INITIN(v) \
                                                           : FGPIO1PIN_NP55_INITOUT(v) )

#define FGPIO1PIN_NP55_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P5=(v).bPullup; \
                                            bFM_GPIO_DDR5_P5=0u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

#define FGPIO1PIN_NP55_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P5=1u; \
                                            bFM_GPIO_DDR5_P5=1u; \
                                            bFM_GPIO_PFR5_P5=0u; }while(0u)

/*---- Fast GPIO bit P56 ----*/
#define FGPIO1PIN_P56_GET               ( FM_FASTIO->FPDIR5_f.P6 )

#define FGPIO1PIN_P56_PUT(v)            ( FM_FASTIO->FPDOR5_f.P6=(v) )

#define FGPIO1PIN_P56_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P56_INITIN(v) \
                                                           : FGPIO1PIN_P56_INITOUT(v) )

#define FGPIO1PIN_P56_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P6=(v).bPullup; \
                                            bFM_GPIO_DDR5_P6=0u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

#define FGPIO1PIN_P56_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P6=1u; \
                                            bFM_GPIO_DDR5_P6=1u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

/*---- Fast GPIO bit NP56 ----*/
#define FGPIO1PIN_NP56_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P6)) )

#define FGPIO1PIN_NP56_PUT(v)           ( FM_FASTIO->FPDOR5_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP56_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP56_INITIN(v) \
                                                           : FGPIO1PIN_NP56_INITOUT(v) )

#define FGPIO1PIN_NP56_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P6=(v).bPullup; \
                                            bFM_GPIO_DDR5_P6=0u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

#define FGPIO1PIN_NP56_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P6=1u; \
                                            bFM_GPIO_DDR5_P6=1u; \
                                            bFM_GPIO_PFR5_P6=0u; }while(0u)

/*---- Fast GPIO bit P57 ----*/
#define FGPIO1PIN_P57_GET               ( FM_FASTIO->FPDIR5_f.P7 )

#define FGPIO1PIN_P57_PUT(v)            ( FM_FASTIO->FPDOR5_f.P7=(v) )

#define FGPIO1PIN_P57_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P57_INITIN(v) \
                                                           : FGPIO1PIN_P57_INITOUT(v) )

#define FGPIO1PIN_P57_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P7=(v).bPullup; \
                                            bFM_GPIO_DDR5_P7=0u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

#define FGPIO1PIN_P57_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P7=1u; \
                                            bFM_GPIO_DDR5_P7=1u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

/*---- Fast GPIO bit NP57 ----*/
#define FGPIO1PIN_NP57_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P7)) )

#define FGPIO1PIN_NP57_PUT(v)           ( FM_FASTIO->FPDOR5_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP57_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP57_INITIN(v) \
                                                           : FGPIO1PIN_NP57_INITOUT(v) )

#define FGPIO1PIN_NP57_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P7=(v).bPullup; \
                                            bFM_GPIO_DDR5_P7=0u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

#define FGPIO1PIN_NP57_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P7=1u; \
                                            bFM_GPIO_DDR5_P7=1u; \
                                            bFM_GPIO_PFR5_P7=0u; }while(0u)

/*---- Fast GPIO bit P58 ----*/
#define FGPIO1PIN_P58_GET               ( FM_FASTIO->FPDIR5_f.P8 )

#define FGPIO1PIN_P58_PUT(v)            ( FM_FASTIO->FPDOR5_f.P8=(v) )

#define FGPIO1PIN_P58_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P58_INITIN(v) \
                                                           : FGPIO1PIN_P58_INITOUT(v) )

#define FGPIO1PIN_P58_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P8=(v).bPullup; \
                                            bFM_GPIO_DDR5_P8=0u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

#define FGPIO1PIN_P58_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P8=1u; \
                                            bFM_GPIO_DDR5_P8=1u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

/*---- Fast GPIO bit NP58 ----*/
#define FGPIO1PIN_NP58_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P8)) )

#define FGPIO1PIN_NP58_PUT(v)           ( FM_FASTIO->FPDOR5_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP58_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP58_INITIN(v) \
                                                           : FGPIO1PIN_NP58_INITOUT(v) )

#define FGPIO1PIN_NP58_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P8=(v).bPullup; \
                                            bFM_GPIO_DDR5_P8=0u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

#define FGPIO1PIN_NP58_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P8=1u; \
                                            bFM_GPIO_DDR5_P8=1u; \
                                            bFM_GPIO_PFR5_P8=0u; }while(0u)

/*---- Fast GPIO bit P59 ----*/
#define FGPIO1PIN_P59_GET               ( FM_FASTIO->FPDIR5_f.P9 )

#define FGPIO1PIN_P59_PUT(v)            ( FM_FASTIO->FPDOR5_f.P9=(v) )

#define FGPIO1PIN_P59_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P59_INITIN(v) \
                                                           : FGPIO1PIN_P59_INITOUT(v) )

#define FGPIO1PIN_P59_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_P9=(v).bPullup; \
                                            bFM_GPIO_DDR5_P9=0u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

#define FGPIO1PIN_P59_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.P9=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.P9=1u; \
                                            bFM_GPIO_DDR5_P9=1u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

/*---- Fast GPIO bit NP59 ----*/
#define FGPIO1PIN_NP59_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.P9)) )

#define FGPIO1PIN_NP59_PUT(v)           ( FM_FASTIO->FPDOR5_f.P9=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP59_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP59_INITIN(v) \
                                                           : FGPIO1PIN_NP59_INITOUT(v) )

#define FGPIO1PIN_NP59_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_P9=(v).bPullup; \
                                            bFM_GPIO_DDR5_P9=0u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

#define FGPIO1PIN_NP59_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.P9=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.P9=1u; \
                                            bFM_GPIO_DDR5_P9=1u; \
                                            bFM_GPIO_PFR5_P9=0u; }while(0u)

/*---- Fast GPIO bit P5A ----*/
#define FGPIO1PIN_P5A_GET               ( FM_FASTIO->FPDIR5_f.PA )

#define FGPIO1PIN_P5A_PUT(v)            ( FM_FASTIO->FPDOR5_f.PA=(v) )

#define FGPIO1PIN_P5A_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P5A_INITIN(v) \
                                                           : FGPIO1PIN_P5A_INITOUT(v) )

#define FGPIO1PIN_P5A_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_PA=(v).bPullup; \
                                            bFM_GPIO_DDR5_PA=0u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

#define FGPIO1PIN_P5A_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.PA=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.PA=1u; \
                                            bFM_GPIO_DDR5_PA=1u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

/*---- Fast GPIO bit NP5A ----*/
#define FGPIO1PIN_NP5A_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.PA)) )

#define FGPIO1PIN_NP5A_PUT(v)           ( FM_FASTIO->FPDOR5_f.PA=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP5A_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP5A_INITIN(v) \
                                                           : FGPIO1PIN_NP5A_INITOUT(v) )

#define FGPIO1PIN_NP5A_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_PA=(v).bPullup; \
                                            bFM_GPIO_DDR5_PA=0u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

#define FGPIO1PIN_NP5A_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.PA=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.PA=1u; \
                                            bFM_GPIO_DDR5_PA=1u; \
                                            bFM_GPIO_PFR5_PA=0u; }while(0u)

/*---- Fast GPIO bit P5B ----*/
#define FGPIO1PIN_P5B_GET               ( FM_FASTIO->FPDIR5_f.PB )

#define FGPIO1PIN_P5B_PUT(v)            ( FM_FASTIO->FPDOR5_f.PB=(v) )

#define FGPIO1PIN_P5B_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P5B_INITIN(v) \
                                                           : FGPIO1PIN_P5B_INITOUT(v) )

#define FGPIO1PIN_P5B_INITIN(v)         do{ \
                                            bFM_GPIO_PCR5_PB=(v).bPullup; \
                                            bFM_GPIO_DDR5_PB=0u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

#define FGPIO1PIN_P5B_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR5_f.PB=(v).bInitVal; \
                                            FM_GPIO->FPOER5_f.PB=1u; \
                                            bFM_GPIO_DDR5_PB=1u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

/*---- Fast GPIO bit NP5B ----*/
#define FGPIO1PIN_NP5B_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR5_f.PB)) )

#define FGPIO1PIN_NP5B_PUT(v)           ( FM_FASTIO->FPDOR5_f.PB=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP5B_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP5B_INITIN(v) \
                                                           : FGPIO1PIN_NP5B_INITOUT(v) )

#define FGPIO1PIN_NP5B_INITIN(v)        do{ \
                                            bFM_GPIO_PCR5_PB=(v).bPullup; \
                                            bFM_GPIO_DDR5_PB=0u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

#define FGPIO1PIN_NP5B_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR5_f.PB=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER5_f.PB=1u; \
                                            bFM_GPIO_DDR5_PB=1u; \
                                            bFM_GPIO_PFR5_PB=0u; }while(0u)

/*---- Fast GPIO bit P60 ----*/
#define FGPIO1PIN_P60_GET               ( FM_FASTIO->FPDIR6_f.P0 )

#define FGPIO1PIN_P60_PUT(v)            ( FM_FASTIO->FPDOR6_f.P0=(v) )

#define FGPIO1PIN_P60_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P60_INITIN(v) \
                                                           : FGPIO1PIN_P60_INITOUT(v) )

#define FGPIO1PIN_P60_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P0=(v).bPullup; \
                                            bFM_GPIO_DDR6_P0=0u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

#define FGPIO1PIN_P60_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P0=1u; \
                                            bFM_GPIO_DDR6_P0=1u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

/*---- Fast GPIO bit NP60 ----*/
#define FGPIO1PIN_NP60_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P0)) )

#define FGPIO1PIN_NP60_PUT(v)           ( FM_FASTIO->FPDOR6_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP60_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP60_INITIN(v) \
                                                           : FGPIO1PIN_NP60_INITOUT(v) )

#define FGPIO1PIN_NP60_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P0=(v).bPullup; \
                                            bFM_GPIO_DDR6_P0=0u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

#define FGPIO1PIN_NP60_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P0=1u; \
                                            bFM_GPIO_DDR6_P0=1u; \
                                            bFM_GPIO_PFR6_P0=0u; }while(0u)

/*---- Fast GPIO bit P61 ----*/
#define FGPIO1PIN_P61_GET               ( FM_FASTIO->FPDIR6_f.P1 )

#define FGPIO1PIN_P61_PUT(v)            ( FM_FASTIO->FPDOR6_f.P1=(v) )

#define FGPIO1PIN_P61_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P61_INITIN(v) \
                                                           : FGPIO1PIN_P61_INITOUT(v) )

#define FGPIO1PIN_P61_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P1=(v).bPullup; \
                                            bFM_GPIO_DDR6_P1=0u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

#define FGPIO1PIN_P61_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P1=1u; \
                                            bFM_GPIO_DDR6_P1=1u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

/*---- Fast GPIO bit NP61 ----*/
#define FGPIO1PIN_NP61_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P1)) )

#define FGPIO1PIN_NP61_PUT(v)           ( FM_FASTIO->FPDOR6_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP61_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP61_INITIN(v) \
                                                           : FGPIO1PIN_NP61_INITOUT(v) )

#define FGPIO1PIN_NP61_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P1=(v).bPullup; \
                                            bFM_GPIO_DDR6_P1=0u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

#define FGPIO1PIN_NP61_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P1=1u; \
                                            bFM_GPIO_DDR6_P1=1u; \
                                            bFM_GPIO_PFR6_P1=0u; }while(0u)

/*---- Fast GPIO bit P62 ----*/
#define FGPIO1PIN_P62_GET               ( FM_FASTIO->FPDIR6_f.P2 )

#define FGPIO1PIN_P62_PUT(v)            ( FM_FASTIO->FPDOR6_f.P2=(v) )

#define FGPIO1PIN_P62_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P62_INITIN(v) \
                                                           : FGPIO1PIN_P62_INITOUT(v) )

#define FGPIO1PIN_P62_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P2=(v).bPullup; \
                                            bFM_GPIO_DDR6_P2=0u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

#define FGPIO1PIN_P62_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P2=1u; \
                                            bFM_GPIO_DDR6_P2=1u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

/*---- Fast GPIO bit NP62 ----*/
#define FGPIO1PIN_NP62_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P2)) )

#define FGPIO1PIN_NP62_PUT(v)           ( FM_FASTIO->FPDOR6_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP62_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP62_INITIN(v) \
                                                           : FGPIO1PIN_NP62_INITOUT(v) )

#define FGPIO1PIN_NP62_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P2=(v).bPullup; \
                                            bFM_GPIO_DDR6_P2=0u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

#define FGPIO1PIN_NP62_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P2=1u; \
                                            bFM_GPIO_DDR6_P2=1u; \
                                            bFM_GPIO_PFR6_P2=0u; }while(0u)

/*---- Fast GPIO bit P63 ----*/
#define FGPIO1PIN_P63_GET               ( FM_FASTIO->FPDIR6_f.P3 )

#define FGPIO1PIN_P63_PUT(v)            ( FM_FASTIO->FPDOR6_f.P3=(v) )

#define FGPIO1PIN_P63_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P63_INITIN(v) \
                                                           : FGPIO1PIN_P63_INITOUT(v) )

#define FGPIO1PIN_P63_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P3=(v).bPullup; \
                                            bFM_GPIO_DDR6_P3=0u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

#define FGPIO1PIN_P63_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P3=1u; \
                                            bFM_GPIO_DDR6_P3=1u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

/*---- Fast GPIO bit NP63 ----*/
#define FGPIO1PIN_NP63_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P3)) )

#define FGPIO1PIN_NP63_PUT(v)           ( FM_FASTIO->FPDOR6_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP63_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP63_INITIN(v) \
                                                           : FGPIO1PIN_NP63_INITOUT(v) )

#define FGPIO1PIN_NP63_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P3=(v).bPullup; \
                                            bFM_GPIO_DDR6_P3=0u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

#define FGPIO1PIN_NP63_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P3=1u; \
                                            bFM_GPIO_DDR6_P3=1u; \
                                            bFM_GPIO_PFR6_P3=0u; }while(0u)

/*---- Fast GPIO bit P64 ----*/
#define FGPIO1PIN_P64_GET               ( FM_FASTIO->FPDIR6_f.P4 )

#define FGPIO1PIN_P64_PUT(v)            ( FM_FASTIO->FPDOR6_f.P4=(v) )

#define FGPIO1PIN_P64_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P64_INITIN(v) \
                                                           : FGPIO1PIN_P64_INITOUT(v) )

#define FGPIO1PIN_P64_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P4=(v).bPullup; \
                                            bFM_GPIO_DDR6_P4=0u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

#define FGPIO1PIN_P64_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P4=1u; \
                                            bFM_GPIO_DDR6_P4=1u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

/*---- Fast GPIO bit NP64 ----*/
#define FGPIO1PIN_NP64_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P4)) )

#define FGPIO1PIN_NP64_PUT(v)           ( FM_FASTIO->FPDOR6_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP64_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP64_INITIN(v) \
                                                           : FGPIO1PIN_NP64_INITOUT(v) )

#define FGPIO1PIN_NP64_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P4=(v).bPullup; \
                                            bFM_GPIO_DDR6_P4=0u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

#define FGPIO1PIN_NP64_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P4=1u; \
                                            bFM_GPIO_DDR6_P4=1u; \
                                            bFM_GPIO_PFR6_P4=0u; }while(0u)

/*---- Fast GPIO bit P65 ----*/
#define FGPIO1PIN_P65_GET               ( FM_FASTIO->FPDIR6_f.P5 )

#define FGPIO1PIN_P65_PUT(v)            ( FM_FASTIO->FPDOR6_f.P5=(v) )

#define FGPIO1PIN_P65_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P65_INITIN(v) \
                                                           : FGPIO1PIN_P65_INITOUT(v) )

#define FGPIO1PIN_P65_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P5=(v).bPullup; \
                                            bFM_GPIO_DDR6_P5=0u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

#define FGPIO1PIN_P65_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P5=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P5=1u; \
                                            bFM_GPIO_DDR6_P5=1u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

/*---- Fast GPIO bit NP65 ----*/
#define FGPIO1PIN_NP65_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P5)) )

#define FGPIO1PIN_NP65_PUT(v)           ( FM_FASTIO->FPDOR6_f.P5=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP65_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP65_INITIN(v) \
                                                           : FGPIO1PIN_NP65_INITOUT(v) )

#define FGPIO1PIN_NP65_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P5=(v).bPullup; \
                                            bFM_GPIO_DDR6_P5=0u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

#define FGPIO1PIN_NP65_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P5=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P5=1u; \
                                            bFM_GPIO_DDR6_P5=1u; \
                                            bFM_GPIO_PFR6_P5=0u; }while(0u)

/*---- Fast GPIO bit P66 ----*/
#define FGPIO1PIN_P66_GET               ( FM_FASTIO->FPDIR6_f.P6 )

#define FGPIO1PIN_P66_PUT(v)            ( FM_FASTIO->FPDOR6_f.P6=(v) )

#define FGPIO1PIN_P66_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P66_INITIN(v) \
                                                           : FGPIO1PIN_P66_INITOUT(v) )

#define FGPIO1PIN_P66_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P6=(v).bPullup; \
                                            bFM_GPIO_DDR6_P6=0u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

#define FGPIO1PIN_P66_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P6=1u; \
                                            bFM_GPIO_DDR6_P6=1u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

/*---- Fast GPIO bit NP66 ----*/
#define FGPIO1PIN_NP66_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P6)) )

#define FGPIO1PIN_NP66_PUT(v)           ( FM_FASTIO->FPDOR6_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP66_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP66_INITIN(v) \
                                                           : FGPIO1PIN_NP66_INITOUT(v) )

#define FGPIO1PIN_NP66_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P6=(v).bPullup; \
                                            bFM_GPIO_DDR6_P6=0u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

#define FGPIO1PIN_NP66_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P6=1u; \
                                            bFM_GPIO_DDR6_P6=1u; \
                                            bFM_GPIO_PFR6_P6=0u; }while(0u)

/*---- Fast GPIO bit P67 ----*/
#define FGPIO1PIN_P67_GET               ( FM_FASTIO->FPDIR6_f.P7 )

#define FGPIO1PIN_P67_PUT(v)            ( FM_FASTIO->FPDOR6_f.P7=(v) )

#define FGPIO1PIN_P67_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P67_INITIN(v) \
                                                           : FGPIO1PIN_P67_INITOUT(v) )

#define FGPIO1PIN_P67_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P7=(v).bPullup; \
                                            bFM_GPIO_DDR6_P7=0u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

#define FGPIO1PIN_P67_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P7=1u; \
                                            bFM_GPIO_DDR6_P7=1u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

/*---- Fast GPIO bit NP67 ----*/
#define FGPIO1PIN_NP67_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P7)) )

#define FGPIO1PIN_NP67_PUT(v)           ( FM_FASTIO->FPDOR6_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP67_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP67_INITIN(v) \
                                                           : FGPIO1PIN_NP67_INITOUT(v) )

#define FGPIO1PIN_NP67_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P7=(v).bPullup; \
                                            bFM_GPIO_DDR6_P7=0u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

#define FGPIO1PIN_NP67_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P7=1u; \
                                            bFM_GPIO_DDR6_P7=1u; \
                                            bFM_GPIO_PFR6_P7=0u; }while(0u)

/*---- Fast GPIO bit P68 ----*/
#define FGPIO1PIN_P68_GET               ( FM_FASTIO->FPDIR6_f.P8 )

#define FGPIO1PIN_P68_PUT(v)            ( FM_FASTIO->FPDOR6_f.P8=(v) )

#define FGPIO1PIN_P68_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P68_INITIN(v) \
                                                           : FGPIO1PIN_P68_INITOUT(v) )

#define FGPIO1PIN_P68_INITIN(v)         do{ \
                                            bFM_GPIO_PCR6_P8=(v).bPullup; \
                                            bFM_GPIO_DDR6_P8=0u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

#define FGPIO1PIN_P68_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR6_f.P8=(v).bInitVal; \
                                            FM_GPIO->FPOER6_f.P8=1u; \
                                            bFM_GPIO_DDR6_P8=1u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

/*---- Fast GPIO bit NP68 ----*/
#define FGPIO1PIN_NP68_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR6_f.P8)) )

#define FGPIO1PIN_NP68_PUT(v)           ( FM_FASTIO->FPDOR6_f.P8=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP68_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP68_INITIN(v) \
                                                           : FGPIO1PIN_NP68_INITOUT(v) )

#define FGPIO1PIN_NP68_INITIN(v)        do{ \
                                            bFM_GPIO_PCR6_P8=(v).bPullup; \
                                            bFM_GPIO_DDR6_P8=0u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

#define FGPIO1PIN_NP68_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR6_f.P8=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER6_f.P8=1u; \
                                            bFM_GPIO_DDR6_P8=1u; \
                                            bFM_GPIO_PFR6_P8=0u; }while(0u)

/*---- Fast GPIO bit P70 ----*/
#define FGPIO1PIN_P70_GET               ( FM_FASTIO->FPDIR7_f.P0 )

#define FGPIO1PIN_P70_PUT(v)            ( FM_FASTIO->FPDOR7_f.P0=(v) )

#define FGPIO1PIN_P70_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P70_INITIN(v) \
                                                           : FGPIO1PIN_P70_INITOUT(v) )

#define FGPIO1PIN_P70_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P0=(v).bPullup; \
                                            bFM_GPIO_DDR7_P0=0u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

#define FGPIO1PIN_P70_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR7_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER7_f.P0=1u; \
                                            bFM_GPIO_DDR7_P0=1u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

/*---- Fast GPIO bit NP70 ----*/
#define FGPIO1PIN_NP70_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR7_f.P0)) )

#define FGPIO1PIN_NP70_PUT(v)           ( FM_FASTIO->FPDOR7_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP70_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP70_INITIN(v) \
                                                           : FGPIO1PIN_NP70_INITOUT(v) )

#define FGPIO1PIN_NP70_INITIN(v)        do{ \
                                            bFM_GPIO_PCR7_P0=(v).bPullup; \
                                            bFM_GPIO_DDR7_P0=0u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

#define FGPIO1PIN_NP70_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR7_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER7_f.P0=1u; \
                                            bFM_GPIO_DDR7_P0=1u; \
                                            bFM_GPIO_PFR7_P0=0u; }while(0u)

/*---- Fast GPIO bit P71 ----*/
#define FGPIO1PIN_P71_GET               ( FM_FASTIO->FPDIR7_f.P1 )

#define FGPIO1PIN_P71_PUT(v)            ( FM_FASTIO->FPDOR7_f.P1=(v) )

#define FGPIO1PIN_P71_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P71_INITIN(v) \
                                                           : FGPIO1PIN_P71_INITOUT(v) )

#define FGPIO1PIN_P71_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P1=(v).bPullup; \
                                            bFM_GPIO_DDR7_P1=0u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

#define FGPIO1PIN_P71_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR7_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER7_f.P1=1u; \
                                            bFM_GPIO_DDR7_P1=1u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

/*---- Fast GPIO bit NP71 ----*/
#define FGPIO1PIN_NP71_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR7_f.P1)) )

#define FGPIO1PIN_NP71_PUT(v)           ( FM_FASTIO->FPDOR7_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP71_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP71_INITIN(v) \
                                                           : FGPIO1PIN_NP71_INITOUT(v) )

#define FGPIO1PIN_NP71_INITIN(v)        do{ \
                                            bFM_GPIO_PCR7_P1=(v).bPullup; \
                                            bFM_GPIO_DDR7_P1=0u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

#define FGPIO1PIN_NP71_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR7_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER7_f.P1=1u; \
                                            bFM_GPIO_DDR7_P1=1u; \
                                            bFM_GPIO_PFR7_P1=0u; }while(0u)

/*---- Fast GPIO bit P72 ----*/
#define FGPIO1PIN_P72_GET               ( FM_FASTIO->FPDIR7_f.P2 )

#define FGPIO1PIN_P72_PUT(v)            ( FM_FASTIO->FPDOR7_f.P2=(v) )

#define FGPIO1PIN_P72_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P72_INITIN(v) \
                                                           : FGPIO1PIN_P72_INITOUT(v) )

#define FGPIO1PIN_P72_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P2=(v).bPullup; \
                                            bFM_GPIO_DDR7_P2=0u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

#define FGPIO1PIN_P72_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR7_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER7_f.P2=1u; \
                                            bFM_GPIO_DDR7_P2=1u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

/*---- Fast GPIO bit NP72 ----*/
#define FGPIO1PIN_NP72_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR7_f.P2)) )

#define FGPIO1PIN_NP72_PUT(v)           ( FM_FASTIO->FPDOR7_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP72_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP72_INITIN(v) \
                                                           : FGPIO1PIN_NP72_INITOUT(v) )

#define FGPIO1PIN_NP72_INITIN(v)        do{ \
                                            bFM_GPIO_PCR7_P2=(v).bPullup; \
                                            bFM_GPIO_DDR7_P2=0u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

#define FGPIO1PIN_NP72_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR7_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER7_f.P2=1u; \
                                            bFM_GPIO_DDR7_P2=1u; \
                                            bFM_GPIO_PFR7_P2=0u; }while(0u)

/*---- Fast GPIO bit P73 ----*/
#define FGPIO1PIN_P73_GET               ( FM_FASTIO->FPDIR7_f.P3 )

#define FGPIO1PIN_P73_PUT(v)            ( FM_FASTIO->FPDOR7_f.P3=(v) )

#define FGPIO1PIN_P73_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P73_INITIN(v) \
                                                           : FGPIO1PIN_P73_INITOUT(v) )

#define FGPIO1PIN_P73_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P3=(v).bPullup; \
                                            bFM_GPIO_DDR7_P3=0u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

#define FGPIO1PIN_P73_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR7_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOER7_f.P3=1u; \
                                            bFM_GPIO_DDR7_P3=1u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

/*---- Fast GPIO bit NP73 ----*/
#define FGPIO1PIN_NP73_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR7_f.P3)) )

#define FGPIO1PIN_NP73_PUT(v)           ( FM_FASTIO->FPDOR7_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP73_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP73_INITIN(v) \
                                                           : FGPIO1PIN_NP73_INITOUT(v) )

#define FGPIO1PIN_NP73_INITIN(v)        do{ \
                                            bFM_GPIO_PCR7_P3=(v).bPullup; \
                                            bFM_GPIO_DDR7_P3=0u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

#define FGPIO1PIN_NP73_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR7_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER7_f.P3=1u; \
                                            bFM_GPIO_DDR7_P3=1u; \
                                            bFM_GPIO_PFR7_P3=0u; }while(0u)

/*---- Fast GPIO bit P74 ----*/
#define FGPIO1PIN_P74_GET               ( FM_FASTIO->FPDIR7_f.P4 )

#define FGPIO1PIN_P74_PUT(v)            ( FM_FASTIO->FPDOR7_f.P4=(v) )

#define FGPIO1PIN_P74_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P74_INITIN(v) \
                                                           : FGPIO1PIN_P74_INITOUT(v) )

#define FGPIO1PIN_P74_INITIN(v)         do{ \
                                            bFM_GPIO_PCR7_P4=(v).bPullup; \
                                            bFM_GPIO_DDR7_P4=0u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

#define FGPIO1PIN_P74_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR7_f.P4=(v).bInitVal; \
                                            FM_GPIO->FPOER7_f.P4=1u; \
                                            bFM_GPIO_DDR7_P4=1u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

/*---- Fast GPIO bit NP74 ----*/
#define FGPIO1PIN_NP74_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR7_f.P4)) )

#define FGPIO1PIN_NP74_PUT(v)           ( FM_FASTIO->FPDOR7_f.P4=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP74_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP74_INITIN(v) \
                                                           : FGPIO1PIN_NP74_INITOUT(v) )

#define FGPIO1PIN_NP74_INITIN(v)        do{ \
                                            bFM_GPIO_PCR7_P4=(v).bPullup; \
                                            bFM_GPIO_DDR7_P4=0u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

#define FGPIO1PIN_NP74_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR7_f.P4=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER7_f.P4=1u; \
                                            bFM_GPIO_DDR7_P4=1u; \
                                            bFM_GPIO_PFR7_P4=0u; }while(0u)

/*---- Fast GPIO bit P80 ----*/
#define FGPIO1PIN_P80_GET               ( FM_FASTIO->FPDIR8_f.P0 )

#define FGPIO1PIN_P80_PUT(v)            ( FM_FASTIO->FPDOR8_f.P0=(v) )

#define FGPIO1PIN_P80_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P80_INITIN(v) \
                                                           : FGPIO1PIN_P80_INITOUT(v) )

#define FGPIO1PIN_P80_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P0=0u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

#define FGPIO1PIN_P80_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR8_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOER8_f.P0=1u; \
                                            bFM_GPIO_DDR8_P0=1u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

/*---- Fast GPIO bit NP80 ----*/
#define FGPIO1PIN_NP80_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR8_f.P0)) )

#define FGPIO1PIN_NP80_PUT(v)           ( FM_FASTIO->FPDOR8_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP80_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP80_INITIN(v) \
                                                           : FGPIO1PIN_NP80_INITOUT(v) )

#define FGPIO1PIN_NP80_INITIN(v)        do{ \
                                            bFM_GPIO_DDR8_P0=0u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

#define FGPIO1PIN_NP80_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR8_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER8_f.P0=1u; \
                                            bFM_GPIO_DDR8_P0=1u; \
                                            bFM_GPIO_PFR8_P0=0u; }while(0u)

/*---- Fast GPIO bit P81 ----*/
#define FGPIO1PIN_P81_GET               ( FM_FASTIO->FPDIR8_f.P1 )

#define FGPIO1PIN_P81_PUT(v)            ( FM_FASTIO->FPDOR8_f.P1=(v) )

#define FGPIO1PIN_P81_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P81_INITIN(v) \
                                                           : FGPIO1PIN_P81_INITOUT(v) )

#define FGPIO1PIN_P81_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P1=0u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

#define FGPIO1PIN_P81_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR8_f.P1=(v).bInitVal; \
                                            FM_GPIO->FPOER8_f.P1=1u; \
                                            bFM_GPIO_DDR8_P1=1u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

/*---- Fast GPIO bit NP81 ----*/
#define FGPIO1PIN_NP81_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR8_f.P1)) )

#define FGPIO1PIN_NP81_PUT(v)           ( FM_FASTIO->FPDOR8_f.P1=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP81_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP81_INITIN(v) \
                                                           : FGPIO1PIN_NP81_INITOUT(v) )

#define FGPIO1PIN_NP81_INITIN(v)        do{ \
                                            bFM_GPIO_DDR8_P1=0u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

#define FGPIO1PIN_NP81_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR8_f.P1=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER8_f.P1=1u; \
                                            bFM_GPIO_DDR8_P1=1u; \
                                            bFM_GPIO_PFR8_P1=0u; }while(0u)

/*---- Fast GPIO bit P82 ----*/
#define FGPIO1PIN_P82_GET               ( FM_FASTIO->FPDIR8_f.P2 )

#define FGPIO1PIN_P82_PUT(v)            ( FM_FASTIO->FPDOR8_f.P2=(v) )

#define FGPIO1PIN_P82_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P82_INITIN(v) \
                                                           : FGPIO1PIN_P82_INITOUT(v) )

#define FGPIO1PIN_P82_INITIN(v)         do{ \
                                            bFM_GPIO_DDR8_P2=0u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

#define FGPIO1PIN_P82_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR8_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOER8_f.P2=1u; \
                                            bFM_GPIO_DDR8_P2=1u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

/*---- Fast GPIO bit NP82 ----*/
#define FGPIO1PIN_NP82_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR8_f.P2)) )

#define FGPIO1PIN_NP82_PUT(v)           ( FM_FASTIO->FPDOR8_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP82_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP82_INITIN(v) \
                                                           : FGPIO1PIN_NP82_INITOUT(v) )

#define FGPIO1PIN_NP82_INITIN(v)        do{ \
                                            bFM_GPIO_DDR8_P2=0u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

#define FGPIO1PIN_NP82_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR8_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER8_f.P2=1u; \
                                            bFM_GPIO_DDR8_P2=1u; \
                                            bFM_GPIO_PFR8_P2=0u; }while(0u)

/*---- Fast GPIO bit PE0 ----*/
#define FGPIO1PIN_PE0_GET               ( FM_FASTIO->FPDIRE_f.P0 )

#define FGPIO1PIN_PE0_PUT(v)            ( FM_FASTIO->FPDORE_f.P0=(v) )

#define FGPIO1PIN_PE0_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_PE0_INITIN(v) \
                                                           : FGPIO1PIN_PE0_INITOUT(v) )

#define FGPIO1PIN_PE0_INITIN(v)         do{ \
                                            bFM_GPIO_PCRE_P0=(v).bPullup; \
                                            bFM_GPIO_DDRE_P0=0u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

#define FGPIO1PIN_PE0_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDORE_f.P0=(v).bInitVal; \
                                            FM_GPIO->FPOERE_f.P0=1u; \
                                            bFM_GPIO_DDRE_P0=1u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

/*---- Fast GPIO bit NPE0 ----*/
#define FGPIO1PIN_NPE0_GET              ( (uint8_t)(!(FM_FASTIO->FPDIRE_f.P0)) )

#define FGPIO1PIN_NPE0_PUT(v)           ( FM_FASTIO->FPDORE_f.P0=(uint8_t)(!(v)) )

#define FGPIO1PIN_NPE0_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NPE0_INITIN(v) \
                                                           : FGPIO1PIN_NPE0_INITOUT(v) )

#define FGPIO1PIN_NPE0_INITIN(v)        do{ \
                                            bFM_GPIO_PCRE_P0=(v).bPullup; \
                                            bFM_GPIO_DDRE_P0=0u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

#define FGPIO1PIN_NPE0_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDORE_f.P0=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOERE_f.P0=1u; \
                                            bFM_GPIO_DDRE_P0=1u; \
                                            bFM_GPIO_PFRE_P0=0u; }while(0u)

/*---- Fast GPIO bit PE2 ----*/
#define FGPIO1PIN_PE2_GET               ( FM_FASTIO->FPDIRE_f.P2 )

#define FGPIO1PIN_PE2_PUT(v)            ( FM_FASTIO->FPDORE_f.P2=(v) )

#define FGPIO1PIN_PE2_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_PE2_INITIN(v) \
                                                           : FGPIO1PIN_PE2_INITOUT(v) )

#define FGPIO1PIN_PE2_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P2=(v).bPullup; \
                                            bFM_GPIO_DDRE_P2=0u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

#define FGPIO1PIN_PE2_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            FM_FASTIO->FPDORE_f.P2=(v).bInitVal; \
                                            FM_GPIO->FPOERE_f.P2=1u; \
                                            bFM_GPIO_DDRE_P2=1u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

/*---- Fast GPIO bit NPE2 ----*/
#define FGPIO1PIN_NPE2_GET              ( (uint8_t)(!(FM_FASTIO->FPDIRE_f.P2)) )

#define FGPIO1PIN_NPE2_PUT(v)           ( FM_FASTIO->FPDORE_f.P2=(uint8_t)(!(v)) )

#define FGPIO1PIN_NPE2_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NPE2_INITIN(v) \
                                                           : FGPIO1PIN_NPE2_INITOUT(v) )

#define FGPIO1PIN_NPE2_INITIN(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P2=(v).bPullup; \
                                            bFM_GPIO_DDRE_P2=0u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

#define FGPIO1PIN_NPE2_INITOUT(v)       do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            FM_FASTIO->FPDORE_f.P2=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOERE_f.P2=1u; \
                                            bFM_GPIO_DDRE_P2=1u; \
                                            bFM_GPIO_PFRE_P2=0u; }while(0u)

/*---- Fast GPIO bit PE3 ----*/
#define FGPIO1PIN_PE3_GET               ( FM_FASTIO->FPDIRE_f.P3 )

#define FGPIO1PIN_PE3_PUT(v)            ( FM_FASTIO->FPDORE_f.P3=(v) )

#define FGPIO1PIN_PE3_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_PE3_INITIN(v) \
                                                           : FGPIO1PIN_PE3_INITOUT(v) )

#define FGPIO1PIN_PE3_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P3=(v).bPullup; \
                                            bFM_GPIO_DDRE_P3=0u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

#define FGPIO1PIN_PE3_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            FM_FASTIO->FPDORE_f.P3=(v).bInitVal; \
                                            FM_GPIO->FPOERE_f.P3=1u; \
                                            bFM_GPIO_DDRE_P3=1u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

/*---- Fast GPIO bit NPE3 ----*/
#define FGPIO1PIN_NPE3_GET              ( (uint8_t)(!(FM_FASTIO->FPDIRE_f.P3)) )

#define FGPIO1PIN_NPE3_PUT(v)           ( FM_FASTIO->FPDORE_f.P3=(uint8_t)(!(v)) )

#define FGPIO1PIN_NPE3_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NPE3_INITIN(v) \
                                                           : FGPIO1PIN_NPE3_INITOUT(v) )

#define FGPIO1PIN_NPE3_INITIN(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            bFM_GPIO_PCRE_P3=(v).bPullup; \
                                            bFM_GPIO_DDRE_P3=0u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

#define FGPIO1PIN_NPE3_INITOUT(v)       do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 0u); \
                                            FM_FASTIO->FPDORE_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOERE_f.P3=1u; \
                                            bFM_GPIO_DDRE_P3=1u; \
                                            bFM_GPIO_PFRE_P3=0u; }while(0u)

/******************************************************************************
   PIN RELOCATION
*******************************************************************************/

/*--- ADTG_0_ADC0 ---*/
#define SetPinFunc_ADTG_0_ADC0(dummy)   do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  1u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- ADTG_0_ADC1 ---*/
#define SetPinFunc_ADTG_0_ADC1(dummy)   do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  1u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- ADTG_0_ADC2 ---*/
#define SetPinFunc_ADTG_0_ADC2(dummy)   do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  1u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- ADTG_1_ADC0 ---*/
#define SetPinFunc_ADTG_1_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  2u ); \
                                            bFM_GPIO_PFR5_P5 = 1u; \
                                        }while (0u)

/*--- ADTG_1_ADC1 ---*/
#define SetPinFunc_ADTG_1_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  2u ); \
                                            bFM_GPIO_PFR5_P5 = 1u; \
                                        }while (0u)

/*--- ADTG_1_ADC2 ---*/
#define SetPinFunc_ADTG_1_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  2u ); \
                                            bFM_GPIO_PFR5_P5 = 1u; \
                                        }while (0u)

/*--- ADTG_2_ADC0 ---*/
#define SetPinFunc_ADTG_2_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  3u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- ADTG_2_ADC1 ---*/
#define SetPinFunc_ADTG_2_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  3u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- ADTG_2_ADC2 ---*/
#define SetPinFunc_ADTG_2_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  3u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- ADTG_3_ADC0 ---*/
#define SetPinFunc_ADTG_3_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  4u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- ADTG_3_ADC1 ---*/
#define SetPinFunc_ADTG_3_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  4u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- ADTG_3_ADC2 ---*/
#define SetPinFunc_ADTG_3_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  4u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- ADTG_4_ADC0 ---*/
#define SetPinFunc_ADTG_4_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  5u ); \
                                            bFM_GPIO_PFR2_P8 = 1u; \
                                        }while (0u)

/*--- ADTG_4_ADC1 ---*/
#define SetPinFunc_ADTG_4_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  5u ); \
                                            bFM_GPIO_PFR2_P8 = 1u; \
                                        }while (0u)

/*--- ADTG_4_ADC2 ---*/
#define SetPinFunc_ADTG_4_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  5u ); \
                                            bFM_GPIO_PFR2_P8 = 1u; \
                                        }while (0u)

/*--- ADTG_5_ADC0 ---*/
#define SetPinFunc_ADTG_5_ADC0(dummy)   do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  6u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- ADTG_5_ADC1 ---*/
#define SetPinFunc_ADTG_5_ADC1(dummy)   do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  6u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- ADTG_5_ADC2 ---*/
#define SetPinFunc_ADTG_5_ADC2(dummy)   do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  6u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- ADTG_6_ADC0 ---*/
#define SetPinFunc_ADTG_6_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  7u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- ADTG_6_ADC1 ---*/
#define SetPinFunc_ADTG_6_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  7u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- ADTG_6_ADC2 ---*/
#define SetPinFunc_ADTG_6_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  7u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- ADTG_7_ADC0 ---*/
#define SetPinFunc_ADTG_7_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  8u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- ADTG_7_ADC1 ---*/
#define SetPinFunc_ADTG_7_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  8u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- ADTG_7_ADC2 ---*/
#define SetPinFunc_ADTG_7_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  8u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- C0 ---*/
#define SetPinFunc_C0(dummy)            do{ \
                                            bFM_GPIO_PFR8_P0 = 1u; \
                                        }while (0u)

/*--- C1 ---*/
#define SetPinFunc_C1(dummy)            do{ \
                                            bFM_GPIO_PFR8_P1 = 1u; \
                                        }while (0u)

/*--- CEC0_0 ---*/
#define SetPinFunc_CEC0_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR18, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PC = 1u; \
                                        }while (0u)

/*--- CEC0_1 ---*/
#define SetPinFunc_CEC0_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR18, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- CEC1_0 ---*/
#define SetPinFunc_CEC1_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR18, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- CEC1_1 ---*/
#define SetPinFunc_CEC1_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR18, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- CROUT_0 ---*/
#define SetPinFunc_CROUT_0(dummy)       do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 1u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P0 = 1u; \
                                        }while (0u)

/*--- CROUT_1 ---*/
#define SetPinFunc_CROUT_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 1u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- CTS1_1 ---*/
#define SetPinFunc_CTS1_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR34, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P0 = 1u; \
                                        }while (0u)

/*--- CTS1_2 ---*/
#define SetPinFunc_CTS1_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR34, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- CTS4_0 ---*/
#define SetPinFunc_CTS4_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PE = 1u; \
                                        }while (0u)

/*--- CTS4_1 ---*/
#define SetPinFunc_CTS4_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PD = 1u; \
                                        }while (0u)

/*--- CTS4_2 ---*/
#define SetPinFunc_CTS4_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 2u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P8 = 1u; \
                                        }while (0u)

/*--- DTTI0X_0 ---*/
#define SetPinFunc_DTTI0X_0(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- DTTI0X_1 ---*/
#define SetPinFunc_DTTI0X_1(dummy)      do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PD = 1u; \
                                        }while (0u)

/*--- DTTI0X_2 ---*/
#define SetPinFunc_DTTI0X_2(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- FRCK0_0 ---*/
#define SetPinFunc_FRCK0_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P4 = 1u; \
                                        }while (0u)

/*--- FRCK0_1 ---*/
#define SetPinFunc_FRCK0_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- FRCK0_2 ---*/
#define SetPinFunc_FRCK0_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 18u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- IC00_0 ---*/
#define SetPinFunc_IC00_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 20u, 3u,  1u ); \
                                            bFM_GPIO_PFR3_P8 = 1u; \
                                        }while (0u)

/*--- IC00_1 ---*/
#define SetPinFunc_IC00_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 20u, 3u,  2u ); \
                                            bFM_GPIO_PFR1_P9 = 1u; \
                                        }while (0u)

/*--- IC00_2 ---*/
#define SetPinFunc_IC00_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 20u, 3u,  3u ); \
                                            bFM_GPIO_PFR1_P2 = 1u; \
                                        }while (0u)

/*--- IC00_LSYN0 ---*/
#define SetPinFunc_IC00_LSYN0(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 20u, 3u,  4u ); \
                                        }while (0u)

/*--- IC00_LSYN4 ---*/
#define SetPinFunc_IC00_LSYN4(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 20u, 3u,  5u ); \
                                        }while (0u)

/*--- IC01_0 ---*/
#define SetPinFunc_IC01_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  1u ); \
                                            bFM_GPIO_PFR3_P7 = 1u; \
                                        }while (0u)

/*--- IC01_1 ---*/
#define SetPinFunc_IC01_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  2u ); \
                                            bFM_GPIO_PFR1_PA = 1u; \
                                        }while (0u)

/*--- IC01_2 ---*/
#define SetPinFunc_IC01_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  3u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- IC01_LSYN1 ---*/
#define SetPinFunc_IC01_LSYN1(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  4u ); \
                                        }while (0u)

/*--- IC01_LSYN5 ---*/
#define SetPinFunc_IC01_LSYN5(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  5u ); \
                                        }while (0u)

/*--- IC02_0 ---*/
#define SetPinFunc_IC02_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  1u ); \
                                            bFM_GPIO_PFR3_P6 = 1u; \
                                        }while (0u)

/*--- IC02_1 ---*/
#define SetPinFunc_IC02_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  2u ); \
                                            bFM_GPIO_PFR1_PB = 1u; \
                                        }while (0u)

/*--- IC02_2 ---*/
#define SetPinFunc_IC02_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  3u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- IC02_LSYN2 ---*/
#define SetPinFunc_IC02_LSYN2(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  4u ); \
                                        }while (0u)

/*--- IC02_LSYN6 ---*/
#define SetPinFunc_IC02_LSYN6(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  5u ); \
                                        }while (0u)

/*--- IC03_0 ---*/
#define SetPinFunc_IC03_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  1u ); \
                                            bFM_GPIO_PFR3_P5 = 1u; \
                                        }while (0u)

/*--- IC03_1 ---*/
#define SetPinFunc_IC03_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  2u ); \
                                            bFM_GPIO_PFR1_PC = 1u; \
                                        }while (0u)

/*--- IC03_2 ---*/
#define SetPinFunc_IC03_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  3u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- IC03_LSYN3 ---*/
#define SetPinFunc_IC03_LSYN3(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  4u ); \
                                        }while (0u)

/*--- IC03_LSYN7 ---*/
#define SetPinFunc_IC03_LSYN7(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  5u ); \
                                        }while (0u)

/*--- IC0_CIN_0 ---*/
#define SetPinFunc_IC0_CIN_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- IC0_CIN_1 ---*/
#define SetPinFunc_IC0_CIN_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P5 = 1u; \
                                        }while (0u)

/*--- IC0_CLK_0 ---*/
#define SetPinFunc_IC0_CLK_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- IC0_CLK_1 ---*/
#define SetPinFunc_IC0_CLK_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P0 = 1u; \
                                        }while (0u)

/*--- IC0_DATA_0 ---*/
#define SetPinFunc_IC0_DATA_0(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P3 = 1u; \
                                        }while (0u)

/*--- IC0_DATA_1 ---*/
#define SetPinFunc_IC0_DATA_1(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P4 = 1u; \
                                        }while (0u)

/*--- IC0_RST_0 ---*/
#define SetPinFunc_IC0_RST_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- IC0_RST_1 ---*/
#define SetPinFunc_IC0_RST_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- IC0_VCC_0 ---*/
#define SetPinFunc_IC0_VCC_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PE = 1u; \
                                        }while (0u)

/*--- IC0_VCC_1 ---*/
#define SetPinFunc_IC0_VCC_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P1 = 1u; \
                                        }while (0u)

/*--- IC0_VPEN_0 ---*/
#define SetPinFunc_IC0_VPEN_0(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PD = 1u; \
                                        }while (0u)

/*--- IC0_VPEN_1 ---*/
#define SetPinFunc_IC0_VPEN_1(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P2 = 1u; \
                                        }while (0u)

/*--- IC1_CIN_0 ---*/
#define SetPinFunc_IC1_CIN_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- IC1_CIN_1 ---*/
#define SetPinFunc_IC1_CIN_1(dummy)     do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- IC1_CLK_0 ---*/
#define SetPinFunc_IC1_CLK_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- IC1_CLK_1 ---*/
#define SetPinFunc_IC1_CLK_1(dummy)     do{ \
                                            bFM_GPIO_ADE_AN00=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P0 = 1u; \
                                        }while (0u)

/*--- IC1_DATA_0 ---*/
#define SetPinFunc_IC1_DATA_0(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- IC1_DATA_1 ---*/
#define SetPinFunc_IC1_DATA_1(dummy)    do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- IC1_RST_0 ---*/
#define SetPinFunc_IC1_RST_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- IC1_RST_1 ---*/
#define SetPinFunc_IC1_RST_1(dummy)     do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- IC1_VCC_0 ---*/
#define SetPinFunc_IC1_VCC_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- IC1_VCC_1 ---*/
#define SetPinFunc_IC1_VCC_1(dummy)     do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- IC1_VPEN_0 ---*/
#define SetPinFunc_IC1_VPEN_0(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- IC1_VPEN_1 ---*/
#define SetPinFunc_IC1_VPEN_1(dummy)    do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR33, 22u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P2 = 1u; \
                                        }while (0u)

/*--- IGTRG0_0 ---*/
#define SetPinFunc_IGTRG0_0(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 13u, 1u,  0u ); \
                                            bFM_GPIO_PFR4_PB = 1u; \
                                        }while (0u)

/*--- IGTRG0_1 ---*/
#define SetPinFunc_IGTRG0_1(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 13u, 1u,  1u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- INT00_0 ---*/
#define SetPinFunc_INT00_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- INT00_1 ---*/
#define SetPinFunc_INT00_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_P5 = 1u; \
                                        }while (0u)

/*--- INT00_2 ---*/
#define SetPinFunc_INT00_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 0u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- INT01_0 ---*/
#define SetPinFunc_INT01_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P1 = 1u; \
                                        }while (0u)

/*--- INT01_1 ---*/
#define SetPinFunc_INT01_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_P6 = 1u; \
                                        }while (0u)

/*--- INT02_0 ---*/
#define SetPinFunc_INT02_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P2 = 1u; \
                                        }while (0u)

/*--- INT02_1 ---*/
#define SetPinFunc_INT02_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- INT02_2 ---*/
#define SetPinFunc_INT02_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR2_P7 = 1u; \
                                        }while (0u)

/*--- INT03_0 ---*/
#define SetPinFunc_INT03_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P3 = 1u; \
                                        }while (0u)

/*--- INT03_1 ---*/
#define SetPinFunc_INT03_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- INT03_2 ---*/
#define SetPinFunc_INT03_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P0 = 1u; \
                                        }while (0u)

/*--- INT04_0 ---*/
#define SetPinFunc_INT04_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- INT04_1 ---*/
#define SetPinFunc_INT04_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P7 = 1u; \
                                        }while (0u)

/*--- INT04_2 ---*/
#define SetPinFunc_INT04_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P1 = 1u; \
                                        }while (0u)

/*--- INT05_0 ---*/
#define SetPinFunc_INT05_0(dummy)       do{ \
                                            bFM_GPIO_ADE_AN19=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P0 = 1u; \
                                        }while (0u)

/*--- INT05_1 ---*/
#define SetPinFunc_INT05_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PA = 1u; \
                                        }while (0u)

/*--- INT05_2 ---*/
#define SetPinFunc_INT05_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P2 = 1u; \
                                        }while (0u)

/*--- INT06_0 ---*/
#define SetPinFunc_INT06_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- INT06_1 ---*/
#define SetPinFunc_INT06_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- INT06_2 ---*/
#define SetPinFunc_INT06_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- INT07_0 ---*/
#define SetPinFunc_INT07_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 14u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- INT07_1 ---*/
#define SetPinFunc_INT07_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 14u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- INT07_2 ---*/
#define SetPinFunc_INT07_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 14u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_P3 = 1u; \
                                        }while (0u)

/*--- INT08_0 ---*/
#define SetPinFunc_INT08_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P2 = 1u; \
                                        }while (0u)

/*--- INT08_1 ---*/
#define SetPinFunc_INT08_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P5 = 1u; \
                                        }while (0u)

/*--- INT08_2 ---*/
#define SetPinFunc_INT08_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 16u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- INT09_0 ---*/
#define SetPinFunc_INT09_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- INT09_1 ---*/
#define SetPinFunc_INT09_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P6 = 1u; \
                                        }while (0u)

/*--- INT10_0 ---*/
#define SetPinFunc_INT10_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P4 = 1u; \
                                        }while (0u)

/*--- INT10_1 ---*/
#define SetPinFunc_INT10_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P7 = 1u; \
                                        }while (0u)

/*--- INT10_2 ---*/
#define SetPinFunc_INT10_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 20u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P4 = 1u; \
                                        }while (0u)

/*--- INT11_0 ---*/
#define SetPinFunc_INT11_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR8_P1 = 1u; \
                                        }while (0u)

/*--- INT11_1 ---*/
#define SetPinFunc_INT11_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 22u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P8 = 1u; \
                                        }while (0u)

/*--- INT11_2 ---*/
#define SetPinFunc_INT11_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 22u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P6 = 1u; \
                                        }while (0u)

/*--- INT12_0 ---*/
#define SetPinFunc_INT12_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PC = 1u; \
                                        }while (0u)

/*--- INT12_1 ---*/
#define SetPinFunc_INT12_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P0 = 1u; \
                                        }while (0u)

/*--- INT12_2 ---*/
#define SetPinFunc_INT12_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P8 = 1u; \
                                        }while (0u)

/*--- INT13_0 ---*/
#define SetPinFunc_INT13_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PD = 1u; \
                                        }while (0u)

/*--- INT13_1 ---*/
#define SetPinFunc_INT13_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_P1 = 1u; \
                                        }while (0u)

/*--- INT13_2 ---*/
#define SetPinFunc_INT13_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR7_P1 = 1u; \
                                        }while (0u)

/*--- INT14_0 ---*/
#define SetPinFunc_INT14_0(dummy)       do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 28u, 2u,  1u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- INT14_1 ---*/
#define SetPinFunc_INT14_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 28u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_P0 = 1u; \
                                        }while (0u)

/*--- INT14_2 ---*/
#define SetPinFunc_INT14_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 28u, 2u,  3u ); \
                                            bFM_GPIO_PFR7_P2 = 1u; \
                                        }while (0u)

/*--- INT15_0 ---*/
#define SetPinFunc_INT15_0(dummy)       do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  1u ); \
                                            bFM_GPIO_PFR1_P6 = 1u; \
                                        }while (0u)

/*--- INT15_1 ---*/
#define SetPinFunc_INT15_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- INT15_2 ---*/
#define SetPinFunc_INT15_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  3u ); \
                                            bFM_GPIO_PFR7_P3 = 1u; \
                                        }while (0u)

/*--- INT16_0 ---*/
#define SetPinFunc_INT16_0(dummy)       do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_P8 = 1u; \
                                        }while (0u)

/*--- INT16_1 ---*/
#define SetPinFunc_INT16_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P9 = 1u; \
                                        }while (0u)

/*--- INT16_2 ---*/
#define SetPinFunc_INT16_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 0u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_PA = 1u; \
                                        }while (0u)

/*--- INT17_0 ---*/
#define SetPinFunc_INT17_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_P9 = 1u; \
                                        }while (0u)

/*--- INT17_1 ---*/
#define SetPinFunc_INT17_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P4 = 1u; \
                                        }while (0u)

/*--- INT17_2 ---*/
#define SetPinFunc_INT17_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 2u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_PB = 1u; \
                                        }while (0u)

/*--- INT18_0 ---*/
#define SetPinFunc_INT18_0(dummy)       do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PB = 1u; \
                                        }while (0u)

/*--- INT18_1 ---*/
#define SetPinFunc_INT18_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P4 = 1u; \
                                        }while (0u)

/*--- INT18_2 ---*/
#define SetPinFunc_INT18_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- INT19_0 ---*/
#define SetPinFunc_INT19_0(dummy)       do{ \
                                            bFM_GPIO_SPSR_USB0C=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PC = 1u; \
                                        }while (0u)

/*--- INT19_1 ---*/
#define SetPinFunc_INT19_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P5 = 1u; \
                                        }while (0u)

/*--- INT19_2 ---*/
#define SetPinFunc_INT19_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- INT20_0 ---*/
#define SetPinFunc_INT20_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PD = 1u; \
                                        }while (0u)

/*--- INT20_1 ---*/
#define SetPinFunc_INT20_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR8_P0 = 1u; \
                                        }while (0u)

/*--- INT20_2 ---*/
#define SetPinFunc_INT20_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_PB = 1u; \
                                        }while (0u)

/*--- INT21_0 ---*/
#define SetPinFunc_INT21_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PE = 1u; \
                                        }while (0u)

/*--- INT21_1 ---*/
#define SetPinFunc_INT21_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PA = 1u; \
                                        }while (0u)

/*--- INT21_2 ---*/
#define SetPinFunc_INT21_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_PC = 1u; \
                                        }while (0u)

/*--- INT22_0 ---*/
#define SetPinFunc_INT22_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P7 = 1u; \
                                        }while (0u)

/*--- INT22_1 ---*/
#define SetPinFunc_INT22_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PB = 1u; \
                                        }while (0u)

/*--- INT22_2 ---*/
#define SetPinFunc_INT22_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN13=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_PD = 1u; \
                                        }while (0u)

/*--- INT23_0 ---*/
#define SetPinFunc_INT23_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 14u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P5 = 1u; \
                                        }while (0u)

/*--- INT23_1 ---*/
#define SetPinFunc_INT23_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 14u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- INT23_2 ---*/
#define SetPinFunc_INT23_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR15, 14u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- LVDI ---*/
#define SetPinFunc_LVDI(dummy)          do{ \
                                            bFM_GPIO_PFR4_P5 = 1u; \
                                        }while (0u)

/*--- MI2SCK5_0 ---*/
#define SetPinFunc_MI2SCK5_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- MI2SCK6_1 ---*/
#define SetPinFunc_MI2SCK6_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P1 = 1u; \
                                        }while (0u)

/*--- MI2SDI5_0 ---*/
#define SetPinFunc_MI2SDI5_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- MI2SDI6_1 ---*/
#define SetPinFunc_MI2SDI6_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- MI2SDO5_0 ---*/
#define SetPinFunc_MI2SDO5_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- MI2SDO6_1 ---*/
#define SetPinFunc_MI2SDO6_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P2 = 1u; \
                                        }while (0u)

/*--- MI2SMCK5_0_IN ---*/
#define SetPinFunc_MI2SMCK5_0_IN(dummy) do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- MI2SMCK5_0_OUT ---*/
#define SetPinFunc_MI2SMCK5_0_OUT(dummy)do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- MI2SMCK6_1_IN ---*/
#define SetPinFunc_MI2SMCK6_1_IN(dummy) do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- MI2SMCK6_1_OUT ---*/
#define SetPinFunc_MI2SMCK6_1_OUT(dummy)do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- MI2SWS5_0 ---*/
#define SetPinFunc_MI2SWS5_0(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR37, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P3 = 1u; \
                                        }while (0u)

/*--- MI2SWS6_1 ---*/
#define SetPinFunc_MI2SWS6_1(dummy)     do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR38, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P0 = 1u; \
                                        }while (0u)

/*--- NMIX ---*/
#define SetPinFunc_NMIX(dummy)          do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 0u, 1u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- RTCCO_0 ---*/
#define SetPinFunc_RTCCO_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- RTCCO_1 ---*/
#define SetPinFunc_RTCCO_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- RTCCO_2 ---*/
#define SetPinFunc_RTCCO_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- RTO00_0 ---*/
#define SetPinFunc_RTO00_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- RTO00_1 ---*/
#define SetPinFunc_RTO00_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- RTO01_0 ---*/
#define SetPinFunc_RTO01_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- RTO01_1 ---*/
#define SetPinFunc_RTO01_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P4 = 1u; \
                                        }while (0u)

/*--- RTO02_0 ---*/
#define SetPinFunc_RTO02_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- RTO02_1 ---*/
#define SetPinFunc_RTO02_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P5 = 1u; \
                                        }while (0u)

/*--- RTO03_0 ---*/
#define SetPinFunc_RTO03_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- RTO03_1 ---*/
#define SetPinFunc_RTO03_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P6 = 1u; \
                                        }while (0u)

/*--- RTO04_0 ---*/
#define SetPinFunc_RTO04_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- RTO04_1 ---*/
#define SetPinFunc_RTO04_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P7 = 1u; \
                                        }while (0u)

/*--- RTO05_0 ---*/
#define SetPinFunc_RTO05_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- RTO05_1 ---*/
#define SetPinFunc_RTO05_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P8 = 1u; \
                                        }while (0u)

/*--- RTS1_1 ---*/
#define SetPinFunc_RTS1_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR34, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- RTS1_2 ---*/
#define SetPinFunc_RTS1_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR34, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR4_P4 = 1u; \
                                        }while (0u)

/*--- RTS4_0 ---*/
#define SetPinFunc_RTS4_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PD = 1u; \
                                        }while (0u)

/*--- RTS4_1 ---*/
#define SetPinFunc_RTS4_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN14=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PE = 1u; \
                                        }while (0u)

/*--- RTS4_2 ---*/
#define SetPinFunc_RTS4_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 0u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P9 = 1u; \
                                        }while (0u)

/*--- SCK0_0 ---*/
#define SetPinFunc_SCK0_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- SCK0_1 ---*/
#define SetPinFunc_SCK0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P6 = 1u; \
                                        }while (0u)

/*--- SCK1_0 ---*/
#define SetPinFunc_SCK1_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 14u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P8 = 1u; \
                                        }while (0u)

/*--- SCK1_1 ---*/
#define SetPinFunc_SCK1_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 14u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- SCK1_2 ---*/
#define SetPinFunc_SCK1_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 14u, 2u,  3u ); \
                                            bFM_GPIO_PFR4_P2 = 1u; \
                                        }while (0u)

/*--- SCK2_0 ---*/
#define SetPinFunc_SCK2_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR7_P4 = 1u; \
                                        }while (0u)

/*--- SCK2_1 ---*/
#define SetPinFunc_SCK2_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P6 = 1u; \
                                        }while (0u)

/*--- SCK2_2 ---*/
#define SetPinFunc_SCK2_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN09=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 20u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_P9 = 1u; \
                                        }while (0u)

/*--- SCK3_0 ---*/
#define SetPinFunc_SCK3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P8 = 1u; \
                                        }while (0u)

/*--- SCK3_1 ---*/
#define SetPinFunc_SCK3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P2 = 1u; \
                                        }while (0u)

/*--- SCK3_2 ---*/
#define SetPinFunc_SCK3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- SCK4_0 ---*/
#define SetPinFunc_SCK4_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- SCK4_1 ---*/
#define SetPinFunc_SCK4_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN12=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PC = 1u; \
                                        }while (0u)

/*--- SCK4_2 ---*/
#define SetPinFunc_SCK4_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- SCK5_0 ---*/
#define SetPinFunc_SCK5_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 14u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- SCK5_1 ---*/
#define SetPinFunc_SCK5_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 14u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P5 = 1u; \
                                        }while (0u)

/*--- SCK5_2 ---*/
#define SetPinFunc_SCK5_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 14u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P8 = 1u; \
                                        }while (0u)

/*--- SCK6_0 ---*/
#define SetPinFunc_SCK6_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P5 = 1u; \
                                        }while (0u)

/*--- SCK6_1 ---*/
#define SetPinFunc_SCK6_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P1 = 1u; \
                                        }while (0u)

/*--- SCK7_0 ---*/
#define SetPinFunc_SCK7_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_PB = 1u; \
                                        }while (0u)

/*--- SCK7_1 ---*/
#define SetPinFunc_SCK7_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PD = 1u; \
                                        }while (0u)

/*--- SCK7_2 ---*/
#define SetPinFunc_SCK7_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR8_P2 = 1u; \
                                        }while (0u)

/*--- SCS60_1 ---*/
#define SetPinFunc_SCS60_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P0 = 1u; \
                                        }while (0u)

/*--- SCS61_1 ---*/
#define SetPinFunc_SCS61_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P4 = 1u; \
                                        }while (0u)

/*--- SCS62_1 ---*/
#define SetPinFunc_SCS62_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P5 = 1u; \
                                        }while (0u)

/*--- SCS70_1 ---*/
#define SetPinFunc_SCS70_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PA = 1u; \
                                        }while (0u)

/*--- SCS71_1 ---*/
#define SetPinFunc_SCS71_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR7_P0 = 1u; \
                                        }while (0u)

/*--- SCS72_1 ---*/
#define SetPinFunc_SCS72_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR23, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR7_P1 = 1u; \
                                        }while (0u)

/*--- SIN0_0 ---*/
#define SetPinFunc_SIN0_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- SIN0_1 ---*/
#define SetPinFunc_SIN0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- SIN1_0 ---*/
#define SetPinFunc_SIN1_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- SIN1_1 ---*/
#define SetPinFunc_SIN1_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- SIN1_2 ---*/
#define SetPinFunc_SIN1_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR4_P0 = 1u; \
                                        }while (0u)

/*--- SIN2_0 ---*/
#define SetPinFunc_SIN2_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR7_P2 = 1u; \
                                        }while (0u)

/*--- SIN2_1 ---*/
#define SetPinFunc_SIN2_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P4 = 1u; \
                                        }while (0u)

/*--- SIN2_2 ---*/
#define SetPinFunc_SIN2_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 16u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_P7 = 1u; \
                                        }while (0u)

/*--- SIN3_0 ---*/
#define SetPinFunc_SIN3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P6 = 1u; \
                                        }while (0u)

/*--- SIN3_1 ---*/
#define SetPinFunc_SIN3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- SIN3_2 ---*/
#define SetPinFunc_SIN3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P2 = 1u; \
                                        }while (0u)

/*--- SIN4_0 ---*/
#define SetPinFunc_SIN4_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- SIN4_1 ---*/
#define SetPinFunc_SIN4_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN10=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PA = 1u; \
                                        }while (0u)

/*--- SIN4_2 ---*/
#define SetPinFunc_SIN4_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P5 = 1u; \
                                        }while (0u)

/*--- SIN5_0 ---*/
#define SetPinFunc_SIN5_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- SIN5_1 ---*/
#define SetPinFunc_SIN5_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P3 = 1u; \
                                        }while (0u)

/*--- SIN5_2 ---*/
#define SetPinFunc_SIN5_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P6 = 1u; \
                                        }while (0u)

/*--- SIN6_0 ---*/
#define SetPinFunc_SIN6_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P3 = 1u; \
                                        }while (0u)

/*--- SIN6_1 ---*/
#define SetPinFunc_SIN6_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- SIN7_0 ---*/
#define SetPinFunc_SIN7_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P9 = 1u; \
                                        }while (0u)

/*--- SIN7_1 ---*/
#define SetPinFunc_SIN7_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 22u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PB = 1u; \
                                        }while (0u)

/*--- SIN7_2 ---*/
#define SetPinFunc_SIN7_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 22u, 2u,  3u ); \
                                            bFM_GPIO_PFR8_P0 = 1u; \
                                        }while (0u)

/*--- SOT0_0 ---*/
#define SetPinFunc_SOT0_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- SOT0_1 ---*/
#define SetPinFunc_SOT0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- SOT1_0 ---*/
#define SetPinFunc_SOT1_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P7 = 1u; \
                                        }while (0u)

/*--- SOT1_1 ---*/
#define SetPinFunc_SOT1_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P2 = 1u; \
                                        }while (0u)

/*--- SOT1_2 ---*/
#define SetPinFunc_SOT1_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR4_P1 = 1u; \
                                        }while (0u)

/*--- SOT2_0 ---*/
#define SetPinFunc_SOT2_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR7_P3 = 1u; \
                                        }while (0u)

/*--- SOT2_1 ---*/
#define SetPinFunc_SOT2_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P5 = 1u; \
                                        }while (0u)

/*--- SOT2_2 ---*/
#define SetPinFunc_SOT2_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN08=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 18u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_P8 = 1u; \
                                        }while (0u)

/*--- SOT3_0 ---*/
#define SetPinFunc_SOT3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P7 = 1u; \
                                        }while (0u)

/*--- SOT3_1 ---*/
#define SetPinFunc_SOT3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P1 = 1u; \
                                        }while (0u)

/*--- SOT3_2 ---*/
#define SetPinFunc_SOT3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P0 = 1u; \
                                        }while (0u)

/*--- SOT4_0 ---*/
#define SetPinFunc_SOT4_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN22=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_P7 = 1u; \
                                        }while (0u)

/*--- SOT4_1 ---*/
#define SetPinFunc_SOT4_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN11=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_PB = 1u; \
                                        }while (0u)

/*--- SOT4_2 ---*/
#define SetPinFunc_SOT4_2(dummy)        do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P6 = 1u; \
                                        }while (0u)

/*--- SOT5_0 ---*/
#define SetPinFunc_SOT5_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- SOT5_1 ---*/
#define SetPinFunc_SOT5_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P4 = 1u; \
                                        }while (0u)

/*--- SOT5_2 ---*/
#define SetPinFunc_SOT5_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_P7 = 1u; \
                                        }while (0u)

/*--- SOT6_0 ---*/
#define SetPinFunc_SOT6_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P4 = 1u; \
                                        }while (0u)

/*--- SOT6_1 ---*/
#define SetPinFunc_SOT6_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P2 = 1u; \
                                        }while (0u)

/*--- SOT7_0 ---*/
#define SetPinFunc_SOT7_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_PA = 1u; \
                                        }while (0u)

/*--- SOT7_1 ---*/
#define SetPinFunc_SOT7_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR4_PC = 1u; \
                                        }while (0u)

/*--- SOT7_2 ---*/
#define SetPinFunc_SOT7_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR08, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR8_P1 = 1u; \
                                        }while (0u)

/*--- SUBOUT_0 ---*/
#define SetPinFunc_SUBOUT_0(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- SUBOUT_1 ---*/
#define SetPinFunc_SUBOUT_1(dummy)      do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- SUBOUT_2 ---*/
#define SetPinFunc_SUBOUT_2(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- SWCLK ---*/
#define SetPinFunc_SWCLK(dummy)         do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 16u, 1u,  1u ); \
                                            bFM_GPIO_PFR0_P1 = 1u; \
                                        }while (0u)

/*--- SWDIO ---*/
#define SetPinFunc_SWDIO(dummy)         do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 16u, 1u,  1u ); \
                                            bFM_GPIO_PFR0_P3 = 1u; \
                                        }while (0u)

/*--- TIOA0_0_OUT ---*/
#define SetPinFunc_TIOA0_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P0 = 1u; \
                                        }while (0u)

/*--- TIOA0_1_OUT ---*/
#define SetPinFunc_TIOA0_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- TIOA0_2_OUT ---*/
#define SetPinFunc_TIOA0_2_OUT(dummy)   do{ \
                                            bFM_GPIO_ADE_AN23=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 2u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P8 = 1u; \
                                        }while (0u)

/*--- TIOA1_0_IN ---*/
#define SetPinFunc_TIOA1_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P1 = 1u; \
                                        }while (0u)

/*--- TIOA1_0_OUT ---*/
#define SetPinFunc_TIOA1_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P1 = 1u; \
                                        }while (0u)

/*--- TIOA1_1_IN ---*/
#define SetPinFunc_TIOA1_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- TIOA1_1_OUT ---*/
#define SetPinFunc_TIOA1_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- TIOA1_2_IN ---*/
#define SetPinFunc_TIOA1_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_P3 = 1u; \
                                        }while (0u)

/*--- TIOA1_2_OUT ---*/
#define SetPinFunc_TIOA1_2_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_P3 = 1u; \
                                        }while (0u)

/*--- TIOA2_0_OUT ---*/
#define SetPinFunc_TIOA2_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P2 = 1u; \
                                        }while (0u)

/*--- TIOA2_1_OUT ---*/
#define SetPinFunc_TIOA2_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- TIOA2_2_OUT ---*/
#define SetPinFunc_TIOA2_2_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 18u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- TIOA3_0_IN ---*/
#define SetPinFunc_TIOA3_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- TIOA3_0_OUT ---*/
#define SetPinFunc_TIOA3_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P3 = 1u; \
                                        }while (0u)

/*--- TIOA3_1_IN ---*/
#define SetPinFunc_TIOA3_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- TIOA3_1_OUT ---*/
#define SetPinFunc_TIOA3_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- TIOA3_2_IN ---*/
#define SetPinFunc_TIOA3_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_PD = 1u; \
                                        }while (0u)

/*--- TIOA3_2_OUT ---*/
#define SetPinFunc_TIOA3_2_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_PD = 1u; \
                                        }while (0u)

/*--- TIOA4_0_OUT ---*/
#define SetPinFunc_TIOA4_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P4 = 1u; \
                                        }while (0u)

/*--- TIOA4_1_OUT ---*/
#define SetPinFunc_TIOA4_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- TIOA4_2_OUT ---*/
#define SetPinFunc_TIOA4_2_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 2u, 2u,  3u ); \
                                            bFM_GPIO_PFR7_P0 = 1u; \
                                        }while (0u)

/*--- TIOA5_0_IN ---*/
#define SetPinFunc_TIOA5_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P5 = 1u; \
                                        }while (0u)

/*--- TIOA5_0_OUT ---*/
#define SetPinFunc_TIOA5_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_P5 = 1u; \
                                        }while (0u)

/*--- TIOA5_1_IN ---*/
#define SetPinFunc_TIOA5_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- TIOA5_1_OUT ---*/
#define SetPinFunc_TIOA5_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- TIOA5_2_IN ---*/
#define SetPinFunc_TIOA5_2_IN(dummy)    do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P5 = 1u; \
                                        }while (0u)

/*--- TIOA5_2_OUT ---*/
#define SetPinFunc_TIOA5_2_OUT(dummy)   do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 10u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P5 = 1u; \
                                        }while (0u)

/*--- TIOA6_0_OUT ---*/
#define SetPinFunc_TIOA6_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR7_P2 = 1u; \
                                        }while (0u)

/*--- TIOA6_1_OUT ---*/
#define SetPinFunc_TIOA6_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P2 = 1u; \
                                        }while (0u)

/*--- TIOA6_2_OUT ---*/
#define SetPinFunc_TIOA6_2_OUT(dummy)   do{ \
                                            bFM_GPIO_ADE_AN15=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 18u, 2u,  3u ); \
                                            bFM_GPIO_PFR2_P7 = 1u; \
                                        }while (0u)

/*--- TIOA7_0_IN ---*/
#define SetPinFunc_TIOA7_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P4 = 1u; \
                                        }while (0u)

/*--- TIOA7_0_OUT ---*/
#define SetPinFunc_TIOA7_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P4 = 1u; \
                                        }while (0u)

/*--- TIOA7_1_IN ---*/
#define SetPinFunc_TIOA7_1_IN(dummy)    do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- TIOA7_1_OUT ---*/
#define SetPinFunc_TIOA7_1_OUT(dummy)   do{ \
                                            bFM_GPIO_ADE_AN16=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- TIOA7_2_IN ---*/
#define SetPinFunc_TIOA7_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P7 = 1u; \
                                        }while (0u)

/*--- TIOA7_2_OUT ---*/
#define SetPinFunc_TIOA7_2_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P7 = 1u; \
                                        }while (0u)

/*--- TIOB0_0_IN ---*/
#define SetPinFunc_TIOB0_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 4u, 3u,  1u ); \
                                            bFM_GPIO_PFR4_PA = 1u; \
                                        }while (0u)

/*--- TIOB0_1_IN ---*/
#define SetPinFunc_TIOB0_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 4u, 3u,  2u ); \
                                            bFM_GPIO_PFR3_P0 = 1u; \
                                        }while (0u)

/*--- TIOB0_2_IN ---*/
#define SetPinFunc_TIOB0_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 4u, 3u,  3u ); \
                                            bFM_GPIO_PFR0_P9 = 1u; \
                                        }while (0u)

/*--- TIOB1_0_IN ---*/
#define SetPinFunc_TIOB1_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PB = 1u; \
                                        }while (0u)

/*--- TIOB1_1_IN ---*/
#define SetPinFunc_TIOB1_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P1 = 1u; \
                                        }while (0u)

/*--- TIOB1_2_IN ---*/
#define SetPinFunc_TIOB1_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR5_P4 = 1u; \
                                        }while (0u)

/*--- TIOB2_0_IN ---*/
#define SetPinFunc_TIOB2_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PC = 1u; \
                                        }while (0u)

/*--- TIOB2_1_IN ---*/
#define SetPinFunc_TIOB2_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P2 = 1u; \
                                        }while (0u)

/*--- TIOB2_2_IN ---*/
#define SetPinFunc_TIOB2_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 20u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- TIOB3_0_IN ---*/
#define SetPinFunc_TIOB3_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 28u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PD = 1u; \
                                        }while (0u)

/*--- TIOB3_1_IN ---*/
#define SetPinFunc_TIOB3_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 28u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P3 = 1u; \
                                        }while (0u)

/*--- TIOB3_2_IN ---*/
#define SetPinFunc_TIOB3_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 28u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_PE = 1u; \
                                        }while (0u)

/*--- TIOB4_0_IN ---*/
#define SetPinFunc_TIOB4_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- TIOB4_1_IN ---*/
#define SetPinFunc_TIOB4_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P4 = 1u; \
                                        }while (0u)

/*--- TIOB4_2_IN ---*/
#define SetPinFunc_TIOB4_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR7_P1 = 1u; \
                                        }while (0u)

/*--- TIOB5_0_IN ---*/
#define SetPinFunc_TIOB5_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_P2 = 1u; \
                                        }while (0u)

/*--- TIOB5_1_IN ---*/
#define SetPinFunc_TIOB5_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_P5 = 1u; \
                                        }while (0u)

/*--- TIOB5_2_IN ---*/
#define SetPinFunc_TIOB5_2_IN(dummy)    do{ \
                                            bFM_GPIO_ADE_AN21=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR0_P6 = 1u; \
                                        }while (0u)

/*--- TIOB6_0_IN ---*/
#define SetPinFunc_TIOB6_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR7_P3 = 1u; \
                                        }while (0u)

/*--- TIOB6_1_IN ---*/
#define SetPinFunc_TIOB6_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 20u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P3 = 1u; \
                                        }while (0u)

/*--- TIOB6_2_IN ---*/
#define SetPinFunc_TIOB6_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 20u, 2u,  3u ); \
                                            bFM_GPIO_PFR2_P8 = 1u; \
                                        }while (0u)

/*--- TIOB7_0_IN ---*/
#define SetPinFunc_TIOB7_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 28u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P5 = 1u; \
                                        }while (0u)

/*--- TIOB7_1_IN ---*/
#define SetPinFunc_TIOB7_1_IN(dummy)    do{ \
                                            bFM_GPIO_ADE_AN17=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 28u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- TIOB7_2_IN ---*/
#define SetPinFunc_TIOB7_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR05, 28u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P8 = 1u; \
                                        }while (0u)

/*--- UDM0 ---*/
#define SetPinFunc_UDM0(dummy)          do{ \
                                            bFM_GPIO_SPSR_USB0C=1u; \
                                        }while (0u)

/*--- UDP0 ---*/
#define SetPinFunc_UDP0(dummy)          do{ \
                                            bFM_GPIO_SPSR_USB0C=1u; \
                                        }while (0u)

/*--- UHCONX0 ---*/
#define SetPinFunc_UHCONX0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 9u, 1u,  1u ); \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- VREGCTL ---*/
#define SetPinFunc_VREGCTL(dummy)       do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPFR_VPFR0=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while (0u)

/*--- VWAKEUP ---*/
#define SetPinFunc_VWAKEUP(dummy)       do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            bFM_RTC_VBPFR_VPFR1=0u; \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while (0u)

/*--- WKUP0 ---*/
#define SetPinFunc_WKUP0(dummy)         do{ \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- WKUP1 ---*/
#define SetPinFunc_WKUP1(dummy)         do{ \
                                            bFM_GPIO_ADE_AN01=0u; \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- WKUP10 ---*/
#define SetPinFunc_WKUP10(dummy)        do{ \
                                            bFM_GPIO_ADE_AN20=0u; \
                                            bFM_GPIO_PFR0_P5 = 1u; \
                                        }while (0u)

/*--- WKUP11 ---*/
#define SetPinFunc_WKUP11(dummy)        do{ \
                                            bFM_GPIO_PFR3_P6 = 1u; \
                                        }while (0u)

/*--- WKUP2 ---*/
#define SetPinFunc_WKUP2(dummy)         do{ \
                                            bFM_GPIO_ADE_AN18=0u; \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- WKUP3 ---*/
#define SetPinFunc_WKUP3(dummy)         do{ \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- WKUP4 ---*/
#define SetPinFunc_WKUP4(dummy)         do{ \
                                            bFM_GPIO_PFR3_P0 = 1u; \
                                        }while (0u)

/*--- WKUP5 ---*/
#define SetPinFunc_WKUP5(dummy)         do{ \
                                            bFM_GPIO_PFR0_PA = 1u; \
                                        }while (0u)

/*--- WKUP6 ---*/
#define SetPinFunc_WKUP6(dummy)         do{ \
                                            bFM_GPIO_PFR4_PD = 1u; \
                                        }while (0u)

/*--- WKUP7 ---*/
#define SetPinFunc_WKUP7(dummy)         do{ \
                                            bFM_GPIO_PFR4_PB = 1u; \
                                        }while (0u)

/*--- WKUP8 ---*/
#define SetPinFunc_WKUP8(dummy)         do{ \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- WKUP9 ---*/
#define SetPinFunc_WKUP9(dummy)         do{ \
                                            bFM_GPIO_PFR5_P6 = 1u; \
                                        }while (0u)

/*--- X0 ---*/
#define SetPinFunc_X0(dummy)            do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 1u); \
                                        }while (0u)

/*--- X0A ---*/
#define SetPinFunc_X0A(dummy)           do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while (0u)

/*--- X1 ---*/
#define SetPinFunc_X1(dummy)            do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 1u); \
                                        }while (0u)

/*--- X1A ---*/
#define SetPinFunc_X1A(dummy)           do{ \
                                            bFM_RTC_VDET_PON = 0u; \
                                            FM_RTC->WTCR20_f.PREAD = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                            PINCONFIG_SET_REG(FM_RTC->VBPFR, 4u, 2u, 0x00u); \
                                            FM_RTC->WTCR20_f.PWRITE = 1u; \
                                            while(0u != FM_RTC->WTCR10_f.TRANS){} \
                                        }while (0u)

/******************************************************************************
   ANALOG PINS
*******************************************************************************/

/*--- AN00 ---*/
#define SetPinFunc_AN00(dummy)          do{ \
                                            bFM_GPIO_ADE_AN00=1u; \
                                        }while (0u)

/*--- AN01 ---*/
#define SetPinFunc_AN01(dummy)          do{ \
                                            bFM_GPIO_ADE_AN01=1u; \
                                        }while (0u)

/*--- AN02 ---*/
#define SetPinFunc_AN02(dummy)          do{ \
                                            bFM_GPIO_ADE_AN02=1u; \
                                        }while (0u)

/*--- AN03 ---*/
#define SetPinFunc_AN03(dummy)          do{ \
                                            bFM_GPIO_ADE_AN03=1u; \
                                        }while (0u)

/*--- AN04 ---*/
#define SetPinFunc_AN04(dummy)          do{ \
                                            bFM_GPIO_ADE_AN04=1u; \
                                        }while (0u)

/*--- AN05 ---*/
#define SetPinFunc_AN05(dummy)          do{ \
                                            bFM_GPIO_ADE_AN05=1u; \
                                        }while (0u)

/*--- AN06 ---*/
#define SetPinFunc_AN06(dummy)          do{ \
                                            bFM_GPIO_ADE_AN06=1u; \
                                        }while (0u)

/*--- AN07 ---*/
#define SetPinFunc_AN07(dummy)          do{ \
                                            bFM_GPIO_ADE_AN07=1u; \
                                        }while (0u)

/*--- AN08 ---*/
#define SetPinFunc_AN08(dummy)          do{ \
                                            bFM_GPIO_ADE_AN08=1u; \
                                        }while (0u)

/*--- AN09 ---*/
#define SetPinFunc_AN09(dummy)          do{ \
                                            bFM_GPIO_ADE_AN09=1u; \
                                        }while (0u)

/*--- AN10 ---*/
#define SetPinFunc_AN10(dummy)          do{ \
                                            bFM_GPIO_ADE_AN10=1u; \
                                        }while (0u)

/*--- AN11 ---*/
#define SetPinFunc_AN11(dummy)          do{ \
                                            bFM_GPIO_ADE_AN11=1u; \
                                        }while (0u)

/*--- AN12 ---*/
#define SetPinFunc_AN12(dummy)          do{ \
                                            bFM_GPIO_ADE_AN12=1u; \
                                        }while (0u)

/*--- AN13 ---*/
#define SetPinFunc_AN13(dummy)          do{ \
                                            bFM_GPIO_ADE_AN13=1u; \
                                        }while (0u)

/*--- AN14 ---*/
#define SetPinFunc_AN14(dummy)          do{ \
                                            bFM_GPIO_ADE_AN14=1u; \
                                        }while (0u)

/*--- AN15 ---*/
#define SetPinFunc_AN15(dummy)          do{ \
                                            bFM_GPIO_ADE_AN15=1u; \
                                        }while (0u)

/*--- AN16 ---*/
#define SetPinFunc_AN16(dummy)          do{ \
                                            bFM_GPIO_ADE_AN16=1u; \
                                        }while (0u)

/*--- AN17 ---*/
#define SetPinFunc_AN17(dummy)          do{ \
                                            bFM_GPIO_ADE_AN17=1u; \
                                        }while (0u)

/*--- AN18 ---*/
#define SetPinFunc_AN18(dummy)          do{ \
                                            bFM_GPIO_ADE_AN18=1u; \
                                        }while (0u)

/*--- AN19 ---*/
#define SetPinFunc_AN19(dummy)          do{ \
                                            bFM_GPIO_ADE_AN19=1u; \
                                        }while (0u)

/*--- AN20 ---*/
#define SetPinFunc_AN20(dummy)          do{ \
                                            bFM_GPIO_ADE_AN20=1u; \
                                        }while (0u)

/*--- AN21 ---*/
#define SetPinFunc_AN21(dummy)          do{ \
                                            bFM_GPIO_ADE_AN21=1u; \
                                        }while (0u)

/*--- AN22 ---*/
#define SetPinFunc_AN22(dummy)          do{ \
                                            bFM_GPIO_ADE_AN22=1u; \
                                        }while (0u)

/*--- AN23 ---*/
#define SetPinFunc_AN23(dummy)          do{ \
                                            bFM_GPIO_ADE_AN23=1u; \
                                        }while (0u)

#endif // #ifndef __GPIO_S6E1B3XG_H__


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

