# Practice Lab Assignment 2.1.1: Counter Class (practice constructor, accessors, mutators)

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
