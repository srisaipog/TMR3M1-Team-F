// Activity 14

#include <PRIZM.h>

PRIZM man;

int turns[2]= {35, -35};
int turnTime = 500;
int slowSpeed = 50;
int dis, disRight, disLeft;


void setup()
{
  man.PrizmBegin();
  man.setMotorInvert(1, 1);
}

void loop()
{
  dis = man.readSonicSensorCM(4);

  if (dis > 15)
  {
    man.setMotorPowers(slowSpeed, slowSpeed);
    man.setRedLED(LOW);
    man.setGreenLED(HIGH);
  }
  else
  {
    man.setRedLED(HIGH);
    man.setGreenLED(LOW);

    man.setMotorPowers(125, 125);
    delay(100);

    man.setMotorPowers(slowSpeed * -1, slowSpeed * -1);
    delay(turnTime * 2);

    man.setMotorPowers(125, 125);
    delay(100);

    turn("right");
    disRight = man.readSonicSensorCM(4);

    turn("left");
    turn("left");
    disLeft = man.readSonicSensorCM(4);

    turn("right");

    if (disLeft > disRight)
    {

      turn("left");
      
      man.setMotorPowers(slowSpeed, slowSpeed);
      delay(turnTime);

      turn("right");
      
    }
    else // (disRight < disLeft) or (disRight == disLeft)
    {

      turn("right");
      
      man.setMotorPowers(slowSpeed, slowSpeed);
      delay(turnTime);

      turn("left");
    }
    
  }
}


void turn(String di)
{
  if (di == "left")
  {
    man.setMotorPowers(turns[1], turns[0]);
    
  }
  else if (di == "right")
  {
    man.setMotorPowers(turns[0], turns[1]);
  }
  
  delay(turnTime);
  man.setMotorPowers(125, 125);
  delay(turnTime);
  
}
