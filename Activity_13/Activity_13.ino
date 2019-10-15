// Activity 13

#include <PRIZM.h>

PRIZM trump;

int fastSpeed = 125;
int slowSpeed = 12;
int distance = 0;

void setup()
{

  trump.PrizmBegin();

  trump.setMotorInvert(1, 1);
  
}

void loop()
{

  distance = trump.readSonicSensorCM(4);
  
  if (distance > 25)
  {
    trump.setMotorPowers(fastSpeed, fastSpeed);
  }
  else if (distance < 5)
  {
    trump.setMotorPowers(125, 125);
  }
  else
  {
    trump.setMotorPowers(distance * 4, distance * 4);
  }
}
