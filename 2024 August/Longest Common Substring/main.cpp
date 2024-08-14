// Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        int dp[n + 1][m + 1];
        int result = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    result = max(result, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string str1 = "ABCDGH";
    string str2 = "ACDGHR";
    cout << obj.longestCommonSubstr(str1, str2) << endl;

    str1 = "ABC";
    str2 = "ACB";
    cout << obj.longestCommonSubstr(str1, str2) << endl;

    return 0;
}