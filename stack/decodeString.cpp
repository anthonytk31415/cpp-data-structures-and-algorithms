#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75
// 394. Decode String

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<string> stack0; 
        string res = "";  
        for (char& c : s){
            if (c == ']') {
                string curString = ""; 
                while (stack0.top() != "["){
                    curString = stack0.top() + curString; 
                    stack0.pop(); 
                }
                stack0.pop(); // pop the '[' from the stack                
                int n = stoi(stack0.top());     // will always be the "large int" 
                stack0.pop(); 
                string newString = ""; 
                for (int i = 0; i < n; ++i)
                    newString += curString; 
                stack0.push(newString);
            } else if (isdigit(c)){ 
                if (!stack0.empty() && isdigit(stack0.top().back())){
                    stack0.top() = stack0.top() + c; 
                } else stack0.push(string() + c);      // notation for turning string + 
            } else stack0.push(string() + c);
        }
        while (!stack0.empty()){
            res = stack0.top() + res; 
            stack0.pop();
        }
        return res; 
    }
};


    
int main() {

    Solution sol = Solution();
    // string s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    string s = "11[abc]3[cd]ef";

    string res = sol.decodeString(s);
    cout << "res: " << res << endl; 
    return 0;

}