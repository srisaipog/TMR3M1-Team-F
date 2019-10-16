#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  pulse.setMotorPower(1,100);
  pulse.setRedLED(HIGH);
  delay(5000);
  pulse.setRedLED(LOW);
  pulse.setMotorPower(1,-50);
  pulse.setGreenLED(HIGH);
  delay(5000);
  pulse.setGreenLED(LOW);

}