//RedBlackTreeMap.cpp

#include <iostream>
#include "red_black_tree_map.hpp"

int main() {
    dsac::search_tree::RedBlackTreeMap<int, std::string> rbt;

    std::cout << "Inserting elements...\n";
    rbt.put(10, "ten");
    rbt.put(20, "twenty");
    rbt.put(5, "five");
    rbt.put(15, "fifteen");
    rbt.put(30, "thirty");

    std::cout << "Size after insertions: " << rbt.size() << "\n";

    std::cout << "\nSearching for key 15...\n";
    auto it = rbt.find(15);
    if (it != rbt.end()) {
        std::cout << "Found: " << it->key() << " => " << it->value() << "\n";
    } else {
        std::cout << "Key 15 not found.\n";
    }

    std::cout << "\nIterating over all key-value pairs:\n";
    for (auto iter = rbt.begin(); iter != rbt.end(); ++iter) {
        std::cout << iter->key() << " => " << iter->value() << "\n";
    }

    std::cout << "\nRemoving key 20...\n";
    rbt.erase(rbt.find(20));
    std::cout << "Size after deletion: " << rbt.size() << "\n";

    std::cout << "\nTrying to find key 20 again...\n";
    it = rbt.find(20);
    if (it == rbt.end()) {
        std::cout << "Key 20 not found (as expected).\n";
    }

    return 0;
}
