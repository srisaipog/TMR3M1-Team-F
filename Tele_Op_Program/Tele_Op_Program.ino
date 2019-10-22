// Sridhar Sairam
// Tele-Op Program
// October 2019

#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int leftX, leftY, rightX, rightY;
int touchX, touchY;
int mode = 0;
int distance;
bool line = false;

void setup()
{
  pulse.PulseBegin();

  Serial.begin(115200);
}

void loop()
{

  ps4.getPS4();                             

  if (ps4.Connected)
  {           

      // DC Motors
      if (mode == 0)
      {
        // Up/down for joysticks
        
        leftX = ps4.Motor(LX); 
        leftY = ps4.Motor(LY);
        rightX = ps4.Motor(RX);
        rightY = ps4.Motor(RY);
      }
      else if (mode == 1)
      {
        // Left Joystick determines direction
        leftX = ps4.Servo(LY)
      }
      

      // Servo Motors
      if (mode == 0)
      {
        touchX = ps4.Touchpad(TOUCHX);
        touchY = ps4.Touchpad(TOUCHY);
  
        touchX = map(touchX, 0, 100, 0, 180);
        touchY = map(touchY, 0, 100, 0, 180);
      }
      else if (mode == 1)
      {
        // Right Joystick determines servo
        
        touchX = ps4.Servo(RY);
      }

      distance = pulse.readSonicSensorCM(3);
      if (distance <= 15)
      {
        if (!(leftY <= 0 && rightY <= 0))
        {
          leftY = 0;
          rightY = 0;
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



      if ((ps4.Button(L2) || ps4.Button(R2)) || (ps4.Button(L1) || ps4.Button(R1)))
      {
        line = true;
      }
      else
      {
        line = false;
      }


      if (line)
      {
        if (pulse.readLineSensor(3) == HIGH)
        {
          rightY = 30;
          leftY = 30;
          ps4.setLED(GREEN);
        }
        else if (pulse.readLineSensor(3) == LOW)
        {
          ps4.setLED(RED);

          for (int i = 0; i < 1; i --)
          {
            ps4.getPS4();
            if (pulse.readLineSensor(3) == LOW)
            {
              pulse.setMotorPowers(-20, 20);
              delay(100 * i)
            }
            ps4.getPS4();
            if (pulse.readLineSensor(3) == LOW)
            {
              ps4.getPS4();
              pulse.setMotorPowers(-20, 20);
              delay(100 * i * 2)
            }
            else
            {
              break;
            }
          }
        }
      }
      
      
      pulse.setMotorDegree(1, 690, touchX);
      pulse.setMotorPowers(leftY, rightY);
      // ps4.setLED(GREEN); // RED, BLUE, YELLOW, GREEN, OFF
       
  }
  
  else
  {
    pulse.setMotorPowers(0,0);
    for (int j = 0; j < 5; j ++)
    {
      ps4.setLED(RED);
      pulse.setRedLED(HIGH);
      delay(50);
      ps4.setLED(OFF);
      pulse.setRedLED(LOW);
      delay(50);
    }
  }

  

  
}
