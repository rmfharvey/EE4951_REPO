/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*! fsl_dspi1 IRQ handler */
void SPI0_IRQHandler(void)
{
#if FSL_DSPI1_DMA_MODE
  DSPI_DRV_EdmaIRQHandler(FSL_FSL_DSPI1);
#else
  DSPI_DRV_IRQHandler(FSL_FSL_DSPI1);
#endif
  /* Write your code here ... */
}

/*! DUT_ADC IRQ handler */
void ADC0_IRQHandler(void)
{
  /* Write your code here ... */
}

/*! SELF_ADC IRQ handler */
void ADC1_IRQHandler(void)
{
  /* Write your code here ... */
}

/*! SPI1 IRQ handler */
void SPI1_IRQHandler(void)
{
#if SPI1_DMA_MODE
  DSPI_DRV_EdmaIRQHandler(FSL_SPI1);
#else
  DSPI_DRV_IRQHandler(FSL_SPI1);
#endif
  /* Write your code here ... */
}

void uartCom1_RxCallback(uint32_t instance, void * uartState)
{
  /* Write your code here ... */
}

void uartCom1_TxCallback(uint32_t instance, void * uartState)
{
  /* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
