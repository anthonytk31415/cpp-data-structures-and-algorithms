// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
// 2605. Form Smallest Number From Two Digit Arrays



class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); 
        sort(nums2.begin(), nums2.end());         
        unordered_set<int> n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end());  
        for (int num : nums1){
            if (n2.contains(num)){
                return num;
            }            
        }
        int x1 = nums1[0], x2 = nums2[0];
        if (x2 < x1){
            swap(x1, x2); 
        }
        return stoi(to_string(x1) + to_string(x2)); 
    }
};