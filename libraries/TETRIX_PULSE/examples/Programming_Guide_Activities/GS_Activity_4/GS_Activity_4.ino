#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  if (pulse.readLineSensor(2) == 1) {
    pulse.setRedLED(LOW);
    pulse.setYellowLED(HIGH);
  } else if (pulse.readLineSensor(2) == 0) {
    pulse.setRedLED(HIGH);
    pulse.setYellowLED(LOW);
  }

}