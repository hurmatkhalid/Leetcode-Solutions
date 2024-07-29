// Given an integer array nums, return an array answer such
//  that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix=1, postfix=1;
        vector <int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(prefix);
            prefix*=nums[i];
        }
        for(int i=n-1; i>=0; i--){
            ans[i]= ans[i]*postfix;
            postfix *=nums[i];
        }
        return ans;
    }
};