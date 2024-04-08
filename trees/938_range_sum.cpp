// Given the root node of a binary search tree and two integers low and high, 
// return the sum of values of all nodes with a value in the inclusive range [low, high].

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)  return 0;
        if(root->val<=high && root->val>=low){
            return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }
        else if(root->val<=low){
            return rangeSumBST(root->right, low, high);
        }
        else{
            return rangeSumBST(root->left, low, high);
        }
    }
};