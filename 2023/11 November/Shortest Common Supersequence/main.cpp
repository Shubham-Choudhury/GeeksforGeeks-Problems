// Link: https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int dp[m + 1][n + 1];
        int length = 0;
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        length = dp[m][n];
        int l1 = m - length;
        int l2 = n - length;
        return length + l1 + l2;
    }
};

int main()
{
    Solution obj;
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << obj.shortestCommonSupersequence(X, Y, X.length(), Y.length());
    return 0;
}