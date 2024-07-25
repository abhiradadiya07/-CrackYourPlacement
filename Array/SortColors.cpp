
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = n - 1, k = 0;

        while (k <= j)
        {
            if (nums[k] == 0)
            {
                swap(nums[i], nums[k]);
                i++;
                k++;
            }
            else if (nums[k] == 2)
            {
                swap(nums[j], nums[k]);
                j--;
            }
            else
            {
                k++;
            }
        }
    }
};