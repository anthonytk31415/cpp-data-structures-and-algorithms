#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75
// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};                
        int countVowels = 0, res = 0; 
        for (int i = 0; i < k-1; i ++){
            if (vowels.find(s[i]) != vowels.end())
                countVowels += 1;
        }
        for (int i = k-1; i < s.size(); i ++){
            if (vowels.find(s[i]) != vowels.end())
                countVowels += 1;
            res = max(res, countVowels); 
            if (vowels.find(s[i - (k-1)]) != vowels.end())
                countVowels -= 1;
        }

        cout << "weird string arithmetic: " << 'z' - 'a' << endl;
        return res; 
    }
};

// 'z' - 'a' // returns 25

int main() {

    Solution sol = Solution();
    string s = "abciiidef";
    int k = 3;

    int res = sol.maxVowels(s, k); 
    cout << res; 
    return 0; 
}