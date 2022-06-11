#include "relativeMapGen.h"

RelativeMapGen::RelativeMapGen(int *mapArray)
{
    this->map = mapArray;
    sharpMountServo.attach(servoPin);
}
RelativeMapGen::RelativeMapGen()
{
    sharpMountServo.attach(servoPin);
}

RelativeMapGen::RelativeMapGen(uint8_t sharpPin, uint8_t servoPin, int *mapArray)
{
    this->sharpIrPin = sharpPin;
    this->servoPin = servoPin;
    this->map = mapArray;
    sharpMountServo.attach(servoPin);
    // this->sharp = new Sharp(sharpPin);
}

bool RelativeMapGen::isInRange(float sharpReading, int blockVal)
{
    if (sharpReading >= blockVal - 5 && sharpReading <= blockVal + 5)
    {
        return true;
    }
    return false;
}

bool RelativeMapGen::checkForObstacle(int index)
{
    float distance = this->sharp.getDistance();
    if (isInRange(distance, this->dist[index]))
    {
        // Serial.println("Obstacle detected at");
        // Serial.println(mapBlock[index][0]);
        // Serial.println(mapBlock[index][1]);
        return (true);
    }
}

void RelativeMapGen::updateMap(int *map)
{
    int distance;
    if (this->clockwise)
        this->clockwise = false;
    {
        for (int index = 0; index < 15; index++)
        {
            sharpMountServo.write(angles[index]);
            if (this->checkForObstacle(index))
            {
                map[mapBlock[index][0]][mapBlock[index][1]] += 1;
            }
        }
    }
}