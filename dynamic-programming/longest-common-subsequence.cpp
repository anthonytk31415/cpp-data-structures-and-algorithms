#include <iostream>
#include <vector>

// longest common subsequence implementation


using namespace std; 

int lcmHelper(int i, int j, string & word1, string & word2, vector<vector<int>> & memo){
    int m = word1.size(), n = word2.size(); 
    if (i < 0 || j < 0){
        return 0; 
    } 
    if (memo[i][j] != -1) {
        return memo[i][j]; 
    }
    int res; 
    if (word1[i] == word2[j]){
        res = 1 + lcmHelper(i - 1, j - 1, word1, word2, memo); 
    } else {
        res = max(
            lcmHelper(i - 1, j, word1, word2, memo), 
            lcmHelper(i, j - 1, word1, word2, memo)
        ); 
    }
    memo[i][j] = res; 
    return res; 
}

int lcm(string & word1, string & word2){
    int m = word1.size(), n = word2.size(); 
    vector<vector<int>> memo (m, vector<int>(n, -1)); 
    for (int i = 0; i < m; ++i ){
        for (int j = 0; j < n; ++j) {
            lcmHelper(i, j, word1, word2, memo); 
        }
    }
    return memo[m-1][n-1];  
}


int main() {
    cout << "longest common subsequence" << endl;
    // string word1 = "fearless"; 
    // string word2 = "fealsdontgo"; 
    // string word1 = "aab"; 
    // string word2 = "aba"; 
    string word1 = "AGGTAB"; // 4 = GTAB
    string word2 = "GXTXAYB"; 
    int res = lcm(word1, word2); 
    cout << res << endl;
    return 0; 
}
