//avl_tree_map.cpp

#include <iostream>
#include "avl_tree_map.hpp"

int main() {
    dsac::search_tree::AVLTreeMap<int, std::string> avl;

    // Insertions
    avl.put(10, "ten");
    avl.put(20, "twenty");
    avl.put(30, "thirty");
    avl.put(25, "twenty-five");
    avl.put(5, "five");
    avl.put(1, "one");

    std::cout << "After insertions:\n";
    for (auto it = avl.begin(); it != avl.end(); ++it)
        std::cout << it->key() << " => " << it->value() << std::endl;

    // Lookup
    auto it = avl.find(25);
    if (it != avl.end())
        std::cout << "Found key 25: " << it->value() << std::endl;
    else
        std::cout << "Key 25 not found." << std::endl;

    // Deletions
    avl.erase(avl.find(10));
    avl.erase(avl.find(30));

    std::cout << "\nAfter deletions:\n";
    for (auto it = avl.begin(); it != avl.end(); ++it)
        std::cout << it->key() << " => " << it->value() << std::endl;

    return 0;
}