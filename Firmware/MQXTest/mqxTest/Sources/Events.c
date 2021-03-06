/* ###################################################################
**     Filename    : Events.c
**     Project     : mqxTest
**     Processor   : MK22FN512VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-08, 22:08, # CodeGen: 0
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

#ifdef fsl_dspi1_IDX
/*
** ===================================================================
**     Interrupt handler : fsl_dspi1_IrqHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void fsl_dspi1_IrqHandler(void)
{
#if fsl_dspi1_DMA_MODE
  #if FSL_FEATURE_SOC_EDMA_COUNT
  /* fsl_dspi_edma driver handler (dma mode) */
  DSPI_DRV_EdmaIRQHandler(fsl_dspi1_IDX);
  #else
  /* fsl_dspi_dma driver does not have handler.
     DMA callbacks are used instead.
   */
  #endif
#else
  /* fsl_dspi driver handler (interrupt mode) */
  DSPI_DRV_IRQHandler(fsl_dspi1_IDX);
#endif
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by fsl_dspi1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by fsl_dspi1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

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
