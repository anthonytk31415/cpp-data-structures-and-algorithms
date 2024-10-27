#include <iostream>
#include <vector> 

using namespace std; 

int cost(string &w1, string &w2, int i, int j) {
    if (i-1 >= w1.size() || j-1 >= w2.size()){
        return 1;
    }
    return (w1[i-1] == w2[j-1]) ? 0 : 1; 
}

int dp(string &w1, string &w2, int i, int j, vector<vector<int>> &memo) {
    int m = w1.size(), n = w2.size(); 
    int res = INT32_MAX;     
    if (memo[i][j] != -1){
        res = memo[i][j]; 
    } else {
        res = min(res, 1 + dp(w1, w2, i, j-1, memo));
        res = min(res, 1 + dp(w1, w2, i-1, j, memo));
        res = min(res, cost(w1, w2, i, j) + dp(w1, w2, i-1, j-1, memo));
        memo[i][j] = res; 
    }
    return res; 
}

int edit_distance(string w1, string w2){
    int m = w1.size(), n = w2.size(); 
    vector<vector<int>> memo (m + 1, vector<int> (n + 1, -1)); 
    for (int i = 0; i < memo.size(); i ++){
        memo[i][0] = i; 
    }
    for (int j = 0; j < memo[0].size(); j ++){
        memo[0][j] = j; 
    }
    for (int i = 1; i < memo.size(); i ++){
        for (int j = 1; j < memo[0].size(); j ++){
            dp(w1, w2, i, j, memo); 
        }
    }
    return memo[m][n]; 
}


int main(){
    // string w1 = "fear"; 
    // string w2 = "feap"; // 3
    string w1 = "kitten"; 
    string w2 = "sitting"; // 3
    // string w1 = "flaw"; 
    // string w2 = "lawn"; // 2
    cout << w1 << "; " << w2 << endl;
    int res = edit_distance(w1, w2); 

    cout << "answer: "<< res << endl;
    return 0; 
}