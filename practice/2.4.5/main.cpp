#include <iostream>
#include <string>

class UserSession {
    public:
        std::string username{"guest"};
};

class LoggingFeature : virtual public UserSession {
    public:
        void logAccess() {
            std::cout << "Logging for user: " << username << "\n";
        }
};

class AuthorizationFeature : virtual public UserSession {
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