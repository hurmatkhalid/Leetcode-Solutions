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
    TreeNode*previousNode;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode*dummy= new TreeNode(0);
        previousNode= dummy;
        inOrderTraversal(root);
        return dummy->right;
    }
    void inOrderTraversal(TreeNode* node){
        if(node==nullptr)   return;
        inOrderTraversal(node->left);
        previousNode->right= node;
        node->left=nullptr;
        previousNode = node;
        inOrderTraversal(node->right);
    }
};