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
/** \file gpio_s6e1a1xc.h
 **
 ** Header file for S6E1A1XC GPIO functions, included in gpio.h
 **
 ** History:
 **   - 2015-12-04  2.0  NOSU	Clean ALL FM Series pin files
 **
 ** Timestamp:
 **   - 2015-12-16 18:30:17  Auto created by GpioHeaderGenerator Rev 1.0.0
 **
 ******************************************************************************/

#ifndef __GPIO_S6E1A1XC_H__
#define __GPIO_S6E1A1XC_H__

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

/*---- GPIO bit P21 ----*/
#define GPIO1PIN_P21_GET                ( bFM_GPIO_PDIR2_P1 )

#define GPIO1PIN_P21_PUT(v)             ( bFM_GPIO_PDOR2_P1=(v) )

#define GPIO1PIN_P21_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P21_INITIN(v) \
                                                           : GPIO1PIN_P21_INITOUT(v) )

#define GPIO1PIN_P21_INITIN(v)          do{ \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define GPIO1PIN_P21_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR2_P1=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- GPIO bit NP21 ----*/
#define GPIO1PIN_NP21_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P1)) )

#define GPIO1PIN_NP21_PUT(v)            ( bFM_GPIO_PDOR2_P1=(uint32_t)(!(v)) )

#define GPIO1PIN_NP21_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP21_INITIN(v) \
                                                           : GPIO1PIN_NP21_INITOUT(v) )

#define GPIO1PIN_NP21_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define GPIO1PIN_NP21_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR2_P1=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P1=1u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

/*---- GPIO bit P22 ----*/
#define GPIO1PIN_P22_GET                ( bFM_GPIO_PDIR2_P2 )

#define GPIO1PIN_P22_PUT(v)             ( bFM_GPIO_PDOR2_P2=(v) )

#define GPIO1PIN_P22_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P22_INITIN(v) \
                                                           : GPIO1PIN_P22_INITOUT(v) )

#define GPIO1PIN_P22_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define GPIO1PIN_P22_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PDOR2_P2=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- GPIO bit NP22 ----*/
#define GPIO1PIN_NP22_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P2)) )

#define GPIO1PIN_NP22_PUT(v)            ( bFM_GPIO_PDOR2_P2=(uint32_t)(!(v)) )

#define GPIO1PIN_NP22_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP22_INITIN(v) \
                                                           : GPIO1PIN_NP22_INITOUT(v) )

#define GPIO1PIN_NP22_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define GPIO1PIN_NP22_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PDOR2_P2=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P2=1u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

/*---- GPIO bit P23 ----*/
#define GPIO1PIN_P23_GET                ( bFM_GPIO_PDIR2_P3 )

#define GPIO1PIN_P23_PUT(v)             ( bFM_GPIO_PDOR2_P3=(v) )

#define GPIO1PIN_P23_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P23_INITIN(v) \
                                                           : GPIO1PIN_P23_INITOUT(v) )

#define GPIO1PIN_P23_INITIN(v)          do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define GPIO1PIN_P23_INITOUT(v)         do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PDOR2_P3=(v).bInitVal; \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

/*---- GPIO bit NP23 ----*/
#define GPIO1PIN_NP23_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR2_P3)) )

#define GPIO1PIN_NP23_PUT(v)            ( bFM_GPIO_PDOR2_P3=(uint32_t)(!(v)) )

#define GPIO1PIN_NP23_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP23_INITIN(v) \
                                                           : GPIO1PIN_NP23_INITOUT(v) )

#define GPIO1PIN_NP23_INITIN(v)         do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define GPIO1PIN_NP23_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PDOR2_P3=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

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

/*---- GPIO bit P46 ----*/
#define GPIO1PIN_P46_GET                ( bFM_GPIO_PDIR4_P6 )

#define GPIO1PIN_P46_PUT(v)             ( bFM_GPIO_PDOR4_P6=(v) )

#define GPIO1PIN_P46_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P46_INITIN(v) \
                                                           : GPIO1PIN_P46_INITOUT(v) )

#define GPIO1PIN_P46_INITIN(v)          do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P6=(v).bPullup; \
                                            bFM_GPIO_DDR4_P6=0u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

#define GPIO1PIN_P46_INITOUT(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PDOR4_P6=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P6=1u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

/*---- GPIO bit NP46 ----*/
#define GPIO1PIN_NP46_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P6)) )

#define GPIO1PIN_NP46_PUT(v)            ( bFM_GPIO_PDOR4_P6=(uint32_t)(!(v)) )

#define GPIO1PIN_NP46_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP46_INITIN(v) \
                                                           : GPIO1PIN_NP46_INITOUT(v) )

#define GPIO1PIN_NP46_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P6=(v).bPullup; \
                                            bFM_GPIO_DDR4_P6=0u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

#define GPIO1PIN_NP46_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PDOR4_P6=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P6=1u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

/*---- GPIO bit P47 ----*/
#define GPIO1PIN_P47_GET                ( bFM_GPIO_PDIR4_P7 )

#define GPIO1PIN_P47_PUT(v)             ( bFM_GPIO_PDOR4_P7=(v) )

#define GPIO1PIN_P47_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P47_INITIN(v) \
                                                           : GPIO1PIN_P47_INITOUT(v) )

#define GPIO1PIN_P47_INITIN(v)          do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P7=(v).bPullup; \
                                            bFM_GPIO_DDR4_P7=0u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

#define GPIO1PIN_P47_INITOUT(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PDOR4_P7=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P7=1u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

/*---- GPIO bit NP47 ----*/
#define GPIO1PIN_NP47_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P7)) )

#define GPIO1PIN_NP47_PUT(v)            ( bFM_GPIO_PDOR4_P7=(uint32_t)(!(v)) )

#define GPIO1PIN_NP47_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP47_INITIN(v) \
                                                           : GPIO1PIN_NP47_INITOUT(v) )

#define GPIO1PIN_NP47_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P7=(v).bPullup; \
                                            bFM_GPIO_DDR4_P7=0u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

#define GPIO1PIN_NP47_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PDOR4_P7=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P7=1u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

/*---- GPIO bit P49 ----*/
#define GPIO1PIN_P49_GET                ( bFM_GPIO_PDIR4_P9 )

#define GPIO1PIN_P49_PUT(v)             ( bFM_GPIO_PDOR4_P9=(v) )

#define GPIO1PIN_P49_INIT(v)            ( (0==(v).bOutput) ? GPIO1PIN_P49_INITIN(v) \
                                                           : GPIO1PIN_P49_INITOUT(v) )

#define GPIO1PIN_P49_INITIN(v)          do{ \
                                            bFM_GPIO_PCR4_P9=(v).bPullup; \
                                            bFM_GPIO_DDR4_P9=0u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

#define GPIO1PIN_P49_INITOUT(v)         do{ \
                                            bFM_GPIO_PDOR4_P9=(v).bInitVal; \
                                            bFM_GPIO_DDR4_P9=1u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

/*---- GPIO bit NP49 ----*/
#define GPIO1PIN_NP49_GET               ( (uint32_t)(!(uint32_t)(bFM_GPIO_PDIR4_P9)) )

#define GPIO1PIN_NP49_PUT(v)            ( bFM_GPIO_PDOR4_P9=(uint32_t)(!(v)) )

#define GPIO1PIN_NP49_INIT(v)           ( (0==(v).bOutput) ? GPIO1PIN_NP49_INITIN(v) \
                                                           : GPIO1PIN_NP49_INITOUT(v) )

#define GPIO1PIN_NP49_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P9=(v).bPullup; \
                                            bFM_GPIO_DDR4_P9=0u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

#define GPIO1PIN_NP49_INITOUT(v)        do{ \
                                            bFM_GPIO_PDOR4_P9=(uint32_t)(!((uint32_t)(v).bInitVal)); \
                                            bFM_GPIO_DDR4_P9=1u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

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

/*---- Fast GPIO bit P21 ----*/
#define FGPIO1PIN_P21_GET               ( FM_FASTIO->FPDIR2_f.P1 )

#define FGPIO1PIN_P21_PUT(v)            ( FM_FASTIO->FPDOR2_f.P1=(v) )

#define FGPIO1PIN_P21_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P21_INITIN(v) \
                                                           : FGPIO1PIN_P21_INITOUT(v) )

#define FGPIO1PIN_P21_INITIN(v)         do{ \
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define FGPIO1PIN_P21_INITOUT(v)        do{ \
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
                                            bFM_GPIO_PCR2_P1=(v).bPullup; \
                                            bFM_GPIO_DDR2_P1=0u; \
                                            bFM_GPIO_PFR2_P1=0u; }while(0u)

#define FGPIO1PIN_NP21_INITOUT(v)       do{ \
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
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define FGPIO1PIN_P22_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
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
                                            bFM_GPIO_ADE_AN07=0u; \
                                            bFM_GPIO_PCR2_P2=(v).bPullup; \
                                            bFM_GPIO_DDR2_P2=0u; \
                                            bFM_GPIO_PFR2_P2=0u; }while(0u)

#define FGPIO1PIN_NP22_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
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
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define FGPIO1PIN_P23_INITOUT(v)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
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
                                            bFM_GPIO_ADE_AN06=0u; \
                                            bFM_GPIO_PCR2_P3=(v).bPullup; \
                                            bFM_GPIO_DDR2_P3=0u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

#define FGPIO1PIN_NP23_INITOUT(v)       do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            FM_FASTIO->FPDOR2_f.P3=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER2_f.P3=1u; \
                                            bFM_GPIO_DDR2_P3=1u; \
                                            bFM_GPIO_PFR2_P3=0u; }while(0u)

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

/*---- Fast GPIO bit P46 ----*/
#define FGPIO1PIN_P46_GET               ( FM_FASTIO->FPDIR4_f.P6 )

#define FGPIO1PIN_P46_PUT(v)            ( FM_FASTIO->FPDOR4_f.P6=(v) )

#define FGPIO1PIN_P46_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P46_INITIN(v) \
                                                           : FGPIO1PIN_P46_INITOUT(v) )

#define FGPIO1PIN_P46_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P6=(v).bPullup; \
                                            bFM_GPIO_DDR4_P6=0u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

#define FGPIO1PIN_P46_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            FM_FASTIO->FPDOR4_f.P6=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P6=1u; \
                                            bFM_GPIO_DDR4_P6=1u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

/*---- Fast GPIO bit NP46 ----*/
#define FGPIO1PIN_NP46_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P6)) )

#define FGPIO1PIN_NP46_PUT(v)           ( FM_FASTIO->FPDOR4_f.P6=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP46_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP46_INITIN(v) \
                                                           : FGPIO1PIN_NP46_INITOUT(v) )

#define FGPIO1PIN_NP46_INITIN(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P6=(v).bPullup; \
                                            bFM_GPIO_DDR4_P6=0u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

#define FGPIO1PIN_NP46_INITOUT(v)       do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            FM_FASTIO->FPDOR4_f.P6=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P6=1u; \
                                            bFM_GPIO_DDR4_P6=1u; \
                                            bFM_GPIO_PFR4_P6=0u; }while(0u)

/*---- Fast GPIO bit P47 ----*/
#define FGPIO1PIN_P47_GET               ( FM_FASTIO->FPDIR4_f.P7 )

#define FGPIO1PIN_P47_PUT(v)            ( FM_FASTIO->FPDOR4_f.P7=(v) )

#define FGPIO1PIN_P47_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P47_INITIN(v) \
                                                           : FGPIO1PIN_P47_INITOUT(v) )

#define FGPIO1PIN_P47_INITIN(v)         do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P7=(v).bPullup; \
                                            bFM_GPIO_DDR4_P7=0u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

#define FGPIO1PIN_P47_INITOUT(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            FM_FASTIO->FPDOR4_f.P7=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P7=1u; \
                                            bFM_GPIO_DDR4_P7=1u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

/*---- Fast GPIO bit NP47 ----*/
#define FGPIO1PIN_NP47_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P7)) )

#define FGPIO1PIN_NP47_PUT(v)           ( FM_FASTIO->FPDOR4_f.P7=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP47_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP47_INITIN(v) \
                                                           : FGPIO1PIN_NP47_INITOUT(v) )

#define FGPIO1PIN_NP47_INITIN(v)        do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            bFM_GPIO_PCR4_P7=(v).bPullup; \
                                            bFM_GPIO_DDR4_P7=0u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

#define FGPIO1PIN_NP47_INITOUT(v)       do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 0u); \
                                            FM_FASTIO->FPDOR4_f.P7=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P7=1u; \
                                            bFM_GPIO_DDR4_P7=1u; \
                                            bFM_GPIO_PFR4_P7=0u; }while(0u)

/*---- Fast GPIO bit P49 ----*/
#define FGPIO1PIN_P49_GET               ( FM_FASTIO->FPDIR4_f.P9 )

#define FGPIO1PIN_P49_PUT(v)            ( FM_FASTIO->FPDOR4_f.P9=(v) )

#define FGPIO1PIN_P49_INIT(v)           ( (0==(v).bOutput) ? FGPIO1PIN_P49_INITIN(v) \
                                                           : FGPIO1PIN_P49_INITOUT(v) )

#define FGPIO1PIN_P49_INITIN(v)         do{ \
                                            bFM_GPIO_PCR4_P9=(v).bPullup; \
                                            bFM_GPIO_DDR4_P9=0u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

#define FGPIO1PIN_P49_INITOUT(v)        do{ \
                                            FM_FASTIO->FPDOR4_f.P9=(v).bInitVal; \
                                            FM_GPIO->FPOER4_f.P9=1u; \
                                            bFM_GPIO_DDR4_P9=1u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

/*---- Fast GPIO bit NP49 ----*/
#define FGPIO1PIN_NP49_GET              ( (uint8_t)(!(FM_FASTIO->FPDIR4_f.P9)) )

#define FGPIO1PIN_NP49_PUT(v)           ( FM_FASTIO->FPDOR4_f.P9=(uint8_t)(!(v)) )

#define FGPIO1PIN_NP49_INIT(v)          ( (0==(v).bOutput) ? FGPIO1PIN_NP49_INITIN(v) \
                                                           : FGPIO1PIN_NP49_INITOUT(v) )

#define FGPIO1PIN_NP49_INITIN(v)        do{ \
                                            bFM_GPIO_PCR4_P9=(v).bPullup; \
                                            bFM_GPIO_DDR4_P9=0u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

#define FGPIO1PIN_NP49_INITOUT(v)       do{ \
                                            FM_FASTIO->FPDOR4_f.P9=(uint8_t)(!((uint8_t)(v).bInitVal)); \
                                            FM_GPIO->FPOER4_f.P9=1u; \
                                            bFM_GPIO_DDR4_P9=1u; \
                                            bFM_GPIO_PFR4_P9=0u; }while(0u)

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

/*--- ADTG_1_ADC0 ---*/
#define SetPinFunc_ADTG_1_ADC0(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 12u, 4u,  2u ); \
                                            bFM_GPIO_PFRE_P0 = 1u; \
                                        }while (0u)

/*--- ADTG_1_ADC1 ---*/
#define SetPinFunc_ADTG_1_ADC1(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 16u, 4u,  2u ); \
                                            bFM_GPIO_PFRE_P0 = 1u; \
                                        }while (0u)

/*--- ADTG_1_ADC2 ---*/
#define SetPinFunc_ADTG_1_ADC2(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 20u, 4u,  2u ); \
                                            bFM_GPIO_PFRE_P0 = 1u; \
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

/*--- AIN0_0 ---*/
#define SetPinFunc_AIN0_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 0u, 2u,  1u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 0u, 1u,  0u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- AIN0_1 ---*/
#define SetPinFunc_AIN0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 0u, 2u,  2u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 0u, 1u,  0u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- AIN0_2 ---*/
#define SetPinFunc_AIN0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 0u, 2u,  3u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 0u, 1u,  0u ); \
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- AIN0_3 ---*/
#define SetPinFunc_AIN0_3(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 0u, 2u,  0u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 0u, 1u,  1u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- BIN0_0 ---*/
#define SetPinFunc_BIN0_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 2u, 2u,  1u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 1u, 1u,  0u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- BIN0_1 ---*/
#define SetPinFunc_BIN0_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 2u, 2u,  2u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 1u, 1u,  0u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- BIN0_2 ---*/
#define SetPinFunc_BIN0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 2u, 2u,  3u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 1u, 1u,  0u ); \
                                            bFM_GPIO_PFR5_P1 = 1u; \
                                        }while (0u)

/*--- BIN0_3 ---*/
#define SetPinFunc_BIN0_3(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 2u, 2u,  0u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 1u, 1u,  1u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- CROUT_1 ---*/
#define SetPinFunc_CROUT_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR00, 1u, 2u,  2u ); \
                                            bFM_GPIO_PFR0_PF = 1u; \
                                        }while (0u)

/*--- DTTI0X_0 ---*/
#define SetPinFunc_DTTI0X_0(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_P9 = 1u; \
                                        }while (0u)

/*--- DTTI0X_1 ---*/
#define SetPinFunc_DTTI0X_1(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  2u ); \
                                            bFM_GPIO_PFRE_P0 = 1u; \
                                        }while (0u)

/*--- DTTI0X_2 ---*/
#define SetPinFunc_DTTI0X_2(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 16u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- FRCK0_0 ---*/
#define SetPinFunc_FRCK0_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- FRCK0_1 ---*/
#define SetPinFunc_FRCK0_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 18u, 2u,  2u ); \
                                            bFM_GPIO_PFR8_P0 = 1u; \
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
                                            bFM_GPIO_PFR6_P0 = 1u; \
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
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- IC01_1 ---*/
#define SetPinFunc_IC01_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 23u, 3u,  2u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
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
                                            bFM_GPIO_ADE_AN01=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  1u ); \
                                            bFM_GPIO_PFR1_P1 = 1u; \
                                        }while (0u)

/*--- IC02_1 ---*/
#define SetPinFunc_IC02_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 26u, 3u,  2u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
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

/*--- IC03_1 ---*/
#define SetPinFunc_IC03_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 29u, 3u,  2u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
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

/*--- IGTRG0_0 ---*/
#define SetPinFunc_IGTRG0_0(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 13u, 1u,  0u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- IGTRG0_1 ---*/
#define SetPinFunc_IGTRG0_1(dummy)      do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 13u, 1u,  1u ); \
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- INT00_0 ---*/
#define SetPinFunc_INT00_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 0u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- INT00_1 ---*/
#define SetPinFunc_INT00_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN03=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 0u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P3 = 1u; \
                                        }while (0u)

/*--- INT01_0 ---*/
#define SetPinFunc_INT01_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR5_P1 = 1u; \
                                        }while (0u)

/*--- INT01_1 ---*/
#define SetPinFunc_INT01_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN02=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P2 = 1u; \
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
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFRE_P0 = 1u; \
                                        }while (0u)

/*--- INT03_0 ---*/
#define SetPinFunc_INT03_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
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
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- INT04_0 ---*/
#define SetPinFunc_INT04_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- INT04_1 ---*/
#define SetPinFunc_INT04_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 8u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- INT05_0 ---*/
#define SetPinFunc_INT05_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- INT05_1 ---*/
#define SetPinFunc_INT05_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 10u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- INT06_0 ---*/
#define SetPinFunc_INT06_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- INT06_1 ---*/
#define SetPinFunc_INT06_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- INT15_0 ---*/
#define SetPinFunc_INT15_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- INT15_1 ---*/
#define SetPinFunc_INT15_1(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  2u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- INT15_2 ---*/
#define SetPinFunc_INT15_2(dummy)       do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR06, 30u, 2u,  3u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
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

/*--- RTO01_0 ---*/
#define SetPinFunc_RTO01_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 2u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- RTO02_0 ---*/
#define SetPinFunc_RTO02_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- RTO03_0 ---*/
#define SetPinFunc_RTO03_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- RTO04_0 ---*/
#define SetPinFunc_RTO04_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- RTO05_0 ---*/
#define SetPinFunc_RTO05_0(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR01, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- SCK0_0 ---*/
#define SetPinFunc_SCK0_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
                                        }while (0u)

/*--- SCK0_2 ---*/
#define SetPinFunc_SCK0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 8u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
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
                                            bFM_GPIO_PFR8_P0 = 1u; \
                                        }while (0u)

/*--- SCK3_0 ---*/
#define SetPinFunc_SCK3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  1u ); \
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- SCK3_1 ---*/
#define SetPinFunc_SCK3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P2 = 1u; \
                                        }while (0u)

/*--- SCK3_2 ---*/
#define SetPinFunc_SCK3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 26u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PD = 1u; \
                                        }while (0u)

/*--- SCS10_1 ---*/
#define SetPinFunc_SCS10_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- SCS10_2 ---*/
#define SetPinFunc_SCS10_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- SCS11_1 ---*/
#define SetPinFunc_SCS11_1(dummy)       do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- SCS11_2 ---*/
#define SetPinFunc_SCS11_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- SCS30_2 ---*/
#define SetPinFunc_SCS30_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 12u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
                                        }while (0u)

/*--- SCS31_2 ---*/
#define SetPinFunc_SCS31_2(dummy)       do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR22, 14u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
                                        }while (0u)

/*--- SIN0_0 ---*/
#define SetPinFunc_SIN0_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 4u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- SIN0_1 ---*/
#define SetPinFunc_SIN0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN04=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 4u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P4 = 1u; \
                                        }while (0u)

/*--- SIN0_2 ---*/
#define SetPinFunc_SIN0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 4u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
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
                                            bFM_GPIO_PFR8_P2 = 1u; \
                                        }while (0u)

/*--- SIN3_0 ---*/
#define SetPinFunc_SIN3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P0 = 1u; \
                                        }while (0u)

/*--- SIN3_1 ---*/
#define SetPinFunc_SIN3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P0 = 1u; \
                                        }while (0u)

/*--- SIN3_2 ---*/
#define SetPinFunc_SIN3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 22u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- SOT0_0 ---*/
#define SetPinFunc_SOT0_0(dummy)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 6u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- SOT0_1 ---*/
#define SetPinFunc_SOT0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN05=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 6u, 2u,  2u ); \
                                            bFM_GPIO_PFR1_P5 = 1u; \
                                        }while (0u)

/*--- SOT0_2 ---*/
#define SetPinFunc_SOT0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 6u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PB = 1u; \
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
                                            bFM_GPIO_PFR8_P1 = 1u; \
                                        }while (0u)

/*--- SOT3_0 ---*/
#define SetPinFunc_SOT3_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  1u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- SOT3_1 ---*/
#define SetPinFunc_SOT3_1(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  2u ); \
                                            bFM_GPIO_PFR5_P1 = 1u; \
                                        }while (0u)

/*--- SOT3_2 ---*/
#define SetPinFunc_SOT3_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR07, 24u, 2u,  3u ); \
                                            bFM_GPIO_PFR3_PE = 1u; \
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
                                            bFM_GPIO_PFR3_PE = 1u; \
                                        }while (0u)

/*--- TIOA0_1_OUT ---*/
#define SetPinFunc_TIOA0_1_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 2u, 2u,  2u ); \
                                            bFM_GPIO_PFR3_PA = 1u; \
                                        }while (0u)

/*--- TIOA1_0_IN ---*/
#define SetPinFunc_TIOA1_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 8u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- TIOA1_0_OUT ---*/
#define SetPinFunc_TIOA1_0_OUT(dummy)   do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 10u, 2u,  1u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
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

/*--- TIOA2_0_OUT ---*/
#define SetPinFunc_TIOA2_0_OUT(dummy)   do{ \
                                            bFM_GPIO_ADE_AN06=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 18u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P3 = 1u; \
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

/*--- TIOB0_0_IN ---*/
#define SetPinFunc_TIOB0_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 4u, 3u,  1u ); \
                                            bFM_GPIO_PFR4_P9 = 1u; \
                                        }while (0u)

/*--- TIOB0_1_IN ---*/
#define SetPinFunc_TIOB0_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 4u, 3u,  2u ); \
                                            bFM_GPIO_PFR0_P4 = 1u; \
                                        }while (0u)

/*--- TIOB1_0_IN ---*/
#define SetPinFunc_TIOB1_0_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 12u, 2u,  1u ); \
                                            bFM_GPIO_PFR4_PA = 1u; \
                                        }while (0u)

/*--- TIOB1_1_IN ---*/
#define SetPinFunc_TIOB1_1_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 12u, 2u,  2u ); \
                                            bFM_GPIO_PFR2_P1 = 1u; \
                                        }while (0u)

/*--- TIOB2_0_IN ---*/
#define SetPinFunc_TIOB2_0_IN(dummy)    do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 20u, 2u,  1u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- TIOB2_2_IN ---*/
#define SetPinFunc_TIOB2_2_IN(dummy)    do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR04, 20u, 2u,  3u ); \
                                            bFM_GPIO_PFR6_P1 = 1u; \
                                        }while (0u)

/*--- X0 ---*/
#define SetPinFunc_X0(dummy)            do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 1u); \
                                        }while (0u)

/*--- X0A ---*/
#define SetPinFunc_X0A(dummy)           do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 1u); \
                                        }while (0u)

/*--- X1 ---*/
#define SetPinFunc_X1(dummy)            do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 2u, 2u, 1u); \
                                        }while (0u)

/*--- X1A ---*/
#define SetPinFunc_X1A(dummy)           do{ \
                                            PINCONFIG_SET_REG(FM_GPIO->SPSR, 0u, 2u, 1u); \
                                        }while (0u)

/*--- ZIN0_0 ---*/
#define SetPinFunc_ZIN0_0(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 4u, 2u,  1u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 2u, 1u,  0u ); \
                                            bFM_GPIO_PFR3_PF = 1u; \
                                        }while (0u)

/*--- ZIN0_1 ---*/
#define SetPinFunc_ZIN0_1(dummy)        do{ \
                                            bFM_GPIO_ADE_AN07=0u; \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 4u, 2u,  2u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 2u, 1u,  0u ); \
                                            bFM_GPIO_PFR2_P2 = 1u; \
                                        }while (0u)

/*--- ZIN0_2 ---*/
#define SetPinFunc_ZIN0_2(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 4u, 2u,  3u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 2u, 1u,  0u ); \
                                            bFM_GPIO_PFR5_P2 = 1u; \
                                        }while (0u)

/*--- ZIN0_3 ---*/
#define SetPinFunc_ZIN0_3(dummy)        do{ \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR09, 4u, 2u,  0u ); \
                                            PINRELOC_SET_EPFR( FM_GPIO->EPFR21, 2u, 1u,  1u ); \
                                            bFM_GPIO_PFR3_PC = 1u; \
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

#endif // #ifndef __GPIO_S6E1A1XC_H__


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

