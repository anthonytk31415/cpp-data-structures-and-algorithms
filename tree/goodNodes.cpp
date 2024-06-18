#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// https://leetcode.com/problems/count-good-nodes-in-binary-tree/?envType=study-plan-v2&envId=leetcode-75
// 1448. Count Good Nodes in Binary Tree

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
    void dfs(TreeNode* node, int &res, int curMax) {
        if (node->val >= curMax)
            ++res;
        if (node->left)
            dfs(node->left, res, max(curMax, node->val));
        if (node->right)
            dfs(node->right, res, max(curMax, node->val));
        return; 
    }

public:
    int goodNodes(TreeNode* root) {
        int curMax = INT_MIN; 
        int res = 0; 
        dfs(root, res, curMax);
        return res; 
    }
};