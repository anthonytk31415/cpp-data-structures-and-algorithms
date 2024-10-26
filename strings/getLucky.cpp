#include <iostream> 
#include <unordered_map>
using namespace std; 

// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03
// 1945. Sum of Digits of String After Convert
int getLucky(string s, int k) {
    // int sInt = 0; 
    string x = ""; 
    for (char sChar : s){
        int sCharVal = sChar - 'a' + 1; 
        // sInt += sCharVal;
        x += to_string(sCharVal);  
    }
    for (int i = 0; i < k; i ++ ){
        int xTemp = 0; 
        for (char xChar : x){
            xTemp += xChar - '0'; 
        }
        x = to_string(xTemp);
    }
    // cout << x << endl;
    return stoi(x); 
};


int main() {
    string s ="iiii"; 
    int k = 1; 
    int x = getLucky(s, k); 
    cout << x << endl;
    return 0; 
}