#include <iostream> 
#include <vector> 

using namespace std; 

// knapsack at an (i, w) will return the max benefit at the current w weight
// with using up to the ith item; 
// you either odn't use it, or if you have capacity, you choose the max benefit
// of not using it, or using it and then after choosing it, the max benefit
// at the prior step with the smaller bag w - weight_of_item_i_taken

int knapsack(vector<int> &benefits, vector<int> &weights, int maxWeight) {
    vector<vector<int>> memo (weights.size() + 1, vector<int> (maxWeight + 1, 0)); 

    for (int i = 1; i < memo.size(); ++i){
        for (int w = 1; w < memo[0].size(); ++w){
            int maxBenefit = memo[i-1][w];
            if (w - weights[i-1] >= 0){
                maxBenefit = max(curRes, benefits[i-1] + memo[i-1][w - weights[i-1]]); 
            }
            memo[i][w] = maxBenefit; 
        }
    }
    return memo[memo.size()-1][memo[0].size()-1]; 
}


int main(){
    vector<int> benefits = {11,6,12}; 
    vector<int> weights = {12,6, 5}; 
    // vector<int> benefits = {5,8,11}; 
    // vector<int> weights = {5,6, 12}; 
    // vector<int> benefits = {1,4,6,9}; 
    // vector<int> weights = {1,2, 3, 9}; 
    int maxWeight = 12; 
    int res = knapsack(benefits, weights, maxWeight); 
    cout << res << endl;
    return 0; 
}