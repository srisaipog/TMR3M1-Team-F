// Activity 8

#include <PRIZM.h>

PRIZM circle;

void setup()
{
  circle.PrizmBegin();

  circle.setMotorInvert(1, 1);

}

int s = 69;
int ti = 3000;

void loop()
{
  circle.setMotorPowers(s, s * 2);
  delay(ti);

  circle.setMotorPowers(0, 0);
  delay(ti / 3);

  circle.setMotorPowers(-1 * s, -2 * s);
  delay(ti);
}
