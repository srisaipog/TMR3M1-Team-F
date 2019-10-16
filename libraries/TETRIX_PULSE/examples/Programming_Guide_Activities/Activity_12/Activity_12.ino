#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  if (pulse.readLineSensor(2) == 1) {
    pulse.setMotorPowers(0,50);
    pulse.setRedLED(LOW);
  }
  if (pulse.readLineSensor(2) == 0) {
    pulse.setMotorPowers(50,0);
    pulse.setRedLED(HIGH);
  }

}