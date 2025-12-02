#include <queue>
#include <string>

#include "grid_path.hpp"

// All 8 possible movement directions
//(right, down, left, up, diagonals)
// Each entry is {row_change, col_change}
std::vector<std::vector<int>> directions = 
    {{0, 1}, //right
    {1, 0},  //down
    {0, -1}, //left
    {-1, 0}, //up
    {-1, -1}, //up left
    {-1, 1}, //up right
    {1, -1}, //down left
    {1, 1} //down right
};

/*
Returns true if (row, col) is inside the grid 
and is a 0-cell (open)
This prevents accessing grid out of bounds 
and blocks cells containing 1.
*/
bool valid(const Grid &grid, int row, int col) {

}

/*
Performs Breadth-First Search (BFS) to find the shortest path from (0,0) to (n-1,n-1) in an n×n binary matrix.
0 = open cell, 1 = blocked cell
BFS guarantees shortest path in an unweighted grid
*/
int shortestPathBinaryMatrix(Grid &grid) {
    
}