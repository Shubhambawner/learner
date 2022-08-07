#include "../../DSA/util/recursion_utilities.cpp"
#include <bits/stdc++.h>
using namespace std;

// on grid m x n, of cherrys, bob alice starting from top cornors, to collect maximum cherrys
// 

int rc(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
        return -1e9;

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    if (i == grid.size() - 1)
    {
        if (j1 == j2)
            return dp[i][j1][j2] = grid[i][j1];
        else
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }

    int ans;
    if (j1 == j2)
        ans = grid[i][j1];
    else
        ans = grid[i][j1] + grid[i][j2];
    int maxi = -1e9;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int t = ans;
            ans += rc(i + 1, j1 + di, j2 + dj, grid, dp);
            maxi = max(maxi, ans);
            ans = t;
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return rc(0, 0, m - 1, grid, dp);
}