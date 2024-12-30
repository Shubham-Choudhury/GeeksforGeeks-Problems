// Link: https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        const int MOD = 1e9 + 7;
        int n = s1.length(), m = s2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution obj;

    string s1 = "geeksforgeeks";
    string s2 = "gks";
    cout << obj.countWays(s1, s2) << endl;

    s1 = "problemoftheday";
    s2 = "gks";
    cout << obj.countWays(s1, s2) << endl;

    return 0;
}
