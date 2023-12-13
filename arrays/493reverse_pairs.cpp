// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

#include <iostream>
#include <vector>
using namespace std;

// brute force ---- gives tle
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long first = nums[i];
                long long second = nums[j];
                if( first > 2* second){
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}