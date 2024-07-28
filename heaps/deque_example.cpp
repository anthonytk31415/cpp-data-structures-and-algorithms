// deque_example

#include <iostream>
#include <deque>

using namespace std; 

int main() {
    // Create a deque of integers
    deque<int> d;
    // Insert elements at the back
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    // Insert elements at the front
    d.push_front(5);
    d.push_front(1);
    // Access elements
    cout << "Elements in deque: ";
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
    // Remove elements from the front
    d.pop_front();
    // Remove elements from the back
    d.pop_back();
    // Access element at a specific position
    cout << "Element at index 1: " << d[1] << endl;
    return 0;
}