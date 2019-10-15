// Activity 12


#include <PRIZM.h>

PRIZM spy;

int fwdSpeed = 169;
int stopSpeed = 10;

// stopSpeed = 125;

void setup()
{
  spy.PrizmBegin();
  spy.setMotorInvert(1, 1);
}

void loop()
{
  if (spy.readLineSensor(3) == 0)
  {
    spy.setMotorPowers(stopSpeed, fwdSpeed);
    spy.setRedLED(LOW);
  }
  else if (spy.readLineSensor(3) == 1)
  {
    spy.setMotorPowers(fwdSpeed, stopSpeed);
    spy.setRedLED(HIGH);
  }
}
