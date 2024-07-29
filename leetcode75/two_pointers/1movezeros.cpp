// Given an integer array nums, move all 0's to 
// the end of it while maintaining the relative 
// order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// naive
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        while(i<n){
            // skip non zeroes
            while(i < n && nums[i]!=0){
                i++;
            }
            // if we reach the end
            if(i ==n)   break;
            // after encountering first zero, skip consecutive zeros
            int pointer = i+1;
            while(pointer < n && nums[pointer]==0){
                pointer++;
            } 
            if(pointer == n)    break;

            swap(nums[i], nums[pointer]);
            i++;
        }
    }
};
// better
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int lastNonZero = 0, i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                swap(nums[lastNonZero], nums[i]);
                lastNonZero++;
            }
        }
    }
};