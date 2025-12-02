#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "grid_path.hpp"

// t00: grid0
TEST_CASE("t00: grid0") {
    int result;
    std::vector<std::vector<int>> grid = {
        {0, 1},
        {1, 0}
    };
    result = shortestPathBinaryMatrix(grid);

    REQUIRE(result == 2);
}