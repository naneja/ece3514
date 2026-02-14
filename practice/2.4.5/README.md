## Practice Lab Assignment 2.4.5: Multiple Inheritance and Diamond Problem

* You inherited a small C++ prototype for a web app. It should maintain a single shared username across all features (logging and authorization). 
* But the program currently has compile errors and/or confusing behavior due to multiple inheritance.
* Your task is to debug it, ensure it compiles, and ensure the output matches the intended behavior.

```cpp
#include <iostream>
#include <string>

class UserSession {
    public:
        std::string username{"guest"};
};

class LoggingFeature : public UserSession {
    public:
        void logAccess() {
            std::cout << "Logging for user: " << username << "\n";
        }
};

class AuthorizationFeature : public UserSession {
    public:
        void checkAccess() {
            std::cout << "Checking permissions for: " << username << "\n";
        }
};

// Web application combines multiple features
class WebApplication : public LoggingFeature, public AuthorizationFeature {
};

int main() {
    WebApplication app;

    app.LoggingFeature::username = "user 100";
    std::cout << app.username << "\n";  // user 100

    app.AuthorizationFeature::username = "user 105";
    std::cout << app.UserSession::username << "\n"; // user 105

    app.WebApplication::username = "user 110";

    std::cout << app.LoggingFeature::username << "\n";      // user 110
    std::cout << app.AuthorizationFeature::username << "\n"; // user 110
    std::cout << app.username << "\n";                       // user 110
}

/*
user 100
user 105
user 110
user 110
user 110
*/
```



## Goal

* After fixes, the program should:
  * Compile cleanly
  * Maintain a single username for the entire WebApplication
  * Produce output showing that when you set the username once, both features see the same value
