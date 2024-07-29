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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)   return ans;
        deque <TreeNode*> d;
        d.push_back(root);
        bool flag = true;
        while(!d.empty()){
            int size = d.size();
            vector<int>temp;
            for(int i =0; i<size; i++){
                if(flag){
                    TreeNode* curr= d.front();
                    d.pop_front();
                    temp.push_back(curr->val);
                    if(curr->left)  d.push_back(curr->left);
                    if(curr->right) d.push_back(curr->right);
                }else{
                    TreeNode*curr= d.back();
                    d.pop_back();
                    temp.push_back(curr->val);
                    if(curr->right)  d.push_front(curr->right);
                    if(curr->left) d.push_front(curr->left);
                }
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};