#include <iostream>
#include <vector>

using namespace std; 

int main() {
    vector<int> vec = {1,2,3};

    // auto example
    for (auto elem : vec) {
        std::cout << elem << " ";
    }

    // simple comparator 
    auto compare = [](const vector<int>& a, const vector<int>& b) {
        return (a[0] + a[1]) < (b[0] + b[1]);
    };

    // simple lambda 
    auto add = [](int a, int b) {
        return a + b;
    };

    int x = 1, y = 2;  

    // has scope of x, y 
    auto sum = [x, y]() {
        return x + y;
    };


    // has scope and modifies x, y
    auto modifyAndSum = [&x, &y]() {
        x += 10;
        y += 20;
        return x + y;
    };

    return 0; 
}