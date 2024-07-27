#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;


// pointers

// References


// funcions
// 

void printVectorContents(vector<int> &v){
    cout << "printing contents of vector: " << endl; 
    for (int &num : v) {
        cout << num << ", "; 
    }
    cout << endl;
    return; 
}

void merge(vector<int> &nums, vector<int> &left, vector<int> &right) {
    int i = 0, j = 0, k = 0; 
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]){
            nums[k] = left[i]; 
            i ++; 
        } else {
            nums[k] = right[j]; 
            j ++; 
        }
        k ++; 
    }
    while (i < left.size()){
        nums[k] = left[i];
        i ++; 
        k ++; 
    }
    while (j < right.size()){
        nums[k] = right[j];
        j ++; 
        k ++; 
    }    
    return; 
}


void mergesort(vector<int> &nums){
    if (nums.size() > 1){
        int q = nums.size() / 2; 
        vector<int> left(nums.begin(), nums.begin() + q); 
        vector<int> right(nums.begin() + q, nums.end());
        mergesort(left); 
        mergesort(right); 
        merge(nums, left, right); 
    }
    return;
}


int main() {
    cout << "hello world!" << endl; 
    // vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> nums = {7, 6, 1, 3, 0, 5, 4, 2};
    cout << "nums[0]: " << nums[0] << endl;
    auto z = nums.begin() + 1;

    vector<int> numsSlice(nums.begin() + 1, nums.begin() + 1 + 3);        // is this the best way to take a slice of a vector?; 
    printVectorContents(numsSlice);

    cout << "Address of z: &z = " << &z << endl; 
    cout << "Dereference a pointer: *z = " << *z << endl; 
    printVectorContents(nums);

    // merge(nums, nums);
    mergesort(nums); 
    printVectorContents(nums);

    // pointer practice
    int n = 10; 
    int *p = &n; 
    cout << "address: p = " << p << ", value: p* = " << *p <<  endl;
    cout << "now we do *p = 11, which will change the object at address p to 11, i.e. n. " << endl;
    *p = 11; 
    cout << "address: p = " << p << ", value: p* = " << *p <<  endl;
    cout << "n = " << n <<  endl;
    return 0;
}


