// Link: https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestSubstring(string s, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int mx_length = 0, last = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[i - 1] == s[j - 1] && dp[i - 1][j - 1] < (j - i))
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    if (dp[i][j] > mx_length)
                    {
                        mx_length = dp[i][j];
                        last = i - 1;
                    }
                }
            }
        }

        if (mx_length == 0)
        {
            return "-1";
        }
        else
            return s.substr(last - mx_length + 1, mx_length);
    }
};

int main()
{
    Solution obj;
    string s = "acdcdacdc";
    int n = s.length();
    cout << obj.longestSubstring(s, n) << endl;
    s = "heheheh";
    n = s.length();
    cout << obj.longestSubstring(s, n) << endl;
    return 0;
}