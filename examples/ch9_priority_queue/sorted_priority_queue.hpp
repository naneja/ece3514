//sorted_priority_queue.hpp

#pragma once
#include <functional>    // defines std::less
#include <list>

namespace dsac::priority {

template <typename Entry, typename Compare=std::less<Entry>>
class SortedPriorityQueue {
    protected:
        // our underlying collection
        std::list<Entry> data;   
        Compare less_than;// less_than(a,b) defines "a < b"

    public:
        SortedPriorityQueue() {} // default empty

        int size() const {
            return data.size(); 
        }
        
        bool empty() const {
            return data.empty(); 
        }

        void insert(const Entry& e) {
            //iterator is a type inside std::list
            typename std::list<Entry>::iterator walk;
            walk = data.begin();
            // while walk's entry is less than new entry
            while (walk != data.end() && less_than(*walk, e))
                ++walk; // advance walk
            // new element goes before walk
            data.insert(walk, e);
        }
        
        const Entry& min() const {
            return data.front();
        }

        void remove_min() {
            data.pop_front();
        }
};
} // namespace
