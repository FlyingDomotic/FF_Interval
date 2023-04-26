/*!
  \file
  \brief This file is the header of FF_Interval.cpp file
  \author Flying Domotic
  \version V1.3.1
  \date March 26, 2017

  For more details, please have a look at FF_Interval.cpp

*/

#ifndef FF_Interval_h
#define FF_Interval_h

#include <inttypes.h>


// Helpers to manipulate minutes and seconds

#define ms(count) count * 1UL                //!< Macro to express time in ms (millisecond)
#define seconds(count) count * 1000UL        //!< Macro to express time in second
#define minutes(count) seconds(count * 60UL) //!< Macro to express time in minutes

// Define default first interval to 1 second and normal interval to one minute
#define DEFAULT_INTERVAL minutes(1)                         //!< Default regular interval (one minute)
#define DEFAULT_FIRST_INTERVAL seconds(1)                   //!< Default first interval (at boot time, one second)

#ifdef __cplusplus
class FF_Interval
{
  public:
	FF_Interval(unsigned long _interval=DEFAULT_INTERVAL, unsigned long _firstInterval=DEFAULT_FIRST_INTERVAL);
	void begin();
	void setNext (unsigned long _interval);
	void restart();
	bool shouldRun();
  //private:
	// Everything is unsigned long, expressed in ms
	unsigned long interval;         //!< Holds "normal" interval 
	unsigned long nextInterval;     //!< Holds first interval
	unsigned long currentTime;      //!< Holds current time
	unsigned long previousTime;     //!< Holds last execution time
};
#endif
#endif
