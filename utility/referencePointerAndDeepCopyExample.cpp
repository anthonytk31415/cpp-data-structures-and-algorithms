#include <iostream> 
#include <vector> 

using namespace std; 

int main () {
    vector<int> original = {1, 2, 3, 4, 5};
    
    // Using the copy constructor
    vector<int> copy(original);

    // Using assignment operator 
    vector<int> copy1 = original; 

    // using a reference
    vector<int> &referenceToOriginal = original; 

    // using a pointer
    vector<int>* pointerToOrignal = &original; 
}

