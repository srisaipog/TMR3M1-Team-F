// Sridhar Sairam
// Tele-Op Program
// October 2019

#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PULSE.h>    // TETRIX PULSE Library

PULSE pulse;          // Create an instance within the PULSE Library class named pulse
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int leftX, leftY, rightX, rightY;
int touchX, touchY;
bool stickTime = true;
bool triggerTime = false;

void setup()
{

  pulse.PulseBegin();

  Serial.begin(115200);
}

void loop()
{

  ps4.getPS4();                             

  if(ps4.Connected)
  {                    
      if (stickTime)
      {
        leftX = ps4.Motor(LX); 
        leftY = ps4.Motor(LY);
        rightX = ps4.Motor(RX);
        rightY = ps4.Motor(RY);
        
        pulse.setMotorPowers(leftY, rightY);
      }

      if (triggerTime)
      {
        // leftX = ps4.Button(LX); 
        leftY = ps4.Button(L2T);
        // rightX = ps4.Button(RX);
        rightY = ps4.Button(R2T);
        
        pulse.setMotorPowers(leftY, rightY);
      }

    
    
    
    
      byte group1 = ps4.buttons_1;
      byte group2 = ps4.buttons_2;

      Serial.println(ps4.buttons_1, BIN);
    
      if (ps4.buttons_2 == 7) // Fix This
      {
        if (stickTime)
        {
          stickTime = false;
          triggerTime = true;
        }
        else if (triggerTime)
        {
          stickTime = true;
          triggerTime = false;
        }
      }
      

      touchX = ps4.Touchpad(TOUCHX);
      touchY = ps4.Touchpad(TOUCHY);

      touchX = map(touchX, 0, 100, 0, 180);
      touchY = map(touchY, 0, 100, 0, 180);

      pulse.setMotorDegree(1, 690, touchX);

      
       
  }
  else{                                         // If PS4 is not connected, stop motors
      pulse.setMotorPowers(0,0);
  }

  

  
}
