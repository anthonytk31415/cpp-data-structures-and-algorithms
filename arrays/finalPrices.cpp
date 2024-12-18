// 1475. Final Prices With a Special Discount in a Shop
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/


#include <iostream>
#include <algorithm>

using namespace std; 

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discountedPrice = {}; 
        for (int i = 0; i < prices.size(); ++i){
            int newPrice = prices[i];
            for (int j = i + 1; j < prices.size(); ++j){
                if (prices[j] <= prices[i]) {
                    newPrice = prices[i] - prices[j]; 
                    break; 
                }
            }
            discountedPrice.push_back(newPrice); 
        }
        return discountedPrice; 
    }
};