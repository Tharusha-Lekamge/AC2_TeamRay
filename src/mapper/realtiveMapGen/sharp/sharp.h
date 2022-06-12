#pragma once
#include "Arduino.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// SYSTEM VARIABLES

class Sharp
{
private:
    float sharpSensorVolt = 0;
    float Vr = 5.0;

    float sharpSensorVal = 0; // Vaue of the sensor in pin
    float sum = 0;            // To store sum of sharpSensorVal to get an average reading within a time
    float distance = 14;      // Measured distance from the sharpSensor

    // constants taken after interpolation to get voltage -> distance conversion
    float k1 = 16.7647563;
    float k2 = -0.85803107;
    int sharpPin = 14;

public:
    Sharp();
    Sharp(uint8_t sharpPin);
    float getDistance();
};