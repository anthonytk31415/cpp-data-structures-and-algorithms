// Heap: The C++ STL provides heap-related functions to manage heaps using any random-access container (like std::vector). These functions are:

// std::make_heap: Converts a range of elements into a heap.
// std::push_heap: Adds an element to the heap.
// std::pop_heap: Removes the largest element from the heap.


#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // Convert the vector into a heap
    std::make_heap(vec.begin(), vec.end());

    // Display the heap
    std::cout << "Heap: ";
    for (const auto& elem : vec) std::cout << elem << ' ';
    std::cout << '\n';

    // Add a new element to the heap
    vec.push_back(8);
    std::push_heap(vec.begin(), vec.end());

    // Display the heap
    std::cout << "After push_heap: ";
    for (const auto& elem : vec) std::cout << elem << ' ';
    std::cout << '\n';

    // Remove the largest element from the heap
    std::pop_heap(vec.begin(), vec.end());
    vec.pop_back();

    // Display the heap
    std::cout << "After pop_heap: ";
    for (const auto& elem : vec) std::cout << elem << ' ';
    std::cout << '\n';

    // Sort the heap
    std::sort_heap(vec.begin(), vec.end());

    // Display the sorted elements
    std::cout << "After sort_heap: ";
    for (const auto& elem : vec) std::cout << elem << ' ';
    std::cout << '\n';

    return 0;
}