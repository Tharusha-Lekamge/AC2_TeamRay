//#include "src/mapper/fullMapGen/fullMapGen.h"
#include <arduino.h>
int fullMapIn[6][11] = {
    {0, 1, 0, 1, 2, 3, 0, 0, 0, 0, 0},
    {0, 44, 55, 11, 12, 6, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void setup()
{

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    // Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(100);                      // wait for a second
    // Serial.println("FUCK");
}
