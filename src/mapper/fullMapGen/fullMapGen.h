#pragma once
#include "stdio.h"
#include <iostream>
#include <cmath>
#include <Vector.h>

class FullMapGen
{
private:
public:
    std::vector<std::vector<int>> fullMap;
    std::vector<std::vector<int>> relMap;

    void initData(std::vector<std::vector<int>> fullMapIn);
    int testing();
    /*currPos format = {row index, column index}*/
    bool updateMap(std::vector<int> currPos, std::vector<std::vector<int>> relMapIn);

    void printVec();
};