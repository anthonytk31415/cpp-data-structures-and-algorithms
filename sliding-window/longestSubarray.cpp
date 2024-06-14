#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75
// 1493. Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j = 0, countZero = 0, res = 0; 
        for (int i = 0; i < nums.size(); i ++){
            if (nums[i] == 0){
                countZero += 1; 
            } 
            while (countZero > 1 && j <= i){
                if (nums[j] == 0){
                    countZero -=1;
                }
                j += 1; 
            }
            res = max(res, i - j + 1 - 1); 
        }
        return res; 
    }
};


int main() {

    Solution sol = Solution();
    // string s = "abciiidef";
    // int k = 3;

    // int res = sol.longestSubarray(s, k); 
    // cout << res; 
    return 0; 
}