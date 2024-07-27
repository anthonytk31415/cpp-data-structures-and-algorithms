#include <tuple>
#include <iostream>
#include <string>

int main() {
    // Define a tuple with different types
    std::tuple<int, std::string, double> myTuple(1, "Hello", 3.14);

    // Access tuple elements
    int myInt = std::get<0>(myTuple);
    std::string myString = std::get<1>(myTuple);
    double myDouble = std::get<2>(myTuple);

    // Print tuple elements
    std::cout << "Initial tuple elements: "
              << myInt << ", "
              << myString << ", "
              << myDouble << std::endl;

    // Modify tuple elements
    std::get<0>(myTuple) = 42;
    std::get<1>(myTuple) = "World";
    std::get<2>(myTuple) = 6.28;

    // Print modified tuple elements
    std::cout << "Modified tuple elements: "
              << std::get<0>(myTuple) << ", "
              << std::get<1>(myTuple) << ", "
              << std::get<2>(myTuple) << std::endl;

    return 0;
}