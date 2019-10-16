#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  pulse.setMotorPower(1,100);
  pulse.setServoSpeed(1,50);
  pulse.setServoPosition(1,90);
  pulse.setRedLED(HIGH);
  delay(1000);
  pulse.setRedLED(LOW);
  pulse.setMotorPower(1,-50);
  pulse.setServoSpeed(1,25);
  pulse.setServoPosition(1,180);
  pulse.setGreenLED(HIGH);
  delay(1000);
  pulse.setGreenLED(LOW);

}