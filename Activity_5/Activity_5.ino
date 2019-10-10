// Activity_5

// Figureout how to concatenate the int and string

#include <PRIZM.h>
// #include <String>
PRIZM pew;

void setup()
{
  pew.PrizmBegin();
  Serial.begin(9600);
}

int distance = pew.readSonicSensorCM(3); 
String message1 = "You are "; 
String message2 = " cm away from something.";

void loop()
{
  // Serial.print(message1 + to_string(distance) + message2);

  Serial.print(distance);

  delay(100);
  
}
