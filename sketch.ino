#include "src/mapper/fullMapGen/fullMapGen.h"
#include "Arduino.h"
#include "stdio.h"

FullMapGen f;

void setup()
{
    int fullMapIn[6][6] = {
        {0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1}};

    int relMapIn[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}};
    int currPos[2] = {2, 3};

    f.initData_array(fullMapIn);
    f.updateMap_arr(currPos, relMapIn);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            Serial.print(fullMapIn[i][j]);
            Serial.println(" ");
        }
        Serial.println("");
    }

    pinMode(13, OUTPUT);
}
void loop()
{
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(2000);
}
