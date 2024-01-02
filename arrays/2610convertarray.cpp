// You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

// The 2D array should contain only the elements of the array nums.
// Each row in the 2D array contains distinct integers.
// The number of rows in the 2D array should be minimal.
// Return the resulting array. If there are multiple answers, return any of them.

// Note that the 2D array can have a different number of elements on each row.


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int cnt =0;
        for(auto it:nums){
            mpp[it]++;
            cnt= max(cnt, mpp[it]);
        }
        vector<vector<int>>ans(cnt);
        for(auto it:mpp){
            int num = it.first;
            int freq = it.second;
            for(int i=0; i<freq; i++){
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};