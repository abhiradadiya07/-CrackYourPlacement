#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long ans = INT_MAX;
        for (int i = m - 1, j = 0; i < n; i++, j++)
        {
            ans = min(ans, a[i] - a[j]);
        }
        return ans;
    }
};