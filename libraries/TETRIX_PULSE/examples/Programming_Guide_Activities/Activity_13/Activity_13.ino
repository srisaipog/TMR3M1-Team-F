#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  if (pulse.readSonicSensorCM(3) > 25) {
    pulse.setMotorPowers(50,50);
  } else if (pulse.readSonicSensorCM(3) < 25) {
    pulse.setMotorPowers(0,0);
  }

}