## Practice Lab Assignment 6.2: Build a Templated `CircularlyLinkedList<T>`

## Objective

* In this lab, you will implement using a templated circular linked list. You are given the full class interface. Your task is to implement all member functions correctly and safely. This lab gives practice with:
  - templates
  - dynamic memory
  - raw pointers
  - singly linked list operations
  - iterators
  - copy/move semantics

```cpp
#pragma once

#include <utility>     // provides std::swap

namespace dsac::list {

/// circularly linked list
template <typename T>
class CircularlyLinkedList {
    private:
        class Node {
            public:
                T elem;
                Node* next;

                Node(const T& element, Node* nxt = nullptr) 
                : elem{element}, next{nxt} {}
        };
    private:
        int sz{0};
        Node* tail{nullptr};

    public:
        /// Constructs an empty list
        CircularlyLinkedList();

        // ---------- access functions ----------

        /// Returns the number of elements stored
        /// @return the number of elements stored
        int size() const;

        /// Tests whether the list is empty.
        /// @return true if the list is empty, false otherwise
        bool empty() const;

        /// Returns live reference to the first element of the list; behavior undefined if list is empty
        /// @return reference to first element of the list
        T& front();

        /// Returns const reference to the first element of the list; behavior undefined if list is empty
        /// @return reference to first element of the list
        const T& front() const;

        /// Returns live reference to the last element of the list; behavior undefined if list is empty
        /// @return reference to last element of the list
        T& back();

        /// Returns const reference to the last element of the list; behavior undefined if list is empty
        /// @return reference to last element of the list
        const T& back() const;

        // ---------- update functions ----------

        /// Inserts element at the beginning of the list
        /// @param elem   the new element
        void push_front(const T& elem);

        /// Inserts element at the end of the list
        /// @param elem   the new element
        void push_back(const T& elem);

        /// Removes the first element of the list
        void pop_front();

        /// Rotates the first element to the back of the list
        void rotate();
    
    //------------------------------------------------
    // rule-of-five behaviors
    //------------------------------------------------

    private:
        // presumes valid empty list when called
        void clone(const CircularlyLinkedList& other);

    public:
        /// non-member function to swap two lists
        friend void swap(CircularlyLinkedList& a, CircularlyLinkedList& b);

        /// Resets the list to empty
        void clear();

        /// Copy constructor
        CircularlyLinkedList(const CircularlyLinkedList& other);

        /// Copy assignment
        CircularlyLinkedList& operator=(const CircularlyLinkedList& other);

    /// Move constructor
    CircularlyLinkedList(CircularlyLinkedList&& other);

    /// Move assignment
    CircularlyLinkedList& operator=(CircularlyLinkedList&& other);

    /// default destructor
    ~CircularlyLinkedList();

    void print();

};

}  // namespace dsac::list


```



## Test the code by writing main function
