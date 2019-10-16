#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  pulse.setRedLED(HIGH);
  delay(1000);
  pulse.setRedLED(LOW);
  delay(1000);

}