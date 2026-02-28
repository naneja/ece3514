## Practice Lab Assignment 5.5.1: Build a Templated `Vector<T>` (Dynamic Array) from Scratch

## Objective

* In this lab, you will implement a simplified version of std::vector called $Vector<T>$. 
* The class will manage a dynamically allocated array, track its size (number of stored elements) and capacity (allocated slots), and support common operations such as indexing, bounds-checked access, insertion, and deletion.
* You are given the class interface (below). 
* Your job is to implement the member functions correctly and safely.

```cpp
#pragma once
#include <algorithm>     // provides max
#include <stdexcept>     // provides out_of_range exception

namespace dsac::array {
///Simplified version of std::vector
/// @tparam T the element type    
template <typename T>
class Vector {
    private:
        /// capacity of the array
        int cap{0};

        /// number of actual entries
        int sz{0};

        /// pointer to array of elements
        T* data{nullptr};

    public:
        /// Constructs an empty vector
        Vector();

        /// Returns the current capacity of the underlying array
        /// @return the size of the underlying array
        int capacity() const;

        /// Returns the number of elements stored
        /// @return the number of elements stored
        int size() const;

        /// Tests whether the vector is empty.
        /// @return true if the vector is empty, false otherwise
        bool empty() const;

        /// Returns const reference to the element at index i; behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        const T& operator[](int i) const;

        /// Returns reference to the element at index i; behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        T& operator[](int i);

        /// Returns const reference to the element at index i; raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        const T& at(int i) const;

        /// Returns reference to the element at index i; raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        T& at(int i);

        /// Returns a const reference to the first element; behavior is undefined if vector is empty
        /// @return reference to first element
        const T& front() const;

        /// Returns a live reference to the first element; behavior is undefined if vector is empty
        /// @return reference to first element
        T& front();

        /// Returns a const reference to the last element; behavior is undefined if vector is empty
        /// @return reference to last element
        const T& back() const;

        /// Returns a live reference to the last element; behavior is undefined if vector is empty
        /// @return reference to last element
        T& back();

        /// Inserts an element at end of the vector
        /// @param elem   the new element
        void push_back(const T& elem);

        /// Removes an element from the end of the vector
        void pop_back();

        /// Inserts an element at index i; behavior is undefined if i is out of bounds
        /// @param i      index at which new element should be placed
        /// @param elem   the new element
        void insert(int i, const T& elem);

        /// Removes element at index i; behavior is undefined if i is out of bounds
        /// @param i index of element to be removed
        void erase(int i);

        /// Requests that the vector capacity be at least as large as the indicated capacity
        /// The function has no effect if the current capacity is already larger than the parameter.
        /// @param cap  the minimum capacity after the operation
        void reserve(int minimum);

        //------------------------------------------------
        // rule-of-five behaviors
        //------------------------------------------------

        /// Copy constructor
        Vector(const Vector& other);

        /// Copy assignment
        Vector& operator=(const Vector& other);

        /// Move constructor
        Vector(Vector&& other);

        /// Move assignment
        Vector& operator=(Vector&& other);

        /// Destructor
        ~Vector();
    
    private:
        void clone(const Vector& other);

        void transfer(Vector& other);

    public:
        //-------------------------------------------------------
        // Support for iterator as a bidirectional access iterator
        //-------------------------------------------------------
        /// A bidirectional iterator
        class iterator {
            // needed by Vector's insert(it,elem) and erase(it)
            friend class Vector;
            
            private:
                Vector* vec;
                int ind;        // index within the vector
            
            public:
                iterator(Vector* v = nullptr, int i = -1);
                T& operator*() const;
                T* operator->() const;
                iterator& operator++();
                iterator operator++(int);
                iterator& operator--();
                iterator operator--(int);
                bool operator==(iterator rhs);
                bool operator!=(iterator rhs);
        };

        //-------------------------------------------------------
        // Support for const_iterator as a bidirectional access iterator
        //-------------------------------------------------------
        /// A bidirectional const_iterator
        class const_iterator {
            private:
                const Vector* vec;
                int ind;                   // index within the vector
            
            public:
                const_iterator(const Vector* v = nullptr, int i = -1);
                const T& operator*() const;
                const T* operator->() const;
                const_iterator& operator++();
                const_iterator operator++(int);
                const_iterator& operator--();
                const_iterator operator--(int);
                bool operator==(const_iterator rhs) const;
                bool operator!=(const_iterator rhs) const;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

        /// Inserts an element immediately before the given iterator position
        /// @param it     iterator defining the insertion position
        /// @param elem   the new element
        /// @return iterator of newly inserted element
        iterator insert(iterator it, const T& elem);

        /// Removes the element at the given iterator position
        /// @param it     iterator defining the position of element to be removed
        /// @return iterator just beyond the removed element
        iterator erase(iterator it);

        // additional assignment functions
        // Reallocate storage to exactly new_cap (>= sz), moving elements.
        void reallocate(int new_cap)

        void shrink();
        
        // explicitly reduce the cap to sz and keep at least 1 slot
        void shrink_to_fit();
    
}; // Vector class

}  // namespace dsac::array

```



## Test the code by writing main function
