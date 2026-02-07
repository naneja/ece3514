## A3: Prime Number Algorithm Efficiency using Smart Pointers

In this assignment, you will modify the A2 to write two new functions that use smart pointers while not modifying other functions that use raw pointers.


### File provided

- prime.hpp

```cpp
// prime.hpp
#pragma once

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, long long* modOps=nullptr);

//Checks for divisibility up to square root of n
bool isPrimeSqrt(int n, long long* modOps=nullptr);

//counts how many modulo operations a given prime function performs
//over a range of numbers
long long countModOpsHalf(int lo, int hi);
long long countModOpsSqrt(int lo, int hi);


//These functions must use smart pointers (unique is preferred) 
//and call isPrimeHalf or isPrimeSqrt which accepts raw pointers
long long countModOpsHalf_sp(int lo, int hi);
long long countModOpsSqrt_sp(int lo, int hi); 
```



- main.cpp

```cpp
#include <iostream>
#include "prime.hpp"

int main() {
    const int LO = 2, HI = 10'000;

    long long halfOps = countModOpsHalf_sp(LO, HI);
    long long sqrtOps = countModOpsSqrt_sp(LO, HI);

    std::cout << halfOps << "\n"; // 1461014
    std::cout << sqrtOps << "\n"; // 65956
}
```

 

### Rubrics

| Criteria                                                     | Points |
| ------------------------------------------------------------ | ------ |
| Autograder: Two test cases                                   | 2      |
| Manually Grading<br>Did countModOpsHalf_sp and countModOpsSqrt_sp use smart pointers and call isPrimeHalf and isPrimeSqrt, which accept raw pointers | 3      |
| Submission is via Private GitHub Repo (Negative Five Points if Public Repo used) | -5     |
| Negative Points for uploading build folder or any folder with executables<br> Use .gitignore with build/ to avoid pushing to the GitHub<br>If you already uploaded, then use: git rm -r --cached build | -2     |



## Submission via Gradescope

* **Submit your CMake Project (without build folder)**
  * Negative Points for uploading the build folder or any folder with executables
  * Use Private Git Repo (negative points for using public repo)
    *  Use .gitignore with build/ to avoid pushing to the GitHub
    * If you have already uploaded, then use: git rm -r --cached build  
* Submission Files:
  * include/prime.hpp
  * src/prime.cpp
  * src/main.cpp
  * CMakeLists.txt
* Note: test.cpp will not be graded.
