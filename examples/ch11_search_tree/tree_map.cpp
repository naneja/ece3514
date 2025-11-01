// tree_map.cpp
#include <iostream>
#include <string>

#include "tree_map.hpp"


int main() {
    dsac::search_tree::TreeMap<int, std::string> map;

    std::cout << "Inserting elements...\n";
    map.put(30, "thirty");
    map.put(10, "ten");
    map.put(20, "twenty");
    map.put(40, "forty");

    std::cout << "\nMap contents (in-order):\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << "\n";
    }

    std::cout << "\nTrying to find key 20:\n";
    auto found = map.find(20);
    if (found != map.end()) {
        std::cout << "Found: " << found->key() << " => " << found->value() << "\n";
    } else {
        std::cout << "Key 20 not found.\n";
    }

    std::cout << "\nErasing key 10...\n";
    auto to_erase = map.find(10);
    if (to_erase != map.end()) {
        map.erase(to_erase);
    }

    std::cout << "\nMap after erasure:\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << "\n";
    }

    std::cout << "\nLower bound for 25:\n";
    auto lb = map.lower_bound(25);
    if (lb != map.end()) {
        std::cout << "Lower bound: " << lb->key() << " => " << lb->value() << "\n";
    } else {
        std::cout << "No lower bound found.\n";
    }

    std::cout << "\nUpper bound for 30:\n";
    auto ub = map.upper_bound(30);
    if (ub != map.end()) {
        std::cout << "Upper bound: " << ub->key() << " => " << ub->value() << "\n";
    } else {
        std::cout << "No upper bound found.\n";
    }

    std::cout << "\nFinal size of map: " << map.size() << "\n";

    return 0;
}