#pragma once

#include <utility> // for std::swap

namespace dsac::list {

// similar to std::forward_list
template <typename T>
class SinglyLinkedList {
    private:
        class Node {
            public:
                Node* next;   // pointer to next node
                T elem;       // element
                Node(const T& element, Node* nxt = nullptr) 
                : elem{element}, next{nxt} {}
        };

        int sz{0};
        Node* head{nullptr};
        Node* tail{nullptr};

    public:
        
        // ToDo: Constructs an empty list
        SinglyLinkedList();

        int size() const {
            // ToDo
        }
    
        bool empty() const {
            // ToDo
        }

        T& front() {
            // ToDo
        }

        const T& front() const {
            // ToDo
        }

        T& back() {
            // ToDo
        }
    
        const T& back() const {
            // ToDo
        }

        void push_front(const T& elem) {
            // ToDo
        }

        void pop_front() {
            // ToDo
        }

        void push_back(const T& elem) {
            // ToDo
        }

    // Concatenate attaches the contents of another list M 
    // to the end of the current list and clears list M.
    // No nodes are copied or allocated; only pointer links are adjusted.
    void concatenate(SinglyLinkedList& M) {
        if (this == &M) 
            return;   // do nothing self-concatenation

        if (M.sz == 0) 
            // ToDo

        if (sz == 0) {
            // ToDo
        } else {
            // ToDo
        }
        // ToDo
    }

    // Reverses the linked list in place
    void reverse() {
        if (sz <= 1) 
            return;  // empty or single-node list
        // ToDo
    }

    class iterator {
        // needed for SinglyLinkedLists's insert_after and erase_after
        friend class SinglyLinkedList;

        private:
            Node* node_ptr;  // pointer to a node

        public:
            iterator(Node* ptr = nullptr) 
            : node_ptr(ptr) {}

            T& operator*() const { 
                // ToDo
            }
            T* operator->() const {
                // ToDo
            }
            iterator& operator++() {
                // ToDo
            }
            iterator operator++(int) {
                // ToDo
            }
            bool operator==(iterator rhs) const {
                // ToDo
            }
            bool operator!=(iterator rhs) const {
                // ToDo
            }
    };

    class const_iterator {
        private:
            Node* node_ptr;  // pointer to a node

        public:
            const_iterator(Node* ptr = nullptr)
            : node_ptr(ptr) {}

            const T& operator*() const {
                // ToDo
            }
            const T* operator->() const {
                // ToDo
            }
            const_iterator& operator++() {
                // ToDo
            }
            const_iterator operator++(int) {
                // ToDo 
            }
            bool operator==(const_iterator rhs) const {
                // ToDo
            }
            bool operator!=(const_iterator rhs) const {
                // ToDo
            }
    };

    iterator begin() {
        // ToDo
    }

    const_iterator begin() const {
        // ToDo
    }

    iterator end() {
        // ToDo
    }

    const_iterator end() const {
        // ToDo
    }

    iterator insert_after(iterator it, const T& elem) {
        // ToDo
    }

    
    iterator erase_after(iterator it) {
        // ToDo
    }

    private:
        // presumes valid empty list when called
        void clone(const SinglyLinkedList& other) {
            // ToDo
        }

    public:
        // non-member function to swap two lists
        friend void swap(SinglyLinkedList& a, SinglyLinkedList& b) {
            // ToDo
        }

        /// resets the list to empty
        void clear() {
            // ToDo
        }

        /// copy constructor
        SinglyLinkedList(const SinglyLinkedList& other) {
            // ToDo
        }

        /// copy assignment
        SinglyLinkedList& operator=(const SinglyLinkedList& other) {
            // ToDo
        }

        /// move constructor
        SinglyLinkedList(SinglyLinkedList&& other) {
            // ToDo
        }

        /// move assignment
        SinglyLinkedList& operator=(SinglyLinkedList&& other) {
            // ToDo
        }

        /// destructor
        ~SinglyLinkedList() { clear(); }

};
}//dsac::list
