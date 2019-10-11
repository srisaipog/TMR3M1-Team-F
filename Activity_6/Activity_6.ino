#include <PRIZM.h>

PRIZM robo;

void setup()
{
  robo.PrizmBegin();
  // robo.setMotorInvert(1, 1);    // Inverting motor 1 to be facing the same direction as motor 2
}

int delTime = 1000;

void loop()
{
  robo.setMotorPowers(50, 50);
  delay(delTime);

  robo.setMotorPowers(100, 100);
  delay(delTime);

  robo.setMotorPowers(0, 0);
  delay(delTime);

  robo.setMotorPowers(-100, -100);
  delay(delTime);

  robo.setMotorPowers(-50, -50);
  delay(delTime);

  // Party
  robo.setMotorPowers(25, -25);
  delay(delTime * 3);

  robo.setMotorPowers(-50, 50);
  delay(delTime * 4);

  robo.setMotorPowers(-100, 100);
  delay(delTime * 4);

  robo.setMotorPowers(0, 100);
  delay(delTime * 2);

  robo.setMotorPowers(100, 0);
  delay(delTime * 2);

  // Add light sequence for fun
}
