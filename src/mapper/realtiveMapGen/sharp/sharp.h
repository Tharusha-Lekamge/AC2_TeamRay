// Sharp sensor input
#define sharpIrPin A0

// SYSTEM VARIABLES

class Sharp
{
private:
    float sharpSensorVolt;
    float Vr;

    float sharpSensorVal; // Vaue of the sensor in pin
    float sum;            // To store sum of sharpSensorVal to get an average reading within a time
    float distance;       // Measured distance from the sharpSensor

    // constants taken after interpolation to get voltage -> distance conversion
    float k1 = 16.7647563;
    float k2 = -0.85803107;

public:
    Sharp(int sharpPin);
    float getDistance();
}