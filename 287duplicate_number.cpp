// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number. You must solve
// the problem without modifying the array nums and uses only constant extra space.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    return 0;
}