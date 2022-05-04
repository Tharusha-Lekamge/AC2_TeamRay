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

/*  hard code an array of tuples (angle,dist)
    from the current position to a specific cell
    in the map.

    keep a blank array of same dimensions to mark obstacles

    rotate the using the angle value in discrete intervals

    measure the distance using sharp

    compare the values of the measured (angle, disatnce)
    with the hard coded array.

    allow for errors

    mark detected obstacles

    returns an 2-d array of detected obstacles.
    With relative position with current location as (0,0)
*/