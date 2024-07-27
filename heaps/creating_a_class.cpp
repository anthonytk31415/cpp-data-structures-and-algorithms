#include <iostream>

class MyClass {
public:
    // Constructor
    MyClass(int initialValue) : value(initialValue) {
        std::cout << "MyClass initialized with value: " << value << std::endl;
    }

    // Method 1: Set a new value
    void setValue(int newValue) {
        value = newValue;
    }

    // Method 2: Print the current value
    void printValue() const {
        std::cout << "Current value: " << value << std::endl;
    }

private:
    int value;  // Member variable
};

int main() {
    // Create an instance of MyClass with an initial value of 10
    MyClass obj(10);

    // Call methods on the object
    obj.printValue();
    obj.setValue(20);
    obj.printValue();

    return 0;
}