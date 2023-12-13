// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.
#include <iostream>
#include <vector>
using namespace std;

// brute force approach, and wouldnt work if there are negatives
class Solution
{
public:
    void setRows(vector<vector<int>> &matrix, int i)
    {
        for (int k = 0; k < matrix[0].size(); k++)
        {
            if (matrix[i][k] != 0)
            {
                matrix[i][k] = -1;
            }
        }
    }
    void setColumns(vector<vector<int>> &matrix, int j)
    {
        for (int k = 0; k < matrix.size(); k++)
        {
            if (matrix[k][j] != 0)
            {
                matrix[k][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int size_r = matrix.size();
        int size_c = matrix[0].size();

        for (int i = 0; i < size_r; i++)
        {
            for (int j = 0; j < size_c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    setRows(matrix, i);
                    setColumns(matrix, j);
                }
            }
        }
        for (int i = 0; i < size_r; i++)
        {
            for (int j = 0; j < size_c; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// better approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row[m];
        int col[n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// best approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    return 0;
}