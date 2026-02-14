# Practice Lab Assignment 2.4.1

> Inheritance and Polymorphism

## Lab : Inheritance, Overriding, and Polymorphism with Credit Card



### Create a class named CreditCard with the following:

* Data Members
  * customer (string) — private
  * bank (string) — private
  * account (string) — private
  * limit (int) — private
  * balance (double) — protected (so derived class can access it)
* Constructors
  * No parameter constructor (default)
  * A parameterized constructor that initializes (use initialzer list):
    * customer, bank, account, limit
    * balance defaulting to 0.0
* Member Functions (Accessors)
  * Implement these getters (must be const):
    * get_customer()
    * get_bank()
    * get_account()
    * get_limit()
    * get_balance()
* Member Functions (Behavior)
  * bool charge(double price)
    * prints string: from class CreditCard
    * If price + balance > limit
      * return false
    * otherwise 
      * increase balance by price
      * return true
  * void make_payment(double amount)
    * prints string: from class CreditCard
    * Decrease balance by amount
* Overload operator<< as a friend so that this prints all card details:
  * Customer, Bank, Account, Balance, Limit

* Implement PredatoryCreditCard (Derived Class)



### Create a class named PredatoryCreditCard that publicly inherits from CreditCard with the following:

* Data Members
  * apr (double) — private
* Constructors
  * No parameter constructor (default)
  * A parameterized constructor that takes:
    * customer, bank, account, limit, initial balance, and interest rate
    * It must call the base class constructor for the shared fields and uses initializer list
* New Member Function
  * void process_month()
    * prints string: from PredatoryCreditCard
    * If balance > 0
      * compute monthly interest using: 
        * monthly_rate = $(1+APR)^{1/12} −1$
        * use pow from <cmath>
      * Then apply interest: 
        * balance = balance + balance × monthly_rate
* Override charge function of CreditCard Class
  * bool charge(double price):
    * prints string: from PredatoryCreditCard
    * Calls the base class charge (using scope resolution)
    * If the base charge fails
      * assess a $5 penalty by increasing balance by 5
    * return whether the charge succeeded



### Write main() function and use the above classes

* Why is the Derived charge() Not Called?

```cpp
int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    // charge is defined in both
    wallet[0]->charge(10000);//from CreditCard
    wallet[1]->charge(10000);//from CreditCard

    delete wallet[0];
    delete wallet[1];
}
/*
from CreditCard
from CreditCard
*/
```

* Fix the class so the output is as below so Polymorphism works

```cpp
/*
from CreditCard
from PredatoryCreditCard
from CreditCard
*/
```

* Why process_month() shows error with wallet[1] while process_month() is a new function defined in PredatoryCreditCard class

```cpp
int main() {
    CreditCard* wallet[2];
    wallet[0] = new CreditCard();
    wallet[1] = new PredatoryCreditCard();

    wallet[1]->process_month();

    delete wallet[0];
    delete wallet[1];
}
```

* Fix the class so the output from process_month is as below, so Polymorphism works

```cpp
//from PredatoryCreditCard
```







