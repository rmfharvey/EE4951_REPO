/*
 * SelfPower.h
 *
 *  Created on: Dec 6, 2015
 *      Author: RossHarvey
 */

#ifndef SOURCES_SELFPOWER_H_
#define SOURCES_SELFPOWER_H_

#include <stdint.h>
#include "self_adc.h"

typedef struct SELF_CURRENT_RANGE	{
	adc16_chn_config_t	adcChConfig;		// ADC channel configuration
	volatile uint16_t 	rawADCVal;			// 16-bit, unsigned fractional ADC value
	float				scaledADCVal;		// ADC Val scaled by reference voltage (Value in amps)
	float				shuntRes;			// Current shunt resistance value
	uint8_t				ampGain;			// Shunt amplifier gain
	float				scalingFactor;		// Scaling factor
}selfCurrentRange_t;


typedef struct SELF_VOLTAGE_RANGE	{
	adc16_chn_config_t	adcChConfig;		// ADC channel configuration
	volatile uint16_t 	rawADCVal;			// 16-bit, unsigned fractional ADC value
	float				scaledADCVal;		// ADC Val scaled by reference voltage (Value in amps)
	float				topResistance;		// Resistor divider top
	float				bottomResistance;	// Resistor divider bottom
	float				scalingFactor;		// Scaling factor
}selfVoltageRange_t;



class SelfPower {

public:
	SelfPower();
private:
/*(	uint16_t 	v3_Vraw;
	float 		v3_Vscaled;
	uint16_t 	v3_Iraw;
	float 		v3_Iscaled;
	uint16_t 	v5_Vraw;
	float 		v5_Vscaled;
	uint16_t 	v5_Iraw;
	float 		v5_Iscaled;
*/
	selfCurrentRange_t	v3_isense;
	selfVoltageRange_t	v3_vsense;
	selfCurrentRange_t	v5_isense;
	selfVoltageRange_t	v5_vsense;

};

#endif /* SOURCES_SELFPOWER_H_ */
