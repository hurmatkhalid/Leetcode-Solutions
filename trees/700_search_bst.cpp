// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals 
// val and return the subtree rooted with that node. 
// If such a node does not exist, return null.

// naive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(root->val> val){
                root = root->left;
            }
            else if(root->val<val){
                root= root->right;
            }
            else{
                return root;
            }
        }
        return NULL;
    }
};

// slightly optimized
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)   return NULL;
        if(root->val==val)  return root;
        if(root->val>val)   return searchBST(root->left, val);
        if(root->val<val)   return searchBST(root->right, val);
        return NULL;
    }
};