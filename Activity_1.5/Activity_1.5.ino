// Activity 2

#include <PRIZM.h>

PRIZM kebab;

void setup()
{
  kebab.PrizmBegin();
}

int bde = 1;

void loop()
{
  /*
  kebab.setRedLED(HIGH);
  delay(bde);
  kebab.setRedLED(LOW);
  kebab.setGreenLED(HIGH);
  delay(bde);
  kebab.setGreenLED(LOW);
  */

  for (int i = 0; i > 254; i++)
  {
    kebab.setRedLED(i);
    kebab.setGreenLED(i);
    delay(bde);
  }
  for (int j = 0; j < 1; j--)
  {
    kebab.setRedLED(j);
    kebab.setGreenLED(j);
    delay(bde);
  }

}
