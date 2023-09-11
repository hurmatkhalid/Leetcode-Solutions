// Given an integer array nums, find a subarray that has the largest product,
// and return the product. The test cases are generated so that the answer will fit in a 32 -bit integer.

#include <iostream>
#include <vector>
using namespace std;

// brute force
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int max_product = INT_MIN;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int prod = 1;
                for (int k = i; k <= j; k++)
                {
                    prod *= nums[k];
                }
                max_product = max(prod, max_product);
            }
        }
        return max_product;
    }
};

// better
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int max_product = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = i; j < n; j++)
            {
                product *= nums[j];
                max_product = max(max_product, product);
            }
        }
        return max_product;
    }
};

// best
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 1, suf = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;

            pre *= nums[i];
            suf *= nums[n - i - 1];
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};

int main()
{
    return 0;
}