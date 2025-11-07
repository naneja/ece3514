#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> M;

    // Check if map is empty
    std::cout << "Initially, M.empty(): " 
        << (M.empty() ? "true" : "false") << "\n";

    // Insert elements using operator[]
    M[1] = "One";
    M[2] = "Two";
    M[3] = "Three";
    std::cout << "\nAfter inserting elements using M[k] = v:\n";
    for (auto &p : M) {
        std::cout << p.first << " -> " << p.second << "\n";
    }

    // Insert using insert()
    auto result = M.insert({2, "Second"});  // Key 2 already exists
    std::cout << "\nInsert with existing key (2): " 
        << (result.second ? "Inserted" : "Key already exists") << "\n";

    auto result2 = M.insert({4, "Four"});   // Key 4 is new
    std::cout << "Insert with new key (4): " 
        << (result2.second ? "Inserted" : "Key already exists") << "\n";

    // Size of the map
    std::cout << "\nM.size(): " << M.size() << "\n";

    // Access using M.at(k)
    try {
        std::cout << "M.at(3): " << M.at(3) << "\n";
        std::cout << "M.at(5): " << M.at(5) << "\n";  // Throws exception
    } catch (const std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << " (Key 5 not found)\n";
    }

    // M.contains(k) (C++20 feature)
#if __cplusplus >= 202002L
    std::cout << "\nM.contains(2): " 
        << (M.contains(2) ? "true" : "false") << "\n";

    std::cout << "M.contains(5): " 
        << (M.contains(5) ? "true" : "false") << "\n";
#else
    std::cout << "\nM.contains is not available. Use M.find(k).\n";
#endif

    // Using find()
    auto it = M.find(2);
    if (it != M.end())
        std::cout << "M.find(2): Found " 
            << it->first << " -> " << it->second << "\n";
    else
        std::cout << "M.find(2): Not found\n";

    // Erase by key
    M.erase(2);
    std::cout << "\nAfter M.erase(2):\n";
    for (auto &p : M) {
        std::cout << p.first << " -> " << p.second << "\n";
    }

    // Erase by iterator
    it = M.find(1);
    if (it != M.end()) {
        M.erase(it);
        std::cout << "\nAfter M.erase(iterator to key 1):\n";
        for (auto &p : M) {
            std::cout << p.first << " -> " << p.second << "\n";
        }
    }

    // Iterate using begin() and end()
    std::cout << "\nIterating with begin() and end():\n";
    for (auto itr = M.begin(); itr != M.end(); ++itr) {
        std::cout << itr->first << " -> " << itr->second << "\n";
    }

    // Check if map is empty after operations
    std::cout << "\nAfter operations, M.empty(): " 
        << (M.empty() ? "true" : "false") << "\n";
}
