/*
 * SDCard.h
 *
 *  Created on: Dec 8, 2015
 *      Author: RossHarvey
 */

#ifndef SOURCES_SDCARD_H_
#define SOURCES_SDCARD_H_

#include "sd_spi.h"

#define MAXARRSIZE	256

#define CMD0	0U

class SDCard {
public:
	SDCard();
	virtual ~SDCard();

	void init(void);
	void sendByte(uint8_t byte);
	uint8_t *getRxBuffer(void);
	//void fillTxBuffer(uint8_t data[], uint8_t size);
	//void sendData(uint8_t data, uint8_t size);
private:
	uint8_t txBuffer[MAXARRSIZE];
	uint8_t rxBuffer[MAXARRSIZE];
};

#endif /* SOURCES_SDCARD_H_ */
