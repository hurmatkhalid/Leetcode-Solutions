// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// brute force
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; j++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> final(ans.begin(), ans.end());
        return final;
    }
};

// better approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> s1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            set<int> hashset;
            for (int j = i + 2; j < n; j++)
            {
                hashset.insert(nums[j - 1]);
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    s1.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(s1.begin(), s1.end());
        return ans;
    }
};

// best approach
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}