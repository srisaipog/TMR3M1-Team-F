// Activity_4

#include <PRIZM.h>
PRIZM fbi;

void setup()
{
  fbi.PrizmBegin();
}

void loop()
{
  if (fbi.readLineSensor(3) == HIGH)
  {
    fbi.setRedLED(LOW);
    fbi.setGreenLED(HIGH);
  }
  else if (fbi.readLineSensor(3) == LOW)
  {
    fbi.setRedLED(HIGH);
    fbi.setGreenLED(LOW);
  }

  delay(10); // Just to not overload the loop
}
