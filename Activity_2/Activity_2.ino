// Activity 2

#include <PRIZM.h>

PRIZM kebab;

void setup()
{
  kebab.PrizmBegin();
}

int k = 0;

void loop()
{

  for (int i = 0; i < 100; i++)
  {
      kebab.setMotorPower(2, i);
  }

  delay(1000);
  
  for (int j = 100; j > 0; j--)
  {
    kebab.setMotorPower(2, j);
  }

  // kebab.setMotorPower(2, 100);

}
