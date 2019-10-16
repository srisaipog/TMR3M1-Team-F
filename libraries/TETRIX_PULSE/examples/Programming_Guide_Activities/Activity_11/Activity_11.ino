#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  if (pulse.readLineSensor(2) == 0) {
    pulse.setMotorPowers(35,35);
  }
  if (pulse.readLineSensor(2) == 1) {
    pulse.setMotorPowers(0,0);
    while (pulse.readLineSensor(2) == 1) {
      pulse.setRedLED(HIGH);
      delay(500);
      pulse.setRedLED(LOW);
      delay(500);
    }
  }

}