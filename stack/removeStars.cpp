#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
// 2390. Removing Stars From a String

using namespace std;

class Solution {
public:

    string removeStars(string s) {
        string res = ""; 
        for (char& c : s){
            if (c == '*'){
                res.pop_back(); 
            } else {
                res += c; 
            }
        }
        return res;
    }

    string removeStars1(string s) {
        stack<char> st, st_reverse; 
        for (char c : s){
            if (c != '*') {
                st.push(c);
            } else if (c == '*' && !st.empty())
                st.pop(); 
        }
 
        while (!st.empty()) {
            char top_element = st.top();
            st_reverse.push(top_element);
            st.pop(); 
        }
        
        string res = ""; 
        while (!st_reverse.empty()){
            char top_element = st_reverse.top();
            res += top_element; 
            st_reverse.pop();
        }
        return res;         
    }
};


    
int main() {

    Solution sol = Solution();
    string word1 = "leet**cod*e";
    // string word1 = "lllllll";
    string res = sol.removeStars(word1);
    cout << "res: " << res ;
    return 0;

}