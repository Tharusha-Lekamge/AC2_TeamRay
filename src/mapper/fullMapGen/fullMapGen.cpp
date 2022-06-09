#include "fullMapGen.h"
#include "stdio.h"
#include <iostream>
#include <cmath>

void FullMapGen::initData(std::vector<std::vector<int>> fullMapIn)
{
    this->fullMap = fullMapIn;
}

int main()
{
    FullMapGen f;
    std::vector<std::vector<int>> fullMap = {
        {0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 1}};
    std::vector<std::vector<int>>
        relMap = {{0, 1, 0},
                  {1, 1, 1},
                  {0, 0, 1}};

    f.initData(fullMap);
    f.printVec();
    f.updateMap({4, 0}, relMap);
    std::cout << "---------------" << std::endl;
    f.printVec();
}

void FullMapGen::printVec()
{
    std::vector<std::vector<int>> v = this->fullMap;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool FullMapGen::updateMap(std::vector<int> currPos, std::vector<std::vector<int>> relMapIn)
{
    // startX = column no.
    int startX = currPos[0] - floor(relMapIn[0].size() / 2);
    // startY = row no.
    int startY = currPos[1] - floor(relMapIn.size() / 2);
    for (int i = 0; i < relMapIn.size(); i++)
    {
        for (int j = 0; j < relMapIn[i].size(); j++)
        {
            if (startX + i >= 0 && startY + j >= 0 && startX + i < this->fullMap.size() && startY + j < this->fullMap[0].size())
            {
                this->fullMap[startX + i][startY + j] += relMapIn[i][j];
            }
        }
    }
}