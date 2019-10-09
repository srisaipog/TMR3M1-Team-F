// Activity 2

#include <PRIZM.h>

PRIZM kebab;

void setup()
{
  kebab.PrizmBegin();
}

int bde = 90;

void loop()
{

  kebab.setRedLED(HIGH);
  delay(bde);
  kebab.setRedLED(LOW);
  kebab.setGreenLED(HIGH);
  delay(bde);
  kebab.setGreenLED(LOW);
  
}
