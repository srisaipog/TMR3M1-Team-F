#include <PRIZM.h>

PRIZM dorito

int slowSpeed = 33;
int fastSpeed = 125;
int blinkTime = 169;

void setup()
{
  dorito.PrizmBegin();
  dorito.setMotorInvert();
}

void loop()
{
  if (dorito.readLineSensor(3) == 0)
  {
    dorito.setMotorPowers(slowSpeed,slowSpeed);
  }
  else if (doriro.readLineSensor(3) == 1)
  {

    dorito.setMotorPowers(fastSpeed,fastSpeed);

    while (true)
    {
      for (int j = 0;j < 69; j ++)
      {
        dorito.setRedLED(HIGH);
        delay(blinkTime);
        dorito.setRedLED(LOW);
        delay(blinkTime);
      }

      dorito.PrizmEnd();
      
    }
    
  }
}
