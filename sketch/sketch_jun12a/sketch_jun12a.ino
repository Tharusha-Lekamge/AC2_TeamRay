#include "fullMapGen.h"

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

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
    FullMapGen f;

    f.initData_array(fullMapIn);
    f.updateMap_arr(currPos, relMapIn);

    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(100);                      // wait for a second

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            Serial.print(fullMapIn[i][j]);
            Serial.print(" ");
        }
        Serial.println(" ");
    }
    delay(2000);
}
