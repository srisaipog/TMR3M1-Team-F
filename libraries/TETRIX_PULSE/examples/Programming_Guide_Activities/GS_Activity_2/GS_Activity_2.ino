#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  pulse.setMotorPower(1,50);
  delay(5000);
  pulse.setMotorPower(1,-50);
  delay(5000);

}