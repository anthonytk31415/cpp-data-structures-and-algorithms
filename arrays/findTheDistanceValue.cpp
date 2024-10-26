#include <iostream>; 
#include <vector>; 

using namespace std; 

// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
// 1385. Find the Distance Value Between Two Arrays

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0; 
    for (int n1 : arr1) {
        bool isValidNum = true;
        for (int n2: arr2) {
            if (abs(n1 - n2) <= d){
                isValidNum = false; 
                break; 
            }
        }
        if (isValidNum)
            count += 1; 
    }
    return count ; 
}