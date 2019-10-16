#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  if (pulse.readSonicSensorCM(3) > 25) {
    pulse.setMotorPowers(35,35);
    pulse.setRedLED(LOW);
    pulse.setGreenLED(HIGH);
  } else {
    pulse.setGreenLED(LOW);
    pulse.setRedLED(HIGH);
    pulse.setMotorPowers(0,0);
    delay(500);
    pulse.setMotorPowers(-35,-35);
    delay(1000);
    pulse.setMotorPowers(0,0);
    delay(500);
    pulse.setMotorPowers(35,-35);
    delay(500);
  }

}