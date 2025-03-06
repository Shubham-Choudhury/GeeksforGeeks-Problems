// Link: https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution object;
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << object.lcs(s1, s2) << endl;

    s1 = "ABC";
    s2 = "AC";
    cout << object.lcs(s1, s2) << endl;

    s1 = "XYZW";
    s2 = "XYWZ";
    cout << object.lcs(s1, s2) << endl;
}