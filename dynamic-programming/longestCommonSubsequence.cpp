// longest common subsequence 
#include <iostream>
#include <unordered_map>
#include <string> 

int lcs(std::string word1, std::string word2) {
    int m = word1.size(), n = word2.size(); 

    // memo will capture the lcs up to i and j, where memo[i][j] corresponds to the ith entry of 1-indexed word
    // at i = 0, j= 0 we have memo[i][j] = 0 as sentinel values
    std::vector<std::vector<int>> memo(m+1, std::vector(n+1, 0)) ;

    for (auto i = 0; i < m; ++i){
        for (auto j = 0; j < n; ++j){
            int curEntry;  
            if (word1[i] == word2[j]){
                curEntry = 1 + memo[i][j];
            } else {
                curEntry = std::max(memo[i+1][j], memo[i][j+1]); 
            }
            memo[i+1][j+1] = curEntry; 
        }
    }
    return memo[m][n];

}


int main() {
    std::string x = "morning";
    std::string y = "triangle"; 
    std::cout << "hi there" << std::endl;
    int res = lcs(x, y);
    std::cout << "running: " << res << std::endl;
    return 0; 
}


