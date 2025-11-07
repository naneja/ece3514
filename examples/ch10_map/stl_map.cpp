#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, int> m;

    m = {{"RAM", 20}, {"CPU", 10}, {"GPU", 15}};
    
    std::cout << m.at("GPU") << "\n"; // 15

    try {
        std::cout << m.at("SSD") << "\n"; //exception
    } catch (const std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}