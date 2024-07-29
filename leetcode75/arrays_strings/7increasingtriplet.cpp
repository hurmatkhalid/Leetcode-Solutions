// Given an integer array nums, return true 
// if there exists a triple of indices (i, j, k) 
// such that i < j < k and nums[i] < nums[j] < nums[k]. 
// If no such indices exists, return false.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            for(int j =i+1; j<n-1; j++){
                if(nums[i]<nums[j]){
                    for(int k= j+1; k<n; k++){
                        if(nums[j]<nums[k])     return true;
                    }
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)   return false;
        int mini = INT_MAX;
        int mid = INT_MAX;
        for(int num: nums){
            if(num<=mini)   mini= num;
            else if(num<mid)    mid= num;
            else if(num>mid)    return true;
        }
        return false;
    }
};