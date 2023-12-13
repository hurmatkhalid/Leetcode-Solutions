// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n /2⌋
// times.You may assume that the majority element always exists in the array.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // moores voting algorithm
        int count = 0;
        int element;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count++;
                element = nums[i];
            }
            else
            {
                if (nums[i] == element)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == element)
                temp++;
        }
        if (temp > nums.size() / 2)
        {
            return element;
        }
        return -1;
    }
};
int main()
{
    return 0;
}