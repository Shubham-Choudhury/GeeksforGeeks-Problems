// Link: https://www.geeksforgeeks.org/problems/number-of-coins1824/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minCoins(vector<int> &coins, int sum)
    {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (auto &coin : coins)
            for (int i = coin; i <= sum; i++)
                if (dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

int main()
{
    Solution obj;
    vector<int> coins = {25, 10, 5};
    int sum = 30;
    cout << obj.minCoins(coins, sum) << endl;

    coins = {9, 6, 5, 1};
    sum = 19;
    cout << obj.minCoins(coins, sum) << endl;

    coins = {5, 1};
    sum = 0;
    cout << obj.minCoins(coins, sum) << endl;

    coins = {4, 6, 2};
    sum = 5;
    cout << obj.minCoins(coins, sum) << endl;
    return 0;
}