//OrderedTableMap.cpp

#include <iostream>
#include <string>

#include "ordered_table_map.hpp"

int main() {
    dsac::map::OrderedTableMap<std::string, int> map;

    std::cout << "Inserting elements..." << std::endl;
    map.put("banana", 3);
    map.put("apple", 5);
    map.put("cherry", 2);
    map.put("banana", 7);  // Overwrite value

    std::cout << "Current map entries (ordered):" << std::endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << std::endl;
    }

    std::cout << "\nFinding 'banana': ";
    auto it = map.find("banana");
    if (it != map.end())
        std::cout << "Found with value " << it->value() << std::endl;
    else
        std::cout << "Not found" << std::endl;

    std::cout << "\nFinding 'date': ";
    it = map.find("date");
    if (it != map.end())
        std::cout << "Found with value " << it->value() << std::endl;
    else
        std::cout << "Not found" << std::endl;

    std::cout << "\nErasing 'apple'..." << std::endl;
    auto appleIt = map.find("apple");
    if (appleIt != map.end()) {
        map.erase(appleIt);
    }

    std::cout << "Map after erasing 'apple':" << std::endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << std::endl;
    }

    std::cout << "\nTesting lower_bound and upper_bound:" << std::endl;
    auto lb = map.lower_bound("banana");
    if (lb != map.end()) std::cout << "lower_bound('banana') = " << lb->key() << std::endl;

    auto ub = map.upper_bound("banana");
    if (ub != map.end()) std::cout << "upper_bound('banana') = " << ub->key() << std::endl;
    else std::cout << "upper_bound('banana') = end()" << std::endl;

    std::cout << "\nFinal map contents:" << std::endl;
    for (auto it = map.begin(); it != map.end(); ++it)
        std::cout << it->key() << ": " << it->value() << std::endl;

    return 0;
}
