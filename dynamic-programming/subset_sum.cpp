// subset sum


#include <iostream>
#include <vector> 
#include <string> 


using namespace std; 

int subset_sum(vector<int> & nums, int t) {
    vector<vector<int>> memo (nums.size() + 1, vector<int> (t+1, 0));
    for (int i = 0; i < memo.size(); ++i){
        memo[i][0] = 1; 
    }
    for (int i = 1; i < memo.size(); ++i){
        for (int k = 1; k < memo[0].size(); ++k){
            memo[i][k] |= memo[i-1][k];
            if (k - nums[i-1] >= 0){
                memo[i][k] |= memo[i-1][k - nums[i-1]];
            }
        }
    }
    return memo[memo.size()-1][memo[0].size() - 1]; 
}

int main(){
    // vector<int> nums = {3,4,5}; 
    // int t = 11;  // false

    vector<int> nums = {1000, 10, 1, 341}; 
    int t = 1011;  // true
    int res = subset_sum(nums, t); 
    cout << res << endl;
    return 0; 
}