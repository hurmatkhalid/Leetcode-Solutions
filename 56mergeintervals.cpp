// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the
// non-overlapping intervals that cover all the intervals in the input.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i + 1][0] <= intervals[i][1])
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
            {
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                ans.push_back(temp);
            }
        }
        ans.push_back(intervals[n - 1]);
        return ans;
    }
};

int main()
{
    return 0;
}