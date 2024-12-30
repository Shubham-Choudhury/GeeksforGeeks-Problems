// Link: https://www.geeksforgeeks.org/problems/good-by-2023/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int ind, int sum, int coins[], vector<vector<int>> &dp, int n)
    {
        if (ind == n)
        {
            if ((sum % 20 == 0 || sum % 24 == 0 || sum == 2024) && sum != 0)
            {
                return true;
            }
            return false;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int not_take = f(ind + 1, sum, coins, dp, n);
        int take = f(ind + 1, coins[ind] + sum, coins, dp, n);
        return dp[ind][sum] = (not_take || take);
    }
    int isPossible(int N, int coins[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(2024, -1));
        return f(0, 0, coins, dp, N);
    }
};

int main()
{
    Solution obj;
    int coins[] = {5, 8, 9, 10, 14, 2, 3, 5};
    int n = 8;
    cout << obj.isPossible(n, coins);
    return 0;
}
