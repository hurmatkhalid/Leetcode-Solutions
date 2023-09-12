// You are given an n x n 2D matrix representing an image,
// rotate the image by 90 degrees (clockwise).
// You have to rotate the image in - place, which means
// you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output : [ [ 7, 4, 1 ], [ 8, 5, 2 ], [ 9, 6, 3 ] ]

// Intuition: By observation, we see that the first column of the original matrix is
//  the reverse of the first row of the rotated matrix, so that’s why we transpose
//  the matrix and then reverse each row, and since we are making changes in the
// matrix itself space complexity gets reduced to O(1).

// Approach :
// Step 1 : Transpose the matrix.(transposing means changing columns to rows and rows to columns)
// Step 2 : Reverse each row of the matrix.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // first make transpose
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    return 0;
}