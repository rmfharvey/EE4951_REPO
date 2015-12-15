/** ###################################################################
 **     Filename    : PORTC_Init.c
 **     Processor   : MK22FN512LL12_4SDK
 **     Abstract    :
 **          This file implements the PORTC module initialization
 **          according to the Peripheral Initialization settings, and
 **          defines interrupt service routines prototypes.
 **
 **     Contents    :
 **         Int   - void PORTC_Init(void);
 **
 **     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
 **     All Rights Reserved.
 **
 **     Redistribution and use in source and binary forms, with or without modification,
 **     are permitted provided that the following conditions are met:
 **
 **     o Redistributions of source code must retain the above copyright notice, this list
 **       of conditions and the following disclaimer.
 **
 **     o Redistributions in binary form must reproduce the above copyright notice, this
 **       list of conditions and the following disclaimer in the documentation and/or
 **       other materials provided with the distribution.
 **
 **     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 **       contributors may be used to endorse or promote products derived from this
 **       software without specific prior written permission.
 **
 **     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 **     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 **     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 **     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 **     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 **     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 **     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 **     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 **     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 **     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **     http: www.freescale.com
 **     mail: support@freescale.com
 ** ###################################################################*/

/*!
 * @file PORTC_Init.c
 * @brief This file implements the PORTC module initialization according to the
 *        Peripheral Initialization settings, and defines interrupt service
 *        routines prototypes.
 */


/* MODULE PORTC_Init. */

#include "PORTC_Init.h"
#include "fsl_device_registers.h"
#include "Init_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

void PORTC_Init(void) {

  /* Register 'PORTC_PCR0' initialization */
  #if PORTC_PCR0_MASK_1
    #if PORTC_PCR0_MASK_1 == 0xFFFFFFFF
  PORTC_PCR0 = PORTC_PCR0_VALUE_1;
    #elif PORTC_PCR0_MASK_1 == PORTC_PCR0_VALUE_1
  PORTC_PCR0 |= PORTC_PCR0_VALUE_1;
    #elif PORTC_PCR0_VALUE_1 == 0
  PORTC_PCR0 &= ~PORTC_PCR0_MASK_1;
    #else
  PORTC_PCR0 = (PORTC_PCR0 & (~PORTC_PCR0_MASK_1)) | PORTC_PCR0_VALUE_1;
    #endif
  #elif defined(PORTC_PCR0_VALUE_1)
  PORTC_PCR0 = PORTC_PCR0_VALUE_1;
  #endif

  /* Register 'PORTC_PCR1' initialization */
  #if PORTC_PCR1_MASK_1
    #if PORTC_PCR1_MASK_1 == 0xFFFFFFFF
  PORTC_PCR1 = PORTC_PCR1_VALUE_1;
    #elif PORTC_PCR1_MASK_1 == PORTC_PCR1_VALUE_1
  PORTC_PCR1 |= PORTC_PCR1_VALUE_1;
    #elif PORTC_PCR1_VALUE_1 == 0
  PORTC_PCR1 &= ~PORTC_PCR1_MASK_1;
    #else
  PORTC_PCR1 = (PORTC_PCR1 & (~PORTC_PCR1_MASK_1)) | PORTC_PCR1_VALUE_1;
    #endif
  #elif defined(PORTC_PCR1_VALUE_1)
  PORTC_PCR1 = PORTC_PCR1_VALUE_1;
  #endif

  /* Register 'PORTC_PCR2' initialization */
  #if PORTC_PCR2_MASK_1
    #if PORTC_PCR2_MASK_1 == 0xFFFFFFFF
  PORTC_PCR2 = PORTC_PCR2_VALUE_1;
    #elif PORTC_PCR2_MASK_1 == PORTC_PCR2_VALUE_1
  PORTC_PCR2 |= PORTC_PCR2_VALUE_1;
    #elif PORTC_PCR2_VALUE_1 == 0
  PORTC_PCR2 &= ~PORTC_PCR2_MASK_1;
    #else
  PORTC_PCR2 = (PORTC_PCR2 & (~PORTC_PCR2_MASK_1)) | PORTC_PCR2_VALUE_1;
    #endif
  #elif defined(PORTC_PCR2_VALUE_1)
  PORTC_PCR2 = PORTC_PCR2_VALUE_1;
  #endif

  /* Register 'PORTC_PCR3' initialization */
  #if PORTC_PCR3_MASK_1
    #if PORTC_PCR3_MASK_1 == 0xFFFFFFFF
  PORTC_PCR3 = PORTC_PCR3_VALUE_1;
    #elif PORTC_PCR3_MASK_1 == PORTC_PCR3_VALUE_1
  PORTC_PCR3 |= PORTC_PCR3_VALUE_1;
    #elif PORTC_PCR3_VALUE_1 == 0
  PORTC_PCR3 &= ~PORTC_PCR3_MASK_1;
    #else
  PORTC_PCR3 = (PORTC_PCR3 & (~PORTC_PCR3_MASK_1)) | PORTC_PCR3_VALUE_1;
    #endif
  #elif defined(PORTC_PCR3_VALUE_1)
  PORTC_PCR3 = PORTC_PCR3_VALUE_1;
  #endif

  /* Register 'PORTC_PCR4' initialization */
  #if PORTC_PCR4_MASK_1
    #if PORTC_PCR4_MASK_1 == 0xFFFFFFFF
  PORTC_PCR4 = PORTC_PCR4_VALUE_1;
    #elif PORTC_PCR4_MASK_1 == PORTC_PCR4_VALUE_1
  PORTC_PCR4 |= PORTC_PCR4_VALUE_1;
    #elif PORTC_PCR4_VALUE_1 == 0
  PORTC_PCR4 &= ~PORTC_PCR4_MASK_1;
    #else
  PORTC_PCR4 = (PORTC_PCR4 & (~PORTC_PCR4_MASK_1)) | PORTC_PCR4_VALUE_1;
    #endif
  #elif defined(PORTC_PCR4_VALUE_1)
  PORTC_PCR4 = PORTC_PCR4_VALUE_1;
  #endif

  /* Register 'PORTC_PCR5' initialization */
  #if PORTC_PCR5_MASK_1
    #if PORTC_PCR5_MASK_1 == 0xFFFFFFFF
  PORTC_PCR5 = PORTC_PCR5_VALUE_1;
    #elif PORTC_PCR5_MASK_1 == PORTC_PCR5_VALUE_1
  PORTC_PCR5 |= PORTC_PCR5_VALUE_1;
    #elif PORTC_PCR5_VALUE_1 == 0
  PORTC_PCR5 &= ~PORTC_PCR5_MASK_1;
    #else
  PORTC_PCR5 = (PORTC_PCR5 & (~PORTC_PCR5_MASK_1)) | PORTC_PCR5_VALUE_1;
    #endif
  #elif defined(PORTC_PCR5_VALUE_1)
  PORTC_PCR5 = PORTC_PCR5_VALUE_1;
  #endif

  /* Register 'PORTC_PCR6' initialization */
  #if PORTC_PCR6_MASK_1
    #if PORTC_PCR6_MASK_1 == 0xFFFFFFFF
  PORTC_PCR6 = PORTC_PCR6_VALUE_1;
    #elif PORTC_PCR6_MASK_1 == PORTC_PCR6_VALUE_1
  PORTC_PCR6 |= PORTC_PCR6_VALUE_1;
    #elif PORTC_PCR6_VALUE_1 == 0
  PORTC_PCR6 &= ~PORTC_PCR6_MASK_1;
    #else
  PORTC_PCR6 = (PORTC_PCR6 & (~PORTC_PCR6_MASK_1)) | PORTC_PCR6_VALUE_1;
    #endif
  #elif defined(PORTC_PCR6_VALUE_1)
  PORTC_PCR6 = PORTC_PCR6_VALUE_1;
  #endif

  /* Register 'PORTC_PCR7' initialization */
  #if PORTC_PCR7_MASK_1
    #if PORTC_PCR7_MASK_1 == 0xFFFFFFFF
  PORTC_PCR7 = PORTC_PCR7_VALUE_1;
    #elif PORTC_PCR7_MASK_1 == PORTC_PCR7_VALUE_1
  PORTC_PCR7 |= PORTC_PCR7_VALUE_1;
    #elif PORTC_PCR7_VALUE_1 == 0
  PORTC_PCR7 &= ~PORTC_PCR7_MASK_1;
    #else
  PORTC_PCR7 = (PORTC_PCR7 & (~PORTC_PCR7_MASK_1)) | PORTC_PCR7_VALUE_1;
    #endif
  #elif defined(PORTC_PCR7_VALUE_1)
  PORTC_PCR7 = PORTC_PCR7_VALUE_1;
  #endif

  /* Register 'PORTC_PCR8' initialization */
  #if PORTC_PCR8_MASK_1
    #if PORTC_PCR8_MASK_1 == 0xFFFFFFFF
  PORTC_PCR8 = PORTC_PCR8_VALUE_1;
    #elif PORTC_PCR8_MASK_1 == PORTC_PCR8_VALUE_1
  PORTC_PCR8 |= PORTC_PCR8_VALUE_1;
    #elif PORTC_PCR8_VALUE_1 == 0
  PORTC_PCR8 &= ~PORTC_PCR8_MASK_1;
    #else
  PORTC_PCR8 = (PORTC_PCR8 & (~PORTC_PCR8_MASK_1)) | PORTC_PCR8_VALUE_1;
    #endif
  #elif defined(PORTC_PCR8_VALUE_1)
  PORTC_PCR8 = PORTC_PCR8_VALUE_1;
  #endif

  /* Register 'PORTC_PCR9' initialization */
  #if PORTC_PCR9_MASK_1
    #if PORTC_PCR9_MASK_1 == 0xFFFFFFFF
  PORTC_PCR9 = PORTC_PCR9_VALUE_1;
    #elif PORTC_PCR9_MASK_1 == PORTC_PCR9_VALUE_1
  PORTC_PCR9 |= PORTC_PCR9_VALUE_1;
    #elif PORTC_PCR9_VALUE_1 == 0
  PORTC_PCR9 &= ~PORTC_PCR9_MASK_1;
    #else
  PORTC_PCR9 = (PORTC_PCR9 & (~PORTC_PCR9_MASK_1)) | PORTC_PCR9_VALUE_1;
    #endif
  #elif defined(PORTC_PCR9_VALUE_1)
  PORTC_PCR9 = PORTC_PCR9_VALUE_1;
  #endif

  /* Register 'PORTC_PCR10' initialization */
  #if PORTC_PCR10_MASK_1
    #if PORTC_PCR10_MASK_1 == 0xFFFFFFFF
  PORTC_PCR10 = PORTC_PCR10_VALUE_1;
    #elif PORTC_PCR10_MASK_1 == PORTC_PCR10_VALUE_1
  PORTC_PCR10 |= PORTC_PCR10_VALUE_1;
    #elif PORTC_PCR10_VALUE_1 == 0
  PORTC_PCR10 &= ~PORTC_PCR10_MASK_1;
    #else
  PORTC_PCR10 = (PORTC_PCR10 & (~PORTC_PCR10_MASK_1)) | PORTC_PCR10_VALUE_1;
    #endif
  #elif defined(PORTC_PCR10_VALUE_1)
  PORTC_PCR10 = PORTC_PCR10_VALUE_1;
  #endif

  /* Register 'PORTC_PCR11' initialization */
  #if PORTC_PCR11_MASK_1
    #if PORTC_PCR11_MASK_1 == 0xFFFFFFFF
  PORTC_PCR11 = PORTC_PCR11_VALUE_1;
    #elif PORTC_PCR11_MASK_1 == PORTC_PCR11_VALUE_1
  PORTC_PCR11 |= PORTC_PCR11_VALUE_1;
    #elif PORTC_PCR11_VALUE_1 == 0
  PORTC_PCR11 &= ~PORTC_PCR11_MASK_1;
    #else
  PORTC_PCR11 = (PORTC_PCR11 & (~PORTC_PCR11_MASK_1)) | PORTC_PCR11_VALUE_1;
    #endif
  #elif defined(PORTC_PCR11_VALUE_1)
  PORTC_PCR11 = PORTC_PCR11_VALUE_1;
  #endif

  /* Register 'PORTC_PCR12' initialization */
  #if PORTC_PCR12_MASK_1
    #if PORTC_PCR12_MASK_1 == 0xFFFFFFFF
  PORTC_PCR12 = PORTC_PCR12_VALUE_1;
    #elif PORTC_PCR12_MASK_1 == PORTC_PCR12_VALUE_1
  PORTC_PCR12 |= PORTC_PCR12_VALUE_1;
    #elif PORTC_PCR12_VALUE_1 == 0
  PORTC_PCR12 &= ~PORTC_PCR12_MASK_1;
    #else
  PORTC_PCR12 = (PORTC_PCR12 & (~PORTC_PCR12_MASK_1)) | PORTC_PCR12_VALUE_1;
    #endif
  #elif defined(PORTC_PCR12_VALUE_1)
  PORTC_PCR12 = PORTC_PCR12_VALUE_1;
  #endif

  /* Register 'PORTC_PCR13' initialization */
  #if PORTC_PCR13_MASK_1
    #if PORTC_PCR13_MASK_1 == 0xFFFFFFFF
  PORTC_PCR13 = PORTC_PCR13_VALUE_1;
    #elif PORTC_PCR13_MASK_1 == PORTC_PCR13_VALUE_1
  PORTC_PCR13 |= PORTC_PCR13_VALUE_1;
    #elif PORTC_PCR13_VALUE_1 == 0
  PORTC_PCR13 &= ~PORTC_PCR13_MASK_1;
    #else
  PORTC_PCR13 = (PORTC_PCR13 & (~PORTC_PCR13_MASK_1)) | PORTC_PCR13_VALUE_1;
    #endif
  #elif defined(PORTC_PCR13_VALUE_1)
  PORTC_PCR13 = PORTC_PCR13_VALUE_1;
  #endif

  /* Register 'PORTC_PCR14' initialization */
  #if PORTC_PCR14_MASK_1
    #if PORTC_PCR14_MASK_1 == 0xFFFFFFFF
  PORTC_PCR14 = PORTC_PCR14_VALUE_1;
    #elif PORTC_PCR14_MASK_1 == PORTC_PCR14_VALUE_1
  PORTC_PCR14 |= PORTC_PCR14_VALUE_1;
    #elif PORTC_PCR14_VALUE_1 == 0
  PORTC_PCR14 &= ~PORTC_PCR14_MASK_1;
    #else
  PORTC_PCR14 = (PORTC_PCR14 & (~PORTC_PCR14_MASK_1)) | PORTC_PCR14_VALUE_1;
    #endif
  #elif defined(PORTC_PCR14_VALUE_1)
  PORTC_PCR14 = PORTC_PCR14_VALUE_1;
  #endif

  /* Register 'PORTC_PCR15' initialization */
  #if PORTC_PCR15_MASK_1
    #if PORTC_PCR15_MASK_1 == 0xFFFFFFFF
  PORTC_PCR15 = PORTC_PCR15_VALUE_1;
    #elif PORTC_PCR15_MASK_1 == PORTC_PCR15_VALUE_1
  PORTC_PCR15 |= PORTC_PCR15_VALUE_1;
    #elif PORTC_PCR15_VALUE_1 == 0
  PORTC_PCR15 &= ~PORTC_PCR15_MASK_1;
    #else
  PORTC_PCR15 = (PORTC_PCR15 & (~PORTC_PCR15_MASK_1)) | PORTC_PCR15_VALUE_1;
    #endif
  #elif defined(PORTC_PCR15_VALUE_1)
  PORTC_PCR15 = PORTC_PCR15_VALUE_1;
  #endif

  /* Register 'PORTC_PCR16' initialization */
  #if PORTC_PCR16_MASK_1
    #if PORTC_PCR16_MASK_1 == 0xFFFFFFFF
  PORTC_PCR16 = PORTC_PCR16_VALUE_1;
    #elif PORTC_PCR16_MASK_1 == PORTC_PCR16_VALUE_1
  PORTC_PCR16 |= PORTC_PCR16_VALUE_1;
    #elif PORTC_PCR16_VALUE_1 == 0
  PORTC_PCR16 &= ~PORTC_PCR16_MASK_1;
    #else
  PORTC_PCR16 = (PORTC_PCR16 & (~PORTC_PCR16_MASK_1)) | PORTC_PCR16_VALUE_1;
    #endif
  #elif defined(PORTC_PCR16_VALUE_1)
  PORTC_PCR16 = PORTC_PCR16_VALUE_1;
  #endif

  /* Register 'PORTC_PCR17' initialization */
  #if PORTC_PCR17_MASK_1
    #if PORTC_PCR17_MASK_1 == 0xFFFFFFFF
  PORTC_PCR17 = PORTC_PCR17_VALUE_1;
    #elif PORTC_PCR17_MASK_1 == PORTC_PCR17_VALUE_1
  PORTC_PCR17 |= PORTC_PCR17_VALUE_1;
    #elif PORTC_PCR17_VALUE_1 == 0
  PORTC_PCR17 &= ~PORTC_PCR17_MASK_1;
    #else
  PORTC_PCR17 = (PORTC_PCR17 & (~PORTC_PCR17_MASK_1)) | PORTC_PCR17_VALUE_1;
    #endif
  #elif defined(PORTC_PCR17_VALUE_1)
  PORTC_PCR17 = PORTC_PCR17_VALUE_1;
  #endif

  /* Register 'PORTC_PCR18' initialization */
  #if PORTC_PCR18_MASK_1
    #if PORTC_PCR18_MASK_1 == 0xFFFFFFFF
  PORTC_PCR18 = PORTC_PCR18_VALUE_1;
    #elif PORTC_PCR18_MASK_1 == PORTC_PCR18_VALUE_1
  PORTC_PCR18 |= PORTC_PCR18_VALUE_1;
    #elif PORTC_PCR18_VALUE_1 == 0
  PORTC_PCR18 &= ~PORTC_PCR18_MASK_1;
    #else
  PORTC_PCR18 = (PORTC_PCR18 & (~PORTC_PCR18_MASK_1)) | PORTC_PCR18_VALUE_1;
    #endif
  #elif defined(PORTC_PCR18_VALUE_1)
  PORTC_PCR18 = PORTC_PCR18_VALUE_1;
  #endif

  /* Register 'PORTC_PCR0' initialization */
  #if PORTC_PCR0_MASK_2
    #if PORTC_PCR0_MASK_2 == 0xFFFFFFFF
  PORTC_PCR0 = PORTC_PCR0_VALUE_2;
    #elif PORTC_PCR0_MASK_2 == PORTC_PCR0_VALUE_2
  PORTC_PCR0 |= PORTC_PCR0_VALUE_2;
    #elif PORTC_PCR0_VALUE_2 == 0
  PORTC_PCR0 &= ~PORTC_PCR0_MASK_2;
    #else
  PORTC_PCR0 = (PORTC_PCR0 & (~PORTC_PCR0_MASK_2)) | PORTC_PCR0_VALUE_2;
    #endif
  #elif defined(PORTC_PCR0_VALUE_2)
  PORTC_PCR0 = PORTC_PCR0_VALUE_2;
  #endif

  /* Register 'PORTC_PCR1' initialization */
  #if PORTC_PCR1_MASK_2
    #if PORTC_PCR1_MASK_2 == 0xFFFFFFFF
  PORTC_PCR1 = PORTC_PCR1_VALUE_2;
    #elif PORTC_PCR1_MASK_2 == PORTC_PCR1_VALUE_2
  PORTC_PCR1 |= PORTC_PCR1_VALUE_2;
    #elif PORTC_PCR1_VALUE_2 == 0
  PORTC_PCR1 &= ~PORTC_PCR1_MASK_2;
    #else
  PORTC_PCR1 = (PORTC_PCR1 & (~PORTC_PCR1_MASK_2)) | PORTC_PCR1_VALUE_2;
    #endif
  #elif defined(PORTC_PCR1_VALUE_2)
  PORTC_PCR1 = PORTC_PCR1_VALUE_2;
  #endif

  /* Register 'PORTC_PCR2' initialization */
  #if PORTC_PCR2_MASK_2
    #if PORTC_PCR2_MASK_2 == 0xFFFFFFFF
  PORTC_PCR2 = PORTC_PCR2_VALUE_2;
    #elif PORTC_PCR2_MASK_2 == PORTC_PCR2_VALUE_2
  PORTC_PCR2 |= PORTC_PCR2_VALUE_2;
    #elif PORTC_PCR2_VALUE_2 == 0
  PORTC_PCR2 &= ~PORTC_PCR2_MASK_2;
    #else
  PORTC_PCR2 = (PORTC_PCR2 & (~PORTC_PCR2_MASK_2)) | PORTC_PCR2_VALUE_2;
    #endif
  #elif defined(PORTC_PCR2_VALUE_2)
  PORTC_PCR2 = PORTC_PCR2_VALUE_2;
  #endif

  /* Register 'PORTC_PCR3' initialization */
  #if PORTC_PCR3_MASK_2
    #if PORTC_PCR3_MASK_2 == 0xFFFFFFFF
  PORTC_PCR3 = PORTC_PCR3_VALUE_2;
    #elif PORTC_PCR3_MASK_2 == PORTC_PCR3_VALUE_2
  PORTC_PCR3 |= PORTC_PCR3_VALUE_2;
    #elif PORTC_PCR3_VALUE_2 == 0
  PORTC_PCR3 &= ~PORTC_PCR3_MASK_2;
    #else
  PORTC_PCR3 = (PORTC_PCR3 & (~PORTC_PCR3_MASK_2)) | PORTC_PCR3_VALUE_2;
    #endif
  #elif defined(PORTC_PCR3_VALUE_2)
  PORTC_PCR3 = PORTC_PCR3_VALUE_2;
  #endif

  /* Register 'PORTC_PCR4' initialization */
  #if PORTC_PCR4_MASK_2
    #if PORTC_PCR4_MASK_2 == 0xFFFFFFFF
  PORTC_PCR4 = PORTC_PCR4_VALUE_2;
    #elif PORTC_PCR4_MASK_2 == PORTC_PCR4_VALUE_2
  PORTC_PCR4 |= PORTC_PCR4_VALUE_2;
    #elif PORTC_PCR4_VALUE_2 == 0
  PORTC_PCR4 &= ~PORTC_PCR4_MASK_2;
    #else
  PORTC_PCR4 = (PORTC_PCR4 & (~PORTC_PCR4_MASK_2)) | PORTC_PCR4_VALUE_2;
    #endif
  #elif defined(PORTC_PCR4_VALUE_2)
  PORTC_PCR4 = PORTC_PCR4_VALUE_2;
  #endif

  /* Register 'PORTC_PCR5' initialization */
  #if PORTC_PCR5_MASK_2
    #if PORTC_PCR5_MASK_2 == 0xFFFFFFFF
  PORTC_PCR5 = PORTC_PCR5_VALUE_2;
    #elif PORTC_PCR5_MASK_2 == PORTC_PCR5_VALUE_2
  PORTC_PCR5 |= PORTC_PCR5_VALUE_2;
    #elif PORTC_PCR5_VALUE_2 == 0
  PORTC_PCR5 &= ~PORTC_PCR5_MASK_2;
    #else
  PORTC_PCR5 = (PORTC_PCR5 & (~PORTC_PCR5_MASK_2)) | PORTC_PCR5_VALUE_2;
    #endif
  #elif defined(PORTC_PCR5_VALUE_2)
  PORTC_PCR5 = PORTC_PCR5_VALUE_2;
  #endif

  /* Register 'PORTC_PCR6' initialization */
  #if PORTC_PCR6_MASK_2
    #if PORTC_PCR6_MASK_2 == 0xFFFFFFFF
  PORTC_PCR6 = PORTC_PCR6_VALUE_2;
    #elif PORTC_PCR6_MASK_2 == PORTC_PCR6_VALUE_2
  PORTC_PCR6 |= PORTC_PCR6_VALUE_2;
    #elif PORTC_PCR6_VALUE_2 == 0
  PORTC_PCR6 &= ~PORTC_PCR6_MASK_2;
    #else
  PORTC_PCR6 = (PORTC_PCR6 & (~PORTC_PCR6_MASK_2)) | PORTC_PCR6_VALUE_2;
    #endif
  #elif defined(PORTC_PCR6_VALUE_2)
  PORTC_PCR6 = PORTC_PCR6_VALUE_2;
  #endif

  /* Register 'PORTC_PCR7' initialization */
  #if PORTC_PCR7_MASK_2
    #if PORTC_PCR7_MASK_2 == 0xFFFFFFFF
  PORTC_PCR7 = PORTC_PCR7_VALUE_2;
    #elif PORTC_PCR7_MASK_2 == PORTC_PCR7_VALUE_2
  PORTC_PCR7 |= PORTC_PCR7_VALUE_2;
    #elif PORTC_PCR7_VALUE_2 == 0
  PORTC_PCR7 &= ~PORTC_PCR7_MASK_2;
    #else
  PORTC_PCR7 = (PORTC_PCR7 & (~PORTC_PCR7_MASK_2)) | PORTC_PCR7_VALUE_2;
    #endif
  #elif defined(PORTC_PCR7_VALUE_2)
  PORTC_PCR7 = PORTC_PCR7_VALUE_2;
  #endif

  /* Register 'PORTC_PCR8' initialization */
  #if PORTC_PCR8_MASK_2
    #if PORTC_PCR8_MASK_2 == 0xFFFFFFFF
  PORTC_PCR8 = PORTC_PCR8_VALUE_2;
    #elif PORTC_PCR8_MASK_2 == PORTC_PCR8_VALUE_2
  PORTC_PCR8 |= PORTC_PCR8_VALUE_2;
    #elif PORTC_PCR8_VALUE_2 == 0
  PORTC_PCR8 &= ~PORTC_PCR8_MASK_2;
    #else
  PORTC_PCR8 = (PORTC_PCR8 & (~PORTC_PCR8_MASK_2)) | PORTC_PCR8_VALUE_2;
    #endif
  #elif defined(PORTC_PCR8_VALUE_2)
  PORTC_PCR8 = PORTC_PCR8_VALUE_2;
  #endif

  /* Register 'PORTC_PCR9' initialization */
  #if PORTC_PCR9_MASK_2
    #if PORTC_PCR9_MASK_2 == 0xFFFFFFFF
  PORTC_PCR9 = PORTC_PCR9_VALUE_2;
    #elif PORTC_PCR9_MASK_2 == PORTC_PCR9_VALUE_2
  PORTC_PCR9 |= PORTC_PCR9_VALUE_2;
    #elif PORTC_PCR9_VALUE_2 == 0
  PORTC_PCR9 &= ~PORTC_PCR9_MASK_2;
    #else
  PORTC_PCR9 = (PORTC_PCR9 & (~PORTC_PCR9_MASK_2)) | PORTC_PCR9_VALUE_2;
    #endif
  #elif defined(PORTC_PCR9_VALUE_2)
  PORTC_PCR9 = PORTC_PCR9_VALUE_2;
  #endif

  /* Register 'PORTC_PCR10' initialization */
  #if PORTC_PCR10_MASK_2
    #if PORTC_PCR10_MASK_2 == 0xFFFFFFFF
  PORTC_PCR10 = PORTC_PCR10_VALUE_2;
    #elif PORTC_PCR10_MASK_2 == PORTC_PCR10_VALUE_2
  PORTC_PCR10 |= PORTC_PCR10_VALUE_2;
    #elif PORTC_PCR10_VALUE_2 == 0
  PORTC_PCR10 &= ~PORTC_PCR10_MASK_2;
    #else
  PORTC_PCR10 = (PORTC_PCR10 & (~PORTC_PCR10_MASK_2)) | PORTC_PCR10_VALUE_2;
    #endif
  #elif defined(PORTC_PCR10_VALUE_2)
  PORTC_PCR10 = PORTC_PCR10_VALUE_2;
  #endif

  /* Register 'PORTC_PCR11' initialization */
  #if PORTC_PCR11_MASK_2
    #if PORTC_PCR11_MASK_2 == 0xFFFFFFFF
  PORTC_PCR11 = PORTC_PCR11_VALUE_2;
    #elif PORTC_PCR11_MASK_2 == PORTC_PCR11_VALUE_2
  PORTC_PCR11 |= PORTC_PCR11_VALUE_2;
    #elif PORTC_PCR11_VALUE_2 == 0
  PORTC_PCR11 &= ~PORTC_PCR11_MASK_2;
    #else
  PORTC_PCR11 = (PORTC_PCR11 & (~PORTC_PCR11_MASK_2)) | PORTC_PCR11_VALUE_2;
    #endif
  #elif defined(PORTC_PCR11_VALUE_2)
  PORTC_PCR11 = PORTC_PCR11_VALUE_2;
  #endif

  /* Register 'PORTC_PCR12' initialization */
  #if PORTC_PCR12_MASK_2
    #if PORTC_PCR12_MASK_2 == 0xFFFFFFFF
  PORTC_PCR12 = PORTC_PCR12_VALUE_2;
    #elif PORTC_PCR12_MASK_2 == PORTC_PCR12_VALUE_2
  PORTC_PCR12 |= PORTC_PCR12_VALUE_2;
    #elif PORTC_PCR12_VALUE_2 == 0
  PORTC_PCR12 &= ~PORTC_PCR12_MASK_2;
    #else
  PORTC_PCR12 = (PORTC_PCR12 & (~PORTC_PCR12_MASK_2)) | PORTC_PCR12_VALUE_2;
    #endif
  #elif defined(PORTC_PCR12_VALUE_2)
  PORTC_PCR12 = PORTC_PCR12_VALUE_2;
  #endif

  /* Register 'PORTC_PCR13' initialization */
  #if PORTC_PCR13_MASK_2
    #if PORTC_PCR13_MASK_2 == 0xFFFFFFFF
  PORTC_PCR13 = PORTC_PCR13_VALUE_2;
    #elif PORTC_PCR13_MASK_2 == PORTC_PCR13_VALUE_2
  PORTC_PCR13 |= PORTC_PCR13_VALUE_2;
    #elif PORTC_PCR13_VALUE_2 == 0
  PORTC_PCR13 &= ~PORTC_PCR13_MASK_2;
    #else
  PORTC_PCR13 = (PORTC_PCR13 & (~PORTC_PCR13_MASK_2)) | PORTC_PCR13_VALUE_2;
    #endif
  #elif defined(PORTC_PCR13_VALUE_2)
  PORTC_PCR13 = PORTC_PCR13_VALUE_2;
  #endif

  /* Register 'PORTC_PCR14' initialization */
  #if PORTC_PCR14_MASK_2
    #if PORTC_PCR14_MASK_2 == 0xFFFFFFFF
  PORTC_PCR14 = PORTC_PCR14_VALUE_2;
    #elif PORTC_PCR14_MASK_2 == PORTC_PCR14_VALUE_2
  PORTC_PCR14 |= PORTC_PCR14_VALUE_2;
    #elif PORTC_PCR14_VALUE_2 == 0
  PORTC_PCR14 &= ~PORTC_PCR14_MASK_2;
    #else
  PORTC_PCR14 = (PORTC_PCR14 & (~PORTC_PCR14_MASK_2)) | PORTC_PCR14_VALUE_2;
    #endif
  #elif defined(PORTC_PCR14_VALUE_2)
  PORTC_PCR14 = PORTC_PCR14_VALUE_2;
  #endif

  /* Register 'PORTC_PCR15' initialization */
  #if PORTC_PCR15_MASK_2
    #if PORTC_PCR15_MASK_2 == 0xFFFFFFFF
  PORTC_PCR15 = PORTC_PCR15_VALUE_2;
    #elif PORTC_PCR15_MASK_2 == PORTC_PCR15_VALUE_2
  PORTC_PCR15 |= PORTC_PCR15_VALUE_2;
    #elif PORTC_PCR15_VALUE_2 == 0
  PORTC_PCR15 &= ~PORTC_PCR15_MASK_2;
    #else
  PORTC_PCR15 = (PORTC_PCR15 & (~PORTC_PCR15_MASK_2)) | PORTC_PCR15_VALUE_2;
    #endif
  #elif defined(PORTC_PCR15_VALUE_2)
  PORTC_PCR15 = PORTC_PCR15_VALUE_2;
  #endif

  /* Register 'PORTC_PCR16' initialization */
  #if PORTC_PCR16_MASK_2
    #if PORTC_PCR16_MASK_2 == 0xFFFFFFFF
  PORTC_PCR16 = PORTC_PCR16_VALUE_2;
    #elif PORTC_PCR16_MASK_2 == PORTC_PCR16_VALUE_2
  PORTC_PCR16 |= PORTC_PCR16_VALUE_2;
    #elif PORTC_PCR16_VALUE_2 == 0
  PORTC_PCR16 &= ~PORTC_PCR16_MASK_2;
    #else
  PORTC_PCR16 = (PORTC_PCR16 & (~PORTC_PCR16_MASK_2)) | PORTC_PCR16_VALUE_2;
    #endif
  #elif defined(PORTC_PCR16_VALUE_2)
  PORTC_PCR16 = PORTC_PCR16_VALUE_2;
  #endif

  /* Register 'PORTC_PCR17' initialization */
  #if PORTC_PCR17_MASK_2
    #if PORTC_PCR17_MASK_2 == 0xFFFFFFFF
  PORTC_PCR17 = PORTC_PCR17_VALUE_2;
    #elif PORTC_PCR17_MASK_2 == PORTC_PCR17_VALUE_2
  PORTC_PCR17 |= PORTC_PCR17_VALUE_2;
    #elif PORTC_PCR17_VALUE_2 == 0
  PORTC_PCR17 &= ~PORTC_PCR17_MASK_2;
    #else
  PORTC_PCR17 = (PORTC_PCR17 & (~PORTC_PCR17_MASK_2)) | PORTC_PCR17_VALUE_2;
    #endif
  #elif defined(PORTC_PCR17_VALUE_2)
  PORTC_PCR17 = PORTC_PCR17_VALUE_2;
  #endif

  /* Register 'PORTC_PCR18' initialization */
  #if PORTC_PCR18_MASK_2
    #if PORTC_PCR18_MASK_2 == 0xFFFFFFFF
  PORTC_PCR18 = PORTC_PCR18_VALUE_2;
    #elif PORTC_PCR18_MASK_2 == PORTC_PCR18_VALUE_2
  PORTC_PCR18 |= PORTC_PCR18_VALUE_2;
    #elif PORTC_PCR18_VALUE_2 == 0
  PORTC_PCR18 &= ~PORTC_PCR18_MASK_2;
    #else
  PORTC_PCR18 = (PORTC_PCR18 & (~PORTC_PCR18_MASK_2)) | PORTC_PCR18_VALUE_2;
    #endif
  #elif defined(PORTC_PCR18_VALUE_2)
  PORTC_PCR18 = PORTC_PCR18_VALUE_2;
  #endif
}

#ifdef __cplusplus
}
#endif

/* END PORTC_Init. */

/** ###################################################################
 **
 **     This file is a part of Processor Expert static initialization
 **     library for Freescale microcontrollers.
 **
 ** ################################################################### */
