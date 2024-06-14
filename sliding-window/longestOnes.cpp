#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75
// 1004. Max Consecutive Ones III

// Invariant: at right index, you will find the longest valid window that includes right. 
// Iterate right index across the string. Set left at 0. Count zeroes. While zeroes > k: decrease left. 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    
        int j = 0, res = 0, countZeroes = 0; 
        for (int i = 0; i < size(nums); i ++){
            if (nums[i] == 0)
                countZeroes += 1; 
            while (countZeroes > k && j <= i){
                if (nums[j] == 0)
                    countZeroes -= 1;
                j += 1;
            }
            res = max(res, i - j + 1);
        }
        return res; 
    }
};



int main()
{
    Solution s = Solution();  
    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0} ;
    // int k = 2;
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1} ;
    int k = 3;
    int res = s.longestOnes(nums, k); 
    cout << "answer is: " << res; 
    return 0;
}