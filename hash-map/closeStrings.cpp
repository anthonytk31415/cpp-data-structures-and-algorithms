#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75
// 1657. Determine if Two Strings Are Close


class Solution {

unordered_map<char, int> counter(string &word){
    unordered_map<char, int> charCounter = {}; 
    for (char c : word)
        charCounter[c] += 1;         
    return charCounter; 
}

unordered_map<int, int> freqCounter(unordered_map<char, int>& counter){
    unordered_map<int, int> freqCounter = {}; 
    for (auto pair : counter)
        freqCounter[pair.second] += 1;
    return freqCounter;
}

public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> counter1 = counter(word1), counter2 = counter(word2);
        unordered_map<int, int> freqCounter1 = freqCounter(counter1), freqCounter2 = freqCounter(counter2); 
        for (auto pair : counter1){
            if (counter2.find(pair.first) == counter2.end()){
                return false; 
            }
        }
        for (auto pair : counter2){
            if (counter1.find(pair.first) == counter1.end()){
                return false; 
            }
        }

        for (auto pair : freqCounter1){
            if (freqCounter2.find(pair.first) == freqCounter2.end() || freqCounter2[pair.first] != pair.second)
                return false; 

        }
        for (auto pair : freqCounter2){
            if (freqCounter1.find(pair.first) == freqCounter1.end() || freqCounter1[pair.first] != pair.second)
                return false; 
        }
        return true; 
    }
};
    
int main() {

    Solution sol = Solution();
    // string word1 = "ab", word2 = "bd";
    // string word1 = "cabbba", word2 = "abbccc";
    string word1 = "a", word2 = "aa";
    bool res = sol.closeStrings(word1, word2);
    cout << "res: " << res ;
    return 0;

}