#include <PRIZM.h>

PRIZM duck;


void setup()
{
  duck.PrizmBegin();
}

void loop()
{
  duck.setMotorPowers(100, 100);
}
