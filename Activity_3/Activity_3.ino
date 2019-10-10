#include <PRIZM.h>

PRIZM obama;


void setup()
{
  obama.PrizmBegin();
  obama.setServoSpeed(1, 69);
}


int di = 69 * 69;

void loop()
{
  obama.setServoPosition(1, 0);
  delay(di);
  obama.setServoPosition(1, 180);
  delay(di);
}
