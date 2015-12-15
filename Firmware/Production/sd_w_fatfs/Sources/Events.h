/* ###################################################################
**     Filename    : Events.h
**     Project     : sd_w_fatfs
**     Processor   : MK22FN512VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-13, 17:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "memoryCard1.h"
#include "fsl_dspi1.h"
#include "dmaController1.h"
#include "gpio1.h"

#ifdef __cplusplus
extern "C" {
#endif 

void check_card_inserted(void);
void wait_for_card(void);
void fsl_spi_OnCardDetect0(bool cardInserted);

/*! fsl_dspi1 IRQ handler */
void fsl_dspi1_IrqHandler(void);

void gpio1_PORTC_IRQHandler(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
