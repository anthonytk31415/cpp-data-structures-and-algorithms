#include <algorithm>
#include <iostream> 
#include <vector>

using namespace std; 
// sorting by a specific function

void printVector(vector<int> &nums){
    for (int &x : nums){
        cout << x << ", "; 
    }
    cout << endl; 
}

void sortExample() {
    vector<int> nums = {1, 3, 2, 5, 7, 0, 6, 4};
    vector<int> numsSlice(nums.begin() + 1, nums.end() - 2); // 3, 2, 5, 7, 0, 
    vector<int> numsSlice1(nums.begin() + 1, nums.end() -1); // 3, 2, 5, 7, 0, 6, 
    sort(nums.begin(), nums.end());
    printVector(nums);
    printVector(numsSlice);
    printVector(numsSlice1);
};

void sortDescendingExample() {
    vector<int> nums = {1, 3, 2, 5, 7, 0, 6, 4};
    sort(nums.begin(), nums.end(), [](int &a, int &b) {
        return a > b; 
    });
    printVector(nums);    
};

void sortDescendingVectorsExample() {
    vector<vector<int>> nums = {{1, 3},{ 2, 5}, {7, 0}, {6, 4}, {7, 1}, {1, 7}, {2, -1}};
    sort(nums.begin(), nums.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]){
            return a[0] > b[0];
        } else {
            return a[1] > b[1]; 
        }
    });
    for (auto &x : nums){
        cout << "(" << x[0] << ", " << x[1] << "); " ;
    }
    cout << endl; 
};




int main() {
    sortDescendingVectorsExample(); 
    // sortExample();
    // sortDescendingExample();  
    return 0; 
};