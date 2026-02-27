#include <iostream>
int main(void) {
    char board[3][5] = {
        {'I','N','R','O','W'},
        {'M','A','J','O','R'},
        {'O','R','D','E','R'}
    };
    // Print the board row by row
    for (int i{0}; i < 3; i++){
        for (int j{0}; j < 5; j++)
            std::cout << board[i][j] << " ";
        std::cout << "\n";
    }
}