//We may use UnsortedPriorityQueue, SortedPriorotyQueue, or HeapPriorityQueue
#include "pq_sort.hpp"
#include "heap_priority_queue.hpp"
#include "unsorted_priority_queue.hpp"
#include "sorted_priority_queue.hpp"
#include <iostream>

int main() {
    std::vector<int> values{5, 2, 8, 3, 1, 7};
    
    dsac::priority::pq_sort<int, dsac::priority::HeapPriorityQueue<int>>(values);

    std::cout << "Sorted values using HeapPriorityQueue: ";
    for (int val : values)
        std::cout << val << " ";
    std::cout << "\n";

    values = {5, 2, 8, 3, 1, 7};
    dsac::priority::pq_sort<int, dsac::priority::UnsortedPriorityQueue<int>>(values);

    std::cout << "Sorted values using UnsortedPriorityQueue: ";
    for (int val : values)
        std::cout << val << " ";
    std::cout << "\n";

    values = {5, 2, 8, 3, 1, 7};
    dsac::priority::pq_sort<int, dsac::priority::SortedPriorityQueue<int>>(values);
    
    std::cout << "Sorted values using SortedPriorityQueue: ";
    for (int val : values)
        std::cout << val << " ";
    std::cout << "\n";

    return 0;
}