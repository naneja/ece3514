#include "hash_code.hpp"

#include <iostream>
#include <vector>


int main() {
    std::vector<std::string> tokens = {"apple", "banana", "cherry", "dsac", "map"};

    for (const std::string& token : tokens) {
        std::cout << "hash_code(\"" << token << "\") is " << dsac::map::hash_code(token) << std::endl;
    }

}
