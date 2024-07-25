#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Approach2 : Recursive
    void Approach2(vector<int> &prices, int &profit, int &minValue, int i)
    {
        if (i == prices.size())
        {
            return;
        }
        profit = max(profit, prices[i] - minValue);
        minValue = min(minValue, prices[i]);
        Approach2(prices, profit, minValue, i + 1);
    }

    // Approach 1 : Iterative
    int Approach1(vector<int> &prices)
    {
        int n = prices.size(), minValue = INT_MAX, profit = INT_MIN, ans = 0;
        for (int i = 0; i < n; i++)
        {
            profit = max(profit, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }
        return ans;
    }
    int maxProfit(vector<int> &prices)
    {
        // return Approach1(prices);
        int minValue = INT_MAX, profit = 0;
        Approach2(prices, profit, minValue, 0);
        return profit;
    }
};