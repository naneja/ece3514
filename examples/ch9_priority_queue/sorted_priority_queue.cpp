//sorted_priority_queue.cpp

#include <iostream>
#include "sorted_priority_queue.hpp"

int main() {
    dsac::priority::SortedPriorityQueue<int, std::greater<int>> pq;

    pq.insert(5); pq.insert(2);
    pq.insert(9); pq.insert(1);
    pq.insert(4);

    std::cout << "Descending order: ";
    while (!pq.empty()) {
        std::cout << pq.min() << " ";
        pq.remove_min();
    }
    std::cout << "\n";
}
//Descending order: 9 5 4 2 1 