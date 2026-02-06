#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "greeting.hpp"  

SCENARIO("CreateGreeting empty input", "[CreateGreeting][invalid]") {
    GIVEN("an invalid input") {
        std::string invalidInput = "";
        WHEN("the input is empty") {
            THEN("an exception should be thrown") {
                REQUIRE_THROWS(CreateGreeting(invalidInput));
            }
        }
    }
}

SCENARIO("CreateGreeting valid input", "[CreateGreeting][valid]") {
    GIVEN("a valid input") {
        WHEN("the input is 'Alice'") {
            std::string validInput = "Alice";
            THEN("the greeting should be 'Hello, Alice!'") {
                REQUIRE(CreateGreeting(validInput) == "Hello, Alice!");
            }
        }
        WHEN("the input is a numeric string '1'") {
            std::string numericInput = "1";
            THEN("the greeting should be 'Hello, 1!'") {
                REQUIRE(CreateGreeting(numericInput) == "Hello, 1!");
            }
        }
    }
}