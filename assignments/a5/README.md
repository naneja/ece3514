# A5: Lower and Upper Bound for a Target in a Sorted Array

## Lower Bound:

* The lower bound gives us a position where one can insert the target value to maintain the sorted order
* The position of the first element that is not less than the target $t$.
* `lower_bound(arr, n, t)` returns first index with `arr[i] >= t` or returns $n$ if no such element

Example: Array: arr = [2, 5, 5, 5, 10] and n = 5 
| Function Call            | return value | Interpretation                                             |
| ------------------------ | ------------ | ---------------------------------------------------------- |
| lower\_bound(arr, n, 5)  | 1            | 5 can be inserted at index 1 to maintain the sorted order  |
| lower\_bound(arr, n, 3)  | 1            | 3 can be inserted at index 1 to maintain the sorted order  |
| lower\_bound(arr, n, 0)  | 0            | 0 can be inserted at index 0 to maintain the sorted order  |
| lower\_bound(arr, n, 15) | 5            | 15 can be inserted at index 5 to maintain the sorted order |



## Upper Bound

* The Upper Bound gives us a position to insert the target value to maintain the sorted order
* The position of the first element that is greater than (>) the target value
* `upper_bound(arr, n, t)` returns the first index $i$ with `arr[i] > x` (or $n$ if none)

Example: Array: arr = [2, 5, 5, 5, 10] and n=5

| Function Call            | return value | Interpretation                                               |
| ------------------------ | ------------ | ------------------------------------------------------------ |
| upper\_bound(arr, n, 5)  | 4            | 5 can be inserted at index 4 to maintain the sorted order <br>(after last 5, before 10) |
| upper\_bound(arr, n, 3)  | 1            | 3 can be inserted at index 1 to maintain the sorted order<br> (same as lower bound if the target value does not exist in the array) |
| upper\_bound(arr, n, 0)  | 0            | 0 can be inserted at index 0 to maintain the sorted order<br> (same as lower bound if the target value does not exist in the array) |
| upper\_bound(arr, n, 15) | 5            | 15 can be inserted at index 5 to maintain the sorted order<br> (same as lower bound if the target value does not exist in the array) |



## Frequency

* number of occurrences of the target value in the array
* `frequency(arr, n, t)` calculate as `upper_bound - lower_bound`

Example: Array: arr = [2, 5, 5, 5, 10] and n = 5

| Function Call        | call upper\_bound           | call lower\_bound           | return  |
| -------------------- | --------------------------- | --------------------------- | ------- |
| frequency(arr, n, 5) | upper\_bound(arr, n, 5) = 4 | lower\_bound(arr, n, 5) = 1 | 4-1 = 3 |
| frequency(arr, n, 2) | upper\_bound(arr, n, 2) = 1 | lower\_bound(arr, n, 2) = 0 | 1-0 = 1 |
| frequency(arr, n, 7) | upper\_bound(arr, n, 7) = 4 | lower\_bound(arr, n, 7) = 4 | 4-4 = 0 |



## Starter Code

```cpp
//include/array_bounds.hpp

// Standard library functions for testing
int std_lower_bound(const int* arr, int n, int target);
int std_upper_bound(const int* arr, int n, int target);
int std_frequency(const int *arr, int n, int target);

// Recursive versions
int lower_bound(const int* arr, int n, int target);
int upper_bound(const int* arr, int n, int target);
int frequency(const int *arr, int n, int target);

// Recursive helper versions
int lower_bound_recursive(const int* arr, int low, int high, int target);
int upper_bound_recursive(const int* arr, int low, int high, int target);

// Iterative versions
int lower_bound_iterative(const int* arr, int n, int target);
int upper_bound_iterative(const int* arr, int n, int target);
int frequency_iterative(const int *arr, int n, int target);
```



```cpp
//src/array_bounds.cpp

#include <algorithm> //std::lower_bound std::upper_bound

// Standard library function for testing
int std_lower_bound(const int* arr, int n, int target){
    auto it = std::lower_bound(arr, arr+n, target);
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_upper_bound(const int* arr, int n, int target){
    auto it = std::upper_bound(arr, arr+n, target);
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_frequency(const int *arr, int n, int target) {
    int lb = std_lower_bound(arr, n, target);
    int ub = std_upper_bound(arr, n, target);
    return ub - lb;
}
```



```cpp
//src/main.cpp

#include "array_bounds.hpp"
#include <cassert>
#include <iostream>

void test_bounds() {
    int a[] = {2, 5, 5, 5, 10};
    int n = sizeof(a) / sizeof(a[0]);
    
    // Test cases with various target values
    for (int t : {-1, 0, 2, 3, 5, 6, 10, 11}) {
        // Test iterative implementations
        assert(lower_bound_iterative(a, n, t) == std_lower_bound(a, n, t));
        assert(upper_bound_iterative(a, n, t) == std_upper_bound(a, n, t));
        
        // Test recursive implementations
        assert(lower_bound(a, n, t) == std_lower_bound(a, n, t));

        assert(upper_bound(a, n, t) == std_upper_bound(a, n, t));
        
        // Test frequency calculation
        assert(frequency(a, n, t) == std_frequency(a, n, t));
        assert(frequency_iterative(a, n, t) == std_frequency(a, n, t));
        
        std::cout << "Target " << t << ": ";
        std::cout << "LB=" << lower_bound(a, n, t) << ", ";
        std::cout << "UB=" << upper_bound(a, n, t) << ", ";
        std::cout << "Freq=" << frequency(a, n, t) << std::endl;
    }
    
    std::cout << "All tests passed!" << std::endl;
}


int main() {
    test_bounds();
    return 0;
}

//for array {2, 5, 5, 5, 10};
/*
Target -1: LB=0, UB=0, Freq=0
Target 0: LB=0, UB=0, Freq=0
Target 2: LB=0, UB=1, Freq=1
Target 3: LB=1, UB=1, Freq=0
Target 5: LB=1, UB=4, Freq=3
Target 6: LB=4, UB=4, Freq=0
Target 10: LB=4, UB=5, Freq=1
Target 11: LB=5, UB=5, Freq=0
All tests passed!
*/
```



```sh
Expected Output for array {2, 5, 5, 5, 10};

Target -1: LB=0, UB=0, Freq=0
Target 0: LB=0, UB=0, Freq=0
Target 2: LB=0, UB=1, Freq=1
Target 3: LB=1, UB=1, Freq=0
Target 5: LB=1, UB=4, Freq=3
Target 6: LB=4, UB=4, Freq=0
Target 10: LB=4, UB=5, Freq=1
Target 11: LB=5, UB=5, Freq=0
All tests passed!
```



## Submissions:

* CMake Project (via private GitHub Repo)

  * include/array_bounds.hpp
  * src/array_bounds.cpp
  * src/main.cpp
  * CMakeLists.txt
  * tests/test.cpp (as per catch2)
  * tests/catch2/catch.hpp

* > Use .gitignore to not push $build$ folder



## Rubrics

* Points will be deducted if library functions are used for lower bound, upper bound, frequency functions, other than for testing

| Criteria                                                     | Points |
| ------------------------------------------------------------ | ------ |
| Autograder                                                   | 7      |
| Verification: `lower_bound`, `upper_bound`, and `frequency` use recursive helper functions | 2      |
| Verification: `lower_bound_iterative`, `upper_bound_iterative`, `frequency_iterative` have iterative implementation | 2      |
| test.cpp (test coverage)                                     | 4      |
| Negative Points for using library functions inside required implementation: <br>`lower_bound`, `upper_bound`, `frequency`<br/>`lower_bound_recursive`, `upper_bound_recursive`<br/>`lower_bound_iterative`, `upper_bound_iterative`, `frequency_iterative` | -4     |
| Build folder uploaded                                        | -1     |
| Negative points for public repo                              | -15    |

