// Link: https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int dp[n];
        if (n == 1)
            return cost[0];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[n - 2], dp[n - 1]);
    }
};

int main()
{
    Solution obj;
    vector<int> cost = {10, 15, 20};
    cout << obj.minCostClimbingStairs(cost) << endl;

    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << obj.minCostClimbingStairs(cost) << endl;

    return 0;
}