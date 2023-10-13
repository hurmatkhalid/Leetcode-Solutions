// Given an unsorted array of integers nums, 
// return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

#include <iostream>
#include <vector>
using namespace std;

//brute
// running unhealthy amount of loops

// best1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count=0;
        int max_count=0;
        for(int i=0; i<n; i++){
            if(i==0) {
                count++;
                max_count=1;
                continue;
            }
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1) count++;
            else count=1;
            max_count = max(count, max_count);
        }
        return max_count;
    }
};
//best2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int>st(nums.begin(), nums.end());
        for(auto it: st){
            if(st.find(it - 1)== st.end()){
                int count =1;
                int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                count++;
            }
            longest = max(longest, count);
            }
        }
        return longest;
    }
};
int main()
{   
    return 0;
}