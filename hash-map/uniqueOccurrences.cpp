#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/unique-number-of-occurrences/?envType=study-plan-v2&envId=leetcode-75
// 1207. Unique Number of Occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> countOccurences = {}; 
        unordered_map<int, int> counter = {}; 
        for (int x : arr){
            counter[x] += 1; 
        }
        for (auto &pair : counter){
            if (countOccurences.find(pair.second) != countOccurences.end())
                return false; 
            countOccurences.insert(pair.second); 
        }
        return true; 
    }
};

// for (auto i = mp.begin(); i != mp.end(); i++) {
//     ans.insert(i->second);
// }

int main() {

    Solution sol = Solution();

}