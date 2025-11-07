#include <iostream>
#include <utility>
#include <vector>

#include "ordered_table_map.hpp"
#include "cost_performance.hpp"


template <typename OrderedMap>
void validate(const dsac::map::CostPerformanceDatabase<OrderedMap>& db) {
    int oldCost{-1}, oldPerf{-1};
    for (auto entry : db) {
        if (entry.value() <= oldPerf)
            std::cout << "(" << oldCost << "," << oldPerf << ") dominates (" << entry.key() << "," << entry.value() << ")" << std::endl;
        oldCost = entry.key();
        oldPerf = entry.value();
    }
    
}

int main() {
    dsac::map::CostPerformanceDatabase database;

    std::vector<std::pair<int,int>> sample = {
        {10,20}, {20,30}, {30,40}, {40,50}, {50,60}, {60,70}, {70,80}, {80,90},
        {100,5}, {100,90}, {100,85}, {65,5}, {65,85}, {35,100}, {1,100}
    };

    for (auto pair : sample) {
        database.add(pair.first, pair.second);
        validate(database);
        for (auto entry : database) 
            std::cout << "(" << entry.key() << "," << entry.value() << ") ";
        std::cout << std::endl;
    }
    
}
