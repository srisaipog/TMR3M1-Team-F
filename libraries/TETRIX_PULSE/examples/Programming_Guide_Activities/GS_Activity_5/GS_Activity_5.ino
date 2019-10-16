#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  if (pulse.readSonicSensorCM(3) > 10) {
    pulse.setRedLED(LOW);
    pulse.setYellowLED(HIGH);
  } else if (pulse.readSonicSensorCM(3) < 10) {
    pulse.setRedLED(HIGH);
    pulse.setYellowLED(LOW);
  }

}