// Activity 7

#include <PRIZM.h>

PRIZM bored;

void setup()
{
  bored.PrizmBegin();

  bored.setMotorInvert(1, 1);
  
}

void loop()
{
  bored.setMotorPowers(50, 50);
  delay(3000);
  bored.PrizmEnd();
}
