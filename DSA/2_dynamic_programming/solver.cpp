#include "../../DSA/util/recursion_utilities.cpp"
// #include <bits/stdc++.h>
using namespace std;

// f(i,t) gives number of posible subsets of sum t from index i to n-1
int findWaysFrom(int ind, int tar, vector<int> &num, vector<vector<int>> &dp)
{
    recurse(ind, tar);
    int n = num.size();
    if (tar == 0)
    {
        returnRecurse(1);
        return 1;
    }
    if (ind == n - 1)
    {
        returnRecurse(num[n - 1] == tar);
        return (int)(num[n - 1] == tar);
    }
    int ans = findWaysFrom(ind + 1, tar, num, dp);
    if (tar >= num[ind])
        ans += findWaysFrom(ind + 1, tar - num[ind], num, dp);

    returnRecurse(ans);
    return ans;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<vector<int>> dp;
    return findWaysFrom(0, tar, num, dp);
}

int main()
{
    //     vector<string> dungeon = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    // Solution a;
    vector<int> num = {0, 1, 0, 1, 0, 1};

    cout << findWays(num, 2);
}