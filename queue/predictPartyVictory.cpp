#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// https://leetcode.com/problems/dota2-senate/?envType=study-plan-v2&envId=leetcode-75
// 649. Dota2 Senate

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q = {};
        int r = 0, d = 0, popR = 0, popD = 0;  
        // push everything to the queue 
        for (char c : senate) {
            if (c == 'R')
                ++r; 
            else 
                ++d;   
            q.push(c);
        }
        while (!q.empty()){
            if (q.front() == 'R' && popR > 0){
                q.pop(); 
                --r; 
                --popR; 
            } else if (q.front() == 'D' && popD > 0){
                q.pop();
                --d;  
                --popD;
            } else if (q.front() == 'R' && d == 0){
                return "Radiant";
            } else if (q.front() == 'D' && r == 0){
                return "Dire";
            } else if (q.front() == 'R'){
                q.pop();
                ++popD; 
                q.push('R'); 
            } else if (q.front() == 'D'){
                q.pop();
                ++popR; 
                q.push('D'); 
            }
        }
    return "Error";
    }
};


    
int main() {

    Solution sol = Solution();
    string s = "RDD";
    string res = sol.predictPartyVictory(s);
    cout << "res: " << res << endl; 
    return 0;

}