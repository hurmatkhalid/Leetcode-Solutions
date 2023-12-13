// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and2 to represent the color red, white, and blue, respectively. You must solve this problem without using the library's sort function.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    { // we will make three pointers, 1)start 2)mid 3)end
        // the start pointer points to the starting, the end starts from the last element and the mid starts from starting too,
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while (start < end && mid <= end)
        {
            if (nums[mid] == 0)
            {
                nums[start] = 0;
                nums[mid] = nums[start];
                mid++;
                start++;
            }
            else if (nums[mid] == 2)
            {
                nums[end] = 2;
                nums[mid] = nums[end];
                end--;
            }
            else
            {
                mid++;
            }
        }
    }
};

int main()
{
    return 0;
}