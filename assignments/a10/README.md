# A10: Stack Queue

Starter Code: [download](https://raw.githubusercontent.com/naneja/ece3514/main/assignments/a10/a10_stack_queue.zip)

In this assignment, you will solve three problems using a stack and a queue. 



## Problem 1: Remove Adjacent Duplicates Using Stack

```cpp
std::string removeDuplicates(std::string s);
```

* Goal: Remove all adjacent duplicate characters in a string until none remain
* Implementation must use a dsac::stackqueue::stack or dsac::stackqueue::queue as an intermediate data structure. Your implementation of stack and queue must use the container class as dsac::array::vector or dsac::list::DoublyLinkedList. A default Container Class must also be defined in the stack and queue
* Example:


| Input string | Output string |
| ------------ | ------------- |
| "abbaca"     | "ca"          |
| "abccba"     | ""            |
| ""           | ""            |
| "abcde"      | "abcde"       |
| "aaaaa"      | "a"           |
| "aaaa"       | ""            |
| "1122334455" | ""            |
| "abbaa"      | "a"           |



## Problem 2: Clean String that has backspace character <

```cpp
std::string clean_backspace_string(std::string s);
```

| Input string | Output string |
| ------------ | ------------- |
| "ab<c"       | "ac"          |
| "ab<<"       | ""            |
| "a<<b<<"     | ""            |
| "<"          | ""            |
| "<<a"        | "a"           |
| "a<bc<d"     | "bd"          |

Implementation must use a dsac::stackqueue::stack or dsac::stackqueue::queue as an intermediate data structure. Your implementation of stack and queue must use the container class as dsac::array::vector or dsac::list::DoublyLinkedList. A default Container Class must also be defined in the stack and queue



## Problem 3: Search element in a Stack (using a queue) without changing the order of the elements in the stack

Suppose you have a stack `st` containing `n` elements and a queue `q` that is initially empty. 

Describe how you can use `q` to scan `st` to see if it contains a certain element `x`, with the additional constraint that your algorithm must return the elements back to `st` in their original order.  

You cannot use an array or linked list—only `st` and `q` and a constant number of reference variables.

* Scanning a Stack Using a Queue
* The Queue must be initially empty

Goal: Check if element x is in stack S using only: Stack S, empty queue Q, and constant variables

* Preserve the original order of `st` after scan

```cpp
template <
    typename T, typename StackContainer=dsac::array::Vector<T>,
    typename QueueContainer=dsac::array::Vector<T>
    >
bool stack_contains(
    dsac::stackqueue::stack<T, StackContainer>& st, 
    dsac::stackqueue::queue<T, QueueContainer>& q, 
    const T& x)
```

| values before stack_contains is called | return value                                         | values after stack_contains_restore is called |
| -------------------------------------- | ---------------------------------------------------- | --------------------------------------------- |
| st = {1, 2, 3, 4, 5}; q={}; x=5        | True                                                 | st = {1, 2, 3, 4, 5}; q={}; x=5               |
| st = {1, 2, 3, 4, 5}; q={}; x=1        | True                                                 | st = {1, 2, 3, 4, 5}; q={}; x=1               |
| st = {1, 2, 3, 4, 5}; q={}; x=3        | True                                                 | st = {1, 2, 3, 4, 5}; q={}; x=5               |
| st = {1, 2, 3, 4, 5}; q={}; x=10       | False                                                | st = {1, 2, 3, 4, 5}; q={}; x=10              |
| st = {1, 2, 3, 4, 5}; q={1}; x=3       | std::invalid_argument("Q must be initially empty."); | st = {1, 2, 3, 4, 5}; q={1}; x=3              |
| st = {}; q={}; x=5                     | False                                                | st = {}; q={}; x=5                            |
| st = {5}; q={}; x=5                    | True                                                 | st = {5}; q={}; x=5                           |
| st = {5}; q={}; x=10                   | False                                                | st = {5}; q={}; x=5                           |



## Submissions:

* stack.hpp
  * simplified implementation of std::stack
  * should be placed in include/stackqueue
  * uses namespace dsac::stackqueue::

* queue.hpp
  * simplified implementation of std::queue
  * should be placed in include/stackqueue
  * uses namespace dsac::stackqueue::
* stack_queue_utils.hpp
  * implementation of above functions for Problem1, Problem 2, Problem 3

* test_stack_queue_utils.cpp
  * at least one catch2 test case for each of the above functions for Problem 1, Problem 2, Problem 3, stack.hpp, and queue.hpp

* array_queue.hpp
  * simplified implementation of queue using vector.hpp

* doubly_linked.hpp
  * simplified implementation of std:list
  * should be placed in include/list/doubly_linked.hpp
  * container class for queue.hpp

* vector.hpp
  * simplified implementation of std:vector
  * should be placed in include/array/vector.hpp
  * container class for stack.hpp and queue.hpp

* Negative Points for not following the instructions



## Rubrics:

| Test Case                                                    |      |
| ------------------------------------------------------------ | ---- |
| Autograder Instructor Test Cases                             | 6    |
| Autograder Student Test Cases                                | 2    |
| Manual Grading of stack_queue_utils.hpp (if instructions followed as mentioned above) | 5    |
| Manual Grading for test cases in the test_stack_queue_utils.cpp (at least one catch2 test case for each of the above functions for Problem 1, Problem 2, Problem 3, stack.hpp, and queue.hpp) | 2    |
| Negative Points for build folder submitted                   | -2   |
