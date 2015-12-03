/* ###################################################################
**     Filename    : Events.c
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
#include "DutISense.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
void ADC0_IRQHandler(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Callback    : PORTA_IRQHandler
**
**     Description :
**         User interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_IRQHandler(void)	{
	//PRINTF("PORTA Interrupt\n\r");
}



/*
** ===================================================================
**     Callback    : ts_timer_OnTimeOut
**     Description : This callback is called when the timer expires.
**     Parameters  :
**       data - User parameter for the callback function.
**     Returns : Nothing
** ===================================================================
*/
void ts_timer_OnTimeOut(void* data)
{
	//TODO increase accuracy on this counter
	/* Write your code here ... */
#ifdef TMR
	extern sysTimer_t timer;
	if(timer.asDiv.usec==998635)	{	// Not exact to account for inaccuracy in timing (was 998635)
	//if(timer.asDiv.usec==100000)	{
		timer.asDiv.usec=0;
		if(timer.asDiv.sec==59)	{
			timer.asDiv.sec=0;
			if(timer.asDiv.min==59)	{
				timer.asDiv.min=0;
				if(timer.asDiv.hr=23)	{
					timer.asDiv.hr=0;
					timer.asDiv.day++;
				}
			}else timer.asDiv.min++;
		}else	{
			timer.asDiv.sec++;
			PRINTF("%d %02d:%02d:%02d.%06\r",
					timer.asDiv.day,
					timer.asDiv.hr,
					timer.asDiv.min,
					timer.asDiv.sec,
					timer.asDiv.usec);
		}
	}else timer.asDiv.usec++;
#endif

}



/*
** ===================================================================
**     Callback    : adc_trigger_OnTimeOut
**     Description : This callback is called when the timer expires.
**     Parameters  :
**       data - User parameter for the callback function.
**     Returns : Nothing
** ===================================================================
*/
void adc_trigger_OnTimeOut(void* data)
{
	 extern bool adcReady;
	 static uint16_t i=0;
	 //extern DutISense dutIsense;
	 //dutIsense.updateADCVal();
	 if(!i++)
	   	PRINTF(":");
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
