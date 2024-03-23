// Link: https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Series(int n)
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp;
    }
};

int main()
{
    Solution obj;
    int n = 5;
    vector<int> ans = obj.Series(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    n = 10;
    ans = obj.Series(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}