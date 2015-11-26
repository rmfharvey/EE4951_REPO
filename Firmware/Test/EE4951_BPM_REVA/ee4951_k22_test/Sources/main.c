/* ###################################################################
**     Filename    : main.c
**     Project     : ee4951_k22_test
**     Processor   : MK22FN512VLH12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-26, 13:05, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "DbgCs1.h"
#include "sd_card.h"
#include "fsl_dspi1.h"
#include "WAIT1.h"
#include "disp_spi.h"
#include "dut_adc.h"
#include "self_adc.h"
#include "hw_irqs.h"
#include "gpio1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */

#define True	1
#define False	0

void printADCvals(void)	{
	uint16_t DUT_vsense;	//DUT
	uint16_t DUT_isense;	//DUT
	uint16_t SELF_3v_vsense;
	uint16_t SELF_3v_isense;
	uint16_t SELF_5v_vsense;
	uint16_t SELF_5v_isense;
	static uint8_t count=0;

	ADC16_DRV_ConfigConvChn(FSL_DUT_ADC, 0U, &dut_vsense_config);
	DUT_vsense = ADC16_DRV_GetConvValueRAW(FSL_DUT_ADC,0);

	ADC16_DRV_ConfigConvChn(FSL_DUT_ADC, 0U, &dut_isense_config);
	DUT_isense = ADC16_DRV_GetConvValueRAW(FSL_DUT_ADC,0);

	PRINTF("%05.0d,%05.0d\n",DUT_vsense,DUT_isense);
	//PRINTF("DUT_Vsense: %5.0d\tDUT_ISense: %5.0d\n",DUT_vsense,DUT_isense);

	/*ADC16_DRV_ConfigConvChn(FSL_SELF_ADC, 0U, &v3_vsense);
	ADC16_DRV_GetConvValueRAW(FSL_SELF_ADC,0);


	ADC16_DRV_ConfigConvChn(FSL_SELF_ADC, 0U, &v3_vsense);
	SELF_3v_vsense = ADC16_DRV_GetConvValueRAW(FSL_SELF_ADC,0);

	ADC16_DRV_ConfigConvChn(FSL_SELF_ADC, 0U, &v3_isense);
	SELF_3v_isense = ADC16_DRV_GetConvValueRAW(FSL_SELF_ADC,0);

	ADC16_DRV_ConfigConvChn(FSL_SELF_ADC, 0U, &v5_vsense);
	SELF_5v_vsense = ADC16_DRV_GetConvValueRAW(FSL_SELF_ADC,0);

	ADC16_DRV_ConfigConvChn(FSL_SELF_ADC, 0U, &v5_isense);
	SELF_5v_isense = ADC16_DRV_GetConvValueRAW(FSL_SELF_ADC,0);
*/
	//PRINTF("\t%5.0d\r",SELF_3v_isense);
	//PRINTF("\t%5.0d\t%5.0d\t%5.0d\t%5.0d\t%5.0d\t%5.0d\t\r",
	//		DUT_vsense, DUT_isense, SELF_5v_vsense, SELF_5v_isense, SELF_3v_vsense, SELF_3v_isense);
	//PRINTF("DUT Vsense = %5.0d\n\rDUT Isense = %5.d\n\rSelf 5v vSense = %5.d\n\rSelf 5v ISense = %5.d\n\rSelf 3v vSense = %5.d\n\rSelf 3v ISense = %5.d\n\n\r",DUT_vsense, DUT_isense, SELF_5v_vsense, SELF_5v_isense, SELF_3v_vsense, SELF_3v_isense);
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  long int i;
  PRINTF("\n\n\r");
  while(True)	{
	  printADCvals();
	  WAIT1_Waitms(10);
  }






  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
