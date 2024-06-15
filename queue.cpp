#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <map>
#include <format> 
#include <queue>
using namespace std;


int main () {
    queue<int> queue; 
    queue.push(1); 
    queue.push(22); 
    queue.push(133);
    int queueFront = queue.front(), queueBack = queue.back();  
    cout << format("front: {}, back: {}", queueFront, queueBack) << endl;; 
    // size: size of queue; 
    // empty: is queue empty
    size_t queueSize = queue.size(); 
    if (!queue.empty())
        cout << "queue is not empty; size is : " << queueSize << endl; 
    return 0; 
}