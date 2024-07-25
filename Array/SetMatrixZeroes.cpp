#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // T.C : O(m*n) S.C : O(m+n).
    void Approach1(vector<vector<int>> &matrix)
    {

        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    v.push_back({i, j});
                }
            }
        }

        for (auto it : v)
        {
            int i = it.first, j = it.second;
            for (int i = 0; i < m; i++)
            {
                matrix[i][j] = 0;
            }
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
        return;
    }

    // T.C : O(m*n) S.C : Constant Space.
    void Approach2(vector<vector<int>> &matrix)
    {

        int m = matrix.size(), n = matrix[0].size();
        bool row = 0, col = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                row = 1;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                col = 1;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }

        if (col)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        return;
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        // Approach1(matrix);
        Approach2(matrix);
        return;
    }
};