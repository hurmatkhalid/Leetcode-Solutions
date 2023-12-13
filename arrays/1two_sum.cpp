// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
//best
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mpp;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int second = target - nums[i];
            if(mpp.find(second)!= mpp.end()){   
                return {mpp[second], i};
            }
            mpp[nums[i]]= i;
        }
        return {-1, -1};
    }
};

int main()
{
    return 0;
}