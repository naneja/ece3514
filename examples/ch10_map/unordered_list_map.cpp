//unordered_list_map.cpp
#include <iostream>
#include <string>
#include "unordered_list_map.hpp"

int main() {
    dsac::map::UnorderedListMap<std::string, int> map;

    std::cout << "Map initially empty? " << std::boolalpha << map.empty() << "\n";

    // Insert some key-value pairs
    map.put("apple", 1);
    map.put("banana", 2);
    map.put("cherry", 3);
    map.put("date", 4);

    std::cout << "Size after 4 insertions: " << map.size() << "\n";

    // Iterate and print
    std::cout << "Entries in the map:\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << " -> " << it->value() << "\n";
    }

    // Test find and contains
    std::string key = "banana";
    std::cout << "Map contains \"" << key << "\"? " << map.contains(key) << "\n";

    // Test at()
    try {
        std::cout << "Value associated with \"" << key << "\": " << map.at(key) << "\n";
    } catch (std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    // Test overwrite with put()
    map.put("banana", 20);
    std::cout << "Updated value for \"banana\": " << map.at("banana") << "\n";

    // Erase by key
    bool erased = map.erase("cherry");
    std::cout << "Erase \"cherry\"? " << erased << "\n";

    // Try erasing a key that doesn't exist
    erased = map.erase("grape");
    std::cout << "Erase \"grape\"? " << erased << "\n";

    // Erase by iterator (removing "date")
    auto it = map.find("date");
    if (it != map.end()) {
        map.erase(it);
        std::cout << "\"date\" erased using iterator.\n";
    }

    // Final map contents
    std::cout << "Final entries in the map:\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->key() << " -> " << it->value() << "\n";
    }

    std::cout << "Final size: " << map.size() << "\n";
    std::cout << "Map empty? " << map.empty() << "\n";

    return 0;
}
