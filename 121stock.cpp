// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock
//  and choosing a different day in the future to sell that stock.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_ = prices[0];
        int n = prices.size();
        int answer = 0;
        for (int i = 1; i < n; i++)
        {
            int output = prices[i] - min_;
            answer = max(output, answer);
            min_ = min(min_, prices[i]);
        }
        return answer;
    }
};

int main()
{
    return 0;
}