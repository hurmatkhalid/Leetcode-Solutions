// You are given an m x n integer matrix matrix with the following two properties :
// Each row is sorted in non - decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

#include <iostream>
#include <vector>
using namespace std;
// good solution without binary search
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1])
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
            else
            {
                continue;
            }
        }
        return false;
    }
};
// using binary search
class Solution
{
public:
    bool bin_search(int arr[], int targ, int n)
    {
        int s = 0;
        int e = n;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] == targ)
                return true;
            else if (arr[mid] < targ)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1])
            {
                if (bin_search(matrix[i].data(), target, n))
                    return true;
            }
        }
        return false;
    }
};
// best solution by considering the 2d matrix to be 1d array
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = n * m - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};

int main()
{
    return 0;
}