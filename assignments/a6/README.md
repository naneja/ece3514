# A6: Squares of a Sorted Array O(n)

Given a sorted integer array nums of length n (sorted in non-decreasing order), compute the squares of each element and return them sorted in non-decreasing order. You must overwrite the input array with the sorted squares.

* Input: array a1 sorted in non-decreasing order
* Output: array of the squares of each number sorted in non-decreasing order.

Example:

* Input: {-5, -3, -1, 3, 5}
* Output: {1, 9, 9, 25, 25}

## Time Complexity

* Your implementation for `sorted_squares` must run in $O(n)$  time

```cpp
void sorted_squares(int* nums, int n);
```

## Space Complexity

* You must use either:
  * $O(n)$ extra space allocated on the heap only or
  * $O(1)$ extra space (no auxiliary array) or
* Not Allowed:
  * Stack arrays of size n (e.g., int temp[n];)
  * std::array<int, n>
* Allowed:
  * new[] / delete[]
  * std::unique_ptr<int[]>
  * O(1) extra scalar variables
  * copy array elements from array a1 to array a1_copy
    * std::copy(a1, a1+n, a1_copy);
  * Computing absolute values of elements
    * std::abs from #include <cstdlib>
* Sorting Restrictions
  * You must not use:
    * std::sort
    * Any comparison-based sorting algorithm
    * Any third-party sorting utility



## Given square_then_sort

* The function below is intentionally provided as a reference implementation, not as a correct solution to the assignment requirements. What It Does
  * Squares each element of the array - $O(n)$
  * Sorts the array using std::sort - $O(n \log n)$
  * Overall Complexity: $O(n \log n)$
  * The assignment is to write $O(n)$ algorithm

```cpp
#include <algorithm> 
void square_then_sort(int* nums, int n) {
    for (int i{0}; i<n; i++) 
        nums[i] = nums[i] * nums[i];
    std::sort(nums, nums + n);
}
```



## Comparison of arrays

You will define the `equal_arr` function to compare elements of two arrays.

```cpp
bool equal_arr(const int* a, const int* b, int n);
```



## Starter Code

```cpp
//squares.hpp

//smallest on front
// must be O(n) // TODO
void sorted_squares(int *nums, int n);

//Complexity O(nlogn) // Given to compare
void square_then_sort(int* nums, int n);

// to compare both arrays //TODO
bool equal_arr(const int* a, const int* b, int n);
```



```cpp
//squares.cpp
#include "squares.hpp"

#include <algorithm> 

// must be of O(n)
void sorted_squares(int *nums, int n){
// ToDo
}

//compares two array if both have same elements
bool equal_arr(const int* a, const int* b, int n) {
// ToDo
}

//Complexity O(n log n)
void square_then_sort(int* nums, int n) {
    for (int i{0}; i<n; i++) 
        nums[i] = nums[i] * nums[i];
    std::sort(nums, nums + n);
}
```



```cpp
// main.cpp
#include "squares.hpp"

#include <cassert>
#include <iostream>

int main() {
    int a1[]{-5, -3, -1, 3, 5};
    int n = std::size(a1);

    auto a1_copy = std::make_unique<int[]>(n);
    std::copy(a1, a1 + n, a1_copy.get());

    sorted_squares(a1, n);
    square_then_sort(a1_copy.get(), n);
    assert(equal_arr(a1, a1_copy.get(), n));

    for(auto const &elt : a1)
        std::cout << elt << " ";
    std::cout << "\n";

    
}
//1 9 9 25 25
```

# Submission:

* Individual Files 
  * squares.hpp
  * squares.cpp
* or CMake Project (via private GitHub Repo)

> Use .gitignore to not push $build$ folder or executable files



## Rubrics

* Points will be deducted if library functions are used for lower bound, upper bound, frequency functions, other than for testing

| Criteria                                                     | Points |
| ------------------------------------------------------------ | ------ |
| Autograder                                                   | 3.5    |
| Verification: Time Complexity O(n)                           | 3      |
| Verification: Space Complexity is or lower than O(n) with heap memory used | 3      |
| No Major Issues in the code                                  | 0.5    |
| Build folder uploaded                                        | -1     |
| Negative points for public repo                              | -10    |
