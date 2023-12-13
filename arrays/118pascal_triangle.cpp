// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> firstrow = {1};
        vector<int> secondrow = {1, 1};
        ans.push_back(firstrow);
        if (numRows == 1)
        {
            return ans;
        }
        ans.push_back(secondrow);
        if (numRows == 2)
        {
            return ans;
        }
        for (int i = 2; i < numRows; i++)
        {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main()
{
    return 0;
}