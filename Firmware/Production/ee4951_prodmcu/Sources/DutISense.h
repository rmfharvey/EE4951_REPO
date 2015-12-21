/*
 * DutISense.h
 *
 *  Created on: Nov 28, 2015
 *      Author: RossHarvey
 */

#ifndef SOURCES_DUTISENSE_H_
#define SOURCES_DUTISENSE_H_

#include <assert.h>
#include <stdint.h>
#include "dut_gpio.h"
#include "dut_adc.h"
#include "floatUnion.h"

#define NUMRANGES		4U	// Number of current ranges on the board
#define ADC_CHNGROUP	0U	// For ADC functions
#define AUTOSWITCHING		// Automatically switches between channels.  Comment this out to disable
#define RNGSWITCHHYS	3U	// I was going to add some hysteresis to prevent false switching between channels.  This wasn;t actually needed, though.

// "Out-of-range" Thresholds for auto-switching.
#define A_LOTHRESH	33U		// 5mA
#define mA_HITHRESH 45875U	// 70mA
#define mA_LOTHRESH	82U		// 500uA
#define uA_HITHRESH	45875U	// 700uA
#define uA_LOTHRESH	66U		// 1uA
#define nA_HITHRESH	16384U	// 100uA

// Enumeration for code readability.
typedef enum IRANGE	{
	nA = 0,
	uA,
	mA,
	A
}iRange_t;

/****************************************************************************************************
 * This struct holds all values relevant to the individual current ranges in the project			*
 * The raw and scaled ADC values will probably never be used here/ but I've included them 			*
 * 		just in case we want to.																	*
 ****************************************************************************************************/
typedef struct CURRENT_RANGE	{
	uint32_t 			enPinName;			// Enable pin for each current range
	adc16_chn_config_t	adcChConfig;		// ADC channel configuration
	volatile uint16_t 	rawADCVal;			// 16-bit, unsigned fractional ADC value
	float				scaledADCVal;		// ADC Val scaled by reference voltage (Value in amps)
	float				shuntRes;			// Current shunt resistance value
	uint8_t				ampGain;			// Shunt amplifier gain
	float				scalingFactor;		// Scaling factor
	uint8_t				rangeNum;			// Range number for switches
}currentRange_t;


/****************************************************************************************************
 * This class should handle all DUT I-sense related calls											*
 ****************************************************************************************************/
class DutISense {
public:
	DutISense();								// Constructor auto-initializes all DUT Isense channels
	void enableCurrentRange(iRange_t range);	// Sets which range is active
	void disableCurrentRange(void);				// Disables all Current Ranges
	uint8_t getCurrentRange(void);				// Returns the active range as an unsigned int in [0,3]
	void updateADCVal(void);					// Reads a new ADC value and updates rawADCVal and floatADCVal.  If AUTOSWITCHING is defined, checks if we need to switch ranges
	uint16_t getADCValRaw(void);				// Returns raw ADC value
	floatUnion_t getADCValScaled(void);			// Returns scaled ADC value in amps
	uint8_t getPreviousIRange(void);			// Returns the previous current range.  This is needed for sending formatted values out, since updateADCVal() will change this range sometimes
private:
	uint8_t numCurrentRanges;
	uint16_t rawADCVal;
	floatUnion_t floatADCVal;
	currentRange_t range0;						// Holds all values for range 0.  Same for range 1-3 (see struct above)
	currentRange_t range1;
	currentRange_t range2;
	currentRange_t range3;
	currentRange_t *activeRange;				// Pointer to whichever range is currently active
	uint8_t prevIRange;							// Used for sending out formatted data since updateADCVal() may change range.
	adc16_chn_config_t *activeADCChannel;		// Pointer to whichever ADC channel is currently active. (see SDK>platform>drivers>inc>fsl_adc_driver.h)

	void PRV_initCurrentRange(currentRange_t *cRange, uint32_t pinName, adc16_chn_config_t adcCfg, float shRes, uint8_t gain, uint8_t rngNum);
	void PRV_enableRange(currentRange_t *newRange);
};

#endif /* SOURCES_DUTISENSE_H_ */
