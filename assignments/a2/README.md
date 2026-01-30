## A2: Prime Number Algorithm Efficiency

In this assignment, you will implement and compare two algorithms for checking whether a number is prime. The goal is not just correctness, but also efficiency, measured by the number of modulo operations (%) performed.

You will compare:

* checking divisibility up to n/2, and
* checking divisibility up to $\sqrt{n}$.

### Files to Create

- Private GitHub Repo with CMake Project (Negative Points for Public repo)
  - include/
    - prime.hpp - Header file with function declarations

  - src/
    - prime.cpp - Implementation of prime-checking algorithms
    - main.cpp - Main program to count modulo operations

  - tests/
    - test.cpp - Unit tests for validation 

  - CMakeLists.txt - Configuration File




### File provided

- prime.hpp

```cpp
// prime.hpp

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, long long* modOps=nullptr);

//Checks for divisibility up to the square root of n
bool isPrimeSqrt(int n, long long* modOps=nullptr);

//counts how many modulo operations over a range of numbers
long long countModOpsHalf(int lo, int hi);
long long countModOpsSqrt(int lo, int hi);
```



## isPrimeHalf and isPrimeSqrt

* These functions determine whether a single integer $n$ is prime.
* n: the number being tested
* modOps: a pointer to a counter that tracks how many % (modulo) operations are actually performed
* If modOps` is `nullptr, no counting is required
* If non-null, increment modOps only when a % is executed

1. **Base Cases**

   - If `n <= 1`:
     - `n` is **not prime**.
     - modOps = 0 (no modulus operation needed).
   - If `n == 2`:
     - `n` is **prime**.
     - `modops = 0` (equality check only, no modulus operation).

2. **Check for Even Numbers (n > 2)**

   - Perform n % 2
   - If result is `0`, then `n` is **not prime**.
   - Regardless of primality, we have:
     - `modops = 1`.

3. **Two algorithms (isPrimeHalf and isPrimeSqrt) to check Odd Divisors (when n > 2 and is not even)**

   - **Algorithm isPrimeHalf:** 3, 5, 7, ... n/2
   - **Algorithm isPrimeSqrt:** 3, 5, 7, ...sqrt(n)
     - Implement d * d <= n instead of computing sqrt from maths library

   - For each divisor, perform one modulus operation:
     - Increment modOps by 1 per divisor test.
   - If any modulus result is `0`, then `n` is **not prime**.
   - If no divisor divides `n`, then `n` is **prime**.

## `countModOpsHalf` and `countModOpsSqrt`

These functions measure the *total* number of modulo operations used by each algorithm over a **range of numbers**.

### Parameters

- `lo`: start of the range (inclusive)
- `hi`: end of the range (inclusive)

### Required behavior

- For each integer `n` in `[lo, hi]`:
  - Call the corresponding prime-checking function
  - Collect the number of modulo operations it performs
- Return the **sum** of all modulo operations over the range

### Important notes

- These functions **must not perform any `%` operations themselves**
- Their only responsibility is to:
  - call the appropriate prime-checking function
  - accumulate and return the modulo count



## Common mistakes to avoid

- Performing `%` when `n <= 1` or `n == 2`
- Continuing to test divisors after a divisor has been found
- Counting loop iterations instead of actual `%` operations
- Performing any `%` inside `countModOpsHalf` or `countModOpsSqrt`

 

- main.cpp

```cpp
#include <iostream>
#include "prime.hpp"

int main() {
    const int LO = 2, HI = 10'000;

    long long halfOps = countModOpsHalf(LO, HI);
    long long sqrtOps = countModOpsSqrt(LO, HI);

    std::cout << halfOps << "\n"; // 1461014
    std::cout << sqrtOps << "\n"; // 65956
}
```

 

### Rubrics

| Criteria                                                     | Points |
| ------------------------------------------------------------ | ------ |
| Autograder: Seven test cases                                 | 7      |
| Correct CMakeLists.txt                                       | 2      |
| Include Guards                                               | 1      |
| Correct and Complete Test Cases                              | 10     |
| Submission is via Private GitHub Repo (Negative Five Points if Public Repo used) | -5     |
| Negative Points for uploading build folder or any folder with executables | -2     |



### Correct and Complete Test Cases [10 Points]

1. [isPrimeHalf] Correct base-case handling
2. [isPrimeHalf] Correct even-number handling for n > 2
3. [isPrimeHalf] Correct odd-divisor loop up to n/2
4. [isPrimeHalf] Correct behavior when modOps == nullptr
5. [isPrimeSqrt] Correct base-case handling
6. [isPrimeSqrt] Correct even-number handling for n > 2
7. [isPrimeSqrt] Correct odd-divisor loop up to $\sqrt{n}$ using $d*d \le n $
8. [isPrimeHalf] Correct behavior when modOps == nullptr
9. countModOpsHalf(lo, hi)
10. countModOpsSqrt(lo, hi)

## Submission via Gradescope

* **Submit your CMake Project (without build folder)**
  * Negative Points for uploading build folder or any folder with executables
  * Use Private Git Repo (negative points for using public repo)
* Submission Files:
  * include/prime.hpp
  * src/prime.cpp
  * src/main.cpp
  * tests/catch2/catch.hpp	
  * tests/test.cpp
  * CMakeLists.txt
