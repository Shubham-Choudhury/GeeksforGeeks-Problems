// Link: https://www.geeksforgeeks.org/problems/maximum-profit4657/1

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        int dp[k + 1][n];
        if (n == 0)
            return 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int mx = dp[i][j - 1];
                for (int p = 0; p < j; p++)
                {
                    mx = max(mx, (prices[j] - prices[p]) + dp[i - 1][p]);
                }
                dp[i][j] = mx;
            }
        }
        return dp[k][n - 1];
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {10, 22, 5, 80};
    int k = 2;
    cout << obj.maxProfit(prices, k) << endl;

    prices = {20, 580, 420, 900};
    k = 3;
    cout << obj.maxProfit(prices, k) << endl;

    prices = {100, 90, 80, 50, 25};
    k = 1;
    cout << obj.maxProfit(prices, k) << endl;
    return 0;
}
