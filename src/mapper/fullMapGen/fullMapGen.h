#include <Arduino.h>

class FullMapGen

{
private:
    vector<int> map;

public:
    void FullMapGen(int *currentLocation, int *relativeMap);
}
