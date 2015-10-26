/* ###################################################################
**     Filename    : Events.h
**     Project     : ee4951_mcu
**     Processor   : MK22FN512VDC12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-26, 00:45, # CodeGen: 0
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
#include "uartCom1.h"
#include "PORTE.h"
#include "SPI1.h"
#include "PORTC.h"
#include "SELF_ADC.h"
#include "DUT_ADC.h"
#include "SD_CARD.h"
#include "fsl_dspi1.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! fsl_dspi1 IRQ handler */
void SPI0_IRQHandler(void);

/*! DUT_ADC IRQ handler */
void ADC0_IRQHandler(void);

/*! SELF_ADC IRQ handler */
void ADC1_IRQHandler(void);

/*! SPI1 IRQ handler */
void SPI1_IRQHandler(void);

void uartCom1_RxCallback(uint32_t instance, void * uartState);

void uartCom1_TxCallback(uint32_t instance, void * uartState);

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
