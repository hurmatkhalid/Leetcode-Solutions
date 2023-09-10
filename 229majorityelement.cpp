// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
// better approach
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int N = n / 3;
        sort(nums.begin(), nums.end());
        set<int> s1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count > N)
            {
                s1.insert(nums[i]);
            }
        }
        vector<int> ans(s1.begin(), s1.end());
        return ans;
    }
};
// another worse better approach
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int N = n / 3;
        vector<int> ls;
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == N + 1)
            {
                ls.push_back(nums[i]);
            }
        }
        return ls;
    }
};

// best approach but no
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // since we will have 2 elements at max
        vector<int> ans;
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count1 == 0 && element2 != nums[i])
            {
                count1 = 1;
                element1 = nums[i];
            }
            else if (count2 == 0 && element1 != nums[i])
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if (nums[i] == element1)
                count1++;
            else if (nums[i] == element2)
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == element1)
                count1++;
            if (nums[i] == element2)
                count2++;
        }
        if (count1 > int(nums.size() / 3))
            ans.push_back(element1);
        if (count2 > int(nums.size() / 3))
            ans.push_back(element2);
        return ans;
    }
};

int main()
{
    return 0;
}