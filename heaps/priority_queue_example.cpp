// Priority Queue: The C++ STL also provides the priority_queue container adapter, which encapsulates a heap. 
// By default, it is a max-heap, but you can make it a min-heap by providing a custom comparator.

// Here's an example of using priority_queue:

#include <queue>
#include <vector>
#include <iostream>

using namespace std; 



// priority_queue<element type, container type, comparator type> pq<comparetype>; 

// implements priority queue by int; default: highest elements on top
void basicPQ() {
    cout << "basic priority queue" << endl;
    priority_queue<int> pq = {}; 
    vector<int> elements = {2,1,3,9,5,4}; 
    for (auto &element: elements){
        pq.push(element); 
    }
    while (!pq.empty()) {
        cout << pq.top() << ", "; 
        pq.pop();         
    }
    cout << endl;     
}


// complare descending a[0], then descending a[1]
auto compare = [](const vector <int>&a, const vector<int> &b) {
    if (a[0] != b[0]){
        return a[0] > b[0]; 
    }
    return a[1] > b[1]; 
};


// note pq reverses the order of complare since it does descending order. 
void customPQ(){
    cout << "custom priority queue" << endl;
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
    vector<vector<int>> elements = {{3, 1}, {3, 0}, {2, 3}, {1,1}, {2, 9}}; 
    // Add elements to the priority queue
    for (auto &element : elements){
        pq.push(element);        
    }
    // Display and remove elements from the priority queue
    cout << "Priority Queue: ";    
    while (!pq.empty()) {
        vector<int> x = pq.top(); 
        cout << x[0] << "," << x[1] << "; ";
        pq.pop(); 
    }
    cout << endl;
}

int main() {
    basicPQ(); 
    customPQ(); 
    return 0;
}
