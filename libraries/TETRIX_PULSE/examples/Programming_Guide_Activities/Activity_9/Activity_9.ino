#include <PULSE.h>
PULSE pulse;

void setup() {
  pulse.PulseBegin();

  pulse.setMotorInvert(1,1);

}

void loop() {
  pulse.setMotorPowers(50,50);
  delay(3000);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,-50);
  delay(1650);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,50);
  delay(3000);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,-50);
  delay(1650);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,50);
  delay(3000);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,-50);
  delay(1650);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.setMotorPowers(50,50);
  delay(3000);
  pulse.setMotorPowers(0,0);
  delay(1000);
  pulse.PulseEnd();
}