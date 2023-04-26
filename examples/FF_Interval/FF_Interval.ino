
#include <FF_Interval.h>

FF_Interval myWork(seconds(5),seconds(2));

void setup()
{
  Serial.begin(115200);
  Serial.println("Start");
  // Set startup time
  myWork.begin();
}

void loop()
{
  if (myWork.shouldRun()) {
    // This line will fire-up 2 seconds after startup, then 5 seconds after each activation
    Serial.println ("Fire!");
  }
}
