#include <PRIZM.h>

PRIZM prizm;

void setup()
{
  prizm.PrizmBegin();
}

int funnyNum = 167;
// char blips = [.... . .-.. .-.. --- --..-- / .-- --- .-. .-.. -.. -.-.--];

void loop()
{
  prizm.setRedLED(HIGH);

  delay(funnyNum);

  prizm.setRedLED(LOW);

  delay(funnyNum);
  
}
