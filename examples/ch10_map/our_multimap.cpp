//OurMultimap.cpp
#include <iostream>
#include <string>
#include "our_multimap.hpp"

int main() {
    dsac::map::OurMultimap<std::string, int> mm;

    std::cout << "Initially, map is empty: " << std::boolalpha << mm.empty() << "\n";
    std::cout << "Initial size: " << mm.size() << "\n\n";

    // Insert key-value pairs
    mm.insert({"Alice", 10});
    mm.insert({"Bob", 20});
    mm.insert({"Alice", 30});
    mm.insert({"Charlie", 40});
    mm.insert({"Bob", 50});

    std::cout << "After inserts:\n";
    std::cout << "Size: " << mm.size() << "\n";
    std::cout << "Count of Alice: " << mm.count("Alice") << "\n";
    std::cout << "Count of Bob: " << mm.count("Bob") << "\n";
    std::cout << "Count of Charlie: " << mm.count("Charlie") << "\n";
    std::cout << "Map is empty: " << mm.empty() << "\n\n";

    // Erase a key
    std::cout << "Erasing key 'Bob'...\n";
    int removed = mm.erase("Bob");
    std::cout << "Number of entries removed: " << removed << "\n";
    std::cout << "Size after erase: " << mm.size() << "\n";
    std::cout << "Count of Bob after erase: " << mm.count("Bob") << "\n\n";

    // Erase non-existent key
    std::cout << "Attempting to erase key 'David'...\n";
    removed = mm.erase("David");
    std::cout << "Number of entries removed: " << removed << "\n\n";

    // Final check
    std::cout << "Final size: " << mm.size() << "\n";
    std::cout << "Map is empty: " << mm.empty() << "\n";

    return 0;
}
