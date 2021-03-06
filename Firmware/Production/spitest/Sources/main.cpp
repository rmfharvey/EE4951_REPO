/* ###################################################################
**     Filename    : main.c
**     Project     : spitest
**     Processor   : MK22FN512VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-07, 19:25, # CodeGen: 0
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
#include "pin_mux.h"
#include "osa1.h"
#include "sd_spi.h"
#include "WAIT1.h"
#include "debug_console.h"
#include "sd_gpio.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "SDCard.h"
#include <stdbool.h>

#define CMD0	0x40
#define CMD1	0x41
#define CMD16	0x50
#define CMD24	0x58
#define CMD58	0x7A
#define CMD59	0x7B

uint8_t sendByte(uint8_t byte)	{
	uint8_t rcv;
	uint8_t bt[1] = {byte};
	DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, &byte, &rcv, 1, 0xFFFFFFFF);
	return rcv;
}

void sendCMD(uint8_t cmd, uint32_t arg, uint8_t arrRet[6])	{
	uint8_t arr[6] = {cmd, (uint8_t)(arg>>24), (uint8_t)(arg>>16), (uint8_t)(arg>>8), (uint8_t)(arg), 0x95};
	DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, arr, arrRet, 6, 0xFFFFFFFF);
}

uint8_t checkArray(uint8_t arr[6], uint8_t target)	{
	if(arr[0]==target)
		return 1;
	else if(arr[1]==target)
		return 1;
	else if(arr[2]==target)
		return 1;
	else if(arr[3]==target)
		return 1;
	else if(arr[4]==target)
		return 1;
	else if(arr[5]==target)
		return 1;
	else
		return 0;
}

uint8_t initSDCard(void)	{
	uint8_t spiArr[10] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	uint8_t resetArr[6] = {0x40, 0x00, 0x00, 0x00, 0x00, 0x95};
	uint8_t initArr[6] = {0x41, 0x00, 0x00, 0x00, 0x00, 0x95};
	uint8_t idleArr[6] = {0x7A, 0x00, 0x00, 0x00, 0x00, 0x95};
	uint8_t sectorSizeArr[6] = {0x40^16, 0x00,  0x00,  0x02,  0x00,  0x95};
	uint8_t arrRx[16] = {0x00};
	uint8_t response;
	// Set Idle
	GPIO_DRV_SetPinOutput(SD_nCS);
	DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, spiArr, &arrRx[0], 10, 0xFFFFFFFF);

	//cmd0
	uint8_t respArr[6] = {0x00};
	GPIO_DRV_ClearPinOutput(SD_nCS);
	sendCMD(CMD0, 0, respArr);
	while(!checkArray(respArr, 0x01))
		sendCMD(CMD0, 0, respArr);
	GPIO_DRV_SetPinOutput(SD_nCS);

	PRINTF("SD Card Reset\n\r");

	// CMD1
	GPIO_DRV_ClearPinOutput(SD_nCS);
	sendCMD(CMD1,0,respArr);
	GPIO_DRV_SetPinOutput(SD_nCS);

	GPIO_DRV_ClearPinOutput(SD_nCS);
	sendByte(0xFF);
	sendByte(0xFF);
	GPIO_DRV_SetPinOutput(SD_nCS);

	// Turn off CRC
	GPIO_DRV_ClearPinOutput(SD_nCS);
	sendCMD(CMD59,0,respArr);
	GPIO_DRV_SetPinOutput(SD_nCS);
	response = 0xFF;
	while(response==0xFF){
		GPIO_DRV_ClearPinOutput(SD_nCS);
		response = sendByte(0xFF);
		GPIO_DRV_SetPinOutput(SD_nCS);
	}
	GPIO_DRV_ClearPinOutput(SD_nCS);
	response = sendByte(0xFF);
	GPIO_DRV_SetPinOutput(SD_nCS);


	// Check OCR
	GPIO_DRV_ClearPinOutput(SD_nCS);
	sendCMD(CMD58,0,respArr);
	while(respArr[0]!=0x00)	{
		respArr[0] = sendByte(0xFF);
	}
	GPIO_DRV_SetPinOutput(SD_nCS);
	PRINTF("SD Card ready\n\r");

	//DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, sectorSizeArr, &arrRx[0], 6, 0xFFFFFFFF);
	//sendCMD(CMD16, 512, respArr);
	//PRINTF("Sector Size Set\n\r");

	//DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, spiArr, &arrRx[0], 2, 0xFFFFFFFF);

	return 1;
}

void writeBlock(uint8_t sector)	{
	uint8_t wArr[513] = {0xFE};
	uint16_t i;
	for(i=1; i<513; i++){
		wArr[i]=i-1;
	}

	/*uint8_t ffArr[512];
	for(i=0; i<512; i++){
		ffArr[i]=i;
	}*/

	uint8_t arrReceive[513] = {0x00};
	uint8_t startToken = 0xFE;


	uint8_t j;

	uint8_t response;
	GPIO_DRV_ClearPinOutput(SD_nCS);
	response = sendByte(CMD24);
	GPIO_DRV_SetPinOutput(SD_nCS);

	while(response == 0xFF)	{
		GPIO_DRV_ClearPinOutput(SD_nCS);
		response = sendByte(CMD24);
		GPIO_DRV_SetPinOutput(SD_nCS);
	}
	//while(arrReceive[0]!=0x05)
	//	DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, ffArr, &arrReceive[0], 1, 0xFFFFFFFF);	// Check Response
	//GPIO_DRV_ClearPinOutput(SD_nCS);
	//DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, &startToken, arrReceive, 1, 0xFFFFFFFF);		// Start token
	//GPIO_DRV_SetPinOutput(SD_nCS);

	GPIO_DRV_ClearPinOutput(SD_nCS);
	DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, wArr, arrReceive, 513, 0xFFFFFFFF);		// Send data
	GPIO_DRV_SetPinOutput(SD_nCS);
	//DSPI_DRV_MasterTransferBlocking(sd_spi_IDX, &sd_spi_BusConfig0, ffArr, arrReceive, 512, 0xFFFFFFFF);		// Check Response
}






/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	//SDCard sd;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */



#define SIZE	10
/*  uint32_t i=0;
  uint8_t arrTx[SIZE];
  uint8_t arrRx[SIZE];
  for(i=0; i<SIZE; i++){
	  arrTx[i] = 0xFF;
  }
*/
  PRINTF("\n\n\r");
  WAIT1_Waitms(2000);
  uint8_t sdActive = 0;
  while(1)	{
	  while(!sdActive)	{
		  sdActive = initSDCard();
	  }
	  // SD Card is initialized
	  uint8_t i;
	  for(i=0; i<0xFF; i++)	{
		  writeBlock(i);
	  }


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
