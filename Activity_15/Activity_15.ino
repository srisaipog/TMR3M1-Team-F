// Activity 15

#include <PRIZM.h>

PRIZM fi;


void setup()
{
  fi.PrizmBegin();
  fi.setMotorInvert(1, 1);

  fi.setServoSpeed(1, 50);
}


void loop()
{
  if (fi.readLineSensor(3) == 1)
  {
    fi.setMotorPowers(30, 125);
    fi.setRedLED(HIGH);
  }
  else
  {
    fi.setMotorPowers(125, 30);
    fi.setRedLED(LOW);
  }


  while (fi.readSonicSensorCM(4) < 25)
  {
    fi.setGreenLED(HIGH);
    fi.setMotorPowers(125, 125);
    fi.setServoPosition(1, 0); 
  }

  fi.setGreenLED(LOW);
  fi.setServoPosition(1, 90);
  
}
