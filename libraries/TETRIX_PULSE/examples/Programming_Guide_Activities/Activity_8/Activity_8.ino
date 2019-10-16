#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  pulse.setMotorPowers(100,50);

}