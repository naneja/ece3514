## Practice Lab Assignment 5.1.1: Build a High-Score Scoreboard (Dynamic Arrays)

* By the end of this lab, you should be able to:
  * Design small C++ classes with private data and public methods
  * Manage a dynamic array with new[] / delete[]
  * Maintain a sorted list (highest score first) using shifting
  * Throw std::out_of_range for invalid indexing
  * Prevent copying of a class that owns heap memory (Rule of 3/5 awareness)
* Background
  * You are building a high-score table for a game. 
  * The scoreboard:
    * Has a fixed capacity (e.g., top 5 scores)
    * Stores entries as (name, score)
    * Always keeps the list sorted in descending by score
    * When full, it only inserts a new entry if it beats the lowest score currently on the board

## Create Class: GameEntry

* Represents one score entry:
  * private data members
    * name (string)
    * score (int)
  * getters: 
    * get_name(), 
    * get_score()

## Create Class: Scoreboard

* private data members
  * Represents the high-score list using a dynamic array GameEntry* board
  * int capacity
  * int num_entries
* Constructor:
  * Scoreboard(int cap=10)
  * allocates dynamic memory (array) of cap objects to GameEntry* board
* Destructor 
  * ~Scoreboard()
* accessors: 
  * get_capacity(), 
  * get_num_entries()
  * get_entry(int i) with range checking
  * void add(int score, const std::string& name);
    * Checks if there is space (num_entries < capacity)
    * If the board is full, only inserts if score is greater than the current lowest score
    * Keeps the list sorted from highest to lowest
    * Uses shifting to make room for the new entry
    * Hints
      * The lowest score is the last valid element: board[num_entries-1]
      * If inserting, shift elements right while the previous score is smaller
  * GameEntry remove(int i);
    * Implement remove(i) so that it:
      * throws std::out_of_range if i is invalid
      * saves the element at index i to return later
      * shifts all elements after i one position left
      * decrements num_entries
      * returns the removed entry
  * Copy semantics and move semantics should be disabled (to avoid accidental shallow copies).

## Rules

* Do not use std::vector
* Do not reallocate memory

## Print Utility Function

```cpp
void print_board(const Scoreboard &board);
```

* Write the print_board function:
  * Accept a Scoreboard object by const reference
  * Iterate through all stored entries using board.get_num_entries()
  * Access each entry using: board.get_entry(i)
  * Print each entry in the following format:
    * Print all entries on one line separated by a tab (`\t`)
    * Print a newline (\n) at the end



## Write main() function

* Write a main() that demonstrates all features.
  * Create a scoreboard of capacity 5
  * Add 5 entries
  * Print the board
  * Add a new entry that should insert and cause a drop (because capacity is full)
  * Print the updated board
  * Remove an entry (try removing the middle element)
  * Print the board again
  * Demonstrate exception behavior by attempting:
    * get_entry(-1)
    * get_entry(999)
    * remove(999)

### Expected Sample Output

```cpp
/*
Current Scoreboard:
1. P1: 800      2. P2: 650      3. P3: 400      4. P4: 360      5. P5: 240

Updated Scoreboard:
1. P1: 800      2. P3: 700      3. P2: 650      4. P3: 400      5. P4: 360
*/
```

