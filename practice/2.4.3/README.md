## Practice Lab Assignment 2.4.3: Building Number Progressions with Inheritance & Polymorphism

* A progression is a sequence of numbers where each new value is computed from the previous one.
  * Arithmetic progression (add a constant step each time)
  * Geometric progression (multiply by a constant base each time)

## Create the Abstract Base Class Progression

* Member Variables
  * protected: 
    * long current; //Stores the current value in the progression.
* Member functions
  * Progression(long start = 0)
    * Constructor sets current to start.
    * Use initializer list
  * virtual ~Progression()
    * Must be virtual so derived objects delete correctly through base pointers.
  * long next_value()
    * Returns the current value
    * but also advances the progression to the next value
  * void print_progression(int n)
    * Prints the next n values in the progression on one line, separated by spaces.
  * protected: virtual void advance() = 0;
    * A pure virtual function that moves the progression forward.
    * Derived classes must implement this.

## Create ArithmeticProgression that publicaly inherits from Progression

* Member Variables
  * protected: 
    * long stepsize;
* Member Functions
  * advance() 
    * should add stepsize to the current
  * Constructor
    * ArithmeticProgression(long stepsize = 1, long start = 0)
      * Pass start to the base class constructor
      * Store the step size in member variables
      * Use initializer list

## Create GeometricProgression that publicaly inherits from Progression

* Member Variables
  * protected: 
    * long base;
* Member Functions
  * advance() 
    * should multiply current by base
* Constructor
  * GeometricProgression(long b = 2, long start = 1)
    * pass start to the base class constructor
    * store b in the member variables base
    * use initializer list



## Write main() to use Polymorphism

* Write a main() that uses a Progression* pointer to test your derived classes
* Create prog as pointer of the base class Progression
* Create objects of below classes dynamically and store in the base pointer one at a time  and call print_progression on each object:
  * ArithmeticProgression()
    * Arithmetic progression with default increment (print 10 values)
  * ArithmeticProgression(5)
    * Arithmetic progression with increment 5 (print 10 values)
  * ArithmeticProgression(5, 2);
    * Arithmetic progression with increment 5 and start 2 (print 10 values)
  * GeometricProgression();
    * Geometric progression with default base (print 10 values)
  * GeometricProgression(3);
    * Geometric progression with base 3 (print 10 values
* Call delete prog; appropriately to avoid memory leaks

### Expected Output

```cpp
/*
Arithmetic progression with default increment: 0 1 2 3 4 5 6 7 8 9
Arithmetic progression with increment 5: 0 5 10 15 20 25 30 35 40 45
Arithmetic progression with increment 5 and start 2: 2 7 12 17 22 27 32 37 42 47
Geometric progression with default base: 1 2 4 8 16 32 64 128 256 512
Geometric progression with base 3: 1 3 9 27 81 243 729 2187 6561 19683
*/
```



