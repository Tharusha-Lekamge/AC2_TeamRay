#include "sharp.h"

Sharp::Sharp()
{
    sharpSensorVolt = 0;
    Vr = 5.0;
    sharpSensorVal = 0;
    sum = 0;
    distance = 0;
    this->sharpPin = 14;
}

Sharp::Sharp(uint8_t sharpPin)
{
    this->sharpSensorVolt = 0;
    this->Vr = 5.0;
    this->sharpSensorVal = 0;
    this->sum = 0;
    this->distance = 0;
    this->sharpPin = sharpPin;
};

float Sharp::getDistance()
{
    this->sum = 0;
    for (int i = 0; i < 100; i++)
    {
        this->sum = this->sum + float(analogRead(sharpPin));
    }

    sharpSensorVal = sum / 100;
    sharpSensorVolt = sharpSensorVal * Vr / 1024;

    this->distance = pow(sharpSensorVolt * (1 / k1), 1 / k2);
    // distance = (sharpSensorVolt * (1 / k1)) * *(1 / k2);
    return (this->distance);
};
