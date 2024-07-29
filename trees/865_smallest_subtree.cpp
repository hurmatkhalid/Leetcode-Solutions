// Given the root of a binary tree, the 
// depth of each node is the shortest distance to the root.
// Return the smallest subtree such that it 
// contains all the deepest nodes in the original tree.
// A node is called the deepest if it has the 
// largest depth possible among any node in the entire tree.
// The subtree of a node is a tree consisting of
//  that node, plus the set of all descendants of that node.

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)   return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*firstnode;
        TreeNode*lastnode;
        while(!q.empty()){
            firstnode = q.front();
            lastnode= q.back();
            int size= q.size();
            while(size){
                TreeNode*curr= q.front();
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                size--;
            }
        }
        return lca(root, firstnode, lastnode);
    }
    private:
        TreeNode* lca(TreeNode* root, TreeNode*p, TreeNode*q){
            if(!root || root==p || root==q) return root;
            TreeNode* left = lca(root->left, p, q);
            TreeNode*right = lca(root->right, p, q);
            if(!left)   return right;
            else if(!right)  return left;
            else    return root;
        }
};