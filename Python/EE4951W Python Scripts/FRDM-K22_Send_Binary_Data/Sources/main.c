/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* This is an example program.*/

#include "fsl_device_registers.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_clock_manager.h"
#include "fsl_debug_console.h"
#include <stdio.h>
#include <math.h>

#define GPIO_INTERRUPT	1	//Set value to 1 for interrupt, 0 for polling
#define PERIOD  0.005	//Define the period of all data transmissions
unsigned int send_data = 0;
unsigned int send_binary = 0;
unsigned int print_val = 0;
unsigned int binary_val = 0x00;

int main(void)
{

    /* enable clock for PORTs */
	CLOCK_SYS_EnablePortClock(PORTA_IDX);
	CLOCK_SYS_EnablePortClock(PORTB_IDX);
	CLOCK_SYS_EnablePortClock(PORTC_IDX);
	CLOCK_SYS_EnablePortClock(PORTE_IDX);

    /* Init board clock */
    BOARD_ClockInit();
    dbg_uart_init();

    //printf("\nHello World! \r\n");
    //printf("\nPress SW2 to Toggle LED. \r\n");
    //printf("\nPress SW3 to send a block of data. \r\n");

#if GPIO_INTERRUPT
    // Configure pin (sw1) interrupt if GPIO_INTERRUPT is set
    switchPins[0].config.interrupt = kPortIntFallingEdge;
#endif
    // Initializes GPIO driver
    GPIO_DRV_Init(switchPins, ledPins);

    while(1)
    {
    	if (send_data == 1)
    	{
    		PrintData(binary_val);
			binary_val = binary_val + 1;
    	}


    	// Poll (sw2) if GPIO_INTERRUPT is not set
    	    	if(GPIO_DRV_ReadPinInput(kGpioSW2) == 0)
    	    	{
    	    		GPIO_SW_DELAY;
    	    		GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_BLUE);
    	    	}
		// Poll (sw3) if GPIO_INTERRUPT is not set
				if(GPIO_DRV_ReadPinInput(kGpioSW3) == 0)
				{
					GPIO_SW_DELAY;
					GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_RED);
					send_data = 1 - send_data;
					//printf ("%08d\r\n",print_val);
					//PrintData(print_val);
					//print_val = print_val + 1;
				}
    }
    /* Never leave main */
    return 0;
}

#if GPIO_INTERRUPT
// Define PORTC_IRQHandler (sw2) if GPIO_INTERRUPT is set
void PORTC_IRQHandler()
{
	if(GPIO_DRV_ReadPinInput(kGpioSW2) == 0)
		{
			GPIO_DRV_ClearPinIntFlag (kGpioSW2); // Clear IRQ flag
			GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_BLUE); // Toggle blue LED
			GPIO_SW_DELAY;
		}

	if(GPIO_DRV_ReadPinInput(kGpioSW3) == 0)
		{
			GPIO_DRV_ClearPinIntFlag (kGpioSW3); // Clear IRQ flag
			GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_RED); // Toggle blue LED
			GPIO_SW_DELAY;
			//printf ("%08d\r\n",print_val);
			//PrintData(print_val);
			//print_val = print_val + 1;
			//send_data = 1 - send_data;
			//send_binary = 1 - send_binary;
		}
}
#endif

int PrintData(unsigned int timeval)
{
	// This function will print out a chunk of data for each category
	// Here we are assuming that all values are slowly increasing.

	//Initial values
	unsigned int mean_V = 0x2CB41780;
	unsigned int mean_I = 0x004C4B40;
	unsigned int start_TS = 0x000000;

	//Introduce fluctuations
	unsigned int V_val,I_val,TS_val;
	V_val = mean_V + 0x500000 * sin(PERIOD*timeval);
	I_val = mean_I + 0x500000 * sin(PERIOD*timeval);
	TS_val = start_TS + timeval;

	unsigned int voltage[4];
	unsigned int current[4];
	unsigned int time_stamp[3];

	voltage[0] = V_val / 0x1000000;	//MSB
	V_val = V_val - (0x1000000 * voltage[0]);
	voltage[1] = V_val / 0x10000;
	V_val = V_val - (0x10000 * voltage[1]);
	voltage[2] = V_val / 0x100;
	V_val = V_val - (0x100 * voltage[2]);
	voltage[3] = V_val;

	current[0] = I_val / 0x1000000;	//MSB
	I_val = I_val - (0x1000000 * current[0]);
	current[1] = I_val / 0x10000;
	I_val = I_val - (0x10000 * current[1]);
	current[2] = I_val / 0x100;
	I_val = I_val - (0x100 * current[2]);
	current[3] = I_val;

	time_stamp[0] = TS_val / 0x10000;	//MSB
	TS_val = TS_val - (0x10000 * time_stamp[0]);
	time_stamp[1] = TS_val / 0x100;
	TS_val = TS_val - (0x100 * time_stamp[1]);
	time_stamp[2] = TS_val;

	fputc(voltage[3],stdout);
	fputc(voltage[2],stdout);
	fputc(voltage[1],stdout);
	fputc(voltage[0],stdout);
	fputc(current[0],stdout);
	fputc(current[1],stdout);
	fputc(current[2],stdout);
	fputc(current[3],stdout);
	fputc(time_stamp[0],stdout);
	fputc(time_stamp[1],stdout);
	fputc(time_stamp[2],stdout);

	unsigned int temp = 0;
	for (int i=0;i<11;i++)
	{
		if (i < 4)
		{
			temp = temp ^ (voltage[i]);
		}
		else if (i < 8)
			{
				temp = temp ^ (current[i-4]);
			}
			else
			{
				temp = temp ^ (time_stamp[i-8]);
			}
	}
	fputc(temp,stdout);	//This is the check_sum

	temp = 0;
	for (int i=0;i<11;i++)
	{
		if (i < 4)
		{
			temp = temp + (voltage[i]);
		}
		else if (i < 8)
			{
				temp = temp + (current[i-4]);
			}
			else
			{
				temp = temp + (time_stamp[i-8]);
			}
	}
	temp = temp % 256;	//Take the least significant byte
	temp = temp ^ 255;	//Flip the sign of each bit
	temp = temp + 1;	//This is the twos_complement
	fputc(temp,stdout);

	fflush(stdout);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
