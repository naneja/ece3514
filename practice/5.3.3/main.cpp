#include <iostream>
# include <memory>

int main(){
    int cols{3};
    int rows{2};

    std::unique_ptr<std::unique_ptr<int[]>[]> mat;

    mat = std::make_unique<std::unique_ptr<int[]>[]>(rows);

    for(int r{0}; r<rows; r++){
        mat[r] = std::make_unique<int[]>(cols);
        for(int c{0}; c<cols; c++)
            mat[r][c] = r+c;
    }

    for(int r{0}; r<rows; r++){
        for(int c{0}; c<cols; c++)
            std::cout << mat[r][c] << " ";
        std::cout << "\n";
    }

}
/*
0 1 2 
1 2 3
*/