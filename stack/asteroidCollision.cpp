#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
// 2390. Removing Stars From a String

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res; 
            for (int x : asteroids){
                int last = 0; 
                bool push = true; 
                while (!res.empty() && res.back() > 0 and x < 0){
                    last = res.back(); 
                    if (abs(last) < abs(x)){
                        res.pop_back(); 
                    } else if (abs(last) == abs(x)){
                        res.pop_back(); 
                        push = false; 
                        break;
                    } else {
                        push = false; 
                        break; 
                    }   
                }
                if (push){
                    res.push_back(x);
                }
            }
        return res; 
    }
};



    
int main() {

    Solution sol = Solution();
    // vector<int> asteroids = {5,10,-5};
    // vector<int> asteroids = {10,2,-5};
    // vector<int> asteroids = {5,10,-10, -5, 5, -6};
    vector<int> asteroids = {5,10, 12,-10, -5, 5, -6};
    // string word1 = "lllllll";
    vector<int> res = sol.asteroidCollision(asteroids);
    for (auto x : res){
        cout << x << ",";
    }
    return 0;

}