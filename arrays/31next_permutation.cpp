// A permutation of an array of integers is an arrangement of its members into
//  a sequence or linear order.
// For example, [2, 1, 3] is a permutation of [1, 2, 3].
// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array
// are sorted in one container according to their lexicographical order,
// then the next permutation of that array is the permutation that follows it
// in the sorted container. If such arrangement is not possible, the array must be
// rearranged as the lowest possible order (i.e., sorted in ascending order).

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int ind = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] > nums[ind])
                {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};

int main()
{
    return 0;
}