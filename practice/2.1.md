# Practice Lab Assignment 2.1

## Lab Assignment 1: Counter Class (practice constructor, accessors, mutators)

* Problem statement
  * You will implement a Counter class that stores an integer value and supports:
    * Creating a counter starting at 0 (default construction)
    * Creating a counter starting at a given initial value
    * Reading the current value
    * Increasing the counter by:
      * 1 (no-argument increment)
      * a specified delta (one-argument increment)
    * Resetting the counter back to 0
    * You will then write a main() program that demonstrates all features.
* Required specifications
  * Part A: Class Counter
    * Private data member
      * int value
    * Public constructors
      * Default constructor
        * No Parameter
        * initialize value to 0 by default
      * Parameterized constructor
        * Takes one integer initial
        * Sets the value to initial
        * Use a member initializer list for the parameterized constructor
    * Public member functions
      * int get_value() const
        * Returns the current value
        * Must be const
      * void increment()
        * Increases the value by 1
      * void increment(int delta)
        * Increases the value by delta
        * This is an overload of increment()
      * void reset()
        * Sets the value back to 0
    * Part B: main
      * Your main() must produce output that demonstrates:
      * Default construction
      * Calling increment() and increment(delta)
      * Resetting to zero
      * Parameterized construction with an initial value
      * print value

## Lab Assignment 2: Seat Class (practice operator overloading)

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



## Lab Assignment 3: BankAccount (practice Friend Class)

* You are tasked with building a simplified banking security module. Follow these requirements:
* Define a BankAccount class:
  * Private members: 
    * accountHolder (string)
    * balance (double)
  * Constructor: Initialize both members via an initialization list.
  * Friendship: Grant the Auditor class access to its private data.
* Define an Auditor class:
  * Create a public method auditAccount that takes a reference to a BankAccount object.
    * print the account holder’s name and the balance followed by the tag "-Audited".
* In main()
  * instantiate a BankAccount for "PersonA" with a balance of $10,500.
  * Instantiate an Auditor and use it to process PersonA's account



## Lab Assignment 4: File System (practice nested Class)

* Define a FileSystem class:
  * Nested Class (File): Inside the public section of FileSystem, define a class named File.
    * Private members: 
      * name (string)
      * size (int).
    * Constructor: 
      * Initialize name and size using an initialization list.
    * Method: 
      * display() should print the file name and size in "KB".
  * Private member: 
    * A std::vector<File> to store multiple file objects.
  * Public Methods:
    * addFile(const File& file): Adds a File object to the vector.
    * listFiles(): Iterates through the vector and calls display() for each file.
* Implementation in main():
  * Create an instance of FileSystem.
  * Use a type alias (using FileType = ...) to create a shorthand for the nested File class.
  * Create three files:
    * "music.mp3" (5120 KB)
    * "notes.txt" (128 KB)
    * "presentation.pptx" (4096 KB)
  * Add these files to your FileSystem instance and then list them to the console.



