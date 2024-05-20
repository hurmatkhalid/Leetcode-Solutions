// Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
    vector<int>ans;
    void helperFunction(TreeNode*root){
        if(root==nullptr)   return;
        helperFunction(root->left);
        ans.push_back(root->val);
        helperFunction(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helperFunction(root);
        return ans;
    }
};