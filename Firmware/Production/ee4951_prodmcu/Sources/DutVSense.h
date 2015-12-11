/*
 * DutVSense.h
 *
 *  Created on: Dec 6, 2015
 *      Author: RossHarvey
 */

#ifndef SOURCES_DUTVSENSE_H_
#define SOURCES_DUTVSENSE_H_

#include <stdint.h>
#include "dut_adc.h"
#include "floatUnion.h"

#define SELFADC_CHNGROUP	0U

class DutVSense {
public:
	DutVSense();
	void updateADCVal(void);					// Reads a new ADC value and updates rawADCVal and floatADCVal
	uint16_t getADCValRaw(void);				// Returns raw ADC value
	floatUnion_t getADCValScaled(void);				// Returns scaled ADC value in volts
private:
	float scalingFactor;
	uint16_t rawADCVal;
	floatUnion_t floatADCVal;
	adc16_chn_config_t	adcChConfig;
};

#endif /* SOURCES_DUTVSENSE_H_ */
