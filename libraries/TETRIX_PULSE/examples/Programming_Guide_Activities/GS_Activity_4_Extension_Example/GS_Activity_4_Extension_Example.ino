#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();
}

void loop() {
  if (pulse.readLineSensor(2) == 1) {
    pulse.setRedLED(LOW);
    pulse.setYellowLED(HIGH);
    pulse.setMotorPower(1,50);
    pulse.setServoSpeed(1,100);
    pulse.setServoPosition(1,180);
  } else if (pulse.readLineSensor(2) == 0) {
    pulse.setRedLED(HIGH);
    pulse.setYellowLED(LOW);
    pulse.setMotorPower(1,-50);
    pulse.setServoSpeed(1,50);
    pulse.setServoPosition(1,0);
  }

}