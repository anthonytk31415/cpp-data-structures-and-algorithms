// deque_example

#include <iostream>
#include <deque>

int main() {
    // Create a deque of integers
    std::deque<int> d;

    // Insert elements at the back
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    // Insert elements at the front
    d.push_front(5);
    d.push_front(1);

    // Access elements
    std::cout << "Elements in deque: ";
    for (int i : d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Remove elements from the front
    d.pop_front();
    std::cout << "After pop_front(): ";
    for (int i : d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Remove elements from the back
    d.pop_back();
    std::cout << "After pop_back(): ";
    for (int i : d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Access element at a specific position
    std::cout << "Element at index 1: " << d[1] << std::endl;

    return 0;
}