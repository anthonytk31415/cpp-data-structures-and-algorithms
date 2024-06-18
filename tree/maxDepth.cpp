#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
// 104. Maximum Depth of Binary Tree

class Solution {
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;          
        int left = maxDepth(root->left);         
        int right = maxDepth(root->right);
        return max(left, right)+1;
    }
};