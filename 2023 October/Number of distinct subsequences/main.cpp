// Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctSubsequences(string S)
    {
        int n = S.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int mod = 1e9 + 7;
        unordered_map<char, int> last;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (dp[i - 1] * 2) % mod;
            if (last.count(S[i - 1]))
            {
                dp[i] = (dp[i] - dp[last[S[i - 1]] - 1] + mod) % mod;
            }
            last[S[i - 1]] = i;
        }
        dp[n]--;
        if (dp[n] < 0)
            dp[n] += mod;
        return dp[n] + 1;
    }
};

int main()
{
    Solution obj;
    cout << obj.distinctSubsequences("gfg") << endl;
    cout << obj.distinctSubsequences("ggg") << endl;
    return 0;
}