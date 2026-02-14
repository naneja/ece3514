## Practice Lab Assignment 5.2.1: Implementing Generic Insertion Sort

* In this lab, you will implement a generic insertion sort algorithm using C++ templates. You will practice:
  * Writing function templates
  * Working with arrays and pointers
  * Understanding sorting algorithms
  * Using move semantics (std::move)
  * Testing your implementation with multiple data types
* Background
  * Insertion sort is a simple comparison-based sorting algorithm that:
    * Divides the array into sorted and unsorted portions.
    * Takes one element from the unsorted portion.
    * Inserts it into its correct position in the sorted portion.
    * Repeats until the entire array is sorted.

## Requirements:

* The function must sort the array in ascending order.
* Use a loop that starts from index 1
* Store the current value before shifting elements
* Shift larger elements to the right
* Insert the stored value in its correct position
* Use std::move() when shifting elements

## Test with main()

* Sort 
  * Given: int arr[] = {5, 2, 7, 1, 5, 6, 3, 4, 5, -1, 0};
    * Expected Output: -1 0 1 2 3 4 5 5 5 6 7
  * Given: std::string arr[] = {"banana", "apple", "cherry", "date"};
    * Expected Output: apple banana cherry date

## Time Complexity:

* Best Case: $O(n)$
* Average Case: $O(n^2)$
* Worst Case: $O(n^2)$
