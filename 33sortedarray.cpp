// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown 
// pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
//  nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index 
// of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
#include <vector>
using namespace std;

// brute force
class Solution {
public:
    int bin(vector<int>nums, int target, int s, int e){
        while(s<=e){
            int mid= (s+e)/2;
            if(target== nums[mid])   return mid;
            else if(target< nums[mid])  e= mid-1;
            else s=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int pivot=-1;
        if(n==1){
            if(target== nums[0]){
                return 0;
            }
            else{
                return -1;
            }
        }
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                pivot= i;
            } 
        }
        if(pivot==-1){
            return bin(nums, target, 0, n-1);
        }
        if(target>=nums[0] && target<=nums[pivot-1]){
            return bin(nums, target, 0, pivot-1);
        }
        else if(target>=nums[pivot] && target<=nums[n-1]){
            return bin(nums, target, pivot, n-1);
        }
        else{
            return -1;
        }
        return -1;
    }
};

// best soln
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0;
        int e = n-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(nums[mid]== target)  return mid;
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
        return -1;
    }
};

int main()
{
    return 0;
}