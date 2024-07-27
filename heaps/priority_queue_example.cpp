// Priority Queue: The C++ STL also provides the std::priority_queue container adapter, which encapsulates a heap. 
// By default, it is a max-heap, but you can make it a min-heap by providing a custom comparator.

// Here's an example of using std::priority_queue:

#include <queue>
#include <vector>
#include <iostream>

int main() {
    std::priority_queue<int> pq;

    // Add elements to the priority queue
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);

    // Display and remove elements from the priority queue
    std::cout << "Priority Queue: ";
    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << '\n';

    // Min-heap example
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(4);
    min_pq.push(1);
    min_pq.push(5);

    std::cout << "Min-heap Priority Queue: ";
    while (!min_pq.empty()) {
        std::cout << min_pq.top() << ' ';
        min_pq.pop();
    }
    std::cout << '\n';

    return 0;
}