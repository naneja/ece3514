//unsorted_priority_queue.cpp
#include <iostream>

#include "unsorted_priority_queue.hpp"

int main() {
    dsac::priority::UnsortedPriorityQueue<int, std::greater<int>> pq;

    pq.insert(10); pq.insert(5);
    pq.insert(30); pq.insert(1);
    pq.insert(20);

    std::cout << pq.min() << "\n"; // 30
    pq.remove_min();
    if (!pq.empty()) {
        std::cout << pq.min() << "\n"; //20
    }
    return 0;
}