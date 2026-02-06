#include <iostream>

#include "greeting.hpp"

int main() {
    std::string userName = "Students";
    
    std::cout 
    << GenerateWelcomeMessage(userName) << "\n";
}