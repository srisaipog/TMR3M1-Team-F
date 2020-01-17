/* Example Sketch demonstrating how to control two TETRIX TorqueNADO DC motors using a SONY PS4 gaming controller.
 * Motor Channel 1 is controlled by PS4 Left Joystick Y axis
 * Motor Channel 2 is controlled by PS4 Right Joystick Y axis
 * Hardware: TETRIX PRIZM, TeleOp module and SONY PS4 gaming controller.
 * Date: 09/26/2018
 * Author: PWU
 */



#include <TELEOP.h>   // TETRIX TeleOp module Library
#include <PRIZM.h>    // TETRIX PRIZM Library

PRIZM prizm;          // Create an instance within the PRIZM Library class named prizm
PS4 ps4;              // Create an instance within the PS4 Library class named ps4

int PowerM1;          // Channel 1 Motor Power 
int PowerM2;          // Channel 2 Motor Power
int degree;

// prizm.setMotorInvert(1, 1);
// prizm.setMotorInvert(2, 1);

void setup() {

  prizm.PrizmBegin();            // Intializes the PRIZM controller and waits here for press of green start button
  // ps4.setDeadZone (LEFT,10);     // Sets a Left Joystick Dead Zone axis range of +/- 10 about center stick
  // ps4.setDeadZone(RIGHT,10);     // Sets a Right Joystick Dead Zone axis range of +/- 10 about center stick

  prizm.setServoSpeed(2,100);
  prizm.setServoSpeed(1,100);
  //Serial.begin(9600);

}

void loop() {

  ps4.getPS4();                                 // Get (read) PS4 connections status and all PS4 button and joystick data values

  if(ps4.Connected){                            // If PS4 controller has been succesfully connected, control motors
      PowerM1 = ps4.Motor(LY);                  // Power (speed) and direction of Motor 1 is set by position of Left Y-axis Joystick
      PowerM2 = ps4.Motor(RY);                  // Power (speed) and direction of Motor 2 is set by position of Right Y-axis Joystick
      prizm.setMotorPowers(-1 * PowerM1,-1 * PowerM2); 
      
      degree = ps4.Touchpad(TOUCHX);

      // Serial.print(degree);
      // Serial.print("/n");
      

      if (degree < 20)
      {
        degree = 0;
      }
      else if (degree > 1900)
      {
        degree = 180;
      }
      else
      {
        degree = map(degree,
                     0,
                     1920,
                     0,
                     180);
      }

      prizm.setServoPosition(1, degree);
      prizm.setServoPosition(2, degree);
      


  }
  else{                                         // If PS4 is not connected, stop motors
      prizm.setMotorPowers(0,0);
  }

  
}
