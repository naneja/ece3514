## Practice Lab Assignment 5.3.2: Dynamic 2D Arrays with Pointers

* By completing this lab, you will be able to:
  * Dynamically allocate a 2D array using new and $int**$
  * Access elements using $mat[r][c]$
  * Use nested loops to initialize and print a matrix
  * Properly free heap memory using $delete[]$
  * Avoid common dynamic memory mistakes (leaks, mismatched deletes)

## Background

* In C++, a 2D dynamic array is often created as:
  * Allocate an array of pointers (rows)
  * For each row, allocate an array of integers (columns)
* Conceptually:
  * $mat$ points to an array of row pointers
  * each $mat[r]$ points to a row of integers
  * each $mat[r][c]$ is a single element



## Problem Statement

* Write a C++ program that:
  * Stores the number of rows and columns in variables
  * Dynamically allocates a 2D integer matrix ($int**$)
  * Fills the matrix with values based on the rule: $mat[r][c]=r+c$
  * Prints the matrix in grid form
  * Correctly deallocates all dynamic memory

## Challenge

* Row and Column Sums
  * Compute and print the sum of each row and column.
