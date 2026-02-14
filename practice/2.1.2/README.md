# Practice Lab Assignment 2.1.2: Seat Class (practice operator overloading)

* Write a C++ program that models a seat using a class Seat and supports
* Construction with a row number and seat letter
* Copying a Seat
* Comparing seats for equality and inequality using overloaded operators

### Requirements

* Part A: Implement the Seat class

  * Create a class named Seat with:
    * Data members (private)
      * int row;
      * char position;
    * Constructor (public)
      * A constructor that takes (int r, char p) and initializes the data members using an initializer list.
    * Operator overloads (public)
      * operator== 
        * Takes const Seat& rhs
        * Returns true if both row and position match.
      * operator!=
        * Takes const Seat& rhs
        * Must be implemented by reusing operator== (do not duplicate logic).

* Part B: Write main()

* In main():

  * Construct: 
    * Seat s1(5, 'A');
    * Seat s2 = s1; (copy initialization)
    * Seat s3(6, 'B');
  * Enable boolean word output using: std::cout << std::boolalpha;
  * Print results of comparisons exactly in this format:
    * s1 == s2? ...
    * s1 != s3? ...
    * s2 == s3? ...

* Expected Output

  * ```sh
    s1 == s2? true
    s1 != s3? true
    s2 == s3? false
    ```
