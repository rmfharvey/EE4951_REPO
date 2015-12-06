/*
 * system_timer.h  (Deprecated as of 2015-12-4)
 *
 *  Created on: Dec 1, 2015
 *      Author: RossHarvey
 */



#ifndef SOURCES_SYSTEM_TIMER_H_
#define SOURCES_SYSTEM_TIMER_H_


typedef union SYSTEM_TIMER	{
	struct COUNTER_DIVISIONS{
		uint32_t	usec	:20;	// 10487576 us
		uint8_t		sec		:6;		// 64 sec
		uint8_t		min		:6;		// 64 min
		uint8_t		hr		:5;		// 32 hr
		uint32_t	day		:23;	// 8388608 days  (save 4 bits for a checksum to be implemented elsewhere)
	}asDiv;
	uint64_t timestamp;
}sysTimer_t;



#endif /* SOURCES_SYSTEM_TIMER_H_ */
