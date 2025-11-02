// splay_tree_map.cpp
#include <iostream>
#include "splay_tree_map.hpp"


int main() {
    dsac::search_tree::SplayTreeMap<int, std::string> splayMap;

    std::cout << "Inserting values...\n";
    splayMap.put(10, "ten");
    splayMap.put(20, "twenty");
    splayMap.put(5, "five");
    splayMap.put(15, "fifteen");
    splayMap.put(30, "thirty");

    std::cout << "Accessing values (should trigger splay)...\n";
    std::cout << "Value for key 15: " << splayMap.get(15) << "\n";
    std::cout << "Value for key 5: " << splayMap.get(5) << "\n";
    std::cout << "Value for key 10: " << splayMap.get(10) << "\n";

    std::cout << "Removing key 20 (should splay the parent)...\n";
    splayMap.remove(20);

    std::cout << "Final access (should show restructured tree):\n";
    std::cout << "Value for key 30: " << splayMap.get(30) << "\n";

    // If you have a print() or debug traversal function, call it here
    // splayMap.print();

    return 0;
}
