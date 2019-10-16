#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  pulse.setGreenLED(HIGH);
  delay(5000);
  pulse.setGreenLED(LOW);
  pulse.setYellowLED(HIGH);
  delay(5000);
  pulse.setYellowLED(LOW);
  pulse.setRedLED(HIGH);
  delay(5000);
  pulse.setRedLED(LOW);

}