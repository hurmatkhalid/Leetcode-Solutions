// Suppose an array of length n sorted in ascending order 
// is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 
// 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.


// naive
class Solution {
public:
    int findMin(vector<int>& nums) {
        int end_pointer = nums.size()-1;
        int count=0;
        while(nums[end_pointer]<nums[0]){
            count++;
            end_pointer--;
        } 
        if(count){
            int rotation = nums.size()-count;
            return nums[rotation];
        }
        return nums[0];
    }
};

// optimal
class Solution{
public:
    {
        int findMin(vector<int>&nums){
            int result= INT_MAX;  
            int start=0;
            int end=nums.size()-1;
            while(start<end){
                int mid = start + (end-start)/2;
                if(nums[mid]>nums[start]){
                    result= min(result, nums[start]);
                    start=mid+1;
                }
                else{
                    result=min(result, nums[mid]);
                    end=mid-1;
                }
            }
            return min(result, nums[start]);
        }
    }
}