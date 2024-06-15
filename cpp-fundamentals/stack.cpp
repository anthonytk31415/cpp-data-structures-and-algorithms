#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <map>
#include <format> 
#include <stack>
using namespace std;

// With the monotonic stack: you can keep track of the smallest element maintain the property of that elements in the stack are monotonically increasing. 
// As you traverse an array, you insert items in the stack as long as the insertion element is >= the element on top of the stack. If not, pop. 


int main () 
{
    stack<int> stack = {}; 
    cout << "is stack empty? : " << stack.empty() << endl; 
    stack.push(11);
    stack.push(22); 
    stack.push(33);
    // stack.push_front(44);
    stack.pop(); 
    int topElement = stack.top(); 
    cout << "top element of stack: " << topElement << endl; 
    size_t stackSize = stack.size(); 
    cout << "stack size: " << stackSize << endl; 
    return 0; 
}