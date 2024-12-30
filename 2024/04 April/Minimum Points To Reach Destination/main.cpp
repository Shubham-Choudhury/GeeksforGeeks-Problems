// Link: https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &p, vector<vector<int>> &dp)
    {
        int m = p.size(), n = p[0].size();
        if (i == m - 1 && j == n - 1)
            return 1 - p[i][j];
        if (i >= m || j >= n)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = solve(i + 1, j, p, dp);
        int op2 = solve(i, j + 1, p, dp);

        return dp[i][j] = max(1, min(op1, op2) - p[i][j]);
    }

    int minPoints(int m, int n, vector<vector<int>> points)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = solve(0, 0, points, dp);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> points = {{2, 3},
                                  {5, 10},
                                  {10, 30}};
    int m = points.size(), n = points[0].size();
    cout << obj.minPoints(m, n, points) << endl;
    points = {{-2, -3, 3},
              {-5, -10, 1},
              {10, 30, -5}};
    m = points.size(), n = points[0].size();
    cout << obj.minPoints(m, n, points) << endl;
    return 0;
}