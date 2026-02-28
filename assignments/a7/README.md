# A7: Build a Simplified vector class (Part 1)

* In this lab you will complete and test a simplified dynamic array class, `dsac::array::Vector<T>`, that behaves similarly to std::vector. 
* You will focus on capacity management, shifting elements for insert/erase, and safe access.
* This is Part 1 to implement functions declared in .hpp. 
* You will also write test cases.
* std::vector must not be used to implement any of these functions (Negative Points if std::vector is used, even if all test cases are passed at Gradescope).

## Learning Objectives

* By the end of this lab, you should be able to:
  * Explain the difference between size and capacity
  * Implement dynamic memory growth and shrinking policies
  * Correctly shift elements for insert() and erase()
  * Write safe access routines that throw exceptions when needed
  * Create tests that validate correctness and edge cases

```cpp
//vector.hpp

#pragma once

#include <algorithm>  //for std::max

namespace dsac::array {

template <typename T>
class Vector {

private:
    int cap{0};
    int sz{0};
    T* data{nullptr};

public:
    //empty
    Vector();
    
    //capacity
    int capacity() const;

    //elements stored
    int size() const;
    
    // True is empty
    bool empty() const;
    
    //element at index when vector is const
    const T& operator[](int i) const;
    
    //element at index when vector is non-const
    T& operator[](int i);
    
    // at function for const
    const T& at(int i) const;
    
    // at function for non const
    T& at(int i);
    
    // first element
    const T& front() const;

    // first element
    T& front();
    
    // last element
    const T& back() const;

    // last element
    T& back();
    
    // insert at end
    void push_back(const T& elem);

    // remove from end
    // also call shrink
    void pop_back();

    // insert at index
    void insert(int i, const T& elem);

    // removes at index
    // also call shrink
    void erase(int i);

    //capacity >= minimum
    void reserve(int minimum);

    // called by other functions to reduce cap by half 
    // when sz <= cap/4 
    void shrink();
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit();

}; //end class Vector
}//end namespace dsa
```



## Submissions

* include/array/vector.hpp

* tests/test.cpp

* You can create a const vector as below for testing

  ```cpp
  dsa::Vector<int> v;
  for (int i{0}; i < 5; ++i) 
      v.push_back(i);
  const dsa::Vector<int>& cv = v;
  ```



## Submission

* Minimum two files:
  * include/array/vector.hpp
  * tests/test.hpp
* No build or exe files must be submitted
* Must be via Private GitHub Repo



## Rubrics

| Criteria                                                     | Points |
| ------------------------------------------------------------ | ------ |
| Autograder with student uploaded test.cpp                    | 2      |
| Autograder with instructor uploaded test.cpp                 | 4      |
| Manual Grading: Vector.hpp (check no usage of std::vector and basic code quality check) | 2      |
| Manual Grading: Test Coverage and Test Cases Quality of student test.cpp | 2      |
| Negative Points for build or executable files submitted (use .gitignore to avoid pushing build to GitHub) | -2     |
| Negative Points for using Public GitHub repo                 | -10    |

