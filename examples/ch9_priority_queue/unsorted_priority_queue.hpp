//unsorted_priority_queue.hpp
#pragma once
#include <functional> //std::less
#include <list>

namespace dsac::priority {

template <typename Entry, typename Compare=std::less<Entry>>
class UnsortedPriorityQueue {
    protected:
        //underlying collection
        std::list<Entry> data;
        //less_than(a,b) defines "a < b" relationship
        Compare less_than;
    private:
        typedef typename std::list<Entry>::const_iterator const_iterator;  // convenient shorthand
    
        // utility to locate the minimum entry
        const_iterator find_min() const {
            const_iterator small{data.begin()};
            const_iterator walk{++data.begin()};
            while (walk != data.end()) {
                // walk's entry is "less than" small's entry
                if (less_than(*walk, *small))
                    small = walk;
                ++walk;
            }
            return small;
        }
    public:
        UnsortedPriorityQueue() {} // default empty
        int size() const {
            return data.size(); 
        }
        bool empty() const {
            return data.empty(); 
        }
        void insert(const Entry& e) {
            data.push_back(e); 
        }
        const Entry& min() const {
            return *find_min(); 
        }
        void remove_min() {
            data.erase(find_min()); 
        }
    
};
} // namespace dsac::priority
