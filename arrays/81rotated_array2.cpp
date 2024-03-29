// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown 
// pivot index k (0 <= k < nums.length) such that the resulting array is
//  [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0;
        int e = n-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(nums[mid]== target)  return true;
            if(nums[s]== nums[mid] && nums[e]==nums[mid]){
                s= s+1;
                e=e-1;
                continue;
            }
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && nums[mid]>=target){
                    e= mid-1;
                }
                else{
                    s= mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[e]>=target){
                    s= mid+1;
                }
                else{
                    e= mid-1;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}