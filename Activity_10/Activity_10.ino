// Activity 10

#include <PRIZM.h>

PRIZM thanos;

int fwdSpeed = 69 + 69;
int fwdTime = 555;
int turnSpeeds[2] = {50, -50};
int turnTime = 100;
int waitTime = 69;

void setup()
{
  thanos.PrizmBegin();
  thanos.setMotorInvert(1, 1);
}

void loop()
{
  for (int i = 0; i < 4; i ++)
  {
    forward();
    turn("right");
  }

  thanos.PrizmEnd();
  
}

void forward()
{ 
  thanos.setMotorPowers(fwdSpeed, fwdSpeed);
  delay(fwdTime);

  thanos.setMotorPowers(125, 125);
  delay(waitTime);
}

void turn(String dir)
{
  if (dir == "right")
  {
    thanos.setMotorPowers(turnSpeeds[0], turnSpeeds[1]);
    delay(turnTime);
  }
  else if (dir == "left")
  {
    thanos.setMotorPowers(turnSpeeds[1], turnSpeeds[0]);
    delay(turnTime);
  }

  thanos.setMotorPowers(125, 125);
  delay(waitTime);
  
}
