# include "grid_path.hpp"
#include <iostream>

int main() {
    int result;
    std::vector<std::vector<int>> grid1 = {
        {0, 1},
        {1, 0}
    };
    result = shortestPathBinaryMatrix(grid1);
    std::cout << "Shortest Path = " << result << "\n"; // 2

    std::vector<std::vector<int>> grid2 = {
        {0, 1},
        {1, 1}
    };
    result = shortestPathBinaryMatrix(grid2);
    std::cout << "Shortest Path = " << result << "\n"; //-1

    std::vector<std::vector<int>> grid3 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    result = shortestPathBinaryMatrix(grid3);
    std::cout << "Shortest Path = " << result << "\n";//4

    std::vector<std::vector<int>> grid4 = {
        {0, 0, 1},
        {1, 0, 1},
        {1, 0, 0}
    };
    result = shortestPathBinaryMatrix(grid4);
    std::cout << "Shortest Path = " << result << "\n";//3

    std::vector<std::vector<int>> grid5 = {
        {0}
    };
    result = shortestPathBinaryMatrix(grid5);
    std::cout << "Shortest Path = " << result << "\n";//1

    std::vector<std::vector<int>> grid6 = {
    {0, 0, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 1},
    {0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 0}
    };

    result = shortestPathBinaryMatrix(grid6);
    std::cout << "Shortest Path = " << result << "\n";//7

}