# A4: Generic in-place Array Reversal

Reversing an array (or string) means rearranging its elements so that their order is flipped — the first element becomes the last, the second becomes the second-to-last, and so on — until the entire sequence is in the opposite order.

* Problem Statement
  * You are required to implement the function template:
    * reverse_array
      * This function should:
        * Take a pointer to an array
          * Think why is reverse_array not using const?
        * Take the number of elements in the array
        * Reverse the array in-place
        * Work with any data type
    * print_array
      * This function should:
        * Take a pointer to a constant array
        * Take the number of elements
        * Print the array 

## Requirements

* reverse_array
  * Must use a two-index approach (i and j) [non-recursive]
  * Swap elements from beginning and end
  * Continue until indices meet
  * Must work for:
    * int
    * double
    * char
    * std::string

```cpp
//reverse.hpp

define generic versions

```



```cpp
//main.cpp
int main() {
    // int[]
    int ai[]{1, 2, 3, 4};
    int ni = // compute size of array
    std::cout<<"ai: "; 
    print_array<int>(ai, ni);
    reverse_array<int>(ai, ni);
    std::cout<<"ai: "; 
    print_array<int>(ai, ni);

    // double[]
    double ad[] = {1.5, 2.5, 3.5, 4.5};
    int nd = // compute size of array
    std::cout<<"ad: "; 
    print_array<double>(ad, nd);
    reverse_array<double>(ad, nd); 
    std::cout<<"ad: "; 
    print_array<double>(ad, nd);

    // char[] (not a C-string)
    char letters[] = {'E','C','E','3','5', '1', '4'};
    int nc = // compute size of array
    std::cout<<"letters: "; 
    print_array<char>(letters, nc);
    reverse_array<char>(letters, nc);
    std::cout<<"letters: "; 
    print_array<char>(letters, nc);

    // C-string: reverse only the characters, not the '\0'
    char word[] = "hello";
    std::cout << "cstr: " << word << "\n";
    int nw = // compute size of string
    reverse_array<char>(word, nw);
    std::cout << "cstr: " << word << "\n";

    return 0;
}
/*
Expected Output
ai: : [1, 2, 3, 4]
ai: : [4, 3, 2, 1]
ad: : [1.5, 2.5, 3.5, 4.5]
ad: : [4.5, 3.5, 2.5, 1.5]
letters: : [E, C, E, 3, 5, 1, 4]
letters: : [4, 1, 5, 3, E, C, E]
cstr: hello
cstr: olleh
*/
```



```cpp
//test.cpp

// you may write array comparison function to compare true/actual and expected use in test cases to see if the array is in reverse or not.
```



## Files to submit

* reverse.hpp // declare generic versions
* main.cpp // use generic versions as below
* test.cpp // test cases
* CMakeLists.txt

## Rubrics

* Autograder: 4.5 Points
* Used two-index approach as described above: 4.5 Points
* test.cpp: 6 Points
  * test coverage of reverse_array with different data types
  * No need to write test case for print_array

