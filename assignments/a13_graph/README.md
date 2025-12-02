# A13_Graph Project Assignment: Shortest Path in a Binary Matrix (BFS)

## Problem Description

* You are given an n × n binary grid where:

  * 0 represents an open cell,
  * 1 represents a blocked cell.

* A path is valid if:

  * It starts at the top-left cell (0,0)

  * It ends at the bottom-right cell (n–1,n–1)

  * All visited cells are 0

  * Movement is allowed in 8 directions:

    * ```sh
      right, down, left, up
      up left, up right
      down left, down right
      ```

* Your task is to write a program that returns the length of the shortest path from (0, 0) to (n−1, n−1) using BFS.

* If no such path exists, your program must return -1.



## Starter Code

```cpp
using Grid = std::vector<std::vector<int>>;

// 8 movement directions
std::vector<std::vector<int>> directions = {
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {-1,-1}, {-1,1}, {1,-1}, {1,1}
};

bool valid(const Grid& grid, int row, int col) {
    int n = grid.size();
    // TODO: return true only if (row, col) is inside the grid and grid[row][col] == 0
    // Check bounds before accessing grid[row][col] as it may crash
}

int shortestPathBinaryMatrix(Grid& grid) {
    // TODO: implement BFS using a queue
    // Each queue entry should store a vector: {row, col, path_length}
    // Use an n×n visited matrix to avoid revisiting cells
    // the visited matrix can initially be false 
    // and mark true when the vertex has been visited
}
```



### Implement BFS in shortestPathBinaryMatrix()

* Your BFS must:
  * Use a queue of triplets: {row, col, path_length}
  * Use a $visited[n][n]$ matrix initialized to false
  * Start from (0,0) with path length 1
  * Explore all 8 directions
  * Mark neighbors as visited when pushing into the queue
  * Return the path length when reaching (n−1,n−1)
  * Return -1 if the queue empties without reaching the goal

# Test Cases

```cpp
std::vector<std::vector<int>> grid1 = {
    {0, 1},
    {1, 0}
};
result = shortestPathBinaryMatrix(grid1);
std::cout << "Shortest Path = " << result << "\n"; // 2 diagonal

std::vector<std::vector<int>> grid2 = {
    {0, 1},
    {1, 1}
};
result = shortestPathBinaryMatrix(grid2);
std::cout << "Shortest Path = " << result << "\n"; //-1 (no path)

std::vector<std::vector<int>> grid3 = {
    {0, 0, 0},
    {1, 1, 0},
    {1, 1, 0}
};
result = shortestPathBinaryMatrix(grid3);
std::cout << "Shortest Path = " << result << "\n";//4 (right diagonal down)

std::vector<std::vector<int>> grid4 = {
    {0, 0, 1},
    {1, 0, 1},
    {1, 0, 0}
};
result = shortestPathBinaryMatrix(grid4);
std::cout << "Shortest Path = " << result << "\n";//3 (all diagonal)
```

# Submissions:

* grid_path.hpp
* grid_path.cpp