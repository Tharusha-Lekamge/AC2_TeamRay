// IMPORTS
#include <Servo.h>
#include "sharp/sharp.h"

// Setting up Environment - PINS
// Sharp sensor input
#define sharpIrPin A0
// Servo Motor output
#define servoPin 9

// servo motor
class RelativeMapGen
{
private:
    int sharpIrPin;
    int servoPin;
    int *map;
    int x, y = 11, 11;    // map size
    int servoRange = 180; // 180 degree full range of servo motor
    bool clockwise = true;
    Servo sharpMountServo;
    Sharp sharp;

    // If the robot is facing in +y direction,
    // 0 degrees is to the -x direction
    const int angles[36] =
        {
            0,
            0,
            0,
            0,
            0,
            11,
            14,
            18,
            21,
            27,
            27,
            34,
            45,
            45,
            45,
            45,
            45,
    };
    const int dist[36] =
        {
            10,
            20,
            30,
            40,
            50,
            51,
            41,
            32,
            54,
            22,
            45,
            36,
            14,
            28,
            42,
            56,
            70,
    };
    const int mapBlock[36][2] =
        {
            {0, 1},
            {0, 2},
            {0, 3},
            {0, 4},
            {0, 5},
            {1, 5},
            {1, 4},
            {1, 3},
            {2, 5},
            {1, 2},
            {2, 4},
            {2, 3},
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 4},
            {5, 5},
    };

public:
    // passed map array should be a 2-D array with dimensions 11x11
    RealtiveMapGen(int sharpPin, int servoPin, int *mapArray);
    bool checkForObstacle();
    void updateMap(int *map);
    bool isInRange(float sharpReading, int blockVal);
}