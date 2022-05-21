#include "sharp.h"

Sharp::Sharp(int sharpPin)
{
    sharpSensorVolt = 0;
    Vr = 5.0;
    sharpSensorVal = 0;
    sum = 0;
    distance = 0;
}

Sharp::getDistance()
{
    sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum = sum + float(analogRead(sharpIrPin));
    }

    sharpSensorVal = sum / 100;
    sharpSensorVolt = sharpSensorVal * Vr / 1024;

    distance = pow(sharpSensorVolt * (1 / k1), 1 / k2);
    return (distance)
}
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
