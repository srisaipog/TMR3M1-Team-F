 // Sridhar Sairam
// Tele-Op Program
// October 2019

#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int leftSpeed, rightSpeed;
int servo;
int distance;
bool line = false;
bool lineFound = false;

int lineInput = 4;
int sonicInput = 3;
int servoInput = 1;

void setup()
{
  pulse.PulseBegin();
  pulse.setServoSpeed(servoInput, 100);
}

void loop()
{
  
  checkPS4Connection();

  motorMoving();

  ultraSonicSensing();

  checkLineMode();
  
  if (line)
  {
    lineMode();
  }
  else
  {
    lineFound = false;
  }

  pulse.setServoPosition(servoInput, servo);
  pulse.setMotorPowers(leftSpeed, rightSpeed);
  
  // pulse.setMotorPowers(15, 15);
}

void checkPS4Connection()
{
  ps4.getPS4();
  
  if(ps4.Connected == false)
  {
    pulse.setMotorPowers(0,0);
    pulse.setRedLED(HIGH);
    pulse.setGreenLED(LOW);
  }
  else
  {
    pulse.setRedLED(LOW);
    pulse.setGreenLED(HIGH);
  }
}


void ultraSonicSensing()
{
  // Makes sure Robot is not to close to object
  ps4.getPS4();
  
  distance = pulse.readSonicSensorCM(sonicInput);
  
  if (distance <= 30)
  {
    if (leftSpeed <= 0)
    {
      leftSpeed = 0;
    }
    if (rightSpeed <= 0)
    {
      rightSpeed = 0;
    }
    
    ps4.setLED(RED);
  }
  else if (distance <= 50)
  {
    ps4.setLED(YELLOW);
  }
  else
  {
    ps4.setLED(GREEN);
  }
}


void motorMoving()
{
  ps4.getPS4();                             
      
  // DC Motors
  // Up/down for joysticks
  leftSpeed = ps4.Motor(LY);
  rightSpeed = ps4.Motor(RY);


  ps4.getPS4();

  // Servo Motors
  // Touchpad X-Axis
  if (ps4.Button(TOUCH))
  {
    servo = ps4.Touchpad(TOUCHX);
    servo = map(servo, 0, 1920, 0, 180);
  }

  // Touchpad Dimensions: 1920 x 900
  
  ps4.getPS4();

  if (ps4.Button(RIGHT) || ps4.Button(UP))
  {
    servo ++;
  }
  if (ps4.Button(LEFT) || ps4.Button(DOWN))
  {
    servo --;
  }
  
  if (servo < 0)
  {
    servo = 0;
  }
  if (servo > 180)
  {
    servo = 180;
  }
  
}


void checkLineMode()
{
  ps4.getPS4();
  if ((ps4.Button(L2) || ps4.Button(R2)) || (ps4.Button(L1) || ps4.Button(R1)))
  {
    line = true;
  }
  else
  {
    line = false;
  }
}


void lineMode()
{
  ps4.getPS4();
  
  if (pulse.readLineSensor(lineInput) == 1)
  {
    if (lineFound == false)
    {
      leftSpeed = 20;
      rightSpeed = 20;
    }
    
  }
  else if(pulse.readLineSensor(lineInput) == 0)
  {
    leftSpeed = 0;
    rightSpeed = 0;
    lineFound = true;
  }
  else
  {
    leftSpeed = -55;
    rightSpeed = 55;
  }

  ps4.setLED(BLUE);
  
  /*
  else if (pulse.readLineSensor(lineInput) == LOW)
  {
    ps4.setLED(RED);

    ps4.getPS4();
    for (int i = 0; i < 1; i --)
    {
      checkLineMode();
      if (line == false)
      {
        break;
      }

      ps4.getPS4();
      if (pulse.readLineSensor(lineInput) == LOW)
      {
        pulse.setMotorPowers(-20, 20);
        
        checkLineMode();
        if (line == false)
        {
          break;
        }
        
        delay(100 * i);

        checkLineMode();
        if (line == false)
        {
          break;
        }
        
        ps4.getPS4();
        if (pulse.readLineSensor(lineInput) == HIGH)
        {
          break;
        }

        pulse.setMotorPowers(-20, 20);

        checkLineMode();
        if (line == false)
        {
          break;
        }
        
        delay(100 * i * 2);

        checkLineMode();
        if (line == false)
        {
          break;
        }
        
        ps4.getPS4();
        if (pulse.readLineSensor(lineInput) == HIGH)
        {
          break;
        }
      }
        
     }
  }
  */
}
