#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);
  pulse.setServoSpeed(1,50);

}

void loop() {
  if (pulse.readLineSensor(2) == 1) {
    pulse.setMotorPowers(30,0);
    pulse.setRedLED(HIGH);
  } else {
    pulse.setMotorPowers(0,30);
    pulse.setRedLED(LOW);
    while (pulse.readSonicSensorCM(3) < 25) {
      pulse.setGreenLED(HIGH);
      pulse.setMotorPowers(0,0);
      pulse.setServoPosition(1,0);
    }
    pulse.setGreenLED(LOW);
    pulse.setServoPosition(1,90);
  }

}