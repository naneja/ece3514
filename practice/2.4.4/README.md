## Practice Lab Assignment 2.4.4: Multiple Inheritance and Ambiguity

* Objective
  * In this lab, you will practice:
    * Implementing multiple inheritance in C++
    * Understanding function ambiguity
    * Resolving ambiguity using scope resolution operator
    * Exploring how inherited member functions behave in derived classes
* Background
  * A class can inherit from more than one base class. This is called multiple inheritance. While powerful, it can lead to ambiguity when two base classes contain member functions with the same name.
  * In this lab, you will recreate and extend a small program that demonstrates this concept.

## Create Base Classes

* Create a Phone class
  * Add a public method:
    * std::string MakeCall(); 
      * that returns "Calling..."
  * Add another public method:
    * std::string Use();
      * that also returns "Calling..."
* Create a Camera class
  * Add a public method:
    * std::string TakePhoto();
      * that returns "Photo taken"
  * Add another public method:
    * std::string Use();
      * that returns "Photo taken"

## Multiple Inheritance

* Create a Smartphone class that inherit publicly from both: 
  * Phone and 
  * Camera

## Testing in main()

* Create objects inside main():
  * Create a Phone object
  * Create a Camera object
  * Create a Smartphone object
* Call Base Class Methods and print returned message
  * From Phone object:
    * MakeCall()
    * Use()
  * From Camera object:
    * TakePhoto()
    * Use()
  * from Smartphone Object
    * MakeCall() 
    * TakePhoto()
    * Try below Use() as below on Smartphone Object that shows error. Resolve the error.

```cpp
Smartphone smartphone;
std::cout << smartphone.Use() << "\n"; //ambiguous
```
