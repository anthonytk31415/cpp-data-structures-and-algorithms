#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75
// 2215. Find the Difference of Two Arrays

class Solution {

vector<int> checkSets(unordered_set<int>& n1, unordered_set<int>& n2){
    vector<int> res = {}; 
    for (int x : n1){
        if (n2.find(x) == n2.end())
            res.push_back(x);
    }
    return res; 
}

public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> res1 = checkSets(n1, n2), res2 = checkSets(n2, n1) ; 
        vector<vector<int>> res = {}; 
        res.push_back(res1); 
        res.push_back(res2); 
        return res;
    }
};

int main() {

    Solution sol = Solution();

}