// Link: https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        int n = price.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    if (buy == 1)
                    {
                        int buyit = -price[index] + dp[index + 1][0][limit];
                        int skip = 0 + dp[index + 1][1][limit];
                        dp[index][buy][limit] = max(buyit, skip);
                    }
                    else
                    {
                        int sell = price[index] + dp[index + 1][1][limit - 1];
                        int skip = 0 + dp[index + 1][0][limit];
                        dp[index][buy][limit] = max(sell, skip);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << obj.maxProfit(prices) << endl;
    prices = {2, 30, 15, 10, 8, 25, 80};
    cout << obj.maxProfit(prices) << endl;
    return 0;
}