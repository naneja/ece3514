//heap_priority_queue.hpp
#pragma once
#include <functional>    // defines std::less
#include <vector>

namespace dsac::priority {

template <typename Entry, typename Compare=std::less<Entry>>
class HeapPriorityQueue {
    protected:
        //underlying collection
        std::vector<Entry> data;
        
        // less_than(a,b) defines "a < b" relationship
        Compare less_than;

        // truncating division
        int parent(int j) {
            return (j-1) / 2; 
        }

        int left(int j) {
            return 2 * j + 1; 
        }

        int right(int j) {
            return 2 * j + 2; 
        }

        bool has_left(int j) {
            return left(j) < data.size(); 
        }

        bool has_right(int j) {
            return right(j) < data.size(); 
        }
        
        // Moves entry at index j higher, to restore heap property
        void upheap(int j) {
            // continue to root (or break statement)
            while (j > 0) {
                int p{parent(j)};
                // if j's entry is less than its parent
                if (less_than(data[j], data[p])) {
                    std::swap(data[j], data[p]);
                    j = p; // continue from new location after the swap
                } else
                    break;
            }
        }
        
        /// Moves entry at index j lower, to restore heap property
        void downheap(int j) {
            // continue to bottom (or break statement)
            while (has_left(j)) {
                // although right may be smaller
                int small_child{left(j)};
                if (has_right(j)) {
                    if (less_than(data[right(j)], data[left(j)]))
                        small_child = right(j);
                }

                // if small child's entry is less than j's
                if (less_than(data[small_child], data[j])) {
                    using std::swap;
                    swap(data[j], data[small_child]);
                    // continue from new location after the swap
                    j = small_child;
                } else
                    break;
            }
        }

        void heapify() {
            // start at PARENT of last entry
            int start{parent(data.size()-1)};

            // loop until processing the root
            for (int j = start; j >= 0; j--)
                downheap(j);
        }
            
    public:
        /// Creates an empty priority queue
        HeapPriorityQueue() {}

        /// Creates a priority queue populated with the given entries
        HeapPriorityQueue(const std::vector<Entry>& contents) 
            : data(contents) { heapify(); }
        
        /// Returns the current size of the priority queue
        int size() const {
            return data.size(); 
        }
        
        /// Returns true if the priority queue is empty
        bool empty() const { 
            return data.empty(); 
        }

        /// Returns a constant reference to the minimum entry
        const Entry& min() const {
            return data.front();
        }

        /// Inserts a new entry into the priority queue
        void insert(const Entry& e) {
            // add to the end of the vector
            data.push_back(e);
            // upheap newly added entry
            upheap(data.size() - 1);
        }
        
        /// Removes the minimum entry
        void remove_min() {
            using std::swap;
            // put last entry at the root
            swap(data[0], data[data.size() - 1]);
            // and remove the displaced minimum
            data.pop_back();
            // fix heap property for new root
            downheap(0);
        }
};
} // namespace
