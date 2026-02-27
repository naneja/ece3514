#include <iostream>

int main(){
    int cols{3};
    int rows{2};
    int **mat = new int*[rows];

    for(int r{0}; r<rows; r++){
        mat[r] = new int[cols];
        for(int c{0}; c<cols; c++)
            mat[r][c] = r+c;
    }

    for(int r{0}; r<rows; r++){
        for(int c{0}; c<cols; c++)
            std::cout << mat[r][c] << " ";
        std::cout << "\n";
    }

    for(int r{0}; r<rows; r++)
        delete[] mat[r];
    delete[] mat;

}
/*
0 1 2 
1 2 3 
*/