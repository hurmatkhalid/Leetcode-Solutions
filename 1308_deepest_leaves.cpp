// Given the root of a binary tree, return the sum of values of its deepest leaves.


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
    int deepestLeavesSum(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> level_queue;
        level_queue.push(root);
        while(!level_queue.empty()){
            ans=0;
            for(int i=level_queue.size(); i>0; i--){
                TreeNode*current_node= level_queue.front();
                level_queue.pop();
                ans+=current_node->val;
                if(current_node->left)  level_queue.push(current_node->left);
                if(current_node->right) level_queue.push(current_node->right);
            }
        }
        return ans;
    }
};