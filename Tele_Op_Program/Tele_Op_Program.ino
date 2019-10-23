// Sridhar Sairam
// Tele-Op Program
// October 2019

// Fix: Line sensor and servo motor


#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int leftSpeed, rightSpeed;
int servo;
int distance;
bool line = false;

int lineInput = 3;
int sonicInput = 3;
int servoInput = 0;

void setup()
{
  pulse.PulseBegin();
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
    pulse.setMotorDegree(servoInput, 690, servo);
    pulse.setMotorPowers(leftSpeed, rightSpeed);   
  }
}


void ultraSonicSensing()
{
  // Makes sure Robot is not to close to object
  ps4.getPS4();
  
  distance = pulse.readSonicSensorCM(sonicInput);
  
  if (distance <= 15)
  {
    if (leftSpeed >= 0)
    {
      leftSpeed = 0;
    }
    if (rightSpeed >= 0)
    {
      rightSpeed = 0;
    }
    
    ps4.setLED(RED);
  }
  else if (distance <= 30)
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
  servo = ps4.Touchpad(TOUCHX);
  servo = map(servo, 0, 100, 0, 180);
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
  if (pulse.readLineSensor(lineInput) == HIGH)
    {
      leftSpeed = 30;
      rightSpeed = 30;
      ps4.setLED(GREEN);
    }
    else if (pulse.readLineSensor(lineInput) == LOW)
    {
      ps4.setLED(RED);

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
          delay(100 * i);
          
          ps4.getPS4();
          if (pulse.readLineSensor(lineInput) == HIGH)
          {
            break;
          }


          pulse.setMotorPowers(-20, 20);
          delay(100 * i * 2);
          
          ps4.getPS4();
          if (pulse.readLineSensor(lineInput) == HIGH)
          {
            break;
          }
        }
          
       }
    }
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
