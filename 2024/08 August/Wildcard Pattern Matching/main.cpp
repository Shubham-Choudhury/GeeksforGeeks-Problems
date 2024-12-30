// Link: https://www.geeksforgeeks.org/problems/wildcard-patterntern-matching/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int wildCard(string pattern, string str)
    {
        int m = str.length();
        int n = pattern.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j)
        {
            if (pattern[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n] ? 1 : 0;
    }
};

int main()
{
    Solution obj;
    string pattern = "ba*a?";
    string str = "baaabab";
    cout << obj.wildCard(pattern, str) << endl;
    pattern = "a*ab";
    str = "baaabab";
    cout << obj.wildCard(pattern, str) << endl;
    return 0;
}