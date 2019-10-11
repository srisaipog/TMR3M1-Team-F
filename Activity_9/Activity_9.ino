// Activity 9

#include <PRIZM.h>

PRIZM ticknpaul;

void setup()
{
  ticknpaul.PrizmBegin();
  ticknpaul.setMotorInvert();
}

int turn = [-50, 50]
int wait = 1000;


void loop()
{

  for (int i = 0; i < 4;i ++)

  {
  
    ticknpaul.setMotorSpeeds(turn[0],turn[0]);
    delay(wait);
  
    ticknpaul.setMotorSpeeds(125, 125);
    delay(wait);

  }
  
  
}
