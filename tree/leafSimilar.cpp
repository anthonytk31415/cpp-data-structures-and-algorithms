#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// https://leetcode.com/problems/leaf-similar-trees/description/?envType=study-plan-v2&envId=leetcode-75
// 872. Leaf-Similar Trees

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
    vector<int> dfs(TreeNode* root){
        vector<int> res = {}; 
        if (!root)
            return res; 
        if (!root->left && !root->right){
            res.insert(res.end(), root->val);
            return res; 
        } 
        vector<int> left = dfs(root->left), right = dfs(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());        
        return res; 
    };

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left = dfs(root1), right = dfs(root2);
        return left == right;  
    }
};  