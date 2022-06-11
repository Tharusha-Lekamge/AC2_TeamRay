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
}
void loop()
{
    delay(1000);
}
