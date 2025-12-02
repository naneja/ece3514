#include <vector>

// Alias for 2D grid of ints
using Grid = std::vector<std::vector<int>>;

/*
Returns true if (row, col) is inside the grid 
and is a 0-cell (open)
This prevents accessing grid out of bounds 
and blocks cells containing 1.
*/
bool valid(const Grid &grid, int row, int col);

/*
Performs Breadth-First Search (BFS) to find the shortest path from (0,0) to (n-1,n-1) in an n×n binary matrix.
0 = open cell, 1 = blocked cell
BFS guarantees shortest path in an unweighted grid
*/
int shortestPathBinaryMatrix(Grid &grid);