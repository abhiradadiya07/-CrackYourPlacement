#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1 : Recursive
    int Approach1(vector<int> &prices, int i, int buy)
    {
        if (i >= prices.size())
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            int buyProfit = -prices[i] + Approach1(prices, i + 1, 0);
            int skip = Approach1(prices, i + 1, 1);
            profit = max(buyProfit, skip);
        }
        else
        {
            int sellProfit = prices[i] + Approach1(prices, i + 1, 1);
            int skip = Approach1(prices, i + 1, 0);
            profit = max(sellProfit, skip);
        }
        return profit;
    }

    // Approach 2 : Top Down
    int Approach2(vector<int> &prices, int i, int buy,
                  vector<vector<int>> &dp)
    {
        if (i >= prices.size())
        {
            return 0;
        }

        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }
        int profit = 0;
        if (buy)
        {
            int buyProfit = -prices[i] + Approach2(prices, i + 1, 0, dp);
            int skip = Approach2(prices, i + 1, 1, dp);
            dp[i][buy] = max(buyProfit, skip);
        }
        else
        {
            int sellProfit = prices[i] + Approach2(prices, i + 1, 1, dp);
            int skip = Approach2(prices, i + 1, 0, dp);
            dp[i][buy] = max(sellProfit, skip);
        }
        return dp[i][buy];
    }

    int Approach3(vector<int> &prices)
    {
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return Approach1(prices, 0, true);
        // return Approach2(prices, 0, true, dp);
        return Approach3(prices);
    }
};