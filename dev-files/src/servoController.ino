#include "Servo.h"

class ServoController
{
private:
    int nextDir; // 1 for clockwise, 0 for anticlockwise
    int curAngle;
    int pin;
    Servo servo;

public:
    ServoController(int pinNo)
    {
        pin = pinNo;
        curAngle = 0;
    }
    void init()
    {
        servo.attach(pin);
    }
    // ALways add delay after rotating
    bool rotate(int angle)
    {
        curAngle = angle;
        if (curAngle <= 0 || curAngle > 179)
        {
            servo.write(0);
            // delay(50);
        }
        else
        {
            servo.write(curAngle);
            // delay(50);
        }
    }
};