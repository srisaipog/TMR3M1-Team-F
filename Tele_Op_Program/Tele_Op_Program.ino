
// Tele_Op_Program
// Using PS4 Controller

// Sridhar Sairam

// October 2019

#include <PRIZM.h>
#include <TELEOP.h>
#include <PULSE.h>

PRIZM prizm;
PS4 ps4;
// PULSE pulse;

// Analog sticks
int left_y, left_x, right_y, right_x;

// Buttons
bool left, right, down, up, x, y, a, b;


void setup()
{
  ps4.getPS4();
  Serial.begin(9600);
}


void loop()
{
  getMotors();
  
  // left_y = map(left_y, 0, 255, -00, 100);
  // left_x = map(left_x, 0, 255, -100, 100);

  Serial.write(left_x);
  Serial.write(left_y);
  //Serial.write("");
  delay(500);
  

  // prizm.setMotorSpeeds(left_);
  
}

void getMotors()
{
  ps4.getPS4();
  left_y = ps4.Stick(LY);
  left_x = ps4.Stick(LX);

  right_y = ps4.Stick(RY);
  right_x = ps4.Stick(RX);
  
}
