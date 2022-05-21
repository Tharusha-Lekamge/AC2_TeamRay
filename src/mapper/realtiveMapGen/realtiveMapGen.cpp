#include "realtiveMapGen.h"

RelativeMapGen::RealtiveMapGen(int sharpPin, int servoPin, int *mapArray)
{
    this->sharpIrPin = sharpPin;
    this->servoPin = servoPin;
    this->map = mapArray;
    sharpMountServo.attach(servoPin);
    sharp = new Sharp(sharpPin);
}

RelativeMapGen::isInRange(float sharpReading, int blockVal)
{
    if (sharpReading >= blockVal - 5 && sharpReading <= blockVal + 5)
    {
        return true;
    }
    return false;
}

RelativeMapGen::checkForObstacle()
{
    int distance;
    if (this->clockwise)
        this->clockwise = false;
    {
        for (int index = 0; angle < 15; index++)
        {
            sharpMountServo.write(angles[index]);
            disatnce = sharp.getDistance();
            if (isInRange(distance, dist[index]))
            {
                Serial.println("Obstacle detected at");
                Serial.println(mapBlock[index][0]);
                Serial.println(mapBlock[index][1]);
            }
        }
    }
}