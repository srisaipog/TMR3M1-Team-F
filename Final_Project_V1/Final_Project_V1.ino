#include <TELEOP.h>
#include <PRIZM.h>

PRIZM prizm;
PS4 ps4;

int PowerM1; 
int PowerM2;
int degree;
double mappingRatio = 1 / 11; // (0 + 180) / (0 + 1980)


void setup()
{
    prizm.PrizmBegin();
    prizm.setServoSpeed(1, 75);
}

void loop()
{
    ps4.getPS4();

    if (ps4.Connected)
    {
        PowerM1 = ps4.Motor(LY);
        PowerM2 = ps4.Motor(RY);
        prizm.setMotorPowers(-1 * PowerM1,-1 * PowerM2); 
        
        degree = ps4.Touchpad(TOUCHX);
        // degree = map(degree, 20, 1900, 0, 180);
        degree *= mappingRatio;

        prizm.setServoPosition(1, degree);
        // prizm.setServoPosition(2, degree);

    }
    else
    {
        prizm.setMotorPowers(0, 0);
    }
}
