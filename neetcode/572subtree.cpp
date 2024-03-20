// Given the roots of two binary trees root and subRoot,
//  return true if there is a subtree of root with the same 
// structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of
//  a node in tree and all of this node's descendants. 
// The tree tree could also be considered as a subtree of itself.


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
    bool isSameTree(TreeNode*T1, TreeNode*T2){
        if(T1==NULL || T2==NULL)    return T1==T2;
        if(T1->val!=T2->val)    return false;
        return isSameTree(T1->right, T2->right) && isSameTree(T1->left, T2->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot==NULL) return true;
        if(root ==NULL) return false;
        if(isSameTree(root, subRoot))   return true;
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};