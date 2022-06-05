#include <Servo.h>
#include "src/mapper/fullMapGen/fullMapGen.h"

void setup()
{
    pinMode(13, OUTPUT);
    FullMapGen f = new FullMapGen();
}

void loop()
{
    Serial.println(f.checking());
    delay(1000);
    Serial.println(f.checking());
    delay(1000);
}
