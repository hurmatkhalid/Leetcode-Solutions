// Given an integer array nums and an integer k, 
// return the number of non-empty subarrays that have a sum divisible by k.
// A subarray is a contiguous part of an array.

// Brute-brute force- obviously TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        if(n==1){
            int sum = nums[0];
            if(sum%k==0)    ans++;
            return ans;
        }
        for(int i=0; i<n; i++){
            int sum = nums[i];
            if(sum%k==0)    ans++;
            for(int j=i+1; j<n; j++){
                sum+=nums[j];
                if(sum%k==0)    ans++;
            }               
        }
        return ans;
    }
};

// optimal
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        unordered_map<int, int> prefixRemainders;
        prefixRemainders[0]=1;
        int sum =0;
        for(int i =0; i<n; i++){
            sum+=nums[i];
            int remainder = sum%k;
            if(remainder <0)    remainder += k;
            if(prefixRemainders.find(remainder)!=prefixRemainders.end()){
                ans+=prefixRemainders[remainder];
            }
            prefixRemainders[remainder]++;
        }
        return ans;
    }
};