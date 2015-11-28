/* ###################################################################
**     Filename    : Events.c
**     Project     : ee4951_prod_mcu
**     Processor   : MK22FN512VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-11-26, 11:21, # CodeGen: 0
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



/*! disp_spi IRQ handler */
void SPI1_IRQHandler(void)
{
#if DISP_SPI_DMA_MODE
  DSPI_DRV_EdmaIRQHandler(FSL_DISP_SPI);
#else
  DSPI_DRV_IRQHandler(FSL_DISP_SPI);
#endif
  /* Write your code here ... */
}

/*! self_adc IRQ handler */
void ADC1_IRQHandler(void)
{
  /* Write your code here ... */
}

/*! dut_adc IRQ handler */
void ADC0_IRQHandler(void)
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
