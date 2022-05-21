// IMPORTS
#pragma once

#include <Servo.h>
#include "sharp/sharp.h"
#include "Arduino.h"

// servo motor
class RelativeMapGen
{
private:
    uint8_t sharpIrPin = 14;
    uint8_t servoPin = 9;

    int *map;
    int x = 11; // map size
    int y = 11;

    int servoRange = 180; // 180 degree full range of servo motor
    Servo sharpMountServo;
    Sharp sharp(this->sharpIrPin);

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
    RelativeMapGen(int *mapArray);
    // passed map array should be a 2-D array with dimensions 11x11
    RelativeMapGen(uint_8 sharpPin, uint_8 servoPin, int *mapArray);
    bool checkForObstacle(int index);
    void updateMap(int *map);
    bool isInRange(float sharpReading, int blockVal);
};