## Practice Lab Assignment 6.1: Build a Templated `SinglyLinkedList<T>`

## Objective

* In this lab, you will implement a simplified version of `std::forward_list` using a **templated singly linked list**.
* You are given the full class interface. Your task is to implement all member functions correctly and safely.
* This lab gives practice with:
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

/// singly linked list, akin to std::forward_list
template <typename T>
class SinglyLinkedList {
    private:
        //---------------- nested Node class ----------------
        class Node {
            public:
                T elem; // stored element
                Node* next; // pointer to next node

                Node(const T& element, Node* nxt = nullptr) 
                : elem{element}, next{nxt} {}
        };  //------------ end of nested Node class ------------

        // SingleLinkedList instance variables
        int sz{0};  // number of entries in the list
        Node* head{nullptr}; // raw pointer to first node of list
        Node* tail{nullptr}; // raw pointer to last node of list

    public:
        /// Constructs an empty list
        SinglyLinkedList() {}

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

        /// Removes the first element of the list; behavior undefined if list is empty
        void pop_front();

        /// Inserts element at the end of the list
        /// @param elem   the new element
        void push_back(const T& elem);

    public:
        //-------------------------------------------------------
        // A basic forward iterator
        //-------------------------------------------------------
        class iterator {
            // needed for SinglyLinkedLists's insert_after and erase_after
            friend class SinglyLinkedList;

            private:
                Node* node_ptr;  // pointer to a node

            public:
                iterator(Node* ptr = nullptr);

                T& operator*() const;
                T* operator->() const;

                iterator& operator++();
                iterator operator++(int);

                bool operator==(iterator rhs) const;
                bool operator!=(iterator rhs) const;
        };

        //-------------------------------------------------------
        // const version of iterator
        //-------------------------------------------------------
    public:
        class const_iterator {
            private:
                Node* node_ptr;  // pointer to a node

            public:
                const_iterator(Node* ptr = nullptr);

                const T& operator*() const;
                const T* operator->() const;

                const_iterator& operator++();
                const_iterator operator++(int);

                bool operator==(const_iterator rhs) const;
                bool operator!=(const_iterator rhs) const;
        };

        // ---------- iterator-based functions ----------
    public:
        /// Returns iterator for the front of the list
        iterator begin();

        /// Returns const_iterator for the front of the list
        const_iterator begin() const;

        /// Returns iterator for the end of the list
        iterator end();

        /// Returns const_iterator for the end of the list
        const_iterator end() const;

        /// Inserts new element just after the given position
        /// @param it     iterator defining position
        /// @param elem   element to insert
        /// @return       iterator of newly inserted element
        iterator insert_after(iterator it, const T& elem);

        /// Removes the element just after the given position
        /// @param it     iterator defining position
        /// @return       iterator of position just beyond the removed element
        iterator erase_after(iterator it);

        //------------------------------------------------
        // rule-of-five behaviors
        //------------------------------------------------

    private:
        // presumes valid empty list when called
        void clone(const SinglyLinkedList& other);

    public:

        /// non-member function to swap two lists
        friend void swap(SinglyLinkedList& a, SinglyLinkedList& b);

        /// resets the list to empty
        void clear();

        /// copy constructor
        SinglyLinkedList(const SinglyLinkedList& other);

        /// copy assignment
        SinglyLinkedList& operator=(const SinglyLinkedList& other);

        /// move constructor
        SinglyLinkedList(SinglyLinkedList&& other);

        /// move assignment
        SinglyLinkedList& operator=(SinglyLinkedList&& other);

        /// destructor
        ~SinglyLinkedList();
};

}  // namespace dsac::list

```



## Test the code by writing main function
