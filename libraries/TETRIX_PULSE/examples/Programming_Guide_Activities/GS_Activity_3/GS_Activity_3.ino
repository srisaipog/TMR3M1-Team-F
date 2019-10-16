#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setServoSpeed(1,25);

}

void loop() {
  pulse.setServoPosition(1,180);
  delay(3000);
  pulse.setServoPosition(1,0);
  delay(3000);

}