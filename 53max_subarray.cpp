// Given an integer array nums, find the subarray with the largest sum,
// and return its sum.
#include <iostream>
#include <vector>
using namespace std;

// brute force

int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;

            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// better approach
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxsum = nums[0];
        int currentsum = nums[0];
        if (n == 1)
        {
            return nums[0];
        }
        for (int i = 1; i < n; i++)
        {
            if ((currentsum + nums[i]) < nums[i])
            {
                currentsum = nums[i];
            }
            else
            {
                currentsum += nums[i];
            }
            maxsum = max(maxsum, currentsum);
        }
        return maxsum;
    }
};

// best approach
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxsum = INT_MIN;
        int currentsum = 0;
        for (int i = 0; i < n; i++)
        {
            currentsum += nums[i];
            maxsum = max(maxsum, currentsum);
            if (currentsum < 0)
            {
                currentsum = 0;
            }
        }
        return maxsum;
    }
};

int main()
{
    return 0;
}