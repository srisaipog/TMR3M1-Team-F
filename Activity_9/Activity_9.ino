// Activity 9

#include <PRIZM.h>

PRIZM ticknpaul;

void setup()
{
  ticknpaul.PrizmBegin();
  ticknpaul.setMotorInvert(1, 1);
}

int turn[2] = {-50, 50};
int wait = 1000;
int turnTime = 100;


void loop()
{

  for (int i = 0; i < 4;i ++)

  {

    ticknpaul.setMotorSpeeds(125, 125);
    delay(wait);
  
    ticknpaul.setMotorSpeeds(turn[0],turn[1]);
    delay(turnTime);

  }
  
  
}
