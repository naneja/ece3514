#include <cstdlib>
#include <iostream>

#include "probe_hash_map.hpp"

#include <sstream>

#define Map ProbeHashMap

int main() {
    dsac::map::Map<std::string,int> freq; // maps strings to count of occurrences
    std::string word;

    std::string text = "apple banana apple orange banana apple";
    std::istringstream input(text);


    while (input >> word) {         // continue reading until ctrl-D
        int count{1};                 // count for this occurrence
        if (freq.contains(word))
            count += freq.at(word);   // and previous occurrences
        freq.put(word, count);
    }

    int max_count{0};
    std::string max_word{""};
    for (dsac::map::Map<std::string,int>::Entry entry : freq) {
        if (entry.value() > max_count) {
            max_count = entry.value();
            max_word = entry.key();
        }
    }
    
    std::cout << "The most frequent word is '" << max_word
         << "' with " << max_count << " occurrences." << std::endl;
}
