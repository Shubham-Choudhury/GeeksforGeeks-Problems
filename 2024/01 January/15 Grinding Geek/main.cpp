// Link: https://www.geeksforgeeks.org/problems/grinding-geek/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dpf(int i, int j, vector<vector<int>> &dp, vector<int> &cost)
    {
        if (i == dp.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = dpf(i + 1, j, dp, cost);
        if (j >= cost[i])
        {
            dp[i][j] = max(dp[i][j], 1 + dpf(i + 1, j - cost[i] + ((9 * cost[i]) / 10), dp, cost));
        }
        return dp[i][j];
    }

public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return dpf(0, total, dp, cost);
    }
};

int main()
{
    Solution obj;
    int n = 11;
    int total = 10;
    vector<int> cost = {10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << obj.max_courses(n, total, cost) << endl;
    return 0;
}