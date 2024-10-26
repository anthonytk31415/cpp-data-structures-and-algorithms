// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/description/
#include <iostream>
#include <vector> 
#include <algorithm>
#include <unordered_map>

class Solution {
public:

    std::unordered_map<int, int> getRankMap(vector<int>& sortedArr){
        std::unordered_map<int, int> rankMap; 
        int curRank = 0; 
        for (int i = 0; i < sortedArr.size(); ++i) {
            if (i == 0 || sortedArr[i-1] < sortedArr[i]){
                curRank += 1; 
                rankMap[sortedArr[i]] = curRank; 
            }
        }
        return rankMap; 
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr; 
        std::sort(sortedArr.begin(), sortedArr.end());
        std::unordered_map<int, int> rankMap = getRankMap(sortedArr);
        vector<int> rankedArr; 
        for (int num : arr){
            rankedArr.push_back(rankMap[num]); 
        }
        return rankedArr;         
    }
};