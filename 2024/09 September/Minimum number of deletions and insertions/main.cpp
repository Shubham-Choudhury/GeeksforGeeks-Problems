// Link: https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int cnt = dp[n][m];
        return n - cnt + m - cnt;
    }
};

int main()
{
    Solution obj;
    string str1 = "heap";
    string str2 = "pea";
    cout << obj.minOperations(str1, str2) << endl;
    str1 = "geeksforgeeks";
    str2 = "geeks";
    cout << obj.minOperations(str1, str2) << endl;
    return 0;
}