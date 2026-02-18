# Practice Lab Assignment 2.2.1: Templates and the Standard Template Library (STL)

Prepared by: Mr Gokul

* Part 1 - Templates
  * Objective: Implement a function template that handles multiple data type comparisons.
    * You need a utility function that finds the minimum of two values. Instead of writing separate functions for int, double, and char, you will use a template.
  * Requirements:
    * Template Definition: Write a function template named min that takes two parameters of potentially different types, T1 and T2.
  * Verfication: Look at slide 4 in the `2.2 Templates and STL.pdf`

* Part 2 - Class Templates in C++
  * Objective: Create a class template to store a pair of related data of any type.
    *  Many applications need to group two pieces of data together (like a student's ID (int) and their name (string)). You will create a generic pair class to handle this.
  *  Requirements:
    *  Define a class pair with two template parameters, A and B.
    *  Data Members: Create two public members: first (of type A) and second (of type B).
    *  Constructor: Implement a constructor that initializes both members using initialization lists.
  *  Verfication: Look at slide 6 in the `2.2 Templates and STL.pdf`
  
*  Part 3 - STL
  *  Map each functional requirement to the correct C++ STL class introduced in the lecture. (Slide 8 in the `2.2 Templates and STL.pdf`)
  
      * I need to access elements by index (0, 1, 2...)
      * I need a data structure that is non-contiguous and helps me reach only the next node
      * I need to insert/delete items in the middle very quickly
      * I need to add or remove items from both the front and the back
      * I need "Last-In, First-Out" (LIFO) behavior
      * I need "First-In, First-Out" (FIFO) behavior
      * I need to access items based on their importance, not arrival time
      * I need to store unique items and keep them sorted
      * I need to store unique items with the fastest possible search
      * I need to map a Key to a Value and keep the Keys sorted
      * I need to map a Key to a Value with the fastest search speed

      * Options: map, forward_list, deque, vector, stack,  unordered_set, list, queue, priority_queue, set, unordered_map
