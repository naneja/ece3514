# Practice Lab Assignment 2.1.3: BankAccount (practice Friend Class)

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