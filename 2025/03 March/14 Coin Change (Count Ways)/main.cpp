// Link: https://www.geeksforgeeks.org/problems/coin-change2448/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &coins, int sum, long curr_sum, vector<vector<int>> &dp)
    {
        if (curr_sum > sum)
        {
            return 0;
        }
        if (i == coins.size())
        {
            return curr_sum == sum;
        }
        if (dp[i][curr_sum] != -1)
        {
            return dp[i][curr_sum];
        }

        int take = solve(i, coins, sum, curr_sum + coins[i], dp);
        int not_take = solve(i + 1, coins, sum, curr_sum, dp);

        return dp[i][curr_sum] = take + not_take;
    }

    int count(vector<int> &coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, coins, sum, 0, dp);
    }
};

int main()
{
    Solution obj;
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << obj.count(coins, sum) << endl;

    coins = {2, 5, 3, 6};
    sum = 10;
    cout << obj.count(coins, sum) << endl;

    coins = {5, 10};
    sum = 3;
    cout << obj.count(coins, sum) << endl;
    return 0;
}