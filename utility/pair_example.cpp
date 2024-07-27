#include <iostream>
#include <utility>  // For std::pair

using namespace std; 

int main() {
    pair<int, int> x = make_pair(1,2); 
    cout << "first: " << x.first << "; second: " << x.second << endl;
    return 0; 
}