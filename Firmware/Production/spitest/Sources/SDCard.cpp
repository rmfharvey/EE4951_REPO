/*
 * SDCard.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: RossHarvey
 */

#include <SDCard.h>

SDCard::SDCard() {
	// TODO Auto-generated constructor stub

}

SDCard::~SDCard() {
	// TODO Auto-generated destructor stub
}

#define BSIZE	10U
void SDCard::init(void)	{

	uint8_t buffer[BSIZE];
	uint8_t i;
	for(i=0; i<BSIZE; i++)	{
		buffer[i]=0;
	}
	DSPI_DRV_MasterTransfer(sd_spi_IDX, &sd_spi_BusConfig0, buffer, rxBuffer, BSIZE);
	sendByte(CMD0);
}

void SDCard::sendByte(uint8_t byte)	{
	uint8_t arr[1] = {byte};
	DSPI_DRV_MasterTransfer(sd_spi_IDX, &sd_spi_BusConfig0, arr, rxBuffer, 1);
}

uint8_t *SDCard::getRxBuffer(void)	{
	return rxBuffer;
}

/*
void SDCard::fillTxBuffer(uint8_t data[], uint8_t size)	{
	uint8_t i = 0;
	for(i; i<size; i++)	{
		txBuffer[i]=data[i];
	}
}

void SDCard::sendData(uint8_t data, uint8_t size)	{
	//fillTxBuffer(data, size);
	DSPI_DRV_MasterTransfer(sd_spi_IDX, &sd_spi_BusConfig0, txBuffer, rxBuffer, 1);
}
*/

