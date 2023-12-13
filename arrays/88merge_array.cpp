// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non - decreasing order.
// The final sorted array should not be returned by the function,
// but instead be stored inside the array nums1.To accommodate this,
// nums1 has a length of m + n, where the first m elements denote the
//  elements that should be merged, and the last n elements are set to 0 and should be ignored.nums2 has a length of n.

#include <iostream>
#include <vector>
using namespace std;

// bad approach
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = n + m - 1;
        int r = m - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums2[i] >= nums1[r])
            {
                nums1[p] = nums2[i];
                p--;
            }
            else
            {
                nums1[p] = nums1[r];
                r--;
                p--;
            }
        }
    }
};

// brute force
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = 0;
        for (int i = m; i < n + m; i++)
        {
            nums1[i] = nums2[k];
            k++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

// we can make it optimal by elimintaing the sort at the end and sorting it simultaneously while merging
//  optimal
int main()
{
    return 0;
}