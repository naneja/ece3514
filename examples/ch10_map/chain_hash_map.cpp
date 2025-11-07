//chain_hash_map.cpp

#include "chain_hash_map.hpp"

#include <iostream>
#include <string>

int main() {
    dsac::map::ChainHashMap<std::string, int> map;

    std::cout << "Adding entries:\n";
    map.put("apple", 1);
    map.put("banana", 2);
    map.put("cherry", 3);
    map.put("date", 4);

    std::cout << "Current entries:\n";
    for (auto it = map.begin(); it != map.end(); ++it)
        std::cout << it->key() << ": " << it->value() << "\n";

    std::cout << "\nSize: " << map.size() << "\n";

    std::cout << "\nUpdating 'banana' to 20\n";
    map.put("banana", 20);

    std::cout << "Finding 'banana': ";
    auto it = map.find("banana");
    if (it != map.end())
        std::cout << it->key() << " = " << it->value() << "\n";
    else
        std::cout << "Not found\n";

    std::cout << "\nErasing 'cherry'\n";
    it = map.find("cherry");
    if (it != map.end())
        map.erase(it);

    std::cout << "Entries after erasing:\n";
    for (auto it = map.begin(); it != map.end(); ++it)
        std::cout << it->key() << ": " << it->value() << "\n";

    std::cout << "\nFinal size: " << map.size() << "\n";

    return 0;
}