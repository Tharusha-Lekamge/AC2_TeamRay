#include "servo.cpp"
#include "sharp.cpp"

class ObstDetector
{
private:
    Servo servo; // Servo motor
    Sharp sharp; // Sharp Sensor

    int angle;
    float distance;

    const int proximArray[13][13]; // Stores angles and dist to the cells
    int proximObsArray[13][13];    // Stores detected obstacles in locations
    int angles[100];

public:
    ObstDetector(int servoPin, int sharpPin);
    void init(); // initialize two arrays
};