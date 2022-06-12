#include "relativeMapGen.h"

RelativeMapGen::RelativeMapGen(int (*relMapIn_arr)[6])
{
    this->relMap_arr = relMapIn_arr;
    sharpMountServo.attach(servoPin);
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
    {
        for (int index = 0; index < 42; index++)
        {
            sharpMountServo.write(angles[index]);
            if (this->checkForObstacle(index))
            {
                relMap_arr[mapBlock[index][0]][mapBlock[index][1]] += 1;
            }
        }
    }
}

// Wadakata Nathi COnstructors
/*RelativeMapGen::RelativeMapGen()
{
    sharpMountServo.attach(servoPin);
}

RelativeMapGen::RelativeMapGen(int sharpPin, int servoPin, int *mapArray)
{
    this->sharpIrPin = sharpPin;
    this->servoPin = servoPin;
    this->map = mapArray;
    sharpMountServo.attach(servoPin);
    // this->sharp = new Sharp(sharpPin);
}*/