//ProbeHashMap.cpp

#include <iostream>
#include <string>
#include "probe_hash_map.hpp"

int main() {
    dsac::map::ProbeHashMap<std::string, int> map;

    // Insert some key-value pairs
    map.put("apple", 10);
    map.put("banana", 20);
    map.put("cherry", 30);
    map.put("date", 40);

    std::cout << "Initial map contents:\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << "\n";
    }

    // Find an entry
    auto found = map.find("banana");
    if (found != map.end()) {
        std::cout << "\nFound 'banana' with value: " << found->value() << "\n";
    } else {
        std::cout << "\n'banana' not found.\n";
    }

    // Erase an entry
    map.erase(found);

    std::cout << "\nMap contents after erasing 'banana':\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << ": " << it->value() << "\n";
    }

    // Verify if 'banana' is gone
    if (map.contains("banana")) {
        std::cout << "\n'banana' is still in the map.\n";
    } else {
        std::cout << "\n'banana' was successfully removed.\n";
    }

    return 0;
}
