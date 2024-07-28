#include <tuple>
#include <iostream>
#include <string>

using namespace std; 

int main() {
    // Define a tuple with different types
    tuple<int, string, double> myTuple(1, "Hello", 3.14);

    // Access tuple elements
    int myInt = get<0>(myTuple);
    string myString = get<1>(myTuple);
    double myDouble = get<2>(myTuple);

    // Print tuple elements
    cout << "Initial tuple elements: " << myInt << ", " << myString << ", " << myDouble << endl;

    // Modify tuple elements
    get<0>(myTuple) = 42;
    get<1>(myTuple) = "World";
    get<2>(myTuple) = 6.28;

    // Print modified tuple elements
    cout << "Modified tuple elements: " << get<0>(myTuple) << ", " << get<1>(myTuple) << ", " << get<2>(myTuple) << endl;

    return 0;
}