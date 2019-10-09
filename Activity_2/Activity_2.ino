// Activity 2

#include <PRIZM.h>

PRIZM kebab;

void setup()
{
  kebab.PrizmBegin();
}

void loop()
{

  kebab.setRedLED(HIGH);
  delay(150);
  kebab.setRedLED(LOW);
  kebab.setGreenLED(HIGH);
  delay(150);
  kebab.setGreenLED(LOW);
  
}
