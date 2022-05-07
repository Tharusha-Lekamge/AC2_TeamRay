#include "Servo.h"

class ObstDetector
{
private:
    Servo servo; // Servo motor
    int angle;
    float distance;
    int sharpModel = 1080

        const int proximArray[6][11];  // Stores angles and dist to the cells
    int proximObsArray[13][13];        // Stores detected obstacles in locations
    int angles[100];

public:
    ObstDetector(Servo servo, int sharpPin)
    {
        int analogPin = sharpPin;
        float sensorVal = 0;
        float sensorVolt = 0;
        float Vr = 5.0;
        float sum = 0;
        float k1 = 16.7647563;
        float k2 = -0.85803107;
        float distance = 0;
    };
    void init(); // initialize two arrays
};