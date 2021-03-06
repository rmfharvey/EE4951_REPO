/* ###################################################################
**     Filename    : Events.c
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

static volatile bool cardInserted = false; /* Flag to indicate a card has been inserted */


/*! fsl_dspi1 IRQ handler */
void fsl_dspi1_IrqHandler(void)
{
#if FSL_DSPI1_DMA_MODE
  DSPI_DRV_EdmaIRQHandler(FSL_FSL_DSPI1);
#else
  DSPI_DRV_IRQHandler(FSL_FSL_DSPI1);
#endif
  /* Write your code here ... */
}

void gpio1_PORTC_IRQHandler(void)
{
  if(PORT_HAL_GetPortIntFlag(PORTE_BASE_PTR) == (1<<SD_CARD_DETECT))
  {
	  check_card_inserted();
  }

  PORT_HAL_ClearPortIntFlag(PORTC_BASE_PTR);
  /* Write your code here ... */
}

void fsl_spi_OnCardDetect0(bool cardInserted)	{
	/* Write your code here */
}

void check_card_inserted(void)
{
    uint32_t state = GPIO_DRV_ReadPinInput(SD_CARD_DETECT);
    uint32_t matchState = -1;

    // Debounce input
    do
    {
        for (int i = 0; i < 0x1FFFFF; i++)
        {
            __asm("nop");
        }
        matchState = state;
        state = GPIO_DRV_ReadPinInput(SD_CARD_DETECT);
    }
    while (state != matchState);

    // Set card state
    cardInserted = (state == 1);

    fsl_spi_OnCardDetect0(cardInserted);
}

void wait_for_card(void)
{
    while ((!cardInserted));
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
