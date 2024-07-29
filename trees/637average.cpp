// Given the root of a binary tree, 
// return the average value of the nodes on 
// each level in the form of an array. Answers 
// within 10-5 of the actual answer will be accepted.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(!root)   return ans;
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            int size = q1.size();
            double sum = 0;
            
            for(int i = 0; i<size; i++){
                TreeNode* curr = q1.front();
                q1.pop();
                sum += curr->val;

                if(curr->left)  q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};