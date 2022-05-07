// IMPORTS
#include <Servo.h>

// Setting up Environment - PINS
// Sharp sensor input
#define sharpIrPin A0
// Servo Motor output
#define servoPin 9

// SYSTEM VARIABLES

float sharpSensorVolt = 0;
float Vr = 5.0;

float sharpSensorVal = 0; // Vaue of the sensor in pin
float sum = 0;            // TO store sum of sharpSensorVal to get an average reading within a time
float k1 = 16.7647563;    // constants taken after interpolation
float k2 = -0.85803107;   // to get voltage -> distance conversion
float distance = 0;       // Measured distance from the sharpSensor

// servo motor
Servo sharpMountServo;

// relative map
const int blockLocationMapAng[6][11] =
    {
        {0, 0, 0, 0, 0, 90, 101, 111, 121, 129, 135},
        {
            0,
            0,
            0,
            0,
            0,
            90,
            104,
        },
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
const int blockLocationMapDist[6][11] =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

const int angles[36] =
    {
        0,
        0,
        0,
        0,
        0,
        11,
        14,
        18,
        21,
        27,
        27,
        34,
        45,
        45,
        45,
        45,
        45,
};

const int dist[36] =
    {
        10,
        20,
        30,
        40,
        50,
        51,
        41,
        32,
        54,
        22,
        45,
        36,
        14,
        28,
        42,
        56,
        70,
};

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

// Support Function
bool isInRange(float sharpReading, int blockVal)
{
  if (sharpReading >= blockVal - 5 && sharpReading <= blockVal + 5)
  {
    return true;
  }
  return false;
}

void setup()
{
  Serial.begin(9600); // To display on the serial display of arduino IDE
  sharpMountServo.attach(servoPin);
}

void loop()
{
  for (int index = 0; index < 15; index++)
  {
    sharpMountServo.write(angles[index]);
    Serial.println("angle is");
    Serial.println(angles[index]);

    sum = 0;
    for (int i = 0; i < 100; i++)
    {
      sum = sum + float(analogRead(sharpIrPin));
    }
    sharpSensorVal = sum / 100;
    sharpSensorVolt = sharpSensorVal * Vr / 1024;

    distance = pow(sharpSensorVolt * (1 / k1), 1 / k2);
    
    Serial.println("disatnce is");
    Serial.println(distance);
    if (isInRange(distance, dist[index]))
    {
      Serial.println("Obstacle detected at");
      Serial.println(mapBlock[index][0]);
      Serial.println(mapBlock[index][1]);
    }
    delay(1000);
  }

  // sum = 0;
  // for (int i = 0; i < 100; i++)
  // {
  //   sum = sum + float(analogRead(analogPin));
  // }
  // sensorVal = sum / 100;
  // sensorVolt = sensorVal * Vr / 1024;

  // distance = pow(sensorVolt * (1 / k1), 1 / k2);
  // Serial.println(distance);
  // delay(500);
}
