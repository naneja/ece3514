//heap_priority_queue.cpp
#include "heap_priority_queue.hpp"
#include <iostream>

int main1() {
    dsac::priority::HeapPriorityQueue<int> pq;

    std::cout << "Inserting elements: 30, 20, 40, 10\n";
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);

    std::cout << "Current size: " << pq.size() << "\n";
    std::cout << "Minimum element: " << pq.min() << "\n";

    std::cout << "Removing minimum element...\n";
    pq.remove_min();
    std::cout << "New minimum element: " << pq.min() << "\n";

    std::cout << "Inserting 5 and 25\n";
    pq.insert(5);
    pq.insert(25);

    std::cout << "Minimum element: " << pq.min() << "\n";
    std::cout << "Removing all elements:\n";

    while (!pq.empty()) {
        std::cout << "Min: " << pq.min() << " -> removing it\n";
        pq.remove_min();
    }

    std::cout << "Priority queue is now empty.\n";

    return 0;
}


int main() {
    // Demonstrate constructor that heapifies from a vector
    std::vector<int> initial_elements = {30, 20, 40, 10};
    dsac::priority::HeapPriorityQueue<int, std::greater<int>> pq(initial_elements);

    std::cout << "Initialized priority queue with elements: 30, 20, 40, 10\n";
    std::cout << "Current size: " << pq.size() << "\n";
    std::cout << "Minimum element after heapify: " << pq.min() << "\n";

    std::cout << "Removing minimum element...\n";
    pq.remove_min();
    std::cout << "New minimum element: " << pq.min() << "\n";

    std::cout << "Inserting 5 and 25\n";
    pq.insert(5);
    pq.insert(25);

    std::cout << "Minimum element: " << pq.min() << "\n";

    std::cout << "Removing all elements:\n";
    while (!pq.empty()) {
        std::cout << "Min: " << pq.min() << " -> removing it\n";
        pq.remove_min();
    }

    std::cout << "Priority queue is now empty.\n";

    return 0;
}