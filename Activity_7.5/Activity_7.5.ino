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

  bored.setMotorPowers(-50, -50);
  delay(3000);

  for (int i = 0; i < 10; i ++)
  {

    bored.setMotorPowers(100, 100);
    delay(100 * i);
  
    bored.setMotorPowers(-100, -100);
    delay(100 * i);

  }
  
  
  bored.PrizmEnd();
}
