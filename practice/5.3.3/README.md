## Practice Lab Assignment 5.3.3: Dynamic 2D Arrays using Smart Pointer

## Objective

* In this lab, you will practice managing dynamic 2D arrays safely using RAII and smart pointers. By the end, you will be able to:
  * Allocate a dynamic 2D matrix using nested $std::unique_ptr$
  * Access elements with $mat[r][c]$
  * Initialize and print a matrix using nested loops
  * Explain why smart pointers prevent memory leaks

## Background

* When you allocate memory using new, you must remember to delete it. However, Smart pointers automatically free memory when they go out of scope.
* For a dynamic 2D array:
  * You can store an array of row pointers
  * Each row pointer owns a dynamically allocated array of int

## Problem Statement

* Write a C++ program that:
  * has $\#include <memory>$
  * Stores the matrix size in rows and cols
  * Allocates a dynamic 2D matrix using std::unique_ptr
  * Fills it using the rule:
    * $mat[r][c]=r+c$
  * Prints the matrix row-by-row
  * Uses no new and no delete directly in your code

## Challenge

* Print in Column-Major Order
  * Instead of printing row-by-row, print column-by-column.
* Find the Maximum
  * Find the largest element and print its value and coordinates
