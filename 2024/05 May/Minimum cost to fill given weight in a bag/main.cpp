// Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-w-in-a-bag1956/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1));

        for (int i = 0; i <= w; i++)
        {
            dp[0][i] = i * cost[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                int not_pick = dp[i - 1][j];
                int pick = int(1e9);

                if (cost[i] != -1 && (i + 1) <= j)
                {
                    pick = cost[i] + dp[i][j - (i + 1)];
                }

                dp[i][j] = min(pick, not_pick);
            }
        }

        return dp[n - 1][w];
    }
};

int main()
{
    Solution sol;
    vector<int> cost1 = {20, 10, 4, 50, 100};
    int n = cost1.size();
    int w = 5;
    cout << sol.minimumCost(n, w, cost1) << endl;

    vector<int> cost2 = {-1, -1, 4, 3, -1};
    n = cost2.size();
    w = 5;
    cout << sol.minimumCost(n, w, cost2) << endl;
    return 0;
}