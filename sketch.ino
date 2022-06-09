#pragma once
#include <Vector.h>
#include "src/mapper/fullMapGen/fullMapGen.h"
#include "Arduino.h"
#include "stdio.h"
FullMapGen f;

void setup()
{
}

void loop()
{
    int name = f.testing();
    Serial.println(name);
    delay(2000);
}
