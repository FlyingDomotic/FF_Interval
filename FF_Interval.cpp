/*!
  \file
  \brief This class allow running some code at regular interval.
  \author Flying Domotic
  \version V1.3.2
  \date March 26, 2017

	Classical usage is to include it in the Arduino loop, with other commands.
	You can define first interval (origin time is set when you call to begin() sub).
	Then, the code will be run at regular interval.

  Typical example:

    # include "FF_Interval.h"

    // Define running interval of 5 seconds, first occurrence 2 seconds after starting
	FF_Interval myWork(seconds(5),seconds(2));

    void setup()
    {
      Serial.begin(115200);
      Serial.println("Start");
      myWork.begin();
    }

    void loop()
    {
      if (myWork.shouldRun()) {
        Serial.println ("Fire!");
      }
    }

*/

#include "FF_Interval.h"
#include "Arduino.h"

/*!   Initialize regular and first interval

      /param interval contains the regular interval (in ms) to fire code
      /param firstInterval contains the first interval (in ms) to fire code after begin() call
      
*/

FF_Interval::FF_Interval(unsigned long _interval, unsigned long _firstInterval) {
	interval = _interval;
	nextInterval = _firstInterval;
	previousTime = 0;
}

/*!   Checks if interval has timed or not (overflow aware code)

      /return true if interval has expired (and code should run), false else

*/

bool FF_Interval::shouldRun() {
  // Get current time
  currentTime = (unsigned long) millis();
  // Is it time to execute FF_ code?
  if((currentTime - previousTime) > nextInterval)
  {
    // Yes, set last execution time
    previousTime = currentTime;
    nextInterval = interval;
    return (true);
  } else {
    return (false);
  }
}

/*!   Redefine  interval and restart timer.
      
      Note that both initial and regular timers are set, so you can call it indifferently before or after begin() call.
      
      /param interval contains the regular interval (in ms) to fire code

*/

void FF_Interval::setNext(unsigned long _interval) {
  interval = _interval;
  nextInterval = _interval;
  restart();
}

/*!   Start class work

      Initialize previous time in order to fire first occurence properly.
  
*/

void FF_Interval::begin() {
  previousTime = (unsigned long) millis();
}

/*!   Restart timer

*/
void FF_Interval::restart() {
  previousTime = (unsigned long) millis();
}
