/*
 * floatUnion.h
 *
 *  Created on: Dec 10, 2015
 *      Author: RossHarvey
 */

#ifndef SOURCES_FLOATUNION_H_
#define SOURCES_FLOATUNION_H_


typedef union	FLOAT_UNION	{
	float	asFloat;
	struct	{
		uint8_t	n0	:8;
		uint8_t	n1	:8;
		uint8_t	n2	:8;
		uint8_t	n3	:8;
	}asIntBF;
}floatUnion_t;




#endif /* SOURCES_FLOATUNION_H_ */
