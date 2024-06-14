#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <format>
using namespace std;

int main() 
{
    unordered_set <int> nums = {}; 
    vector<int> numsToInsert = {1,2,2,3,4}; 
    for (auto num : numsToInsert)
        nums.insert(num);
    nums.erase(1);
    if (nums.find(2) != nums.end()) 
        cout << "found key" << endl;
    for (auto &num : nums) 
        cout << num << endl;
    return 0;
}