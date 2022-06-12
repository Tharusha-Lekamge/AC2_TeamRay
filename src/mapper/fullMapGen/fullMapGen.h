#include "stdio.h"

class FullMapGen
{
private:
public:
    /*============Vector Implementation(Fully functioning)=======================*/
    /*currPos format = {row index, column index}*/
    // std::vector<std::vector<int>> fullMap;
    // std::vector<std::vector<int>> relMap;
    // bool updateMap(std::vector<int> currPos, std::vector<std::vector<int>> relMapIn);
    // void printVec();
    // void initData(std::vector<std::vector<int>> fullMapIn);
    /*============Vector Implementation(Fully functioning)=======================*/

    /*============Array Implementation(Fully Functioning and to be used)=======================*/
    /*currPos format = {row index, column index}*/

    // Array of array pointers
    int (*fullMap_arr)[6];
    void initData_array(int (*ptr)[6]);
    void printMap_arr();
    void updateMap_arr(int *currentPos_arr, int (*relMap_arr)[3]);
    /*============Array Implementation(Fully Functioning and to be used)=======================*/
};
