//greeting.cpp

#include "greeting.hpp"

std::string CreateGreeting(
    const std::string userName){

    if (userName == "") {
        throw std::invalid_argument("name cannot be empty");
    }

    return "Hello, " + userName + "!";
}

std::string GenerateWelcomeMessage(
    const std::string userName){

    if (userName == "")
        throw std::invalid_argument("name cannot be empty");
    std::string greeting = CreateGreeting(userName);
    greeting += " Welcome to the class!";
    return greeting;

}
