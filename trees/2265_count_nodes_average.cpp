// Given the root of a binary tree, return the number 
// of nodes where the value of the node is equal
//  to the average of the values in its subtree.
// Note:
// The average of n elements is the sum of the n elements 
// divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    vector<int> dfs(TreeNode* node){
        if (!node) return {0, 0}; 
        vector<int>leftSubTree= dfs(node->left);
        vector<int>rightSubTree = dfs(node->right);
        int subTreeSum = leftSubTree[0]+rightSubTree[0]+node->val; 
        int subTreeCount = leftSubTree[1]+rightSubTree[1]+1;
        if(subTreeSum/subTreeCount==node->val)  ++ans;
        return {subTreeSum, subTreeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};