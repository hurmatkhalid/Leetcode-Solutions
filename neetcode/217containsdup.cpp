// Given an integer array nums, return true if any value 
// appears at least twice in the array, and 
// return false if every element is distinct.

// 375ms,  71mb
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set <int> s1;
        for(int i=0; i<nums.size(); i++){
            if(s1.find(nums[i])!=s1.end()){
                return true;
            }
            s1.insert(nums[i]);
        }
        return false;
    }
};

// 180ms,  57mb
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i<nums.size(); i++){
            if(nums[i]==nums[i-1])  return true;
        }
        return false;
    }
};

// 89ms, 57mb
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i<nums.size(); ++i){
            if(nums[i]==nums[i-1])  return true;
        }
        return false;
    }
};