/* ###################################################################
**     Filename    : Events.h
**     Project     : ee4951_prodmcu
**     Processor   : MK22FN512VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-11-28, 12:40, # CodeGen: 0
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
#include "op_sys.h"
#include "WAIT1.h"
#include "adc_trigger.h"
#include "dut_gpio.h"
#include "dut_adc.h"
#include "opt_bits.h"
#include "testgpio.h"
#include "DbgCs1.h"
#include "self_adc.h"
#include "system_timer.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*
** ===================================================================
**     Interrupt handler : ADC0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC0_IRQHandler(void);

/*
** ===================================================================
**     Interrupt handler : PORTA_IRQHandler
**
**     Description :
**         User interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
//void PORTA_IRQHandler(void);



/*
** ===================================================================
**     Callback    : ts_timer_OnTimeOut
**     Description : This callback is called when the timer expires.
**     Parameters  :
**       data - User parameter for the callback function.
**     Returns : Nothing
** ===================================================================
*/
void ts_timer_OnTimeOut(void* data);


/*
** ===================================================================
**     Callback    : adc_trigger_OnTimeOut
**     Description : This callback is called when the timer expires.
**     Parameters  :
**       data - User parameter for the callback function.
**     Returns : Nothing
** ===================================================================
*/
void adc_trigger_OnTimeOut(void* data);

/*
** ===================================================================
**     Interrupt handler : ADC1_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC1_IRQHandler(void);




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
