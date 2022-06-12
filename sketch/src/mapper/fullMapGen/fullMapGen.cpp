#include "C:\Users\LENOVO\Documents\GitHub\AC2_TeamRay\sketch\src\mapper\fullMapGen\fullMapGen.h"
#include "stdio.h"
// #include <iostream>
// #include <cmath>

// void FullMapGen::initData(std::vector<std::vector<int>> fullMapIn)
// {
//     this->fullMap = fullMapIn;
// }

void FullMapGen::initData_array(int (*fullMapIn_arr)[6])
{
    this->fullMap_arr = fullMapIn_arr;
}
int main()
{
}

/*// int main()
// {
//     FullMapGen f;
//     // std::vector<std::vector<int>> fullMap = {
//     //     {0, 1, 0, 0, 0, 1},
//     //     {1, 0, 1, 0, 0, 1},
//     //     {1, 1, 1, 0, 0, 1},
//     //     {0, 0, 1, 1, 0, 1},
//     //     {1, 0, 0, 0, 1, 1},
//     //     {1, 1, 0, 1, 1, 1}};
//     // std::vector<std::vector<int>>
//     //     relMap = {{0, 1, 0},
//     //               {1, 1, 1},
//     //               {0, 0, 1}};

//     // f.initData(fullMap);
//     // f.printVec();
//     // f.updateMap({2, 3}, relMap);
//     // std::cout << "---------------" << std::endl;
//     // f.printVec();

//     int fullMapIn[6][6] = {
//         {0, 1, 0, 0, 0, 1},
//         {1, 0, 1, 0, 0, 1},
//         {1, 1, 1, 0, 0, 1},
//         {0, 0, 1, 1, 0, 1},
//         {1, 0, 0, 0, 1, 1},
//         {1, 1, 0, 1, 1, 1}};

//     int relMapIn[3][3] = {
//         {0, 1, 0},
//         {1, 1, 1},
//         {0, 0, 1}};

//     int currPos[2] = {2, 3};

//     f.initData_array(fullMapIn);
//     f.printMap_arr();
//     f.updateMap_arr(currPos, relMapIn);
//     f.printMap_arr();
// }

// void FullMapGen::printMap_arr()
// {
//     int(*v)[6] = this->fullMap_arr;

//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = 0; j < 6; j++)
//         {
//             std::cout << v[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }*/

void FullMapGen::updateMap_arr(int *currentPos_arr, int (*relMap_arr)[3])
{
    int relMapsize = (sizeof(relMap_arr[0]) / sizeof(relMap_arr[0][0]) / 2);

    int startX = currentPos_arr[0] - relMapsize;
    int startY = currentPos_arr[1] - relMapsize;

    for (int i = 0; i < (sizeof(relMap_arr[0]) / sizeof(relMap_arr[0][0])); i++)
    {
        for (int j = 0; j < (sizeof(relMap_arr[0]) / sizeof(relMap_arr[0][0])); j++)
        {
            if (startX + i >= 0 && startY + j >= 0 && startX + i < sizeof(fullMap_arr[0]) / 4 && startY + j < sizeof(fullMap_arr[0]) / 4)
            {
                this->fullMap_arr[startX + i][startY + j] += relMap_arr[i][j];
            }
        }
    }
}

/*
// void FullMapGen::printVec()
// {
//     std::vector<std::vector<int>> v = this->fullMap;
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             std::cout << v[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// bool FullMapGen::updateMap(std::vector<int> currPos, std::vector<std::vector<int>> relMapIn)
// {
//     // startX = column no.
//     int startX = currPos[0] - floor(relMapIn[0].size() / 2);
//     // startY = row no.
//     int startY = currPos[1] - floor(relMapIn.size() / 2);
//     for (int i = 0; i < relMapIn.size(); i++)
//     {
//         for (int j = 0; j < relMapIn[i].size(); j++)
//         {
//             if (startX + i >= 0 && startY + j >= 0 && startX + i < this->fullMap.size() && startY + j < this->fullMap[0].size())
//             {
//                 this->fullMap[startX + i][startY + j] += relMapIn[i][j];
//             }
//         }
//     }
// }
*/