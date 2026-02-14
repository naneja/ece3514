## Practice Lab Assignment 2.4.2: Virtual Destructors & Resource Cleanup in Polymorphism

### Overview

This lab focuses on a classic C++ pitfall: deleting derived objects through base-class pointers. 

You’ll investigate destructor behavior, identify a memory/resource leak, and fix it using proper polymorphic design and modern C++ techniques.



### Starter Code

```cpp
#include <iostream>

class CreditCard {
    public:
        ~CreditCard() { 
            std::cout << "~CreditCard\n"; 
        }
        
        // polymorphic class
        virtual bool charge(double) { 
            return true; 
        }
};

class PredatoryCreditCard : public CreditCard {
    // dynamically allocated resource
    int* log_;
    public:
        PredatoryCreditCard(){ //allocate resource
            log_ = new int[1000];
        }
        ~PredatoryCreditCard() { // should free resource
            std::cout << "~PredatoryCreditCard (freeing)\n";
            delete[] log_;
        }
};

int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    delete wallet[0];
    delete wallet[1];
}
```



* When `delete wallet[0];` runs, which destructor(s) execute?
* When `delete wallet[1];` runs, which destructor(s) execute?
  * Is `~PredatoryCreditCard()` called? 
  * What does that imply about the dynamically allocated array?
* Fix the class so the destructor of the derived class runs. It will print:
  * ~PredatoryCreditCard (freeing)